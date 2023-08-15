#include <iostream>
#include <vector>

using namespace std;
#define MAX 100

typedef struct node* node_ptr;
typedef vector<vector<int>> matrix_t;

typedef struct node {
    int key;
    node_ptr left;
    node_ptr right;
}node_t;

void search(node_ptr tree, int keyin, node_ptr& p)
{
    bool found;

    p = tree;
    found = false;
    while(!found) {
        if(p->key == keyin)
            found = true;
        else if (keyin < p->key)
            p = p->left;
        else // keyin > p->key
            p = p->right;
    }
}

int minimum(int i, int j, int &root, vector<int> &p, matrix_t &A)
{
    int min= 99999;
    for(int k=i; k<=j; k++) {
        if (min > A[i][k-1] + A[k+1][j]) {
            min = A[i][k-1] + A[k+1][j];
            root = k;
        }
    }
    for(int m=i; m<=j; m++) {
        min += p[m];
    }
    return min;
}


void optsearchtree(int n, vector<int> &p, matrix_t& A, matrix_t& R)
{
    int k;
    int i, j;
    for (i=1; i<=n; i++) {
        A[i][i-1] =0; A[i][i] =p[i];
        R[i][i-1] = 0; R[i][i] = i;
    }
    A[n+1][n] = R[n+1][n] = 0;

    for(int diagonal = 1; diagonal <= n-1; diagonal++) {
        for(i=1; i<=n-diagonal; i++) {
            j = i+diagonal;
            A[i][j] = minimum(i,j,k,p,A);
            R[i][j] = k;
        }
    }
}


node_ptr create_node(int k)
{
    node_ptr node;
    node = (node_ptr) malloc(sizeof(node_t));
    node->left = NULL;
    node->right = NULL;
    node->key = k;
    return node;
}

node_ptr tree(int i, int j, vector<int>& keys, matrix_t& R)
{
    int k = R[i][j];
    if (k==0)
        return NULL;
    else {
        node_ptr node = create_node(keys[k]);
        node->left = tree(i,k-1,keys, R);
        node->right = tree(k+1,j,keys,R);
        return node;
    }
}

int flag1 = 1;

void preorder(node_ptr node)
{
    if (node != NULL) {
        if(::flag1 == 1) {
            printf("%d",node->key);
            ::flag1=0;
        } else {
            printf(" %d",node->key);
        }
        preorder(node->left);
        preorder(node->right);
    }
    
}
int flag2 = 1;
void inorder(node_ptr node)
{
    if (node != NULL) {
        inorder(node->left);
        if(::flag2 == 1) {
            printf("%d",node->key);
            ::flag2=0;
        } else {
            printf(" %d",node->key);
        }
        inorder(node->right);
        
    }
}

void postorder(node_ptr node)
{
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        if(::flag2 == 1) {
            printf("%d",node->key);
            ::flag2=0;
        } else {
            printf(" %d",node->key);
        }
        
        
    }
}

void Moutput(int n, matrix_t& v)
{
    for(int i=1; i<=n+1;i++) {
        for(int j=i-1; j<n; j++) {
            cout << v[i][j] << " ";
        }
        cout << v[i][n] << endl;
    }
}

void input(int n ,vector<int> &v)
{
    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }
}

int main()
{
    int n; cin >> n;
    vector<int> keys(n+1);
    vector<int> p(n+1);
    matrix_t A(n+2,vector<int> (n+1));
    matrix_t R(n+2,vector<int> (n+1));
    node_ptr root;

    input(n,keys);
    input(n,p);
    optsearchtree(n,p,A,R);
    Moutput(n, A);
    Moutput(n,R);
    cout << A[1][n] << endl;
    root = tree(1,n,keys,R);
    preorder(root);
    
   
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    
    

    return 0;
}

/*
교재와 강의자료를 참고하여 Algorithm 3.9 / 3.10의 구현을 완성하시오.

원소의  개수 n, 키의 값 K, 원소의 탐색 빈도값의 배열 p 가 주어질 때
A, R 행렬의 값을 구해서 출력하고,
R 행렬을 이용하여 구축할 수 있는 이진탐색트리의
preorder, inorder 순회 탐색 결과를 출력하시오.

INPUT
첫째 줄에 key의 개수 n이 주어진다.
둘째 줄에 n 개의 key 값이 주어진다. (key 값은 정렬되어 있다고 가정해도 된다.)
셋째 줄에 n 개의 빈도값 p가 주어진다. (p[i] 값은 양의 정수값으로 주어진다.)

OUTPUT
먼저 행렬의 A의 윗 부분 삼각형을 출력한다. (0을 포함)
다음으로 행렬 R의 윗 부분 삼각형을 출력한다. (0을 포함)
A와 R을 출력한 후에 최적 이진탐색트리에서 평균검색시간의 최적값을 출력한다.
다음 줄에 최적 이진탐색트리의 preorder 순회 탐색 결과를 출력한다.
다음 줄에 최적 이진탐색트리의 inorder 순회 탐색 결과를 출력한다. 
*/

/*
Sample Input 1 

4
10 20 30 40
3 3 1 1
Sample Output 1

0 3 9 11 14
0 3 5 8
0 1 3
0 1
0
0 1 1 2 2
0 2 2 2
0 3 3
0 4
0
14
20 10 30 40
10 20 30 40
Sample Input 2 

6
10 20 30 40 50 60
5 15 5 35 5 35
Sample Output 2

0 5 25 35 95 105 180
0 15 25 80 90 165
0 5 45 55 130
0 35 45 120
0 5 45
0 35
0
0 1 2 2 4 4 4
0 2 2 4 4 4
0 3 4 4 4
0 4 4 4
0 5 6
0 6
0
180
40 20 10 30 60 50
10 20 30 40 50 60
*/


/*
자료 구조 (C언어)
Node Creation 할 때 메모리 할당해야하는 것!!! 잊지 말기 
포인터에 대해 진짜 조금만 더 깨달으면 될 껏 같은데... 
- 내가 부족한 부분 
    문자열 관련된 함수 학습
    메모리 할당 (특히 구조체를 할당할 때 ) : 코드 case 별로 어떤식으로 메모리에서 작동하는지 생각할수 있게 학습
    함수 포인터 라던가 책 뒷 부분 학교에서 못나간 부분 전반적으로 약한듯
*/  