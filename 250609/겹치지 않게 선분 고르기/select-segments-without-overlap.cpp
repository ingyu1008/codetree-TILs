#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<pair<int, int>> lines(N);
    for (int i = 0; i < N; ++i) {
        cin >> lines[i].first >> lines[i].second;
    }

    int ans = 0;
    for(int i = 0; i < (1 << N); i++){
        bool intersect = false;
        for(int x = 0; x < N; x++){
            if (!(i & (1 << x))){
                continue;
            }

            for(int y = x + 1; y < N; y++){
                if (!(i & (1 << y))){
                    continue;
                }

                // Check if lines x and y intersect
                int st1 = lines[x].first;
                int en1 = lines[x].second;
                int st2 = lines[y].first;
                int en2 = lines[y].second;

                if((en1 < st2) || (en2 < st1)) continue;

                intersect = true;
                break;
            }
        }

        if (!intersect) {
            ans = max(ans, __builtin_popcount(i));
        }
    }

    cout << ans << '\n';

    return 0;
}
