#include <bits/stdc++.h>
using namespace std;

void manachers(std::string& S, std::vector<int>& A)
{
    int size = S.size();
    A.resize(size);
    for (int i = 0, r = 0, p = 0; i < size; i++)
    {
        A[i] = 0;
        if (i <= r) A[i] = std::min(A[2 * p - i], r - i);
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < size && S[i - A[i] - 1] == S[i + A[i] + 1]) A[i]++;
        if (r < i + A[i]) r = i + A[i], p = i;
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::string s, S;
    std::vector<int> p;

    std::cin >> s;

    int len = s.size();
    S.resize(len * 2+1);
    for (int i = 0; i < len; i++)
    {
        S[2 * i] = '#';
        S[2 * i + 1] = s[i];
    }
    S[2 * len] = '#';

    manachers(S, p);

    int res = 0;
    for (int i = 0; i <= 2 * len; i++)
    {
        res = std::max(res, p[i]);
    }

    std::cout << res << "\n";

    return 0;
}