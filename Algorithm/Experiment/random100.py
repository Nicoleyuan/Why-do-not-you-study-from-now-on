#coding: utf-8
#!/usr/bin/python
import random

#随机生成0~100之间的数值
def get_andomNumber(num):
    lists=[]
    i=0
    while i<num:
        lists.append(random.randint(0, 100))
        i+=1
    return lists

'''
a = get_andomNumber(10)
print("随机数：%s" %a)
'''