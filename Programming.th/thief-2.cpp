#include <bits/stdc++.h>
using namespace std;

struct node{
    int y,val;
}t;

int x1,y1,n,t1,t2,t3,last,mem[1005][1005][2];

vector<node>a[1005];
stack<node>b;

int chase(int time,int x,int che){
    int i,era=0;
    if(time==last) return 0;
    if(!mem[time][x][che])
    {
        if(x>time) mem[time][x][che]=max(chase(time+1,x,che),mem[time][x][che]);
        if(x<=time)
        {
            mem[time][x][che]=max(mem[time][x][che],chase(time+1,x+1,che));
            if(!a[x].empty()){
            for(i=0;i<a[x].size();i++)
            {

                mem[time][x][che] = max(mem[time][x][che],chase(time+1,a[x][i].y,che)+a[x][i].val);
                if(che==0 && mem[time][x][che]==chase(time+1,a[x][i].y,che)+a[x][i].val) era=i;

            }
            printf("time=%d x=%d xhe=%d mem=%d\n",time,x,che,mem[time][x][che]);
            b.push({x,a[x][era].y});

            }
        }


    }
    return mem[time][x][che];
}

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        a[t1].push_back({t2,t3});
        last=max(last,t2);
    }
    last++;
    x1=chase(1,1,0);
    y1=chase(1,1,1);
    printf("%d",x1+y1);
}
