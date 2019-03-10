// https://www.codecube.in.th/task/62
#include <bits/stdc++.h>
using namespace std;

int n,e,sta,en,val[1005];
struct node{
    int x,val,tim;
    bool operator < (node a)const{
        return a.x < x;
    }
};
vector<node>edge[1005];
priority_queue<node>heap;
int main(){
    int i,t1,t2,t3,t4;
    scanf("%d%d",&n,&e);
    scanf("%d%d",&sta,&en);
    scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
    edge[t1].push_back({t2,t3,t4});
    t4=1e9;
    for(i=0;i<e;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        edge[t1].push_back({t2,t3,t4});
        // edge[t2].push_back({t1,t3,t4});
    }
    fill(&val[1],&val[n],1e9);
    heap.push({sta,0});
    while(!heap.empty())
    {
        node t = heap.top();
        //printf("size = %d\n",heap.size());
        heap.pop();
        for(i=0;i<edge[t.x].size();i++)
        {
            if(t.val<=edge[t.x][i].tim)
            {
                val[edge[t.x][i].x]=min(val[edge[t.x][i].x],t.val+edge[t.x][i].val);
                if(t.val+edge[t.x][i].val==val[edge[t.x][i].x])
                {
                    heap.push({edge[t.x][i].x,val[edge[t.x][i].x]});
                    edge[t.x][i].tim=1e9;
                }
            }
        }
    }
    printf("%d",val[en]);
}
/*
4 4
0 3
1 3 -10 10
0 1 5
0 3 10
1 3 3
2 3 5
*/
