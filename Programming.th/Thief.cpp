// https://programming.in.th/task/rev2_problem.php?pid=1153
#include <bits/stdc++.h>
using namespace std;

struct node{
    int y,val;
};

int n,t1,t2,t3,last,mem[1005][2][2];

vector<node>a[1005];

int chase(int time,int x,int y){
    int che=0,i,j,cx=0,cy=0;
    if(x<=time) cx=1;
    if(y<=time) cy=1;
    if(time==last) return 0;
//    printf("   x=%d cx=%d y=%d cy=%d time=%d\n",x,cx,y,cy,time);
    if(!mem[time][cx][cy])
    {

        if(cx && cy)
        {
            for(i=0;i<a[x].size();i++)
            {
                mem[time][cx][cy]=max(mem[time][cx][cy],chase(time+1,a[x][i].y,y+1)+a[x][i].val);
                mem[time][cx][cy]=max(mem[time][cx][cy],chase(time+1,x+1,a[x][i].y)+a[x][i].val);
                che=i;
                for(j=0;j<a[x].size();j++)
                if(i!=j) mem[time][cx][cy]=max(mem[time][cx][cy],chase(time+1,a[x][i].y,a[x][j].y)+a[x][i].val+a[x][j].val);
            }
        }
        if(cx && y>time)
        {
            for(i=0;i<a[x].size();i++)
            {
                mem[time][cx][cy]=max(mem[time][cx][cy],chase(time+1,a[x][i].y,y)+a[x][i].val);
            }
            mem[time][cx][cy]=max(mem[time][cx][cy],chase(time+1,x+1,y));
        }
        if(cy && x>time)
        {
            for(i=0;i<a[y].size();i++)
            {
                mem[time][cx][cy]=max(mem[time][cx][cy],chase(time+1,x,a[y][i].y)+a[y][i].val);
            }
            mem[time][cx][cy]=max(mem[time][cx][cy],chase(time+1,x,y+1));
        }
//        printf("in x=%d cx=%d y=%d cy=%d time=%d max=%d\n",x,cx,y,cy,time,mem[time][cx][cy]);

    }
    mem[time][cx][cy]=max(mem[time][cx][cy],chase(time+1,x+1,y+1));
//    printf("ou x=%d cx=%d y=%d cy=%d time=%d max=%d\n",x,cx,y,cy,time,mem[time][cx][cy]);
    return mem[time][cx][cy];
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
    printf("%d",chase(1,1,1));
}
