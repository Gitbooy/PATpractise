#include<cstdio>
#include<vector>
using namespace std;

const int MAXN = 110;

struct node{
	int level;
	vector<int> child;
}Node[MAXN];

void pre(int root){
	for(int i = 0; i < Node[root].child.size(); i++){
		Node[Node[root].child[i]].level = Node[root].level + 1;
		pre(Node[root].child[i]);
	}
}

int n, m, maxLevel, ans, members = 0;
int levelNum[MAXN] = {0}; //记录每层结点数
void levelOrder(int root){
	for(int i = 0; i < n; i++){
		if(Node[i].level > maxLevel)
			maxLevel = Node[i].level;
		levelNum[Node[i].level]++;
	}
	for(int i = 0; i < maxLevel; i++){
		if(levelNum[i + 1] > members){
			ans = i + 1;
			members = levelNum[i + 1];
		}
	}

}

int main(){

	scanf("%d%d", &n, &m);
	int childNum, child, index;
	for(int i = 0; i < m; i++){
		scanf("%d", &index);//
		scanf("%d", &childNum);
		for(int k = 0; k < childNum; k++){
			scanf("%d", &child);
			Node[index].child.push_back(child);
		}
	}

	Node[1].level = 1;
	pre(1);

	levelOrder(1);
	printf("%d %d\n", members, ans);

	return 0;
}
