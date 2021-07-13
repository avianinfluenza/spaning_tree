#include <stdio.h>
#include <algorithm>
using namespace std;

int v, e, memo[10100], gum = 0, cnt[10100], memo2[100100];

struct graph{
	int start, end, gil, inx;
};

bool cmpPoint(const graph &v, const graph &s){
	if(memo2[v.inx]+memo2[s.inx] == 0){
		if(memo[v.start] + memo[s.start]==2){
			if(memo[v.end] + memo[s.end] == 2){
				return false;
			}
			else if(memo[v.end] + memo[s.end] == 0){
				if(v.gil < s.gil){
					return true;
				}
				else{
					return false;
				}
			}
			else if(memo[v.end] == 0){
				return true;
			}
			else{
				return false;
			}
		}
		else if(memo[v.start] == 1){
			return true;
		}
		else{
			return false;
		}
	}
	else if(memo2[v.inx] == 0){
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
	memo[1] = 1;
	while(count() < v){
		sort(graph, graph+e*2, cmpPoint);
		printf("%d %d %d\n", graph[0].start, graph[0].end, graph[0].gil);
		gum += graph[0].gil;
		memo[graph[0].end] = 1;
		memo2[graph[0].inx] = 1;
	}
	printf("%d", gum);
}
