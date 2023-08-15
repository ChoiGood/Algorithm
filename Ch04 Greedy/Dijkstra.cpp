//최단경로 : 다익스트라 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0xffff

typedef vector<vector<int>> matrix_t;
typedef vector<pair<int,int>> set_of_edges;
typedef pair<int,int> edge_t;

void OutTouch(int n, vector<int> touch)
{
    for(int i=2; i<n;i++) {
        cout << touch[i] << " ";
    }

    cout << touch[n] << endl;
}

void dijkstra(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> touch(n+1), length(n+1);

    F.clear();
    for(int i = 2; i<=n; i++) {
        touch[i] = 1;
        length[i] = W[1][i];
    }

    OutTouch(n,touch);

    for(int repeat = 1; repeat <= n-1; repeat++) {
        min = INF;
        for(int i = 2; i<=n; i++) {
            if (0 <= length[i] && length[i] < min) {
                min = length[i];
                vnear = i;
            }
        }

        // e = edge from vertex indexed by touch[vnear];
        // add e to F
        F.push_back(make_pair(touch[vnear],vnear));
        for (int i = 2; i<=n; i++) {
            if (length[i] > (length[vnear] + W[vnear][i])) {
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        }
        OutTouch(n,touch);
        length[vnear] = -1;

    }
}

void InputW(int n, int m, matrix_t& W)
{
    int a,b,c;

    for(int i=1; i<=n;i++) {
        W[i][i] = 0;
    }

    for(int i=1; i<=m; i++) {
        cin >> a >> b >> c;
        W[a][b] = c;
    }
}

void FindPath(int n, set_of_edges& F)
{
    vector<int> temp;
    while(1) {
        if (n == 1) {
            temp.push_back(1);
            break;
        }
        for(edge_t e : F) {
            if (e.second == n) {
                temp.push_back(n);
                n=e.first;
            }
        }
    }
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.size()-1; i++)
	    cout << temp[i] << " ";
    cout << temp[temp.size()-1] << endl;
    
}

int main()
{
    int n, m,u,v; cin >> n >> m;
    matrix_t W(n+1,vector<int> (n+1,INF));
    set_of_edges F;
    InputW(n,m,W);

    dijkstra(n,W,F);

    for(edge_t e: F) {
        u = e.first; v= e.second;
        cout << u << " " << v << " " << W[u][v] << endl;
    }

    int n2;
    cin >> n2;

    int k;

    for(int i=1; i<=n2; i++) {
        cin >> k;
        FindPath(k,F);
    }




    return 0;
}










/*
Description
교재와 강의자료를 참고하여 Algorithm 4.3 다익스트라 알고리즘의 구현을 완성하시오.

그래프의 입력은 간선의 집합으로 주어지며, 
출력값은 그리디 알고리즘의 각 단계별로 touch 배열의 변화를 출력하고,
F 집합에 추가되는 간선을 순서대로 출력한다.
단, 출발 정점은 1번 정점으로 가정하였으므로,
이후로 주어지는 정점 번호에 대해서 1번 정점으로부터 해당 정점으로 
가능 최단 경로를 출력한다.

Input
첫 줄에 정점의 개수 n, 간선의 개수 m이 주어진다.
두 번째 줄부터 다음과 같은 형태로 m개의 간선이 주어진다.
u v w
u 와 v 는 정점의 번호이고, 1부터 n까지의 자연수로 표시한다.
w는 간선 <u,v> 가중치이며, 양의 정수 값으로 주어진다.
이후에 정점의 개수 T가 주어진다.
이후에 T개의 정점 번호가 주어진다.
(1번 정점이 주어지는 경우는 없다고 가정해도 된다)

Output
다익스트라 알고리즘의 초기 단계부터 종료 단계까지 (n-1 tiems)
touch 배열의 값을 한 단계에 한 줄씩 출력한다.
첫번째 정점(v1) 이 출발 정점이므로
touch 배열의 값은 2번부터 n번까지만 출력한다. (i = 2..n)
이후로, 다익스트라 알고리즘의 F집합에 포함되는 간선을 순서대로 출력한다.
이후로, T개의 정점 v에 대해서
1번 정점으로부터 정점 v로 가는 최단 경로를 출력한다.
*/

/*
Sample Input 1 

5 8
1 2 7
1 3 4
1 4 6
1 5 1
3 2 2
3 4 5
4 2 3
5 4 1
4
2
3
4
5
Sample Output 1

1 1 1 1
1 1 5 1
4 1 5 1
4 1 5 1
4 1 5 1
1 5 1
5 4 1
1 3 4
4 2 3
1 5 4 2
1 3
1 5 4
1 5
*/