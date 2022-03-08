#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N,M;
vector<vector<int>> edges;
int d[10002],degin[10002]={0},degout[10002]={0},check[10002]={0};
long long max_path=0;
long long path=0,c=1;
int index[10002];
long long dist[10002];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int u,v;
	d[0]=0;
    cin>>N>>M;
    edges.resize(N+2);
    for (int i=1;i<=N;i++) {
    	cin>>d[i];
	}
    for(int i=0;i<M;i++){
    	cin>>u>>v;
    	degout[u]++;
    	degin[v]++;
    	edges[u].push_back(v);
	}
	for (int i=1;i<=N;i++){
		if (degin[i]==0){
			edges[0].push_back(i);
			degout[0]++;
		}
		if (degout[i]==0){
			edges[i].push_back(N+1);
			degin[N+1]++;
		}
	}
	queue<int> q;
	for (int i=0;i<=N+1;i++)
		if (degin[i]==0) q.push(i);
	int num=0;
	while (!q.empty()){
		u=q.front();
		q.pop();
		index[num++]=u;
		for (int v:edges[u]){
			degin[v]--;
			if (degin[v]==0) q.push(v);
		}
	}
	memset(dist,-1,sizeof(dist));
	dist[0]=0;
	for (int i=0;i<=N+1;i++){
		for (int v: edges[index[i]]){
			if (dist[v]<dist[index[i]]+d[index[i]])
				dist[v]=dist[index[i]]+d[index[i]];
		}
	}
	cout<< dist[N+1];
	return 0;
}