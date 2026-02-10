# k_means_titanic.py

import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score
from k_means import KMeans

def run_kmeans(features, X, y_true):
    # 标准化
    X_std = StandardScaler().fit_transform(X[features].values)
    # 自定义 KMeans (K=2)
    km = KMeans(X_std, num_clusters=2)
    centroids, labels = km.train(max_iterations=100)
    labels = labels.flatten().astype(int)

    # 将簇号映射到 Survived (0/1)
    df_tmp = pd.DataFrame({'label': labels, 'true': y_true})
    # 对每个簇，取出现率更高的 Survived 值作为该簇的预测
    mapping = {}
    for cluster_id in [0,1]:
        majority = df_tmp[df_tmp['label']==cluster_id]['true'].mode()[0]
        mapping[cluster_id] = majority
    y_pred = np.vectorize(mapping.get)(labels)

    acc = accuracy_score(y_true, y_pred)
    return acc, mapping

if __name__ == "__main__":
    # 1. 加载数据
    df = pd.read_csv('./data/titanic.csv')
    # 简单预处理：剔除缺失
    df = df.dropna(subset=['Age','Fare','Survived'])
    y = df['Survived'].astype(int)

    experiments = {
        'feat_Age_Fare': ['Age','Fare'],
        'feat_Pclass_Age_Fare': ['Pclass','Age','Fare']
    }

    for name, feats in experiments.items():
        acc, mapping = run_kmeans(feats, df, y)
        print(f"[KMeans | {name}] Accuracy = {acc:.4f}, mapping = {mapping}")
