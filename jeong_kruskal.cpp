#include <stdio.h>
#include <algorithm>
using namespace std;

long long int v, e, memo[10100], gum = 0, cnt = 0, memo2[100100];

struct graph{
	int start, end, gil, inx;
};

bool cmpPoint(const graph &v, const graph &s){
	if(v.gil < s.gil){
		return true;
	}
	else{
		return false;
	}
}

int search(int start){
	if(memo[start] == 0){
		return start;
	}
	else{
		return search(memo[start]);
	}
}

int main(){
	int a, b, c;
	struct graph graph[2100];
	printf("정점의 갯수 : ");
	scanf("%d", &v);
	printf("간선의 갯수 : ");
	scanf("%d", &e);
	printf("x y z의 형식으로 입력해주세요(x와 y가 이어진 길이가 z인 간선)\n"); 
	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &a, &b, &c);
		graph[2*i].inx = i;
		graph[2*i+1].inx = i;
		graph[2*i].start = a;
		graph[2*i+1].start = b;
		graph[2*i].end = b;
		graph[2*i+1].end = a;
		graph[2*i].gil = c;
		graph[2*i+1].gil = c;
	}
	sort(graph, graph+e*2, cmpPoint);
	//printf("\n");
	for(int i = 0; cnt < v-1; i++){
		if(memo2[graph[i].inx] == 1){
			continue;
		}
		else if(search(graph[i].end) == graph[i].start || search(graph[i].start) == graph[i].end){
			continue;
		}
		else{
			gum += graph[i].gil;
			cnt++;
			printf("%c와 %c가 연결된 길이가 %d인 간선으로 연결합니다.\n", graph[i].start+64, graph[i].end+64, graph[i].gil);
			if(memo[graph[i].start] != 0){
				memo[graph[i].end] = graph[i].start;
			}
			else{
				memo[graph[i].start] = graph[i].end;
			}
			memo2[graph[i].inx] = 1;
		}
	}
	printf("간선의 총 길이 : %d", gum);
}

