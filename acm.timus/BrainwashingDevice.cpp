// http://acm.timus.ru/problem.aspx?space=1&num=1900
#include <bits/stdc++.h>
using namespace std;
int n,k,mem[505][505],track[505][505],a[505][505],b[505][505],t3,amo;
int pos(int x,int y){
    if(x>=n || y>=k) return 0;
    if(!mem[x][y])
    {
        mem[x][y]=-1;
        int t1;
        for(int i=x;i<n;i++)
        {
            t1=pos(i+1,y+1)+b[i][i]-b[x-1][i];
            if(t1>mem[x][y])
            {
                mem[x][y]=t1;
                track[x][y]=i+1;
            }
        }
    }
    return mem[x][y];
}
int main(){
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<n;i++)
        for(j=i;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<n;i++)
        for(j=n-1;j>=i;j--)
            b[i][j]=a[i][j]+b[i][j+1]+b[i-1][j]-b[i-1][j+1];
    printf("%d\n",pos(1,0));
    t3=1;
    while(amo<k)
        t3=track[t3][amo++],printf("%d\n",t3-1);
}
/*
4 2
9 2 1
6 3
8
4 1
5 0 6
5 3
5
*/
