# Tutorial

Task A. Idea [FairyWinx](https://codeforces.com/profile/FairyWinx "Master FairyWinx")

 **Hint 1**The optimal answer has the maximum number of digits, so you only need to use the digits 1,2.

 **Hint 2**Alternate these numbers so that there are no adjacent identical numbers.

 **Solution**Since we want to maximize the number we need, we will first find the longest suitable number. Obviously, it is better to use only the numbers 1 and 2 for this. Therefore, the answer always looks like 2121… or 1212…. The first option is optimal when n has a remainder of 2 or 0 modulo 3, otherwise the second option is optimal.

Below is an example of a neat implementation.

 **Code**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    int type;
    if (n % 3 == 1)
        type = 1;
    else
        type = 2;
    int sum = 0;
    while (sum != n) {
        cout << type;
        sum += type;
        type = 3 - type;
    }
    cout << 'n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
        solve();
}
```
 

---

Задача B. Idea [FairyWinx](https://codeforces.com/profile/FairyWinx "Master FairyWinx")

 **Hint 1**What is a picture if the answer to the problem is "YES".

 **Hint 2**Think about a square of size 2×2.

 **Solution**Note that the answer to the problem is "YES" if and only if the picture is a certain number of disjoint rectangles. Now, in this case, let's look at all squares of size 2×2, note that there cannot be exactly 3 filled cells in each of them.

It is also clear that if there are 3 such cells, then there will be two intersecting rectangles. Therefore, you just need to check if there is a 2×2 square in which there are exactly 3 colored cells.

 **Code**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int sum = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
            if (sum == 3) {
                cout << "NOn";
                return;
            }
        }
    }
    cout << "YESn";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
        solve();
}
```
 

---

Задача C. Idea [FairyWinx](https://codeforces.com/profile/FairyWinx "Master FairyWinx")

 **Hint 1**There is always an answer when the upper right cell is painted white.

 **Hint 1**Imagine that you have only rectangles of size 1×2.

 **Hint 2**Paint over the cells from the "end".

 **Solution**According to the condition, if the upper left cell is painted black, then we cannot paint it that way. Otherwise it is possible. Let's colour the cells in the following order: (n,m),(n,m−1),…,(n,1),(n−1,m),…(1,1).

Let the cell (i,j) be colored black, then if j>1, then just paint the rectangle (i,j−1), (i,j). Otherwise, if j=1, then we will color the rectangle (i−1,j).

After such an operation, no cells that we painted before will be repainted, since they have one coordinate larger than ours, and the cell itself will be painted black.

Thus, we are able to paint the table for a maximum of n⋅m−1 operations.

 **Code**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
            a[i][j] = s[j] - '0';
    }
    vector<array<int, 4>> ans;
    if (a[0][0] == 1) {
        cout << -1<< 'n';
        return;
    }
    
    for (int j = m - 1; j >= 0; --j) {
        for (int i = n - 1; i >= 0; --i) {
            if (a[i][j]) {
                if (i != 0) {
                    ans.push_back({i, j + 1, i + 1, j + 1});
                } else {
                    ans.push_back({i + 1, j, i + 1, j + 1});
                }
            }
        }
    }
    cout << ans.size() << 'n';
    for (auto i : ans) {
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << ' ' << i[3] << 'n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
        solve();
}
```
 

---

Задача D. Idea [FairyWinx](https://codeforces.com/profile/FairyWinx "Master FairyWinx")

 **An important fact**A number is beautiful only if it is a multiple of d, but not a multiple of d2

 **Hint 1.1**Let's solve a more general problem: count the number of such partitions.

 **Hint 1.2**This problem is solved by dynamic programming.

 **Hint 1.3**Keep the remaining number in dynamics, as well as the last divisor.

 **Solution 1**Let's solve a more complex problem: calculate the number of partitions into such multipliers.

This is easily solved by dynamic programming. Let dpn,d be the number of factorizations, if we have a number left to decompose the number n, and before that we divided by the number d. Let's go through all such beautiful numbers i≥d that divide n, then dpn/i,i+=dpn,d.

Note that in this case, we took into account each option exactly once, since we count the divisors in the order of their increase.

Let C be the number of divisors of the number x, and V be the number of beautiful divisors of the number x. Then it works for O(C⋅V) or O(C⋅V2⋅log) depending on the implementation (since n is always a divisor of the number x), but it all comes easily, since V is no more 700.

 **Code**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
bool good(int i, int d) {
    return i % d == 0 && i % (1ll * d * d) != 0;
}
 
void solve() {
    int x, d;
    cin >> x >> d;
    map<pair<int, int>, int> dp;
    dp[{x, 1}] = 1;
    int res = 0;
    vector<int> del;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            if (good(i, d))
                del.push_back(i);
            if (x != i * i && good(x / i, d))
                del.push_back(x / i);
        }
    }
    while (dp.size()) {
        auto z = *dp.rbegin();
        if (z.first.first == 1) {
            res += z.second;
        }
        for (auto i : del) {
            if (z.first.first % i == 0 && i >= z.first.second) {
                dp[{z.first.first / i, i}] = min(dp[{z.first.first / i, i}] + z.second, 2);
            }
        }
        dp.erase(z.first);
    }
    if (res == 1)
        cout << "NOn";
    else
        cout << "YESn";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--)
        solve();
}
```
 **Hint 2.1**Consider the case ![dw_smiley](images/9ab563b1a2afd666eecce1a2949cf939fbd1aba6.gif)

 **Solution 2 (which almost everyone wrote)**Let x=da⋅b. Where b is not a multiple of d.

