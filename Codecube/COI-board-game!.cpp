// https://www.codecube.in.th/task/122
#include <bits/stdc++.h>
//J=1 B=2 P=4
using namespace std;
struct axis{
    int x,y,w;
}t;
int cx[]={-1,0,1,0};
int cy[]={0,1,0,-1};
int n,m,ex,ey,sx,sy,mem[505][505][10],tx,ty,tw;
int ad[505][505],che[505][505];
char c;
queue<axis>q;
bool border(int x,int y){
    if(x>=0 && x<n && y>= 0 && y<m) return 1;
    return 0;
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
             scanf(" %c",&c);
             if(c=='.');
             else if(c=='j') ad[i][j]=1;
             else if(c=='b') ad[i][j]=2;
             else if(c=='p') ad[i][j]=4;
             else if(c=='J') che[i][j]=1;
             else if(c=='B') che[i][j]=2;
             else if(c=='P') che[i][j]=4;
             else if(c=='#') che[i][j]=8;
             else if(c=='E') ex=i,ey=j;
             else if(c=='S') sx=i,sy=j;
        }
    q.push({sx,sy,0});
    while(!q.empty())
    {
         t=q.front(); q.pop();
        if(t.x==ex && t.y==ey)
        {
            printf("%d",mem[t.x][t.y][t.w]);
            return 0;;
        }
        for(i=0;i<4;i++)
        {
            tx=t.x+cx[i];
            ty=t.y+cy[i];
            tw=(t.w|ad[tx][ty]);    
            if(border(tx,ty) && (t.w&che[tx][ty])==che[tx][ty] && !mem[tx][ty][tw])
            {
                mem[tx][ty][tw]=mem[t.x][t.y][t.w]+1;
                q.push({tx,ty,tw});
            }
        }
    }
    printf("-1");
}
/*
2 5
S.J.b
.jB.E
*/
