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
    // your logic here

    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (int &x : heights)
        cin >> x;
    int kthHeight = heights[k - 1];
    int maxHeight = *max_element(heights.begin(), heights.end());
    if (kthHeight == maxHeight) {
        cout << "YES\n";
        return;
    }

    vector<int> uniqueHeights = heights;
    sort(uniqueHeights.begin(), uniqueHeights.end());
    uniqueHeights.erase(unique(uniqueHeights.begin(), uniqueHeights.end()), uniqueHeights.end());
    int position = lower_bound(uniqueHeights.begin(), uniqueHeights.end(), kthHeight) - uniqueHeights.begin();
    bool isValid = true;
    for (int i = position; i + 1 < (int)uniqueHeights.size(); ++i) {
        if (uniqueHeights[i + 1] - uniqueHeights[i] > kthHeight) {
            isValid = false;
            break;
        }
    }
    if (isValid)
        cout << "YES\n";
    else
        cout << "NO\n";
      
}



int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}