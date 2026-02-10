# text.py

import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, export_graphviz
import graphviz

# 请根据你本地结构，保证能导入到你的 KMeans 实现
from k_means.k_means import KMeans  


def run_kmeans(features, X: pd.DataFrame, y_true: pd.Series):
    """对给定特征集跑 KMeans(K=2)，并映射簇标签到真实标签计算准确率。"""
    X_std = StandardScaler().fit_transform(X[features].values)
    km = KMeans(X_std, num_clusters=2)
    centroids, labels = km.train(max_iterations=100)
    labels = labels.flatten().astype(int)

    df_tmp = pd.DataFrame({'cluster': labels, 'true': y_true})
    mapping = {}
    for cid in [0, 1]:
        sub = df_tmp[df_tmp['cluster'] == cid]['true']
        mapping[cid] = int(sub.mode()[0]) if not sub.empty else 0
    y_pred = np.vectorize(mapping.get)(labels)
    acc = accuracy_score(y_true, y_pred)
    return acc, mapping


if __name__ == "__main__":
    # 1. 读取 CSV 并把所有列名转成小写
    df = pd.read_csv('./data/titanic.csv')
    df.columns = df.columns.str.strip().str.lower()
    print("读取后列名：", df.columns.tolist())

    # 2. 如果存在 'class' 列，则重命名为 'pclass'
    if 'class' in df.columns and 'pclass' not in df.columns:
        df = df.rename(columns={'class': 'pclass'})

    # 3. 丢弃关键列缺失值（包括 pclass）
    df = df.dropna(subset=['survived', 'age', 'fare', 'sex', 'embarked', 'pclass'])

    # 4. 把 pclass 文本映射成数值（First->1, Second->2, Third->3）
    df['pclass'] = (
        df['pclass']
        .astype(str)
        .str.lower()
        .map({'first': 1, 'second': 2, 'third': 3})
    )

    # 5. 性别映射
    df['sex'] = df['sex'].map({'male': 0, 'female': 1})

    # 6. K-Means 两组特征对比
    y = df['survived'].astype(int)
    experiments = {
        'age_fare': ['age', 'fare'],
        'pclass_age_fare': ['pclass', 'age', 'fare']
    }
    for name, feats in experiments.items():
        acc, mapping = run_kmeans(feats, df, y)
        print(f"[KMeans | {name}] Accuracy = {acc:.4f}, mapping = {mapping}")

    # 7. 决策树分类
    features = ['pclass', 'sex', 'age', 'fare', 'sibsp', 'parch', 'embarked']
    X = pd.get_dummies(df[features], drop_first=True)
    y = df['survived'].astype(int)

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42
    )
    clf = DecisionTreeClassifier(max_depth=4, random_state=42)
    clf.fit(X_train, y_train)
    dt_acc = clf.score(X_test, y_test)
    print(f"[DecisionTree] Test Accuracy = {dt_acc:.4f}")

    # 8. 导出并保存决策树可视化
    dot = export_graphviz(
        clf,
        out_file=None,
        feature_names=X.columns.tolist(),
        class_names=['not_survived', 'survived'],
        filled=True, rounded=True, special_characters=True
    )
    graphviz.Source(dot).render('titanic_tree', format='png', cleanup=True)
    print("已生成决策树可视化：titanic_tree.png")
