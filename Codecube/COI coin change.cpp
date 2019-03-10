// https://www.codecube.in.th/task/120
#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
int k,p,m,a[15],mem[1000005],track[1000005],t,buy,sell,amo[15],t1,t2;
void con(int x){
    if(x==0) return ;
    amo[track[x]]++;
    con(x-a[track[x]]);
}
int main(){
    int i,j;
    scanf("%d%d%d",&p,&m,&k);
    for(i=0;i<k;i++) scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
    {
        mem[i]=inf;
        for(j=0;j<k;j++)
        {
            if(a[j]>i) continue;
            mem[i]=min(mem[i],mem[i-a[j]]+1);
            if(mem[i]==mem[i-a[j]]+1) track[i]=j;
        }
    }
    t=inf;
    for(i=p;i<=m;i++)
    {
        t=min(mem[i]+mem[i-p],t);
        if(t==mem[i]+mem[i-p])
        {
            sell=mem[i-p];
            buy=mem[i];
            t1=i;
            t2=i-p;
        }
    }
    printf("%d %d\n",buy,sell);
    con(t1);
    for(i=0;i<k;i++) printf("%d ",amo[i]);
    printf("\n");
    memset(amo,0,sizeof(amo));
    con(t2);
    for(i=0;i<k;i++) printf("%d ",amo[i]);
}
/*
8 20 3
1 5 10
*/
