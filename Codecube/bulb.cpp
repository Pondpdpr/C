// https://www.codecube.in.th/task/27
#include <bits/stdc++.h>
using namespace std;
int n,tim[1050000],t1,t2,start;
int light(int x){
    if(!x) return 0;
    if(tim[x]) return tim[x];
    tim[x]=1e9;
    int go;
    for(int ii=-1;ii<n-1;ii++)
    {
        go=x;
        if(ii>=0)if(go&(1<<ii)) go-=(1<<(ii));
        else go+=(1<<(ii));
//        printf("go1=1 = %d ",go);
        if(ii+1<n) if(go&(1<<ii+1)) go-=(1<<(ii+1));
        else go+=(1<<(ii+1));
//        printf("go2=1 = %d ",go);
        if(ii+2<n) if(go&(1<<ii+2)) go-=(1<<(ii+2));
        else go+=(1<<(ii+2));
//        printf("go3=1 = %d ",go);
//        printf("now = %d time = %d ii = %d goto = %d\n",x,tim[x],ii,go);
        tim[x]=min(tim[x],light(go)+1);
    }
    return tim[x];
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=n-1;i>=0;i--)
    {
        scanf("%d",&t1);
        start+=(t1<<(i));
    }
//    printf("%d\n",start);
    if(n==1)
    {
        if(!start) printf("0");
        else printf("1");
        return 0;
    }
    if(n==2)
    {
        if(!start) printf("0");
        else if(start==3) printf("1");
        else printf("-1");
        return 0;
    }
    printf("%d",(light(start)>=1e9)?-1:tim[start]);
}
