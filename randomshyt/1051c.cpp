#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll;
typedef vector<int> vi;
#define rep(i,a,b) for (int i=(a); i<(b); ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vi indeg(n+1, 0);

    rep(i, 0, n-1) {
        int u, v;
        ll x, y;
        cin >> u >> v >> x >> y;
        if (x > y) { 
            adj[u].push_back(v);
            indeg[v]++;
        } else if (x < y) { 
            adj[v].push_back(u);
            indeg[u]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> q; 
    rep(i, 1, n+1) if (indeg[i] == 0) q.push(i);
    vi topo;
    while (!q.empty()) {
        int node = q.top(); q.pop();
        topo.push_back(node);
        for (int nxt : adj[node]) {
            if (--indeg[nxt] == 0) q.push(nxt);
        }
    }

    vi p(n+1);
    int val = n;
    for (int node : topo) {
        p[node] = val--;
    }

    rep(i, 1, n+1) cout << p[i] << " ";
    cout << "\n";
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
