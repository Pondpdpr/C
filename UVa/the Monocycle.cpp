#include <bits/stdc++.h>
using namespace std;
int cx[]={1,0,-1,0};
int cy[]={0,-1,0,1};
int n,m,tra[25][25][4][5],ex,ey,s1,s2,amo,t1,ans;
char a[25][25];
struct di{
    int x,y,dir,col;
};
queue<di>q;
bool bor(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m) return 0;
    return 1;
}
int main(){
    int i,j,k,l;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0 && m==0) return 0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                a[i][j]=0;
                for(k=0;k<4;k++)
                    for(l=0;l<5;l++)
                    {
                        tra[i][j][k][l]=0;
                    }
            }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='S') q.push({i,j,3,0});
                if(a[i][j]=='T') ex=i,ey=j;
            }
        while(!q.empty())
        {
            di t=q.front();
            q.pop();
            if(t.x==ex && t.y==ey && t.col==0)
            {
                ans=tra[t.x][t.y][t.dir][t.col];
                t1=1;
                break;
            }
            for(i=0;i<4;i++)
            {
                s1=(t.dir+i)%4;
                    if(i==0 && a[t.x+cx[s1]][t.y+cy[s1]]!='#' && bor(t.x+cx[s1],t.y+cy[s1]) && !tra[t.x+cx[s1]][t.y+cy[s1]][s1][(t.col+1)%5])
                    {
                        tra[t.x+cx[s1]][t.y+cy[s1]][s1][(t.col+1)%5]=tra[t.x][t.y][t.dir][t.col]+1;
                        q.push({t.x+cx[s1],t.y+cy[s1],s1,(t.col+1)%5});
                    }
                    if((i==1 || i==3) && !tra[t.x][t.y][s1][t.col])
                    {
                        tra[t.x][t.y][s1][t.col]=tra[t.x][t.y][t.dir][t.col]+1;
                        q.push({t.x,t.y,s1,t.col});
                    }
            }

        }
        if(t1==0)
        {
            printf("destination not reachable\n");
            continue;
        }
        t1=0;
        while(!q.empty()) q.pop();
        printf("minimum time = %d sec\n",ans+1);
        for(k=0;k<4;k++)
        {
            for(l=0;l<5;l++)
            {
                printf("\ndi = %d\ncol = %d",k+1,l+1);
                for(i=0;i<n;i++)
                {
                    printf("\n");
                    for(j=0;j<m;j++)
                    {
                        printf("%2d(%2d)",tra[i][j][k][l]);
                    }
                }
            }

        }

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
*/
