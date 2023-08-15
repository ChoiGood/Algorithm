#include <iostream>
#include <vector>

using namespace std;

// typedef unsigned long long LongInteger;

// // Binomial Coefficient Using Divide - and - Conquer
// LongInteger bin(int n, int k)
// {
//     if ( k==0 || n==k)
//         return 1;
//     else
//         return bin(n-1, k) + bin(n-1, k-1);
// }

// // Binomial Coefficient Using Dynamic Programming
// LongInteger bin2(int n, int k)
// {
//     vector<vector<LongInteger>> B(n+1,vector<LongInteger>(n+1));
//     for(int i=0; i<=n; i++) {
//         for(int j=0; j<= min(i,k); j++) {
//             if(j==0 || j==i)
//                 B[i][j] = 1;
//             else
//                 B[i][j] = B[i-1][j] + B[i-1][j-1];
//         }
//     }
//     return B[n][k];
// }



// // 실습 문제 1번 : 이항계수 1 - 메모이제이션

// int cnt = 0;
// vector<vector<int>> DP;

// int bin(int n, int k)
// {
//     ::cnt++; // 함수 호출 횟수 카운트
//     if (k==0 || k==n)
//         DP[n][k] = 1;
//     else if (DP[n][k] == -1)
//         DP[n][k] = (bin(n-1, k) + bin(n-1, k-1)) % 10007; // memoize using recursive call
    
//     return DP[n][k]; // return memoized value
// }

/*
Input
첫째 줄에 이항계수의 n과 k가 주어진다.
0≤k≤n≤1,000

Output
첫째 줄에 이항계수의 값 bin(n, k)를 출력한다.

이 때 bin(n, k)는 10,007보다 작은 양의 정수임에 유의한다.

둘째 줄에 메모이제이션을 적용한 이항계수 함수의 호출 횟수를 출력한다.


Sample Input 1 

0 0
Sample Output 1

1
1
Sample Input 2 

10 5
Sample Output 2

252
51
Sample Input 3 

1000 123
Sample Output 3

7408
215743
Sample Input 4 

1000 765
Sample Output 4

6372
359551
*/


// 실습 문제 2번 : 이항계수 2 - 테뷸레이션!!
// 공간 복잡도를 O(n) 으로 개선시키고 더 효율적인 걸로 DP 최적화 시켜보자!!
vector<int> DP;

int bin2(int n, int k)
{
    if (k > n/2)
        k = n - k;
    DP.resize(k+1);


    for(int i=0; i<=n; i++) {
        for(int j=i;j>=0; j--) {
            if(j > k) j=k;
            if(j==0 || j==i) {
                DP[j] = 1;
            }
            else {
                DP[j] = (DP[j] + DP[j-1])%10007;
            }
        }
    }   
    
    return DP[k];
}


int main()
{
    int n,k; cin >> n >> k;

    cout << bin2(n,k);


    return 0;
}

/*
이항계수 2: 태뷸레이션
Description

교재와 강의자료를 참고하여 이항계수를 구하는 동적계획법 알고리즘을 구현해 보자.

이항계수의 값이 너무 커질 수 있으므로, 이항계수를 다음과 같이 10,007로 나눈 나머지로 정의한다.

bin(n,k)=1,ifk==0ork==n

bin(n,k)=(bin(n−1,k)+bin(n−1,k−1))mod10,007,otherwise


이 문제에서는 태뷸레이션을 이용하는 Algorithm 3.2 를 개선하여,

교재와 수업시간에 다룬 공간 복잡도가 

O(n)인 동적계획법 알고리즘으로 구현해야

시간 초과(Time Limit Error) 또는 메모리 초과(Memory Limit Exceeded)를 피할 수 있을 것이다.
Input
첫째 줄에 이항계수의 n과 k가 주어진다.
0≤k≤n≤50,000

Output
첫째 줄에 이항계수의 값 bin(n, k)를 출력한다.

이 때 bin(n, k)는 10,007보다 작은 양의 정수임에 유의한다.


Sample Input 1 

1000 123
Sample Output 1

7408
Sample Input 2 

10000 8987
Sample Output 2

9404
Sample Input 3 

10000 5000
Sample Output 3

8160
*/