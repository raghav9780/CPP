#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    int i=0,j=0;
    int ans=0;
    unordered_map<char,int> m;
    while(j<s.size()){
        m[s[j]]++;
        if(m.size()==(j-i+1)){
            ans=max(ans,j-i+1);
        }else{
            while(m.size()<(j-i+1)){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}


int main(){
    string s = "pwwkew";
    cout<<solve(s);
}