# 🧠 CPP — DSA Practice

> C++ solutions to DSA problems, solved & documented for revision.
> Har solution file ke andar ek detailed **intuition note** (Hinglish) bhi likha hai.

---

## 🔍 Binary Search

Do tarah ke problems yahan cover hue hain:

- **On Index / Array** → array ke index pe search (sorted / rotated / peak).
- **On Answer** → answer ki ek range maano, monotonic feasibility check karke sabse chhoti/badi valid value dhoondo (`F F F T T T` pattern).

---

### 📐 Binary Search on Index / Array

| # | Problem | Time | Space | Intuition (2 lines) |
|---|---------|------|-------|---------------------|
| 33 | [Search in Rotated Sorted Array](<BinarySearch/01_33SearchinRotatedSortedArray.cpp>) | `O(log n)` | `O(1)` | Mid nikaalo, dekho kaunsa half sorted hai. Target us sorted half ki range mein hai to wahan jao, warna dusre half mein. |
| 81 | [Search in Rotated Sorted Array II](<BinarySearch/02_81SearchinRotatedSortedArrayII.cpp>) | `O(log n)` avg / `O(n)` worst | `O(1)` | Wahi 33 wala logic, par duplicates. Jab `nums[i]==nums[m]==nums[j]` ho to sorted half decide nahi hota — `i++, j--` karke shrink karo. |
| 153 | [Find Minimum in Rotated Sorted Array](<BinarySearch/03_153FindMinimuminRotatedSortedArray.cpp>) | `O(log n)` | `O(1)` | Min wahan hai jahan rotation toota. `nums[m] > nums[j]` → min right mein (`i=m+1`), warna `m` khud candidate (`j=m`). |
| 162 | [Find Peak Element](<BinarySearch/05_162FindPeakElement.cpp>) | `O(log n)` | `O(1)` | Uphill direction pakdo: `nums[m] < nums[m+1]` to peak right mein hai (`i=m+1`), warna left (`j=m`). Convergence pe peak. |
| 540 | [Single Element in a Sorted Array](<BinarySearch/04_540SingleElementinaSortedArray.cpp>) | `O(log n)` | `O(1)` | Pairs ki parity use karo. `m` ko even rakho: agar `nums[m]==nums[m+1]` to single right mein (`i=m+2`), warna left (`j=m`). |
| 1539 | [Kth Missing Positive Number](<BinarySearch/12_1539KthMissingPositiveNumber.cpp>) | `O(log n)` | `O(1)` | Index `i` tak missing count = `arr[i]-(i+1)`, jo monotonic hai. Pehla index dhoondo jahan missing `>= k`; answer = `i + k`. |

---

### 🎯 Binary Search on Answer

| # | Problem | Time | Space | Intuition (2 lines) |
|---|---------|------|-------|---------------------|
| 69 | [Sqrt(x)](<BinarySearch/06_69Sqrt(x).cpp>) | `O(log x)` | `O(1)` | Answer `[0, x]` mein. `m*m` ko `x` se compare karke aadha range kaato; floor sqrt ke liye `j` lautao. (overflow se bachne ko `long long`). |
| — | [Find Nth Root of a Number](<BinarySearch/08_FindNthrootofanumber.cpp>) | `O(n · log m)` | `O(1)` | Answer `[1, m]` mein. `mid^n` ko `m` se compare. Power compute karte waqt early-bail (sentinel) se overflow rok. |
| 875 | [Koko Eating Bananas](<BinarySearch/07_875KokoEatingBananas.cpp>) | `O(n · log(maxPile))` | `O(1)` | Speed pe search `[1, max(pile)]`. `feasible(k)` = total ghante `<= h`? Monotonic, isliye sabse chhoti valid speed dhoondo. |
| 1482 | [Min Days to Make m Bouquets](<BinarySearch/09_1482MinimumNumberofDaystoMakemBouquets.cpp>) | `O(n · log(maxDay))` | `O(1)` | Din pe search. **Sort mat karo** — adjacency chahiye. `feasible(d)` = consecutive bloomed flowers se `>= m` bouquets bante? |
| 1283 | [Smallest Divisor Given a Threshold](<BinarySearch/10_1283FindtheSmallestDivisorGivenaThreshold.cpp>) | `O(n · log(maxNum))` | `O(1)` | Divisor pe search `[1, max(nums)]`. `feasible(d)` = `Σ ceil(nums[i]/d) <= threshold`? Sabse chhota aisa divisor. |
| 1011 | [Capacity To Ship Packages Within D Days](<BinarySearch/11_1011CapacityToShipPackagesWithinDDays.cpp>) | `O(n · log(sum))` | `O(1)` | Capacity pe search `[max(weights), sum(weights)]`. `feasible(cap)` = contiguous packages bharke din `<= D`? Sabse chhoti capacity. |

---

## 🧩 Key Patterns Cheat-Sheet

| Pattern | Kab use karein | Search Space |
|---------|----------------|--------------|
| **Rotated array search** | Sorted array rotate ho gaya ho | index `[0, n-1]` |
| **Peak / min finding** | Slope / rotation point dhoondna | index `[0, n-1]` |
| **BS on answer** | "Minimum/maximum X jo condition satisfy kare" + monotonic feasibility | value range `[lo, hi]` |

> 💡 **BS on Answer ka mantra:** *Range maano → `feasible(mid)` likho → `F F F T T T` ka flip point dhoondo → boundary (`j=mid-1` / `i=mid+1`) sambhalo.*

---

<sub>Solved by [@raghavgupta2412](https://github.com/raghavgupta2412) · har file ke top pe detailed Hinglish intuition note hai.</sub>
