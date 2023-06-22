//
// Created by 21050 on 2023/6/20.
//
/*
 * trie树：1. 快速地存储和查找字符串集合数据结构
 * 2. 以后会应用到图论的算法
 *
 * 原理：1. 是以字典的形式存在
 * 2. 从根节点出发，依次判断当前单词的当前字母在trie树中是否存在，如不存在的话且左子树为空的话，则在左子树开辟一根新的节点链接
 * 若左子树存在则在右子树开辟一个新的节点，若当前字母在trie树中存在的话，则继续往下行走
 * 3. 若当前节点存在以该字母结尾的单词，则我们需要在当前节点处打上一个标记
 * 4.
 */

#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int son[N][26], cnt[N], idx;//son子树存储的当前子节点的下标，cnt以当前这个点结尾的单词有多少个，idx当前使用到的下标
//注意下标从0开始，下标为0的点，既是根节点，又是空节点，故当一个节点指向的下一个节点的地址为0时，说明已经到了叶节点
//将son[N][26]类比为树的话，行就对应的是地址，而列对应的就是值，而son[][]中节点存储的就是下一个节点的地址
//例如下标为x的点，他的所有子节点都存在了son[x][..]对应的值中，son[x][0]存储的就是第一个儿子...依次类推
//cnt[x]，即存储的是以地址x结尾的单词有多少个
char src[N];

void insert(char str[]){
    int p = 0;
    for(int i = 0;str[i];i++){
        int u = str[i] - 'A';
        /*将当前的子节点编号搞出来*/
        if(!son[p][u]) son[p][u] = ++idx;//如果son[p][u]的位置不存在节点
        p = son[p][u];//
    }
    cnt[p]++;//在这个深度结尾的单词数量多了一个
}

int query(char str[]){
    int p = 0;
    for(int i = 0;str[i];i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;//该节点为空，说明集合中不存在这个单词，返回空节点
        p = son[p][u];//否则前往下一个节点处
    }
    return cnt[p];//返回在p深度结尾的节点数量
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        char op[2];
        scanf("%s%s", op, src);
        if(op[0] == 'I') insert(src);
        else printf("%d\n", query(src));
    }
    return 0;
}