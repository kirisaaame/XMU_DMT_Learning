# 第十章 面向对象（上）

## 10.1 面向对象的概念
## 10.2类和对象
## 10.3 类的定义和使用
## 10.4 属性和方法
属性分为类属性和对象属性。其中，类属性可以直接通过类修改，而对象属性不能这么做。对象属性可以直接通过实例代码修改，也可以在类方法中定义。
```python
class A:
    company = 0
    def __init__(self,value):
        company = value

b = A(1)
b.company = 2
b.attib = 3 #通过实例代码添加属性
print(b.attib)
```
```python
#通过方法添加属性
class A:
    company = 0
    def __init__(self,value):
        self.company = value
    def newinfo(self):
        self.friend =1

b = A(1)
b.newinfo()
print(b.friend)
```
你也可以使用`del`方法删除对象的属性

### 类方法
类方法是使用修饰器`@classmethod`修饰的方法，系统会自动调用类作为参数传入，以修改类属性的方法。
```python
class A:
    company = 0
    def __init__(self,value):
        self.company = value
    @classmethod
    def NewInfo(cls):
        cls.company =1
```
除了类方法，还有常见的静态方法(`@staticmethod`)

### 便捷的访问私有属性
使用`@property`方法，可以把方法变成属性，从而通过属性访问来访问方法。


# 第十一章 面向对象（下）
## 11.1 面向对象的三大特性
面向对象的三大特性是**封装、继承和多态**。
## 11.2 封装
封装只展现对象的外在功能而将具体细节隐藏起来，使得代码更加容易维护而且，同时一定程度上保证了系统的安全。
## 11.3 继承 
继承增加了代码的复用性，还提高了开发效率，并且为程序后期的维护提供了便利。
### 11.3.1 单继承
### 11.3.2 isinstance()函数和issubclass()函数
`isinstace()`函数的参数为对象名和类名，返回值代表该对象是否属于该类。

`issubclass()`函数的参数为子类名和父类名，返回值代表该子类是否确实继承自该父类。
### 11.3.3 多继承
### 11.3.4 重写
### 11.3.5 覆盖，super关键字
使用super关键字可以访问父类的同名方法，而不是子类的重写方法。
## 11.4 多态
同一个属性和方法在父类和子类之中有着不同的定义，是一种十分常见的多态性。
## 11.5 运算符重载
常见的运算符重载方法如下：
`__init__()`:构造函数

`__add__()`:加法

`__sub__()`:减法

`__mul__()`:乘法

`__truediv__()`:除法

`__floordiv__()`:整除

`__bool__()`:判断

`__repr__(),__str()`:打印

`__contains__()`:检查包含

`__getitem__()`:切片和索引

`__delitem__()`:删除

`__setitem__()`:设置

`__len__()`:长度检查
## 11.6 `__new__`方法
`__new__`方法是object类的一个静态方法，它可以用于生成一个实例化的类，在构造函数中，这个方法的优先级高于`__init__`，因为先创建对象然后才初始化。

该方法至少要有一个参数cls,在方法最后返回cls。
## 11.7 单例模式
可以设置参数来确定某类的多个对象指向一个实例。
```python
class A:
    __instance = None
    __firstInit = False
    def __new__(cls, age,name):
        if not cls.__instance:
            cls.__instance = object.__new__(cls)
        return cls.__instance
    def __init__(self,age,name):
        if not self.__firstInit:
            self.age = age
            self.name = name
            A.__firstInit = True
```
### 11.8 工厂模式
工厂模式类似于C++的类模板，根据传入的参数选择对应的对象生成。不同的是，Python的工厂模式相比C++具有更高的自由度，生成的类差别也允许比较大。
```python
class Mobile(object):
    def __init__(self):
        self.name = None
        self.price = None
    def getName(self):
        return self.name
    def getPrice(self):
        return self.price
class HuaweiMobile(Mobile):
    def __init__(self):
        print("生产一部Huawei手机")
class VivoMobile(Mobile):
    def __init__(self):
        print("生产一部Vivo手机")
class MobileFactory:
    def getMobile(self,name):
        if name == "Huawei":
            return HuaweiMobile()
        elif name == "Vivo":
            return VivoMobile()
```
# 第十二章 错误与异常
## 12.1 错误和异常简介
当代码执行语法或者逻辑发生错误时，程序就会抛出异常。
### 12.1.1 异常
默认的异常处理方式是程序崩溃。
### 12.1.2 Python 常见异常
- `SyntaxError` 语法错误
- `ZeroDivisionError` 除数为0时报错
- 
# 第十三章 模块

# 第十四章 内存管理

# 第十五章 正则表达式

# 第十六章 图形用户界面编程

# 第十七章 多任务编程

# 第十八章 网络编程

# 第十九章 数据库编程

# 第二十章 WEB编程
