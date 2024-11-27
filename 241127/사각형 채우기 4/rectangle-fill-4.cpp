#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    vector<int> dp00(N+1), dp01(N+1), dp10(N+1), dp11(N+1);

    dp00[0] = dp01[0] = dp10[0] = dp11[0] = 1;

    int mod = 10007;

    for(int i = 1; i <= N; i++){
        dp00[i] = dp11[i-1];
        dp01[i] = dp10[i-1];
        dp10[i] = dp01[i-1];
        dp11[i] = (dp00[i-1] + dp11[i-1]) % mod;
    }

    cout << dp11[N] << '\n';

    return 0;
}