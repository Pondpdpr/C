#include <bits/stdc++.h>
using namespace std;
int n,m,t1,t2,t3,total,used,a[20000];
struct node{
    int x,y,val;
    bool operator < (node b)const
    {
        return b.val>val;
    }
};
int par(int x){
    if(a[x]==x) return x;
    else return a[x]=par(a[x]);
}

priority_queue<node>heap;
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        heap.push({t1,t2,t3});
        total+=t3;
    }
    for(i=0;i<n;i++)a[i]=i;
    while(!heap.empty())
    {
        node t=heap.top(); heap.pop();
        t1=par(t.x);
        t2=par(t.y);
        //printf("par-t.x= = %d\npar-t.y = %d\n",par(t.x),par(t.y));
        if(t1 != t2)
        {
            used+=t.val;
            a[t1]=t2;
        }
    }
    printf("%d\n",total-used);
}
/*
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0
*/
