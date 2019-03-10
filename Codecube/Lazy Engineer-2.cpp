// https://www.codecube.in.th/task/14
#include <bits/stdc++.h>
using namespace std;
int n,m,mem[1105][3],t1,t2,t3,tx,tval,tnum,tku,ans1=1e9,ans2;
struct node{
    int x,val,num,ku;
    bool operator <(node a)const{
        return a.val<val;
    }
}t;
struct edge{
    int xx,valx,numx;
};
vector<edge>way[1105];
priority_queue<node>pq;
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    fill(&mem[0][0],&mem[1101][2],1e9);
    mem[1][1]=0;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        way[t1].push_back({t2,t3,i});
        way[t2].push_back({t1,t3,i});
    }
    pq.push({1,0,0,1});
    while(!pq.empty())
    {
        t=pq.top(); pq.pop();
        if(t.x==n && t.ku==0 && t.val<=mem[t.x][t.ku] && t.num<ans1)
        {
            ans1=t.num;
            ans2=t.val;
        }
        tku=((t.ku+1)%2);
        for(i=0;i<way[t.x].size();i++)
        {
            tx=way[t.x][i].xx;
            tval=way[t.x][i].valx+t.val;
            tnum=max(way[t.x][i].numx,t.num);
            if(tval<=mem[tx][tku])
            {
                pq.push({tx,tval,tnum,tku});
                mem[tx][tku]=tval;
            }
        }
    }
    printf("%d %d",ans1,ans2);
}