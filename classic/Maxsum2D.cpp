#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005],ma,f,t;
int main(){
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            scanf("%d",&f);
            a[i][j]=a[i][j-1]+f;
        }
    for(i=0;i<m;i++)
        for(j=i;j<m;j++)
        {
            for(k=0;k<n;k++)
            {
                t+=a[k][j]-a[k][i-1];
                if(t<0)t=0;
                ma=max(ma,t);
            }
            t=0;
        }
        printf("%d",ma);
}
/*
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/
