#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef struct item *item_ptr;
typedef struct item {
    int id;
    int weight;
    int profit;
    int profit_per_unit;    // = profit / weight
} item_t;

int n, W;
int maxprofit;
vector<item_t> items;
vector<bool> include;

vector<bool> bestset;
float prebound;


bool compare_item(item_t i, item_t j) {
    if(i.profit_per_unit > j.profit_per_unit)
        return true;
    return false;
}

bool promising(int i, int profit, int weight)
{
    int j,k, totweight;
    float bound;
    if (weight >= W) {        // 첫 번째 조건 : 배낭 무게
        cout << i << " " << weight << " " << profit << " " << prebound << " " << maxprofit << endl;
        return false;
    }
    else {                 // 두 번째 조건 : 바운드
        j = i + 1;
        bound = profit;
        totweight = weight;
        while(j <= n && totweight + items[j].weight <= W) {
            totweight += items[j].weight;
            bound += items[j].profit;
            j++;
        }
        k = j;
        if(k <= n)
            bound += (W - totweight) * ((float)items[k].profit / items[k].weight);

        if(bound != 0)
            cout << i << " " << weight << " " << profit << " " << bound << " " << maxprofit << endl;
        prebound = bound;
        
        return bound > maxprofit;
    }
}

void knapsack4(int i, int profit, int weight)
{
    if (weight <= W && profit > maxprofit) {
        maxprofit = profit;
        copy(include.begin(), include.end(), bestset.begin());  // copy from include to bestset
    }

    if (promising(i, profit, weight)) {
        include[i+1] = true;
        knapsack4(i+1, profit + items[i+1].profit, weight + items[i+1].weight);
        include[i+1] = false;
        knapsack4(i+1, profit, weight);
    }
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
}



int main()
{
    cin >> n >> W;
    vector<int> w(n+1);
    vector<int> p(n+1);
    include.resize(n+1);
    bestset.resize(n+1);
   
    InputItem(n,w,p);
    sort(items.begin()+1, items.end(),compare_item);

    maxprofit = 0;
    knapsack4(0,0,0);

    cout << maxprofit << endl;
    for(int i=1; i<=n; i++) {
        if(bestset[i])
            cout << items[i].weight << " " <<items[i].profit << endl;
    }
    

    
    return 0;
}


// 0-1 배낭문제와 백트레킹
/*
Description
교재와 강의자료를 참고하여 0-1 배낭문제를 해결하는 Algorithm 5.7을 완성하시오.

단, 문제의 입력은 단위무게당 이익순으로 정렬되어 있지 않음에 유의하시오.
또한, 알고리즘의 출력은 알고리즘의 실행 단계별로
상태공간트리의 각 노드에서의 상태를 출력해야 함에 주의하시오.

INPUT
첫 번째 줄에 아이템의 개수 n과 배낭의 무게 W가 주어진다.
두 번째 줄에 n개의 아이템 무게 w[i]가 주어진다.
세 번째 줄에 n개의 아이템 이익 p[i]가 주어진다.

OUTPUT
첫 번째 줄부터 한 줄에 하나씩 상태공간트리를 방문하는 노드의 상태를 출력하시오.
노드 상태는 다음과 같은 순서로 출력한다.
i weight profit bound maxprofit
상태를 출력하는 순서는 Algorithm 5.7의 노드 실행 순서이다. (즉, DFS with Pruningi의 노드 순회 순서임)
노드의 상태 출력이 끝나는 다음 줄에 최대이익을 출력한다.
이후로 배낭에 담은 아이템을 한 줄에 하나씩 무게와 이익 순서로 출력한다.
아이템을 출력하는 순서는 처음에 단위무게당 이익으로 정렬한 순서대로 출력함에 주의할 것.
*/

/*
---------------------------------------
Sample Input 1 

4 16
2 5 10 5
40 30 50 10
Sample Output 1

0 0 0 115 0
1 2 40 115 40
2 7 70 115 70
3 17 120 115 70
3 7 70 80 70
4 12 80 80 80
4 7 70 70 80
2 2 40 98 80
3 12 90 98 90
4 17 100 98 90
4 12 90 90 90
3 2 40 50 90
1 0 0 82 90
90
2 40
10 50
---------------------------------------
Sample Input 2 

4 16
5 2 5 10
30 40 10 50
Sample Output 2

0 0 0 115 0
1 2 40 115 40
2 7 70 115 70
3 17 120 115 70
3 7 70 80 70
4 12 80 80 80
4 7 70 70 80
2 2 40 98 80
3 12 90 98 90
4 17 100 98 90
4 12 90 90 90
3 2 40 50 90
1 0 0 82 90
90
2 40
10 50
---------------------------------------
Sample Input 3 

5 16
2 5 7 3 1
20 30 35 12 3
Sample Output 3

0 0 0 93 0
1 2 20 93 20
2 7 50 93 50
3 14 85 93 85
4 17 97 93 85
4 14 85 88 85
5 15 88 88 88
5 14 85 85 88
3 7 50 65 88
2 2 20 70 88
1 0 0 80 88
88
2 20
5 30
7 35
1 3
---------------------------------------
*/