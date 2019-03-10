#include <bits/stdc++.h>
using namespace std;
int Q,n,m,amo[2],t1,t2,t,tx,ans;
bool mem[205],che[205],t3;
vector<int>v[205];
queue<int>q;
int main(){
    int i,j;
//    freopen("Place The Guards-2-out.txt","w",stdout);
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d%d",&n,&m);
        fill(&che[0],&che[n],true);
        for(i=0;i<n;i++) while(!v[i].empty()) v[i].pop_back();
        while(!q.empty()) q.pop();
        ans=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&t1,&t2);
            v[t1].push_back(t2);
            v[t2].push_back(t1);
        }
        for(j=0;j<n;j++)
            if(che[j])
            {
                t3=false;
                q.push(j);
                che[j]=false;
                amo[0]=1;
                amo[1]=0;
                mem[j]=false;
                while(!q.empty())
                {
                    t=q.front(); q.pop();
                    for(i=0;i<v[t].size();i++)
                    {
                        if(che[v[t][i]])
                        {
                            mem[v[t][i]]=!mem[t];
                            amo[!mem[t]]++;
                            che[v[t][i]]=false;
                            q.push(v[t][i]);
                        }else if(mem[v[t][i]]==mem[t])
                        {
                            printf("-1\n");
                            t3=true;
                            break;
                        }
                    }
                    if(t3) break;
                }
                if(t3) break;
                if(amo[1]<amo[0] && amo[1]!=0) ans+=amo[1];
                else ans+=amo[0];
            }
        if(!t3)printf("%d\n",ans);
    }
}
/*
2
4 2
0 1
2 3
5 5
0 1
1 2
2 3
0 4
3 4
*/
