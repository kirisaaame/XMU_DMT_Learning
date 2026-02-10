import requests
import pandas as pd
from bs4 import BeautifulSoup
import re

# ====== 配置区 ======
TOPIC_URL = "https://www.douban.com/group/topic/319735763/?_spm_id=MjU0OTcyNDA2&_i=1525768zmPcUkr"  # 替换为目标问答页面的URL
COOKIE = '''ll="118201"; bid=zmPcUkraIPM; dbcl2="287648570:av5ogo/VzUU"; ck=Zvtd; ap_v=0,6.0; frodotk_db="08695fb88a0e0cc6193c1f299e2a2652"; push_noty_num=0; push_doumail_num=0'''

# ====== 请求头配置 ======
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
    'Referer': 'https://www.douban.com/',
    'Cookie': COOKIE,
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
    'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8',
    'Connection': 'keep-alive'
}

# ====== 核心函数 ======
def fetch_douban_topic():
    try:
        # 发送请求
        response = requests.get(TOPIC_URL, headers=headers, timeout=15)
        response.raise_for_status()

        # 解析 HTML
        soup = BeautifulSoup(response.text, 'html.parser')

        # 提取问题标题
        title = soup.find('h1').text.strip()
        title = filter_gbk_unsupported(title)

        # 提取问题内容
        question_content = extract_clean_question_content(soup)
        # print(soup)
        clean_text(question_content)
        question_content = filter_gbk_unsupported(question_content)

        # 提取回答内容
        answers = []
        reply_items = soup.find_all('li', class_='reply-item')
        # print(reply_items)
        for reply in reply_items:
            answer_content = reply.find('div', class_='reply-content').find('div', class_='markdown').text.strip()
            answers.append(filter_gbk_unsupported(answer_content))

        # 存储数据
        data = {
            # '序号': 1,  # 主键（序号）
            'question': title + ":" + question_content,
            # 'answer': "\n".join(answers), # 将回答内容拼接为字符串
            'answer': [f" 回答{i+1}: {answer};" for i, answer in enumerate(answers)],
        }

        # 保存为 CSV 文件
        df = pd.DataFrame([data])
        df.to_csv('douban_topic.csv', encoding='gbk', index=False)
        print("数据已保存到 douban_topic.csv")

    except Exception as e:
        print(f"抓取失败：{str(e)}")

# ====== 辅助函数：提取干净的提问内容 ======
def extract_clean_question_content(soup):
    # 找到提问内容的容器
    topic_content = soup.find('div', class_='topic-content').find('div', class_='rich-content') #.text.strip()
    if not topic_content:
        return ""

    # 移除不需要的元数据标签
    for tag in topic_content.find_all(class_=['sharing-button', 'action-collect', 'action-react', 'collect', 'share']):  # 替换为实际的类名
        tag.decompose()  # 移除标签

    # 提取干净的文本内容
    clean_content = topic_content.get_text(separator='\n').strip()
    return clean_content

# ====== 辅助函数：清理文本中的多余换行符 ======
def clean_text(text):
    # 使用正则表达式替换连续的换行符为单个换行符
    text = re.sub(r'\n+', '\n', text)
    # 移除文本开头和结尾的换行符
    text = text.strip()
    return text

def filter_gbk_unsupported(text):
    filtered_text = []
    for char in text:
        try:
            # 尝试将字符编码为 gbk
            char.encode('gbk')
            filtered_text.append(char)
        except UnicodeEncodeError:
            # 如果无法编码，跳过该字符
            continue
    return ''.join(filtered_text)

# ====== 执行入口 ======
if __name__ == "__main__":
    fetch_douban_topic()