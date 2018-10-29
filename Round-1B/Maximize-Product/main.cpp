#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

ll sum(ll l, ll r) {
    l = (l * (l - 1)) >> 1;
    r = (r * (r + 1)) >> 1;
    return r - l;
}

int main() {
    ll t, n, k, ans;
    cin >> t;
    ll mod = 1000000007;
    while (t--) {
        cin >> n >> k;
        if (sum(1, k) > n) {
            cout << -1 << endl;
            continue;
        }
        int i = 1;
        for (; i < n; ++i) {
            if (sum(i, i + k - 1) > n)
                break;
        }
        --i;
        ans = 1;
        ll m = n - sum(i, i + k - 1);
        for (int j = i + k - 1; j >= i; --j) {
            ll cur = j;
            if (m)
                ++cur, --m;
            ll a = cur * cur - cur;
            a %= mod;
            ans *= a;
            ans %= mod;
        }
        cout << ans << endl;
    }
}
