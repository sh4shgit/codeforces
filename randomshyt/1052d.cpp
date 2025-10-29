#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int l, r;
        cin >> l >> r; // for easy version l == 0
        int n = r - l + 1;
        vector<int> a(n, -1);

        for (int x = r; x >= l; --x) {
            if (a[x - l] != -1) continue;
            int k;
            if (x == 0) k = 1;
            else {
                int p = 31 - __builtin_clz(x); // highest bit position
                k = 1 << (p + 1);              // smallest power of two > x
            }
            int y = (k - 1) - x;
            if (y < l || y > r || a[y - l] != -1) {
                a[x - l] = x; // can't pair, map to itself
            } else {
                a[x - l] = y;
                a[y - l] = x;
            }
        }

        ll sum = 0;
        for (int i = 0; i < n; ++i) sum += ( (l + i) | a[i] );

        cout << sum << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
