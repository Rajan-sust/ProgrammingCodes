/*input
5
10 5 5 5
10 6 6 7
10 12 13 14
10 15 15 15
10 19 20 18

*/

/*
https://discuss.codechef.com/questions/120449/areafigr-editorial
*/

#include <bits/stdc++.h>
using namespace std;

#define x() real()
#define y() imag()

#define debug(x) cout << #x << " is " << (x) << '\n'

constexpr double eps = 1e-9;
constexpr int N = 5000000;

typedef complex<double> pt;
inline double cross(const pt& a, const pt& b) { return (conj(a) * b).y(); }

inline pt reflect(const pt& a, const pt& b, const pt& p) { return a + conj((p - a) / (b - a)) * (b - a); }

inline bool point_in_circle(const pt& c, double r, const pt& p)
{
    double dx = c.x() - p.x(), dy = c.y() - p.y();
    return (dx * dx + dy * dy) <= (r * r + eps);
}

int main(int argc, char const* argv[])
{

    ios::sync_with_stdio(false);

    int test;
    cin >> test;

    while (test--) {
        double a, r1, r2, r3;
        cin >> a >> r1 >> r2 >> r3;

        pt A((a * -1.0), 0.0), B(a, 0.0), C(0.0, sqrt(3.0) * a);

        pt c1 = (A + B) / 2.0, c2 = (B + C) / 2.0, c3 = (A + C) / 2.0;

        pt v1 = C - A, v2 = B - A;

        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        mt19937 rng(seed);

        int cnt = 0;

        for (int i = 1; i <= N; i++) {
            double k1 = rng() / (1.0 * rng.max()), k2 = rng() / (1.0 * rng.max());

            pt x = k1 * v1 + k2 * v2 + A;

            if (cross(C - B, x - B) < 0.0) {
                x = reflect(B, C, x);
            }

            if (point_in_circle(c1, r1, x) and point_in_circle(c2, r2, x) and point_in_circle(c3, r3, x)) {
                cnt++;
            }
        }

        double area = sqrt(3) * (a * a);

        area = (area * cnt) / (N * 1.0);

        cout << fixed << setprecision(5) << area << "\n";
    }

    return 0;
}
