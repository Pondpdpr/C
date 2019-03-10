#include <bits/stdc++.h>
using namespace std;
int i,j,n,m,area[1000][1000],amo;
int check(int x,int y){
    area[x][y]=2;
    if(area[x+1][y]==0 && x+1<n){
        check(x+1,y);
    }
    if(area[x-1][y]==0 && x-1>=0){
        check(x-1,y);
    }
    if(area[x][y+1]==0 && y+1<m){
        check(x,y+1);
    }
    if(area[x][y-1]==0 && y-1>=0){
        check(x,y-1);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&area[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(area[i][j]==0)
        {
            check(i,j);
            amo+=1;
        }
        printf("%d\n",amo);
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            printf("%d ",area[i][j]);
        printf("\n");
        }
}
