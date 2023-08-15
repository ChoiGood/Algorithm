#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binsearch(int n, vector<int> S, int x, int& location)
{
   int a,b,middle;
   a=1; b=n;
   while(true)
   {
    if(a>b) break;
    middle = (a+b)/2;
    if (x<S[middle])
    {
        b=middle-1;
    }
    else if (x>S[middle])
    {
        a=middle+1;
    }
    else{
        location = middle;
        return ;
    }

   }
   location = 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> S(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    sort(S.begin() + 1, S.end());
    while (m--) {
        int x, location;
        scanf("%d", &x);
        binsearch(n, S, x, location);
        if (location > 0)
            printf("%d is in %d.\n", x, location);
        else
            printf("%d is not in S.\n", x);
    }
}

/*
이분 탐색
Description

교재의 Algorithm 1.5. Binary Search 를 아래와 같이 C++ 언어로 구현하시오.

#include <bits/stdc++.h>
using namespace std;

void binsearch(int n, vector<int> S, int x, int& location);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> S(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    sort(S.begin() + 1, S.end());
    while (m--) {
        int x, location;
        scanf("%d", &x);
        binsearch(n, S, x, location);
        if (location > 0)
            printf("%d is in %d.\n", x, location);
        else
            printf("%d is not in S.\n", x);
    }
}
온라인 저지 제출시에는 binsearch() 함수의 구현 부분만 제출하면 된다.


Input
첫째 줄에 양의 정수 N과 M이 주어진다.

둘째 줄에 N개의 양의 정수가 주어진다.

셋째 줄에 M개의 양의 정수가 주어진다.


Output
첫째 줄부터 한 줄에 하나씩, 입력의 셋째 줄에 주어진 양의 정수 x에 대해 아래와 같은 형식으로 위치를 출력한다.

x is in location.

만약 x가 주어진 입력에 존재하지 않으면 다음과 같이 출력한다.

x is not in S.


Sample Input 1 

6 3
10 7 11 5 13 8
5 8 3
Sample Output 1

5 is in 1.
8 is in 3.
3 is not in S.
*/