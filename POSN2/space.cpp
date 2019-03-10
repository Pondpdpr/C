#include <bits/stdc++.h>
using namespace std;
int n,mem[17000],test,tmp;
int main(){
    int i,j;
    scanf("%d",&n);
    for(test=0;test<(1<<n);test++)
    {
        mem[test]=1;
        for(i=0;i<n;i++)
        {
            tmp=(test|(1<<i));
            if(!mem[tmp] && tmp!=test)
            {
                for(j=n-1;j>=0;j--)
                    if(test&(1<<j)) printf("1");
                    else printf("0");
                    printf(" ");
                for(j=n-1;j>=0;j--)
                    if(tmp&(1<<j)) printf("1");
                    else printf("0");
                    printf("\n");
            }
        }
    }
}
