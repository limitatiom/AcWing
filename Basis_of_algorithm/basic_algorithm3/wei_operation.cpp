//
// Created by 21050 on 2023/4/14.
//
//位运算：求n的二进制表示的第k位是几
/*
 * 1. 先把第k位移到最后一位， n >> k
 * 2. 看个位是几, x & 1
 */
/*
#include <iostream>

using namespace std;

int main(){
    int n = 10;
    for(int k = 3;k >= 0;k--) cout << (n >> k & 1);//从最高位开始

    return 0;
}
*/
/*
 * lowbit(x):返回x的最后一位1为起始的一个二进制数
 *  如：x = 1010b lowbit(x) = 10b
 *     x = 101000b lowbit(x) = 1000b
 * lowbit(x):实现： x & -x ,又由补码知，等效于x & (~x + 1)
 * 应用：统计x中1的个数，每次都把最后一位1指代的数去掉
 */

#include <iostream>

using namespace std;

int lowbit(int x){
    return x & -x;//返回了最后一个1所代表的数
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--) {
        int x, res = 0;
        scanf("%d", &x);
        while(x) x -= lowbit(x), res++;
        printf("%d ", res);
    }
    return 0;
}