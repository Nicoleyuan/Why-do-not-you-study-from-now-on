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
#归并排序
def merge_sort(lists):
	if len(lists) <= 1:
		return lists
	mid = int(len(lists) / 2)
	left = merge_sort(lists[:mid])
	right = merge_sort(lists[mid:])
	return merge(left, right)

def merge(left,right):
    result=[]
    i,j=0,0
    while i<len(left) and j<len(right):
        if left[i]<=right[j]:
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+=1
    result+=left[i:]
    result+=right[j:]
    return result


a = get_andomNumber(100000)
'''print("排序之前：%s" %a)

b = merge_sort(a)
print("排序之后：%s" %b)
'''

end = time.clock()
print('Merge_Sort Running time: %s s'%((end-start)*60))
