//
// Created by 21050 on 2023/5/5.
//
/*
 * 栈：先进后出
 * 队列：先进先出
 */

/*
#include <iostream>

//栈
using namespace std;

const int N = 1e5 + 10;

int stk[N], tt;//tt表示栈顶的下标

//插入：
void push(int x){
    stk[++tt] = x;
}

//tt弹出：
void pop(){
    tt--;
}

//为空
bool isEmpty(){
    return tt > 0;
}

int top(){
    return stk[tt];
}

//队列：队尾插入元素，队头弹出元素
int q[N], h, t = -1;//队头:h, 队尾:t
// 队列： ***********************
//       hh                   tt

//插入：
void push_(int x){
    q[++t] = x;
}

//弹出：
void pop_(){
    h++;
}

//空队列：
bool is_empty(){
    return h > t;
}

//取出队头元素:
int top_(){
    return q[h];
}
 */

//单调栈和单调队列
//单调栈：给定一个序列，对于该序列中的一个数，求该序列左边离他最近的且比他小的数，不存在则返回-1
//存在如下关系：ax, ay均在ai左边，x < y, ax >= ay, ax永远不会被用到
//故每次都可以删除栈中元素，使得栈中元素呈现严格上升的趋势

/*
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int m;
int stk[N], tt;

int main(){
    scanf("%d", &m);

    for(int i = 0;i<m;i++){
        int x;
        scanf("%d", &x);
        while(tt && (stk[tt] >= x)) tt--;//栈非空 且 栈顶元素大于等于待定元素,即弹出栈顶，以确保栈中始终单调
        if(tt) printf("%d\n", stk[tt]);//如果结束后栈非空，则栈顶元素即是在待求元素左边第一个比它小的数
        else printf("-1\n");

        stk[++tt] = x;
    }
    return 0;
}*/

//单调队列：应用求滑动窗口中的最大值或最小值：
//单调队列来维护窗口
//暴力：遍历队列中的所有元素
//优化：寻找最小值：比队尾元素大且位于队头的元素永远无法被使用，则队头元素会被弹出，最终队列中的元素会成为一个单调上升的趋势
//取极值则可以寻找队列的端点，寻找一个值，则可以使用二分
//队列中存储的是下标并非值，故当队列中元素超出下标范围时[i - k + 1, i]，则可以将其弹出


#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int m, k;//总数和区间长度
int a[N], q[N];

int main(){
    scanf("%d%d", &m, &k);
    for(int i = 0;i<m;i++) scanf("%d", &a[i]);
    //最小值
    int hh = 0, tt = -1;//定义对头和队尾
    for(int i = 0;i<m;i++) {
        //判断队头是否已经滑出了窗口和是否为空队列
        while(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt--;//非空且队尾元素大于当前元素，弹出队尾，确保队列为单调上升
        q[++tt] = i;//将当前元素插入队尾,当前元素可能是最小元素，所以需要先加入单调队列中
        if(i >= k - 1) printf("%d ", a[q[hh]]);//从第k个数开始输出
    }
    //最大值
    hh = 0, tt = -1;//定义对头和队尾
    for(int i = 0;i<m;i++) {
        //判断队头是否已经滑出了窗口和是否为空队列
        while(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;//非空且队尾元素大于当前元素，弹出队尾，确保队列为单调下降
        q[++tt] = i;//将当前元素插入队尾,当前元素可能是最大元素，所以需要先加入单调队列中
        if(i >= k - 1) printf("%d ", a[q[hh]]);//从第k个数开始输出
    }
    return 0;
}