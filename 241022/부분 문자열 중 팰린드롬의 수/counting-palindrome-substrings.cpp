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
    string S;
    cin >> S;
    
    auto A = Manachers(S);

    long long ans = 0;
    for(int i = 0; i < A.size(); i++){
        int len = 2*A[i] + 1;
        len >>= 1;
        
        ans += (len + 1)/2;
    }

    cout << ans <<"\n";

    return 0;
}