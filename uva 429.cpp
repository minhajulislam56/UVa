#include<bits/stdc++.h>
using namespace std;
bool strComp(string s, string t)
{
    int cnt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=t[i]) cnt++;
        if(cnt>1){
            return false;
        }
    }
    if(s=="slice" && t=="stick")
        cout<<cnt<<endl;
    return true;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--){

        string s[205],st;
        map<string,int> mp;
        int i=0;
        while(cin>>st){
            if(st=="*") break;
            mp[st]=i;
            s[i++]=st;
        }
        vector<int>edge[205];
        int p1,p2;
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                if(j==k || s[j].length()!=s[k].length())
                    continue;

                if(strComp(s[j],s[k])){
                    p1=mp[s[j]];
                    p2=mp[s[k]];
                    edge[p1].push_back(p2);
                }
            }
        }
        cin.ignore();
        string input;
        string source,destination;
        while(getline(cin,input) && input!=""){
            size_t pos=input.find(" ");
            source=input.substr(0,pos);
            destination=input.substr(pos+1,input.size());
            bool visited[205];
            memset(visited,false,sizeof visited);
            int dist[205];
            memset(dist,0,sizeof dist);

            int sr=mp[source];
            int ds=mp[destination];
            queue<int> q;
            dist[sr]=0;
            visited[sr]=true;

            q.push(sr);

            while(!q.empty()){
                int u=q.front();
                q.pop();
                if(u==ds)
                    break;
                for(int p=0;p<edge[u].size();p++){
                    int v=edge[u][p];
                    if(!visited[v]){
                        visited[v]=true;
                        dist[v]=dist[u]+1;
                        q.push(edge[u][p]);
                    }
                }
            }
            cout<<source<<" "<<destination<<" "<<dist[ds]<<endl;

        }
        if(tc)
            cout<<endl;

    }

    return 0;
}
