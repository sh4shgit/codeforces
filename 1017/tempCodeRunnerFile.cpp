#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,m,l,r;
        cin >> n >> m >> l >> r;
        int ln , rn;
        int diff = n - m;
        if(l+diff <= 0){
            cout << l+diff <<' '<< r << endl;
            continue; 
        }
        else{
            cout << 0 <<' ' << r-(l+diff);
            continue;
        }
        if(r-diff <= 0){
            cout << l <<' '<< r-diff << endl;
            continue; 
        }
        else{
            cout << l+(r-diff) <<' ' << 0;
            continue;
        }

    }    
    return 0;
}