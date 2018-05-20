#实验1：排序算法比较

##实验目的：掌握分治法、键值比较排序

###实现算法1：插入排序
>INSERTION-SORT(A)
1  for j ← 2 to length[A]
2  		do key ← A[j]
3 		     ▹ Insert A[j] into the sorted sequence A[1，j - 1].
4 		    i ← j - 1
5 		    while i > 0 and A[i] > key
6 			do A[i + 1] ← A[i]
7 			     i ← i - 1
8             A[i + 1] ← key

###实现算法2：归并排序
MERGE-SORT(A,p,r)


###实现算法3：快速排序
>PARTITION(A, p, r) 
1 x ← A[p] 
2 i ← p
3 for j ← p+1 to r 
4 		do if A[j] ≤ x 
5 			then i ← i + 1 
6 				exchange A[i] ↔ A[j] 
7 exchange A[i] ↔ A[p]
8 return i

>QUICKSORT(A, p, r) 
1 if p < r 
2 		then q ← PARTITION(A, p, r) 
3 			QUICKSORT(A, p, q - 1) 
QUICKSORT(A, q + 1, r) 

>Initial call：QUICKSORT(A, 1, length[A]) 

##测试
随机产生100，000个数

srand()

rand()

记录各种算法的运行时间

-time
