//
// Created by 21050 on 2023/6/22.
//
/*
 * 并查集：用于快速地处理以下问题：
 * 1. 将两个集合合并
 * 2. 询问两个元素是否在一个集合当中
 * 3. 在近乎O(1)的时间复杂度之内完成
 *
 * 原理：1.集合以树的形式维护
 * 2. 每个集合的编号以根节点为准
 * 3. 每个节点存储它的父节点，即p[x]表示x的父节点的地址，x是当前节点的位置
 *
 * 问题1：如何判断树根，除了根节点之外，p[x]都不等于x if(p[x] == x)
 * 问题2：如何求x的集合编号: while(p[x] != x) x = p[x];
 * 问题3：如何求x,y是否在同一集合，即判断x,y的编号是否相等
 * 问题4：如何合并两个集合，给两个集合加上同一个根节点, p[x] = y;//根节点指向另一个根节点
 *
 * 优化：当一条路径上的点找到根节点时，直接将该条路径所有的点的父节点设为根节点
 * 这个优化叫路径压缩
 */

#include <iostream>

int main(){


    return 0;
}