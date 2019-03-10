#include <bits/stdc++.h>
using namespace std;
int Q,n,m,ans,t1,t2;
unordered_map<int,int>mp1;
unordered_map<int,int>mp2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    cin >> Q;
    while(Q--)
    {
        cin >> n >> m;
        ans=n;
        for(i=0;i<n;i++) cin >> t1,mp1[t1]++;
        for(i=0;i<m;i++)
        {
            cin >> t1;
            if(mp2[t1]<mp1[t1]) ans--;
            else ans++;
            mp2[t1]++;
        }
        cout << ans << endl;
        mp1.clear();
        mp2.clear();
    }
}
