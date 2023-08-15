#include <iostream>
#include <vector>

using namespace std;

void collaz(long int n,vector<long int> &v)
{
    v.push_back(n);
    if (n==1) {
        return;
    }
    else if (n%2==0) {
        collaz(n/2,v);
    }
    else {
        collaz(3*n+1,v);
    }
}


int main()
{
    vector<long int> v;
    long int n; cin >>n;
    collaz(n,v);

    for(int i : v)
        cout << i << " ";


    return 0;
}

/*
콜라츠 수열 출력하기
Description

1937년, 로타르 콜라츠가 제기한 콜라츠 추측(Collatz Conjecture)에 따르면,

모든 양의 정수 n에 대하여아래와 같은 연산을 반복하면 반드시 1로 수렴한다고 한다.

n이 짝수이면 n을 2로 나눈다.
n이 홀수이면 n에 3을 곱해서 1을 더한다.
콜라츠 추측은 유명한 수학사의 난제로 남아 있으며, 아직도 아무도 증명하지 못했다고 한다.

양의 정수 N에 대하여, N이 1로 수렴할 때까지 위의 연산을 반복할 때 나오는 수열을 콜라츠 수열이라고 하자.

임의의 양의 정수 N이 주어질 때 콜라츠 수열을 출력하시오.


Input
첫째 줄에 양의 정수 N이 주어진다.


Output
첫째 줄에 양의 정수 N에 대한 콜라츠 수열을 순서대로 출력한다.


Sample Input 1 : 1
Sample Output 1 : 1

Sample Input 2  : 7
Sample Output 2 : 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

Sample Input 3  : 10
Sample Output 3 : 10 5 16 8 4 2 1
*/