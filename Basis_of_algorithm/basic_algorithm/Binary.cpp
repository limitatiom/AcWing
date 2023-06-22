//
// Created by 21050 on 2023/4/7.
//
/*
 * 整数二分：有单调性一定可以二分，能二分的未必具有单调性
 * 应用：当一个数组中有一半满足一个性质，另一个不满足，就可以使用，来寻找边界
 */
/* mid应使条件成立
 * 如果mid右边区间满足的条件
 * 1. 寻找中间值：mid = (l + r + 1) / 2 （注意加一， C++中的取整向下取整，如果没有加一的话，当l = r - 1时，右区间将始终不变，进入死循环）
 * 2. 检测Mid是否满足条件，然后分支
 * 3. true: [mid, r], l = mid(满足的是右区间)
 * 4. false: [l, mid - 1], r = mid - 1
 * 如果mid左边区间满足条件
 * 1. mid = (l + r) / 2
 * 2. check(mid)
 * 3. true: [l, mid]（左区间满足）
 * 4. false: [mid + 1, r]
 */
/*
 * 1. 先写一个check函数
 * 2. 思考check函数如何更新
 */
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n,m;
int q[N];//升序有序数组

int main(){
    scanf("%d %d",&n, &m);
    for(int i = 0;i<n;i++) scanf("%d",&q[i]);

    while(m--){
        int x;
        scanf("%d",&x);

        int l = 0, r = n - 1;
        while(l < r) {//确定左边界，即右边数组是全是大于等于x的，寻找右边的第一个数
            int mid = (l + r) >> 1;//÷2
            if (q[mid] >= x) r = mid;//true: mid应该存在条件中
            else l = mid + 1;//false分支: q[mid] < x, 不满足条件
        }
        if(q[l] != x) cout << "-1 -1" << endl;//二分无解的问题：寻找到的答案不满足题意
        else {
            cout << l << " ";

            l = 0, r = n - 1;
            while(l < r){//寻找右边界，相等时跳出
                int mid = (l + r + 1) >> 1;
                if(q[mid] <= x) l = mid;//true, 左边全是小于等于的, 寻找左边的最后一个, mid始终满足于条件
                else r = mid - 1;//false
            }
            cout << l << endl;
        }
        //保证区间里面有答案！！，即满足条件的范围一定要包含mid
        //每一次判断答案落在那一边，确保答案始终在区间中
    }

    return 0;
}