// https://programming.in.th/task/rev2_problem.php?pid=1038
#include <bits/stdc++.h>
using namespace std;
int n;
double mem[2100000],t1,a[21][21];
double bond(int x,int y){
    if(x==n) return 1;
    if(!mem[y])
        for(int i=0;i<n;i++)
            if(((1<<i)&y)==0) mem[y]=max(mem[y],a[i][x]*bond(x+1,y|(1<<i)));
    return mem[y];
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%lf",&t1);
            a[i][j]=t1/100;
        }
    printf("%.6f",bond(0,0)*100);
}
