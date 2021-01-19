#include<cstdio>
#include<vector>
using namespace std;

const int MAXN = 101; //大写

struct node{
	int weight;
	vector<int> child;
}Node[MAXN];

int n, m, w, ansNum = 0;
vector<int> ans[];
vector<int> temp;
void BFS(int index, int wSum){
	wSum += Node[index].weight;
	if(wSum > w) return;
	temp.push_back(Node[index].weight);
	if(wSum == w)
		ans[ansNum++] = temp;
	for(int i = 0; i < Node[index].child.size(); i++){
		BFS(Node[index].child[i], wSum);
		//temp.pop_back(Node[index].child[i].weight);
	}
	temp.pop_back(Node[index].weight);
}


int main(){

	scanf("%d%d%d", &n, &m, &w);
	for(int i = 0; i < n; i++){
		scanf("%d", &Node[i].weight);
	}

	int index, childNum;
	for(int i = 0; i < m; i++){
		scnaf("%d%d", &index, &childNum);
		for(int k = 0; k < childNum; k++){
			scnaf("%d", &Node[index].child[k]);
		}
	}


	return 0;
}


//下为算法笔记参考代码
#include<cstdio>
#include<vertor>
#include<algorithm>
using namespace std;

const int MAXN = 110;
struct node{
	int weight;
	vector<int> child;
}Node[MAXN];

bool cmp(int a, int b){
	return Node[a].weight > Node[b].weight;//大到小排序 -- 大于倒序，小于顺序
}

int n, m, w;//节点数，非叶节点数，给定和
int path[MAXN];//记录路径

//nodeNum为当前路径path上的结点个数
void DFS(int index, int nodeNum, int sum){
	if(sum > w) return;
	if(sum == w){
		//注意情况：仍是非叶结点，返回 
		if(Node[index].child.size() != 0) return;
		//直接进行输出
		for(int i = 0; i < nodeNum; i++){
			printf("%d", Node[p[i]].weight);
			if(i < nodeNum - 1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for(int i = 0; i < Node[index].chile.size(); i++){
		int child = Node[index].child[i];
		path[nodeNum] = child;
		DFS(child, nodeNum + 1, sum + Node[child].weight);
	}
}

int main(){

	scanf("%d%d%d", &n, &m, &w);
	for(int i = 0; i < n; i++){
		scanf("%d", &Node[i].weight);
	}

	int index, childNum, child;
	for(int i = 0; i < m; i++){
		scnaf("%d%d", &index, &childNum);
		for(int k = 0; k < childNum; k++){
			//scnaf("%d", &Node[index].child[k]);
			scanf("%d", &child);
			Node[index].child.push_back(child);
		}
		//孩子结点按权值进行排序，避免了后续的排序
		sort(Node[index].child.begin(), Node[index].child.end(), cmp);
	}

	path[0] = 0;// 路径第一个结点设置为0号
	DFS(0, 1, Node[0].weight);
	return 0;
}
