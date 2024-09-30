#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<bool> color(1 << 20);

    while(Q--){
        int cur = 1;
        int dest;
        cin >> dest;

        int x = 1;
        while(x < dest) x <<= 1;
        x >>= 1;

        if(dest & x){
            cur = cur * 2 + 1;
            if(color[cur]){
                cout << cur << "\n";
                continue;
            }
            color[cur] = true;
        } else {
            cur = cur * 2;
            if(color[cur]){
                cout << cur << "\n";
                continue;
            }
            color[cur] = true;
        }

        cout << 0 << "\n";
    }
    return 0;
}
/*
1
10 11
100 101 110
*/