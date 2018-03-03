#include<bits/stdc++.h>
using namespace std;
#define MAX 200
int par[MAX];
int find_set(int n)
{
    if(par[n]==n) return n;
    return par[n]=find_set(par[n]);
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc;
    cin>>tc;
    while(tc--){
        char m;
        cin>>m;
        getchar();
        for(int i='A';i<=m;i++) par[i]=i;

        string st;
        while(true){
            getline(cin,st);
            if(st.empty()){
                break;
            }

            if(find_set(st[0])!=find_set(st[1]))
                par[find_set(st[0])]=find_set(st[1]);
        }
        int cnt=0;
        for(int i='A';i<=m;i++){
            if(par[i]==i) cnt++;
        }
        if(tc) cout<<cnt<<endl<<endl;
        else cout<<cnt<<endl;
    }

    return 0;
}
