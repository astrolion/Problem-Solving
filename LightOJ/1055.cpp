#include "bits/stdc++.h"
using namespace std;

const int N = 11;
char s[N][N];
int n;
map< pair<int, int >, int > mp;
int vis[N][N][N][N][N][N], dist[N][N][N][N][N][N];
int fx[] = { 1, -1, 0, 0 };
int fy[] = { 0, 0, 1, -1 };

struct node {
        pair<int, int > A, B, C;
};

bool valid( pair<int, int > x ) {
        return x.first >= 0 && x.first < n && x.second >= 0 && x.second < n && s[x.first][x.second] != '#';
}


int bfs( node st ) {

        vis [ st.A.first ][ st.A.second ][ st.B.first ][ st.B.second ][ st.C.first ][ st.C.second ] = 1;
        dist[ st.A.first ][ st.A.second ][ st.B.first ][ st.B.second ][ st.C.first ][ st.C.second ] = 0;

        queue<node> q;
        q.push(st);

        while(!q.empty()) {
                node top = q.front(); q.pop();

                if( mp[top.A] && mp[top.B] && mp[top.C] && top.A != top.B && top.B != top.C && top.A != top.C ) {
                        return dist[ top.A.first ][ top.A.second ][ top.B.first ][ top.B.second ][ top.C.first ][ top.C.second ];
                }

                for(int i = 0; i < 4; i++) {
                        pair<int, int > a = top.A, b = top.B, c = top.C;

                        if( valid( make_pair( top.A.first + fx[i], top.A.second + fy[i] ) ) ) {
                                a = make_pair( top.A.first + fx[i], top.A.second + fy[i] );
                        }

                        if( valid( make_pair( top.B.first + fx[i], top.B.second + fy[i] ) ) ) {
                                b = make_pair( top.B.first + fx[i], top.B.second + fy[i] );
                        }

                        if( valid( make_pair( top.C.first + fx[i], top.C.second + fy[i] ) ) ) {
                                c = make_pair( top.C.first + fx[i], top.C.second + fy[i] );
                        }

                        if( a == b ) {
                                if( b == c ) {
                                        c = top.C;
                                }
                                a = top.A, b = top.B;
                        }

                        if( a == c ) {
                                if( a == b ) b = top.B;
                                a = top.A;
                                c = top.C;
                        }

                        if( b == c ) {
                                if( a == b ) a = top.A;
                                b = top.B;
                                c = top.C;
                        }

                        node v;
                        v.A = a, v.B = b, v.C = c;
                        if( vis[ v.A.first ][ v.A.second ][ v.B.first ][ v.B.second ][ v.C.first ][ v.C.second ] == 0 ) {
                                vis[ v.A.first ][ v.A.second ][ v.B.first ][ v.B.second ][ v.C.first ][ v.C.second ] = 1;
                                dist[ v.A.first ][ v.A.second ][ v.B.first ][ v.B.second ][ v.C.first ][ v.C.second ] = 1 +
                                                dist[ top.A.first ][ top.A.second ][ top.B.first ][ top.B.second ][ top.C.first ][ top.C.second ];

                                q.push(v);
                        }


                }

        }
        return -1;
}



int main() {

        int t; scanf("%d", &t);

        for(int tc = 1; tc <= t; tc++) {
                scanf("%d", &n);

                memset( vis, 0, sizeof vis );
                memset( dist, 0, sizeof dist );
                mp.clear();


                node nd;

                for(int i = 0; i < n; i++) {
                        scanf("%s", s[i]);
                        for(int j = 0; j < n; j++) {
                                if( s[i][j] == 'X' )
                                        mp[ make_pair(i, j) ] = 1;
                                if( s[i][j] == 'A' )
                                        nd.A = make_pair(i, j);
                                if( s[i][j] == 'B' )
                                        nd.B = make_pair(i, j);
                                if( s[i][j] == 'C' )
                                        nd.C = make_pair(i, j);
                        }
                }

                int ans = bfs(nd);

                printf("Case %d: ", tc);
                if(ans == -1)
                        puts("trapped");
                else
                        printf("%d\n", ans);

        }


        return 0;
}
