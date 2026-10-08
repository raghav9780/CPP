#include<bits/stdc++.h>
using namespace std;

/* ---------------- SHORT SUMMARY (logic only) ----------------
   - Insight: index i tak missing numbers ki ginti = arr[i] - (i+1).
     (kyunki bina missing ke arr[i] == i+1 hota)
   - Ye count non-decreasing -> monotonic -> binary search.
   - Smallest index 'i' dhoondo jahan missing(i) >= k  (lower bound).
   - Answer = i + k  (i = kitne array-elements is missing se pehle aa gaye).
   - Time O(log n), Space O(1).
------------------------------------------------------------- */

/*
==========================================================================
 1539. Kth Missing Positive Number  --  NOTE (Intuition)
==========================================================================

 PROBLEM (1 line):
   sorted, distinct positives arr[] diya hai. k-th MISSING positive
   number return karo.
   e.g. arr=[2,3,4,7,11], k=5 -> missing = 1,5,6,8,9,10,12...
        -> 5th missing = 9.

--------------------------------------------------------------------------
 BRUTE FORCE  O(n)
--------------------------------------------------------------------------
   1 se numbers pe chalo, har missing ko gino, k-th pe ruk jao.
   Theek hai par O(n). Hum O(log n) chahte hain.

--------------------------------------------------------------------------
 KEY INSIGHT -> "index i tak kitne numbers missing hain?"
--------------------------------------------------------------------------
   Agar KUCH missing na hota, to array perfectly aisa hota:
        index:  0  1  2  3  4
        value:  1  2  3  4  5        (arr[i] == i+1)
   Yani index i pe "expected" value (i+1) thi. Actual arr[i] usse bada
   hai -> jitna bada, utne numbers beech mein gayab.

        missing(i) = arr[i] - (i + 1)

   arr=[2,3,4,7,11]:
        i=0: 2-1=1 | i=1: 3-2=1 | i=2: 4-3=1 | i=3: 7-4=3 | i=4: 11-5=6

   MONOTONIC: i badhne pe missing(i) ghatta nahi -> F F F T T T flip
   -> isliye BINARY SEARCH lag sakti hai.

--------------------------------------------------------------------------
 BINARY SEARCH (on index)
--------------------------------------------------------------------------
   Goal: sabse pehla index jahan missing(i) >= k  (lower bound).
     missing(m) < k  -> abhi kam missing hue -> right jao  i = m+1
     missing(m) >= k -> ye candidate, left bhi dekho        j = m-1
   Loop (while i<=j) ke baad 'i' us pehle index pe ruk jata hai
   jahan missing >= k (ya n, agar answer array ke aage hai).

--------------------------------------------------------------------------
 ANSWER kaise banta hai?
--------------------------------------------------------------------------
   Loop ke baad 'i' = kitne array-elements humare k-th missing se PEHLE
   aate hain. Un i present numbers ko hata do, to k-th missing:

        answer = i + k

   CHECK arr=[2,3,4,7,11], k=5:
     missing: i0=1,i1=1,i2=1,i3=3,i4=6 -> pehla index missing>=5 hai i=4
     answer = 4 + 5 = 9   ✔
   CHECK arr=[1,2,3,4], k=2:  (missing 5,6,... -> 2nd = 6)
     saare missing(i)=0 -> koi index >=2 nahi -> i ruk jata n=4 pe
     answer = 4 + 2 = 6   ✔

--------------------------------------------------------------------------
 COMPLEXITY :  Time O(log n)   Space O(1)
==========================================================================
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // TODO (khud likho):
        // 1) i=0, j=arr.size()-1
        // 2) while(i<=j): m=mid; missing = arr[m]-(m+1);
        //       missing < k  -> i=m+1
        //       else         -> j=m-1
        // 3) return i + k;

    }
};
