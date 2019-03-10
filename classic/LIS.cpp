#include <bits/stdc++.h>
using namespace std;
int n,a[1005];
int mem[1005][1005],trac[1005][1005];
int lis(int x,int y){
    if(x==n)
    {
        return 0;
    }
    else if(mem[x][y]==0)
    {
        int t=0;
        if(y<a[x])t=max(t,lis(x+1,a[x])+1);
        t=max(t,lis(x+1,y));
        if(t==lis(x+1,y))
        {
            trac[x][y] = 1;
        }
        else trac[x][y] = 2;
        mem[x][y]=t;
        return mem[x][y];
    }
    return mem[x][y];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        int t=lis(0,0);
    printf("%d\n",t);
    t= 0;
    int t2 = 0;
    while(t!=n)
    {
        if(trac[t][t2]==2)t2=a[t],printf("%d ",a[t]);
        t++;
    }
}
// 7 4 1 5 6 2 3 7
