// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=293
#include <bits/stdc++.h>
using namespace std;
int n;
long long mem[30005];
int coin[]={1,5,10,25,50};
int main(){
    int i,j;
    mem[0]=1;
    for(i=0;i<5;i++)
        for(j=coin[i];j<=30000;j++)
            mem[j]+=mem[j-coin[i]];
    while(scanf("%d",&n) != EOF)
    {
        if(mem[n]==1) printf("There is only 1 way to produce %d cents change.\n",n);
        else printf("There are %lld ways to produce %d cents change.\n",mem[n],n);
    }
}