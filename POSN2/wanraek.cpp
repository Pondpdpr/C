#include <bits/stdc++.h>
using namespace std;
int che,coin[100],amo;
int mem[1005],track[1005];
int change(int x){
    int i;
    if(x==0) return 0;
    else if(mem[x]==0)
    {
        int t=1000000;
        for(i=0;i<che;i++)
        if(x>=coin[i]){
            t=min(t,change(x-coin[i])+1);
            if(t==change(x-coin[i])+1)
                track[x]=coin[i];
        }
        mem[x] = t;
        return mem[x];
    }
    return mem[x];
}
int main(){
    scanf("%d",&che);
    for(int i=0;i<che;i++)
        scanf("%d",&coin[i]);
    scanf("%d",&amo);
    printf("%d\n",change(amo));
    int t=amo;
    while(t!=0){
        printf("%d ",track[t]);
        t-=track[t];
    }
}
