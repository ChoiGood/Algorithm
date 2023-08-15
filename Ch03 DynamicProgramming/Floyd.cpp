// Floyd's Algorithm for Shortest Paths
// from each vertex to all other vertices (All Pairs Shortest Paths)
#include <iostream>
#include <vector>

using namespace std;

#define INF 999
typedef vector<vector<int>> matrix_t;

void floyd(int n, matrix_t &W, matrix_t &D)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            D[i][j] = W[i][j];
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}

void Ginput(int n, int m, matrix_t &V)
{
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        V[u][v] = w;
    }
    for (int i = 1; i <= n; i++)
    {
        V[i][i] = 0;
    }
}

void Goutput(int n, matrix_t &V)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << V[i][j] << " ";
        }
        cout << V[i][n] << endl;
    }
}

void floyd2(int n, matrix_t &W, matrix_t &D, matrix_t &P)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;   // 이 부분 좀 더 공부해야함
                }
            }
        }
    }
}

void path(matrix_t &P, int u, int v, vector<int> &p)
{
    int k = P[u][v];
    if (k != 0)
    {
        path(P, u, k, p);
        p.push_back(k);
        path(P, k, v, p);
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m;
    matrix_t W(n + 1, vector<int>(n + 1, INF));
    matrix_t D(n + 1, vector<int>(n + 1));
    matrix_t P(n + 1, vector<int>(n + 1));
    vector<int> p;

    Ginput(n, m, W);

    floyd2(n, W, D, P);
    Goutput(n, D);
    Goutput(n, P);

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int s, d;
        cin >> s >> d;

        if (D[s][d] == INF)
        {
            cout << "NONE" << endl;
        }
        else
        {
            path(P, s, d, p);
            cout << s << " ";
            for (int i = 0; i < p.size(); i++)
            {
                cout << p[i] << " ";
            }
            cout << d << endl;

            p.clear();
        }
    }

    return 0;
}

/*
플로이드 알고리즘
- 교재와 강의자료를 참고하여 Algorithm 3.4/3.5 Floyd2 알고리즘의 구현을 완성하시오.

이 문제에서는 주어진 가중치가 있는 방향 그래프에서 모든 쌍 최단경로를 찾는 플로이드 알고리즘을 수행하고,

알고리즘의 결과물인 D 테이블과 P 테이블을 출력한다.

또한, 주어진 D의 출발 정점과 도착 정점에 대해서 최단 경로를 출력한다.

D 테이블에서 경로가 없는 정점에 대해서는 INF = 999 를 출력하도록 한다.

경로를 출력할 때는 출발 정점과 도착 정점도 함께 표시해야 하고,

경로가 존재하지 않는 두 정점에 대해서는 NONE 이라고 표시하도록 한다.

출발 정점과 도착 정점이 같은 경우에는 출발 정점과 도착 정ㅈ점을 따로 표시하면 된다

*/

/*
INPUT
첫 번째 줄에 정점의 개수 N 과 간선의 개수 M 이 주어진다.
정점의 번호는 1번부터 N번까지로 정한다.
두 번째 줄부터 M개의 간선의 정보가 주어진다.
각 간선의 정보 u v w 는 각각 간선의 출발 정점 u, 도착 정점 v, 해당 간선의 가중치 w로 주어진다.
모든 간선의 정보가 주어진 후에 다음 줄에 출발/도착 정점의 쌍의 개수 T 가 주어진다.

그 다음 줄부터 T개의 출발/도착 정점의 쌍이 주어진다.
*/

/*
Sample Input 1 

5 10
1 2 1
1 4 1
1 5 5
2 1 9
2 3 3
2 4 2
3 4 4
4 3 2
4 5 3
5 1 3
25
1 1
1 2
1 3
1 4
1 5
2 1
2 2
2 3
2 4
2 5
3 1
3 2
3 3
3 4
3 5
4 1
4 2
4 3
4 4
4 5
5 1
5 2
5 3
5 4
5 5
Sample Output 1

0 1 3 1 4
8 0 3 2 5
10 11 0 4 7
6 7 2 0 3
3 4 6 4 0
0 0 4 0 4
5 0 0 0 4
5 5 0 0 4
5 5 0 0 0
0 1 4 1 0
1 1
1 2
1 4 3
1 4
1 4 5
2 4 5 1
2 2
2 3
2 4
2 4 5
3 4 5 1
3 4 5 1 2
3 3
3 4
3 4 5
4 5 1
4 5 1 2
4 3
4 4
4 5
5 1
5 1 2
5 1 4 3
5 1 4
5 5

Sample Input 2 

5 8
1 2 7
1 3 4
1 4 6
1 5 1
3 2 2
3 4 5
4 2 3
5 4 1
25
1 1
1 2
1 3
1 4
1 5
2 1
2 2
2 3
2 4
2 5
3 1
3 2
3 3
3 4
3 5
4 1
4 2
4 3
4 4
4 5
5 1
5 2
5 3
5 4
5 5
Sample Output 2

0 5 4 2 1
999 0 999 999 999
999 2 0 5 999
999 3 999 0 999
999 4 999 1 0
0 5 0 5 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 4 0 0 0
1 1
1 5 4 2
1 3
1 5 4
1 5
NONE
2 2
NONE
NONE
NONE
NONE
3 2
3 3
3 4
NONE
NONE
4 2
NONE
4 4
NONE
NONE
5 4 2
NONE
5 4
5 5
*/