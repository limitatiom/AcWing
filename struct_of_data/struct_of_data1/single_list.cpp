//
// Created by 21050 on 2023/5/4.
//
/*
 * 数组模拟单链表：邻接表
 * 邻接表应用：存储树和图，例如最短路问题等等
 * 双链表：优化某些问题
 * 单链表：
 * head->null
 * head->node->node->node->null
 * 使用一个数组来存储链表中的值，另一个数组来存储链表中的指针
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

//head表示头节点的下一个节点的下标
//e[i]表示对应下标节点的值
//ne[i]表示对应下标节点指向的下一个节点
//idx表示当前所用到的地址，当前idx之前的位置都是使用过的，故其只能增加
int head, e[N], ne[N], idx;

void init(){
    head = -1;//-1表示nullptr
    idx = 0;
}

//将x插入头节点
void add_node_to_head(int x){
    e[idx] = x;
    ne[idx] = head;//新节点的下一个节点指向head所指向的位置
    head = idx;//头指向当前插入的节点
    idx++;//idx移动到下一位
}

void add(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

//将下标为k的节点的下一位节点删除
void remove(int k){
    ne[k] = ne[ne[k]];//指向下一位的下一位
}

int main(){
    init();
    int m;
    scanf("%d", &m);
    while(m--){
        int k, x;
        char op;
        getchar();
        scanf("%c", &op);
        if(op == 'H'){
            scanf("%d", &x);
            add_node_to_head(x);
        } else if (op == 'D'){
            scanf("%d", &k);
            if(!k) head = ne[head];//删除头节点
            remove(k - 1);
        } else {
            scanf("%d%d", &k,&x);
            add(k - 1 ,x);//下标从0开始，第k个点其实下标为k
        }
    }
    for(int i = head; i != -1;i = ne[i]) printf("%d ", e[i]);
    return 0;
}