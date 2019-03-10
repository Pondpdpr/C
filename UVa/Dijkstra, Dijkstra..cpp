#include <bits/stdc++.h>
using namespace std;
int n,m,mem[105][3],t1,t2,t3,ans,tx,tval,no[105][105],che[2];
struct node{
    int x,val,per,from;
    bool operator < (node a)const{
     return a.val<val;
    }
}t;
priority_queue<node>pq;
vector<node>v[105];
int main(){
    int i,j;
    freopen("Djikstra, Djikstra.-out.txt","w",stdout);
    while(1)
    {
        scanf("%d",&n);
        if(!n) return 0;
        scanf("%d",&m);
        fill(&mem[0][0],&mem[101][2],1e9);
        fill(&no[0][0],&no[104][104],3);
        ans=0;
        mem[1][0]=mem[1][1]=0;
        che[0]=che[1]=0;
        for(i=0;i<=n;i++) v[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&t1,&t2,&t3);
            v[t1].push_back({t2,t3,0,0});
            v[t2].push_back({t1,t3,0,0});
        }
        pq.push({1,0,0,101});
        pq.push({1,0,1,102});
        while(!pq.empty())
        {
            t=pq.top(); pq.pop();
//            printf("at %d from %d with %d im %d no[%d][%d]=%d\n",t.x,t.from,t.val,t.per,t.x,t.from,no[t.x][t.from]);
            if((no[t.x][t.from]==((t.per+1)%2)) || che[t.per]) continue;
//            printf("in\n");
            no[t.x][t.from]=t.per;
            no[t.from][t.x]=t.per;
            mem[t.x][t.per]=t.val;
            if(t.x==n)
            {
                che[t.per]=1;
                continue;
            }
//            printf("in\n");
            for(i=0;i<v[t.x].size();i++)
            {
                tx=v[t.x][i].x;
                tval=(t.val+v[t.x][i].val);
//                printf("t0 %d with %d mun %d\n",tx,tval,mem[tx][t.per]);
                if(tval < mem[tx][t.per] && no[t.x][tx]!=((t.per+1)%2))
                {
//                    printf("in\n");
                    pq.push({tx,tval,t.per,t.x});
                }
            }
        }
//        for(i=1;i<=n;i++) printf(" %d",mem[i][0]);
//        printf("\n");
//        for(i=1;i<=n;i++) printf(" %d",mem[i][1]);
//        for(i=0;i<=n;i++)
//        {
//            for(j=i;j<=n;j++) printf("%d to %d per %d\n",i,j,no[i][j]);
//        }
        ans+=(mem[n][0]+mem[n][1]);
//        printf("\nansper0=%d ansper1=%d\n",mem[n][0],mem[n][1]);
        if(ans>=1e9) printf("back to jail\n");
        else printf("%d\n",ans);
    }
}
