#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);

    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    function<void(int, int, int)> transform = [&] (int l, int r, int midx){
        int mval = B[midx];
        for(int i = l; i <= r; i++){
            if(A[i] == mval){
                cout << mval << " ";
                transform(l, i-1, midx - (r - (i+1) + 1) - 1);
                transform(i+1, r, midx - 1);
                break;
            }
        } 
    };

    transform(0, N-1, N-1);
    
    return 0;
}