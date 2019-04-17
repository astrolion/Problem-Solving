#include "bits/stdc++.h"
using namespace std;

const int N = 1e6;
const int MOD = 1000000007;

int vis[N];
vector< int > primes;

long long zip( long long x ) { return x % MOD; }

long long EXP( long long base, long long power ) {
        long long ret = 1LL;
        long long po = base;
        while(power) {
                if( power & 1LL  )
                        ret = (ret * po) % MOD;
                power /= 2LL;
                po = (po * po) % MOD;
        }
        return ret;
}


int main() {

        for(int i = 2; i < N; i++) {
                if(!vis[i]) {
                        primes.push_back(i);
                        for(int j = i + i; j < N; j += i)
                                vis[j] = 1;
                }
        }

        int t; scanf("%d", &t);

        for(int tc = 1; tc <= t; tc++) {
                int n, m; scanf("%d %d", &n, &m);

                long long ans = 1LL;
                for(int i = 0; i < primes.size(); i++) {
                        if( n == 1LL  ) break;
                        int cnt = 0;
                        while( n % primes[i] == 0 ) {
                                cnt++;
                                n /= primes[i];
                        }
                        if(cnt == 0) continue;

                        long long step = 1LL * cnt * m + 1;

                        long long up = ( EXP( 1LL * primes[i], step ) + MOD - 1LL ) % MOD;
                        long long down = ( EXP( 1LL * primes[i] - 1, 1LL * MOD - 2LL ) ) % MOD;



                        ans = ( zip(ans) * zip( zip( up ) * zip(down) ) ) %MOD;
                }

                if ( n != 1 ) {
                        long long stepo = 1LL * m + 1;
                        long long up = ( EXP( 1LL * n, stepo ) + MOD - 1LL ) % MOD;
                        long long down = EXP( 1LL * n - 1LL, 1LL * MOD - 2 ) % MOD;
                        ans = ( zip(ans) * zip( zip( up ) * zip(down) ) ) %MOD;

                }

                printf("Case %d: %lld\n", tc, ans);

        }




        return 0;
}
