// https://codeforces.com/contest/1121/problem/A
#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[105],s[105],ma[105],t1,ans;
int main(){
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=n;i++) scanf("%d",&s[i]),ma[s[i]]=max(ma[s[i]],a[i]);
    for(i=0;i<k;i++)
    {
        scanf("%d",&t1);
        if(a[t1]!=ma[s[t1]]) ans++;
    }
    printf("%d",ans);
}