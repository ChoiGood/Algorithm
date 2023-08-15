#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> DP;

int solution(int n) {
    int answer = 0;
    int h = 1;
    int b = n;
    int cur; int next;


    while(1)
    {
        cur = b * h;
        if(answer< cur)
            answer = cur;
        
        
        next = (b - h) * (h+1);
        if(b-h <= h+1) { // 불가능 테스트
            break;
        } 

        if (answer < next) {
            answer = next;
        }
        

        b = b - h;
        h = h + 1;
    }


    return answer;
}

int main()
{
    int n; cin >> n;
    cout << solution(n);
}







/*
나무 상자 n 개를 이용해 탑을 쌓아 점수를 받는 게임을 하려고합니다.

탑을 싸ㅗ는 규칙은 아래와 같습니다.

1. 나무 상자 n 를 전부 사용하여 하나의 탑을 만들어야 합니다.

2. 나무 상자 탑은 아래층부터 위 층으로 올라갈수록 사용되는 나무 상자의 수가
최소 1개 이상 적어야 합니다.

예를 들어  n d이 10 일 때는 만들수 있는 탑중 하난느 앙래와 같습니다.
2 3 5
각층의 상자들은 반드시 붙어 있어야합니다

위 뀨칙대로 ㅏㅂ을 쌓으면 (탑의 높이) x (탑의 너비) 만큼의 점수르 얻습니다.

- 탑의 너비는 1층에 상용된 상자의 개수를 의미합니다.

탑을 쌓아 얻을 수 있는 최고 점수를 구하려고 합니다.

나무  상자의 개수를 나타내느 정 ㅅ ㅜ  n 이 매개변수로 주어집니다.
이때 얻을 수 있는 최고 점수를 return 하도록 solution 함수르 완성해주세요.

제한사항   1 < n < 100,000
*/