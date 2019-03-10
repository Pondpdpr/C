
// https://programming.in.th/task/rev2_problem.php?pid=1161#include <bits/stdc++.h>
using namespace std;
struct node{
    int y,x,val;
}t;
int t1,t2,sx,sy,n,m,a[105][105][4],mem[105][105];
int cy[]={-1,0,1,0};
int cx[]={0,1,0,-1};
char c1;
queue<node>q;
bool bor(int y,int x){
    if(y>0 && y<=n && x>0 && x<=m) return 1;
    return 0;
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            scanf(" %c",&c1);
            if(c1=='R') a[i][j][1]=1,a[i][j+1][3]=1;
            else if(c1=='D') a[i][j][2]=1,a[i+1][j][0]=1;
            else if(c1=='B') a[i][j][1]=1,a[i][j][2]=1,a[i][j+1][3]=1,a[i+1][j][0]=1;
        }
    q.push({1,1,1});
    mem[1][1]=1;
    while(!q.empty())
    {
        t=q.front();
//        printf("y=%d x=%d val=%d\n",t.y,t.x,t.val);
        q.pop();
        for(i=0;i<4;i++)
        {
            sx=t.x+cx[i];
            sy=t.y+cy[i];
            if(bor(sy,sx) && a[t.y][t.x][i])
            {
                if(t.val+1==mem[sy][sx])
                {
                    printf("%d\n%d %d",t.val+1,sy,sx);
                    return 0;
                }
                if(!mem[sy][sx] || t.val+1>mem[sy][sx]+2)
                {
                mem[sy][sx]=t.val+1;
                q.push({sy,sx,t.val+1});
                }
            }
        }
    }
}
