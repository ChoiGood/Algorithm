#include <iostream>
#include <cmath>
using namespace std;

typedef long long long_t;
int count=0;

long_t fun(long_t n) {
    long_t cnt;
    cnt=pow(8,((long_t)log2(n)/2+1));
    return cnt;
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}

/*
시간 복잡도 분석 4
Description

이전 문제와 동일하다.

#include <bits/stdc++.h>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    if (n == 0)
        return 1;
    else {
        long_t s = 0;
        for (int i=1; i<=8; i++)
            s += fun(n/4);
        return s;
    }
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}

Input
첫째 줄에 입력값이 주어진다.


Output
첫째 줄에 출력값을 출력한다.


Sample Input 1 : 1
Sample Output 1 : 8

Sample Input 2 : 4
Sample Output 2 : 64

Sample Input 3 : 1024
Sample Output 3 : 262144
*/
