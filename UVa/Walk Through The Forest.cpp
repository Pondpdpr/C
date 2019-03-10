#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,val;
    bool operator <(node a)const{
    return a.val<val;
    }
}t;

int test,ans,fa,fb,sx,sval,n,m,t1,t2,t3,mem[1005];

priority_queue<node>heap;
vector<node>way[1005];

int main(){
    int i,j;
    while(1)
    {
//        freopen("in.txt","r",stdin);
//        freopen("out.txt","w",stdout);

        ans=0;
        scanf("%d",&n);
        if(n==0) return 0;
        scanf("%d",&m);
        if(test++) printf("\n");
        for(i=1;i<=n;i++) way[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&t1,&t2,&t3);
            way[t1].push_back({t2,t3});
            way[t2].push_back({t1,t3});
        }
        for(i=2;i<n;i++)
        {
            fill(&mem[0],&mem[1004],1e9);
            heap.push({i,0});
//            fill(&mem[0],&mem[1004],1e9);
            while(!heap.empty())
            {
                t=heap.top();
                heap.pop();
                mem[t.x]=min(mem[t.x],t.val);
                if(t.x==1)
                {
                    fa=mem[t.x];
                    printf("a=%d\n",mem[t.x]);
                    break;
                }
                if(t.x==n)
                {
                    fb=mem[t.x];
                    printf("b=%d\n",mem[t.x]);
                    ans++;
                    break;
                }
                for(j=0;j<way[t.x].size();j++)
                {
                    sx=way[t.x][j].x;
                    sval=t.val+way[t.x][j].val;
                    if(sval<mem[sx]) heap.push({sx,sval});
                }
            }
            while(!heap.empty()) heap.pop();
        }
        printf("%d",ans+1);
    }
}
/*
6 11
1 6 2995
6 3 4827
3 1 32391
1 3 153
3 5 12382
5 4 18716
4 3 19895
3 6 21726
6 1 1869
1 5 25667
5 2 17035
10 8
1 4 16803
4 8 6286
8 1 28531
1 10 10722
10 3 22946
3 8 24230
8 6 30570
6 2 19832
0
*/
