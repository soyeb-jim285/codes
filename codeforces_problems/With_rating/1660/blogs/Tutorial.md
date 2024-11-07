# Tutorial

[1660A - Vasya and Coins](../problems/A._Vasya_and_Coins.md "Codeforces Round 780 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1660A - Vasya and Coins](../problems/A._Vasya_and_Coins.md "Codeforces Round 780 (Div. 3)")

If Vasya has b coins of 2 burles, then he can collect amounts of 2,4,…,2∗b burls. If Vasya does not have 1 burles coins, then he cannot collect the amount of 1 burle. If he has at least one coin in 1 burl, he can score odd amounts up to 2∗b+a. The following 1burl coins increase the maximum amount he can make. If Vasya has a coins for 1 burle, he can make up the amount of 2∗b+a burles, and 2∗b+a+1 - not anymore.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    for (int it = 0; it < t; ++it) {
        int a, b;
        cin >> a >> b;
        cout << (a == 0 ? 1 : a + 2 * b + 1) << 'n';
    }
    return 0;
}
```
[1660B - Vlad and Candies](../problems/B._Vlad_and_Candies.md "Codeforces Round 780 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1660B - Vlad and Candies](../problems/B._Vlad_and_Candies.md "Codeforces Round 780 (Div. 3)")

There will be three cases in total, let's consider them on two types of candies:

* a1=a2, then we will eat candies in this order [1,2,1,2, dots,1,2]
* a1=a2+1, then we will eat a candy of the type 1, and then we will eat in this order [2,1,2,1,…,2,1] (almost as in the case above)
* a1>=a2+2, then we will eat a candy of the type 1, but there will still be more of them than candies of the type 2 and we will have to eat a candy of the type 1 again. So the answer is "NO".

Now we prove that it is enough to check these conditions on two maximums of the array a. If the third condition is true, the answer is obvious "NO". Otherwise, we will by turns eat candies of the two maximum types until their number is equal to the third maximum, after which we will by turns eat candies of these three types and so on.

 **Solution**
```cpp
t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    if n == 1:
        if a[0] > 1:
            print("NO")
        else:
            print("YES")
        continue
    if a[-2] + 1 < a[-1]:
        print("NO")
    else:
        print("YES")
```
[1660C - Get an Even String](../problems/C._Get_an_Even_String.md "Codeforces Round 780 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1660C - Get an Even String](../problems/C._Get_an_Even_String.md "Codeforces Round 780 (Div. 3)")

We will act greedily: we will make an array prev consisting of 26 elements, in which we will mark prev[i]=true if the letter is already encountered in the string, and prev[i]=false otherwise. In the variable m we will store the length of the even string that can be obtained from s. We will go through the string by executing the following algorithm: 

* if prev[i]=false, mark prev[i]=true.
* if prev[i]=true, then we already have a pair of repeating characters to add to an even string — add 2 to the number m and clear the array used.

Clearing prev is necessary because both characters that will make up the next pair must be in the s string after the current character. In other words, if the last character in the current pair was st, then the first character in the new pair can be sk, where t<k<n.

Then we calculate the answer as n−m.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
int sz = 26;
 
void solve(){
    string s;
    cin >> s;
    int m = 0, n = (int)s.size();
    vector<bool>prev(sz, false);
    for(auto &i : s){
        if(prev[i - 'a']){
            m += 2;
            for(int j = 0; j < sz; j++) prev[j] = false;
        }
        else prev[i - 'a'] = true;
    }
 
    cout << n - m << endl;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
```
[1660D - Maximum Product Strikes Back](../problems/D._Maximum_Product_Strikes_Back.md "Codeforces Round 780 (Div. 3)")

