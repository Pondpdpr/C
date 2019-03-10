// https://www.codecube.in.th/task/14
#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,cnt,rd,go;
	bool operator <(node a)const{
		return a.cnt<cnt;
	}
}t;
struct way{
	int num,y,val;
};
int ans1,ans2,che=1e9,che2,t4,gy,gcnt,grd,gto,n,m,ans,t1,t2,t3,mem[1500][4];
vector<way>edge[1100];
priority_queue<node>heap;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	fill(&mem[0][0],&mem[1499][3],1e9);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		edge[t1].push_back({i,t2,t3});
		edge[t2].push_back({i,t1,t3});
	}
	heap.push({1,0,0,0});
	while(!heap.empty())
	{
		t=heap.top();
		heap.pop();
		if(t.go+1<che)
		{
			mem[t.x][(t.rd+1)%2]=min(mem[t.x][(t.rd+1)%2],t.cnt);
//			mem[t.x][(t.rd+1)%2]=t.cnt;
//			printf("here=%d %t.rd=%d t.cnt=%d\n",t.x,t.rd,t.cnt);
			if(t.x==n && ((t.rd+1)%2)==0 && (!t4++ || t.cnt==che2))
			{
				ans1=t.go+1;
				ans2=t.cnt;
				che=t.cnt;
				che=t.go+1;
			}
			for(i=0;i<edge[t.x].size();i++)
			{
			   gy=edge[t.x][i].y;
			   gcnt=t.cnt+edge[t.x][i].val;
			    grd=t.rd+1;
			   gto=max(t.go,edge[t.x][i].num);
			   if(gcnt<=mem[gy][(grd+1)%2])
				heap.push({gy,gcnt,grd,gto});
			}
		}
	}
	printf("%d %d",ans1,ans2);
}
/*
5 10
4 5 7
2 3 1
3 5 5
2 5 5
1 4 6
1 2 1
3 4 7
1 3 7
2 4 4
1 5 8
*/