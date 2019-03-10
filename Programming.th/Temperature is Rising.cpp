// https://programming.in.th/task/rev2_problem.php?pid=1061
#include <bits/stdc++.h>
using namespace std;
int n,sx,sy,tx,ty,a[21][21],ma,mem[21][21];
int cx[]={-1,0,1,0};
int cy[]={0,1,0,-1};
struct axis{
    int x,y;
}t;
queue<axis>q;
int main(){
    int i,j;
    scanf("%d%d%d",&n,&sy,&sx);
    q.push({sx,sy});
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    ma=a[sx][sy];
    mem[sx][sy]=1;
    while(!q.empty())
    {
        t=q.front(); q.pop();
        for(i=0;i<4;i++)
        {
            tx=t.x+cx[i];
            ty=t.y+cy[i];
            if(a[tx][ty]!=100 && a[tx][ty]>a[t.x][t.y] && !mem[tx][ty])
            {
                mem[tx][ty]=1;
                q.push({tx,ty});
                ma=max(ma,a[tx][ty]);
            }
        }
    }
    printf("%d",ma);
}
