#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;
int threshold = 1;
int count=0;

void print_matrix(int n, matrix_t M);
void resize(int n, matrix_t &mat);
void madd(int n, matrix_t A, matrix_t B, matrix_t &C);
void msub(int n, matrix_t A, matrix_t B, matrix_t &C);
void mmsult(int n, matrix_t A, matrix_t B, matrix_t &C);
void partition(int m , matrix_t M, matrix_t &M11, matrix_t&M12, matrix_t& M21, matrix_t& M22);
void combine(int m, matrix_t& M, matrix_t M11, matrix_t M12, matrix_t M21, matrix_t M22);
void strassen(int n, matrix_t A, matrix_t B, matrix_t &C);

void inputM(int n, matrix_t & V)
{
    for(int i=0; i<n; i++) {
        for(int j=0;j<n; j++) {
            cin >> V[i][j];
        }
    }
}

void resizeL(int n, int k, matrix_t &V)
{
    for(int i=0; i<n; i++) {
        V[i].resize(k);
    }
    resize(k,V);
}

int main()
{
    int n,hold; cin >> n >> hold;

    matrix_t A(n,vector<int>(n));
    matrix_t B(n,vector<int>(n));
    matrix_t C(n,vector<int>(n));

    inputM(n,A);
    inputM(n,B);
    ::threshold = hold;
    
    int k=1;
    while(k<n) k *= 2;

    if(n!=k) {
        resizeL(n,k,A);
        resizeL(n,k,B);
        resizeL(n,k,C);
    }

    strassen(k,A,B,C);

    printf("%d\n",::count);
    print_matrix(n,C);

    return 0;
}

void print_matrix(int n, matrix_t M)
{
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1;j++) {
            cout << M[i][j] << " ";
        }
        cout << M[i][n-1] << endl;
    }
}

void resize(int n, matrix_t& mat)
{
    mat.resize(n,vector<int>(n));
}

void madd(int n, matrix_t A, matrix_t B, matrix_t &C)
{
    for(int i=0;i<n;i++) {
        for(int j=0; j<n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void msub(int n, matrix_t A, matrix_t B, matrix_t &C)
{
    for(int i=0;i<n;i++) {
        for(int j=0; j<n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void mmult(int n, matrix_t A, matrix_t B, matrix_t &C)
{
    for(int i=0; i<n; i++) {
        for(int j=0;j<n;j++) {
            C[i][j]=0;
            for(int k=0;k<n;k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }    
    }
}

void partition(int m, matrix_t M, matrix_t& M11, matrix_t &M12, matrix_t &M21, matrix_t &M22)
{
    for(int i=0; i< m; i++) {
        for(int j=0; j< m; j++) {
            M11[i][j] = M[i][j];
            M12[i][j] = M[i][j+m];
            M21[i][j] = M[i+m][j];
            M22[i][j] = M[i+m][j+m];
        }
    }
}

void combine(int m, matrix_t& M, matrix_t M11, matrix_t M12, matrix_t M21, matrix_t M22)
{
    for(int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            M[i][j] = M11[i][j];
            M[i][j+m] = M12[i][j];
            M[i+m][j] = M21[i][j];
            M[i+m][j+m] = M22[i][j];
        }
    }
}

void strassen(int n, matrix_t A, matrix_t B, matrix_t &C) {
    ::count++;   // strassen 함수 호출 횟수

    if (n <= threshold) {
        mmult(n,A,B,C);
    }
    else {
        //Define local variables here
        matrix_t A11, A12, A21, A22;
        matrix_t B11, B12, B21, B22;
        matrix_t C11, C12, C21, C22;
        matrix_t M1, M2, M3, M4, M5, M6, M7;
        matrix_t L,R;

        int m = n/2;
        resize(m, A11); resize(m,A12); resize(m,A21); resize(m,A22);
        resize(m, B11); resize(m,B12); resize(m,B21); resize(m,B22);
        resize(m, C11); resize(m,C12); resize(m,C21); resize(m,C22);
        resize(m, M1); resize(m,M2); resize(m,M3); resize(m,M4); resize(m,M5);
        resize(m, M6); resize(m,M7); resize(m,L); resize(m,R);

        partition(m, A, A11, A12, A21, A22);
        partition(m, B, B11, B12, B21, B22);

        // Implement Strassen's Method Here

        madd(m,A11,A22,L);
        madd(m,B11,B22,R);
        strassen(m,L,R,M1);

        madd(m,A21,A22,L);
        strassen(m,L,B11,M2);

        msub(m,B12,B22,R);
        strassen(m,A11,R,M3);

        msub(m,B21,B11,R);
        strassen(m,A22,R,M4);

        madd(m,A11,A12,L);
        strassen(m,L,B22,M5);

        msub(m,A21,A11,L);
        madd(m,B11,B12,R);
        strassen(m,L,R,M6);

        msub(m,A12,A22,L);
        madd(m,B21,B22,R);
        strassen(m,L,R,M7);

        madd(m,M1,M4,L);
        msub(m,L,M5,R);
        madd(m,R,M7,C11);

        madd(m,M3,M5,C12);

        madd(m,M2,M4,C21);

        madd(m,M1,M3,L);
        msub(m,L,M2,R);
        madd(m,R,M6,C22);

        combine(m,C,C11,C12,C21,C22);

    }
}
/*
쉬트라센 행렬곱셈 알고리즘
Description

교재와 강의자료를 참고하여 Algorithm 2.8 쉬트라센 행렬곱셈 알고리즘을 구현하시오.

이 문제의 입력으로 
�
n, 
�
ℎ
�
�
�
ℎ
�
�
�
threshold 값이 주어지고, 
�
×
�
n×n 정방행렬 두 개가 입력으로 주어진다.

Algorithm 2.8을 구현하여 적용했을 때, strassen() 함수의 호출 횟수와 두 정방행렬의 곱 
�
×
�
A×B를 출력한다.



단, n의 값이 2의 거듭제곱 수가 아닐 때에는 n보다 큰 2의 거듭제곱 수를 n으로 재정의해야 한다.

예를 들어, n보다 큰 2의 거듭제곱 수 k를 찾고자 할 때 다음과 같은 코드 조각을 이용할 수 있다.

int k = 1;
while (k < n) k *= 2;
또한, 위와 같은 2의 거듭제곱 수 k를 찾았다면, 
�
×
�
n×n크기의 행렬을 
�
×
�
k×k 크기의 행렬로 바꿔야 한다. (빈 원소의 값은 0으로 초기화)


Input
첫째 줄에 
�
n과 
�
ℎ
�
�
�
ℎ
�
�
�
threshold가 주어진다.

둘째 줄부터
�
×
�
n×n 행렬 두 개가 한 줄에 한 행씩 주어진다.


Output
첫째 줄에 strassen() 함수의 호출 횟수를 출력한다.

둘째 줄부터 두 행렬의 곱을 한 줄에 한 행씩 출력한다.

* 주의: 행렬 출력시에 각 행의 끝에 줄끝 공백을 출력하지 않도록 주의한다.


Sample Input 1 

2 1
2 3
4 1
5 7
6 8
Sample Output 1

8
28 38
26 36
Sample Input 2 

2 2
2 3
4 1
5 7
6 8
Sample Output 2

1
28 38
26 36
Sample Input 3 

5 2
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
Sample Output 3

57
5 5 5 5 5
5 5 5 5 5
5 5 5 5 5
5 5 5 5 5
5 5 5 5 5
*/