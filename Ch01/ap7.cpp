#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long LongInt;

LongInt fib2(int n)
{
    vector<LongInt> F;
    if (n<=1)
        return n;
    else{
        F.push_back(0);
        F.push_back(1);
        for (int i =2; i<=n;i++)
            F.push_back((F[i-1]+F[i-2])%1000000);
        return F[n];
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fib2(n));
}

/*
피보나치 수 (반복)
Description

교재의 Algorithm 1.7. Fibonacci (Iterative) 를 반복 버전으로 구현하시오.

단, 피보나치 수의 크기가 정수 범위를 넘어가지 않도록 다음과 같이 피보나치 수를 정의한다.

F(n) = (F(n-1) + F(n-2)) % 1000000


Input
첫째 줄에 음이 아닌 정수 N이 주어진다. (0<=N<=10000)

Output
첫째 줄에 피보나치 수를 1000000 으로 나눈 나머지를 출력한다.


Sample Input 1 

100
Sample Output 1

915075
Sample Input 2 

1000
Sample Output 2

228875
*/