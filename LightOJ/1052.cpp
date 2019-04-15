#include "bits/stdc++.h"
using namespace std;

const int MOD = 1000000007;

struct MatrixExp {

        long long base[2][2], ans[2][2], temp[2][2];
        long long power;

        MatrixExp( long long base[2][2], long long ans[2][2], long long power ) {
                Copy( this->base, base );
                Copy( this->ans, ans );
                this->power = power;
                Power();

        }

        void Mul( long long a[2][2], long long b[2][2] ) {

                temp[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
                temp[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];

                temp[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
                temp[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

                for(int i = 0; i < 2; i++) {
                        for(int j = 0; j < 2; j++) {
                                temp[i][j] %= MOD;
                        }
                }

        }

        void Copy( long long to[2][2], long long from[2][2] ) {
                for(int i = 0; i < 2; i++) {
                        for(int j = 0; j < 2; j++) {
                                from[i][j] %= MOD;
                                to[i][j] = from[i][j];
                        }
                }
        }


        void Power() {

                while( power > 0LL ) {
                        if( power & 1LL ) {
                                Mul( ans, base );
                                Copy( ans, temp );
                        }

                        Mul( base, base );
                        Copy( base, temp );
                        power >>= 1LL;
                }
        }

        long long get_n_th() {
                return ans[0][1];
        }

        long long get_n_plus_one_th() {
                return ans[0][0];
        }

        long long get_n_minus_one_th() {
                return ans[1][1];
        }

};

bool same_sign( long long x, long long y ) {
        return ( x >= 0LL && y >= 0LL ) || ( x < 0LL && y < 0LL );
}

long long zip( long long x ) {
        return x % MOD;
}


int main() {

        int t; scanf("%d", &t);

        long long matrix[2][2] = { {1, 1}, {1, 0} };



        for(int tc = 1; tc <= t; tc++) {

                long long n, N, x, M, k;
                scanf("%lld %lld", &n, &N);
                scanf("%lld %lld", &x, &M);
                scanf("%lld", &k);

                MatrixExp L = MatrixExp(matrix, matrix, n);
                long long x0 = L.get_n_th(), y0 = L.get_n_minus_one_th();

                MatrixExp R = MatrixExp(matrix, matrix, x);
                long long x1 = R.get_n_th(), y1 = R.get_n_minus_one_th();

                long long up = N * y1 - M * y0;
                long long down = x0 * y1 - x1 * y0;

                long long upp = N * x1 - M * x0;
                long long downn = x1 * y0 - x0 * y1;


                printf("Case %d: ", tc);

                if( down == 0LL || downn == 0LL) {
                        puts("Impossible");
                } else {
                        MatrixExp mid = MatrixExp(matrix, matrix, k);
                        long long X = mid.get_n_th(), Y = mid.get_n_minus_one_th();

                        long long one = up / down;
                        long long two = upp / downn;

                        if( one < 0LL || two < 0LL ) {
                                puts("Impossible");
                                continue;
                        }

                        if( up % down || upp % downn ) {
                                puts("Impossible");
                                continue;
                        }

                        long long ans = zip( zip(X) * zip(one) ) + zip( zip(Y) * zip(two) );
                        ans = zip(ans);

                        printf("%lld\n", ans);
                }

        }

        return 0;
}
