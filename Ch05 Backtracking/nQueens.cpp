#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> col;
int n;
int count = 0;
string result;

bool promising(int i) {
    int k =1;
    bool flag = true;

    while(k<i && flag) {
        if((col[i] == col[k]) || (abs(col[i] - col[k]) == i - k))
            flag = false;
        k++;
    }
    return flag;
}


void queens(int i)
{
    int j;
    
    if(promising(i)) {
        if (i==n) {
            // cout << col[1] through col[n];
            ::count++;
            string str;
            for(int i=1; i<=n; i++) {
                str += to_string(col[i]);
            }
            
            if(result.empty()) {
                result = str;
            }
            else {
                if (result < str) { // 여기서 최대 최소 너가 정해
                    swap(result, str);
                }
            }
            str.clear();
        }
        else
            for (j = 1; j<=n; j++) {
                col[i + 1] = j;
                queens(i+1);
            }
    }
}



int main()
{
    cin >> n;
    col.resize(n+1);

    queens(0);

    cout << ::count << endl;
    cout << result;

    return 0;
}


// n-Queens 문제
/*
Description
교재와 강의자료를 참고하여 n-Queens 문제를 해결하는 Algorithm 5.1 을 완성하시오.
n의 값이 주어질 때, n-Queens 문제를 해결하는 보드의 배치가 총 몇 개인지를 카운트하고,
col 배열의 값을 숫자의 문자열로 취급했을 때 가장 큰 값을 출력하도록 수정하시오.

예)
n = 4 일 때 가능한 보드의 배치는 다음과 같이 총 2개가 이싿.
col1 = [2,4,1,3]
col2 = [3,1,4,2]
위 배치의 col 배열을 숫자의 문자열로 취급하면 각각 2413,3142의 값을 갖는다.
따라서 이 문제의 출력은 다음과 같다.
2 : 가능한 보드 배치의 갯수
3142 : 가능한 보드 배치 중에서 숫자의 문자열이 가장 큰 값

INPUT
첫 줄에 n의 값이 주어진다.
단, n은 4보다 크거나 같다.

OUTPUT
첫 줄에 가능한 보드의 배치 개수를 출력한다.
둘쨰 줄에 col 배열의 값을 숫자의 문자열로 취급했을 때 최대값을 출력한다.
*/

/*
------------------------------------------
Sample Input 1 

4
Sample Output 1

2
3142

---------------------------------------
Sample Input 2 

9
Sample Output 2

14200
975811210364211
*/

