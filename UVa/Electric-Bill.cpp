#include <bits/stdc++.h>
using namespace std;
int n,m,bot,top,mid,amo,t1,t2,t;
int bill(int x){
    int b=0;
    if(x>100) x-=100,b+=200;
    else b+=(x*2),x=0;
    if(x>9900) x-=9900,b+=29700;
    else b+=(x*3),x=0;
    if(x>990000) x-=990000,b+=4950000;
    else b+=(x*5),x=0;
    b+=(x*7);
    return b;
}
int main(){
    int i,j;
    while(1)
    {
        amo=bot=0;
        scanf("%d%d",&n,&m);
        if(!n && !m) return 0;
        if(n>200) n-=200,amo+=100;
        else amo+=(n/2),n=0;
        if(n>29700) n-=29700,amo+=9900;
        else amo+=(n/3),n=0;
        if(n>4950000) n-=4950000,amo+=990000;
        else amo+=(n/5),n=0;
        amo+=(n/7);
        top=amo;
        while(1)
        {
            // printf("%d %d\n",bot,top);
            mid=(bot+top)>>1;
            t1=bill(mid);
            t2=bill(amo-mid);
            // printf("bill - %d %d\n",t2,t1);
            if(t2-t1 == m)
            {
                printf("%d\n",t1);
                break;
            }
            else if(t2-t1 > m) bot=mid+1;
            else top=mid-1;
        }
    }
}