Idea: [Aris](https://codeforces.com/profile/Aris "Candidate Master Aris")

 **Tutorial**
### [1660D - Maximum Product Strikes Back](../problems/D._Maximum_Product_Strikes_Back.md "Codeforces Round 780 (Div. 3)")

First, we can always get a product value equal to 1 if we remove all elements of the array. Then we need to know what maximal positive value of the product we can get. Consequently, the remaining array (after removing the corresponding prefix and suffix) should have no 0 elements. We can find maxima in all sections between zeros. Now we are left with a set of nonzero numbers. If the value of the product on the current segment is positive, it makes no sense to remove any more elements. Otherwise, the product is negative, then we must remove one negative number from the product (either to the left or to the right). Compare the values of the product on the prefix and suffix to the nearest negative value, and remove either the suffix or the prefix, respectively.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
 
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
 
    forn(i, n) 
        cin >> a[i];
    int ans = 0;
    int ap = n, as = 0;
    for(int i = 0, l = -1; i <= n; i++) {
        if (i == n || a[i] == 0) {
            int cnt = 0;
            bool neg = false;
            int left = -1, right = -1;
            int cl = 0, cr = 0;
            for (int j = l+1; j < i; j++) {
                neg ^= a[j] < 0;
                if (a[j] < 0) {
                    right = j;
                    cr = 0;
                }
 
                if (abs(a[j]) == 2) {
                    cnt++, cr++;
                    if (left == -1) cl++;
                }
 
                if (a[j] < 0 && left == -1) {
                    left = j;
                }
            }
            if (neg) {
                if (cnt - cl > cnt - cr) {
                    right = i;
                    cnt -= cl;
                } else {
                    left = l;
                    cnt -= cr;
                }
            } else {
                left = l, right = i;
            }
            if (ans < cnt) {
                ans = cnt;
                ap = left + 1, as = n - right;
            }
 
            l = i;
        }
    }
    cout << ap << ' ' << as << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    forn(tt, t) {
        solve();
    }
}
```
[1660E - Matrix and Shifts](../problems/E._Matrix_and_Shifts.md "Codeforces Round 780 (Div. 3)")

Idea: [myav](https://codeforces.com/profile/myav "Pupil myav"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1660E - Matrix and Shifts](../problems/E._Matrix_and_Shifts.md "Codeforces Round 780 (Div. 3)")

Count to the variable sum the number of all ones in the matrix.

Then consider pairs of diagonals, one of which starts in cell A[i][0], and the other — in cell A[0][n−i] (for 1≤i≤n−1). Using cyclic shifts, we can assemble the main diagonal from this pair. Then among all such pairs (and the main diagonal), find the one that contains the maximal number of ones, and store this number in the variable Max.

The number of zeros on the main diagonal, which should be turned into ones, is equal to n−Max.

The number of ones to be turned into zeros, because they are not on the main diagonal, is calculated as sum−Max.

The total answer is calculated as n−Max+sum−Max=n+sum−2Max.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back
 
const int INF = INT_MAX >> 1;
 
void solve() {
    int n; cin >> n;
    int cnt1 = 0;
    vector<int> cnt (n, 0);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0, k = (n - i) % n; j < n; j++, k = (k + 1 == n ? 0 : k + 1)) if (s[j] == '1') {
            cnt1++;
            cnt[k]++;
        }
    }
    int ans = INF;
    for (int i = 0; i < sz(cnt); i++) {
        ans = min(ans, cnt1 - cnt[i] + (n - cnt[i]));
    }
    cout << ans << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    forn(tt, t) {
        solve();
    }
}
```
[1660F1 - Promising String (easy version)](../problems/F1._Promising_String_(easy_version).md "Codeforces Round 780 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1660F1 - Promising String (easy version)](../problems/F1._Promising_String_(easy_version).md "Codeforces Round 780 (Div. 3)")

Note the fact that if the number of minus signs is greater than the number of plus signs by at least 2, then there is sure to be a pair of standing next to minus signs (according to the Dirichlet principle). When we apply the operation of replacing two adjacent minus signs with a plus sign, the balance (the difference of plus signs and minus signs) increases by 3. Then we need to find the number of subsections such that the balance on them is a multiple of 3 and non-positive (then we can apply the operations until the balance is 0). The balance value on the segment equals the balance value on the right boundary minus the balance value on the left boundary, i.e. we can find O(1) by prefix sums.

 **Solution**
```cpp
tst = int(input())
for _ in range(tst):
    n = int(input())
    s = input()
    b = [0 for i in range(n+1)]
    bal = n
    b[0] = bal
    ans = 0
    for i in range(1,n+1):
        if s[i-1] == '+':
            bal += 1
        else:
            bal -= 1
        b[i] = bal
        for j in range(i):
            if b[j] >= b[i] and (b[j] - b[i]) % 3 == 0:
                ans += 1
    print(ans)
```
[1660F2 - Promising String (hard version)](../problems/F2._Promising_String_(hard_version).md "Codeforces Round 780 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1660F2 - Promising String (hard version)](../problems/F2._Promising_String_(hard_version).md "Codeforces Round 780 (Div. 3)")

Now we need to quickly find for a given balance value (on the prefix), the number of matching left boundaries. The boundary is suitable if the balance on the boundary is comparable modulo 3 to the current balance and the current balance is less than the balance on the boundary, since we need the balance on the segment to be non-positive. That is, we need to be able to find a number of numbers for each value of the balance that is not less than ours. This can be done either by data structure, or notice that the balance takes only 2n+1 different values, then you can find the number of numbers not less on the prefix for O(1).

 **Solution**
```cpp
tst = int(input())
for _ in range(tst):
    n = int(input())
    s = input()
    f = [0 for i in range(3)]
    cur_bal = n
    cnt_bal = [0 for i in range(2 * n + 1)]
    cnt_bal[cur_bal] += 1
    f[cur_bal % 3] += 1
    ans = 0
    for i in range(n):
        #print(f)
        #print(cur_bal, ans)
        new_bal = cur_bal
        if s[i] == '-':
            new_bal -= 1
            f[new_bal % 3] += cnt_bal[new_bal]
            ans += f[new_bal % 3]
            cnt_bal[new_bal] += 1
            f[new_bal % 3] += 1
        else:
            f[new_bal % 3] -= cnt_bal[new_bal]
            new_bal += 1
            ans += f[new_bal % 3]
            cnt_bal[new_bal] += 1
            f[new_bal % 3] += 1
        cur_bal = new_bal
    print(ans)
```
