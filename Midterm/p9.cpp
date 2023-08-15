#include <iostream>
#include <vector>
using namespace std;

// DP를 이용한 Catalan 수 구하기
unsigned long long int catalan(unsigned int n)
{
    // Catalan 수열의 항을 저장하기 위한 배열 선언
    vector<unsigned long long int> catalan_num(n + 1);
 
    // 초기값 설정
    catalan_num[0] = 5;
    catalan_num[1] = 25;
 
    // 배열을 이용하여 Catalan 수열의 항들을 계산
    for (int i = 2; i <= n; i++) {
        catalan_num[i] = 0;
        for (int j = 0; j < i; j++) {
            catalan_num[i] += catalan_num[j] * catalan_num[i - j - 1];
        }
        catalan_num[i] = catalan_num[i] % 12345;
    }
 
    // n번째 Catalan 수를 반환
    return catalan_num[n];
}

int main()
{
    int n; cin >> n;
    cout << "Catalan(" << n << ") = " << catalan(n) << endl;
    return 0;
}