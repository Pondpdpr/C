#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],ans,really[1000005][2],fac,t[2];
int main(){

    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    really[0][0]=a[0];
    really[0][1]=a[0];
    for(i=1;i<n;i++)
    {
        fac=0;
        if(a[i]>a[0])fac=1;
            if(fac==1){
                if(a[i]>really[t[fac]][fac])
                {
                    t[fac]++;
                    really[t[fac]][fac]=a[i];
                }
                else
                {
                    int bot=0;
                    int top=t[fac];
                    int ans = 0;
                    while(bot<=top)
                    {
                        int mid =bot+top>>1;
                        //printf("mid = %d bot = %d top = %d [%d]\n",mid,bot,top,a[i]);
                        if(a[i]<=really[mid][fac])
                        {
                            ans=mid;
                            top=mid-1;
                        }else
                        {
                            bot=mid+1;
                        }
                    }
                    really[ans][fac]=a[i];
                }
            }
        else{
            if(a[i]<really[t[fac]][fac])
            {
                t[fac]++;
                really[t[fac]][fac]=a[i];
            }
            else
            {
                int bot=0;
                int top=t[fac];
                int ans = 0;
                while(bot<=top)
                {
                    int mid =bot+top>>1;
                    //printf("mid = %d bot = %d top = %d [%d]\n",mid,bot,top,a[i]);
                    if(a[i]>=really[mid][fac])
                    {
                        ans=mid;
                        bot=mid+1;
                    }
                    else
                    {
                        top=mid-1;
                    }
                }
                really[ans][fac]=a[i];
            }
        }
    }
    printf("%d",t[1]+t[0]);
}
/*
9
1 7 3 -4 2 6 0 10 -5
*/
        //for(j=0;j<=t;j++)printf("%d ",really[j]);
        //printf("\n");
