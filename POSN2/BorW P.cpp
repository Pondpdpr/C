#include <bits/stdc++.h>
using namespace std;
int n,a[205],t1,t2,mem[205][205][205];
int bow(int x,int in,int de){
    if(x==n) return 0;
    if(!mem[x][in][de])
    {
        if(a[x]>a[in]) mem[x][in][de]=max(mem[x][in][de],bow(x+1,x,de)+1);
        if(a[x]<a[de]) mem[x][in][de]=max(mem[x][in][de],bow(x+1,in,x)+1);
        mem[x][in][de]=max(mem[x][in][de],bow(x+1,in,de));
    }
    return mem[x][in][de];
}
int main(){
    int i,j;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1) return 0;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        a[203]=0;
        a[204]=1e9;
        fill(&mem[0][0][0],&mem[204][204][204],0);
        printf("%d\n",n-bow(0,203,204));
    }
}
/*
8
1 4 2 3 3 2 4 1
12
7 8 1 2 4 6 3 5 2 1 8 7
-1
*/
