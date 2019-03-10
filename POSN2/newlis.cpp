#include <bits/stdc++.h>
using namespace std;
int n,a[1005],top=0,bot=0,mid,ans,t=0,real[1005];
int main(){

    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    real[0]=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>real[t])
        {
            t++;
            real[t]=a[i];
        }else
        {
            a[i];
            bot=0;
            top=t;
            while(bot<=top)
            {
                mid =bot+top>>1;
                if(a[i]<a[mid])
                {
                    ans=a[mid];
                    top=mid-1;
                }else bot=mid+1;
            }
            real[ans]=a[i];
        }
        for(j=0;j<n;j++)printf("%d ",real[j]);
        printf("\n");
    }
    printf("%d",t+1);
}
/*
9
1 7 3 -4 2 6 0 10 -5
*/
