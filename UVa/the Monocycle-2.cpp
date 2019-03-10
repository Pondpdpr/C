#include <bits/stdc++.h>
using namespace std;
int cy[]={-1,0,1,0};
int cx[]={0,1,0,-1};
int n,m,tra[30][30][5][6],ex,ey,s1,t1,ans,T;
char a[30][30];
struct to{
    int y,x,di,col;
}t;
queue<to>q;
bool bor(int y,int x){
    if(y>=0 && x>=0 && y<n && x<m) return 1;
    return 0;
}
int main(){
    freopen("in-Monocycle.txt","r",stdin);
    freopen("out-Monocycle.txt","w",stdout);
    int i,j,k,l;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(!n) return 0;
        if(T && n)printf("\n");
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='S') q.push({i,j,0,0});
                if(a[i][j]=='T') ey=i,ex=j;
            }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                for(k=0;k<4;k++)
                    for(l=0;l<5;l++)
                        tra[i][j][k][l]=0;

        while(!q.empty())
        {
            t=q.front();
            q.pop();
            if(t.x==ex && t.y==ey && t.col==0)
            {
                ans=tra[t.y][t.x][t.di][t.col];
                t1=1;
                break;
            }
            if(a[t.y+cy[t.di]][t.x+cx[t.di]]!='#' && bor(t.y+cy[t.di],t.x+cx[t.di]) && !tra[t.y+cy[t.di]][t.x+cx[t.di]][t.di][(t.col+1)%5])
            {
                tra[t.y+cy[t.di]][t.x+cx[t.di]][t.di][(t.col+1)%5]=tra[t.y][t.x][t.di][t.col]+1;
                q.push({t.y+cy[t.di],t.x+cx[t.di],t.di,(t.col+1)%5});
            }
            s1=(t.di+1)%4;
            if(!tra[t.y][t.x][s1][t.col])
            {
                tra[t.y][t.x][s1][t.col]=tra[t.y][t.x][t.di][t.col]+1;
                q.push({t.y,t.x,s1,t.col});
            }
            s1=(t.di+3)%4;
            if(!tra[t.y][t.x][s1][t.col])
            {
                tra[t.y][t.x][s1][t.col]=tra[t.y][t.x][t.di][t.col]+1;
                q.push({t.y,t.x,s1,t.col});
            }
        }
        printf("Case #%d\n",++T);
        if(t1==0)
        {
            printf("destination not reachable\n");
            continue;
        }
        t1=0;
        while(!q.empty()) q.pop();
//        for(i=0;i<4;i++) ans=min(ans,tra[ey][ex][i][0]);
        printf("minimum time = %d sec\n",ans);
    }
}
