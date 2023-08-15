#include <iostream>
using namespace std;

int count=0; // 하노이 함수(아래 함수일듯?) 호출 횟수
int move=0;  // 이동횟수

void hanoi(int n, char src, char via, char dst, int m) {
    ::count++;
    if (n == 1) {
        ::move++;
        if (::move == m) {
            printf("%c -> %c\n", src, dst);
        }
    }
    else {
        hanoi(n-1, src, dst, via,m);
        hanoi(1, src, via, dst,m);
        hanoi(n-1, via, src, dst,m);
    }
}

int main() {
    int n,m; cin >> n >>m;
    
    hanoi(n, 'A', 'B', 'C',m);
    cout << ::count;
}

/*
하노이의 탑
Description

하노이의 탑에는 세 개의 기둥과 크기가 서로 다른 N개의 원반이 있다.

세 개의 기둥을 각각 A, B, C라고 하고, 처음에 원반은 모두 A 기둥에 꽂혀 있다.

하노이 탑의 수도승들은 A 기둥에 있는 원반을 모두 C 기둥으로 옮겨야 한다.

원반을 옮기는 규칙은 다음과 같다.

한 번에 하나의 원반만 움직일 수 있고, 각 기둥의 제일 위에 있는 원반을 옮겨야 한다.
반드시 크기가 작은 원반이 크기가 큰 원반 위에 놓여야 한다.
한 원반의 이동은 이동하려는 원반의 시작 기둥과 도착 기둥의 이름으로 표시한다.

예를 들어, A 기둥에 있는 원반 하나를 C 기둥으로 옮기는 것을 다음과 같이 표시한다.

A -> B
주니온은 이 문제를 풀기 위해 아래와 같은 재귀 알고리즘을 이용한 프로그램을 작성했다.

#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char src, char via, char dst) {
    if (n == 1) {
        printf("%c -> %c\n", src, dst);
    }
    else {
        hanoi(n-1, src, dst, via);
        hanoi(1, src, via, dst);
        hanoi(n-1, via, src, dst);
    }
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
}
원반의 개수 N가 이동 횟수 K가 주어졌을 때,

위 알고리즘으로 N개의 원반을 이동할 때, K번째로 이동하는 원반의 시작 기둥와 도착 기둥을 출력하시오.


Input
첫째 줄에 원반의 개수 N가 이동 횟수 K가 주어진다.


Output
첫째 줄에 K번째 이동하는 원반의 시작 기둥과 도착 기둥을 출력한다.

둘째 줄에 hanoi() 함수의 총 호출 횟수를 출력한다.


Sample Input 1 

3 4
Sample Output 1

A -> C
10
Sample Input 2 

4 8
Sample Output 2

A -> C
22
Sample Input 3 

10 10
Sample Output 3

B -> A
1534
*/