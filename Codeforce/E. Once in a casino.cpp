#include <bits/stdc++.h>
using namespace std;
int n,a[100005],che[100005],track[100005],t1,t2,t3=100000,t4;
long long ans;
char c;
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int i,j;
    cin >> n;
    for(i=0;i<n;i++) cin >> c,a[i]=c-'0';
    for(i=0;i<n;i++) cin >> c,che[i]=c-'0';
    t1=che[0]-a[0];
    a[1]+=t1;
    ans+=(t1<0)?(-t1):t1;
    track[0]=t1;
    for(i=1;i<n-1;i++)
    {
        t1=che[i]-a[i];
        a[i+1]+=t1;
        ans+=abs(t1);
        t4=(che[i])-(a[i]%10);
        if(abs(t4)<=5) track[i]=t4;
        else
        {
            if(t4<0) t4+=10;
            else t4-=10;
            track[i]=t4;
        }
    }
    if(a[n-1]!=che[n-1])
    {
        cout << -1;
        return 0;
    }
    cout << ans << endl;
    for(i=n-2;i>=0 && t2<t3;i--)
    {
        if(track[i])
        {
            if(track[i]<0) t1=-1,track[i]*=-1;
            else t1=1;
            for(j=0;j<track[i] && t2<t3;j++) cout << i+1 << " " << t1 << endl,t2++;
        }
    }
}
