//
// Created by 21050 on 2023/4/7.
//
//浮点数二分法
#include <iostream>

using namespace std;

int main(){//计算平方根
    double x;
    scanf("%lf", &x);

    double l = 0, r = x - 1;
    do{
        double mid = (l + r) / 2;
        if(mid * mid >= x) r = mid;//过大
        else l = mid;//不需要处理边界的问题
    }while(r - l > 1e-6);
    cout << r << endl;
    return 0;
}