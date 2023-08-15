#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void exchange(int n, vector<int>& S)
{
    for (int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
          if(S[i] > S[j])
          {
            swap(S[i],S[j]);
          }
        }
    }

}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> S(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    exchange(n, S);
    for (int i = 1; i <= n; i++)
        if (i < n)
            printf("%d ", S[i]);
        else
            printf("%d\n", S[i]);
    
    printf("ab");
    return 0;
}

/*
교환 정렬
Description

교재의 Algorithm 1.3. Exchange Sort 를 아래와 같이 C++ 언어로 구현하시오.

#include <bits/stdc++.h>
using namespace std;

void exchange(int n, vector<int>& S);

int main() {
    int n;
    scanf("%d", &n);
    vector<int> S(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    exchange(n, S);
    for (int i = 1; i <= n; i++)
        if (i < n)
            printf("%d ", S[i]);
        else
            printf("%d\n", S[i]);
}
온라인 저지 제출시에는 exchange() 함수의 구현 부분만 제출하면 된다.


Input
첫째 줄에 양의 정수 N이 주어진다.

둘째 줄에 N개의 양의 정수가 주어진다.


Output
첫째 줄에 주어진 배열 S를 오름차순으로 정렬하여 출력한다.


Sample Input 1 

6
10 7 11 5 13 8
Sample Output 1

5 7 8 10 11 13
*/