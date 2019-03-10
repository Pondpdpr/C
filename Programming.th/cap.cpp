// https://programming.in.th/task/rev2_problem.php?pid=1111
#include <bits/stdc++.h>
using namespace std;
int n,t1,t2,t3,tx,tval,mem[100005],ma;
struct node{
    int x,val;
    bool operator < (node a)const{
        return a.val<val;
    }
}t;
priority_queue<node>pq;
vector<node>v[100005];
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    pq.push({1,0});
    fill(&mem[2],&mem[n+1],1e9);
    while(!pq.empty())
    {
        t=pq.top(); pq.pop();
        for(i=0;i<v[t.x].size();i++)
        {
            mem[v[t.x][i].x]=min(mem[v[t.x][i].x],t.val+v[t.x][i].val);
            if(t.val+v[t.x][i].val==mem[v[t.x][i].x]) pq.push({v[t.x][i].x,mem[v[t.x][i].x]});
        }
    }
    for(i=1;i<=n;i++) ma=max(ma,mem[i]);
    printf("%d",ma);
}
