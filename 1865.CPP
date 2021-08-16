#include <iostream>
#include <vector>
#define NUM 501
#define INF 2000000000
#define pii pair<int,int>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	for(int tc=1; tc<=TC; tc++){
		int N,M,W,s,e,t;
		vector<pii> v[NUM];
		int dist[NUM];
		cin >> N >> M >> W;
		for(int i=1; i<=N; i++) v[i].clear();

		while(M--){
			cin >> s >> e >> t;
			v[s].push_back(make_pair(e,t));
			v[e].push_back(make_pair(s,t));
		}
		while(W--){
			cin >> s >> e >> t;
			v[s].push_back(make_pair(e,-t));
		}

		//벨만포드 알고리즘
		bool ans = false;

		//for(int start=1; start<=N; start++){
		int start = 1;
		bool cycle = false;	
		for(int i=1; i<=N; i++) dist[i] = INF;
		dist[start] = 0;

		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				for(int p=0; p<v[j].size(); p++){
					int node = v[j][p].first;
					int val = v[j][p].second;
					if(dist[node] > val + dist[j]){
						dist[node] = dist[j] + val;
						if(i==N) cycle = true;
					}
				}
				if(cycle) break;
			}
			if(cycle) break;
		}
		if(cycle || dist[start] < 0) ans = true;
		//}

		if(ans) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}