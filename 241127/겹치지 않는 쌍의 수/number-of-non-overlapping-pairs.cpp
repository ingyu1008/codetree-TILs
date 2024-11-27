#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    vector<int> A(N);

    for(int i = 0; i < N; i++)
    {
        int cnt;
        cin >> cnt;

        for(int j = 0; j < cnt; j++)
        {
            int x;
            cin >> x;
            A[i] |= 1 << (x-1);
        }
    }

    int cnt = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if((A[i] & A[j]) == 0)
            {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}