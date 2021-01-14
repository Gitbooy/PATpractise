#include<cstdio>
#include<vector>
using namespace std;

int N, K, P, sumMax = -1;
vector<int> temp, ans;

int power(int a, int p){
	int sum = a;
	while((--b) != 0)
		sum *= a;
	return sum;
}

void DFS(int index, int nowK, int nowN, int sum){
	if(nowN == N && nowK == k){
		if(sum => sumMax){
			if... zidian
				ans = temp;
		}
		return;
	}
	if(nowK == k) return;

	temp.push_back(index);
	DFS(index, nowK + 1, nowN + power(index, P), sum + index);
	tmep.pop_back(index);
	DFS(index + 1, nowK, nowN, sum);
}

void main(){

	scanf("%d%d%d", &N, &K, &P);
	DFS(0, 0, 0, 0);
	sort(ans, ans + K, );// 逆排序
	printf("%d=",N);
	for(int i = 0; i < K; i++){
		if(i != K -1)
			printf("%d^%d +", ans[i], P);
		else
			printf("%d^%d\n", ans[i], P);
	}
	return 0;
}


--------------
--------------
//标答
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> temp, ans, fac;
int n, k, p, sumMax = -1;

int power(int x){
	int ans = 1;
	while((p--) != 0){
		ans *= x;
	}
	return ans;
}

void init(){
	int i = 0, temp = 0;
	while(temp <= n){
		fac.push_back(temp);
		temp = power(++i);
	}
}

void DFS(int index, int nowK, int sum, int nowN){
	if(nowN = n && nowK == k){
		if(sum > sumMax){
			ans = temp;
			sumMax = sum;
		}
		return;
	}
	if(sum > n || nowK > K) return;
	if(index - 1 >= 0){
		temp.push_back(index);
		DFS(index, nowK + 1, sum + index, nowN + fac[index]);
		temp.pop_back();
		DFS(index - 1, nowK, sum, nowN);
	}
}

int main(){
	scanf("%d%d%d", &n, &k, &p);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if(sumMax == -1) printf("Impossible\n");
	else{
		for(int i = 0; i < K; i++){
			if(i != K -1)
				printf("%d^%d +", ans[i], P);
			else
				printf("%d^%d\n", ans[i], P);
			}
	}
	return 0;
}