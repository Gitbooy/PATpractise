#include<cstdio>

const int maxn = 100010;//#定义常量来代替常数

struct Node{
	char c;
	int next;
	int flag;
}node[maxn];

int main(){

	int first1, first2, n;
	scanf("%d%d%d", &first1, &first2, n);

	int address, next;
	char c;
	for(int i = 0; i < n; i++){
		scanf("%d %c %d", &address, &c, &next);
		node[address].c = c;
		node[address].next = next;
		node.flag = 0;
	}

	int temp = first1;
	while(temp != -1){
		node[temp].flag = 1;
		temp = node[temp].next;
	}

	temp = first2;
	while(temp != -1){
		if(node[temp].flag == 1) break;
	}

	if(p != -1){
		printf("%05d\n", p);//#注意题目所给的输出格式
	}else{
		printf("-1\n");
	}

	return 0;
}

