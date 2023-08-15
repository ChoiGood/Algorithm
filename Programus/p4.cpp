#include <iostream>
#include <algorithm>

using namespace std;

int multi(int a, int b)
{
    return a*b;
}

int main()
{
    int n;
    cin >> n;
    int tot=0;
    for(int i=1; i<=n; i++ ) {
        for(int j=1; j<=n; j++ ) {
            for(int k=1; k<=n; k++ ) {
                for(int l=1; l<=n; l++ ) {
                    for(int m=1; m<=n; m++ ) {
                        for(int h=1; h<=n; h++ ) {
                            tot += multi(1,3);
                        }
                    }

                }

            }    
        }    
    }
    cout << tot;
}