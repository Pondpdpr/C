// https://www.codecube.in.th/task/35
#include <bits/stdc++.h>
using namespace std;
int n,m,k,mem[100005],a[100005],t1,t2,tx,t,ma;
long long ans;
queue<int>q;
vector<int>fa[100005];
vector<int>v[100005];
priority_queue<int>pq;
int main(){
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    mem[k]=1;
    q.push(k);
    while(!q.empty())
    {
        t=q.front(); q.pop();
        for(i=0;i<v[t].size();i++)
        {
            tx=v[t][i];
            if(!mem[tx])
            {
                mem[tx]=mem[t]+1;
                q.push(tx);
                fa[mem[tx]].push_back(a[tx]);
                ma=max(ma,mem[tx]);
            }
        }
    }
    for(i=ma;i>1;i--)
    {
        for(j=0;j<fa[i].size();j++) pq.push(fa[i][j]);
        if(pq.top()>0) ans+=pq.top(),pq.pop();
    }
    for(i=1;i<=n;i++) if(!mem[i] && a[i]>0) ans+=a[i];
    printf("%lld",ans);
}
