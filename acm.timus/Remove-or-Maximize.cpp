// http://acm.timus.ru/problem.aspx?space=1&num=2110
#include <bits/stdc++.h>
using namespace std;
int n,k,amo[35],a[100005],t1,t2,mi,ans;
unordered_map<int,bool>che;
int main(){
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(!che[a[i]])
        {
            for(j=0;j<31;j++) if((1<<j)&a[i]) amo[j]++; 
            che[a[i]]=true;
        }
        else
        {
            k--;
            a[i]=INT_MAX;
        }
        
    }
    for(i=0;i<k;i++)
    {
        mi=INT_MAX;
        for(j=0;j<n;j++)
        {
            if((t1|a[j])<mi)
            {
                // printf("when %d %d %d\n",i,t1,(t1|a[j]));
                mi=t1|a[j];
                t2=j;
            }
        }
        t1|=a[t2];
        for(j=0;j<31;j++) if((1<<j)&a[t2]) amo[j]--;
        a[t2]=INT_MAX;
    }
    for(i=0;i<31;i++) if(amo[i]>0) ans|=(1<<i);
    printf("%d",ans);
}