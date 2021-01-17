#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

const int maxn = 31;
int in[maxn], pre[maxn];
int n; //结点个数

typedef struct node{
	int data;
	node *lchild, *rchild;
}node;

node *create(int preL, int preR, int inL, int inR){

	if(preL > preR) return NULL;
	node *root = new node;
	root->data = pre[preL];

	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] = pre[preL]) break;
	}

	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);

	return root;
}

void BFS(node *root, int count){
	if(root == NULL) return;
	BFS(root->lchild);
	BFS(root->rchild);
	printf("%d", root->data);
	if(count != n) printf(" ");
	count++;
}

int main(){

	scanf("%d", &n);
	char str[5]; //char数组来读取
	stack<int> st;

	for(int i = 0; i < n; i++)
		pre[i] = i + 1;

	int x, preIndex = 0, inIndex = 0;//入栈元素及先序中序序列位置
	for(int i = 0; i < 2 * n; i++){
		scanf("%s", str);
		if(strcmp(str, "Push") == 0){ //第一次匹配位置为0
			scanf("%d", &x);
			pre[preIndex++] = x;
			st.push(x);
		}else{
			in[inIndex++] = st.top();
			st.pop();
		}
	}

	node *root = create(0, n - 1, 0, n - 1);
	BFS(root, 1);

	return 0;

}

