#include <bits/stdc++.h>
using namespace std;
int s1[3],s2[3],n,a[100005],mem[100005][9][9];
char s[100005];
int nu1(int x,int y,int z){
    int c1=0;
    c1|=x;
    c1|=y;
    c1|=z;
    if(c1&1 && c1&2 && c1&4) return 3;
    if((c1&1 && c1&2) || (c1&2 && c1&4) || (c1&1 && c1&4)) return 2;
    if(c1&1 || c1&2 || c1&4) return 1;
}
int nu2(int x,int y,int z){
    int c1=0;
    c1|=x;
    c1|=y;
    c1|=z;
    if(c1&1 && c1&2 && c1&4) return 3;
    if((c1&1 || c1&2) && c1&4) return 2;
    if(c1&1 || c1&2 || c1&4) return 1;
}
int farm(int x,int f1[],int f2[]){
    if(x==n) return 0;
    int i,c1=0,c2=0,to1[3],to2[3];
    for(i=0;i<3;i++)
    {
        c1|=f1[i];
        c2|=f2[i];
    }
    to1[0]=f1[1]; to2[0]=f2[1];
    to1[1]=f1[2]; to2[1]=f2[2];
    to1[2]=a[x]; to2[2]=a[x];
//    printf("f1[0]=%d f1[1]=%d f1[2]=%d\n",f1[0],f1[1],f1[2]);
//    printf("to1[0]=%d to1[1]=%d to1[2]=%d\n",to1[0],to1[1],to1[2]);
//    printf("f2[0]=%d f2[1]=%d f2[2]=%d\n",f2[0],f2[1],f2[2]);
//    printf("to2[0]=%d to2[1]=%d to2[2]=%d\n",to2[0],to2[1],to2[2]);
    if(!mem[x][c1][c2])
    {
        if(!c1&a[x] && c2&a[x])
        mem[x][c1][c2]=max(mem[x][c1][c2],farm(x+1,to1,f2)+nu1(f1[1],f1[2],a[x]));
        else if(!c2&a[x] && c1&a[x]) mem[x][c1][c2]=max(mem[x][c1][c2],farm(x+1,f1,to2)+nu2(f2[1],f2[2],a[x]));
        else
        {
            mem[x][c1][c2]=max(mem[x][c1][c2],farm(x+1,to1,f2)+nu1(f1[1],f1[2],a[x]));
            mem[x][c1][c2]=max(mem[x][c1][c2],farm(x+1,f1,to2)+nu2(f2[1],f2[2],a[x]));
        }
    }
    return mem[x][c1][c2];
}
int main(){
    int i,j;
    scanf("%d",&n);
    scanf("%s",s);
    for(i=0;i<n;i++)
    {
        if(s[i]=='W') a[i]=1;
        if(s[i]=='D') a[i]=2;
        if(s[i]=='F') a[i]=4;
    }
    printf("%d",farm(0,s1,s2));

}
/*
10
FDWWDFFDWW
*/
