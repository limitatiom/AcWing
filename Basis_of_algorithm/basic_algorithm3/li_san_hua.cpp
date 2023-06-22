//
// Created by 21050 on 2023/4/25.
//
/*
 * 离散化：与哈希表相结合
 * 把一个整数数组中的值映射到从0开始的连续的自然数
 * 例如：a[i]: 1, 3, 100, 200, 2000
 * 映射：下标： 0, 1, 2, 3, 4
 * 该过程就被称为离散化
 *
 * 离散化的小问题：
 * 1. a[]中可能有重复元素，需要去重
 * 2. 需要将a[]中的值快速映射，需要算出a[i]离散化后的值(此处采用保序的离散化，下的值放在前面)，由有序知，可以采取二分查找
 * 对于源数组的初始排序和去重使用库函数完成
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
vector<int> allS;

int find(int x){//找到第一个大于等于x的位置
    int l = 0, r = allS.size() - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(allS[mid] >= x) r = mid;//只要allS[mid]>=x，r就会等于mid, 向左移动
        else l = mid + 1;
    }
    return r + 1;//映射到1到n的下标
}

int main(){
    //离散化：

    sort(allS.begin(), allS.end());//初始的有序化
    allS.erase(unique(allS.begin(), allS.end()), allS.end());//C++中的unique函数是将所有重复的元素放置于容器的后面，并且返回重复部分起始的下标

    return 0;
}
*/
/*
 * 应用：一个无限长的数轴，前后无限长，n个操纵，每次操作将某个位置上的数加上C，
 * m个询问，询问某个区间上的数的总和
 * 1. 前缀和：数组范围较小
 * 2. 离散化：数据跨度很大，但是数据的总数很少，将其与前缀和相结合
 * 求从下标为Kl - Kr到上的a[]的总和.
 *
 */

const int N = 3 * 1e5;

typedef pair<int, int> pir;//值和其映射

int n,m;
int a[N], S[N];
vector<int> allS;
vector<pir> add, query;//加上和查询一个数用pir进行

int find(int x){
    int l = 0, r = allS.size() - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(allS[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;//寻找其在新映射中的下标，用前缀和做
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i<n;i++){
        int x, c;
        scanf("%d%d", &x, &c);
        add.emplace_back(x, c);//所有的插入操作，在x位置加上c

        allS.push_back(x);//为将下标x离散化，故需要将x加入待离散化的数组中
    }
    for(int i = 0;i<m;i++){
        int l, r;
        scanf("%d%d",&l,&r);
        query.emplace_back(l, r);//所有查询的区间

        allS.push_back(l);
        allS.push_back(r);//将所有区间加入待离散化的数组
    }
    //allS数组包含了所有待用的下标
    sort(allS.begin(), allS.end());//排序
    allS.erase(unique(allS.begin(), allS.end()), allS.end());//去重,去除重复的下标

    //插入操作：
    for(auto item: add){
        int x = find(item.first);//寻找原下标其映射对应的下标，按着升序
        a[x] += item.second;//将要插入的数放入一离散化的下标的数组中
    }

    //预处理前缀和：
    for(int i = 1;i<=allS.size();i++) S[i] = S[i - 1] + a[i - 1];

    //处理询问:
    for(auto item:query){
        int l = find(item.first), r = find(item.second);
        cout << S[r] - S[l - 1] << endl;
    }
    return 0;
}

/*
 * unique函数的实现：
 * 元素是不同的满足的条件为:
 * 1. 它是第一个
 * 2. 他和前一个元素不一样
 * 双指针：
 * 1. 第一个遍历所有的数
 * 2. 第二个存储了多少个不同的数
 */

vector<int>::iterator my_unique(vector<int> &a){
    int j = 0;
    for(int i = 0;i<a.size();i++)
        if(i == 0 || a[i] != a[i - 1])
            a[j++] = a[i];
        //从0~j-1存储的都是不同的数；
    return a.begin() + j;
}