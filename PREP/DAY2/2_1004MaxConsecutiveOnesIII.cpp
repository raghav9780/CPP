#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&v,int k){
    int zeros = 0;
    int ans=0;
    int i=0;
    for(int j = 0; j < v.size(); j++){
            if(v[j] == 0) zeros++;                 // 1. add
            while(zeros > k){                      // 2. shrink until valid
                if(v[i] == 0) zeros--;
                i++;
            }
        ans = max(ans, j - i + 1);             // 3. update
    }
    return ans;
}

int main(){
    vector<int> v={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k=3;
    cout<<solve(v,k);
}