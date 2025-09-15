#include <bits/stdc++.h>
using namespace std;

// ------------------------- Fast I/O -------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// ------------------------- Typedefs -------------------------
typedef long long ll;
typedef vector<int> vi;

// ------------------------- Macros ---------------------------
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()

// ------------------------- Constants ------------------------
const int MOD = 998244353;  

// ------------------------- Globals -------------------------
vi a, b;
ll dp[105][2];  
bool vis[105][2];

// ------------------------- Recursive DP ---------------------
ll go(int i, int prev_state, int n) {
    if (i == n) return 1; 
    if (vis[i][prev_state]) return dp[i][prev_state];
    vis[i][prev_state] = true;
    ll ways = 0;
    int prev_a = (i == 0 ? -1 : (prev_state == 0 ? a[i-1] : b[i-1]));
    int prev_b = (i == 0 ? -1 : (prev_state == 0 ? b[i-1] : a[i-1]));
    int curr_a = a[i], curr_b = b[i];
    if ((i == 0) || (curr_a >= prev_a && curr_b >= prev_b)) {
        ways += go(i+1, 0, n);
        if (ways >= MOD) ways %= MOD;
    }
    curr_a = b[i]; curr_b = a[i];
    if ((i == 0) || (curr_a >= prev_a && curr_b >= prev_b)) {
        ways += go(i+1, 1, n);
        if (ways >= MOD) ways -= MOD;
    }

    return dp[i][prev_state] = ways;
}

// ------------------------- Solve Function -------------------
void solve() {
    int n; cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    memset(vis, 0, sizeof(vis));
    cout << go(0, 0, n) % MOD << "\n";
}

int main() {
    fast_io;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
