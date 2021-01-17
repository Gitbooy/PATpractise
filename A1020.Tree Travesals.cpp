#include<cstdio>
#include<queue>
using namespace std;

const int maxn = 31;
int post[maxn];
int in[maxn];

typedef struct node{
	int data;
	node *lchild, *rchild;
}node;

node *create(int postL, int postR, int inL, int inR){

	if(postL > postR) return NULL;

	node *root = new node;
	int k;
	for(k = inL; k <= inR; k--){
		if(post[posrR] == in[k]) break;
	}

	int numLeft = k - inL;

	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);

	return root;

}

int main(){

	scanf("%d", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &post[i]);
	}
	for(int i = 0: i < n; i++){
		scanf("%d", &in[i]);
	}

	int a[n], k = 0;

	node *root = create(0, n - 1, 0, n - 1); //序列终值为n - 1，注意
	queue<node> Q;
	Q.push(root);
	while(!Q.empty()){
		node *top = Q.front();
		Q.pop();
		a[k++] = top->data;
		if(top->lchild != NULL) Q.push(Q->lchild);
		if(top->rchild != NULL) Q.push(Q->rchild);
	}

	for(int i = 0; i < n; i++){
		if(i == n - 1)
			printf("%d", a[i]);
		else
			printf("%d ", a[i]);
	}

	return 0;
}


/*
优化写法

int num = 0; //已输出结点的个数
while(!Q.empty()){
	node *top = Q.front();
	Q.pop();
	printf("%d", top->data);
	num++;
	if(num < n) printf(" ");
	if(now->lchild != NULL) Q.push(top->lchild);
	if(noe->rchild != NULL) Q.push(top->rchild);
}

*/