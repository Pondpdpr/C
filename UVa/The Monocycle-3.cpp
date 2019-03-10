#include <bits/stdc++.h>
using namespace std;
int n,m,j,Q,t1,t2,mem[26][26][5][6];
int cx[]={-1,0,1,0};
int cy[]={0,1,0,-1};
int tx,ty,ex,ey;
char c;
bool a[26][26];
struct axis{
    int x,y,di,col;
}t;
queue<axis>q;
bool border(int x,int y){
    if(a[x][y] && x>=0 && x<n && y>=0 && y<m) return 1;
    return 0;
}
int main(){
    int i,j;
//    freopen("out-monocycle","w",stdout);
    while(++Q)
    {
        scanf("%d%d",&n,&m);
        if(!n)
        {
            return 0;
        }
        memset(mem,0,sizeof(mem));
        memset(a,false,sizeof(a));
        while(!q.empty()) q.pop();
        t1=1;
        if(Q>1) printf("\n");
        printf("Case #%d\n",Q);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                scanf(" %c",&c);
                if(c=='.') a[i][j]=true;
                else if(c=='S') q.push({i,j,0,0}),a[i][j]=true;
                else if(c=='T') ex=i,ey=j,a[i][j]=true;
            }
        while(!q.empty())
        {
            t=q.front(); q.pop();
            if(t.x==ex && t.y==ey && !t.col)
            {
                printf("minimum time = %d sec\n",mem[t.x][t.y][t.di][t.col]);
                t1=0;
                break;
            }
//            printf("\nat %d %d di %d color %d",t.x,t.y,t.di,t.col);
            tx=t.x+cx[t.di];
            ty=t.y+cy[t.di];
            if(border(tx,ty) && !mem[tx][ty][t.di][(t.col+1)%5])
            {
                mem[tx][ty][t.di][(t.col+1)%5]=mem[t.x][t.y][t.di][t.col]+1;
                q.push({tx,ty,t.di,(t.col+1)%5});
            }
            if(!mem[t.x][t.y][(t.di+1)%4][t.col])
            {
                mem[t.x][t.y][(t.di+1)%4][t.col]=mem[t.x][t.y][t.di][t.col]+1;
                q.push({t.x,t.y,(t.di+1)%4,t.col});
            }
            if(!mem[t.x][t.y][(t.di+3)%4][t.col])
            {
                mem[t.x][t.y][(t.di+3)%4][t.col]=mem[t.x][t.y][t.di][t.col]+1;
                q.push({t.x,t.y,(t.di+3)%4,t.col});
            }
        }
        if(t1) printf("destination not reachable\n");
    }
}
/*
1 3
S#T
10 10
#S.......#
#..#.##.##
#.##.##.##
.#....##.#
##.##..#.#
#..#.##...
#......##.
..##.##...
#.###...#.
#.....###T
0 0

*/
