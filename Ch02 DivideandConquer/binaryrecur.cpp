#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Inputdata(vector<int> &v, int n)
{
      for(int i=1;i<=n;i++) {
        cin >> v[i];
    }

}

int count =0;

int location(int low,int high,vector<int> s, int find)
{
    ::count++;
    int mid;

    if (low>high)
        return 0;
    else {
        mid = (low+high)/2;
        if (s[mid]==find) {
            return mid;
        }
        else if (s[mid]>find) {
            return location(low,mid-1,s,find);
        }
        else {
            return location(mid+1,high,s,find);
        }
    }
}

int main()
{
    int n,m; cin >> n >> m;
    vector<int> v(n+1);
    vector<int> w(m+1);

    Inputdata(v,n);
    Inputdata(w,m);

    sort(v.begin()+1,v.end());

    int k;


    for(int i=1;i<=m;i++) {
        k=location(1,n,v,w[i]);
        cout << ::count <<" " << k << endl;
        ::count=0;    
    }

    


    return 0;
}

/*
이분 탐색 (재귀)
Description

교재와 강의자료를 참고하여, Algorithm 2.1 이분 탐색 (재귀) 알고리즘을 구현하시오.

정렬되지 않은 채로 주어진 N개의 정수 리스트에서

해당 리스트를 정렬한 후에 M개의 정수를 탐색하여, 원소의 위치와 location() 함수의 호출 횟수를 출력하시오.


Input
첫째 줄에 양의 정수 N과 M이 주어진다.

둘째 줄에 정렬되지 않은 양의 정수 N개가 주어진다.

셋째 줄에 리스트에서 탐색하고자 하는 양의 정수 M개가 주어진다.


Output
첫째 줄부터 M개의 줄에 한 줄에 하나씩 이분 탐색 결과를 출력한다.

각 줄의 첫 번째 값은 이분 탐색 과정에서 location() 함수의 호출 횟수이다.

각 줄의 두 번째 값은 정렬된 리스트에서의 위치 인덱스이다. (location() 함수의 리턴값)


Sample Input 1 

6 3
10 7 11 5 13 8
5 8 3
Sample Output 1

2 1
1 3
3 0

*/