#include<bits/stdc++.h>
using namespace std;
string solve(string &s,string t){
    int ans =INT_MAX;
    pair<int,int> b={0,0};
    map<char,int>m,n;
    for(auto it:t){
        m[it]++;
    }
    int req=0;
    int i=0,j=0;
    while(j<s.size()){
        char ch = s[j];
        n[ch]++;
        if(m.count(ch) && m[ch]==n[ch]){
            req++;
        }
        while(req ==m.size()){
            if(j-i+1<ans){
                b.first=i;
                b.second=j-i+1;
                ans=min(ans,j-i+1);
            }
            char l=s[i];
            n[l]--;
            if(m.count(l) && n[l]<m[l]){
                req--;
            }
            i++;
        }
        j++;
    }
    if (ans == INT_MAX) return "";
    return s.substr(b.first,b.second);
}

int main()
{
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<solve(s,t);
    return 0;
}