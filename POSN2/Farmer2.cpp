#include <bits/stdc++.h>
using namespace std;
/*
0 = --
1 = WW
2 = WD
3 = WF
4 = DW
5 = DD
6 = DF
7 = FW
8 = FD
9 = FF
*/
int n,a[100005],mem[100005][10][10];
string s;
int f(int x,int f1,int f2){
    if(x==n) return 0;
    if(!mem[x][f1][f2])
    {
        if(a[x]==1)
        {
            if(f1==0) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,1,f2)+1);
            else if(f1==1) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,1,f2)+1);
            else if(f1==2) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,4,f2)+2);
            else if(f1==3) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,7,f2)+2);
            else if(f1==4) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,1,f2)+2);
            else if(f1==5) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,4,f2)+2);
            else if(f1==6) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,7,f2)+3);
            else if(f1==7) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,1,f2)+2);
            else if(f1==8) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,4,f2)+3);
            else if(f1==9) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,7,f2)+2);
            if(f2==0) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,1)+1);
            else if(f2==1) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,1)+1);
            else if(f2==2) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,4)+1);
            else if(f2==3) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,7)+2);
            else if(f2==4) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,1)+1);
            else if(f2==5) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,4)+1);
            else if(f2==6) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,7)+3);
            else if(f2==7) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,1)+2);
            else if(f2==8) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,4)+3);
            else if(f2==9) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,7)+2);
        }
        if(a[x]==2)
        {
            if(f1==0) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,5,f2)+1);
            else if(f1==1) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,2,f2)+2);
            else if(f1==2) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,5,f2)+2);
            else if(f1==3) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,8,f2)+3);
            else if(f1==4) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,2,f2)+2);
            else if(f1==5) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,5,f2)+1);
            else if(f1==6) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,8,f2)+2);
            else if(f1==7) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,2,f2)+3);
            else if(f1==8) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,5,f2)+2);
            else if(f1==9) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,8,f2)+2);
            if(f2==0) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,5)+1);
            else if(f2==1) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,2)+1);
            else if(f2==2) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,5)+1);
            else if(f2==3) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,8)+3);
            else if(f2==4) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,2)+1);
            else if(f2==5) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,5)+1);
            else if(f2==6) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,8)+2);
            else if(f2==7) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,2)+3);
            else if(f2==8) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,5)+2);
            else if(f2==9) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,8)+2);
        }
        if(a[x]==3)
        {
            if(f1==0) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,9,f2)+1);
            else if(f1==1) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,3,f2)+2);
            else if(f1==2) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,6,f2)+3);
            else if(f1==3) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,9,f2)+2);
            else if(f1==4) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,3,f2)+3);
            else if(f1==5) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,6,f2)+2);
            else if(f1==6) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,9,f2)+2);
            else if(f1==7) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,3,f2)+2);
            else if(f1==8) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,6,f2)+3);
            else if(f1==9) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,9,f2)+1);
            if(f2==0) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,9)+1);
            else if(f2==1) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,3)+2);
            else if(f2==2) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,6)+3);
            else if(f2==3) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,9)+2);
            else if(f2==4) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,3)+3);
            else if(f2==5) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,6)+2);
            else if(f2==6) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,9)+2);
            else if(f2==7) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,3)+2);
            else if(f2==8) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,6)+2);
            else if(f2==9) mem[x][f1][f2]=max(mem[x][f1][f2],f(x+1,f1,9)+1);
        }
    }
    return mem[x][f1][f2];
}
int main(){
    int i,j;
    scanf("%d",&n);
    cin >> s;
    for(i=0;i<n;i++)
    {
        if(s[i]=='W') a[i]=1;
        else if(s[i]=='D') a[i]=2;
        else if(s[i]=='F') a[i]=3;
    }
    printf("%d",f(0,0,0));
}
/*
10
FDWFWDFWFD
*/
