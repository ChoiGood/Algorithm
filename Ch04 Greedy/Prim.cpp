#include <iostream>
#include <vector>

using namespace std;

#define INF 0xffff

typedef vector<vector<int>> matrix_t;
typedef vector<pair<int,int>> set_of_edges;
typedef pair<int,int> edge_t;

void Outputnear(int n, vector<int> near)
{
    for(int i=2; i<n; i++) {
        cout << near[i] << " ";
    }
    cout << near[n] << endl;
}

void prim(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> nearest(n+1), distance(n+1);

    F.clear(); // F = O;
    for(int i = 2; i <= n; i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }

    Outputnear(n,nearest);

    for(int repeat = 1; repeat <= n-1; repeat++) {
        min = INF;
        for (int i = 2; i <= n; i++) {
            if(0 <= distance[i] && distance[i] < min) {
                min = distance[i];
                vnear = i;
            }
        }

        // e = edge connecting vertices indexed by vnear and nearest[vnear]
        // add e to F;
        F.push_back(make_pair(vnear, nearest[vnear]));
        distance[vnear] = -1;
        for(int i=2; i<= n; i++) {
            if (distance[i] > W[i][vnear]) {
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            }
        }
        
        Outputnear(n,nearest);

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
        W[b][a] = c;
    }
}

void OutputW(int n, matrix_t &W)
{
    for(int i=1; i<=n; i++) {
        for(int j=1; j<n; j++) {
            cout << W[i][j] << " ";
        }
        cout << W[i][n] << endl;
    }
}

int main()
{
    int n,m,u,v; cin >> n >> m; // n : 정점의 개수 ,, m: 간선의 개수
    matrix_t W(n+1,vector<int> (n+1,INF));
    set_of_edges F;
    
    InputW(n,m,W);

    prim(n,W,F);
    
    for(edge_t e: F) {
        u = e.first; v= e.second;
        cout << u << " " << v << " " << W[u][v] << endl;
    }



    return 0;
}







/*
교재와 강의자료를 참고하여 Algorithm 4.1 프림 알고리즘의 구현을 완성하시오.

그래프의 입력은 간선의 집합으로 주어지며,

출력밧은 그리디 알고리즘의 각 단계별로 nearest 배열의 변화를 출력하고,

F집합에 추가되는 간선을 순서대로 출력한다.

Input
첫째 줄에 정점의 개수 n, 간선의 개수 m 이 주어진다.
둘째 줄부터 다음과 같은 형태로 m 개의 간선이 주어진다. 
u v m
u 와 v 는 정점의 번호이고, 1부터 n까지의 자연수로 표시한다.
w는 간선 <u,v>의 가중치이며, 양의 정수 값으로 주어진다.

Output
프림 알고리즘의 초기 단계부터 종료 단계까지(n-1 times)
nearest 배열의 값을 한 단계에 한 줄씩 출력한다.
첫번째 정점(v1)을 선택하는 전략이므로
nearest 배열의 값은 2번부터 n번까지만 출력한다. (i=2 .. n)
이후로, 프림 알고리즘의 F집합에 포함되는 간선을 순서대로 출력한다.
u v m
*/

/*
Sample Input 1 

5 7
1 2 1
1 3 3
2 3 3
2 4 6
3 4 4
3 5 2
4 5 5
Sample Output 1

1 1 1 1
1 1 2 1
1 1 3 3
1 1 3 3
1 1 3 3
2 1 1
3 1 3
5 3 2
4 3 4
*/