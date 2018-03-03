#include<bits/stdc++.h>
using namespace std;
map<string,string>par;
map<string,int>rnk;
string find_set(string st)
{
    if(par[st]==st) return st;
    return par[st]=find_set(par[st]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int c,r;
    while(cin>>c>>r && (c || r)){
        string st,st2;
        int ans=0;
        par.clear();
        rnk.clear();
        vector<string> vec;
        for(int i=0;i<c;i++){
            cin>>st;
            par[st]=st;
            vec.push_back(st);
        }
        for(int i=0;i<r;i++){
            cin>>st>>st2;
            if(find_set(st)!=find_set(st2)){
                rnk[find_set(st2)]+=rnk[find_set(st)]+1;
                if(rnk[find_set(st2)]>ans) ans=rnk[find_set(st2)];
                par[find_set(st)]=find_set(st2);
            }
        }
        cout<<ans+1<<endl;
    }


    return 0;
}
