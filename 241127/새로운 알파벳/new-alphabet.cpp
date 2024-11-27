#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<string> words(N+1);
    words[0] = string(1, 'a' - 1);

    vector<bool> occurence(27);

    for (int i = 1; i <= N; i++)
    {
        cin >> words[i];
        words[i] += 'a' - 1;

        for(char c : words[i]){
            occurence[c - 'a' + 1] = true;
        }
    }

    vector<vector<int>> E(27);
    vector<int> indegree(27);
    bool impossible = false;

    for(int i = 0; i < N; i++){
        string &a = words[i];
        string &b = words[i+1];

        int j = 0;
        while(j < a.size() && j < b.size() && a[j] == b[j]){
            j++;
        }

        if(j == b.size()){
            impossible = true;
            break;
        }

        if(j == a.size()){
            continue;
        }

        E[a[j] - 'a' + 1].push_back(b[j] - 'a' + 1);
        indegree[b[j] - 'a' + 1]++;
    }

    if(impossible){
        cout << "-1" << endl;
        return 0;
    }

    queue<int> q;
    string ans;
    for(int i = 0; i < 27; i++){
        if(indegree[i] == 0 && occurence[i]){
            q.push(i);
        }
    }

    if(q.size() > 1){
        cout << "inf\n";
        return 0;
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(q.size() > 0){
            cout << "inf\n";
            return 0;
        }

        if(u > 0)ans += (char)('a' + u - 1);

        for(int v : E[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }

    for(int i = 0; i < 27; i++){
        if(indegree[i] > 0){
            cout << "-1\n";
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}