#include "bits/stdc++.h"
using namespace std;

// Problem :: https://codeforces.com/problemset/problem/1089/E

const int N = 8;
bool vis[N + 5][N + 5];

int main() {
        int n; scanf("%d", &n);


        vector< int > fx = { 0, 0, 1, -1 };
        vector< int > fy = { 1, -1, 0, 0 };

        function< bool( int, int ) > valid =
        [&]( int x, int y ) {
                return x >= 1 && x <= N && y >= 1 && y <= N;
        };

        vector< pair<int, int > > v;
        vis[1][1] = 1;
        function< void(int, int, int) > solve =
        [&]( int x, int y, int take ) {
                //cout<<take<<endl;

                //cout<<x<<" "<<y<<endl;
                if( take > n ) return ;
                if( x == N && y == N  ) {
                        //cout<<take<<endl;
                        if( take == n ) {
                                printf("a1");
                                for(auto it: v){
                                        printf(" %c%d", 'a'+( it.first -1 ) , it.second );
                                }


                                exit(0);
                        }
                        return ;
                }

                for(int i = 0; i < 4; i++) {

                        for(int j = 1;; j++) {
                                int xx = x + j * fx[i];
                                int yy = y + j * fy[i];
                                if(!valid(xx, yy)) break;

                                if(!vis[xx][yy]) {
                                        vis[xx][yy] = 1;
                                        v.push_back({xx, yy});
                                        solve(xx, yy, take + 1);
                                        vis[xx][yy] = 0;
                                        v.pop_back();
                                }


                        }


                }

        };

        solve(1, 1, 0);




        return 0;
}

