#include <bits/stdc++.h>
using namespace std;
int t,tmp,n,m,a[1000000];
queue<int>q;
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) q.push(i);
    while(!q.empty())
    {
        tmp++;
        if(tmp%m==0)
        {
            printf("%d ",q.front());
            q.pop();
        }else
        {
            t=q. front();
            q.pop();
            q.push(t);
        }
        tmp=tmp%m;
    }
}
