#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,val;
    bool operator <(node a)const{
        return a.val<val;
    }
}t;
int t1,t2,t3,n,m,k,s,e,a[1005],sx,sval,mem[1005];
vector<node>v[1005];
vector<node>way[1005];
priority_queue<node>heap;
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    scanf("%d%d%d",&k,&s,&e);
    for(i=0;i<n;i++)
    {
        fill(&mem[0],&mem[n],1e9);
        heap.push({i,0});
        while(!heap.empty())
        {
            t=heap.top();
            heap.pop();
            if(t.val>=mem[t.x] || t.val>k ) continue;
            mem[t.x]=t.val;
            if(t.x!=i) way[i].push_back({t.x,t.val});
            for(j=0;j<v[t.x].size();j++)
            {
                sx=v[t.x][j].x;
                sval=mem[t.x]+v[t.x][j].val;
                if(sval<mem[sx] && sval<=k) heap.push({sx,sval});
            }
        }
    }
    while(!heap.empty()) heap.pop();
    heap.push({s,0});
    fill(&mem[0],&mem[n],1e9);
    while(!heap.empty())
    {
        t=heap.top();
        heap.pop();
//        printf("at %d\n",t.x);
        if(t.val>mem[t.x]) continue;
        mem[t.x]=t.val;
        if(t.x==e)
        {
            printf("%d",t.val);
            return 0;
        }
        for(i=0;i<way[t.x].size();i++)
        {
            sx=way[t.x][i].x;
            sval=mem[t.x]+way[t.x][i].val*a[t.x];
//            printf("go %d val %d che %d\n",sx,sval,mem[sx]);
            if(mem[t.x]+sval<mem[sx]) heap.push({sx,sval});
        }
    }
    printf("-99");
}
