#include <bits/stdc++.h>
using namespace std;
int n,mem[1005][1005],track[1005][1005][2];
char a[2][1005];
int dup(int x,int y){
    int i;
    if(x==n) return 0;
    else if(!mem[x][y])
    {
        for(i=y;i<n;i++)
        {
            if(a[0][x]==a[1][i])
            {
                mem[x][y]= max(mem[x][y],dup(x+1,i+1)+1);
                break;
            }
        }
        mem[x][y]= max(mem[x][y],dup(x+1,y));
        if(mem[x][y]==dup(x+1,y))track[x][y][0]=1;
        else track[x][y][0]=2,track[x][y][1]=y;
    }
    return mem[x][y];
}
int main(){
    scanf("%d",&n);
    scanf("%s",&a[0]);
    scanf("%s",&a[1]);
    printf("%d\n",dup(0,0));
    int t1=0,t2=0;
    while(t1!=n)
    {
        if(track[t1][t2][0]==2)printf("%c ",a[0][t1]),t2=track[t1][t2][1];
        t1++;
    }
}
