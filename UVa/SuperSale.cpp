#include <bits/stdc++.h>
using namespace std;
int Q,mem[1005][35],n,m,ans,t1,t2,t3,w;
pair<int,int>a[1005];
int su(int x,int y){
    if(y==0 || x==n || y<a[x].first) return 0;
    if(!mem[x][y])
    {
        for(int i=x;i<n;i++)
        {
            if(y>=a[i].first) mem[x][y]=max(mem[x][y],su(i+1,y-a[i].first)+a[i].second);
            else 
            {
                break;
            }
        }
    }
    return mem[x][y];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    cin >> Q;
    while(Q--)
    {
        fill(&mem[0][0],&mem[1004][34],0);
        ans=0;
        cin >> n;
        for(i=0;i<n;i++) cin >> a[i].second >> a[i].first;
        sort(a,a+n);
        cin >> m;
        for(i=0;i<m;i++)
        {
            cin >> w;
            ans+=su(0,w);
        }
        for(i=0;i<n;i++) a[i].first=0,a[i].second=0;
        printf("%d\n",ans);
    }
}