#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<vector<int>> E1(N), E2(N);
    vector<int> indeg1(N), indeg2(N);

    for(int i = 0; i+1 < N; i++){
        string s;
        cin >> s;

        if(s == "<"){
            E1[i].push_back(i+1);
            indeg1[i+1]++;
            E2[i].push_back(i+1);
            indeg2[i+1]++;
        }

        if(s == ">"){
            E1[i+1].push_back(i);
            indeg1[i]++;
            E2[i+1].push_back(i);
            indeg2[i]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, less<int>> pq2;

    for(int i = 0; i < N; i++){
        if(indeg1[i] == 0){
            pq1.push(i);
        }
        if(indeg2[i] == 0){
            pq2.push(i);
        }
    }

    vector<int> order1, order2;

    while(!pq1.empty()){
        int u = pq1.top();
        pq1.pop();
        order1.push_back(u);

        for(int v : E1[u]){
            indeg1[v]--;
            if(indeg1[v] == 0){
                pq1.push(v);
            }
        }
    }

    while(!pq2.empty()){
        int u = pq2.top();
        pq2.pop();
        order2.push_back(u);

        for(int v : E2[u]){
            indeg2[v]--;
            if(indeg2[v] == 0){
                pq2.push(v);
            }
        }
    }

    vector<int> ans1(N), ans2(N);

    for(int i = 0; i < N; i++){
        ans1[order1[i]] = i+1;
        ans2[order2[i]] = i+1;
    }

    for(int i = 0; i < N; i++){
        cout << setfill('0') << setw(3) << ans1[i];
    }

    cout << "\n";

    for(int i = 0; i < N; i++){
        cout << setfill('0') << setw(3) << ans2[i];
    }


    return 0;
}