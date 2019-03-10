// https://www.codecube.in.th/task/162
#include <bits/stdc++.h>
using namespace std;
int Q,n,amo,a[100005],t1,t2;
int main(){
    int i,j;
    scanf("%d",&Q);
    while(Q--)
    {
        amo=t2=0;
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&t1),a[i]=-t1,amo+=a[i];
        sort(a,a+n);
        for(i=0;i<n;i++) a[i]*=-1;
        if(amo%2)
        {
            printf("No\n");
            continue;
        }
        for(i=0;i<n;i++)
        {
            t1=i+1;
            while(a[i])
            {
                if(t1==n)
                {
                    printf("No\n");
                    t2=1;
                    break;
                }
                if(a[t1]) a[t1]--,a[i]--;
                t1++;
            }
            if(t2) break;
        }
        if(t2) continue;
        printf("Yes\n");
    }
}