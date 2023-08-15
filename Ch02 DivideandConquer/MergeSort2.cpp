#include <iostream>
#include <vector>

using namespace std;

// 전역 변수 연습하게 써봐

vector<int> S;
int cnt=0;

void merge2(int low, int mid, int high) {
    int i, j, k;
    vector<int> U(high - low + 1);

    i = low; j = mid+1; k = 0;
    while (i <= mid && j <= high) {
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
        ::cnt++; // S의 원소끼리의 비교 연산 횟수 카운트. cnt는 전역 변수
    }

    if (i > mid)
        while (j <= high) U[k++] = S[j++];
    else
        while (i <= mid) U[k++] = S[i++];
    
    for (int t = low; t <= high; t++)
        S[t] = U[t-low];
}

void mergesort2(int low, int high)
{
    if (low < high) {
        int mid = (low + high) /2 ;
        mergesort2(low,mid);
        mergesort2(mid+1, high);
        merge2(low,mid,high);
    }
}





int main()
{
    int n; cin >> n;

    S.resize(n+1);

    for(int i=1; i<=n;i++) {
        cin >> S[i];
    }

    mergesort2(1,n);

    for (int i=1; i<n; i++) {
        cout << S[i] << " ";
    }
    cout << S[n] << endl;
    cout << ::cnt;

    return 0;
}
/*
합병 정렬 2
Description

교재와 강의자료를 참고하여, Algorithm 2.4/2.5 합병 정렬 2 알고리즘을 구현하시오.

N개의 원소를 가진 정렬되지 않은 양의 정수의 리스트 S를 합병정렬 2 알고리즘으로 오름차순으로 정렬하고,

merge2() 함수에서 비교 연산의 총 횟수를 출력한다.

단, 인덱스끼리의 비교 연산은 무시하고, 아래 코드의 예시와 같이 리스트 S의 원소끼리의 비교 연산 횟수만 카운트한다.

void merge2(int low, int mid, int high) {
    int i, j, k;
    vector<int> U(high - low + 1);

    i = low; j = mid+1; k = 0;
    while (i <= mid && j <= high) {
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
        cnt++; // S의 원소끼리의 비교 연산 횟수 카운트. cnt는 전역 변수
    }

    if (i > mid)
        while (j <= high) U[k++] = S[j++];
    else
        while (i <= mid) U[k++] = S[i++];
    
    for (int t = low; t <= high; t++)
        S[t] = U[t-low];
}

Input
첫째 줄에 리스트의 원소 개수 N이 주어진다.

둘째 줄에 정렬되지 않은 N개의 양의 정수가 주어진다.


Output
첫째 줄에 주어진 리스트를 합병 정렬 2로 정렬하여 오름차순으로 출력한다.

둘째 줄에 merge2() 함수에서 비교 연산의 총 횟수를 출력한다.


Sample Input 1 

8
27 10 12 20 25 13 15 22
Sample Output 1

10 12 13 15 20 22 25 27
17
Sample Input 2 

11
91 34 27 66 58 42 37 19 20 73 84
Sample Output 2

19 20 27 34 37 42 58 66 73 84 91
26
*/