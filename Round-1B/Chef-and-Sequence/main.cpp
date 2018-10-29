#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    long long t, n, k, a[10005]={};
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        cin >> a[i];
        sort(a, a + n);
        reverse(a, a + n);
        long long sq = 0, sum = 0;
        for (int i = 0; i < k; ++i)
            a[i] = 1;
        for (int i = 0; i < n; ++i)
            sum += a[i], sq += a[i] * a[i];
        if (sq <= sum)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
