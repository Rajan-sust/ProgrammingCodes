
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " is " << (x) << '\n'

const int N = 4;
const int mod = 1e9 + 7;

typedef long long ll;

struct matrix {

    int mat[N][N] = { { 0, 1, 1, 1 }, { 1, 0, 1, 1 }, { 1, 1, 0, 1 }, { 1, 1, 1, 0 } };
    matrix() {}

    matrix operator*(const matrix& other)
    {

        matrix res;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                ll sum = 0;
                for (int k = 0; k < N; k++) {
                    sum = (sum + 1ll * mat[i][k] * other.mat[k][j]) % mod;
                }
                res.mat[i][j] = sum;
            }

        return res;
    }

    friend matrix matexp(matrix a, int p)
    {
        if (p == 1)
            return a;
        if (p & 1)
            return a * matexp(a, p - 1);
        matrix dp = matexp(a, p / 2);
        return dp * dp;
    }
};
