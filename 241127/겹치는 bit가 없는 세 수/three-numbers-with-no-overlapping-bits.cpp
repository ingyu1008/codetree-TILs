#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    ll ans = 1e18;

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                if(!(A[i] & A[j]) && !(A[j] & A[k]) && !(A[k] & A[i])){
                    ans = min(ans, 1LL * A[i] + A[j] + A[k]);
                }
            }
        }
    }

    if(ans == 1e18){
        cout << 0 << '\n';
    }else {
        cout << ans << '\n';
    }


    return 0;
}