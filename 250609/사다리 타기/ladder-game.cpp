#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].second >> edges[i].first;
        
        edges[i].first--; // Convert to 0-based index
        edges[i].second--; // Convert to 0-based index
    }

    sort(edges.begin(), edges.end());

    vector<int> original(N);
    iota(original.begin(), original.end(), 0); // Fill with 0, 1, ..., N-1

    for(int i = 0; i < M; ++i) {
        swap(original[edges[i].first], original[edges[i].second]);
    }

    int ans = M;

    for(int i = 0; i < (1 << M); i++){
        vector<int> result(N);
        iota(result.begin(), result.end(), 0); // Fill with 0, 1, ..., N-1

        for(int j = 0; j < M; j++){
            if(i & (1 << j)) {
                swap(result[edges[j].first], result[edges[j].second]);
            }
        }

        bool isValid = true;
        for(int j = 0; j < N; j++) {
            if(result[j] != original[j]) {
                isValid = false;
                break;
            }
        }

        if(isValid) {
            ans = min(ans, __builtin_popcount(i));
        }
    }

    cout << M-ans << endl;

    return 0;
}
