#include <bits/stdc++.h>
using namespace std;
struct node{
    int y,x;
}t;
int cy[]={-1,0,1,0};
int cx[]={0,1,0,-1};
int t1,sx,sy,mi,n,m,a[65][65],water[65][65],che,siz,wc[65][65],amo=1e9;
char s[65];
vector<node>v;
queue<node>q;
bool bor(int y,int x){
    if(y>0 && y<=n && x>0 && x<=m) return 1;
    return 0;
}
int main(){
    int i,j,l,o;
    scanf("%d%d",&m,&n);
    mi=min(n,m);
    for(i=1;i<=n;i++)
    {
        scanf("%s",s);
        for(j=1;j<=m;j++)
        {
            if(s[j-1]=='T') a[i][j]=1-a[i-1][j-1]+a[i-1][j]+a[i][j-1];
            else a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            if(s[j-1]=='P') water[i][j]=1;
        }
    }
//    for(i=1;i<=n;i++)
//    {
//        for(j=1;j<=m;j++) printf("%d ",a[i][j]);
//        printf("\n");
//    }
    for(l=mi;l>=0;l--)
    {
        for(i=1;i+l<=n;i++)
        {
            for(j=1;j+l<=m;j++)
            {
                if(a[i+l][j+l]-a[i+l][j-1]-a[i-1][j+l]+a[i-1][j-1]==0)
                {
                    v.push_back({i,j});
                    che=1;
//                    printf("l=%d at {%d,%d} to {%d,%d}\n",l,i,j,i+l,j+l);
                }
            }
        }
        if(che) break;
    }
    siz=l;
//    printf("siz=%d\n",siz);
    if(v.empty())
    {
        printf("0 0");
        return 0;
    }
    for(l=0;l<v.size();l++)
    {
        t1=0;
        fill(&wc[1][1],&wc[n][m],0);
        for(i=v[l].y;i<=v[l].y+siz;i++)
        {
            for(j=v[l].x;j<=v[l].x+siz;j++)
            {
                if(water[i][j] && !wc[i][j])
                {
                    t1++;
                    wc[i][j]=1;
                    q.push({i,j});
//                    printf("start st [%d][%d]\n",i,j);
                    while(!q.empty())
                    {
                        t=q.front();
                        q.pop();
                        for(o=0;o<4;o++)
                        {
                            sy=t.y+cy[o];
                            sx=t.x+cx[o];
                            if(bor(sy,sx) && !wc[sy][sx] && water[sy][sx])
                            {
//                                printf("water spread to [%d][%d]\n",sy,sx);
                                wc[sy][sx]=1;
                                q.push({sy,sx});
                            }
                        }
                    }
                }
            }
        }
        amo=min(amo,t1);
    }
    siz++;
    siz=siz*siz;
    printf("%d %d",siz,amo);
}
/*
6 6
PSPSPS
SPSPSP
PSPSPS
SPSPSP
PSPSPS
SPSPSP
*/
