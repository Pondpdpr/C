// https://codeforces.com/problemset/problem/1118/A?locale=en
#include <bits/stdc++.h>
using namespace std;
int Q;
long long int t1,t2,t3;
int main(){
     int i,j;
     scanf("%d",&Q);
     while(Q--)
     {
         scanf("%lld%lld%lld",&t1,&t2,&t3);
         if(t2*2<=t3) printf("%lld\n",t1*t2);
         else
         {
             if(t1%2==0)printf("%lld\n",(t1/2)*t3);
             else printf("%lld\n",(t1/2)*t3+t2);
         }
     }
}
