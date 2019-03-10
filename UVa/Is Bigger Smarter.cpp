#include <bits/stdc++.h>
using namespace std;
int mem[1005],track[1005],t1,n;
struct el{
    int x,y,num;
    bool operator <(el a)const{
        return a.x>x;
    }
}a[1005];
stack<int>st;
int ele(int x){
    if(x==n+1) return 0;
    if(!mem[x])
    {
        for(int i=x;i<=n;i++)
        {
            int t=0;
            if(a[i].x>a[x-1].x && a[i].y<a[x-1].y) t=(ele(i+1)+1);
            if(t>mem[x])
            {
                mem[x]=t;
                track[x]=i+1;
            }
        }
    }
    return mem[x];
}
int main(){
//    freopen("Is Bigger Smarter.txt","r",stdin);
    int i,j;
    while(++n && scanf("%d%d",&a[n].x,&a[n].y) != EOF) a[n].num=n;
    n--;
//    for(i=0;i<=n;i++) printf("%d %d %d\n",a[i].x,a[i].y,a[i].num);
    sort(a+1,a+n+1);
    a[0].y=1e9;
//    for(i=0;i<=n;i++) printf("%d %d %d\n",a[i].x,a[i].y,a[i].num);
    printf("%d\n",ele(1));
    t1=1;
    for(i=0;i<mem[1];i++)
    {
        t1=track[t1];
        printf("%d\n",a[t1-1].num);
    }
}
