#include <bits/stdc++.h>
using namespace std;
int ans,sy,sx,t1,t2,n,m,k,a[55][55];
long long mem[55][55];
int main(){
    int i,j;
    scanf("%d%d",&m,&n);
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&t1,&t2);
        a[t2][t1]=1;
    }
//    for(i=1;i<=n;i++)
//    {
//        for(j=1;j<=m;j++) printf("%d ",a[i][j]);
//        printf("\n");
//    }
    mem[1][1]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(!a[i][j])
            {
                mem[i+1][j]+=mem[i][j];
                mem[i][j+1]+=mem[i][j];
            }
        }
    }
//    for(i=1;i<=n;i++)
//    {
//        for(j=1;j<=m;j++) printf("%d ",mem[i][j]);
//        printf("\n");
//    }
    printf("%lld",mem[n][m]);
}
