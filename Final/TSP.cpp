#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#define INF 999

using namespace std;

typedef vector<int> ordered_set;

typedef struct node *node_pointer;
typedef struct node{
    int level;
    ordered_set path;
    int bound;
}nodetype;

struct compare {
    bool operator() (node_pointer u , node_pointer v){
        if(u->bound > v->bound)
            return true;
        return false;
    }
};

typedef priority_queue<node_pointer,vector<node_pointer>, compare> priority_queue_of_node;
typedef vector<vector<int>> matrix_t;
matrix_t W;
ordered_set opttour={};
int n;
int minlength=INF;
int idx=1;
int length(ordered_set path)
{
    vector<int> ::iterator it;
    int len=0;
    for(it=path.begin();it!=path.end();it++)
        if(it!=path.end()-1)
            len +=W[*it][*(it+1)];
    return len;
}
bool isIn(int i,ordered_set path)
{
    for(int j=0;j<path.size();j++)
        if(path[j]==i)
            return true;
    return false;

}
bool hasOutgoing(int v,ordered_set path)
{
    vector<int> :: iterator it;
    for(it = path.begin();it!=path.end()-1;it++)
        if(*it == v)return true;
    return false;
}

bool hasIncoming(int v, ordered_set path)
{
    vector<int> :: iterator it;
    for(it = path.begin()+1;it != path.end();it++)
        if(*it==v)return true;
    return false;
}

int bound(node_pointer v)
{
    int lower = length(v->path);

    for(int i=1;i<=n;i++)
    {
        if(hasOutgoing(i,v->path))continue;
        int min = INF;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue; // self-loop
            if(j==1 && i==v->path[v->path.size()-1]) continue;
            if(hasIncoming(j, v->path))continue; // incomming node 가 j에서 v->path 로 오면 안됨.
            if(min > W[i][j]) min = W[i][j];
        }
        if(min !=INF)
            lower+=min;
    }
    return lower;
}

node_pointer create_node (int level, ordered_set path)
{
    node_pointer v = new node;
    v->level = level;
    v->path = path;
    v->bound = 0;
    return v;
}
bool correct_path(node_pointer v)
{
    bool flag = true;
    for (int i = 1; i < v->path.size(); i++)
    {
        if (W[v->path[i - 1]][v->path[i]] == INF) //경로가 없다면
        {
            flag = false;
        }
    }
    return flag;
}
void print(node_pointer v)
{
    cout << v->level << ' ';
    if(!correct_path(v)) cout << "INF" << ' ';
    else cout << v->bound << ' ';

    for (int i = 0; i < v->path.size(); i++)
    {
        if(v->path[i] != INF)
            cout << v->path[i];
        else
            cout << "INF";

        if (i == v->path.size() - 1)
            cout << endl;
        else
            cout << ' ';
    }
}
void travel2(ordered_set &opttour, int &minlength)
{
    priority_queue_of_node PQ;
    node_pointer u,v;

    minlength = INF;
    v= create_node(0,{1}); v->bound = bound(v);
    //print(v);
    PQ.push(v);
    while(!PQ.empty())
    {
        v=PQ.top();
        PQ.pop();
        if(v->bound < minlength) //pruning 조건
        {
            for(int i=2;i<=n;i++)
            {
                if(isIn(i,v->path))continue;
                u=create_node(v->level + 1,v->path);
                u->path.push_back(i);
                u->bound=bound(u);
                //print(u);
                if(u->level == n-2) // 마지막 경로 빼고 다 설정됐음
                {
                    for(int k=2; k<=n; k++)
                        if(!isIn(k, u->path))
                            u->path.push_back(k);
                    u->path.push_back(1); // 마지막은 1로 돌아가야함
                    if(length(u->path) < minlength)
                    {
                        minlength= length(u->path);
                        opttour=u->path;
                    }
                }
                else
                {
                    u->bound = bound(u);
                    if(u->bound < minlength)
                    {
                        PQ.push(u);
                        //print(u);
                    }
                }
                //print(u);
            }
        }
        printf("%d : ",idx++);
        print(v);
    }
}
int main()
{
    int m, u, v, w;
    cin >> n >> m;

    W.resize(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=n;j++)
            W[i][j] = INF; 
        W[i][i] = 0;
    }

    for(int i=1;i<=m;i++)
    {
        cin >> u >> v >> w;
        W[u][v]=w;
    }

    // for(int i=1;i<=n;i++) W 인접행렬 확인
    // {   
    //     for(int j=1;j<=n;j++)
    //         cout << W[i][j] << ' '; 
    //     cout << endl;
    // }
    
    travel2(opttour,minlength);

    cout << minlength << endl;
    
    for(int i=0;i<opttour.size();i++)
        cout << opttour[i] << ' ';
    return 0;
}

// 외판원 순회 문제와 분기 한정법
/*
Description
교재와 강의자료를 참고하여 외판원 순회 문제를 분기한정법으로 해결하는 Algorithm 6.3의 구현을 완성하시오.

분기한정을 위한 Best FS의 방문순서대로 노드의 상태를 출력해야함에 유의하시오.

또, 방향 그래프에서는 bound 값이 무한대일 경우에 INF라고 출력하도록 해야 함에 유의하시오 !!!

INPUT
첫 줄에 정점의 개수 n과 간선의 개수 m이 주어진다.

둘째 줄부터 m개의 간선이 u, v, w의 형태로 주어진다.

OUTPUT
첫째 줄부터 분기한정법으로 방문하는 노드의 상태를 아래와 같이 출력한다.

level bound path[0] path[1] ... ... path[k]
(마지막에 공백이 출력되지 않도록 유의할 것)

노드의 상태 출력이 모두 끝나면 다음 줄에 최적값 minlength를 출력한다.

다음 줄에는 1번 정점을 출발점으로 하는 최적 순회 경로를 출력한다.
(최적 순회 경로는 여러 개가 있을 수 있으나, 교재와 강의자료에서 선택하는 순회 경로를 출력하도록 유의할 것)

또한, 방향 그래프에서는 bound 값이 무한대일 경우에는 INF라고 출력하도록 해야 함에 유의하시오!!!
*/

/*
---------------------------
Sample Input 1 

5 20
1 2 8
1 3 13
1 4 18
1 5 20
2 1 3
2 3 7
2 4 8
2 5 10
3 1 4
3 2 11
3 4 10
3 5 7
4 1 6
4 2 6
4 3 7
4 5 11
5 1 10
5 2 6
5 3 2
5 4 1

Sample Output 1

0 22 1
1 26 1 2
1 30 1 3
1 33 1 4
1 34 1 5
2 29 1 2 3
2 29 1 2 4
2 29 1 2 5
3 46 1 2 3 4 5 1
3 29 1 2 3 5 4 1
29
1 2 3 5 4 1
---------------------------
Sample Input 2 

4 9
1 2 2
1 3 9
2 1 1
2 3 6
2 4 4
3 2 7
3 4 8
4 1 6
4 2 3

Sample Output 2

0 13 1
1 20 1 2
1 20 1 3
1 INF 1 4
2 22 1 2 3 4 1
2 INF 1 2 4 3 1
2 26 1 3 2 4 1
2 21 1 3 4 2 1
21
1 3 4 2 1
---------------------------
*/