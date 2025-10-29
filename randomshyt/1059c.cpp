#include <bits/stdc++.h>
using namespace std;

// ------------------------- Fast I/O -------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// ------------------------- Typedefs -------------------------
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

// ------------------------- Macros ---------------------------
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// ------------------------- Solve ----------------------------
void solve() {
    ll a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    ll x = a ^ b;
    if (x <= a) {
        cout << 1 << "\n" << x << "\n";
        return;
    }

    int msb_a = 63 - __builtin_clzll(a); 
    int msb_b = 63 - __builtin_clzll(b); 
    if (msb_b > msb_a) {
        cout << -1 << "\n";
        return;
    }
    ll y = ((1LL << (msb_a + 1)) - 1); 
    ll x1 = y ^ a;                     
    ll a1 = a ^ x1;                    
    ll x2 = a1 ^ b;                    
    cout << 2 << "\n" << x1 << " " << x2 << "\n";
}

// --------------------------- Main ---------------------------
int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
