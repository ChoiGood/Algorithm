#include <iostream>
#include <vector>

using namespace std;

int W;
vector<int> w;
vector<bool> include;

int count = 0;
vector<vector<bool>> result;

bool promising(int i, int weight, int total) {
    return (weight + total >= W) && (weight == W || weight + w[i+1] <= W);
}

void sum_of_subsets(int i, int weight, int total)
{
    if(promising(i, weight, total)) {
        if(weight == W) {
            //cout << include[1] through include [i];
            ::count++;
            result.push_back(include);

        }
        else {
            include[i+1] = true;
            sum_of_subsets(i+1, weight + w[i+1], total - w[i+1]);
            include[i+1] = false;
            sum_of_subsets(i+1, weight, total - w[i+1]);

        }
    }
}

void Rprint(int n) {
    int first;
    for(int i=0; i<::count; i++) {
        first = 1;
        for(int j=1; j<=n; j++) {
            if(result[i][j]) {
                if(first) {
                    cout << w[j];
                    first = 0;
                } else {
                    cout << " " << w[j];
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    int n; cin >> n;    cin >> W;  // W는 전역으로 설정함.
    int total=0;

    w.resize(n+1);
    include.resize(n+1);

    for(int i=1; i<=n; i++) {
        cin >> w[i];
        total += w[i];
    }

    sum_of_subsets(0,0,total);

    cout << ::count << endl;
    Rprint(n);



    return 0;
}

// 부분집합의 합 문제
/*
Description
교재와 강의자료를 참고하여 Sum-of-Subsets 문제를 푸는 Algorithm 5.4의 구현을 완성하시오.
n개의 원소를 가진 정수의 집합 S가 주어지고,
임의의 정수 W가 주어졌을 때,
합이 W가 되는 부분집합의 개수와 각 부분집합을 출력하도록 하시오.

INPUT
첫 줄에 원소의 개수 n과 임의의 정수 W가 주어진다.
둘 째줄에 n개의 정수가 주어진다.

OUTPUT
첫 줄에 원소의 합이 W가 되는 부분집합의 개수를 출력한다.
둘째 줄부터 원소의 합이 W가 되는 모든 부분집합을 한 줄에 하나씩 출력한다.

단, 부분집합에서의 원소 출력 순서는 주어진 S의 원소 순서와 동일해야 한다. (백트래킹 순서대로)
*/

/*
--------------------------------------------
Sample Input 1 

4 13
3 4 5 6
Sample Output 1

1
3 4 6
--------------------------------------------
Sample Input 2 

3 10
1 2 3
Sample Output 2

0
--------------------------------------------
*/