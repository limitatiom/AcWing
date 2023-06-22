//
// Created by 21050 on 2023/4/7.
//
/*
 * 归并排序：分治
 * 1. 以中间点为分界，分为两侧， mid = (l + r) / 2
 * 2. 递归处理两侧数组，将左右变为有序的数组
 * 3. 将两个有序的数组归并为一个
 */
/*
 * 因为两个数组均有序，故最左边的一定是最小值，不断比较两个数组的最小值，将其添加进入新数组
 * 归并和快速排序的时间复杂度均是nlogn（以2为底）
 */

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void merge_sort(int q[], int l, int r){
    if(l >= r) return;//一个元素

    int mid = (l + r) / 2;

    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;//需要一个额外的结果数组来存储答案
    int tmp[r - l + 1];
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];//选择较小值
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];//观察还有没有剩余的
    for(i = l, j = 0;i<=r;i++, j++) q[i] = tmp[j];
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++) scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for(int i = 0;i<n;i++) printf("%d ", q[i]);
    return 0;
}