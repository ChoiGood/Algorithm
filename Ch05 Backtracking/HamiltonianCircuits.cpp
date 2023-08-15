#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> vindex;
vector<vector<int>> W;

int count = 0;

bool promising(int i)
{
    int j;
    bool flag;
    if (i == n -1 && !W[vindex[n-1]][vindex[0]])
        flag = false;
    else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
        flag = false;
    else {
        flag = true;
        j = 1;
        while(j < i && flag) {
            if (vindex[i] == vindex[j])
                flag = false;
            j++;
        }
    }
    return flag;
}


void hamiltonian(int i)
{
    int j;

    if(promising(i)) {
        if (i == n - 1) {
            //cout << vindex[0] through vindex[n-1]
            ::count++;
        }
        else {
            for(j = 2; j<= n; j++) {
                vindex[i+1] = j;
                hamiltonian(i+1);
            }
        }
    }
}

void InputW(int n)
{
    int a, b;
    for(int i=1; i<=n; i++) {
        cin >> a >> b;
        W[a][b] = 1;
        W[b][a] = 1;
    }
}


int main()
{
    int m; cin >> n >> m;
    W.resize(n+1, vector<int> (n+1,0));
    vindex.resize(n+1);

    InputW(m);

    vindex[0] = 1;
    hamiltonian(0);

    cout << ::count;


    return 0;
}

// 해밀턴 회로 문제
/*
Description
교재와 강의자료를 참고하여 해밀턴 회로 문제를 해결하는 Algorithm 5.6의 구현을 완성하시오.
주어진 무방향 무가중치 그래프 G=(V,E) 에서 해밀턴 회로의 개수를 출력하시오.

Algorithm 5.6을 구현할 때, 출발정점은 1로 간주한다는 것을 주의하시오.
vindex[0] = 1;
hamiltonian(0);

INPUT
첫째 줄에 정점의 개수 n과 간선의 개수 m이 주어진다.
둘쨰 줄부터 m개의 간선이 주어진다.

OUTPUT
첫째 줄에 해밀턴 회러의 개수를 출력한다.
*/

/*
----------------------------------------
Sample Input 1 

8 13
1 2
1 3
1 7
1 8
2 3
2 7
2 8
3 4
3 6
4 5
5 6
6 7
7 8
Sample Output 1

8
-------------------------------------------
Sample Input 2 

5 6
1 2
1 5
2 3
2 4
2 5
3 4
Sample Output 2

0
---------------------------------------------
*/