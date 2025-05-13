#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int>> lines(N);

    for (int i = 0; i < N; i++)
    {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines.begin(), lines.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });

    vector<int> dp(N, 1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (lines[i].first > lines[j].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLines = 0;
    for (int i = 0; i < N; i++)
    {
        maxLines = max(maxLines, dp[i]);
    }

    cout << maxLines << "\n";


    return 0;
}