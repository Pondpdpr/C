// https://www.codecube.in.th/task/11
#include <bits/stdc++.h>
using namespace std;
int n,m,k,t1,t2,mem[1005][1005],per[1005];
int main(){
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        t1=m;
        for(j=1;j<=m;j++)
        {
            scanf("%d",&mem[i][j]);
            t1-=mem[i][j];
        }
        per[i]=t1;
    }
    for(i=n;i>0;i--)
    {
        if(per[i]>=k-t2)
        {
            t1=0;
            for(j=1;j<=m;j++)
            {
                t1+=mem[i][j];
                if(j>k) t1-=mem[i][j-k];
                if(t1<=t2 && j>=k)
                {
                    printf("%d",i);
                    return 0;
                }
            }
        }
        t2+=per[i];
    }
}
