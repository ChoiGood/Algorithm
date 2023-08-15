#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define INF 99999
typedef vector<vector<int>> matrix_t;


int minimum(int i, int j, int& mink, vector<int>& d, matrix_t& M)
{
    int minValue = INF, value;
    for (int k=i; k<= j-1; k++) {
        value = M[i][k] + M[k+1][j] + d[i - 1] * d[k] * d[j];
        if(minValue > value) {
            minValue = value;
            mink = k;
        }
    }
    return minValue;
}

void minmult(int n, vector<int>& d, matrix_t& M, matrix_t& P)
{
    for(int i =1; i<= n; i++)
        M[i][i] = 0;
    for(int diagonal = 1; diagonal <= n - 1; diagonal++) {
        for(int i = 1; i<= n-diagonal; i++) {
            int j = i + diagonal, k;
            M[i][j] = minimum(i,j,k,d,M);
            P[i][j] = k;

        }
    }
}



void RCinput(int n, vector<int> &d)
{
    for(int i=0; i<=n; i++)
    {
        cin >> d[i];
    }
}
void Output(int n, matrix_t &v)
{
    for(int i=1; i<=n; i++) {
        for(int j=i; j<n; j++) {
            cout << v[i][j] << " ";
        }
        cout << v[i][n] << endl; 
    }
}

void order(int i, int j, matrix_t& P, string& s)
{
    if (i==j)
        s += string("(A") + to_string(i) + string(")");
    else {
        int k = P[i][j];
        s += string("(");
        order(i,k,P,s);
        order(k+1,j,P,s);
        s += string(")");
    }
}

int main()
{
    int n; cin >> n;
    vector<int> d(n+1);
    matrix_t M(n+1,vector<int>(n+1));
    matrix_t P(n+1,vector<int>(n+1));
    string s("");

    RCinput(n,d);
    minmult(n,d,M,P);

    Output(n,M);
    Output(n,P);
    cout << M[1][n] << endl;

    order(1,n,P,s);
    cout << s;
    

    return 0;
}

/*
교재와 강의자료를 참고하여, Algorithm 3.6/3.7 연쇄 행렬 곱셈 알고리즘의 구현을 완성하시오

행렬의 개수 n과 각 행렬의 크기 값의 배열 d를 입력으로 받고 
M,P 행렬의 값을 구해서 출력하고,
단위 곱셈의 최적 횟수 및 괄호로 묶은 행렬 곱셈의 순서를 출력하시오.

단, 최적 횟수의 최댓값은 999999를 넘지 않는다.

INPUT
첫째 줄에 행렬의 개수 n 이 주어진다.
둘째 줄에 행렬의 크기 값의 배열 d가 차례대로 주어진다. (배열의 크기는 n+1 이다.)

OUTPUT
먼저 행렬 M의 윗 부분 삼각형을 출력한다. (0을 포함)
다음으로 행렬 P의 윗 부분 삼각형을 출력한다. (0을 포함)
M과 P를 출력한 후에 행렬 곱셈 횟수의 최적값을 출력한다.
모든 단위 행렬에도 괄호가 포함되어야 하고, 행렬 이름은 A1,A2,... An 으로 표기한다.

*/

/*
---------------------------------------------------
Sample Input 1 

6
5 2 3 4 6 7 8

Sample Output 1

0 30 64 132 226 348
0 24 72 156 268
0 72 198 366
0 168 392
0 336
0
0 1 1 1 1 1
0 2 3 4 5
0 3 4 5
0 4 5
0 5
0
348
((A1)(((((A2)(A3))(A4))(A5))(A6)))

----------------------------------------------
Sample Input 2 
1
3 5

Sample Output 2
0
0
0
(A1)
---------------------------------------------------
*/