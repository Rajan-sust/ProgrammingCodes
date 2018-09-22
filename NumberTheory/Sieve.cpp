const int N = 4000;
bitset<N + 5> mask;
vector<int> prime;

void sieve()
{
    for (int i = 3; i * i <= N; i += 2)
        if (!mask.test(i))
            for (int j = i * i; j <= N; j += (i << 1))
                mask.set(j);

    prime.emplace_back(2);

    for (int i = 3; i <= N; i += 2)
        if (!mask.test(i))
            prime.emplace_back(i);
}
