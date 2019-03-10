#include <bits/stdc++.h>
using namespace std;
struct way{
    int x,val;
};
struct node{
    int x,bit,val;
    bool operator <(node a)const{
        return a.val<val;
    }
}t;
int che1,che2,che3,sx,sval,sbit,dis,n,m,a[11][3],com[11][3],mem[11][2100];
vector<way>v[11];
priority_queue<node>heap;
int main(){
    int i,j;
    scanf("%d",&n);
    scanf("%d%d%d",&a[0][0],&a[0][1],&a[0][2]);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        scanf("%d%d%d",&com[i][0],&com[i][1],&com[i][2]);
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==j) continue;
            dis=(((a[j][0]-a[i][0])*(a[j][0]-a[i][0]))+((a[j][1]-a[i][1])*(a[j][1]-a[i][1]))+((a[j][2]-a[i][2])*(a[j][2]-a[i][2])));
            v[i].push_back({j,dis});
        }
    }
    heap.push({0,1,0});
    fill(&mem[0][0],&mem[10][2099],1e9);
    while(!heap.empty())
    {
        t=heap.top();
        heap.pop();
        mem[t.x][t.bit]=t.val;
        che1=0; che2=0; che3=0;
        for(i=1;i<=m;i++)
        {
            if(t.bit&(1<<i))
            {
                che1+=com[i][0];
                che2+=com[i][1];
                che3+=com[i][2];
            }
        }
//        printf("at %d use %d mee %d %d %d already %d\n",t.x,t.val,che1,che2,che2,t.bit);
        if(che1>=n && che2>=n && che3>=n)
        {
            printf("%d",mem[t.x][t.bit]);
            return 0;
        }
        for(i=0;i<v[t.x].size();i++)
        {
            sx=v[t.x][i].x;
            sval=t.val+v[t.x][i].val;
            sbit=(t.bit|(1<<sx));
            if(sval<mem[sx][sbit]) heap.push({sx,sbit,sval});
        }
    }
}
