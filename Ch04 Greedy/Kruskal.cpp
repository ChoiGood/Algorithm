#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct edge {
    int u, v, w;
} edge_t;

struct edge_compare {
    bool operator()(edge_t e1, edge_t e2) {
        if (e1.w > e2.w) return true;
        else return false;
    }
};

typedef vector<edge_t> set_of_edges;
typedef priority_queue<edge_t, vector<edge_t>, edge_compare> PriorityQueue;

vector<int> dset;

void dset_init(int n) {
    dset.resize(n+1);
    for (int i=1; i<= n; i++)
        dset[i] = i;
}

int dset_find(int i) {
    while(dset[i] != i)
        i = dset[i];
    return i;
}

void dset_merge(int p, int q) {
    dset[p] = q;
}

void kruskal(int n, int m, set_of_edges& E, set_of_edges& F) {
    int p, q;
    edge_t e;
    PriorityQueue PQ;

    //sort the m edges in E by weight in nondecreasing order;
    for (edge_t e: E)
        PQ.push(e);

    F.clear(); // F = O
    dset_init(n);
    while(F.size()<n-1) {
        e = PQ.top(); PQ.pop(); // edge with least weight not yet considered;
        p = dset_find(e.u);
        q = dset_find(e.v);
        if(p!=q) {
            dset_merge(p,q);
            F.push_back(e); // add e to F
        }
    } 

}

void InputE(int m, set_of_edges& E)
{
    edge_t temp;

    for(int i=1; i<=m; i++) {
        cin >> temp.u >> temp.v >> temp.w;
        E.push_back(temp);
    }
}

void OutputE(set_of_edges& E)
{
    for(edge_t e : E)
        cout << e.u << " " << e.v << " " << e.w << endl;
}

int main()
{
    int n,m; cin >> n >> m;
    set_of_edges E,F;

    InputE(m,E);

    kruskal(n,m,E,F);

    OutputE(F);



    return 0;
}




/*
Description
교재와 강의자료를 참고하여 Algorithm 4.2 크루스칼 알고리즘의 구현을 완성하시오.

그래프의 입력은 간선의 집합으로 주어지며,
출력값은 크루스칼 알고리즘의 각 단계별로
F집합에 추가되는 간선을 순서대로 출력한다.
단, 가중치는 unique 하며, 동일한 가중치를 가진 간서은 없다고 강정해도 된다.

Input
첫 줄에 정점의 개수 n , 간선의 개수 m 이 주어진다.
두 번째 줄부터 다음과 같은 형태로 m 개의 간선이 주어진다.
u v m
u 와 v는 정점의 번호이고 1부터 n까지의 자연수로 표시한다.
w는 간선 <u,v> 의 가중치이며, 양의 정수 값으로 주어진다.

Output
크루스칼 알고리즘의 초기 단계부터 종료 단계까지(n-1 times)
F 집합에 포함되는 간서을 순서대로 출력한다.
u v w
*/

/*
Sample Input 1 

5 7
1 2 1
1 3 3
2 3 7
2 4 6
3 4 4
3 5 2
4 5 5
Sample Output 1

1 2 1
3 5 2
1 3 3
3 4 4
*/