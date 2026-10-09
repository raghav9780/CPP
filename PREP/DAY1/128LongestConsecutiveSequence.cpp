#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v){
    int ans=0;
    unordered_set<int> s;
    for(auto it:v){
        s.insert(it);
    }
    for(auto it : s){
        if(s.find(it-1)==s.end()){
            int c=1;
            for(int i=it;;i++){
                if(s.find(i+1)!=s.end()){
                    c++;
                }else{
                    break;
                }
            }
            ans=max(c,ans);
        }
    }
    return ans;
}

int main(){
    vector<int>v = {0,3,7,2,5,8,4,6,0,1};
    cout<<solve(v);
}