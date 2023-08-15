#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Test(int n)
{
    if (n==1) {
        return 5;
    }
    else if (n>1 && n<=5) {
        return n -1;
    }
    else ;
}

int Test2(int n)
{
    if (n==5) {
        return 1;
    }
    else {
        return n+1;
    }
}

void PrintM(vector<int> v)
{
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> solution(vector<int> c) {
    vector<int> answer;
    
    int n = c.size();
    vector<int> test;
    
    if (Test(c[0]) == c[1]) {
        test.push_back(1);
    }
    else {
        test.push_back(0);
    }

    //PrintM(test);

    for(int i=1; i<n-1; i++)
    {
        if ((Test(c[i]) == c[i+1]) || (Test2(c[i]) == c[i-1])) {
            
            test.push_back(1);
        }
        else{
            test.push_back(0);
        }
    }

    //PrintM(test);

    for (int i=0; i<test.size(); i++)
    {
        if (test[i] == 0) {
            test.push_back(1);
            break;
        }
        if (i==test.size()-1) {
            test.push_back(0);
        }
    }

    int flag = 1;

    for(int i =0; i<test.size(); i++) 
    {
        if (test[i]==0) {
            if(flag) {
                answer.push_back(i+1);
                answer.push_back(c[i]);
                flag = 0;
            }
            else {
                answer.push_back(c[i]);
            }
        }
    }

    return answer;


}

int main()
{
    vector<int> c;
    c.push_back(2);
    c.push_back(1);
    c.push_back(3);
    c.push_back(5);
    c.push_back(4);
    PrintM(c);

    PrintM(solution(c));


}