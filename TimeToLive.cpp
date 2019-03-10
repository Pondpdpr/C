#include <bits/stdc++.h>
using namespace std;
int c,n,mem[100005],ma,t1,t2,poma,t;
vector<int>v[100005];
queue<int>q;
int main(){
    int i,j;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&t1,&t2);
            v[t1].push_back(t2);
            v[t2].push_back(t1);
        }
        q.push(0);
        while(!q.empty())
        {
            t=q.front();
            q.pop();
//            printf("1-in at %d with %d\n",t,mem[t]);
            for(i=0;i<v[t].size();i++)
            {
//                printf("scan to %d\n",v[t][i]);
                if(!mem[v[t][i]] && v[t][i])
                {
//                    printf("go\n");
                    q.push(v[t][i]);
                    mem[v[t][i]]=mem[t]+1;
                    if(mem[t]+1>ma) poma=v[t][i];
                }
            }
        }
        q.push(poma);
        for(i=0;i<n;i++) mem[i]=0;
        while(!q.empty())
        {
            t=q.front();
            q.pop();
//            printf("2-in at %d with %d\n",t,mem[t]);            for(i=0;i<v[t].size();i++)
            {
//                printf("scan to %d\n",v[t][i]);
                if(!mem[v[t][i]])
                {
//                    printf("go\n");
                    q.push(v[t][i]);
                    mem[v[t][i]]=mem[t]+1;
                    ma=max(mem[t]+1,ma);
                }
            }
        }
        printf("%d\n",(ma+1)/2);
        for(i=0;i<=n;i++)
        {
            while(!v[i].empty())v[i].pop_back();
            mem[i]=0;
        }
        ma=0;
    }
}
