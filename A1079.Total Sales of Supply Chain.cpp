#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

const int MAXN = 100010;

struct node{
	int amount;
	vector<int> child;
}Node[MAXN];

int depth, n;
double sumAmount = 0, p, r;
void DFS(int root, int depth){
	if(Node[root].child.size() == 0)
		//各自的amount不要忘记
		sumAmount += pow(1 + r / 100, depth) * Node[root].amount; 
	//for(int i = 0; i < n; i++){ -- 只需遍历孩子结点
	for(int k = 0; k < Node[root].child.size(); k++){
		DFS(Node[root].child[k], depth + 1);
	}
	//}
}

int main(){

	scanf("%d%lf%lf", &n, &p, &r);

	int childNum, child;
	for(int i = 0; i < n; i++){
		scanf("%d", &childNum);
		//if应该写在外面，不然childNum取0时，根本不会进入循环
		/*for(int i = 0; i < childNum; i++){
			if(childNum == 0){
				scanf("%d", &Node[i].amount);
			}
			else{
				scanf("%d", &child);
				Node[i].child.push_back(child);
			}
		}*/
		if(childNum == 0){
			scanf("%d", &Node[i].amount);
		}else{
			for(int j = 0; j < childNum; j++){
				scanf("%d", &child);
				Node[i].child.push_back(child);
			}
		}
	}

	DFS(0, 0);
	printf("%.1f\n", p * sumAmount); 

	return 0;

}