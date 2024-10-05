#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> par(N+1);
    vector<int> indegree(N+1);
    vector<int> tree(N+1);


    for(int i = 2; i <= N; i++){
        int t, a, p;
        cin >> t >> a >> p;
        if(t == 0) a = -a;

        tree[i] = a;
        par[i] = p;
        indegree[p]++;
    }

    stack<int> st;
    for(int i = 1; i <= N; i++) if (indegree[i] == 0) st.push(i);

    while(!st.empty()){
        int cur = st.top();
        st.pop();

        if(tree[cur] > 0){
            tree[par[cur]] += tree[cur];
        }

        indegree[par[cur]]--;
        if(indegree[par[cur]] == 0) st.push(par[cur]);
    }

    cout << tree[1] <<  "\n";

    return 0;
}