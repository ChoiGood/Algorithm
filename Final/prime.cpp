#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define INF 10000

bool prime(int n) {
    int i; bool flag;
    flag = true;
    i = 2;
    while( flag && i <= (int) floor(sqrt(n)))
        if(n%i == 0)
            flag = false;
        else
            i++;
    return flag;
}

int prime2(int n)
{
    int i;
    int count = 0;

    int k=2;
    while(1)
    {
        int flag = 1;
        for(int i = 2; i<n; i++)
        {
            if(n/i == 0) {
                count++;
                n = n/i;
                int flag = 0;
                break;
            }
        }
        
        if(flag) {
            return count;
        }
        
    }
}


int main()
{

    int c = 0;
    int k;

    for(int i=111; i<=1111; i++) {
        k = prime2(i);
        if(k == 2) c++;

    }
    cout << c;

    return 0;
}

