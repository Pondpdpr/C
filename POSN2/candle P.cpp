#include <bits/stdc++.h>
using namespace std;
struct node{
    int y,x;
}t;
int sy,sx,ans,n,m,mem[2005][2005],a[2005][2005];
int cy[]={-1,-1,0,1,1,1,0,-1};
int cx[]={0,1,1,1,0,-1,-1,-1};
queue<node>q;
bool bor(int y,int x){
    if(y>=0 && y<n && x>=0 && x<m) return 1;
    return 0;
}
int main(){
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        char s[m];
        scanf(" %s",s);
        for(j=0;j<m;j++)
        {
            if(s[j]=='1') a[i][j]=1;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==1 && !mem[i][j])
            {
                mem[i][j]=1;
                ans++;
                q.push({i,j});
                while(!q.empty())
                {
                    t=q.front();
                    q.pop();
                    for(k=0;k<8;k++)
                    {
                        sy=t.y+cy[k];
                        sx=t.x+cx[k];
                        if(bor(sy,sx) && a[sy][sx] && !mem[sy][sx])
                        {
                            mem[sy][sx]=1;
                            q.push({sy,sx});
                        }
                    }
                }
            }
        }
    }
    printf("%d",ans);
}
