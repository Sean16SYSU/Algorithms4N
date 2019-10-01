# 归并排序 MergeSort

* 假设已经存在有两个有序的序列，通过Merge的操作变成一个有序的序列。
* MergeSort则是通过递归的方式，先取定一个分界点，让左右两个子列分别做MergeSort，之后，再通过Merge的操作，合并成一条有序的序列。

至少要O(n logn),最多要O(n logn)

f(n) = 2 * f(n/2) + c * n

![](MergeSort.gif)