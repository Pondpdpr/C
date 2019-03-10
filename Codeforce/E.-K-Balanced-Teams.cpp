// https://codeforces.com/contest/1133/problem/E
#include <bits/stdc++.h>
using namespace std;
int n,k,mem[5005][5005],a[5005];
int tea(int x,int y){
    //  printf("%d %d\n",x,y);
    if(y==k || x==n) return 0;
    if(!mem[x][y])
    {
        mem[x][y]=max(mem[x][y],tea(x+1,y));
        int now=a[x];
        int i=x+1;
        // printf("che %d %d\n",now,k);
        while(now+5 >= a[i] && i<n) i++;
        mem[x][y]=max(mem[x][y],tea(i,y+1)+i-x); 
    }
    return mem[x][y];
}
int main(){
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    // for(i=0;i<n;i++) printf("%d ",a[i]);
    printf("%d",tea(0,0));
}