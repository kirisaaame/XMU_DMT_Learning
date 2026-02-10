$(function(){
    // 点击精确/索引检索按钮
    $("#chatbotsendbtn").on("click", function(e){
      e.preventDefault();
      const q = $.trim($("#chattextarea").val());
      if (!q) { alert("请输入您的问题"); return; }
  
      appendUserBubble(q);
      showLoadingBubble('search');
  
      $.ajax({
        url: "/searchanswer/",
        data: { id: "chatbotsendbtn", text: q },
        dataType: "json",
        timeout: 30000,
        success: function(res){
          removeLoadingBubble('search');
          const exact = res.answer_exact || '检索不到答案';
          const app   = res.answer_app   || '检索不到答案';
          appendBotBubble(`精确匹配：<br>${exact}`);
          appendBotBubble(`词汇占比：<br>${app}`);
        },
        error: function(xhr, status){
          removeLoadingBubble('search');
          if (status === 'timeout') {
            appendBotBubble('检索超时，请稍后再试');
          } else {
            appendBotBubble('检索出错，请稍后再试');
          }
        }
      });
    });
  
    // 点击 DeepSeek 按钮
    $("#deepseekbtn").on("click", function(e){
      e.preventDefault();
      const q = $.trim($("#chattextarea").val());
      if (!q) { alert("请输入您的问题"); return; }
  
      appendUserBubble(q);
      showLoadingBubble('deepseek');
  
      $.ajax({
        url: "/deepseekanswer/",
        data: { text: q },
        dataType: "json",
        timeout: 60000,
        success: function(res){
          removeLoadingBubble('deepseek');
          const ans = res.answer_api || '检索不到答案';
          appendBotBubble(`DeepSeek：<br>${ans}`);
        },
        error: function(xhr, status){
          removeLoadingBubble('deepseek');
          if (status === 'timeout') {
            appendBotBubble('调用超时，请稍后再试');
          } else {
            appendBotBubble('DeepSeek 出错，请稍后再试');
          }
        }
      });
    });
  
    // 点击建立索引按钮
    $("#submit2index").on("click", function(e){
      e.preventDefault();
      showLoadingBubble('build');
      $.ajax({
        type: "post",
        url: "/buildindex/",
        data: { id: "submit2index" },
        dataType: "json",
        timeout: 20000,
        success: function(res){
          removeLoadingBubble('build');
          if (res.status === 200) {
            alert('索引已更新');
          } else {
            alert('索引失败：' + res.text);
          }
        },
        error: function(xhr, status){
          removeLoadingBubble('build');
          alert('索引出错，请稍后再试');
        }
      });
    });
  
    // 工具函数：显示“加载中”气泡
    function showLoadingBubble(id) {
      const html = `<div class="item item-left loading" id="loading-${id}">` +
                   `<div class="avatar avatar-bot"></div>` +
                   `<div class="bubble bubble-left">加载中……</div>` +
                   `</div>`;
      $('.content').append(html);
      scrollToBottom();
    }
  
    function removeLoadingBubble(id) {
      $(`#loading-${id}`).remove();
    }
  
    // 工具函数：添加用户对话泡
    function appendUserBubble(text) {
      const html = `<div class="item item-right">` +
                   `<div class="bubble bubble-right">${text}</div>` +
                   `<div class="avatar avatar-user"></div>` +
                   `</div>`;
      $('.content').append(html);
      scrollToBottom();
    }
  
    // 工具函数：添加机器人对话泡
    function appendBotBubble(htmlContent) {
      const html = `<div class="item item-left">` +
                   `<div class="avatar avatar-bot"></div>` +
                   `<div class="bubble bubble-left">${htmlContent}</div>` +
                   `</div>`;
      $('.content').append(html);
      scrollToBottom();
    }
  
    // 工具函数：滚动到底部
    function scrollToBottom() {
      const c = $('.content');
      c.scrollTop(c[0].scrollHeight);
    }
  });
  