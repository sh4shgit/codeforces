#include <bits/stdc++.h>
using namespace std;

// ------------------------- Fast I/O -------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// ------------------------- Typedefs -------------------------
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// ------------------------- Macros ---------------------------
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define per(i,a,b) for (int i = (a); i > (b); --i)

// ------------------------ Debugging -------------------------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << '\n';
#else
#define debug(x)
#endif

template<typename T> void _print(T x) { cerr << x; }
template<typename T1, typename T2> void _print(pair<T1,T2> p) {
    cerr << '{'; _print(p.ff); cerr << ", "; _print(p.ss); cerr << '}';
}
template<typename T> void _print(vector<T> v) {
    cerr << '['; for (T i : v) { _print(i); cerr << ' '; } cerr << ']';
}

// ------------------------- Constants ------------------------
const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;  // or 998244353

// ------------------------- Solve Function -------------------
void solve() {
    int n; cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    vi prefix(n + 1, 0);
    rep(i,1,n+1) prefix[i] = prefix[i - 1] + a[i - 1];

    bool found = false;
    for (int l = 0; l <= n - 3 && !found; l++) {      
        for (int r = l + 1; r <= n - 2; r++) {        
            int s1 = prefix[l + 1] % 3;
            int s2 = (prefix[r + 1] - prefix[l + 1]) % 3;
            int s3 = (prefix[n] - prefix[r + 1]) % 3;

            if ((s1 == s2 && s2 == s3) ||
                (s1 != s2 && s1 != s3 && s2 != s3)) {
                cout << l + 1 << " " << r + 1 << "\n";
                found = true;
                break;
            }
        }
    }
    if (!found) cout << "0 0\n";
}

int main() {
    fast_io;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
