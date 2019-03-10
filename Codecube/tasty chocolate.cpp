#include <bits/stdc++.h>
using namespace std;
int n,a[1005],mem[1005][3005];
int sweet(int x,int y){
    if(x==n) return 0;
    if(y==3001) return 1e9;
    if(!mem[x][y])
    {
        mem[x][y]=1e9;
        if(a[x]>y)mem[x][y]=min(mem[x][y],sweet(x+1,a[x]));
        mem[x][y]=min(mem[x][y],sweet(x+1,y+1)+1);
    }
    return mem[x][y];
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d",sweet(0,0));
}
/*
6
3 1 5 5 10 9
*/
