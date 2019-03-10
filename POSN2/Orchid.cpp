#include <bits/stdc++.h>
using namespace std;
int n,d,bot,top,mid,ans,t1;
int a[1000005],che[1000005];
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]>=che[d]) che[++d]=a[i];
        else
        {
            bot=0;
            top=d+1;
            while(bot<=top)
            {
                mid=bot+top>>1;
                if(che[mid]>a[i])
                {
                    if(che[mid-1]<=a[i]){che[mid]=a[i];break;}
                    else top=mid-1;
                }
                else
                {
                    if(che[mid+1]>a[i]){che[mid+1]=a[i];break;}
                    else bot=mid+1;
                }
            }
        }
    }
    printf("%d",n-d);
}
