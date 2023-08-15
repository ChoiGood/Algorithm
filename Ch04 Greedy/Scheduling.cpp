// 데드라인 스케쥴링 문제

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> sequence_of_integer;

bool is_feasible(sequence_of_integer& K, sequence_of_integer& deadline)
{
    for (int i =1; i < K.size(); i++) {
        if (i > deadline[K[i]])
            return false;
    }
    return true;
}

void schedule(int n, sequence_of_integer& deadline, sequence_of_integer& J)
{
    sequence_of_integer K;
    J.clear();
    J.push_back(0); // for an empty job
    J.push_back(1);
    for (int i = 2; i <= n; i++) {
        // K = J with i added according to nondecreasing values of deadlin[i];
        K.resize(J.size());
        copy(J.begin(), J.end(), K.begin());
        int j = 1;
        while(j < K.size() && deadline[K[j]] <= deadline[i]) {
            j++;
        }
        K.insert(K.begin() + j, i);
        if(is_feasible(K,deadline)) {
            // J = K
            J.resize(K.size());
            copy(K.begin(), K.end(), J.begin());
        }
    }
}
void InputSeq(int n, sequence_of_integer& s)
{
    int temp;
    s.push_back(0);
    for(int i=1; i<=n; i++) {
        cin >> temp;
        s.push_back(temp);
    }
}
void OutputJobSeqP(sequence_of_integer& profit, sequence_of_integer& jobseq)
{
    int total=0;
    for (int i=1; i< jobseq.size(); i++) {
        total += profit[jobseq[i]];
    }
    cout << total << endl;

    for (int i=1; i< jobseq.size() - 1; i++) {
        cout << profit[jobseq[i]] << " ";
    }
    cout << profit[jobseq[jobseq.size() - 1]];

}
int main()
{
    int n; cin >> n;
    sequence_of_integer deadline;
    sequence_of_integer profit;
    sequence_of_integer jobseq;

    InputSeq(n,deadline);
    InputSeq(n,profit);

    schedule(n,deadline,jobseq);

    OutputJobSeqP(profit, jobseq);




    return 0;
}

/*
Description
교재와 강의자료를 참고하여 Algorithm 4.4 Scheduling with Deadlines 의 구현을 완성하시오.

입력값은 profit의 내림차순으로 이미 정렬이 되어 있다고 가정해도 된다.

출력은 최대 이익과 함께 feasible sequence의 profit을 순서대로 출력한다.

INPUT
첫째 줄에 job의 개수 n 이 주어진다.
둘째 줄에 n개의 deadline이 주어진다.
셋째 줄에 n개의 profit이 주어진다.
단, profit은 내림차순으로 정렬되어있다.

Output
첫 줄에 최대 이익의 값을 출력한다.
둘째 줄에 Algorithm 4.4가 발견한 job sequence의 순서대로 각 job의 profit을 출력한다.
*/

/*
Sample Input 1 

7
3 1 1 3 1 3 2
40 35 30 25 20 15 10

Sample Output 1

100
35 40 25

-----------------------------------------------
Sample Input 2 

5
2 1 2 1 3
97 27 25 19 13

Sample Output 2

137
27 97 13
*/