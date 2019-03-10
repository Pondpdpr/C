#include <bits/stdc++.h>
using namespace std;
long long  n,t1;
long long mid,top=1e15,bot;
long long amo;
vector<long long>v;
bool ca(long long  x){
    long long tmp=0;
    for(int i=0;i<v.size();i++)
    {
        tmp+=(x/v[i]);
    }
    if(amo<=tmp) return 1;
    return 0;
}
int main(){
    int i,j;
    scanf("%lld%lld",&n,&amo);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t1);
        v.push_back(t1);
    }
    while(1<=top)
    {
        mid=(bot+top)/2;
//        printf("mid=%lld bot=%lld top=%lld\n",mid,bot,top);
        if(ca(mid) && ca(mid-1)) top=mid-1;
        else if(!ca(mid) && !ca(mid-1)) bot=mid+1;
        else if(!ca(mid-1) && ca(mid))
        {
            printf("%lld",mid);
            return 0;
        }
    }
}
