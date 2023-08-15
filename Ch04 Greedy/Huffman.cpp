// 허프만 코드와 허프만 알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef struct node *node_ptr;
typedef struct node {
    char symbol;        // the value of a character.
    int frequency;      // the number of times the character is in the file.
    node_ptr left;
    node_ptr right;
} node_t;

struct compare {
    bool operator()(node_ptr p, node_ptr q) {
        return p->frequency > q->frequency;
    }
};

typedef priority_queue<node_ptr, vector<node_ptr>, compare> PriorityQueue;

node_ptr creat_node(char s, int f)
{
    node_ptr node;
    node = (node_ptr) malloc(sizeof(node_t));
    node->symbol = s;
    node->frequency = f;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

void huffman(int n, PriorityQueue& PQ)
{
    for (int i = 1; i <= n-1; i++) {
        node_ptr p = PQ.top(); PQ.pop();
        node_ptr q = PQ.top(); PQ.pop();
        node_ptr r = creat_node('+', p->frequency + q->frequency);
        r->left = p;
        r->right = q;
        PQ.push(r);
    }
}

void make_encoder(node_ptr node, string code, map<char, string> &encoder)
{
    if (node->symbol != '+') { // leaf node
        encoder[node->symbol] = code;
    } else { // internal node
        make_encoder(node->left, code + "0", encoder);
        make_encoder(node->right, code + "1", encoder);
    }
}

void decode(node_ptr root, node_ptr node, string s, int i)
{
    if(i <= s.length()) {
        if(node->symbol != '+') { // leaf node
            cout << node->symbol;
            decode(root, root, s, i); // !!! 루트로 다시 돌아감
        } else {  // internal node
            if (s[i] == '0')
                decode(root, node->left, s, i+1);
            else
                decode(root, node->right, s, i+1);
        }
    }
}

void InputPQ(int n, vector<char> &c, vector<int> &f, PriorityQueue &PQ )
{
    for (int i=1; i<=n; i++) {
        PQ.push(creat_node(c[i],f[i]));
    }
}

void preorder(node_ptr node)
{
    if (node != NULL) {
        printf("%c:%d ", node->symbol, node->frequency);
        preorder(node->left);
        preorder(node->right);
    }
    
}

void inorder(node_ptr node)
{
    if (node != NULL) {
        inorder(node->left);
        printf("%c:%d ", node->symbol, node->frequency);
        inorder(node->right);
    }
    
}


int main()
{
    int n; cin >> n;
    vector<char> c(n+1);
    for(int i=1; i<=n; i++) {
        cin >> c[i];
    }
    vector<int> f(n+1);
    for(int i=1; i<=n; i++) {
        cin >> f[i];
    }

    PriorityQueue PQ;
    InputPQ(n,c,f,PQ);

    huffman(n,PQ);

    node_ptr node = PQ.top();

    preorder(PQ.top()); cout << endl;
    inorder(PQ.top());  cout << endl;

    int n1, n2; string s;
    map<char, string> encoder;
    make_encoder(node, s, encoder);

    cin >> n1;
    for(int i=1; i<=n1; i++) {
        cin >> s;
        for(int j=0; j<s.length();j++) {
            cout << encoder[s[j]];
        }
        cout << endl;
    }

    cin >> n2;
    for(int i=1; i<=n2; i++) {
        cin >> s;
        decode(node,node,s,0);
        cout << endl;
    }

    return 0;
}

/*
허프만 코드와 허프만 알고리즘

Description
교재와 강의자료를 참고하여 허프만 코드 트리를 생성하는 허프만 알고리즘의 구현을 완성하시오.

허프만 트리의 리프노드가 아닌 internal 노드들에는 심볼값으로 '+' 문자를 입력해 두도록 한다.

위 알고리즘을 통해 허프만 트리를 만들었다면, 문자열을 허프만 코드로 인코딩, 디코딩하는 알고리즘을 구현하시오.

INPUT
첫째 줄에 문자의 개수 n이 주어진다.

둘쨰 줄에 n개의 문자가 주어진다. (문자는 알파벳 대문자, 또는 소문자로만 입력된다고 가정한다.)

셋째 줄에 n개의 빈도값이 주어진다. (빈도값은 모두 양의 정수라고 가정한다.)

다음 줄에 문자열의 개수 T1이 주어진다.
이후 T1개의 줄에 한 줄에 하나씩 텍스트 문자열이 주어진다.

다음 줄에 문자열의 개수 T2가 주어진다.
이후 T2개의 줄에 한 줄에 하나씩 허프만 코드 문자열이 주어진다.

OUTPUT
첫째 줄에 허프만 트리의 preorder traversal 결과를 쓴다. (출력 포맷은 아래 출력 사례를 참조한다. 예외적으로 줄끝 공백이 있음에 주의한다.)

둘째 줄에 허프만 트리의 inorder traversal 결과를 쓴다. (출력 포맷은 아래 출력 사례를 참조한다. 예외적으로 줄끝 공백이 있음에 주의한다.)

셋째 줄 이후로 T1개의 문자열을 인코딩한 허프만 코드를 한 줄에 하나씩 출력한다. (줄끝 공백이 없다.)

이후로 T2개의 허프만 코드를 디코딩한 텍스트 문자열을 한 줄에 하나씩 출력한다. (줄끝 공백이 없다.)
*/

/*
Sample Input 1 

6
b e c a d f
5 10 12 16 17 25
5
cab
dec
fad
becadf
fdaceb
5
110001110
011111110
100001
11101111110000110
10010011011111110

Sample Output 1

+:85 +:33 a:16 d:17 +:52 f:25 +:27 c:12 +:15 b:5 e:10 
a:16 +:33 d:17 +:85 f:25 +:52 c:12 +:27 b:5 +:15 e:10 
110001110
011111110
100001
11101111110000110
10010011011111110
cab
dec
fad
becadf
fdaceb

*/