#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

const int MAXN = 100010;
vector<int> Node[MAXN];

double p, r;
int n, maxDepth = 0, num = 0;
void find(int root, int depth){
	//通过深度来代替具体的值，减少中间过程的计算
	if(depth > maxDepth){
		maxDepth = depth;
		num = 1;
	}else if(depth == maxDepth){
		num++;
	}

	for(int i = 0; i < Node[root].size(); i++){
		find(Node[root][i], depth + 1);
	}

}

int main(){

	//double 型用lf接收
	scanf("%d%lf%lf", &n, &p, &r);

	r /= 100;//看清题意，是百分数
	int root, k;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(k != -1)
			Node[k].push_back(i);
		else
			root = i;
	}

	find(root, 0);
	//输出格式 + 自带的数学函数pow
	printf("%.2f %d\n", p * pow(1 + r, maxDepth), num);

	return 0;
}	