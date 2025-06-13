function blob_detection(image_path)
    img = im2double(imread(image_path));

    function log_filter = generate_log_filter(sigma)
        [x, y] = meshgrid(-3*sigma:3*sigma, -3*sigma:3*sigma);
        normalizer = 1/(2*pi*sigma^4);
        log_filter = normalizer * (x.^2 + y.^2 - 2*sigma^2) .* exp(-(x.^2 + y.^2)/(2*sigma^2));
    end


    n = 6; 
    s = 2;
    k = sqrt(2); 
    scales = zeros(n, 1);
    responses = cell(n, 1);
    %滤波图像
    for i = 1:n
        sigma = k*s + 1 * (k^(i-1)); 
        log_filter = generate_log_filter(sigma);
        filtered_img = imfilter(img, log_filter, 'replicate');
        responses{i} = filtered_img.^2;
        scales(i) = sigma;
    end

    suppressed_response = nonmax_suppression(responses, scales);

    display_results(suppressed_response, img, scales, responses);
end

function suppressed_response = nonmax_suppression(responses, scales)
    % 非最大抑制
    suppressed_response = zeros(size(responses{1}));
    
    for i = 1:length(responses)
        current_response = responses{i};
        max_response = imdilate(current_response, strel('disk', 1));
        suppressed_response = suppressed_response + (current_response == max_response) .* current_response;
    end
end

function display_results(suppressed_response, img, scales, responses)
    % 显示检测结果
    figure;
    imshow(img); hold on;

    threshold = 0.15 * max(suppressed_response(:));
    [y, x] = find(suppressed_response > threshold);
    
    % 绘制圆圈
    for i = 1:length(x)
        scale_index = find_max_response_index(responses, x(i), y(i));
        if ~isempty(scale_index)
            viscircles([x(i), y(i)], scales(scale_index), 'Color', 'r', 'LineWidth', 1);
        end
    end
    
    title('Detected Spots');
    hold off;
end

function index = find_max_response_index(responses, x, y)
    % 找到最大响应的尺度索引
    max_response = -Inf;
    index = [];
    
    for i = 1:length(responses)
        if responses{i}(y, x) > max_response
            max_response = responses{i}(y, x);
            index = i; % 更新索引
        end
    end
end