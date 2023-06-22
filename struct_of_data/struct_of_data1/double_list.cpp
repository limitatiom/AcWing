//
// Created by 21050 on 2023/5/5.
//
/*
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int m, idx;
int e[N], l[N], r[N];//l左节点指向的下标，r右节点指向的下标,0表示左端点，1表示右端点

void init(){
    r[0] = 1;//左端点的右边为1号点
    l[1] = 0;//右端点的左边为0号点
    idx = 2;
}

void add(int k, int x){
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
}//在k的左边插入一个点，等效于在l[k]的右边插入一个点

//删除一个点
void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main(){

    return 0;
}*/
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int head, tail, e[N], l[N], r[N], idx;

void init(){
    head = -1;
    tail = -1;
    idx = 0;
}//头到0为止，尾到一为止

void add_to_head(int x){
    e[idx] = x;
    if(head == -1){
        l[idx] = -1;
        r[idx] = -1;
        tail = idx;
    } else {
        r[idx] = head;
        l[idx] = -1;
        l[head] = idx;
    }
    head = idx;
    idx++;
}

void add_to_tail(int x){
    e[idx] = x;
    if(tail == -1){
        l[idx] = -1;
        r[idx] = -1;
        head = idx;
    } else {
        l[idx] = tail;
        r[idx] = -1;
        r[tail] = idx;
    }
    tail = idx;
    idx++;
}

void add_to_right(int k, int x){
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void add_to_left(int k, int x){
    e[idx] = x;
    r[idx] = k;
    l[idx] = l[k];
    r[l[k]] = idx;
    l[k] = idx;
    idx++;
}

void remove(int k){//直接删除第k个数
    if(head == tail){
        head = -1;
        tail = -1;
    } else if(k == head){
        head = r[k];
        l[r[k]] = -1;
    } else if(k == tail){
        tail = l[k];
        r[l[k]] = -1;
    } else {
        r[l[k]] = r[k];
        l[r[k]] = l[k];
    }
}

int main(){
    init();
    int M;
    scanf("%d", &M);
    while(M--){
        int k, x;
        char op;
        getchar();
        scanf("%c", &op);
        if(op == 'L'){
            scanf("%d", &x);
            add_to_head(x);
        } else if (op == 'R'){
            scanf("%d", &x);
            add_to_tail(x);
        } else if (op == 'D'){
            scanf("%d", &k);
            remove(k - 1);
        } else {
            char op2;
            scanf("%c", &op2);
            if(op2 == 'L'){
                scanf("%d%d", &k, &x);
                if(k - 1 == head) add_to_head(x);
                else add_to_left(k - 1,x);
            } else {
                scanf("%d%d", &k, &x);
                if(k - 1 == tail) add_to_tail(x);
                else add_to_right(k - 1, x);
            }
        }
    }
    for(int i = head;i != -1;i = r[i]) printf("%d ", e[i]);
    return 0;
}