Then consider a few cases:

 * a=1. Then a is a beautiful number, since any number multiple of d2 can be decomposed into d⋅(a/d), each of which is colored, and a number multiple of only d, obviously, cannot be decomposed. So in this case there is exactly one option.
* b is composite, then obviously we can decompose in several ways if a≠1.
* d is simple. If b is prime, then the statement — we have only one option to decompose the number. Since every beautiful multiplier of the form d⋅k. But since d is simple, there are no other ways to decompose it, except to add a multiplier from b, and since b is simple, then all these options will be equal before the permutation.
* d is composite and is not a power of prime. If a≤2, then this case is no different from the past, since we still have to get two beautiful multipliers and they will all just be equal to d. Otherwise, let d=p⋅q, where gcd(p,q)=1. Then we can make the number p⋅qb−1 and pb−1⋅q. And also q⋅p,q⋅p,…,q⋅p, in this case we have a different number of divisors, so these options will be different, which means we have several options in this case.
* d is the power of a prime number. Then d=pk. The statement, if d=p2, and x=p7, then it cannot be decomposed in several ways, otherwise, if a>2 and k>1, then let's look at the partition of p2k−1,pk+1,pk,…,pk, it is clear that if k>2, then even if b=p, then the multiplier of pk+2 will still be beautiful, so it does not differ from the composite d in last case. Otherwise, if k=2, then if a=3 and b=p, then nothing can be added, otherwise we will have the opportunity to choose 3 of the multiplier pk, and somehow decompose the rest (since in this case a>3, then at least one more multiplier will be) and add b there. And we can decompose these 3 multipliers into 2 or 3 multipliers, as written above. Therefore, the only unique case when d is the degree of a prime is d=p2,x=p7.
 **Реализация**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return i;
    }
    return -1;
}
 
void solve() {
    int x, d;
    cin >> x >> d;
    int cnt = 0;
    while (x % d == 0) {
        ++cnt;
        x /= d;
    }
    if (cnt == 1) {
        cout << "NOn";
        return;
    }
    if (prime(x) != -1) {
        cout << "YESn";
        return;
    }
    if (prime(d) != -1 && d == prime(d) * prime(d)) {
        if (x == prime(d) && cnt == 3) {
            cout << "NOn";
            return;
        }
    }
    if (cnt > 2 && prime(d) != -1) {
        cout << "YESn";
        return;
    }
    cout << "NOn";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}
