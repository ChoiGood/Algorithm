#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> trom;

int count = 0;

void tromino(int n,int h_r, int h_c, int st_r, int st_c, trom &V)
{
    if (n==2)
    {
        ::count++;
        // 홀을 뺀 위치에 tromino 두기
        for (int i=st_r; i<st_r+2;i++) {
            for(int j=st_c; j<st_c+2;j++) {
                if (!((i==h_r) && (j==h_c))) { // hole 이 아닐 때
                    V[i][j] = ::count;
                }
            }
        }
    }
    else
    {
        //  hole 을 가진 사분면을 제외하고 나머지에 걸쳐서 tromino 두기
        ::count++;
        int m_row = st_r + n/2;
        int m_col = st_c + n/2;
        if(h_r < m_row) {
            if (h_c < m_col) { // 2사분면에 있을 때
                V[m_row][m_col] = ::count;        
                V[m_row][m_col -1] = ::count;
                V[m_row -1][m_col] = ::count;
                tromino(n/2,h_r,h_c,st_r,st_c,V);            //2
                tromino(n/2,m_row-1,m_col,st_r,m_col,V);     //1
                tromino(n/2,m_row,m_col-1,m_row,st_c,V);     //3
                tromino(n/2,m_row,m_col,m_row,m_col,V);      //4

            }
            else {  // 1사분면에 있을 때
                V[m_row][m_col] = ::count;        
                V[m_row -1][m_col -1] = ::count;
                V[m_row][m_col -1] = ::count;
                tromino(n/2,m_row-1,m_col-1,st_r,st_c,V);       //2
                tromino(n/2,h_r,h_c,st_r,m_col,V);              //1
                tromino(n/2,m_row,m_col-1,m_row,st_c,V);        //3
                tromino(n/2,m_row,m_col,m_row,m_col,V);         //4



            }

        }
        else {
            if (h_c < m_col) { // 3사분면에 있을때 
                V[m_row][m_col] = ::count;        
                V[m_row -1][m_col -1] = ::count;
                V[m_row -1][m_col] = ::count;
                tromino(n/2,m_row-1,m_col-1,st_r,st_c,V);       //2     
                tromino(n/2,m_row-1,m_col,st_r,m_col,V);        //1
                tromino(n/2,h_r,h_c,m_row,st_c,V);              //3
                tromino(n/2,m_row,m_col,m_row,m_col,V);         //4
            }
            else {  // 4사분면에 있을 때
                V[m_row-1][m_col-1] = ::count;        
                V[m_row][m_col -1] = ::count;
                V[m_row -1][m_col] = ::count;
                tromino(n/2,m_row-1,m_col-1,st_r,st_c,V);       //2
                tromino(n/2,m_row-1,m_col,st_r,m_col,V);        //1     
                tromino(n/2,m_row,m_col-1,m_row,st_c,V);        //3
                tromino(n/2,h_r,h_c,m_row,m_col,V);             //4
            
            }

        }
        
    }
}

int main()
{
    int n,row,col; cin >> n >> row >> col;
    trom V(n,vector<int>(n));

    V[row][col]=0;
    tromino(n,row,col,0,0,V);

    for(int i =0; i<n;i++) {
        for(int j=0; j<n-1; j++) {
            cout << V[i][j] << " ";
        }
        cout << V[i][n-1] << endl;
    }



    return 0;
}

/*
트로미노 퍼즐
Description

교재의 연습문제 Chapter 2. Exercise 42 (p.94) 트로미노 퍼즐 문제를 분할정복으로 풀어보시오.

이 문제는 부분문제를 4분할하는 분할정복의 대표적인 문제로, 트로미노 타일링 문제로 잘 알려져있다.



단, 이 실습과제에서 트로미토 타일의 번호는 트로미노를 놓은 순서로 정한다.

예를 들어, 다음과 같은 트로미노 퍼즐은 아래와 같은 순서로 트로미노를 놓는다.



tromino1.pngtromino2.png



참고할 수 있는 유튜브 영상:https://youtu.be/WP_Bg2rpJ1w


Input
첫째 줄에 n, row, col 이 주어진다.

�
n은 
�
×
�
n×n 트로미노 퍼즐의 보드 크기이다. (단, n은 2의 거듭제곱 수만 주어진다.)

row, col 은 구멍의 행과 열이다. 
0
≤
�
�
�
,
�
�
�
≤
�
−
1
0≤row,col≤n−1

Output
트로미노를 놓은 순서대로 타일에 번호를 부여한 보드를 출력한다.

구멍 타일의 번호는 0으로 한다.



* 주의: 보드를 출력할 때 각 행의 줄끝 공백을 출력하지 않도록 주의할 것.


Sample Input 1 

2 0 0
Sample Output 1

0 1
1 1
Sample Input 2 

4 0 0
Sample Output 2

0 2 3 3
2 2 1 3
4 1 1 5
4 4 5 5
Sample Input 3 

8 1 2
Sample Output 3

3 3 4 4 8 8 9 9
3 2 0 4 8 7 7 9
5 2 2 6 10 10 7 11
5 5 6 6 1 10 11 11
13 13 14 1 1 18 19 19
13 12 14 14 18 18 17 19
15 12 12 16 20 17 17 21
15 15 16 16 20 20 21 21
*/