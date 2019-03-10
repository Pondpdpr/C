#include <bits/stdc++.h>
using namespace std;
int t1,t2,m,o,a[105],mem[21][105][105];
int wire(int cnt,int x,int y){
    if(cnt==m || x==y) return a[y]-a[x-1];
    if(!mem[cnt][x][y])
    {
        mem[cnt][x][y]=1e9;
        for(int i=x;i<y;i++)
        {
            mem[cnt][x][y]=min(mem[cnt][x][y],max(wire(cnt+1,x,i),wire(cnt+1,i+1,y)));
        }
    }
    return mem[cnt][x][y];
}
int main(){
    int i,j;
    scanf("%d%d",&m,&o);
    for(i=1;i<=o;i++)
    {
        scanf("%d",&t1);
        a[i]=t1+a[i-1];
    }
    printf("%d",wire(1,1,o));
}
