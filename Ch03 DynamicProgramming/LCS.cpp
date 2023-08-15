// 최장공통부분서열(LCS)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<vector<int>> matrix_t;

matrix_t c;
matrix_t b;

void lcs(string x, string y, matrix_t &b, matrix_t &c)
{
    x= string(" ") + x;
    y= string(" ") +y;
    int m,n; m=x.size(); n=y.size();

    c.resize(m,vector<int>(n));
    b.resize(m,vector<int> (n));

    for (int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if (x[i] == y[j]) {
                c[i][j] = c[i-1][j-1] +1;
                b[i][j] = 1;
            }
            else {
                c[i][j] = max(c[i][j-1], c[i-1][j]);
                if (c[i][j-1] > c[i-1][j])
                    b[i][j] =2;
                else
                    b[i][j] = 3;
            }
        }
    }
    
}

string get_lcs(int i, int j, string &x)
{
    if (i==0 || j==0)
        return "";
    else {
        if (b[i][j] == 1)
            return get_lcs(i-1,j-1,x) + x[i];
        else if (b[i][j] == 2)
            return get_lcs(i,j-1,x);
        else if (b[i][j] == 3)
            return get_lcs(i-1,j,x);
    }
}

int main()
{
    string x,y; cin >> x >> y;
    lcs(x,y,b,c);
    
    string temp = string(" ") + x;
    
    int row = x.size();
    int col =y.size();
    if (c[row][col] == 0) {
        cout << 0;
    }
    else {
        cout << c[row][col] << endl;
        cout << get_lcs(x.size(),y.size(),temp);    
    }
    
}

/*
Description

두 개의 문자열이 주어질 때, 최장공통부분서열(LCS, Longest Common Subsequence)을 찾아라.

예를 들어, 두 개의 문자열 X = "ABCBDAB", Y = "BDCABA"에 대해서

공통부분서열의 최대값은 4이고, 해당하는 부분서열은 BCBA이다.



최장공통부분서열 문제는 대표적인 동적계획법 알고리즘으로,

다음과 같은 파이썬 코드로 구현된 알고리즘을 참조할 수 있다.

def lcs(x, y):
    x, y = [' '] + x, [' '] + y
    m, n = len(x), len(y)
    c = [[0 for _ in range(n)] for _ in range(m)]
    b = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(1, m):
        for j in range(1, n):
            if x[i] == y[j]:
                c[i][j] = c[i - 1][j - 1] + 1
                b[i][j] = 1
            else:
                c[i][j] = max(c[i][j - 1], c[i - 1][j])
                b[i][j] = 2 if (c[i][j - 1] > c[i - 1][j]) else 3
    return c, b


공통부분서열의 재구축은 다음과 같은 파이썬 코드로 구현된 알고리즘을 참조할 수 있다.

def get_lcs(i, j, b, x):
    if i == 0 or j == 0:
        return ""
    else:
        if b[i][j] == 1:
            return get_lcs(i - 1, j - 1, b, x) + x[i]
        elif b[i][j] == 2:
            return get_lcs(i, j - 1, b, x)
        elif b[i][j] == 3:
            return get_lcs(i - 1, j, b, x)

위 파이썬 참조 구현에 대한 해설은 유튜브 동영상을 참고할 수 있다.

https://youtu.be/z8KVLz9BFIo

단, 파이썬 참조 구현이 제공되므로, 이 과제에서는 파이썬 언어는 선택할 수 없음에 유의하라.

*/

/*
--------------------------------------------
Sample Input 1 

ABCBDAB
BDCABA

Sample Output 1

4
BCBA
---------------------------------------------
Sample Input 2 

AAAA
BBB

Sample Output 2

0
*/