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
    int n , k; cin >> n >> k;
    int arr[n];
    rep(i,0,n){
        cin >> arr[i];
    }
    int minv = INF;
    int mul = 0; 
    switch (k) {
        case 2:
            rep(i,0,n){
                minv = min(minv,arr[i]%2); 
            }
            cout << minv << endl;
            break;
        case 3:
        rep(i,0,n){
            if(arr[i]%3==0){
                cout << 0 << endl;
                return;
                break;
            }
            else{
                mul = (arr[i]/3) + 1;
                minv = min(minv,(3*mul)-arr[i]);
            }
        }
        cout << minv << endl;
        break;
        
        case 4:
            if(n==1){
                cout << arr[0]%4 << endl;
                return;
                break;
            }
            else{
                int even = 0;
                int flag = 0;
                rep(i,0,n){
                    if(arr[i]%2==0){
                        even++;
                    }
                    if(even == 2){
                        cout<<0<<endl;
                        return;
                        break;
                    }
                    if(arr[i]%4==0){
                        cout<<0<<endl;
                        return;
                        break;
                    }
                    if((arr[i]+1)%4==0){
                        flag = 1;
                    }
                }
                if(flag){
                    cout << 1 << endl;
                    return;
                    break;
                }
                else{
                    cout << max(0,(2-even)) << endl;
                    return;
                    break;
                }
                break;
            }
        case 5:
            rep(i,0,n){
                if(arr[i]%5==0){
                    cout << 0 << endl;
                    return;
                    break;
                }
                else{
                    mul = (arr[i]/5) + 1;
                    minv = min(minv,(5*mul)-arr[i]);
                }
            }
            cout << minv << endl;
            break;

    }
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}