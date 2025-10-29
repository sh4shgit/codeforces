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
const int N = 2e5 + 5;

// ------------------------- Solve Function -------------------
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool possible = true;
    if (n > 1) {
        if (s[0] == '0' && s[1] == '1') possible = false;
        if (s[n-2] == '1' && s[n-1] == '0') possible = false;
    }
    rep(i,0,n-2) {
        if (s[i]=='1' && s[i+1]=='0' && s[i+2]=='1') {
            possible = false;
            break;
        }
    }
    if (!possible) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vi p(n);
    vi b;
    b.pb(0);
    rep(i,0,n) if (s[i]=='1') b.pb(i+1);
    b.pb(n+1);
    rep(k,0,sz(b)-1) {
        int l = b[k]+1, r = b[k+1]-1;
        if (l > r) continue;
        int val = r;
        rep(i,l,r+1) p[i-1] = val--;
    }
    rep(i,0,n) if (s[i]=='1') p[i] = i+1;
    rep(i,0,n) cout << p[i] << (i==n-1?"\n":" ");
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
