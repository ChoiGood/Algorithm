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
vector<item_t> items;
//vector<vector<int>> P;
map<pair<int, int>, int> P;

bool compare_item(item_t i, item_t j) {
    if(i.profit_per_unit > j.profit_per_unit)
        return true;
    return false;
}


// DP 방법으로 푼 배낭문제에서 어떻게 담은지를 알아내려면 어떤 함수를 만들어야하나?? PATH??

/*
int knapsack2(vector<vector<int>> &P)
{
    for (int i = 0; i <= n; i++)
        P[i][0] = 0;
    for (int j=1; j<=W; j++)
        P[0][j] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            P[i][j] = (items[i].weight > j) ? P[i-1][j] : max(P[i-1][j], items[i].profit + P[i-1][j-items[i].weight]); 
        }
    }

    return P[n][W];
}
*/

int knapsack3(int n, int W, map<pair<int, int>, int> &P)
{
    if(n == 0 || W <= 0)
        return 0;

    int lvalue = (P.find(make_pair(n-1,W)) != P.end()) ? P[make_pair(n-1,W)] : knapsack3(n-1,W,P);

    int rvalue = (P.find(make_pair(n-1, W-items[n].weight)) != P.end()) ? P[make_pair(n-1, W-items[n].weight)] : knapsack3(n-1, W-items[n].weight,P);

    P[make_pair(n,W)] = (items[n].weight > W) ? lvalue : max(lvalue, items[n].profit + rvalue);

    return P[make_pair(n,W)];
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

/*
void PrintTable()
{
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=W; j++) {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }
}
*/


int main()
{
    cin >> n;
    vector<int> w(n+1);
    vector<int> p(n+1);
   

    InputItem(n,w,p);
    sort(items.begin()+1, items.end(),compare_item);

    int t;
    cin >> t;
    
    for(int i=1; i<=t; i++) {
        cin >> W;
        cout << knapsack3(n,W,P) << endl;

        for(auto iter = P.begin(); iter != P.end(); ++iter) {
            cout << iter->first.first << " " << iter->first.second << " " << iter->second << endl;
        }

        P.clear();
    }
    
    
    return 0;
}


// 0-1 배낭문제와 동적계획법
/*
Description
교재의 내용과 강의자료를 참고하여 0-1 배낭문제를 해결하는 알고리즘의 구현을 완성하시오.

강의자료에서 knapsack2() 또는 knapsack3()를 참조할 것.

단, 입력값은 단위 무게당 이익의 순서로 정렬되어 있지 않음에 유의하시오.
또한, 알고리즘의 실행 결과의 출력은 알고리즘의 실행과정에서 결과 테이블 P에 저장한
무게(i) 또는 이익(j)이 0이 아닌 모든 항복 P[i][j]를 (i,j)의 오름차순으로 모두 출력한다는 것에 주의하시오.

INPUT
첫 번째 줄에 아이템의 개수 n이 주어진다.
두 번째 줄에 n개의 무게 w[i]가 주어진다.
세 번째 줄에 n개의 이익 p[i]가 주어진다.
네 번째 줄에 배낭 무게의 개수 T가 주어진다.
이후로 T개의 줄에 한 줄에 하나씩 배낭 무게 W가 주어진다.

OUTPUT
주어진 배낭 무게 W 각각에 대해 다음과 같이 출력한다.
첫 줄에 최대 이익 maxprofit을 출력한다.
이후로 알고리즘의 실행과정에서 결과 텥이블 P에 저장한
무게(i) 또는 이익(j)이 0이 아닌 모든 항목 P[i][j]를 (i,j)의 오름차순으로 모두 출력한다.
*/

/*
---------------------------------------------
Sample Input 1 

3
5 10 20
50 60 140
1
30
Sample Output 1

200
1 10 50
1 20 50
1 30 50
2 20 140
2 30 190
3 30 200

---------------------------------------------
Sample Input 2 

4
2 5 10 5
40 30 50 10
4
8
16
20
25
Sample Output 2

70
1 3 40
1 8 40
2 3 40
2 8 70
3 3 40
3 8 70
4 8 70
90
1 1 0
1 6 40
1 11 40
1 16 40
2 1 0
2 6 40
2 11 70
2 16 70
3 11 70
3 16 90
4 16 90
120
1 5 40
1 10 40
1 15 40
1 20 40
2 5 40
2 10 70
2 15 70
2 20 70
3 15 90
3 20 120
4 20 120
130
1 5 40
1 10 40
1 15 40
1 20 40
1 25 40
2 10 70
2 15 70
2 20 70
2 25 70
3 20 120
3 25 120
4 25 130

---------------------------------------------
Sample Input 3 

5
2 5 7 3 1
20 30 35 12 3
5
7
9
11
16
20
Sample Output 3

50
1 1 0
1 2 20
1 3 20
1 4 20
1 6 20
1 7 20
2 3 20
2 4 20
2 6 30
2 7 50
3 3 20
3 4 20
3 6 30
3 7 50
4 6 32
4 7 50
5 7 50
55
1 1 0
1 2 20
1 3 20
1 4 20
1 5 20
1 6 20
1 8 20
1 9 20
2 1 0
2 2 20
2 5 30
2 6 30
2 8 50
2 9 50
3 5 30
3 6 30
3 8 50
3 9 55
4 8 50
4 9 55
5 9 55
65
1 1 0
1 2 20
1 3 20
1 4 20
1 5 20
1 6 20
1 7 20
1 8 20
1 10 20
1 11 20
2 1 0
2 3 20
2 4 20
2 7 50
2 8 50
2 10 50
2 11 50
3 7 50
3 8 50
3 10 55
3 11 55
4 10 62
4 11 62
5 11 65
88
1 1 0
1 3 20
1 4 20
1 5 20
1 6 20
1 7 20
1 8 20
1 9 20
1 10 20
1 11 20
1 12 20
1 13 20
1 15 20
1 16 20
2 5 30
2 6 30
2 8 50
2 9 50
2 12 50
2 13 50
2 15 50
2 16 50
3 12 65
3 13 65
3 15 85
3 16 85
4 15 85
4 16 85
5 16 88
100
1 4 20
1 5 20
1 7 20
1 8 20
1 9 20
1 10 20
1 11 20
1 12 20
1 13 20
1 14 20
1 15 20
1 16 20
1 17 20
1 19 20
1 20 20
2 9 50
2 10 50
2 12 50
2 13 50
2 16 50
2 17 50
2 19 50
2 20 50
3 16 85
3 17 85
3 19 85
3 20 85
4 19 97
4 20 97
5 20 100
---------------------------------------------
*/

