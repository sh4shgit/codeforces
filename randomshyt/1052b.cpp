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
    int n, m;
    cin >> n >> m;
    vector<vi> sets(n);
    vi count(m + 1, 0);     
    rep(i, 0, n) {
        int li;
        cin >> li;
        sets[i].resize(li);
        rep(j, 0, li) {
            cin >> sets[i][j];
            count[sets[i][j]]++;
        }
    }
    rep(x, 1, m + 1) {
        if (count[x] == 0) {
            cout << "NO\n";
            return;
        }
    }
    vector<bool> forced(n, false);
    rep(i, 0, n) {
        for (int x : sets[i]) {
            if (count[x] == 1) {
                forced[i] = true;
                break;
            }
        }
    }
    int optional = 0;
    rep(i, 0, n) {
        if (!forced[i]) optional++;
    }
    if (optional >= 2) cout << "YES\n";
    else cout << "NO\n";
}

// ------------------------- Main Function --------------------
int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
