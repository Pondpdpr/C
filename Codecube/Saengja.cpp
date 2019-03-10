// https://www.codecube.in.th/task/193
#include <bits/stdc++.h>
using namespace std;
struct axis{
    int x,val;
    bool operator <(axis a)const{
        return a.x>x;
    }
}a[100005];
int n,k,t1,t2;
long long mem[100005];
long long sa(int x){
    if(x==n) return 0;
    if(!mem[x])
    {
        int dis,tval,t=x;
        for(int i=x+1;i<n;i++)
            for(int j=t;j<i;j++)
            {
                dis=abs(a[i].x-a[j].x);
                if(dis>k)
                {
                    t++;
                    continue;
                }
                tval=(a[i].val+a[j].val-dis);
                if(tval>0) mem[x]=max(mem[x],sa(i+1)+tval);
            }
    }
    return mem[x];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> t1 >> t2;
        a[i].x=t1;
        a[i].val=t2;
    }
    sort(a,a+n);
//    for(i=0;i<n;i++) printf("%d %d\n",a[i].x,a[i].val);
    cout << sa(0);
}
