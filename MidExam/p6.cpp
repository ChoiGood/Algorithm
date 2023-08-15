#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;

void Minput(int n, matrix_t &T)
{
    for(int i=1; i<=n; i++) {
        for(int j=1;j<=i;j++) {
            cin >> T[i][j];
        }
    }
}

void Moutput(int n, matrix_t &T)
{
    for (int i=1; i<=n; i++) {
        for(int j=1; j<i; j++) {
            cout << T[i][j] << " ";
        }
        cout << T[i][i] << endl;
    }
}

void Poutput(int n, matrix_t &P, matrix_t &T)
{
    for (int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(P[i][j] ==1) {
                if(i!=n) {
                    cout << T[i][j] << " ";
                } else {
                    cout << T[i][j];
                }
            }

        }
    }
}

// // 삼각형의 위치 : i,j   삼각형의 깊이 : n 
// // Usint Divide and Conquer
// int cost(int n,int i,int j, matrix_t &T) {
//     if (i == n) {
//         return T[i][j];
//     }
//     else {
//         return T[i][j] + max(cost(n,i+1,j,T),cost(n,i+1,j+1,T));
//     }
// }

// //Using memoization - 재귀 조건은 남아있음!! top down 방식임!!
// matrix_t DP;
// int cost2(int n,int i,int j, matrix_t &T) {
//     DP.resize(n+1,vector<int> (n+1, -1));
//     if (i==n) {
//         DP[i][j] = T[i][j];
//     }
//     else if (DP[i][j] == -1) {
//         DP[i][j] = T[i][j] + max(cost(n,i+1,j,T),cost(n,i+1,j+1,T));
//     }
//     return DP[i][j];
// }

//Using Tabulation  남아있는 재귀조건을 없애고 bottom - up 으로 바꾸자 (재귀보다 반복이 더 빠르다)
//++ 경로 출력할 수 있게 추가 시키자 (별도의 dp table 을 만들자)
matrix_t DP;
matrix_t path;
int cost3(int n,int a,int b, matrix_t &T)
{
    DP.resize(n+1,vector<int> (n+1,-1));
    path.resize(n+1,vector<int> (n+1,0));

    // 최대 경로 DP table 채우기
    for(int i=1; i<=n; i++) {
        DP[n][i] = T[n][i];
    }
    for(int i=n-1; i>=1; i--) {
        for(int j=1;j<=i;j++) {
            DP[i][j] = T[i][j] + min(DP[i+1][j], DP[i+1][j+1]);
        }
    }
    // 만든 DP table을 가지고 최대경로를 가지는 path를 찾기위한 path table 만들기
    path[1][1] = 1;
    int j=1;
    for(int i=1; i<n;i++) {
        if(DP[i+1][j]<DP[i+1][j+1]) { // 왼쪽 경로
            path[i+1][j]=1;
        }   
        else { // 같은 경로 생길 때 가장 오른 쪽 선택!!
            path[i+1][j+1] = 1;
            j++; 
        }     
    }
    
    return DP[a][b];
}

// 최대경로 경우의 수 세아리기
int count = 1;
void pathcount(int n,int a,int b)
{
    for(int i=a; i<n;i++) {
        if (DP[i+1][b]==DP[i+1][b+1]) {
            ::count++;
            pathcount(n,i+1,b);
            b++;
        }
        else if(DP[i+1][b]<DP[i+1][b+1]) { // 왼쪽 경로
           
        }   
        else { //가장 오른 쪽 선택!!
            path[i+1][b+1] = 1;
            b++; 
        }     
    }

}


int main()
{
    int n; cin >> n;
    matrix_t T(n+1,vector<int> (n+1,0));
    Minput(n,T);

    cout << cost3(n,1,1,T) << endl;

    Poutput(n,path,T);
    
    pathcount(n,1,1);
    cout<< endl << ::count;

    return 0;
}

/*
삼각형 위의 최대 경로
파스칼의 삼각형처럼 생긴 삼각형에서 경로 위의 숫자들의 합이 최대가 되는 경로를 찾고자 한다.

예를 들어, 아래와 같이 높이가 4인 삼각형을 생각해 보자.
3
7 4
2 4 6
8 5 9 3
삼각형에서 경로 이동은 다음과 같이 두 가지만 가능하다.
- 현재 위치에서 바로 아래로 이동
- 현재 위치에서 바로 아래의 오른쪽으로 이동
출발점은 항상 최고층에서 출발한다고 할 때, 가장 아래 층으로 내려올 때까지 방문한 위치의 숫자의 합이 경로의 합이다.

위 삼각형에서 최대 경로는 [3, 7, 4, 9] 이고 경로의 합의 최대값은 23이다.

단, 최대 크기를 가진 경로가 여러 개일 경우에는 제일 오른쪽으로 치우친 경로를 출력한다.

예를 들어,
1
2 2
3 2 3
4 2 2 5
5 2 2 2 4
이처럼 두 개의 최대 경로 [1,2,3,4,5] 와 [1,2,3,5,4] 가 존재할 경우
오른쪽으로 가장 치우친 [1,2,3,5,4]의 경로를 출력하면 된다.
*/

/*
INPUT
첫 번째 줄에는 삼각형의 높이 n이 주어진다.
두 번째 줄부터 n개의 줄에 각각 삼각형의 숫자들이 주어진다.

Output
첫 번째 줄에 최대 경로의 합을 출력한다.
두 번째 줄에 최대 경로를 출력한다.
단, 최대 경로가 여러 개일 경우에는 가장 오른쪽으로 치우친 경로를 출력한다.
*/