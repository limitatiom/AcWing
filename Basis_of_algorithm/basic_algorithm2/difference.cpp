//
// Created by 21050 on 2023/4/9.
//
//差分为前缀和的逆运算，
//给我们一个数组（a1,a2,a3,a4,a5,..an），构造b数组（b1,b2,b3,b4,b5,b6..bn）
//使得a数组是b数组的前缀和
//差分的作用：知道b数组就能用o(n)的时间求和得到a数组，如想要将区间[l, r]中的a数组的每一个都加上一个常数，使用差分就只需要o(1)的时间复杂度
//只需使b[l] + c， b[r + 1] - c即可，
//差分数组的初始化，相当于进行了n次插入操作，例如：假定a数组初始值都是0, a[i] = c, 即是对b[i, i]这个区间中的元素进行了 + c操作
/*
#include <iostream>
#define F(n) for(int i = 1;i<=n;i++)

using namespace std;

const int N = 1e6 + 10;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c){
    b[l] += c;
    b[r + 1] -= c;
}

int main(){
    scanf("%d%d", &n, &m);
    F(n) scanf("%d", &a[i]);
    F(n) insert(i, i, a[i]);//初始化差分数组

    while(m--){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    F(n) b[i] += b[i - 1];//得到改造过的a数组
    F(n) printf("%d", b[i]);
    return 0;
}*/

//二维差分矩阵:
//原矩阵a[i, j]
//差分矩阵b[i, j]
//使得a[i, j] = b[i, j]的前缀和
//假定a[i, j]全为0， 则显然b[i, j]也全为0
//给其中的一个子矩阵加上一个值， b[x1, y1] += c,效果a数组x1行y1列右下角的元素全部加上c，作为修正：b[x2 + 1, y1] -= c, b[x1, y2 + 1] -= c, b[x2 + 1, y2 + 1] += c;
//还原就求前缀和

#include <iostream>
#define F(n, m) for(int i = 1; i <= n;i++)for(int j = 1;j<=m;j++)

using namespace std;

const int N = 1e3 + 10;

int n,m,q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    F(n, m) scanf("%d", &a[i][j]);
    F(n, m) insert(i,j,i,j,a[i][j]);
    while(q--){
        int x1,y1,x2,y2,c;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        insert(x1,y1,x2,y2,c);
    }
    F(n, m) b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    F(n ,m) printf("%d ", b[i][j]);
    return 0;
}