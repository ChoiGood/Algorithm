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

    quicksort(1,n);

    for (int i=1; i<n; i++) {
        cout << S[i] << " ";
    }
    cout << S[n] << endl;
    cout << cnt;

    return 0;
}