from django.db import models

# 创建问答知识库表
class QuestionAnswerKB(models.Model):
    question = models.TextField()
    answer = models.TextField()
    def __str__(self):
        return self.question

# 创建索引表
class QuestionIndex(models.Model):
    keyword = models.CharField(max_length=256)
    doclist = models.TextField()
    def __str__(self):
        return self.keyword
