#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int Q;
    cin >> Q;

    int S = 0;

    while (Q--)
    {
        string op;
        cin >> op;

        if(op == "clear") S = 0;

        int x;
        cin >> x;

        if(op == "add") S |= (1 << x);
        if(op == "delete") S &= ~(1 << x);
        if(op == "print"){
            if(S & (1 << x)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        if(op == "toggle") S ^= (1 << x);
    }



    return 0;
}