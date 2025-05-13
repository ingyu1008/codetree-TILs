#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<int> lis(N), lds(N);

    lis[0] = 1;
    for(int i = 1; i < N; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    lds[N-1] = 1;
    for(int i = N-2; i >= 0; i--)
    {
        lds[i] = 1;
        for (int j = N-1; j > i; j--)
        {
            if (A[j] < A[i])
            {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        ans = max(ans, lis[i] + lds[i] - 1);
    }
    cout << ans << '\n';

    return 0;
}