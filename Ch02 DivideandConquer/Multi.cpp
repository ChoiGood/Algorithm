#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;

matrix_t multivec(matrix_t a,matrix_t b,int n)
{
    matrix_t c(n+1,vector<int>(n+1));
    int cnt;
    for(int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++){
            cnt=0;
            for(int k=1;k<=n;k++) {
                cnt += ((a[i][k])*(b[k][j]));
            }
            c[i][j]=cnt%1000;
        }
    }
    return c;
}

matrix_t solve(matrix_t a, int b, int n)
{
    matrix_t c(n+1,vector<int>(n+1));
    if(b==1) {
        return a;
    }
    else {
        c= solve(a,b/2,n);
        if(b%2==0) {
            return multivec(c,c,n);
        }
        else {
            return multivec(a,multivec(c,c,n),n);
        }
    }
}

int main()
{
    int n, m ; cin>> n >> m;

    matrix_t a(n+1,vector<int> (n+1));
    matrix_t c(n+1,vector<int> (n+1));

    for (int i=1;i<=n;i++) {
        for (int j=1; j<=n;j++) {
            cin >> a[i][j];
        }
    } 

    c=solve(a,m,n);

    for(int i=1;i<=n;i++) {
        for(int j=1; j<n;j++) {
            cout << c[i][j] << " ";
        }
        cout << c[i][n] << endl;
    }



    return 0;
}

/*
행렬의 거듭제곱
Description

�
×
�
N×N 정방행렬 A와 양의 정수 b가 주어졌을 때, A 행렬의 b 거듭제곱인 정방행렬 
�
�
A 
b
 을 출력하시오.

단, 행렬의 원소는 항상 1,000으로 나눈 나머지 값만을 가진다. (거듭제곱의 중간 과정을 포함하여)



Note:

이 문제는 분할정복을 이용한 모듈러 거듭제곱 알고리즘을 행렬에 적용하여 구현하는 문제이다.

두 정수 a, b에 대하여
�
�
a 
b
 을 구하는 문제를 생각해보자.

종료 조건은 b가 1일 때, a를 리턴하면 된다는 것은 명확하다.

재귀 조건은 다음과 같은 두 가지 경우로 나누어 생각해 볼 수 있다.

만약, b가 짝수라면, 다음 규칙이 성립한다.

�
�
=
�
�
2
×
�
�
2
a 
b
 =a 
2
b
​
 
 ×a 
2
b
​
 
 
만약, b가 홀수라면, 다음 규칙이 성립한다.

�
�
=
�
×
�
⌊
�
2
⌋
×
�
⌊
�
2
⌋
a 
b
 =a×a 
⌊ 
2
b
​
 ⌋
 ×a 
⌊ 
2
b
​
 ⌋
 

위의 재귀적 관계에서 모듈러 곱셈 연산의 다음 성질을 이용할 수 있다.

ab % N = {(a % N)
×
×(b % N)} % N



이렇게 종료 조건과 재귀 조건을 모두 파악했다면

기존의 과제에서 풀었던 행렬 곱셈 알고리즘을 위의 재귀 관계에 대입하면 이 문제를 풀 수 있다.

단순한 행렬 곱셈으로는 O(b) 번의 곱셈을 해야 하므로 시간 초과가 발생할 것이고,

분할 정복을 이용하여 O(log b) 번의 곱셈으로 거듭제곱을 할 수 있어야 시간 초과를 면할 수 있다.

또한, 모듈러 연산을 통해 중간 과정에서 오버플로우가 발생하지 않도록 주의해야 한다.


Input
첫째 줄에 행렬의 크기 N과 거듭제곱의 크기 b가 주어진다.

둘째 줄부터 N개의 줄에 행렬의 각 원소가 N개씩 주어진다.

행렬의 각 원소는 1,000보다 작은 음이 아닌 정수이다.


Output
첫째 줄부터 행렬 A를 b번 거듭제곱한 정방행렬
�
�
A 
b
  를 출력한다.

행렬의 곱셈 과정에서 모든 원소는 1,000으로 나눈 나머지 값을 가진다.


Sample Input 1 

2 3
1 2
3 4
Sample Output 1

37 54
81 118
Sample Input 2 

3 1234567
1 2 3
4 5 6
7 8 9
Sample Output 2

432 744 56
958 65 172
484 386 288
*/