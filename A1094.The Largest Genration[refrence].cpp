#include<cstdio>
#include<vector>
using namespace std;

const int MAXN = 110;
vector<int> Node[MAXN];

int hashTable[MAXN] = {0};

//不创建一个带层数的结构
//直接用层次数组来进行存储和记录
void DFS(int index, int level){
	hashTable[level]++;
	for(int i = 0; i < Node[index].size(); i++){
		DFS(Node[index][i], level + 1);
	}
}

int main(){

	int n, m;
	scanf("%d%d", &n, &m);
	int childNum, child, index;
	for(int i = 0; i < m; i++){
		scanf("%d", &index);//注：不要漏
		scanf("%d", &childNum);
		for(int k = 0; k < childNum; k++){
			scanf("%d", &child);
			Node[index].push_back(child);
		}
	}

	DFS(1, 1);
	int maxLevel = -1, maxValue = 0;
	for(int i = 1; i < MAXN; i++){
		if(hashTable[i] > maxValue){
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}

	printf("%d %d\n", maxValue, maxLevel);
	return 0;
}







