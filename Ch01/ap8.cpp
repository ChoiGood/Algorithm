#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    vector<int> S(n+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&S[i]);
    sort(S.begin()+1,S.end());
    
    if (n%2==0)
        printf("%d %d %d",S[1],S[n/2],S[n]);
    else
        printf("%d %d %d",S[1],S[n/2+1],S[n]);

    return 0;
}

/*
최솟값, 중앙값, 최댓값
Description

주어진 배열의 최솟값, 중앙값, 최댓값을 출력하시오.

배열의 원소 인덱스는 1부터 N까지로 가정하며, 중앙값은 [N/2]위치에 있는 값으로 정의한다.



Algorithm 1.3 교환 정렬을 이용해도 되지만,

가급적 언어별로 제공되는 정렬 라이브러리 함수를 이용하시오.

C: qsort()

C++: sort()

Java: Arrays.sort() 또는 Collections.sort()

Python: 리스트의 sort() 메서드, 또는 sorted() 함수


Input
첫째 줄에 양의 정수 N이 주어진다.

둘째 줄에 N개의 양의 정수가 주어진다.


Output
첫째 줄에 최솟값, 중앙값, 최댓값을 차례대로 출력한다.

배열의 원소 인덱스는 1부터 N까지로 가정하며, 중앙값은 [N/2] 위치에 있는 값으로 정의한다.


Sample Input 1 

6
10 7 11 5 13 8
Sample Output 1

5 8 13
*/