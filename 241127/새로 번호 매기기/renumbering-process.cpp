#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> E(N);
    vector<int> in(N);

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;

        E[b].push_back(a);
        in[a]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < N; i++)
        if(in[i] == 0)
            pq.push(i);
        
    vector<int> order;
    while(!pq.empty())
    {
        int u = pq.top();
        pq.pop();

        order.push_back(u);

        for(int v : E[u])
        {
            in[v]--;
            if(in[v] == 0)
                pq.push(v);
        }
    }

    if(order.size() != N)
    {
        cout << "-1\n";
        return 0;
    }

    vector<int> ans(N);

    for(int i = 0; i < N; i++)
        ans[order[i]] = N - i;

    for(int i = 0; i < N; i++)
        cout << ans[i] << " ";

    return 0;
}