$(document).ready(function () {
    // 点击检索按钮，发请求
    $("#chatbotsendbtn").on("click", function () {
        var searchtext = $.trim($('#chattextarea').val());
        if (searchtext == "") {
            alert("请输入您的问题");
            return;
        }
        // 将问题添加到聊天窗口的末尾
        var question_html = '<div class="item item-right">'
            + '<div class="bubble bubble-right">' + searchtext + '</div>'
            + '<div class="avatar avatar-user"></div>'
            + '</div>';
        $('.content').append(question_html);
        // 清空问题文本框
        $('#chattextarea').val('');
        $('#chattextarea').focus();
        // 滚动条置底
        var height = $('.content').scrollTop();
        $(".content").scrollTop(height); $.ajax({
            type: "get",
            url: "/searchanswer",
            data: {
                "id": $("#chatbotsendbtn").attr("id"),
                "text": searchtext
            },
            dataType: "json",
            beforeSend: function () {
                // 设置 disabled 阻止用户继续点击
                $("#chatbotsendbtn").attr("disabled", "disabled");
            },
            complete: function () {
                // 请求完成移除 disabled 属性
                $("#chatbotsendbtn").removeAttr("disabled");
            },
            success: function (result) {
                if (result.status == 200) {
                    // 将答案添加到聊天窗口的末尾
                    var answer_html = '<div class="item item-left">'
                        + '<div class="avatar avatar-bot"></div>'
                        + '<div class="bubble bubble-left">' + result.answer + '</div>'
                        + '</div>';
                    $('.content').append(answer_html);
                    // 滚动条置底
                    var height = $('.content').scrollTop();
                    $(".content").scrollTop(height);
                    console.log("检索答案成功");
                }
                else {
                    // 将答案添加到聊天窗口的末尾
                    var answer_html = '<div class="item item-left">'
                        + '<div class="avatar avatar-bot"></div>'
                        + '<div class="bubble bubble-left">对不起！我不明白您的问题，可以换种问法吗？</div > '
                        + '</div>';
                    $('.content').append(answer_html);
                    // 滚动条置底
                    var height = $('.content').scrollTop();
                    $(".content").scrollTop(height);
                    console.log("检索不到答案");
                }
            },
            error: function (jqXHR, textStatus, e) {
                alert("提交异常：" + e);
            }
        });
    });
});