#include <bits/stdc++.h>
using namespace std;
int mid,ma,mi=1e9,t1,t2,n,c,a[1000000];
bool cat(int x){
    int i,t4=0,che=0;
    for(i=0;i<n*2;i++)
    {
        if(a[i]>x)
        {
//            printf("a[%d]=%d che=%d t4=%d\n",i,a[i],che,t4);
            if(t4==0)
            {
                che=a[i];
            }
            else if(a[i]!=che)
            {
//                printf("1\n");
                return 0;
            }
            t4=(t4+1)%2;
        }
    }
    return 1;
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n*2;i++)
    {
        scanf("%d",&a[i]);
        ma=max(ma,a[i]);
        mi=min(mi,a[i]);
    }
    while(1)
    {
        mid=(ma+mi)/2;
//        printf("%d ",mid);
        if(cat(mid) && !cat(mid-1))
        {
            printf("%d",mid);
            return 0;
        }else if(cat(mid) && cat(mid-1))
        {
            ma=mid-1;
        }else
        {
            mi=mid+1;
        }
    }
}
