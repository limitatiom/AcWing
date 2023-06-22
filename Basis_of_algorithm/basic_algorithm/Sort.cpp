//
// Created by 21050 on 2023/4/6.
//
//快速排序：基于分治的思想：
/*
 * 1.确定分界点：l, r, mid = (r + l) / 2, 随机一个数
 * 2.调整区间：小于等于基准的在分界点左边， 大于等于基准的在分界点右边（可能存在基准和分界点的交换）
 * 3.递归处理左右两个区间
 */
/*
 * 法一：
 * 1.开辟新数组
 * 2.处理思路： 新数组分为两个区间
 * 3.扫描原数组中的每一个数
 * 4.左区间放小于等于基准的，右区间放大于基准的
 * 5.再返回
 * 法二：
 * 双指针：
 * 1.左指针一直移动直至遇到大于等于基准的，停止
 * 2.右指针一直移动直至遇到小于基准的，停止
 */
#include <iostream>
using namespace std;
const int N = 1e6 + 10;

int m;
int q[N];

void swap(int *ob1, int *ob2){
    int x = *ob1;
    *ob1 = *ob2;
    *ob2 = x;
}

void quick_sort(int q[], int l, int r){
    if(l >= r) return;//没有数，或仅有一个数就不用排序了

    int pivot = q[l], i = l - 1, j = r + 1;//初始化基准，左右的指针分别指向边界的两侧
    //先移动再进行交换，所以要放在边界的两侧
    while(i < j){
        do i++; while(q[i] < pivot);//小于的不动
        do j--; while(q[j] > pivot);
        if(i < j) swap(&q[i], &q[j]);//如果指针还未相遇交换
    }
    quick_sort(q, l, j);//注意取j为右边界的话，基准就不能设置为右边界，否则会出现边界问题
    quick_sort(q, j + 1, r);
    /*
     * quick_sort(q, l, i - 1);
     * quick_sort(q, i, r);
     */
}

int main(){
    scanf("%d",&m);
    for(int i = 0;i<m;i++) scanf("%d", &q[i]);

    int l = 0, r = m - 1;
    quick_sort(q, l ,r);

    for(int i = 0;i<m;i++) printf("%d ", q[i]);
    return 0;
}