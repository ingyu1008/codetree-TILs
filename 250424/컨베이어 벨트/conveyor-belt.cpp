#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N, T;
    cin >> N >> T;

    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    for (int i = 0; i < N; i++){
        cin >> B[i];
    }

    while(T--){
        int poppedA = A.back();
        A.pop_back();
        int poppedB = B.back();
        B.pop_back();

        A.insert(A.begin(), poppedB);
        B.insert(B.begin(), poppedA);
    }

    for (int i = 0; i < N; i++){
        cout << A[i] << " ";
    }

    cout << "\n";

    for (int i = 0; i < N; i++){
        cout << B[i] << " ";
    }
    cout << "\n";


    return 0;
}