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
        while(n>m){
            if(l<0) l++;
            else r--;
            n--;
        }
        cout << l << " " << r << endl;

    }    
    return 0;
}