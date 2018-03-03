#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //freopen("input.txt","r",stdin);
    while(cin>>n){
        int matrix[110][110];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
            }
        }
        int sum[110][110];
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                sum[i][j]=sum[i][j-1]+matrix[i][j-1];
            }
        }
        int chk[110];
        int maxx=-(1<<28);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                chk[0]=0;
                for(int k=0;k<n;k++){
                    chk[k+1]=max(sum[k][j+1]-sum[k][i]+chk[k], sum[k][j+1]-sum[k][i]);
                    if(chk[k+1]>maxx){
                        maxx=chk[k+1];
                    }
                }
            }
        }
        cout<<maxx<<endl;
    }

    return 0;
}
