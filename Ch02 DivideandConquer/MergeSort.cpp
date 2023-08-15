#include <iostream>
#include <vector>

using namespace std;
/*
    N개의 원소를 가진 정렬되지 않은 양의 정수의 리스트 S를 합병 정렬 알고리즘으로
    오름차순으로 정렬하고 ,

    merge()함수에서 추가적으로 사용하는 메모리 U,V의 크기의 총합ㅇ르 출력하시오.

    단, 인덱스로 인한 크기는 무시하며, 아래 코드 예시와 같이 h,m의 크기만 더한 총합을 구한다.
*/
int cnt=0;

void merge(int h,int m, vector<int> U,vector<int> V, vector<int> &S)
{
    int i=1,j=1,k=1;
    while(i <= h && j<=m) {
        if (U[i]>V[j]) {
            S[k] = V[j]; k++; j++;
        }
        else {
            S[k] = U[i]; k++; i++;
        }
    }

    if (i>h) {
        // copy V[j] through V[m] to S[k] through S[h+m]
        while(j<=m) {
            S[k]=V[j]; k++; j++;
        }
    }
    else {  // j>m
        while(i<=h) {
            S[k]=U[i]; k++; i++;
        }
    }

}

void mergesort(int n, vector<int>& S) {
    if (n>1) {
        int h = n/2, m= n-h;
        vector<int> U(h+1), V(m+1);
        ::cnt += h+m; // 추가 메모리 크기 카운트 cnt는 전역 변수
        for (int i =1; i<=h;i++)
            U[i] = S[i];
        
        for(int i= h+1;i<=n;i++)
            V[i-h] = S[i];
        
        mergesort(h,U);
        mergesort(m,V);
        merge(h,m,U,V,S);
    }
}



int main()
{   
    int n; cin >> n;
    vector<int> v(n+1);


    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }
    
    mergesort(n,v);

    for(int i=1; i<n; i++) {
        cout << v[i] << " ";
    }
    cout << v[n] << endl;
    cout << ::cnt;

    return 0;
}

/*
합병 정렬 1
Description

교재와 강의자료를 참고하여 Algorithm 2.2/2.3 합병정렬 알고리즘을 구현하시오.

N개의 원소를 가진 정렬되지 않은 양의 정수의 리스트 S를 합병정렬 알고리즘으로 오름차순으로 정렬하고,

merge() 함수에서 추가적으로 사용하는 메모리 U, V의 크기의 총합을 출력하시오.

단, 인덱스로 인한 크기는 무시하며, 아래 코드 예시와 같이 h, m의 크기만 더한 총합을 구한다.

void mergesort(int n, vector<int>& S) {
    if (n > 1) {
        int h = n / 2, m = n - h;
        vector<int> U(h+1), V(m+1);
        cnt += h + m; // 추가 메모리 크기 카운트. cnt는 전역 변수
        for (int i = 1; i <= h; i++)
            U[i] = S[i];
        for (int i = h+1; i <= n; i++)
            V[i - h] = S[i];
        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);
    }
}

Input
첫째 줄에 리스트의 원소 개수 N이 주어진다.

둘째 줄에 정렬되지 않은 N개의 양의 정수가 주어진다.


Output
첫째 줄에 주어진 리스트를 합병 정렬로 정렬하여 오름차순으로 출력한다.

둘째 줄에 merge() 함수에서 추가적으로 사용하는 메모리의 총합을 출력한다.


Sample Input 1 

8
27 10 12 20 25 13 15 22
Sample Output 1

10 12 13 15 20 22 25 27
24
Sample Input 2 

11
91 34 27 66 58 42 37 19 20 73 84
Sample Output 2

19 20 27 34 37 42 58 66 73 84 91
39
*/