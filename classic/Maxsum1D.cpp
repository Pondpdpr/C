#include <bits/stdc++.h>
using namespace std;
int n,a[1005],ma,t;
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        t+=a[i];
        if(t<0)t=0;
        ma=max(ma,t);
    }
    printf("%d",ma);
}
/*
9
1 -2 5 -8 3 5 -9 3 4
*/
