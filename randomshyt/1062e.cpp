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
        int n,k,x; cin >> n >> k >> x;
        int tempx = x;
        vector<int> arr(n);
        for(int& x : arr){
            cin >> x;
        }
        sort(all(arr));
        int maxdist = 0;
        int maxind = 0;
        vector<pii> index;
        for(int i = 1 ; i<n ; i++){
            int l = arr[i-1];
            int r = arr[i];
            int dist = (r - l)/ 2;
            int ind  = dist + l;
            index.pb({dist,ind});
            if(dist > maxdist) {
                maxdist = dist;
                maxind = dist + l;
            }
        }

        // if(maxdist < tempx - arr[n-1]){
        //     maxind  = tempx;
        // }
        // if(maxdist < arr[0] - 0){
        //     maxind  = 0;
        // }
        vector<int> ans;
        // ans.push_back(maxind);
        // k--;
        
        // for(int i = 0; i <= x && k > 0; i++){
        //     if(i == maxind) continue;
    
        //     ans.push_back(i);
        //     k--;
        // }
        sort(all(index), greater<>());
        for(auto it : index){
            auto[d,in] = it;
            if(k <= 0) break;
            ans.pb(in);
            k--;
        }
        for (int x : ans) cout << x << " ";
        cout << "\n";
        
    }

    int main() {
        fast_io;
        int t = 1;
        cin >> t;
        while (t--) solve();
        return 0;
    }