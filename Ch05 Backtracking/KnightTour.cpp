#include <iostream>
#include <vector>

using namespace std;

int count_circuit = 0; // 해밀턴 회로
int count_path = 0;    // 해밀턴 경로

void make_graph(int n, int m , vector<vector<int>> &graph)
{
    vector<int> imove = {-2, -1, 1, 2,  2,  1, -1, -2};
    vector<int> jmove = { 1,  2, 2, 1, -1, -2, -2, -1};
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<8; k++) {
                int ni = i + imove[k];
                int nj = j + jmove[k];
                
                if((0 <= ni && ni < n) && (0 <= nj && nj < m) ) {
                    graph[i*m + j].push_back(ni*m + nj);
                }
            }
        }
    }
}

bool VinGraph(int s, int v, vector<vector<int>> &graph)
{
    for(int i=0; i<graph[v].size(); i++ ) {
        if(s == graph[v][i]) {
            return true;
        }
    }

    return false;
}

void tour(int k, int v, int s, int n, int m, vector<vector<int>> &graph ,vector<int> &mark)
{
    if (k == n*m) {
        mark[v] = k;
        count_path++;
        if(VinGraph(s,v,graph)) {
            count_circuit++;
        }
    }        
    else {
        for(int i=0; i<graph[v].size(); i++) {
            if (mark[graph[v][i]] == 0) {
                mark[graph[v][i]] = k+1;
                tour(k+1,graph[v][i],s,n,m,graph,mark);
                mark[graph[v][i]] = 0;
            }
        }
    }   
}



int main()
{
    // 체스판의 row, col 입력 받기
    int n,m;
    cin >> n >> m; 

    // 인접그래프와 mark 배열 생성
    vector<vector<int>> graph;
    graph.resize(n*m);
    make_graph(n,m,graph);

    vector<int> mark(n*m,0);

    int first = 1;
    int t; cin >> t;
    for(int i=1; i<=t; i++) {
        int a,b; cin >> a >> b;
        int s = a * m + b;
        mark[s] = 1;
        tour(1,s,s,n,m,graph,mark);
        if(first) {
            cout << count_circuit << endl;
            first = 0;
        }
        cout << count_path << endl;

        count_path = 0;
        mark.clear();
        mark.resize(n*m,0);
    }
    


    return 0;
}

/*
Description
n by m 체스보드에서 기사의 여행 문제를 해결하는 백트래킹 알고리즘을 구현하시오.

Knight's Tour 문제는 해밀턴 경로(path)와 해밀턴 회로(circuit, cycle)를 찾는 문제로 구분할 수 있다.

해밀턴 회로는 출발 정점과 무관하게 회로의 수를 구할 수 있고,

해밀턴 경로는 출발 정점에 따라 가능한 경로의 수가 달라짐에 유의하시오.

INPUT
첫 번째 줄에 체스보드의 크기 n(행의 크기)과 m(열의 크기)이 주어진다.

두 번째 줄에 출발정점의 개수 T가 주어진다.

이후로 T개의 출발정점이 i(row), j(col) 의 쌍으로 주어진다.

OUTPUT
첫 번째 줄에 해밀턴 회로의 개수를 출력한다.

두 번째 줄부터 입력에서 주어진 출발정점 각각에 대해 해밀턴 경로의 수를 하나씩 출력한다.
*/

/*
-------------------------------
Sample Input 1 

3 4
3
0 0
0 1
1 0
Sample Output 1

0
2
0
4
-------------------------------
Sample Input 2 

3 10
2
0 0
1 1
Sample Output 2

32
448
416
-------------------------------
*/