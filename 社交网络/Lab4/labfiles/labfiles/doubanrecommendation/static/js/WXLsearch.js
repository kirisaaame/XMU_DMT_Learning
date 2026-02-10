$(document).ready(function(){
    // 点击发送按钮，发请求
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
        $(".content").scrollTop(height);

        // 请在这里添加词性标注、实体识别的提示语句处理代码
        var opType = "search"; // 默认认为问答检索操作
        if (searchtext.includes("词性标注：")) {
            // 删除用户要处理的文本内容外的其他提示内容
            searchtext = searchtext.replace("词性标注：", "").trim();
            opType = "pos";
        }
        else if (searchtext.includes("实体识别：")) {
            // 删除用户要处理的文本内容外的其他提示内容
            searchtext = searchtext.replace("实体识别：", "").trim();
            opType = "entity";
            }
        else if (searchtext.includes("词云分析：")) {
            // 删除用户要处理的文本内容外的其他提示内容
            searchtext = searchtext.replace("词云分析：", "").trim();
            opType = "wcloud";
        }
        $.ajax({
            type: "get",
            url: "/searchanswer",
            data: {
                "id": $("#chatbotsendbtn").attr("id"), 
                "text": searchtext,
                "opType": opType
            },
            dataType: "json",
            beforeSend: function() {
                // 设置disabled阻止用户继续点击
                $("#chatbotsendbtn").attr("disabled", "disabled");
            }, 
            complete: function () {
                // 请求完成移除 disabled 属性
                $("#chatbotsendbtn").removeAttr("disabled");
            },  
            success: function(result){
                if(result.status == 200){

                    if (opType == "search") {
                        // 精确匹配答案
                        var answer_html = '<div class="item item-left">'
                            + '<div class="avatar avatar-bot"></div>'
                            + '<div class="bubble bubble-left">' + '精确匹配答案：<br>' + result.answer_exact + '</div>' 
                            + '</div>';
                        $('.content').append(answer_html);

                        // 基于词频的答案
                        var answer_html_app = '<div class="item item-left">'
                            + '<div class="avatar avatar-bot"></div>'
                            + '<div class="bubble bubble-left">' + '基于词频的答案：<br>' + result.answer_app + '</div>' 
                            + '</div>';
                        $('.content').append(answer_html_app);
                    }
                    else if (opType == "pos" || opType == "entity") {
                        // 将词性标注或实体识别结果添加到聊天窗口的末尾
                        var answer_html = '<div class="item item-left">'
                            + '<div class="avatar avatar-bot"></div>'
                            + '<div class="bubble bubble-left">' + result.answer_exact + '</div>' 
                            + '</div>';
                        $('.content').append(answer_html);
                    }
                    else if (opType == "wcloud") {
                        // 将词云分析结果添加到聊天窗口的末尾
                        var answer_html = '<div class="item item-left">'
                            + '<div class="avatar avatar-bot"></div>'
                            + '<img src="'+ result.answer_exact + '">'
                            + '</div>';
                        $('.content').append(answer_html);
                    }

                    // 滚动条置底
                    var height = $('.content').scrollTop();
                    $(".content").scrollTop(height);
                }
                else {
                    // 未识别到答案
                    var answer_html = '<div class="item item-left">'
                        + '<div class="avatar avatar-bot"></div>'
                        + '<div class="bubble bubble-left">对不起！我不明白您的问题，可以换种问法吗？</div>' 
                        + '</div>';
                    $('.content').append(answer_html);
                    // 滚动条置底
                    var height = $('.content').scrollTop();
                    $(".content").scrollTop(height);
                }
            }, 
            error: function (jqXHR, textStatus, e) {
                alert("提交异常："+e);
            }
        });
    })
    // 点击索引按钮，发请求
    $("#submit2index").on("click", function () {
        $.ajax({
            type: "post",
            url: "/buildindex",
            data: {"id": $("#submit2index").attr("id")},
            dataType: "json",
            beforeSend: function() {
                // 设置disabled阻止用户继续点击
                $("#submit2index").attr("disabled", "disabled");
            }, 
            complete: function () {
                // 请求完成移除 disabled 属性
                $("#submit2index").removeAttr("disabled");
            },  
            success: function(result){
                if(result.status == 200){
                    console.log(result.text);
                }else{
                    alert("索引失败");
                }
            },
            error: function (jqXHR, textStatus, e) {
                alert("提交异常："+e);
            }
        });
    })
})
