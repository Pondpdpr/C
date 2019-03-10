#include <bits/stdc++.h>
using namespace std;
int n,a[1005],che,top,bot,mid,ans;
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(&a[0],&a[n]);
    scanf("%d",&che);
    top=n-1;
    bot=0;
    while(bot<=top)
    {
        mid =bot+top>>1;
        if(che>a[mid])
        {
            ans=a[mid];
            bot=mid+1;
        }else top=mid-1;
    }
    printf("%d",ans);
}
