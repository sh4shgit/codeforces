#include <bits/stdc++.h>
using namespace std;

// ------------------------- Fast I/O -------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// ------------------------- Typedefs -------------------------
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

// ------------------------- Macros ---------------------------
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define per(i,a,b) for (int i = (a); i >= (b); --i)

// ------------------------- Solve Function -------------------

ll ask(int type, int l, int r) {
    cout << type << " " << l << " " << r << endl;
    cout.flush();
    ll res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int low = 1, high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        ll diff = ask(2, 1, mid) - ask(1, 1, mid);
        if (diff >= 1) high = mid;
        else low = mid + 1;
    }
    int l = low;
    low = l; high = n;
    while (low < high) {
        int mid = (low + high + 1) / 2; 
        ll diff = ask(2, mid, n) - ask(1, mid, n);
        if (diff >= 1) low = mid;
        else high = mid - 1;
    }
    int r = low;
    cout << "! " << l << " " << r << endl;
    cout.flush();
}

// ------------------------- Main Function --------------------
int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
