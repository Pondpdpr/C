#include <bits/stdc++.h>
using namespace std;
struct node{
    int y,x,di;
}t;
int tmp,amo,t1,t2,n,m,sx,sy,sdi,a[305][305],mem[305][305];
vector<int>si;
queue<node>q;
int cy[]={-1,0,1,0};
int cx[]={0,1,0,-1};
bool bor(int y,int x){
    if(y>=0 && y<n && x>=0 && x<m) return 1;
    return 0;
}
int sus(int x){
//    printf("rem at [%d][%d] di %d\n",q.front().y,q.front().x,q.front().di);
    mem[q.front().y][q.front().x]--;
    amo++;
    tmp=1;
    while(!q.empty())
    {
            t=q.front();
            q.pop();
            if(a[t.y][t.x]==11 && t.di==2) sx=t.x-1,sy=t.y,sdi=3;
            else if(a[t.y][t.x]==11 && t.di==1) sy=t.y-1,sx=t.x,sdi=0;
            else if(a[t.y][t.x]==12 && t.di==2) sx=t.x+1,sy=t.y,sdi=1;
            else if(a[t.y][t.x]==12 && t.di==3) sy=t.y-1,sx=t.x,sdi=0;
            else if(a[t.y][t.x]==13 && t.di==1) sy=t.y+1,sx=t.x,sdi=2;
            else if(a[t.y][t.x]==13 && t.di==0) sx=t.x-1,sy=t.y,sdi=3;
            else if(a[t.y][t.x]==14 && t.di==3) sy=t.y+1,sx=t.x,sdi=2;
            else if(a[t.y][t.x]==14 && t.di==0) sx=t.x+1,sy=t.y,sdi=1;
            else sy=t.y+cy[t.di],sx=t.x+cx[t.di],sdi=t.di;
//            printf("at [%d][%d] di %d go [%d][%d]\n",t.y,t.x,t.di,sy,sx);
            if(bor(sy,sx) &&  mem[sy][sx]) q.push({sy,sx,sdi}),mem[sy][sx]--,tmp++;
        }
    si.push_back(tmp);
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++) printf("%d ",mem[i][j]);
//        printf("\n");
//    }
}
int main(){
    freopen("8.in","r",stdin);
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            scanf("%d",&t1);
            a[i][j]=t1;
            if(t1/10==1 || t1/10==2) mem[i][j]=1;
            else if(t1/10==3) mem[i][j]=2;
        }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(mem[i][j])
            {
                if(a[i][j]==31)
                {
                    if((mem[i-1][j] || !bor(i-1,j)) && (mem[i+1][j] || !bor(i+1,j))) q.push({i,j,2}),q.push({i,j,0}),sus(1);
                    if((mem[i][j-1] || !bor(i,j-1)) && (mem[i][j+1] || !bor(i,j+1))) q.push({i,j,3}),q.push({i,j,1}),sus(1);
                }
                else
                {
                    if(a[i][j]==11)
                    q.push({i,j,2}),q.push({i,j,1});
                    else if(a[i][j]==12)
                    q.push({i,j,2}),q.push({i,j,3});
                    else if(a[i][j]==13)
                    q.push({i,j,0}),q.push({i,j,1});
                    else if(a[i][j]==14)
                    q.push({i,j,3}),q.push({i,j,0});
                    else if(a[i][j]==21)
                    q.push({i,j,2}),q.push({i,j,0});
                    else if(a[i][j]==22)
                    q.push({i,j,3}),q.push({i,j,1});
//                    printf("  rem\n");
                    sus(1);
                }

            }
        }
    }
    printf("%d\n",amo);
    for(i=0;i<si.size();i++) printf("%d ",si[i]);
}
