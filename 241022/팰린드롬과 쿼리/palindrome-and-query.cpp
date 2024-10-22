#include <bits/stdc++.h>
using namespace std;

vector<int> Manachers(string &S){
    int N = S.size();
    string T;
    for(int i = 0; i < N; i++){
        T += "#";
        T += S[i];
    }
    T += "#";
    N = T.size();


    vector<int> A(N);
    A[0] = 0;

    int p = 0;
    int r = p + A[p];

    for(int i = 1; i < N; i++){
        A[i] = 0;

        if(r > i){
            int ii = 2*p - i;
            A[i] = min(r - i, A[ii]);
        }

        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < N
            && T[i - A[i] - 1] == T[i + A[i] + 1]){
            A[i]++;
        }
        
        if(i + A[i] > r){
            p = i;
            r = p + A[p];
        }
    }

    return A;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    
    auto A = Manachers(S);
    
    while(Q--){
        int a, b;
        cin >> a >> b;
        a = 2*a - 1;
        b = 2*b - 1;
        int m = (a+b) >> 1;
        if(m + A[m] >= b) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}