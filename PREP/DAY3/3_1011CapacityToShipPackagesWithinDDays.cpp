#include<bits/stdc++.h>
using namespace std;

/* ---------------- SHORT SUMMARY (logic only) ----------------
   - Binary search on CAPACITY cap in [max(weights), sum(weights)].
   - solve(cap): array pe chalo, ek din mein contiguous packages bharo;
     agar sum+w > cap -> naya din (c++, sum=w); warna sum+=w.
     c=1 se shuru (aakhri adhoora din bhi count ho). return = days needed.
   - feasible (days<=D) -> jj=min(jj,cap), j=mid-1 ; warna i=mid+1.
   - Time O(n log sum), Space O(1).
------------------------------------------------------------- */

/*
==========================================================================
 1011. Capacity To Ship Packages Within D Days  --  NOTE (Intuition)
==========================================================================

 PROBLEM (1 line):
   weights[] packages belt pe ORDER mein aate hain. Har din ship ek
   capacity tak load kar sakta hai (contiguous packages, order todna mana).
   D din mein sab bhejne ke liye minimum CAPACITY kya ho?

--------------------------------------------------------------------------
 KEY IDEA -> "Binary Search on the ANSWER (= CAPACITY)"
--------------------------------------------------------------------------
   Capacity pe binary search. MONOTONIC: capacity jitni badi, utne kam din
   lagenge (ya same). pattern: F F F T T T  <- pehla T = min feasible cap.

--------------------------------------------------------------------------
 SEARCH SPACE  [i, j]   (ISKO SAMAJHNA SABSE ZAROORI)
--------------------------------------------------------------------------
   i = max(weights)   -> LOWER BOUND.
        Kyun? Package tod nahi sakte -> ek package ek hi din mein poora
        jaata hai. Agar cap < max(weights), to sabse bhaari package KISI
        bhi din load hi nahi hoga -> impossible. Isliye valid cap kam se
        kam max(weights) honi hi chahiye.
        e.g. weights=[1,2,3,10], cap=8 -> 10 kabhi ship nahi -> bekaar.

   j = sum(weights)   -> UPPER BOUND.
        Itni cap ho ki saara weight ek hi din mein aa jaye -> sirf 1 din.
        Isse zyada cap ka koi fayda nahi.

   (Koko 875 se ULTA: wahan ek ghante mein sirf EK pile -> upper=max(pile).
    Yahan ek din mein KAI packages -> lower=max, upper=sum.)

--------------------------------------------------------------------------
 FEASIBILITY  -> solve(cap): is capacity pe kitne DIN lagenge?
--------------------------------------------------------------------------
   c=1 (pehla din already chal raha), sum=0.
   har package w:
      agar sum+w > cap -> current din full -> naya din: c++, sum=w
      warna             -> usi din rakho:   sum += w
   return c.
   ZAROORI: c=1 se shuru karo (ya end pe +1) warna aakhri adhoora din
   count nahi hoga -> undercount.

--------------------------------------------------------------------------
 BOUNDARY -> sabse CHHOTI feasible capacity chahiye
--------------------------------------------------------------------------
   if (days <= D) -> cap kaam karti -> jj=min(jj,mid), chhoti dhoondo j=mid-1
   else           -> zyada cap chahiye                              -> i=mid+1

--------------------------------------------------------------------------
 COMPLEXITY :  Time O(n * log(sum))   Space O(1)
--------------------------------------------------------------------------
 DRY RUN: weights=[1,2,3,4,5,6,7,8,9,10], D=5  -> answer 15
   cap=15 -> [1,2,3,4,5][6,7][8][9][10] = 5 din <=5  (feasible)
   cap=14 -> 6 din >5  (no) -> min feasible = 15
==========================================================================
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int j = accumulate(weights.begin(), weights.end(), 0);
        int i=*max_element(weights.begin(), weights.end());
        int jj=INT_MAX;
        while(j>=i){
            int m = i+(j-i)/2;
            int d = solve(m,weights);
            if(d<=days){
                jj=min(jj,m);
                j=m-1;
            }else{
                i=m+1;
            }
        }
        return jj;
    }
    int solve(int m , vector<int>&weights){
        int c=1;
        int sum=0;
        for(int i =0;i<weights.size();i++){
            int kk= sum+weights[i];
            if(kk>m){
                sum=0;
                sum+=weights[i];
                c++;
            }else{
                sum=kk;            
            }
        }
       return c;
    }
};