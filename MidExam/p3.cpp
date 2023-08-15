#include <iostream>
#include <vector>

using namespace std;

vector<int> S;
int cnt=0;

void partition(int low, int high, int& pivotpoint) {
    int i, j, pivotitem;
    
    swap(S[low],S[high]);
    pivotitem = S[low];
    j = low;
    for (i = low+1; i <= high; i++) {
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
            cnt++; // swap 연산의 실행 횟수 카운트
        }
    }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
    cnt++; // swap 연산의 실행 횟수 카운트
}

void quicksort(int low,int high)
{
    int pivotpoint;

    if(low<high) {
        partition(low,high,pivotpoint);
        quicksort(low,pivotpoint -1);
        quicksort(pivotpoint +1, high);
    }
}

int main()
{
    int n; cin >>n;
    S.resize(n+1);

    for (int i=1; i<=n; i++) {
        cin >> S[i];
    }
    int pivot;
    //quicksort(1,n);
    partition(1,n,pivot);
    for (int i=1; i<n; i++) {
        cout << S[i] << " ";
    }
    cout << S[n] << endl;
    cout << cnt;

    return 0;
}

/*
퀵 정렬
Description

교재와 강의자료를 참고하여, Algorithm 2.6/2.7 퀵 정렬/분할 알고리즘을 구현하시오.

N개의 원소를 가진 정렬되지 않은 양의 정수의 리스트 S를 퀵 정렬 알고리즘으로 오름차순으로 정렬하고,

partition() 함수에서 swap 연산의 실행 횟수를 아래 코드의 예시와 같이 카운트하여 출력하시오.

void partition(int low, int high, int& pivotpoint) {
    int i, j, pivotitem;

    pivotitem = S[low];
    j = low;
    for (i = low+1; i <= high; i++) {
        if (S[i] < pivotitem) {
            j++;
            swap(S[i], S[j]);
            cnt++; // swap 연산의 실행 횟수 카운트
        }
    }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
    cnt++; // swap 연산의 실행 횟수 카운트
}


Input
첫째 줄에 리스트의 원소 개수 N이 주어진다.

둘째 줄에 정렬되지 않은 N개의 양의 정수가 주어진다.


Output
첫째 줄에 주어진 리스트를 퀵 정렬로 정렬하여 오름차순으로 출력한다.

둘째 줄에 swap 연산의 총 실행 횟수를 출력한다.


Sample Input 1 

8
15 22 13 27 12 10 20 25
Sample Output 1

10 12 13 15 20 22 25 27
11
Sample Input 2 

10
1 2 3 4 5 6 7 8 9 10
Sample Output 2

1 2 3 4 5 6 7 8 9 10
9
Sample Input 3 

10
10 9 8 7 6 5 4 3 2 1
Sample Output 3

1 2 3 4 5 6 7 8 9 10
34
*/