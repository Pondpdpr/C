// https://www.codecube.in.th/task/35
#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[100005][2],t;
long long ma;
vector<int>edge[100005];
vector<int>val[100005];
priority_queue<int>heap;
queue<int>q;
int main(){
    int i,j,t1,t2;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i][0]);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&t1,&t2);
        edge[t1].push_back(t2);
        edge[t2].push_back(t1);
    }
    q.push(k);
    while(!q.empty())
    {
        int u = q.front();
        for(i=0;i<edge[u].size();i++)
        {
            if(a[edge[u][i]][1]==0 && edge[u][i]!=k)
            {
                a[edge[u][i]][1]=a[u][1]+1;
                q.push(edge[u][i]);
                val[a[edge[u][i]][1]].push_back(a[edge[u][i]][0]);
                t=max(t,a[edge[u][i]][1]);
            }
        }
        q.pop();
    }
    for(i=t;i>0;i--)
    {
        for(j=0;j<val[i].size();j++)
        {
            heap.push(val[i][j]);
        }
        if(!heap.empty() && heap.top()>0)
        {
            ma+=heap.top();
            heap.pop();
        }
    }
    for(i=1;i<=n;i++)
    {
        if(a[i][1]==0 && i!=k && a[i][0]>0)ma+=a[i][0];
    }
    printf("%lld",ma);
}
/*
5 5 2
5 8 2 10 7
1 2
2 4
1 3
1 4
4 5
*/
