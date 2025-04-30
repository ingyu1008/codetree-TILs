#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<ll> fib;
    fib.push_back(1);
    fib.push_back(1);

    for(int i = 0; i < 45; i++){
        int next = fib[i] + fib[i + 1];
        fib.push_back(next);
    }

    cout << fib[N-1] << "\n";

    return 0;
}