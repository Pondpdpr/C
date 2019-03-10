// https://www.codecube.in.th/task/181
#include <bits/stdc++.h>
using namespace std;
struct node{
	int go,val;
	bool operator < (node a) const{
	return val<a.val;
	}
}t;
int n,m,p,t1,t2,t3,s,e,k=1e9,mem[40005],to,tx,tval;
vector<node>v[40005];
priority_queue<node>pq;
int main(){
	int i,j;
	scanf("%d%d%d",&n,&m,&p);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		v[t1].push_back({t2,t3});
		v[t2].push_back({t1,t3});
	}
	for(j=0;j<p;j++)
    {
        scanf("%d%d",&s,&e);
        fill(&mem[0],&mem[40005],0);
        pq.push({s,0});
        while(!pq.empty())
        {
            t=pq.top(); pq.pop();
            if(t.go==e)
            {
                k=min(k,t.val);
                break;
            }
            for(i=0;i<v[t.go].size();i++)
            {
                tx=v[t.go][i].go;
                tval=t.val;
                tval=max(v[t.go][i].val,t.val);
                if(!mem[tx] && tval<k)
                {
                    mem[tx]=1;
                    pq.push({tx,tval});
                }
            }
        }
        while(!pq.empty()) pq.pop();
    }
    if(k==1e9) k=-1;
    printf("%d",k);
}
