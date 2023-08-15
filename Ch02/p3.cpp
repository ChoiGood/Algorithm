#include <iostream>
#include <cmath>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    long_t cnt;
    cnt = pow(4,log2(n)+1);
    return cnt;
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}

/*
시간 복잡도 분석 3
Description

1번 문제와 동일하다.

#include <bits/stdc++.h>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    if (n == 0)
        return 1;
    else
        return fun(n/2) + fun(n/2) + fun(n/2) + fun(n/2);
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


Sample Input 1 

1
Sample Output 1

4
Sample Input 2 

4
Sample Output 2

64
Sample Input 3 

1024
Sample Output 3

4194304
*/