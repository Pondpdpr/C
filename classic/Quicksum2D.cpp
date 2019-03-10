#include <bits/stdc++.h>
using namespace std;
int sum[1000][1000],w,y,x,z,i,j,m,n,a;
int main(){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
    {
        scanf("%d",&a);
        sum[i][j]=a+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    }
    scanf("%d%d",&w,&x);
    scanf("%d%d",&y,&z);
    printf("%d",sum[y][z]-sum[w-1][z]-sum[y][x-1]+sum[w-1][x-1]);
}
