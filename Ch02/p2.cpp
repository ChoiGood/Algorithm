#include<iostream>
#include<cmath>

using namespace std;

typedef long long long_t;

long_t fun(long_t n, long_t m, long_t p) {
    long_t cnt;
    cnt= ((2*n -1)/4 +1)*(log2(2*m)+1)*(log2(4*p)+1);
    return cnt;
}

int main()
{
    long_t n, m, p;
    scanf("%lld %lld %lld", &n, &m, &p);
    printf("%lld", fun(n, m, p));
    return 0;
}

/*
시간 복잡도 분석 2
Description

1번 문제와 동일하다.

#include <bits/stdc++.h>
using namespace std;

typedef long long long_t;

long_t fun(long_t n, long_t m, long_t p) {
    long_t i, j, k, cnt = 0;
    for (i=1; i<=2*n; i+=4)
        for (j=1; j<=2*m; j*=2)
            for (k=4*p; k>=1; k/=2)
                cnt++;
    return cnt;
}

int main() {
    long_t n, m, p;
    scanf("%lld %lld %lld", &n, &m, &p);
    printf("%lld", fun(n, m, p));
}

Input
첫째 줄에 입력값 N, M, P가 차례대로 주어진다.


Output
첫째 줄에 위 프로그램의 출력값을 출력한다.


Sample Input 1 

1 2 4
Sample Output 1

15
Sample Input 2 

4 8 16
Sample Output 2

70
Sample Input 3 

1024 2048 4096
Sample Output 3

99840
*/