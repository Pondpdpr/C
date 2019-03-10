// https://www.codecube.in.th/task/66
#include <bits/stdc++.h>
using namespace std;
struct node{
    int y,x;
}t;
int cy[]={-1,0,1,0};
int cx[]={0,1,0,-1};
int sx,sy,n,m,a[1005][1005],mem[1005][1005],ans;
queue<node>q;
bool bor(int y,int x){
    if(y>=0 && y<n && x>=0 && x<m) return 1;
    return 0;
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    ans=n*m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0) q.push({i,j}),ans--;
        }
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            sy=t.y+cy[i];
            sx=t.x+cx[i];
            if(!mem[sy][sx] && bor(sy,sx))
                if(mem[t.y][t.x]+1<a[sy][sx])
                {
                    mem[sy][sx]=mem[t.y][t.x]+1;
                    ans--;
                    q.push({sy,sx});
                }
        }
    }
    printf("%d",ans);
}
