#include "bits/stdc++.h"
using namespace std;


int main() {

        int t; scanf("%d", &t);

        for(int tc = 1; tc <= t; tc++) {
                int n, m, k; scanf("%d %d %d", &n, &m, &k);

                const int N = n + 1;
                vector < pair<int, int > > g[N];
                vector< int > vis(N, 0);

                while(m--) {
                        int from, to, cost;
                        scanf("%d %d %d", &from, &to, &cost);

                        g[from].push_back( make_pair(to, cost) );
                        g[to].push_back( make_pair(from, cost) );
                }

                long long tot = 0LL;
                int ports = 0;

                for(int node = 1; node < N; node++) {
                        if( vis[node] ) continue;
                        ports++;
                        int sum = 0;
                        set< pair<int, int > > s;
                        s.insert(make_pair(0, node));
                        //vis[node] = 1;

                        while( !s.empty() ) {
                                set< pair<int, int > > ::iterator it = s.begin();
                                pair<int, int > top = *it;
                                s.erase(it);
                                if(!vis[top.second])
                                        sum += top.first;
                                //cout << top.second << " " << top.first << endl;
                                vis[ top.second ] = 1;


                                for(int i = 0; i < g[top.second].size(); i++ ) {
                                        int v = g[top.second][i].first;
                                        int cost = g[top.second][i].second;
                                        if(vis[v]) continue;
                                        if( cost < k ) {
                                                //vis[v] = 1;
                                                s.insert( make_pair( cost, v ) );
                                        }
                                }
                        }
                        tot += sum + k;
                }

                printf("Case %d: %lld %d\n", tc, tot, ports);




        }

        return 0;
}
