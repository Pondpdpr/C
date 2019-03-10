// https://www.codecube.in.th/task/189
#include <bits/stdc++.h>
using namespace std;
int n,m,s,e,tx,tval,mem[100005][3],t1,t2,t3,all;
struct edge{
    int x,val;
};
struct node{
    int x,val;
    bool k;
    bool operator <(node a)const{
        return a.val<val;
    }
}t;
vector<edge>v[100005];
priority_queue<node>pq;
int main(){
    int i,j;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    fill(&mem[0][0],&mem[n][2],1e9);
    mem[s][1]=0;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        all+=t3;
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    pq.push({s,0,1});
    while(!pq.empty())
    {
        t=pq.top(); pq.pop();
        for(i=0;i<v[t.x].size();i++)
        {
            tx=v[t.x][i].x;
            if(t.k && t.val<mem[tx][0])mem[tx][0]=t.val,pq.push({tx,t.val,false});
            tval=t.val+v[t.x][i].val;
            if(tval<mem[tx][t.k]) mem[tx][t.k]=tval,pq.push({tx,tval,t.k});
        }
    }
    printf("%d",all-mem[e][0]);
}
