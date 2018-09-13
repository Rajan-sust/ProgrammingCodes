
const int N = 100000;
vector<int> u(N + 1, 1), factor(N + 1);

void getMobius()
{

    for (int i = 2; i <= N; i++) {

        if (factor[i] == 0) {

            for (int j = i; j <= N; j += i) {

                int temp = j, cnt = 0;
                while ((temp % i) == 0) {
                    temp /= i;
                    cnt++;
                }
                if (cnt >= 2) {
                    u[j] = 0;
                }
                factor[j]++;
            }
        }
    }

    for (int i = 2; i <= N; i++) {

        if (u[i] == 1)
            u[i] = (factor[i] & 1) ? -1 : 1;
    }

    return;
}
