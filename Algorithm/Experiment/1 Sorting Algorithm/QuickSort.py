# coding: utf-8
# !/usr/bin/python
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
#快速排序
def quick_sort(lists,left,right):
	if left < right:
		mid = partition(lists, left, right)

		quick_sort(lists, left, mid - 1)
		quick_sort(lists, mid + 1, right)
	else:
		return

def partition(lists, left, right):
		mid = left
		temp = lists[left]
		while left < right:
			while left < right and lists[right] >= temp:
				right -= 1
			lists[left] = lists[right]
			while left < right and lists[left] <= temp:
				left += 1
			lists[right] = lists[left]
		lists[right] = temp
		return right

'''
def quick_sort(lists, left, right):
	if left >= right:
		return lists
	key = lists[left]
	low = left
	high = right
	while left < right:
		while left < right and lists[right] >= key:
			right -= 1
		lists[left] = lists[right]
		while left < right and lists[left] <= key:
			left += 1
		lists[right] = key
		quick_sort(lists, low, left - 1)
		quick_sort(lists, left + 1, high)
		return lists
'''


a = get_andomNumber(100000)
'''print("排序之前：%s" % a)


b = quick_sort(a,0,len(a) - 1)
print("排序之后：%s" % b)
'''

end = time.clock()
print('Quick_Sort Running time: %s s'%((end-start)*60))
