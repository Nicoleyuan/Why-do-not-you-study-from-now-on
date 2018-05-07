#coding: utf-8
#!/usr/bin/python
import time
from random100 import get_andomNumber

'''
#随机生成0~100之间的数值
def get_andomNumber(num):
    lists=[]
    i=0
    while i<num:
        lists.append(random.randint(0, 100))
        i+=1
    return lists
'''

start =time.clock()
# 插入排序
def insert_sort(lists):
    count = len(lists)
    for i in range(1, count):
        key = lists[i]
        j = i - 1
        while j >= 0:
            if lists[j] > key:
                lists[j + 1] = lists[j]
                lists[j] = key
            j -= 1
    return lists


a = get_andomNumber(100000)
'''print("排序之前：%s" %a)

b = insert_sort(a)
print("排序之后：%s" %b)
'''

end = time.clock()
print('Insertion_Sort Running time: %s s'%((end-start)*60))