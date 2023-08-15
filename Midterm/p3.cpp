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



// 실습 문제 1번 : 이항계수 1 - 메모이제이션

int cnt = 0;
vector<vector<int>> DP;

int bin(int n, int k)
{
    ::cnt++; // 함수 호출 횟수 카운트
    if (k==1 || k==n)
        DP[n][k] = 2;
    else if (DP[n][k] == -1)
        DP[n][k] = (bin(n-1, k) + bin(n-1, k-1)) % 1000; // memoize using recursive call
    
    return DP[n][k]; // return memoized value
}

/*
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
*/

int main()
{
    int n,k; cin >> n >> k;
    DP.resize(n+1,vector<int> (n+1,-1));

    cout << bin(n,k);


    return 0;
}