//
// Created by 21050 on 2023/4/9.
//
//前缀和：如果有一个长度为n的数组（a1, a2, a3, a4, a5, a5.. an），前缀和sn就为sum(a1 ,a2, a3, a4, a5, .. an)
//如何求Sn?Sn用来干什么?
//如何求Sn：for(int i = 0;i<=n;i++) S[i]/*前i个数的和*/ = S[i - 1]/*前i-1个数的和*/ + a[i];
//Sn用来干什么? 求解区间[l, r]之间数的和，S[r] - S[l - 1]，时间复杂度为o(1)
//Sn下标从1开始，定义S[0] = 0
/*
#include <iostream>
#define F(n) for(int i = 0;i<=n;i++)

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], s[N];

int main(){
    //ios::sync_with_stdio(false);//使得cin和标准读入不同步，可以加快cin速度
    scanf("%d %d",&n,&m);
    F(n) scanf("%d", &a[i]);

    F(n) s[i] = s[i - 1] + a[i];
    while(m--){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}
*/
//二维前缀和：求出某个子矩阵中的和，s[i, j]是整个i行j列左上角的和
//具体求一个子区间的和，一个区间[x, y]和[i, j], 和 = S[x, y] - S[l, y] - S[x, r] + S[l, r]/*多减的*/
//初始化S[i, j] = S[i - 1, j] + S[i, j - 1] - S[i - 1, j - 1]/*多加的*/ + a[i , j]
#include <iostream>
#define F(n, m) for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)

const int N = 1e3 + 10;

int n, m, q;
int a[N][N], S[N][N];

int main(){
    scanf("%d%d%d", &n,&m,&q);
    F(n, m) scanf("%d", &a[i][j]);
    F(n, m) S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];//求前缀和
    while(q--){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", S[x2][y2] - S[x2][y1] - S[x1][y2] + S[x1][y1]);//算部分和
    }
    return 0;
}