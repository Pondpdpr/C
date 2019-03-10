// https://programming.in.th/task/rev2_problem.php?pid=1031
#include <bits/stdc++.h>
using namespace std;
int n,m,k,mem[10005],t1,t2,ma;
vector<int>v[10005];
int main(){
    int i,j;
    scanf("%d%d%d",&k,&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&t1,&t2);
        v[t2].push_back(t1);
    }
    fill(&mem[0],&mem[10004],-1);
    mem[1]=k;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<v[i].size();j++) mem[i]=max(mem[i],mem[v[i][j]]-1);
        if(mem[i]>=0) ma=i;
    }
    printf("%d",ma);
}
