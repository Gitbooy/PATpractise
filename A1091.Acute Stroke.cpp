#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int xSize = 1286, ySize = 128, zSize = 60;

struct node{
	int x, y, z;
}node;

int M, N, L, T;
int matric[xSize][ySize][zSize];
int inq[xSize][ySize][zSize] = {false};

int X[6] = {-1, 0, 0, 1, 0, 0};
int Y[6] = {0, 1, -1, 0, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

int BFS(int x, int y, int z, int T){
	queue<node> Q;
	if(matric[x][y][z] == 0) return 0;
	int ans = 1;
	node.x = x, node.y = y, node.z = z;
	Q.push(node);
	inq[x][y][z] = true;
	while(!Q.empty()){
		node top = Q.front();
		Q.pop();
		for(int i = 0; i < 6; i++){
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if(judge(newX, newY, newZ)){
				node.x = newX;
				node.y = newY;
				node.z = newZ;
				Q.push(node);
				inq[newX][newY][newZ] = true;
				ans++;
			}
		}
	}
	if(ans >= T) return ans;
	else return 0;
}
int main(){
	scnaf("%d%d%d%d", &M, &N, &L, &T);
	for(int i = 0; i < L; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < N; k++){
				scanf("%d", &matric[i][j][k]);
			}
			getchar();
		}
	}

	for(int i = 0; i < L; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < N; k++){		
					ans += BFS(i, j, k);
			}
		}
	}
	return ans;
}