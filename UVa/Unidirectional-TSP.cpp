#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][105],mem[15][105],track[15][105],mi,si;
int ts(int x,int y){
    // printf("at %d %d \n",x,y);
    if(y>=m) return 0;
    if(!mem[x][y])
    {
        mem[x][y]=1e9;
        track[x][y]=1e9;
        int to,t;
        for(int i=-1;i<=1;i++)
        {
            to=((x+i+n)%n);
            t=(ts(to,y+1)+a[to][y+1]);
            if(t<mem[x][y])
            {
                mem[x][y]=t;
                track[x][y]=to;
            }
            else if(t==mem[x][y] && to<track[x][y]) track[x][y]=to;
        }
    }
    return mem[x][y];
}
int main(){
    int i,j;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        fill(&mem[0][0],&mem[14][104],0);
        fill(&a[0][0],&a[14][104],0);
        mi=1e9;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for(i=0;i<n;i++)
            if((ts(i,0)+a[i][0])<mi)
                mi=mem[i][0]+a[i][0],si=i;
        // for(i=0;i<n;i++)
        // {
        //     for(j=0;j<m;j++)  printf("%2d ",a[i][j]);
        //     printf("\n");
        // }
        // printf("\n");
        // for(i=0;i<n;i++)
        // {
        //     for(j=0;j<m;j++)  printf("%2d ",mem[i][j]);
        //     printf("\n");
        // }
        printf("%d",si+1);
        for(i=0;i<m-1;i++)
        {
            si=track[si][i];
            printf(" %d",si+1);
        }
        printf("\n%d\n",mi);
    }
}