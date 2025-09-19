#include <bits/stdc++.h>
using namespace std;

// ------------------------- Fast I/O -------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// ------------------------- Typedefs -------------------------
typedef long long ll;
typedef vector<ll> vll;

// ------------------------- Macros ---------------------------
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()

// ------------------------- Solve Function -------------------
void solve() {
    int n, k;
    cin >> n >> k;
    vll a(n);
    rep(i, 0, n) cin >> a[i];
    vll b(k);
    rep(i, 0, k) cin >> b[i];

    sort(a.rbegin(), a.rend()); // descending prices
    sort(all(b));               // ascending vouchers

    // prefix sum of a[]
    vll prefix(n + 1, 0);
    rep(i, 0, n) prefix[i + 1] = prefix[i] + a[i];

    ll totalCost = 0;
    int idx = 0; // current index in a[]

    rep(i, 0, k) {
        int x = b[i];
        if (idx >= n) break; // no items left

        int takeCount = min(x - 1, n - idx); // how many we actually pay for
        // sum for [idx, idx+takeCount)
        totalCost += prefix[idx + takeCount] - prefix[idx];
        idx += takeCount;

        // skip free item
        if (idx < n) idx++;
    }

    // pay for remaining items if any
    if (idx < n) totalCost += prefix[n] - prefix[idx];

    cout << totalCost << "\n";
}

// ------------------------- Main ----------------------------
int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
