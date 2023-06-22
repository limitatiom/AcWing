//
// Created by 21050 on 2023/4/27.
//
/* 区间合并：
 * 将两个及以上区间的并集当作一个新的区间
 * 注意:两个区间，即使只有端点相交，也是可以进行合并的
 * 解决思路：贪心算法
 * 1.按照所有区间的左端点进行升序排序
 * 2.扫描整个区间，扫描过程将所有有可能有交集的区间进行合并
 *      具体操作：维护一个当前区间，假设已经扫描到了第i个区间（第i区间左端点大于等于当前区间左端点的），第i个区间和我当前区间的关系：
 *      1.第i个区间在我当前区间的内部
 *      **********
 *        *****
 *      2.第i个区间与我当前区间有交集，但并非包含
 *      **********
 *             ********
 *      3.第i个区间与我当前区间没有交集
 *      **********
 *                   **********
 *      操作：
 *      1.第一种情况：当前区间无需变动
 *      2.第二种情况：需要延长右端点，移动到第i个区间的右端点
 *      3.第三种情况：因为从左到右排序左端点，如果第i个区间与当前区间完全没有交点，则说明我们已经找到了一个独立的区间，计数器加一，将我们当前维护的区间更新为第i个区间
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

typedef pair<int, int> pir;

int n;
vector<pir> seg;

void merge(vector<pir> &src){
    vector<pir> res;
    sort(src.begin(), src.end());//pair排序，C++中，默认先以左端点进行排序，然后再以右端点排序
    int st = -2e9, ed = -2e9;//起始区间的范围
    for(auto i : src){
        if(ed < i.first){//没有交集的情况
            if(st != -2e9) res.emplace_back(st, ed);//并非初始区间的话，加入答案
            st = i.first, ed = i.second;//更新区间
        } else ed = max(ed, i.second);
    }
    if(st != -2e9) res.emplace_back(st, ed);//并非起始区间加入答案
    src = res;
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        seg.emplace_back(l, r);
    }
    merge(seg);
    printf("%d", seg.size());
    return 0;
}