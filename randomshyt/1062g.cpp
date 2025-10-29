#include <bits/stdc++.h>
using namespace std;

// ------------------------- Fast I/O -------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// ------------------------- Typedefs -------------------------
typedef long long ll;
typedef vector<ll> vll;

// ------------------------- Macros ---------------------------
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

// ------------------------- Solve Function -------------------
void solve() {
    int n; cin >> n;
    vll a(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : c) cin >> x;

    vll dp(n);
    ll total = accumulate(all(c), 0LL);
    ll ans = 0;

    rep(i, 0, n) {
        dp[i] = c[i];
        rep(j, 0, i) {
            if (a[j] <= a[i]) {
                dp[i] = max(dp[i], dp[j] + c[i]);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << total - ans << "\n";
}

// ---------------------------- Main --------------------------
int main() {
    fast_io;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
