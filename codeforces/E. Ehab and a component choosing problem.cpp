#include "bits/stdc++.h"
using namespace std;

const int MAX_RANGE = 1e6;
int node_weight[MAX_RANGE];
long long maximum_weight = LONG_MIN;
long long Distance[MAX_RANGE];
vector< int > Graph[MAX_RANGE];
int k;

void dfs( int node, int parent, int flag ) {
        Distance[node] = node_weight[node];

        for(auto adjacent_node : Graph[node]) {
                if( adjacent_node != parent ) {
                        dfs(adjacent_node, node, flag);
                        Distance[node] += max(0LL, Distance[adjacent_node]);
                }
        }
        if(flag) maximum_weight = max( maximum_weight, Distance[node] );
        else if( Distance[node] == maximum_weight ) {
                k++;
                Distance[node] = 0LL;
        }
}




int main() {

        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", node_weight + i);
        for(int i = 1; i < n; i++) {
                int from, to; scanf("%d %d", &from, &to);
                Graph[from].push_back(to);
                Graph[to].push_back(from);
        }
        dfs(1, 0, 1); dfs(1, 0, 0);

        printf("%lld %d\n", 1LL * maximum_weight * k, k );
        return 0;
}
