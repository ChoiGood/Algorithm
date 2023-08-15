#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> matrix_t;

void matrixmult(int n, int m, int k, int l, matrix_t A, matrix_t B, matrix_t& C)
{
    if (m!=k)
    {
        printf("행렬곱 불가능");
    }
    else
    {
        for (int i=1; i<=n;i++)
        {
            for(int j=1; j<=l;j++)
            {
                C[i][j]=0;
                for(int k1=1;k1<=k;k1++)
                {
                    C[i][j]+=A[i][k1]*B[k1][j];
                }
            }
        }
    }
   
}

void matrixread(int n, int m, matrix_t& M) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &M[i][j]);
}

int main() {
    int n,m,k,l;
    scanf("%d %d", &n,&m);
 
    matrix_t A(n+1, vector<int>(m+1));
    matrixread(n,m, A);

    scanf("%d %d", &k,&l);
    matrix_t B(k+1, vector<int>(l+1));
    matrixread(k,l, B);
    matrix_t C(n+1, vector<int>(l+1));
    matrixmult(n,m,k,l, A, B, C);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= l; j++)
            if (j < n)
                printf("%d ", C[i][j]);
            else
                printf("%d\n", C[i][j]);
}

/*
행렬 곱셈
Description

교재의 Algorithm 1.4 Matrix Multiplication 을 아래와 같이 C++ 언어로 구현하시오.

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix_t;

void matrixmult(int n, matrix_t A, matrix_t B, matrix_t& C);

void matrixread(int n, matrix_t& M) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &M[i][j]);
}

int main() {
    int n;
    scanf("%d", &n);
 
    matrix_t A(n+1, vector<int>(n+1));
    matrixread(n, A);
    matrix_t B(n+1, vector<int>(n+1));
    matrixread(n, B);
    matrix_t C(n+1, vector<int>(n+1));
    matrixmult(n, A, B, C);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (j < n)
                printf("%d ", C[i][j]);
            else
                printf("%d\n", C[i][j]);
}
온라인 저지 제출시에는 matrixmult() 함수의 구현 부분만 제출하면 된다.


Input
첫째 줄에 양의 정수 N이 주어진다.

다음 줄부터 N개의 줄에 첫 번째 N*N 행렬의 원소가 한 줄에 한 행씩 차례대로 주어진다.

다음 줄부터 N개의 줄에 두 번째 N*N 행렬의 원소가 한 줄에 한 행씩 차례대로 주어진다.


Output
두 행렬의 곱셈 결과를 N개의 줄에 한 줄에 한 행씩 차례대로 출력한다.


Sample Input 1 

2
2 3
4 1
5 7
6 8
Sample Output 1

28 38
26 36
*/