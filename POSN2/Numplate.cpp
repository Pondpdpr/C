#include <bits/stdc++.h>
using namespace std;
int Q,n,t1,t2,lk,che[5],a[4][4][5];
int tx,ty,tval,sx,sy,sval;
int cx[]={-1,0,1,0};
int cy[]={0,1,0,-1};
map<int,int>m;
struct axis{
    int x,y,val;
}t;
bool border(int x,int y){
    if(x>=0 && x<n && y>=0 && y<n) return 1;
    return 0;
}
queue<axis>q;
int main(){
    int i,j;
    scanf("%d",&Q);
    che[2]=3210;
    che[3]=876543210;
    lk=1;
    for(i=0;i<2;i++) for(j=0;j<2;j++) a[i][j][2]=lk,lk*=10;
    lk=1;
    for(i=0;i<3;i++) for(j=0;j<3;j++) a[i][j][3]=lk,lk*=10;
    while(Q--)
    {
        sval=0;
        lk=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&t1);
                sval+=(t1*a[i][j][n]);
                if(!t1) sx=i,sy=j;
            }
        }
        q.push({sx,sy,sval});
        while(!q.empty())
        {
            t=q.front(); q.pop();
            if(t.val==che[n]) break;
            for(i=0;i<4;i++)
            {
                tx=t.x+cx[i];
                ty=t.y+cy[i];
                if(!border(tx,ty)) continue;
                tval=(t.val-(((t.val/a[tx][ty][n])%10)*a[tx][ty][n]));
                tval+=(((t.val/a[tx][ty][n])%10)*a[t.x][t.y][n]);
                if(!m[tval])
                {
                    q.push({tx,ty,tval});
                    m[tval]=m[t.val]+1;
                }
            }
        }
        while(!q.empty()) q.pop();
        printf("%d\n",m[che[n]]);
        m.clear();
    }
}
/*
1 
2 
1 3 
2 0 

2 
3 
0 1 2 
3 4 5 
6 7 8 
3 
1 2 0 
3 4 5 
6 7 8 

2 
3 
3 0 1
4 8 2 
6 5 7 
3 
4 1 5 
0 2 8 
3 6 7 
*/