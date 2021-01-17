#include<cstdio>

const int maxn = 11;

typedef struct node{
	int data;
	int lchild, rchild;
}tree[maxn];

bool isRoot = {true};

int inNum = 0;
void inBFS(int root){
	inBFS(tree[root].lchild);
	printf("%d", root);
	if(inNum != n) printf(" ");
	inNum++;
	inBFS(tree[root].rchild);
}

int levelNum = 0;
void LevelBFS(int root){
	queue<node> Q;
	Q.push(tree[root]);
	while(!Q.empty()){
		node top = Q.top();
		printf("%d", top.data);
		if(levelNum != n) printf(" ");
		levelNum++;
		if(top.lchild != -1) Q.push(tree[top.lchild]);
		if(top.rchild != -1) Q.push(tree[top.rchild]);
	}
}

int main(){
	scanf("%d", &n);
	char lchild, rchild;
	for(int i = 0; i < n; i++){
		scanf("%c", &lchild);
		if(lchild > '9' || lchild < '0') tree[i].rchild = -1;
		else{
			tree[i].rchild = lchild - '0';
			isRoot[tree[i].rchild] = false;
		} 
		scanf("%c", &rchild);
		if(rchild > '9' || rchild < '0') tree[i].lchild = -1;
		else{
			tree[i].lchild = rchild - '0';
			isRoot[tree[i].lchild] = false;
		} 
	}

	int root = -1;
	for(int i = 0; i < n; i++){
		if(isRoot[i]){
			root = i;
			break;
		}
	}

	inBFS(root);
	LevelBFS(root);

	return 0;
}