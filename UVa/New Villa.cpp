#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,che;
}t;
int ans,test,r,d,s,mem[12][1100],track[12][1100][4],t1,t2,t3,t4;
vector<int>door[12];
vector<int>lit[12];
queue<node>q;
stack<node>st;
int main(){
    freopen("in-New Villa.txt","r",stdin);
    freopen("out-New Villa.txt","w",stdout);
    int i,j;
while(1)
{
    mem[12][1100]={};
    track[12][1100][4]={};
    for(i=0;i<12;i++)
    {
        door[i].clear();
        lit[i].clear();
    }
    scanf("%d%d%d",&r,&d,&s);
    if(!r && !d && !s) return 0;
    if(test++) printf("\n");
    for(i=0;i<d;i++)
    {
        scanf("%d%d",&t1,&t2);
        door[t1].push_back(t2);
        door[t2].push_back(t1);
    }
    for(i=0;i<s;i++)
    {
        scanf("%d%d",&t1,&t2);
        lit[t1].push_back(t2);
    }
    q.push({1,1});
    t3=0;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t.x==r && t.che==(1<<r-1))
        {
            ans=mem[t.x][t.che];
            t3=1;
            break;
        }
        for(i=0;i<door[t.x].size();i++)
        {
            t1=door[t.x][i];
//            printf("room=%d li=%d changeroom=%d\n",t.x,t.che,t1);
            if(!mem[t1][t.che] && t.che&(1<<t1-1))
            {
                mem[t1][t.che]=mem[t.x][t.che]+1;
                track[t1][t.che][0]=t.x;
                track[t1][t.che][1]=t.che;
                track[t1][t.che][2]=2;
                track[t1][t.che][3]=t1;
                q.push({t1,t.che});
            }
        }
        for(i=0;i<lit[t.x].size();i++)
        {
            t1=lit[t.x][i];
            t2=0;
            if(t.che&(1<<t1-1)) t2=t.che-(1<<t1-1),t3=0;
            else t2|=t.che|(1<<t1-1),t3=1;
//            printf("room=%d li=%d changelit=%d\n",t.x,t.che,t2);
            if(!mem[t.x][t2])
            {
                mem[t.x][t2]=mem[t.x][t.che]+1;
                track[t.x][t2][0]=t.x;
                track[t.x][t2][1]=t.che;
                track[t.x][t2][2]=t3;
                track[t.x][t2][3]=t1;
                q.push({t.x,t2});
            }
        }
    }
    printf("Villa #%d\n",test);
    while(!q.empty()) q.pop();
    if(t3==0)
    {
        printf("The problem cannot be solved.\n");
        continue;
    }
    printf("The problem can be solved in %d steps:\n",ans);
    t3=r;
    t4=(1<<r-1);
    for(i=0;i<ans;i++)
    {
//        printf("t1=%d t2=%d t3=%d t4=%d\n",track[t3][t4][2],track[t3][t4][3],t3,t4);
        t1=track[t3][t4][2];
        t2=track[t3][t4][3];
        if(t1==2) t3=track[t3][t4][0];
        else t4=track[t3][t4][1];
        st.push({t1,t2});
    }
    for(i=0;i<ans;i++)
    {
        t=st.top();
        st.pop();
        if(t.x==0) printf("- Switch off light in room %d.\n",t.che);
        else if(t.x==1) printf("- Switch on light in room %d.\n",t.che);
        else printf("- Move to room %d.\n",t.che);
    }
}
}
/*
3 3 4
1 2
1 3
3 2
1 2
1 3
2 1
3 2
2 1 2
2 1
1 1
1 2
0 0 0
*/
