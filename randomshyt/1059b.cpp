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

bool isNonDecreasing(const string &p) {
    for (int i = 1; i < sz(p); ++i)
        if (p[i] < p[i - 1]) return false;
    return true;
}

bool isPalindrome(const string &x) {
    for (int i = 0, j = sz(x) - 1; i < j; ++i, --j)
        if (x[i] != x[j]) return false;
    return true;
}

void solve() {
    int n; 
    cin >> n;
    string s; 
    cin >> s;
    bool found = false;
    for (int mask = 0; mask < (1 << n); ++mask) {
        string p = "", x = "";
        vi indices;
        rep(i, 0, n) {
            if (mask & (1 << i)) {
                p += s[i];
                indices.pb(i + 1);
            } else {
                x += s[i];
            }
        }
        if (isNonDecreasing(p) && isPalindrome(x)) {
            cout << sz(indices) << "\n";
            if (!indices.empty()) {
                rep(i, 0, sz(indices))
                    cout << indices[i] << (i + 1 == sz(indices) ? '\n' : ' ');
            }
            found = true;
            break;
        }
    }

    if (!found) cout << "-1\n";
}

// --------------------------- Main ---------------------------
int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
