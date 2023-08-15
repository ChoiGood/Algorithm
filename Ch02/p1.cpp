#include<iostream>
using namespace std;

typedef long long long_t;

int main()
{
    long_t n;
    scanf("%lld", &n);
    printf("%lld", 2*n*n);
}

/*
시간 복잡도 분석 1
Description

아래 프로그램을 분석하고, 입력값에 따른 출력값을 출력하시오.

단, 코드를 그대로 실행하면 시간 초과에 걸리게 되므로, fun() 함수의 시간 복잡도를 계산하여 바로 출력해야 한다.

#include <bits/stdc++.h>
using namespace std;

typedef long long long_t;

long_t fun(long_t n) {
    long_t i, j, cnt = 0;
    for (i=1; i<=4*n; i+=2)
        for (j=n; j>=1; j--)
            cnt++;
    return cnt;
}

int main() {
    long_t n;
    scanf("%lld", &n);
    printf("%lld", fun(n));
}

Input
첫째 줄에 입력 매개변수 N의 값이 주어진다.


Output
첫째 줄에 N의 값에 따른 출력값을 출력한다.


Sample Input 1 
1
Sample Output 1

2
Sample Input 2 

4
Sample Output 2

32
Sample Input 3 

1024
Sample Output 3

2097152
*/