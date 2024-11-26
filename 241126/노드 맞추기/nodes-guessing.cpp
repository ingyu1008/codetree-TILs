#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    map<string, int> names;
    map<int, string> inames;
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        names[name] = i;
        inames[i] = name;
    }

    int M;
    cin >> M;

    vector<vector<int>> E(N);
    vector<int> indegree(N);

    for (int i = 0; i < M; i++)
    {
        string a, b;
        cin >> a >> b;
        
        int u = names[a], v = names[b];

        E[v].push_back(u);
        indegree[u]++;
    }

    vector<int> roots;
    vector<vector<int>> children(N);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0){
            pq.push(i);
            roots.push_back(i);
        }
    }

    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();

        for (int v : E[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                pq.push(v);
                children[u].push_back(v);
            }
        }
    }

    cout << roots.size() << '\n';

    for (auto it = roots.begin(); it != roots.end(); it++)
    {
        int root = *it;
        if(it != roots.begin()){
            cout << ' ';
        }
        cout << inames[root];
    }
    cout << '\n';
    
    for(auto &[name, idx]: names){
        sort(children[idx].begin(), children[idx].end(), [&](int a, int b){
            return inames[a] < inames[b];
        });
        cout << name << ' ' << children[idx].size() << ' ';
        for(int child: children[idx]){
            cout << inames[child] << ' ';
        }
        cout << '\n';
    }

    

    return 0;
}