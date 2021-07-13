#include <stdio.h>
#include <algorithm>
using namespace std;

int v, e, memo[10100], gum = 0, cnt[10100], memo2[100100];

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

int count(){
	int s = 0;
	for(int i = 1; i <= v; i++){
		s += memo[i];
	}
	return s;
}

int main(){
	int a, b, c;
	struct graph graph[2100];
	scanf("%d %d", &v, &e);
	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &a, &b, &c);
		cnt[a]++;
		cnt[b]++;
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
	printf("\n");
	for(int i = 0; count() < v; i++){
		if(memo2[graph[i].inx] == 1){
			continue;
		}
		else if(memo[graph[i].start]+memo[graph[i].end] == 2){
			continue;
		}
		else{
			gum += graph[i].gil;
			printf("%d %d %d\n", graph[i].start, graph[i].end, graph[i].gil);
			memo[graph[i].start] = 1;
			memo[graph[i].end] = 1;
			memo2[graph[i].inx] = 1;
		}
	}
	printf("%d", gum);
}