```
 

---

Задача E. Idea [FairyWinx](https://codeforces.com/profile/FairyWinx "Master FairyWinx")

 **Hint 1**After each operation, the maximum number is always increased by a specific number.

 **Hint 2**Students with a number greater than n are not interested in us.

 **Hint 3**Imagine that schoolchildren are not expelled, but at any given time we are just interested in a student with a minimum number. Obviously, the answer in this case will not change in any way.

 **Hint 4**Understand that every student will move to one particular desk after all the operations.

 **Hint 5**Write a greedy ![dw_smiley](images/811f0005ac46f06725274786a34a2080609f03ee.gif)

 **Solution**After each lesson, the person's number increases from the maximum number by the number of desks where no one goes. Therefore, it is easy to calculate how much time has passed since the very beginning, let it be the number k.

Then let's imagine that schoolchildren are not expelled, but at any given time we are simply interested in a student with a minimum number. Obviously, the answer in this case will not change in any way.

Let toi be the desk to which the student will move after k transfers, who originally sat at i desk. This is a standard problem that can be solved using binary lifts or not the most pleasant dfs with cycle allocation and the like. (but we do not recommend you to write the latter), we define the set Vi as the set of all numbers j, where toj=i.

Let the starting placement of the student be a permutation of b, then we will understand that if someone is transferred to the i desk after k operations, then the value in it is the minimum value in Vi. And if no one changes seats for it, then a student with the same number will always sit in it, regardless of the initial seating arrangement. After that, it is not difficult to guess the optimal starting seating of schoolchildren.

Let s be a lot of schoolchildren for whom we have not yet chosen the desk at which they are sitting. We will iterate over i from 1 to n in ascending order. Then you need to understand who should sit at the i desk.

If we know that there is a desk for which min(Vi)=i must be performed, then we must put a student with the minimum number of Vi at i, and we can put the remaining people at any desks with a number greater than i, so we will add all the other students to the set s. Otherwise, we just need to take a person from s with the minimum number and put him in a place under the number i, and then just remove him from the set of s.

 **Реализация**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int K = 30;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> cnt(n);
    vector<vector<int>> up(n, vector<int> (K));
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        ++cnt[a];
        up[i][0] = a;
    }
    for (int k = 1; k < K; ++k) {
        for (int i = 0; i < n; ++i) {
            up[i][k] = up[up[i][k - 1]][k - 1];
        }
    }
    vector<int> a(n);
    int cnt_bad = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!cnt[i]) {
            ++cnt_bad;
        }
    }
    int k = (*max_element(a.begin(), a.end()) - n) / cnt_bad;
    vector<vector<int>> add(n);
 
    for (int i = 0; i < n; ++i) {
        int v = i, level = k;
        for (int j = K - 1; j >= 0; --j) {
            if (level >= (1 << j)) {
                level -= (1 << j);
                v = up[v][j];
            }
        }
        add[a[v] - 1].push_back(i);
    }
    set<int> now;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (add[i].size()) {
            int res = *min_element(add[i].begin(), add[i].end());
            for (int j : add[i]) {
                if (j != res) {
                    now.emplace(j);
                }
            }
            ans[res] = i + 1;
        } else {
            ans[*now.begin()] = i + 1;
            now.erase(*now.begin());
        }
    }
    for (int i : ans)
        cout << i << ' ';
    cout << 'n';
}
```
 

---

