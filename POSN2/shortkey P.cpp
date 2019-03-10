#include <bits/stdc++.h>
using namespace std;
int most,n,m,k,t1,t2,fin,mem[2000005];
vector<int>key[200005];
int main(){
    int i,j;
    scanf("%d%d%d",&n,&k,&m);
    fill(&mem[1],&mem[n+1],1e9);
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&t1,&t2);
        key[t1].push_back(t2);
    }
    for(i=0;i<n;i++)
    {
        if(mem[i]<=m) most=max(most,i);
        for(j=0;j<key[i].size();j++)
        {
            mem[key[i][j]]=min(mem[key[i][j]],mem[i]+1);
        }
        mem[i+1]=min(mem[i+1],mem[i]+1);
    }
    printf("%d\n",mem[n]);
    if(mem[n]<=m) printf("1");
    else printf("0 %d",most);
}
