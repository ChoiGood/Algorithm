#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long longint;
vector<longint> F;

longint fib1(int n)
{
    if (n <= 1)
        return n;
    else
        return fib1(n-1) + fib1(n-2);
}


// Using Memoization  <- 쓸데없는 중복 부분 문제 해결!! 메모이제이션 ( 재귀ㅣ 호출은 남아 있음)  
// ==> 재귀는 반복문 보다 느리니 재귀도 없애보자
longint fib2(int n) {
    if (n<=1)
        F[n] = n;
    else if (F[n] == -1)
    {
        F[n] = fib2(n-1) + fib2(n -2);
    }
    return F[n];
    
}

// Using TABULATION
longint fib3(int n) {
    F.resize(n+1);
    if (n <= 1)
        F[n] = n;
    else {
        F[0] = 0; F[1] = 1;
        for (int i=2; i<=n; i++) {
            F[i] = F[i-1] + F[i-2];    
        }
    }
    return F[n];
} 
  
int main()
{
    int n; cin >> n;
    //F.resize(n+1, -1);
    
    cout << fib3(n) << endl;

    return 0;
}