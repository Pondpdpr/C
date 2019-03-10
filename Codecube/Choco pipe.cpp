// https://www.codecube.in.th/task/99
#include <bits/stdc++.h>
using namespace std;
int n,m,co[3],ct,a[105][105],mem[105][105][5],tcost;
int tx,ty;
int cx[]={-1,0,1,0};
int cy[]={0,1,0,-1};
char c;
struct axis{
    int x,y,di,cost;
    bool operator <(axis a)const{
        return a.cost<cost;
    }
}t;
priority_queue<axis>pq;
bool border(int x,int y){
    if(x==n-1 && y==m) return 1;
    if(x<n && x>=0 && y<m && y>=0) return 1;
    return 0;
}
int main(){
    int i,j;
    scanf("%d%d%d",&co[0],&co[1],&ct);
    scanf("%d%d",&m,&n);
    for(i=n-1;i>=0;i--)
        for(j=0;j<m;j++)
        {
            scanf(" %c",&c);
            mem[i][j][0]=1e9;
            mem[i][j][1]=1e9;
            mem[i][j][2]=1e9;
            mem[i][j][3]=1e9;
            if(c=='X') a[i][j]=ct;
        }
    mem[0][0][1]=0;
    mem[n-1][m][1]=1e9;
    pq.push({0,0,1,0});
    while(!pq.empty())
    {
        t=pq.top(); pq.pop();
        for(i=0;i<4;i++)
        {
            if(i==2) continue;
            tx=t.x+cx[(t.di+i)%4];
            ty=t.y+cy[(t.di+i)%4];
            tcost=(t.cost+co[i%2]+a[tx][ty]);
            if(border(tx,ty) && tcost<mem[tx][ty][(t.di+i)%4])
            {
                mem[tx][ty][(t.di+i)%4]=tcost;
                pq.push({tx,ty,(t.di+i)%4,tcost});
            }
        }
    }
    printf("%d",mem[n-1][m][1]+a[0][0]);
 }
