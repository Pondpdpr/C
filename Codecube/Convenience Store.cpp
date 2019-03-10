// https://www.codecube.in.th/task/48
#include <stdio.h>
using namespace std;
int n,m,a,mem[3][50005],flag;
int main(){
//    freopen("Convenience Store.txt","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	mem[flag][0]=1;
	flag=!flag;
	for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        for(j=0;j<=m;j++)
        {
            mem[flag][j]=mem[!flag][j];
            if(j>=a) mem[flag][j]+=mem[!flag][j-a];
            mem[flag][j]%=1000007;
        }
        flag=!flag;
    }
    printf("%d",mem[!flag][m]);
}
