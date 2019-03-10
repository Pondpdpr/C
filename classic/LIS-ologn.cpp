#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],ans,really[1000005];
int main(){

    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    really[0]=a[0];
    int t=0;
    for(i=1;i<n;i++)
    {
        if(a[i]>really[t])
        {
            t++;
            really[t]=a[i];
        }
        else
        {
            int bot=0;
            int top=t;
            int ans = 0;
            while(bot<=top)
            {
                int mid =bot+top>>1;
                //printf("mid = %d bot = %d top = %d [%d]\n",mid,bot,top,a[i]);
                if(a[i]<=really[mid])
                {
                    ans=mid;
                    top=mid-1;
                }
                else
                {

                    bot=mid+1;
                }
            }
            really[ans]=a[i];
        }
        //for(j=0;j<=t;j++)printf("%d ",really[j]);
        //printf("\n");
    }
    printf("%d",t+1);
}
/*
9
1 7 3 -4 2 6 0 10 -5
*/
