from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.feature_extraction import  DictVectorizer
import pandas as pd

def descision():

    iris = pd.read_csv('./data/iris.csv')

    # 处理数据，找出特征值和目标值
    x = iris[["petal_length","petal_width"]]

    y = iris["class"]


    # 分割数据集到训练集和测试集
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.25)

    # 进行处理(特征工程)
    dict = DictVectorizer(sparse=False)
    x_train = dict.fit_transform(x_train.to_dict(orient="records"))
    x_test = dict.transform(x_test.to_dict(orient="records"))

    # 用决策树进行预测
    dec = DecisionTreeClassifier()

    dec.fit(x_train, y_train)

    ret = dec.score(x_test, y_test)

    # 预测准确率
    print("预测的准确率为：", ret)


if __name__=="__main__":
    descision()