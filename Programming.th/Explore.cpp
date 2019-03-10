#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[500005],t1,t2,mem[500005],ma;
vector<int>v[500005];
int main(){
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
    }
    for(i=1;i<=k;i++) scanf("%d",&t1),a[t1]=1;
    for(i=1;i<n;i++) if(!a[i]) v[i].push_back(i+1);
    mem[1]=1;
    for(i=1;i<n;i++)
    {
        if(!mem[i]) continue;
        ma=i;
        for(j=0;j<v[i].size();j++) mem[v[i][j]]=1;
    }
    if(mem[n]) printf("1");
    else printf("0 %d",ma);
}
