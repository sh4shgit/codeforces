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
        string t,p;
        cin >> t >> p;
        ll l1 = 0 ,l2 = 0, r1 = 0, r2 = 0;
        int flag = 1;
        while(r1<t.size() && r2<p.size() && flag ==1){
            while(t[r1]==t[r1+1] && r1 < t.size()){
                r1++;
            }
            ll d1 = r1-l1+1;
            while(p[r2]==p[r2+1] && r2 < p.size() && p[l2]==t[l1]){
                r2++;
            }
            ll d2 = r2-l2+1;
            if(d2<d1 || d2>d1*2){
                flag = 0;
                break;
            }
            r1+=1;
            l1=r1;
            r2+=1;
            l2=r2;
        }
        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }    
    return 0;
}