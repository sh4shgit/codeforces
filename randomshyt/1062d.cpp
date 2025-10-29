#include <bits/stdc++.h>
using namespace std;

// ------------------------- Fast I/O -------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// ------------------------- Typedefs -------------------------
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;

// ------------------------- Macros ---------------------------
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

// ------------------------- gcd function ---------------------
ll gcdll(ll a, ll b) {
    return b ? gcdll(b, a % b) : a;
}

// ------------------------- Solve Function -------------------
void solve() {
    int n; cin >> n;
    vll a(n);
    for (auto &x : a) cin >> x;
    ll g = a[0];
    for (auto x : a) g = gcdll(g, x);
    if (g == 1) {
        cout << 2 << "\n";
        return;
    }
    vector<ll> primes;
    ll temp = g;
    for (ll p = 2; p * p <= temp; ++p) {
        if (temp % p == 0) {
            primes.push_back(p);
            while (temp % p == 0) temp /= p;
        }
    }
    if (temp > 1) primes.push_back(temp);
    for (ll x = 2; x <= 1e18; ++x) {
        bool ok = true;
        for (ll p : primes) {
            if (x % p == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << x << "\n";
            return;
        }
        if (x > 1e6) break; 
    }
    cout << -1 << "\n";
}

// ---------------------------- Main --------------------------
int main() {
    fast_io;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
