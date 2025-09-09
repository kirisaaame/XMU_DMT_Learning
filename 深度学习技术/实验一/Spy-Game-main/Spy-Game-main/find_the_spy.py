import streamlit as st
from random import choices
from openai import OpenAI

state = st.session_state

# title
st.title("找出AI中的卧底😎")
st.caption("“找出AI卧底”游戏平台，AI时代已经到了，但人类对AI的了解并不彻底。在这场没有硝烟的战争中，你将担任人类阵营的侦察员，找出AI中的伪装者……\n由东北大学数据挖掘实验室、书生·浦语、LangGPT开源社区等提供支持。")

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
}

# define the state of the game and save some data
if "messages" not in state:
    state.messages = []
    pass
if "players" not in state:
    state.players = []
    pass
if "client" not in state:
    state.client = OpenAI(
        api_key="internlm2",
        base_url="http://0.0.0.0:23333/v1"
    )
    pass
if "max_round" not in state:
    state.max_round = 100
    pass
if "round" not in state:
    state.round = 0
    pass

def generate(prompt):
    return state.client.chat.completions.create(
        model=state.client.models.list().data[0].id,
        messages=[{"role":"system", "content":prompt}],
        max_tokens=100
    ).choices[0].message.content

with st.sidebar:
    st.write("游戏设置")
    with st.form(key="game_setting"):
        spy_word = st.text_input("卧底关键词", "黄桃")
        civilian_word = st.text_input("平民关键词", "黄瓜")
        total_num = st.number_input("总人数", 5, 10, 5)
        spy_num = st.number_input("卧底人数", 1, total_num//2, 1)
        max_round = st.number_input("最大回合数", 5, 10, 10)

        submitted = st.form_submit_button("保存设置")

        if submitted:
            state.spy_word = spy_word
            state.civilian_word = civilian_word
            state.total_num = total_num
            state.spy_num = spy_num
            state.max_round = max_round
            state.players = [{"id":"P"+str(i+1)} for i in range(total_num)]
            spy_id = choices([f"P{a}" for a in list(range(1,total_num+1))], k=state.spy_num)
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

with st.container(height=300):
    for message in state.messages:
        st.chat_message(message["id"], avatar=avatar_dict[message["id"]]).write(message["message"])
        pass

if state.round < state.max_round:
    if "description" not in state:
        state.description = []
        pass
    start = st.button("开始第{}轮游戏".format(state.round+1))
    if start:
        if "round" not in state:
            state.round = 0
            pass
        state.messages.append({"id":"host", "message":f"第{state.round+1}轮游戏开始"})
        civilian_prompt = """
# Role: 卧底游戏玩家

## Profile
- author: LangGPT 
- version: 1.0
- language: 中文
- description: 一个卧底游戏的玩家，身份是平民。

## Goals:
根据关键词进行描述，避免与已有描述重复。

## Background:
你正在参与一场卧底游戏，你被分配到的角色是平民。
-  关键词：{}
-  已有描述：{}

## OutputFormat:
- 一句话描述关键词，不超过20字。

## Constraints
- 输出不能超过20字。
- 不能直接说出关键词。
- 描述不能与已有描述重复。
- 描述需要符合你的关键词。

## Workflows
1. 收集关键词和已有描述。
2. 设计初步的描述，确保不超过20字且不直接说出关键词。
3. 检查描述是否与已有描述重复。
4. 提供最终的描述。

## Initialization
开始游戏，根据你收到的关键词和已有描述，提供你的描述。
"""
        spy_prompt = """
# Role: 卧底游戏玩家

## Profile
- author: LangGPT 
- version: 1.0
- language: 中文
- description: 一个卧底游戏的玩家，身份是卧底。

## Background:
- 你正在参与一场卧底游戏，你被分配到的角色是卧底。
- 你的关键词：{}
- 平民的关键词：{}
- 已有描述：{}

## Goals:
- 根据关键词进行描述，避免与已有描述重复。
- 根据平民关键词进行伪装。

## OutputFormat:
- 一句话描述关键词，不超过20字。

## Constraints
- 输出不能超过20字。
- 不能直接说出关键词。
- 描述不能与已有描述重复。
- 描述需要符合你的关键词。

## Workflows
1. 收集关键词、平民的关键词和已有描述。
2. 设计初步的描述，确保不超过20字且不直接说出关键词。
3. 根据平民关键词进行伪装。
4. 检查描述是否与已有描述重复。
5. 提供最终的描述。

## Initialization
开始游戏，根据你收到的关键词、平民的关键词和已有描述，提供你的描述。
"""
        for player in state.players:
            if player["dignity"] == "spy":
                text = generate(spy_prompt.format(state.spy_word, state.civilian_word, "\n".join(state.description)))
                # text = f"我是卧底，关键词是{state.spy_word}"
                state.messages.append({"id":player["id"], "message": text})
                state.description.append(text)
            else:
                text = generate(civilian_prompt.format(state.civilian_word, "\n".join(state.description)))
                # text = f"我是平民，关键词是{state.civilian_word}"
                state.messages.append({"id":player["id"], "message": text})
            pass
        st.rerun()
    vote_id = st.selectbox("选择要投出的玩家", [a["id"] for a in state.players])
    if st.button("投票"):
        state.messages.append({"id":"host", "message":f"玩家{vote_id}被投票出局"})
        state.round += 1
        for player in state.players:
            if player["id"] == vote_id:
                state.players.remove(player)
                break
            pass
        # 验证是否还有卧底存活
        spy_live = False
        for player in state.players:
            if player["dignity"] == "spy":
                spy_live = True
                break
            pass
        if not spy_live and state.players:
            state.messages.append({"id":"host", "message":"平民胜利！"})
            pass
        st.rerun()

