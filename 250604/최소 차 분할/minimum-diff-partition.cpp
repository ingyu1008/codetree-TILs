#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    vector<bool> possible(100001, false);
    possible[0] = true; // 0 weight is always possible
    cin >> N;

    vector<int> A(N);
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 100000 - A[i]; j >= 0; j--)
        {
            if(possible[j])
            {
                possible[j + A[i]] = true;
            }
        }
    }

    int result = 1e9;
    for(int i = 0; i <= 100000; i++)
    {
        if(possible[i])
        {
            result = min(result, abs(sum - 2 * i));
        }
    }

    cout << result << '\n';

    return 0;
}
