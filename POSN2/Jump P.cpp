#include <bits/stdc++.h>
using namespace std;
int tmp=0,tma,t1,t2,n,k,a[60005],ma,che[60005];
int main(){
    int i,j;
    scanf("%d%d",&n,&k);
    if(n==0 || k==0)
    {
        printf("0");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&t1);
        che[i]=t1;
        tma=max(tma,t1);
        a[t1]--;
        t2=t1-k;
        if(t2<0) t2=0;
//        printf("t2=%d\n",t2);
        a[t2]++;
//        printf("a[%d]=%d\n",t2,a[t2]);
    }
    t1=0;
    for(i=0;i<=tma;i++)
    {
//        printf("a[%d]=%d\n",i,a[i]);
        t1+=a[i];
        if(i==che[tmp]) ma=max(ma,t1),tmp++;
    }
    printf("%d",ma);
}