Задача F. Idea [Igorbunov](https://codeforces.com/profile/Igorbunov "Grandmaster Igorbunov")

 **Hint 1**Realize that the maximum element is always an "inflection" of the first sequence.

 **Hint 2**It can be assumed that the "inflection" of the second subsequence will always be to the left of the maximum element (if anything, you can then simply expand the array).

 **Hint 3**In total, we have 3 points in time — both subsequences increase, the first decreases, and the second increases, or both subsequences decrease.

 **Hint 4**The first and third cases are solved by obvious greed.

 **Hint 5**For the second one, you can simply write the dynamics.

 **Solution**The inflection of the sequence is the maximum number in the subsequence. Then note that in the first subsequence, the inflection will be the maximum number in our array, let its position in the array be ind.

Then let's say for convenience that the inflection of the second subsequence will be to the right of the maximum element. (then expand the array and run the solution one more time).

In this case, we will have 3 states: both subsequences increase, the first decreases, and the second increases, or both subsequences decrease.

Let's solve the first case first:

Let dp1i be the minimum possible maximum element in a subsequence that does not contain an i element. It is considered not difficult. If dp1i−1<ai, then dp1i=min(dp1i,ai−1), since in this case we can add an i element to a subsequence that does not contain an element of i−1. Similarly, if ai−1<ai, then dp1i=min(dp1i,dp1i−1).

The third case is considered anologically, but only it needs to be counted from the end. (This array will be dp3)

Now let's deal with the second case:

Let dp2i,0 be the minimum possible last element in the second subsequence if the i element belongs to the first subsequence. And dp2i,1 is the maximum possible last element in the first subsequence if the i element belongs to the second subsequence. There are several options. If i and i−1 lie in the same and different subsequences. And we will count for i≤ind, since before this section both sub-sequences increase, and this is another calculated case. And then it is not difficult to get the conversion formulas:

 * dp2ind,0=dp1ind, by definition dp2ind,0
* If ai−1>ai, then dp2i,0=min(dp2i,0,dp2i−1,0).
* If dp2i−1,1>ai, then dp2i,0=min(dp2i,0,ai−1).
* If ai−1<ai, then dp2i,1=max(dp2i,1,dp3i−1,1).
* If dp2i−1,0<ai, then dp2i,1=max(dp2i,1,ai−1).

Now let's understand that the element with the number i can be an inflection of the second subsequence if i>ind, as well as dp2i,1>dp3i. That is, we can move from the second state to the third.

 **Реализация**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9 + 228;
 
int solve (int n, vector<int> a) {
    int ind = max_element(a.begin(), a.end()) - a.begin();
    vector<int> dp1(n, inf);
    dp1[0] = -1;
    for (int i = 1; i <= ind; ++i) {
        if (a[i] > dp1[i - 1])
            dp1[i] = min(dp1[i], a[i - 1]);
        if (a[i] > a[i - 1])
            dp1[i] = min(dp1[i], dp1[i - 1]);
    }
 
    vector<int> dp2(n, inf);
    dp2[n - 1] = -1;
    for (int i = n - 2; i >= ind; --i) {
        if (a[i] > dp2[i + 1])
            dp2[i] = min(dp2[i], a[i + 1]);
        if (a[i] > a[i + 1])
            dp2[i] = min(dp2[i], dp2[i + 1]);
    }
 
    vector<array<int, 2>> dp3(n, {inf, -inf});
    dp3[ind][0] = dp1[ind];
    int ans = 0;
    for (int i = ind + 1; i < n; ++i) {
        if (a[i - 1] > a[i])
            dp3[i][0] = min(dp3[i][0], dp3[i - 1][0]);
        if (dp3[i - 1][1] > a[i])
            dp3[i][0] = min(dp3[i][0], a[i - 1]);
        
        if (a[i - 1] < a[i])
            dp3[i][1] = max(dp3[i][1], dp3[i - 1][1]);
        if (dp3[i - 1][0] < a[i])
            dp3[i][1] = max(dp3[i][1], a[i - 1]);
        
        if (dp3[i][1] > dp2[i])
            ++ans;
    }
    return ans;
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = solve(n, a);
    reverse(a.begin(), a.end());
    cout << ans + solve(n, a) << 'n';
}

```
