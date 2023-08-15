#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1000000

int count2 = 0;
int collazlen(long long n)
{
    long long temp = n;
    int count =0;
    while(true)
    {
        count++;
        if (n==1) {
            break;
        }
        else if (n%2==0) {
            n=n/2;
        }
        else {
            n=3*n-1;
        }

        if (n==temp) {
            ::count2++;
            break;
        }

        if(count > MAX) {
            ::count2++;
            break;
        }
    }
    return count-1;
}






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
    int n1,n2; cin >> n1 >> n2;
    int max=-1; int min=9999999;

    int k;
    int temp;
    for (int i=n1;i<=n2;i++) {
        temp = collazlen(i);
        if (temp>max) {
            max = temp;
            k=i;
        }
    }

    cout << k <<" " << max << endl;
    cout << n2 - ::count2;
    //collaz(k,v);
    /*
    for(int i : v)
        cout << i << " ";


    return 0;
    */
}

/*
가장 긴 콜라츠 수열
Description

임의의 양의 정수 N, M에 대하여,

N보다 크거나 같고, M보다 작거나 같은 양의 정수 중에서

콜라츠 수열의 길이가 가장 긴 수 K를 찾아, K의 콜라츠 수열 길이와 해당하는 콜라츠 수열을 출력하시오.

단, 가장 긴 콜라츠 수열의 길이가 같은 수가 여러 개 있으면, 그 중 가장 큰 수를 K로 정한다.


Input
첫째 줄에 양의 정수 N, M이 주어진다. (N <= M)


Output
첫째 줄에 N보다 크거나 같고, M보다 작거나 같은 수 중에서 가장 긴 콜라츠 수열을 가진 수 K와 K의 콜라츠 수열 길이를 출력한다.

둘째 줄에 K의 콜라츠 수열을 출력한다.

단, 콜라츠 수열의 최장 길이가 같은 수가 여러 개 있으면, 그 중 가장 큰 수를 K로 정한다.


Sample Input 1 

1 10
Sample Output 1

9 19
9 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
Sample Input 2 

123 1234
Sample Output 2

1161 181
1161 3484 1742 871 2614 1307 3922 1961 5884 2942 1471 4414 2207 6622 3311 9934
4967 14902 7451 22354 11177 33532 16766 8383 25150 12575 37726 18863 56590 28295 
84886 42443 127330 63665 190996 95498 47749 143248 71624 35812 17906 8953 26860 13430 
6715 20146 10073 30220 15110 7555 22666 11333 34000 17000 8500 4250 2125 6376 3188 1594 
797 2392 1196 598 299 898 449 1348 674 337 1012 506 253 760 380 190 95 286 143 430 215 
646 323 970 485 1456 728 364 182 91 274 137 412 206 103 310 155 466 233 700 350 175 526 
263 790 395 1186 593 1780 890 445 1336 668 334 167 502 251 754 377 1132 566 283 850 425 1276 
638 319 958 479 1438 719 2158 1079 3238 1619 4858 2429 7288 3644 1822 911 2734 1367 4102 2051 
6154 3077 9232 4616 2308 1154 577 1732 866 433 1300 650 325 976 488 244 122 61 184 92 46 23 70
 35 106 53 160 80 40 20 10 5 16 8 4 2 1
*/