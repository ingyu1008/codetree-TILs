#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    vector<int> T(N+1);
    vector<vector<int>> E(N+1);
    vector<int> in(N+1);

    vector<int> dp(N+1);

    for(int i = 1; i <= N; i++)
    {
        cin >> T[i];
    
        int M;
        cin >> M;

        for(int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            E[x].push_back(i);
            in[i]++;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 1; i <= N; i++)
    {
        if(in[i] == 0)
        {
            pq.push({T[i], i});
            dp[i] = T[i];
        }
    }

    while(!pq.empty())
    {
        auto [t, u] = pq.top();
        pq.pop();

        for(auto v : E[u])
        {
            dp[v] = max(dp[v], dp[u]);
            if(--in[v] == 0)
            {
                dp[v] += T[v];
                pq.push({dp[v], v});
            }
        }
    }
    
    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}