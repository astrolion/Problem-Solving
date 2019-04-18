#include "bits/stdc++.h"
using namespace std;

const int N = 1005;

int Count( vector< vector<int> >&pos, int val, int st, int ed ) {
        vector<int>::iterator down = lower_bound( pos[val].begin(), pos[val].end(), st );
        vector<int>::iterator up = upper_bound( pos[val].begin(), pos[val].end(), ed );
        return up - down;
}

int main() {

        int t; scanf("%d", &t);

        for(int tc = 1; tc <= t; tc++) {
                vector< vector< int > > g(N);
                int n, q; scanf("%d %d", &n, &q);

                for(int i = 0; i < n; i++) {
                        int x; scanf("%d", &x);
                        g[x].push_back(i);
                }

                printf("Case %d:\n",tc);


                while(q--) {
                        int x, y; scanf("%d %d", &x, &y);

                        int ans = N;
                        int pre = 0;

                        for(int i = 1; i < N; i++) {
                                int cnt = Count(g, i, x, y);

                                if( cnt > 1 ) {
                                        ans = 0;
                                        break;
                                }
                                if(cnt > 0 && pre > 0 ) {
                                        ans = min( ans, i - pre );
                                }
                                if(cnt > 0) {
                                        pre = i;
                                }

                        }

                        printf("%d\n", ans);


                }


        }


        return 0;
}
