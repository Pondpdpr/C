// https://programming.in.th/task/rev2_problem.php?pid=1031
#include <bits/stdc++.h>
using namespace std;
int n,m,k,mem[10005],t1,t2,ans;
vector<int>v[10005];
int tower(int x,int y){
    if(y==k || v[x].empty())
    {
        ans=max(ans,x);
        return 0;
    }
    mem[x]=y;
    for(int i=0;i<v[x].size();i++)
        if(y+1<mem[v[x][i]]) tower(v[x][i],y+1);

}
int main(){
    int i,j;
    scanf("%d%d%d",&k,&n,&m);
    fill(&mem[2],&mem[10004],1e9);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
    }
    tower(1,0);
    printf("%d",ans);
}
