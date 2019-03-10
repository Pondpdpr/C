// https://codeforces.com/contest/1108/problem/F
#include <bits/stdc++.h>
using namespace std;
int n,m,h[200005],now,t1,t2,t3,ans;
struct node{
    int x,y,val;
    bool operator <(node a)const{
        return a.val<val;
    }
}t;
priority_queue<node>pq;
int head(int x){
    if(h[x]==x) return x;
    return h[x]=head(h[x]);
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) h[i]=i;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        pq.push({t1,t2,t3});
    }
    while(!pq.empty())
    {
        t=pq.top(); pq.pop();
        if(head(t.x)!=head(t.y))
        {
            h[head(t.y)]=head(t.x);
            now=t.val;
        }
        else if(now==t.val)
        {
            ans+=1;
            pq.push({t.x,t.y,t.val+1});
        }
    }
    // for(i=1;i<=n;i++) printf("%d ",head(i));
    printf("\n");
    printf("%d",ans);
}