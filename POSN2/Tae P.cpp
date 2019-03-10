#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val;
    bool operator <(node a)const{
        return a.val>val;
    }
}t;
int t1,t2,t3,n,m,h[200005];
long long ans;
priority_queue<node>heap;
int head(int x){
    if(h[x]==x) return x;
    else return h[x]=head(h[x]);
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        heap.push({t1,t2,t3-1});
    }
    for(i=0;i<=n;i++) h[i]=i;
    while(!heap.empty())
    {
        t=heap.top();
//        printf("x=%d y=%d headx=%d heady=%d val=%d\n",t.x,t.y,head(t.x),head(t.y),t.val);
        heap.pop();
        if(head(h[t.x])!=head(h[t.y]))
        {
//            printf("kao\n");
            ans+=t.val;
            h[head(t.x)]=head(h[t.y]);
        }
    }
    printf("%lld",ans);
}
/*
6 9
1 2 8
2 3 6
1 4 6
4 2 6
4 5 8
2 5 7
5 6 5
2 6 9
3 6 5
*/
