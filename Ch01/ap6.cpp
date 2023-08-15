#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count=0;

int fib(int n)
{
    ::count++;
    if (n==0 || n==1)
    {
        return n;
    }
    else
    {
        return fib(n-1)+fib(n-2);
    }
}


int main()
{
    int n;
    scanf("%d",&n);

    printf("%d\n",fib(n));
    printf("%d",::count);

    return 0;
}
/*
피보나치 수 (재귀)
Description

교재의 Algorithm 1.6. Fibonacci (Recursive) 를 재귀 버전으로 구현하시오.

이 문제에서는 피보나치 수와 함께 fib() 함수의 호출 횟수를 출력해야 한다.

단, 피보나치 수의 크기가 정수 범위를 넘어가지 않도록 다음과 같이 피보나치 수를 정의한다.

F(n) = (F(n-1) + F(n-2)) % 1000000

이 문제는 C/C++/Java/Python 중에서 어떤 언어로든 풀면 된다.


Input
첫째 줄에 음이 아닌 정수 N이 주어진다. (0<=N<=30)


Output
첫째 줄에 피보나치 수를 1000000 으로 나눈 나머지를 출력한다.

둘째 줄에 fib() 함수를 호출한 횟수를 출력한다.


Sample Input 1 

0
Sample Output 1

0
1
Sample Input 2 

1
Sample Output 2

1
1
Sample Input 3 

2
Sample Output 3

1
3
*/