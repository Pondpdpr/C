#include <bits/stdc++.h>
using namespace std;

int n,e,sta,en,val[1005];
struct node{
    int x,val;
    bool operator < (node a)const{
        return a.x < x;
    }
};
vector<node>edge[1005];
priority_queue<node>heap;
int main(){
    int i,t1,t2,t3;
    scanf("%d%d%d%d",&n,&e,&sta,&en);
    for(i=0;i<e;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        edge[t1].push_back({t2,t3});
        edge[t2].push_back({t1,t3});
    }
    fill(&val[2],&val[n],1e9);
    heap.push({sta,0});
    while(!heap.empty())
    {
        node t = heap.top();
        heap.pop();
        for(i=0;i<edge[t.x].size();i++)
        {
            val[edge[t.x][i].x]=min(val[edge[t.x][i].x],t.val+edge[t.x][i].val);
            if(t.val+edge[t.x][i].val==val[edge[t.x][i].x]) heap.push({edge[t.x][i].x,val[edge[t.x][i].x]});
        }
    }
    printf("%d",val[en]);
}
/*
5 6
1 2 3
2 4 5
4 5 6
2 3 2
1 3 1
3 5 2
1 5
*/
