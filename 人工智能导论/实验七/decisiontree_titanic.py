# decisiontree_titanic.py

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, export_graphviz
import graphviz

if __name__ == "__main__":
    # 1. 加载数据
    df = pd.read_csv('./data/titanic.csv')
    # 简单预处理
    df = df.dropna(subset=['Age','Fare','Embarked'])
    df['Embarked'] = df['Embarked'].astype(str)
    df['Sex'] = df['Sex'].map({'male': 0, 'female': 1})

    features = ['Pclass','Sex','Age','Fare','SibSp','Parch','Embarked']
    X = pd.get_dummies(df[features], drop_first=True)
    y = df['Survived'].astype(int)

    # 2. 划分集
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42
    )

    # 3. 训练
    clf = DecisionTreeClassifier(max_depth=4, random_state=42)
    clf.fit(X_train, y_train)
    acc = clf.score(X_test, y_test)
    print(f"[DecisionTree] Test Accuracy = {acc:.4f}")

    # 4. 导出并保存可视化
    dot_data = export_graphviz(
        clf,
        out_file=None,
        feature_names=X.columns,
        class_names=['NotSurvived','Survived'],
        filled=True, rounded=True,
        special_characters=True
    )
    graph = graphviz.Source(dot_data)
    graph.render('titanic_tree', format='png', cleanup=True)
    print("已生成决策树可视化: titanic_tree.png")
