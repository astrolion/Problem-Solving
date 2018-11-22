/***
Problem name : Conquering Keokradong
Algorithm used : Binary Search

***/

#include "bits/stdc++.h"
using namespace std;

const int N = 1005;
int a[N];


int main() {

        int t; scanf("%d", &t);

        for(int tc = 1; tc <= t; tc++) {
                int n, k; scanf("%d %d", &n, &k);

                int st = 0, ed = 1e9;
                for(int i = 0; i <= n; i++) scanf("%d", a + i), st = max( st, a[i] );

                int ans = 0;

                while(st <= ed) {
                        int mid = (st + ed) >> 1;
                        int cnt = 1;
                        int sum = 0;
                        for(int i = 0; i <= n; i++) {
                                if( sum + a[i] > mid ) {
                                        cnt++;
                                        sum = a[i];
                                } else sum += a[i];
                        }

                        if( cnt <= k + 1 ) {
                                ans = mid;
                                ed = mid - 1;
                        } else {
                                st = mid + 1;
                        }

                }

                printf("Case %d: %d\n", tc, ans);

                int sum = 0;


                for(int i = 0; i <= n; i++) {
                        int rem = n - i + 1;
                        sum += a[i];
                        if( sum > ans || rem == k ) {
                                k--;
                                sum -= a[i];
                                printf("%d\n", sum);
                                sum = a[i];
                        }
                }

                printf("%d\n", sum);




        }


        return 0;
}
