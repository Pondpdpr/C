#include <bits/stdc++.h>
using namespace std;
int t1,t2;
char a[10000];
int main(){

    int i,j;
    gets(a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='a' && a[i]<='z') t1=1;
        if(a[i]>='A' && a[i]<='Z') t2=1;
    }
    if(t1==0 && t2==1) printf("All Capital Letter");
    else if(t1==1 && t2==0) printf("All Small Letter");
    else printf("Mix");
}
