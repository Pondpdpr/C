// https://www.codecube.in.th/task/30
#include <bits/stdc++.h>
using namespace std;
int n,k,a,mem[3][1000][100],ans;
/*
int mine(int x,int y,int che){
    if(!mem[x][y][che])
    {
        if(x<n-1)
        {
            if(che<k)
                mem[x][y][che]=max(mem[x][y][che],mine(x+1,y,che+1)+a[x+1][y]);
            mem[x][y][che]=max(mem[x][y][che],mine(x+1,y,0));
        }
        if(y<n-1)
        {
            if(che<k)
                mem[x][y][che]=max(mem[x][y][che],mine(x,y+1,che+1)+a[x][y+1]);
            mem[x][y][che]=max(mem[x][y][che],mine(x,y+1,0));
        }

    }
    return mem[x][y][che];
}
*/
int main(){
    int i,j,x,y,che;
    scanf("%d%d",&n,&k);
    bool flag=0;
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            scanf("%d",&a);
            for(che=0;che<=k;che++)
            {
                mem[flag][y][che] = 0;
                if(che-1>=0)
                {
                    mem[flag][y][che]=max(mem[flag][y][che],mem[!flag][y][che-1]+a);
                    if(y)mem[flag][y][che]=max(mem[flag][y][che],mem[flag][y-1][che-1]+a);
                }
                mem[flag][y][che]=max(mem[flag][y][che],mem[!flag][y][k]);
                if(y)mem[flag][y][che]=max(mem[flag][y][che],mem[flag][y-1][k]);
            }
        }
        flag = !flag;
    }
    for(i=0;i<=k;i++)ans=max(ans,mem[!flag][n-1][i]);
    printf("%d",ans);
}
/*
5 2
1 1 3 2 1
1 1 2 9 1
1 1 1 9 1
1 1 1 1 9
1 1 1 1 1
*/
