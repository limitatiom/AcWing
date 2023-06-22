//
// Created by 21050 on 2023/4/9.
//
//原理模拟:人工计算加减乘除
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define F(c) for(int i = c.size() - 1;i>=0;i--)

using namespace std;

const int N = 1e6 + 10;

vector<int> add(vector<int>& A, vector<int>& B){
    vector<int> C;

    int carry = 0;
    for(int i = 0; i<A.size()||i<B.size();i++){
        if(i < A.size()) carry += A[i];
        if(i < B.size()) carry += B[i];
        C.push_back(carry % 10);
        carry /= 10;
    }
    if(carry) C.push_back(carry);//检查最高位是否还有进位
    return C;
}

int AisLarger(vector<int>& A, vector<int>& B){
    auto len1 = A.size(), len2 = B.size();
    if(len1 > len2) return 1;
    else if(len1 < len2) return -1;
    else{
        F(A) {if(A[i] > B[i]) return 1; else if(A[i] < B[i]) return -1;}
        return 0;
    }
}

vector<int> sub(vector<int>& A, vector<int>& B){
    //默认A > B, 也就是确保大的数是被减数，如果A<B, 计算-(B-A)
    //每一步都是A[i] - B[i] - carry, 分为两种情况, 借位或者是不接位
    vector<int> res;
    int carry = 0;
    for(int i = 0;i<A.size();i++){
        carry = A[i] - carry;//计算有无借位
        if(i < B.size()) carry -= B[i];//减去B[i]
        res.push_back((carry + 10) % 10);//如果carry >= 0, 结果为carry本身， 故+ 10 % 10抵消， 如果carry小于0， 结果就为t + 10, % 10无影响
        if(carry < 0) carry = 1;
        else carry = 0;
    }
    //去掉前导0
    while(res.size() > 1/*只有一位，不能去掉*/ && res.back() == 0) res.pop_back();
    return res;
}

//乘法：高精度×低精度， 注意此处把低精度当作整体
vector<int> multiple(vector<int> &A, int B){
    vector<int> C;
    int carry = 0;
    for(int i : A){
        carry += i * B;
        C.push_back(carry % 10);
        carry /= 10;
    }
    if(carry) C.push_back(carry);
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

//除法：上一位的余数*10加上该位，商为结果数组该位，余数重复以上步骤
vector<int> div(vector<int> &A, int b, int& r){//r为余数
    vector<int> C;
    //除法从最高位开始计算
    r = 0;
    F(A){
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    string a, b;//a = "123456"
    vector<int> A, B;//注意数组是倒序存储！！
    cin >> a >> b;
    F(a) A.push_back(a[i] - '0');//A[6,5,4,3,2,1]
    F(b) B.push_back(b[i] - '0');

    /*
    auto C = add(A, B);
    F(C) printf("%d", C[i]);
     */
    /*
    int res = AisLarger(A, B);
    vector<int> ans;
    if(res > 0) ans = sub(A, B);
    else if(res < 0) { ans = sub(B, A); printf("-");}
    else {printf("0"); return 0;}
    F(ans) printf("%d", ans[i]);
     */
    /*
    auto C = multiple(A, 9999);
    F(C) printf("%d",C[i]);
     */
    int r;
    auto C = div(A, 76845, r);
    F(C) printf("%d", C[i]);
    cout << endl << r << endl;
    return 0;
}
