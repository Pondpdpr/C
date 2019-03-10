// https://www.codecube.in.th/task/33
#include <bits/stdc++.h>
using namespace std;
struct node{
    int y,x,che;
}t;
int ans,t1,sx,sy,ex,ey,vc,n,m,che[350][350][4],mem[350][350][4];
int cx[]={0,1,0,-1};
int cy[]={-1,0,1,0};
int lx[]={0,1,1,1};
//int lx[]={0,-1,-1,-1};
int ly[]={-1,-1,0,-1};
//int ly[]={1,1,0,-1};
char in,a[305][305];
bool bor(int y,int x){
    if(y>=0 && y<n && x>=0 && x<m) return 1;
    return 0;
}
int laser(int y,int x,int way){
    int ux,uy;
    for(int i=0;i<4;i++)
    {
        ux=x+lx[(way+i)%4];
        uy=y+ly[(way+i)%4];
        while(che[uy][ux][1]!=-1 && bor(uy,ux))
        {
            che[uy][ux][i]=1;
            ux+=lx[(way+i)%4];
            uy+=ly[(way+i)%4];
        }
        ux=x-lx[(way+i)%4];
        uy=y-ly[(way+i)%4];
        while(che[uy][ux][1]!=-1 && bor(uy,ux))
        {
            che[uy][ux][i]=1;
            ux-=lx[(way+i)%4];
            uy-=ly[(way+i)%4];
        }
    }

}
queue<node>q;
int main(){
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            scanf(" %c",&in);
            if(in=='#')
                for(k=0;k<4;k++)
                    che[i][j][k]=-1;
            if(in=='S')
            {
                sy=i;
                sx=j;
                for(k=0;k<4;k++)
                    che[i][j][k]=-1;
            }
            if(in=='|' || in=='/' || in=='-' || in=='\\')
            {
                q.push({i,j,0});
                for(k=0;k<4;k++)
                    che[i][j][k]=-1;
            }
            if(in=='E')
            {
                ey=i;
                ex=j;
                for(k=0;k<4;k++)
                    che[i][j][k]=-1;
            }
            a[i][j]=in;
        }
    while(!q.empty())
    {
        t=q.front();
        q.pop();
//        printf("t.y=%d t.x=%d cha=%c\n",t.y,t.x,a[t.y][t.x]);
        if(a[t.y][t.x]=='|')
            laser(t.y,t.x,0);
        if(a[t.y][t.x]=='/')
            laser(t.y,t.x,1);
        if(a[t.y][t.x]=='-')
            laser(t.y,t.x,2);
        if(a[t.y][t.x]=='\\')
            laser(t.y,t.x,3);
    }
//    for(k=0;k<4;k++)
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<m;j++) printf("%3d",che[i][j][k]);
//            printf("\n");
//        }
    q.push({sy,sx,0});
    t1=0;
    for(k=0;k<4;k++)
        che[ey][ex][k]=0;
    while(!q.empty())
    {
        if(t.x==ex && t.y==ey)
        {
            ans=t.che;
            t1=1;
            break;
        }
        t=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            sy=t.y+cy[i];
            sx=t.x+cx[i];
            vc=mem[t.y][t.x][t.che%4]+1;
            if(che[sy][sx][vc%4]==0 && !mem[sy][sx][vc%4] && bor(sy,sx))
            {
//                printf("sy=%d sx=%d vc=%d\n",sy,sx,vc);
                mem[sy][sx][vc%4]=vc;
                q.push({sy,sx,vc});
            }
        }
    }
    if(t1) printf("%d",ans);
    else printf("-1");
}
/*
2 3
S-#
.E.
*/
