#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(int n, vector<int> S)
{
    int total=0;
    for (int i =1; i<=S.size();i++)
    {
        total+=S[i];
    }
    return total;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> S(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    printf("%d", sum(n, S));
}

/*
배열 원소 더하기
Description

교재의 Algorithm 1.2. Adding Array Members 를 아래와 같이 C++ 언어로 구현하시오.

#include <bits/stdc++.h>
using namespace std;

int sum(int n, vector<int> S);

int main() {
    int n;
    scanf("%d", &n);
    vector<int> S(n+1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &S[i]);
    printf("%d", sum(n, S));
}
온라인 저지 제출시에는 sum() 함수의 구현 부분만 제출하면 된다.


Input
첫째 줄에 양의 정수 N이 주어진다.

둘째 줄에 N개의 배열 원소가 주어진다.


Output
첫째 줄에 배열 원소의 합 S를 출력한다.


Sample Input 1 

6
10 7 11 5 13 8
Sample Output 1

54
*/