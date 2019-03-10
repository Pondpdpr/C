#include <bits/stdc++.h>
using namespace std;
int a[25],Q;
long long mem[10005];
int main(){
    int i,j;
    mem[0]=1;
    for(i=1;i<=23;i++) a[i]=(i*i*i);
    for(i=1;i<=21;i++)
    {
        for(j=a[i];j<=10000;j++) mem[j]+=mem[j-a[i]];
    }
    while(scanf("%d",&Q) != EOF) printf("%lld\n",mem[Q]);
}
