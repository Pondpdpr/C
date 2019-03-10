#include <bits/stdc++.h>
using namespace std;
int n,cnt1,cnt0,che;
char c1;
int gcd(int a,int b){
    return b==0 ? a:gcd(b,a%b);
}
int main(){
    int i,j,k;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf(" %c",&c1);
        if(c1=='1') cnt1++,a[i]=1;
        else cnt0++,a[i]=0;
    }
    if(!cnt1 || !cnt0)
    {
        printf("1");
        return 0;
    }
    if(gcd(cnt1,cnt0)==1)
    {
        printf("%d",n);
        return 0;
    }
    i=1;
    while(i++)
    {
        if(!(n%i))
        {
            che=0;
            for(j=0;j<n-i;j+=i)
            {
                if(che) break;
                for(k=j;k<j+i;k++)
                if(a[k]!=a[k+i]){che=1;break;}
            }
            if(che) continue;
            printf("%d",i);
            return 0;
        }
    }
}
