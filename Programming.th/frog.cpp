// https://programming.in.th/task/rev2_problem.php?pid=0029
#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    if(n>m)
    {
        printf("2");
        return 0;
    }
    printf("%d",((n-1)/m)+1);
}
