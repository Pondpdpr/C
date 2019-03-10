// https://www.codecube.in.th/task/25
#include <bits/stdc++.h>
using namespace std;
int t1,t2,n,a[605];
int mem[605][605];
int f(int x,int y){
//    printf("x=%d y=%d\n",x,y);
    if(x==y) return 0;
    if(!mem[x][y])
    {
        for(int i=x;i<y;i++)
        {
            if(a[i]-a[x-1]<a[y]-a[i]) mem[x][y]=max(f(i+1,y)+(a[i]-a[x-1])*2+(a[y]-a[i]),mem[x][y]);
            else mem[x][y]=max(f(x,i)+(a[y]-a[i])*2+(a[i]-a[x-1]),mem[x][y]);
        }
    }
//    printf("mem[%d][%d]=%d\n",x,y,mem[x][y]);
    return mem[x][y];
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t1);
        a[i]=a[i-1]+t1;
    }
    printf("%d",f(1,n));
}
/*
4
1 4 5 2
*/
