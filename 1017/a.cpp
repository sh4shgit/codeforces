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
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        string ans = "";
        ans += s[0];
        for(int i = 1 ; i < s.size()-1 ; i++){
            if(s[i-1]==' ') ans += s[i];
        }
        cout << ans << endl; 
    }    
    return 0;
}