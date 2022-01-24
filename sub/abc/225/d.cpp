#include <bits/stdc++.h>
using namespace std;

int main () {
   long long n,q;cin>>n>>q;
    long long nil=-1;
    vector<long long>front(n+1,nil); // front[i] := 電車iの前部に連結している電車。ないならnil。
    vector<long long>back(n+1,nil);  // back[i]  := 電車iの後部に連結している電車。ないならnil。
    while(q--){
        long long c;cin>>c;
        if(c==1){
            long long x,y;cin>>x>>y;
            back[x] = y;
            front[y] = x;
        }else if(c==2){
            long long x,y;cin>>x>>y;
            back[x] = nil;
            front[y] = nil;
        }else{
            long long x;cin>>x;
            while(front[x] != nil){
                x = front[x]; // xの連結成分の、先頭に移動
            }
            vector<long long>ans;
            while(x != nil){
                ans.push_back(x);
                x = back[x];
            }
            cout<<ans.size()<<" ";
            for(long long i=0;i<=(int)ans.size()-1;i++){
                cout<<ans[i];
                if(i!=(int)ans.size()-1)cout<<" ";
                else cout<<endl;
            }
        }
    }

}