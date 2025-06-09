#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);
    
    int K, N;
    cin >> K >> N;

    vector<int> v;

    function<void(void)> dfs = [&]() {
        if(v.size() == N) {
            for(int i = 0; i < N; i++){
                cout << v[i] << " ";
            }
            cout << "\n";
            return;
        }

        for(int i = 1; i <= K; i++) {
            v.push_back(i);
            dfs();
            v.pop_back();
        }
    };

    dfs();


    return 0;
}
