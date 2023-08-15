#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


typedef struct node *node_pointer;
typedef struct node {
    int level;      // the node's level in the state space tree
    int weight;
    int profit;
    float bound;
} nodetype;

struct compare {
    bool operator()(node_pointer u, node_pointer v) {
        if (u->bound < v->bound)
            return true;
        return false;
    }
};

typedef priority_queue<node_pointer, vector<node_pointer>, compare> priority_queue_of_node;


int n, W;  // 개수, 무게
vector<int> p;
vector<int> w;
int maxprofit;


float bound(node_pointer u) {
    int j, k, totweight; float result;
    if (u->weight >= W)
        return 0;
    else {
        result = u->profit;
        j = u->level + 1;
        totweight = u->weight;
        while (j <= n && totweight + w[j] <= W) {
            totweight += w[j];
            result += p[j];
            j++;
        }
        k = j;
        if (k <= n)
            result += (W - totweight) * ((float)p[k] / w[k]);
        return result;
    }
}

node_pointer create_node(int level, int weight, int profit) {
    node_pointer v = (node_pointer)malloc(sizeof(nodetype));
    v->level = level;
    v->weight = weight;
    v->profit = profit;
    v->bound = bound(v);
    return v;
}



void knapsack6() {
    priority_queue_of_node PQ; node_pointer u, v;
    maxprofit = 0;
    PQ.push(create_node(0,0,0));
    v = PQ.top();
    cout << v->level << " " << v->weight << " " << v->profit << " " << v->bound << endl;
    while(!PQ.empty()) {
        v = PQ.top(); PQ.pop();
        cout << v->level << " " << v->weight << " " << v->profit << " " << v->bound << endl;
        if (v->bound > maxprofit) {
            u = create_node(v->level + 1, v->weight + w[v->level + 1], v->profit + p[v->level +1]);

            //cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;

            if(u->weight <= W && u->profit > maxprofit)
                maxprofit = u->profit;
            
            if(u->bound > maxprofit)
                PQ.push(u);
            
            u = create_node(v->level + 1, v->weight, v->profit);

            //cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;


            if(u->bound > maxprofit)
                PQ.push(u);
        }
    }

}

typedef struct item {
    int id;
    int weight;
    int profit;
    int profit_per_unit;    // = profit / weight
} item_t;

vector<item_t> items;

bool compare_item(item_t i, item_t j) {
    if(i.profit_per_unit > j.profit_per_unit)
        return true;
    return false;
}

void InputItem(int n, vector<int> &w, vector<int> &p)
{
    items.resize(n+1);
    item_t temp;
    for(int i=1; i<=n; i++) {
        cin >> w[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> p[i];
    }
    for(int i=1; i<=n; i++) {
        temp.profit = p[i];
        temp.weight = w[i];
        temp.profit_per_unit = p[i] / w[i];
        items[i] = temp;
    }

    sort(items.begin()+1, items.end(),compare_item);

    for(int i=1; i<=n; i++) {
        w[i] = items[i].weight;
    }
    for(int i=1; i<=n; i++) {
        p[i] = items[i].profit;
    }

    // items.clear() 이걸로 필요없는 메모리를 없애는 게 좋겠죠??
    
}


int main()
{
    cin >> n >> W;
    w.resize(n+1); p.resize(n+1);

    InputItem(n,w,p);

    knapsack6();

    cout << maxprofit << endl;


    return 0;
}


// 0-1 배낭 문제와 분기한정법
/*
Description
교재와 강의자료를 참고하여 0-1 배낭문제를 분기한정법으로 해결하는 Algorithm 6.2 의 구현을 완성하시오.

단, 입력값은 단위 무게당 이익의 내림차순으로 정렬되어 있지 않음에 주의하시오.

출력은 Best FS로 노드를 방문할 때 해당 노드의 상태를 아래와 같이 출력해야한다.

level weight profit bound

INPUT
첫 줄에 아이템의 개수 n과 배낭 무게 W가 주어진다.
둘째 줄에 n개의 아이템 무게 w가 주어진다.
셋째 줄에 n개의 아이템 이익 p가 주어진다.

OUTPUT
첫 줄부터 BestFS로 방문하는 모든 노드의 상태를 출력한다.
각 상태를 출력하는 순서는 다음과 같다.
level weight profit bound
상태의 출력이 모두 끝나고 다음 줄에 최대 이익 maxprofit을 출력한다.
*/

/*
--------------------------------
Sample Input 1 

4 16
2 5 10 5
40 30 50 10

Sample Output 1

0 0 0 115
1 2 40 115
1 0 0 82
2 7 70 115
2 2 40 98
3 17 120 0
3 7 70 80
3 12 90 98
3 2 40 50
4 17 100 0
4 12 90 90
90

--------------------------------
Sample Input 2 

4 16
5 2 10 5
30 40 50 10 

Sample Output 2

0 0 0 115
1 2 40 115
1 0 0 82
2 7 70 115
2 2 40 98
3 17 120 0
3 7 70 80
3 12 90 98
3 2 40 50
4 17 100 0
4 12 90 90
90

--------------------------------
Sample Input 3 

3 30
5 10 20
50 60 140

Sample Output 3

0 0 0 220
1 5 50 220
1 0 0 200
2 25 190 220
2 5 50 110
3 35 250 0
3 25 190 190
2 20 140 200
2 0 0 60
3 30 200 0
3 20 140 140
200
--------------------------------
*/

