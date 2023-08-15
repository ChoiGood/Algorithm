#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> LargeInteger;
int threshold = 1;

void roundup_carry(LargeInteger& v)
{
    int carry = 0;
    for (int i = 0; i < v.size(); i++) {
        v[i] += carry;
        carry = v[i] / 10;
        v[i] = v[i] % 10;
    }
    if (carry != 0)
        v.push_back(carry);
}

void ladd(LargeInteger a, LargeInteger b, LargeInteger& c)
{
    c.resize(max(a.size(), b.size()));
    fill(c.begin(), c.end(), 0);
    for (int i =0; i<c.size(); i++) {
        if (i < a.size()) c[i] += a[i];
        if (i < b.size()) c[i] += b[i];
    }
    roundup_carry(c);
}

void lsub(LargeInteger a, LargeInteger b, LargeInteger& c)
{
    c.resize(max(a.size(), b.size()));
    fill(c.begin(), c.end(), 0);
    for(int i=0; i<c.size(); i++) {
        if(i<a.size()) c[i] += a[i];
        if(i<b.size()) c[i] -= b[i];
    }
    for(int i=0; i<c.size();i++) {//양수일때만 생각하자
        if (c[i] < 0 && (i != c.size() -1)) {
            c[i+1] -= 1;
            c[i] += 10;
        }
    }
    if(c[c.size()-1] == 0) {
        c.resize(c.size()-1);
    }
}

void lmult(LargeInteger a, LargeInteger b, LargeInteger& c)
{
    c.resize(a.size() + b.size() -1);
    fill(c.begin(), c.end(), 0);
    for (int i =0; i< a.size(); i++)
        for (int j=0; j<b.size(); j++)
            c[i + j] += a[i] * b[j];
    roundup_carry(c);
}

void pow_by_exp(LargeInteger u, int m, LargeInteger &v)
{
    if (u.size() == 0)
        v.resize(0);
    else {
        v.resize(u.size() + m);
        fill(v.begin(), v.end(), 0);
        copy(u.begin(), u.end(), v.begin() + m);
    }
}

void remove_leading_zeros(LargeInteger &v) {
    while(v.size() != 0 && v.back()==0)
        v.pop_back();
}

void rem_by_exp(LargeInteger u, int m, LargeInteger &v) {
    if (u.size() == 0)
        v.resize(0);
    else {
        // Note that u.size() can be smaller than m.
        int k = m < u.size() ? m : u.size();
        v.resize(k);
        copy(u.begin(), u.begin() + k, v.begin());
        remove_leading_zeros(v);
    }
}

void div_by_exp(LargeInteger u, int m, LargeInteger &v) {
    if (u.size()==0)
        v.resize(0);
    else {
        int k = m < u.size() ? u.size() - m : 0; 
        v.resize(k);
        if (v.size()!=0)
            copy(u.begin()+m,u.end(),v.begin());
        remove_leading_zeros(v);
    }
}

int count =0;

void prod(LargeInteger u, LargeInteger v, LargeInteger &r) {
    ::count++;
    LargeInteger x, y, w, z;
    LargeInteger t1,t2, t3,t4,t5,t6,t7,t8;
    int n = max(u.size(), v.size());
    if (u.size() == 0 || v.size() == 0)
        r.resize(0);
    else if (n <= ::threshold)
        lmult(u,v,r);
    else {
        int m = n / 2;  
        div_by_exp(u,m,x); rem_by_exp(u,m,y);
        div_by_exp(v,m,w); rem_by_exp(v,m,z);
        // t2 <- prod(x,w) * 10^(2*m)
        prod(x, w, t1); pow_by_exp(t1, 2*m, t2);
        // t6 <- (prod(x,z) + prod(w,y)) * 10^m
        prod(x, z, t3); prod(w, y, t4); ladd(t3,t4,t5); pow_by_exp(t5, m, t6);
        // r <- t2 + t6 + prod(y, z)
        prod(y, z, t7); ladd(t2, t6, t8); ladd(t8,t7,r);
    }
}

void prod2(LargeInteger u, LargeInteger v, LargeInteger &r) {
    ::count++;
    LargeInteger x, y, w, z;
    LargeInteger t1,t2, t3,t4,t5,t6,t7,t8;
    int n = max(u.size(), v.size());
    if (u.size() == 0 || v.size() == 0)
        r.resize(0);
    else if (n <= ::threshold)
        lmult(u,v,r);
    else {
        int m = n / 2;  
        div_by_exp(u,m,x); rem_by_exp(u,m,y);
        div_by_exp(v,m,w); rem_by_exp(v,m,z);
        // t2 <- prod(x,w) * 10^(2*m)
        prod2(x, w, t1); pow_by_exp(t1, 2*m, t2);
        // t7 < - prod(y,z)
        prod2(y, z, t7); 
        // t6 <- (prod(x,z) + prod(w,y)) * 10^m
        ladd(x,y,t3); ladd(w,z,t4); prod2(t3,t4,t5);  lsub(t5,t1,t3); lsub(t3,t7,t4); pow_by_exp(t4, m, t6);
        // r <- t2 + t6 + prod(y, z)
        ladd(t2, t6, t8); ladd(t8,t7,r);
    }
}


void inputLint(string n, LargeInteger &v)
{
    for(int i=n.length()-1;i>=0;i--) {
        v.push_back(n[i]-'0');
    }        
}

/* 
int main()
{
    int th;  
    cin >> th;
    string str1,str2;
    cin >> str1 >> str2;

    LargeInteger A,B,C;
    ::threshold = th;
    inputLint(str1,A);
    inputLint(str2,B);

    lsub(A,B,C);

    for(int i=C.size()-1; i>=0;i--)
    {
        printf("%d",C[i]);
    }
} */


int main()
{
    int th;  
    cin >> th;
    string str1,str2;
    cin >> str1 >> str2;

    LargeInteger A,B,C;
    ::threshold = th;
    inputLint(str1,A);
    inputLint(str2,B);

    prod2(A,B,C);

    printf("%d\n",::count);
    for(int i=C.size()-1; i>=0;i--)
    {
        printf("%d",C[i]);
    }
    
    return 0;
}


/*
카라츠바 정수곱셈 알고리즘
Description

교재와 강의자료를 참고하여 Algorithm 2.9 큰 정수의 곱셈 문제를 구현하시오. (Algorithm 2.10이 아님에 주의)

이 알고리즘에서 두 개의 큰 정수와 threshold 값이 주어질 때, prod() 함수의 호출 횟수와 두 정수의 곱을 출력한다.



단, 알고리즘 호출의 중간 과정에서 leading zero(앞부분 0)를 제거해야 함에 주의할 것.

void remove_leading_zeros(LargeInteger& v) {
    while (v.size() != 0 && v.back()==0)
        v.pop_back();
}


또한, 두 정수를 곱할 때 두 정수의 자릿수가 서로 큰 차이가 날 수도 있음에 주의할 것.

예) 1000000000000000001 * 111 =111000000000000000111


Input
첫째 줄에 threshold의 값이 주어진다.

둘째 줄에 정수 A가 주어진다.

셋째 줄에 정수 B가 주어진다.


Output
첫째 줄에 prod() 함수의 호출 횟수를 출력한다.

둘째 줄에 A와 B의 곱 C를 출력한다.


Sample Input 1 

1
567832
9423723
Sample Output 1

77
5351091478536
Sample Input 2 

1
111111111111111
111111111111111
Sample Output 2

337
12345679012345654320987654321
Sample Input 3 

2
10000000000000000000000000000000000000000001
111
Sample Output 3

25
1110000000000000000000000000000000000000000111
*/