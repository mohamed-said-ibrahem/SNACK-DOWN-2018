#include <bits/stdc++.h>
#define ll long long

using namespace std;
int t;

int main() {
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m;
        multiset<ll> a, b;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x)
                a.insert(x);
        }
        for (int i = 0; i < m; ++i) {
            cin >> x;
            if (x)
                b.insert(x);
        }
        if (a == b)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    return 0;
}
