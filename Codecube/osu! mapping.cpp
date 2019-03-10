// https://www.codecube.in.th/task/185
#include <bits/stdc++.h>
using namespace std;
int n,m,k,t1,t2,s,e,tx,ts;
long long t3,tval,mem[10005][10];
struct node{
    int x;
    long long val;
    int s;
    bool operator <(node a)const{
        return a.val<val;
    }
}t;
priority_queue<node>pq;
vector<node>v[10005];
int main(){
    int i;
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&s,&e);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%lld",&t1,&t2,&t3);
        v[t1].push_back({t2,t3,0});
    }
    pq.push({s,0,1});
    while(!pq.empty())
    {
        t=pq.top(); pq.pop();
        //  printf("at %d with %d have %d\n",t.x,t.val,t.s);
        if(!t.s && t.x==e)
        {
            printf("%lld",t.val);
            return 0;
        }
        ts=(t.s+1)%k;
        for(i=0;i<v[t.x].size();i++)
        {
            tx=v[t.x][i].x;
            tval=t.val+v[t.x][i].val;
            //  printf("go to %d with %d and %d mem = %d\n",tx,tval,ts);
            if(tval<mem[tx][ts] || !mem[tx][ts])
            {
                //  printf("in\n");
                mem[tx][ts]=tval;
                pq.push({tx,tval,ts});
            }
        }
    }
    printf("-1");
}