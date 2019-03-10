// https://codeforces.com/problemset/problem/118/A
#include <bits/stdc++.h>
using namespace std;
char c[105];
int main(){
    int i,j;
    scanf("%s",&c);
    j=strlen(c);
    for(i=0;i<j;i++)
    {
        if(c[i]=='A' || c[i]=='a' || c[i]=='E' || c[i]=='e' || c[i]=='I' || c[i]=='i' || c[i]=='O' || c[i]=='o' || c[i]=='U' || c[i]=='u' || c[i]=='Y' || c[i]=='y')
        continue;
        printf(".");
        if(c[i]>='A' && c[i]<='Z') c[i]+=32;
        printf("%c",c[i]);
    }
}
