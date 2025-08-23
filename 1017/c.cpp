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
    
    while(t--) {
        int n;
        cin >> n;
        
        int arr[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        
        int ans[2*n+1] = {0};
        int check[2*n+1] = {0};
        
        for(int j = 0; j < n; j++) {
            ans[j+1] = arr[0][j];
            check[ans[j+1]] = 1;
        }
        
        for(int i = 1; i < n; i++) {
            ans[i+n] = arr[i][n-1];
            check[ans[i+n]] = 1;
        }
        
        for(int i = 1; i < 2*n+1; i++) {
            if(check[i] == 0) {
                ans[0] = i;
                break;
            }
        }
        
        //ll out = 0;
        for(int i = 0; i < 2*n; i++) {
           cout << ans[i]<<" ";
        }
        
        cout << endl;
    }
    
    return 0;
}