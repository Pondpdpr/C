// https://www.codecube.in.th/task/13
#include <bits/stdc++.h>
using namespace std;
int n,k,mem[1005][305],t1,t2,a[1005];
int par(int x,int y){
    if(x==n+1 && y==k+1) return 0;
    if(x>n+1 || y>k+1) return 1e9;
    if(!mem[x][y])
    {
        mem[x][y]=1e9;
        for(int i=x;i<=(n-(k-y));i++) mem[x][y]=min(mem[x][y],max(a[i]-a[x-1],par(i+1,y+1)));
    }
    return mem[x][y];
}
int main(){
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)  scanf("%d",&a[i]),a[i]+=a[i-1];
    printf("%d",par(1,1));
}