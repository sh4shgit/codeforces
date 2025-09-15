#include <bits/stdc++.h>
using namespace std;

// ------------------------- Fast I/O -------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// ------------------------- Typedefs -------------------------
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// ------------------------- Macros ---------------------------
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

// ------------------------- Solve Function -------------------
void solve() {
    int n, m;
    cin >> n >> m;
    vpii req(n);
    rep(i, 0, n) cin >> req[i].ff >> req[i].ss;

    int cur_side = 0;   
    int prev_time = 0;  
    ll ans = 0;

    auto process = [&](int gap, int target_side) {
        int need = (cur_side == target_side ? 0 : 1);
        if (gap < need) return; 
        int runs = (gap % 2 == need % 2 ? gap : gap - 1);
        ans += runs;
        if (runs % 2) cur_side ^= 1;
        cur_side = target_side; 
    };

    for (auto &x : req) {
        int gap = x.ff - prev_time;
        process(gap, x.ss);
        prev_time = x.ff;
    }
    ans += (m - prev_time);

    cout << ans << "\n";
}

// ------------------------- Main ----------------------------
int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
