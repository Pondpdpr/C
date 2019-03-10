// https://programming.in.th/task/rev2_problem.php?pid=1149
#include <bits/stdc++.h>
using namespace std;
struct node{
    int y,x,val,gay;
    bool operator <(node a)const{
    return a.val<val;
    }
}t;
int cy[]={-1,0,1,0};
int cx[]={0,1,0,-1};
int sy,sx,t1,t2,n,a[1100][1100],mem[1100][1100],che[1100][1100];
priority_queue<node>heap;
bool bor(int y,int x){
    if(y>=0 && y<n && x>=0 && x<n) return 1;
    return 0;
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&t1);
            a[i][j]=t1;
            if(t1==0) heap.push({i,j,0,++t2}),che[i][j]=1;
        }
        while(!heap.empty())
        {
            t=heap.top();
            mem[t.y][t.x]=t.gay;
            printf("y=%d x=%d val=%d\n",t.y,t.x,t.val);
            heap.pop();
            for(i=0;i<4;i++)
            {
                sy=t.y+cy[i];
                sx=t.x+cx[i];
                if(bor(sy,sx))
                {
                    if(!mem[sy][sx] && !che[sy][sx])
                    {
                        printf("kao-y=%d x=%d di=%d\n",sy,sx,i);
                        che[sy][sx]=1;
                        t.val=max(t.val,a[sy][sx]);
                        heap.push({sy,sx,t.val,t.gay});
                    }else if(mem[t.y][t.x]!=mem[sy][sx] && mem[sy][sx])
                    {
                        printf("y=%d x=%d di=%d\n",t.y,t.x,i);
                        printf("%d",t.val);
                        return 0;
                    }
                }
            }
        }
}
