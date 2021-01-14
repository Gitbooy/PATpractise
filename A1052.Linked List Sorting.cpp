#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Node{ 
	int address, data, next; //定义在一行
	bool flag; //节点是否在链表上
}node[maxn]; //静态链表实现

bool cmp(Node a, Node b){
	if(a.flag == false || b.flag == false){
		return a.flag > b.flag; //a b中有一个无效节点，就将无效节点放在后面
	}else{
		return a.data < b.data; //如果都是有效节点，就按要求排序
	}
} //cmp ture则后大前小，排序结果正序; false则前大后小，排序结果逆序

int main(){

	int n, first;
	scnaf("%d%d", &n, &first);

	for(int i = 0; i < maxn; i++){ //初始化
		node[i].flag = false;
	} 

	for(int i = 0; i < n; i++){
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next); //直接赋值
		node[address].address = address;
	}

	int temp = first, count = 0;
	while(temp != -1){ //遍历链表，有效节点标记，并计数
		node[temp].flag = true;
		temp = node[temp].next;
		count++;
	}

	if(count == 0){ //特殊情况：链表中没有节点，输出0 -1
		printf("0 -1");
	}else{
		//排序 -- 参数
		sort(node, node + maxn, cmp);
		printf("%d %05d\n", count, node[0].address);
		for(int i = 0; i < count; i++){
			//特殊情况：-1直接输出，不能%05d
			if(i != count - 1){
				printf("%05d %d %05d\n", node[i].address, node[i].data,
					node[i + 1].address);
			}else{
				printf("%05d %d -1\n", node[i].address, node[i].data);
			}
		}
	}
	return 0;
}