import streamlit as st
import os
from random import choices, randint
from openai import OpenAI
import json

"""
谁是卧底游戏
"""

state = st.session_state

# title
st.title("谁是卧底😎")

# read the word list from the json file
with open("word_list.json", "r",encoding='utf-8') as f:
    word_list = json.load(f)
    pass

# define the avatar dict for the players
avatar_dict = {
    "host": "🐼",
    "P1": "🚀",
    "P2": "🚄",
    "P3": "🚁",
    "P4": "🚂",
    "P5": "🚢",
    "P6": "🚤",
    "P7": "🚙",
    "P8": "🚠",
    "P9": "🚲",
    "P10": "🚜",
    "H": "🤹‍♂️",
}

# define the state of the game and save some data
## 全局消息栈
if "messages" not in state:
    state.messages = []
    pass
## 玩家列表
if "players" not in state:
    state.players = []
    pass
## 玩家系统提示
if "prompt" not in state:
    with open("prompt.txt", "r",encoding='utf-8') as f:
        state.prompt = f.read()
        pass
    pass

# create a new OpenAI client and define the generation function
if "client" not in state:
    state.client = OpenAI(
        api_key=os.getenv("DASHSCOPE_API_KEY"),
        base_url="https://dashscope.aliyuncs.com/compatible-mode/v1",
    )
    state.model_name ="qwen-turbo"
    pass
def response(messages):
    return state.client.chat.completions.create(
        model=state.model_name,
        messages=messages,
        temperature=0.5,
    ).choices[0].message.content

# settings
## 记录轮次
if "max_round" not in state:
    state.max_round = 100
    pass
if "round" not in state:
    state.round = 0
    pass
## 侧边栏设置游戏，包括关键词，人数，回合数等
with st.sidebar:
    st.write("游戏设置")
    with st.form(key="game_setting"):
        if "words" not in state:
            words_num = randint(0, len(word_list)-1)
            state.words = word_list[words_num]
        total_num = st.number_input("总人数", 5, 10, 5)
        spy_num = st.number_input("卧底人数", 1, total_num//2, 1)
        max_round = st.number_input("最大回合数", 5, 10, 10)

        submitted = st.form_submit_button("保存设置")

        ## 提交后保存设置，初始化玩家、消息栈等
        if submitted:
            # print("游戏设置已保存")
            state.spy_word = state.words["spy_word"]           # 卧底关键词
            state.civilian_word = state.words["civilian_word"] # 平民关键词
            state.total_num = total_num        # 总人数
            state.spy_num = spy_num           # 卧底人数
            state.max_round = max_round     # 最大回合数
            ## 初始化玩家列表，人类玩家和AI玩家分开存
            human_dignity = randint(0,1)    # 人类玩家的身份，0: 平民 1: 卧底
            if human_dignity == 0:
                state.players = [{"id": "H", "dignity": "civilian"}]
                st.write("你的关键词是{}".format(state.civilian_word))
                pass
            else:
                state.players = [{"id": "H", "dignity": "spy"}]
                st.write("你的关键词是{}".format(state.spy_word))
                pass
            state.players += [{"id":"P"+str(i+1)} for i in range(total_num-1)]
            if human_dignity == 1 and state.spy_num-1 == 0:
                spy_id = []
                pass
            else:
                spy_id = choices([f"P{a}" for a in list(range(1,total_num))], k=state.spy_num)
                pass
            for each in state.players:
                if each["id"] in spy_id:
                    each["dignity"] = "spy"
                    pass
                else:
                    each["dignity"] = "civilian"
                    pass
                pass
            pass
        pass
    pass

# 消息显示窗口
with st.container(height=300):
    for message in state.messages:
        with st.chat_message(message["id"], avatar=avatar_dict[message["id"]]):
            st.text(message["id"])
            st.write(message["message"])
        pass
# 游戏主体环节
if state.round < state.max_round:
    if "description" not in state:
        state.description = []
        pass
    ## 控制游戏轮次及开始
    start = st.button("开始第{}轮游戏".format(state.round+1))
    if start:
        if "round" not in state:
            state.round = 0
            pass
        state.messages.append({"id":"host", "message":f"第{state.round+1}轮游戏开始"})
        ## 生成描述环节
        for player in state.players:
            ## 如果是人类玩家，跳过
            if player["id"] == "H":
                continue
            if player["dignity"] == "spy":
                text = response([
                    {"role":"system", "content":state.prompt.format(state.spy_word)},
                    {"role":"system", "content":"/describe "+"请根据描述历史记录描述你的关键词，需要注意不能与已有的描述重复，下面是描述历史记录：\n"+"\n".join(state.description)}
                    ])
            else:
                text = response([
                    {"role":"system", "content":state.prompt.format(state.civilian_word)},
                    {"role":"system", "content":"/describe "+"请根据描述历史记录描述你的关键词，下面是描述历史记录：\n"+"\n".join(state.description)}
                    ])
                pass
            state.messages.append({"id":player["id"], "message": text})
            state.description.append(player["id"] + ":" + text)
            pass
        st.rerun()
        pass
    ## 投票环节, AI玩家生成回复，最后由人类玩家统计并选择投票对象
    col1, col2 = st.columns([8,2])
    with col1:
        vote_id = st.selectbox("投票对象", [a["id"] for a in state.players])
        pass
    with col2:
        if st.button("开始投票"):
            for player in state.players:
                if player["id"] == "H":
                    continue
                text = response([
                    {"role":"system", "content":state.prompt.format(state.spy_word)},
                    {"role":"system", "content":"/vote "+"请根据描述历史记录选择要投出的玩家，下面是描述历史记录：\n"+"\n".join(state.description)+"\n"+"当前场上存活玩家id为：\n"+",".join([a["id"] for a in state.players])}
                    ])
                state.messages.append({"id":player["id"], "message": text})
                pass
            st.rerun()
            pass
        pass
        if st.button("投出玩家"):
            state.messages.append({"id":"host", "message":f"玩家{vote_id}被投票出局"})
            state.round += 1
            for player in state.players:
                if player["id"] == vote_id:
                    state.players.remove(player)
                    break
                pass
        ## 验证是否还有卧底存活
            spy_live = False
            for player in state.players:
                if player["dignity"] == "spy":
                    spy_live = True
                    break
                pass
            if not spy_live and state.players:
                state.messages.append({"id":"host", "message":"平民胜利！"})
                pass
            elif spy_live:
                ## 统计当前卧底人数，如果占据一半以上则卧底胜利
                spy_num = 0
                for player in state.players:
                    if player["dignity"] == "spy":
                        spy_num += 1
                        pass
                    pass
                if spy_num >= len(state.players)//2:
                    state.messages.append({"id":"host", "message":"卧底胜利！"})
                    pass
            st.rerun()
            pass
    human_live = False
    for player in state.players:
        if player["id"] == "H":
            human_live = True
            break
        pass
    if human_live:
        if des := st.chat_input():
            state.messages.append({"id":"H", "message":des})
            state.description.append("H:"+des)
            st.rerun()

