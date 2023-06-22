//
// Created by 21050 on 2023/4/14.
//
//双指针算法类型：
/*
 * 1. 两段序列，两个指针，分别指向两个序列的开头，如：归并排序
 * 2. 一段序列，两个指针，分别指向开头和结尾，如：快速排序
 */
/*
 * 代码的一般写法：
 * for(int i = 0, j = 0;i<n;i++){
 *      while(j < i && check(i, j)) j++;//j在一个合理的范围内，并且i,j满足某种条件
 *      //每道题目的具体逻辑
 * }
 */
/*
 * 核心思想将二重循环的复杂度优化为o(n)，适用于满足某种性质能化简的数组
 */
/*
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3 + 10;

int main(){
    char str[1000];
    gets(str);//输出一句话中的所有单词
    int len = strlen(str);
    for(int i = 0;i<len;i++){
        int j = i;//假定字符串开头没有空格，且单词之间由空格隔开
        while(j < len && str[j] != ' ') j++;//指向一个单词的开头和结尾
        //具体的操作
        for(int k = i;k < j;k++) cout << str[k];
        cout << endl;
        i = j;//跳过整个区间
    }
    return 0;
}*/

//最长连续下降序列：
//一般入手都可以从暴力的做法开始
/*
 * 朴素做法：
 * for(int i = 0;i < n;i++)//枚举终点
 *      for(int j = 0;j<=i;j++)//枚举起点
 *          if(check(i, j)){//检测是否满足条件
 *              res = max(res, i - j + 1);
 *          }
 * 优化：本质上是寻找i, j的规律
 * 规律：当终点向后移动时，起点要么向后移动，要么不走，不会往前，因为移动的原因就是之间的区间有重复
 * 故优化思路便是，仅移动i终点，然后观察j走不走
 */
#include <iostream>

using namespace std;

/*
bool check(int r, int l, const int nums[]){
    for(int i = l;i < r;i++){
        if(nums[i] == nums[r]) return false;
    }
    return true;
}*/
const int N = 1e5 + 10;
int nums[N], S[N];//S记录当前区间中数的出现次数，每当有一个数i进区间，S[a[i]]++,每有一个j出区间，S[a[j]]--;

int main(){
    int n, _max = 0;
    scanf("%d", &n);

    for(int i = 0;i<n;i++) scanf("%d", &nums[i]);
    for(int i = 0, j = 0;i<n;i++){
        //while(j < i && !check(i, j, nums)) j++;法一
        //法二：利用哈希表动态管理
        S[nums[i]]++;
        while(S[nums[i]] > 1){
            S[nums[j]] --;//j出队列,哈希表！！！！！！！！！！！！！！！！！
            j++;
        }
        _max = _max > i - j + 1 ? _max : i - j + 1;
    }
    printf("%d", _max);
    return 0;
}
