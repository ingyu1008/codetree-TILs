#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> ans(N+1, 0);

    ans[0] = 1;

    for(int i = 1; i <= N; i++)
    {
        if(i >= 1) ans[i] += ans[i-1];
        if(i >= 2) ans[i] += ans[i-2];
        if(i >= 5) ans[i] += ans[i-5];
        
        ans[i] %= 10007;
    }

    cout << ans[N] << "\n";

    return 0;
}