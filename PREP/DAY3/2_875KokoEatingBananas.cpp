#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1;
        int j = *max_element(piles.begin(),piles.end());
        if(piles.size()==h){
            return j;
        }
        long long  jj=INT_MAX;
        while(j>=i){
            long long m = i+(j-i)/2;
            long long ans=solve(m,piles);
            if(ans<=h){
                jj=min(jj,m);
                j=m-1;
            }
            else{
                i=m+1;   
            }
        }
        return jj;
    }

    long long solve(long long m,vector<int>&piles){
        long long ans=0;
        for(auto k:piles){
            ans+=(k+m-1)/m;
        }
        return ans;
    }
int main()
{
    return 0;
}