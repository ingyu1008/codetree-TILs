#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<int> v;
    int cnt = 0;

    function<void(void)> dfs = [&]() {
        if(v.size() == N) {
            cnt++;
            return;
        }
        if(v.size() > N) return;

        for(int i = 1; i <= 4; i++) {
            for(int j = 0; j < i; j++) {
                v.push_back(i);
            }
            dfs();

            for(int j = 0; j < i; j++) {
                v.pop_back();
            }
        }
    };

    dfs();

    cout << cnt << '\n';


    return 0;
}
