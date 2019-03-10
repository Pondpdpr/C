#include <bits/stdc++.h>
using namespace std;
int n,m,t1,t2,tx,amo[200005],d,sta;
bool mem[200005];
struct node{
    int from,x;
}t;
queue<node>q;
vector<int>v[200005];
int main(){
    int i,j;
    scanf("%d%d%d",&n,&m,&d);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
        ++amo[t1];
        ++amo[t2];
    }
    for(i=1;i<=n;i++) if(amo[i]==d) sta=i;
    if(!sta) 
    {
        printf("NO");
        return 0;
    }
    else printf("YES\n");
    q.push({0,sta});
    while(!q.empty())
    {
        t=q.front(); q.pop();
        if(mem[t.x]) continue;
        if(t.from) printf("%d %d\n",t.from,t.x);
        mem[t.x]=true;
        for(i=0;i<v[t.x].size();i++)
        {
            tx=v[t.x][i];
            if(!mem[tx]) q.push({t.x,tx});
        }
    }
}