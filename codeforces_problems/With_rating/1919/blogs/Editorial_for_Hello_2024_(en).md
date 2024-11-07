# Editorial_for_Hello_2024_(en)


### [1919A - Wallet Exchange](../problems/A._Wallet_Exchange.md "Hello 2024")

Author: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**When does the game end?

 **Solution**Depending on whether the player chooses to exchange wallets with their opponent on step 1, 1 coins will be removed from either the opponent's wallet or the player's wallet. This means that if either of the players still has remaining coins, the game will not end as at least one of the choices will still be valid.

The only way that the game ends is when both players have 0 coins. Since each operation decreases the total amount of coins by exactly 1, the only way for Alice to win the game is if a+b is odd.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if ((a + b) % 2 == 0) {
            cout << "Bobn";
        } else {
            cout << "Alicen";
        }
    }
}
```
### [1919B - Plus-Minus Split](../problems/B._Plus-Minus_Split.md "Hello 2024")

Author: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**Try to find a lower bound.

 **Solution**The answer is |a1+a2+…+an|. Intuitively, whenever we have a subarray with a sum equal to 0, it will be helpful for us as its penalty will become 0. Hence, we can split a into subarrays with a sum equal to 0 and group up the remaining elements into individual subarrays of size 1. A formal proof is given below.

Let us define an alternative penalty function p2(l,r)=|al+al+1+…+ar|. We can see that p2(l,r)≤p(l,r) for all 1≤l≤r≤n. Since the alternative penalty function does not have the (r−l+1) term, there is no reason for us to partition a into two or more subarrays as |x|+|y|≥|x+y| for all integers x and y, so the answer for the alternative penalty function is |a1+a2+…+an|.

Since p2(l,r)≤p(l,r), this means that the answer to our original problem cannot be smaller than |a1+a2+…+an|. In fact, this lower bound is always achievable. Let us prove this by construction.

Note that if we flip every "+" to "−" and every "−" to "+", our answer will remain the same since our penalty function involves absolute values. Hence, we can assume that the sum of elements of a is non-negative.

If the sum of elements of a is 0, we can split a into a single array equal to itself b1=a and obtain a penalty of 0. Otherwise, we find the largest index i where a1+a2+…+ai=0. Then we let the first subarray be b1=[a1,a2,…,ai] and the second subarray be b2=[ai+1], so we have p(b1)=0 and p(b2)=1. Since i is the largest index, ai+1 has to be equal to 1 as if ai+1 is −1 instead, there has to be a larger index where the prefix sum becomes 0 again for the prefix sum to go from negative to the final positive total sum. This means that for the remaining elements of the array ai+2…n, the sum of its elements decreases by 1, so we can continue to use the same procedure to split the remaining elements which decrease the sum by 1 and increase the penalty by 1 each time until the sum of elements becomes 0. Hence, the total penalty will be equal to the sum of elements of a.

 **Code**
```cpp
#include <bits/stdc++.h> 
using namespace std;

int t;
int n;
string s;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int sm = 0;
        for (int i = 0; i < n; i++) {
            sm += s[i] == '+' ? 1 : -1;
        }
        cout << abs(sm) << 'n';
    }
}
```
### [1919C - Grouping Increases](../problems/C._Grouping_Increases.md "Hello 2024")

Author: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**Consider a greedy approach.

 **Solution 1**Consider the following approach. We start with empty arrays b and c, then insert elements of the array a one by one to the back of b or c. Our penalty function only depends on adjacent elements, so at any point in time, we only care about the value of the last element of arrays b and c. Suppose we already inserted a1,a2,…,ai−1 into arrays b and c and we now want to insert ai. Let x and y be the last element of arrays b and c respectively (if they are empty, use ∞). Note that swapping arrays b and c does not matter, so without loss of generality, assume that x≤y. We will use the following greedy approach.

 1. If ai≤x, insert ai to the back of the array with a smaller last element.
2. If y<ai, insert ai to the back of the array with a smaller last element.
3. If x<ai≤y, insert ai to the back of the array with a bigger last element.

The proof of why the greedy approach is optimal is given below:

 1. ai≤x. In this case, ai is not greater than the last element of both arrays, so inserting ai to the back of either array will not add additional penalties. However, it is better to insert ai into the array with a smaller last element so that in the future, we can insert a wider range of values into the new array without additional penalty.
2. y<ai. In this case, ai is greater than the last element of both arrays, so inserting ai to the back of either array will contribute to 1 additional penalty. However, it is better to insert ai into the array with a smaller last element so that in the future, we can insert a wider range of values into the new array without additional penalty.
3. x<ai≤y. In this case, if we insert ai to the back of the array with the larger last element, there will not be any additional penalty. However, if we insert ai to the back of the array with the smaller last element, there will be an additional penalty of 1. The former option is always better than the latter. This is because if we consider making the same choices for the remaining elements ai+1 to an in both scenarios, there will be at most one time where the former scenario will add one penalty more than the latter scenario as the former scenario has a smaller last element after inserting ai. After that happens, the back of the arrays in both scenarios will become the same and hence, the former case will never be less optimal.

Following the greedy approach for all 3 cases will result in a correct solution that runs in O(n) time.

 **Hint 1**Consider a dynamic programming approach.

 **Hint 2**Let dpi,v represent the minimum penalty when we are considering splitting a1…i into two subarrays where the last element of one subarray is ai while the last element of the second subarray is v.

 **Hint 3**Speed up the transition by storing the state in a segment tree.

 **Solution 2**Let us consider a dynamic programming solution. Let dpi,v represent the minimum penalty when we are considering splitting a1…i into two subarrays where the last element of one subarray is ai while the last element of the second subarray is v. Then, our transition will be dpi,v=dpi−1,v+[ai−1<ai] for all 1≤v≤n,v≠ai−1 and dpi,ai−1=min(dpi−1,ai−1+[ai−1<ai],min1≤x≤n(dpi−1,x+[x<ai])).

To speed this up, we use a segment tree to store the value of dpi−1,p at position p. To transition to dpi, notice that the first transition is just a range increment on the entire range [1,n] of the segment tree if ai−1<ai. For the second transition, we can do two range minimum queries on ranges [1,ai−1] and [ai,n]. The final time complexity is O(nlogn).

 **Code (Solution 1)**
```cpp
#include <bits/stdc++.h> 
using namespace std;

const int INF = 1000000005;
const int MAXN = 200005;

int t;
int n;
int a[MAXN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int t1 = INF, t2 = INF;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (t1 > t2) {
                swap(t1, t2);
            }
            if (a[i] <= t1) {
                t1 = a[i];
            } else if (a[i] <= t2) {
                t2 = a[i];
            } else {
                t1 = a[i];
                ans++;
            }
        }
        cout << ans << 'n';
    }
}
```
 **Code (Solution 2)**
```cpp
#include <bits/stdc++.h> 
using namespace std;

const int INF = 1000000005;
const int MAXN = 200005;

int t;
int n;
int a[MAXN];

int mn[MAXN * 4], lz[MAXN * 4];
void init(int u = 1, int lo = 1, int hi = n) {
    mn[u] = lz[u] = 0;
    if (lo != hi) {
        int mid = lo + hi >> 1;
        init(u << 1, lo, mid);
        init(u << 1 ^ 1, mid + 1, hi);
    }
}
void propo(int u) {
    if (lz[u] == 0) {
        return;
    }
    lz[u << 1] += lz[u];
    lz[u << 1 ^ 1] += lz[u];
    mn[u << 1] += lz[u];
    mn[u << 1 ^ 1] += lz[u];
    lz[u] = 0;
}
void incre(int s, int e, int x, int u = 1, int lo = 1, int hi = n) {
    if (lo >= s && hi <= e) {
        mn[u] += x;
        lz[u] += x;
        return;
    }
    propo(u);
    int mid = lo + hi >> 1;
    if (s <= mid) {
        incre(s, e, x, u << 1, lo, mid);
    }
    if (e > mid) {
        incre(s, e, x, u << 1 ^ 1, mid + 1, hi);
    }
    mn[u] = min(mn[u << 1], mn[u << 1 ^ 1]);
}
int qmn(int s, int e, int u = 1, int lo = 1, int hi = n) {
    if (s > e) {
        return INF;
    }
    if (lo >= s && hi <= e) {
        return mn[u];
    }
    propo(u);
    int mid = lo + hi >> 1;
    int res = INF;
    if (s <= mid) {
        res = min(res, qmn(s, e, u << 1, lo, mid));
    }
    if (e > mid) {
        res = min(res, qmn(s, e, u << 1 ^ 1, mid + 1, hi));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        init();
        for (int i = 1; i <= n; i++) {
            int ndp = min(qmn(1, a[i] - 1) + 1, qmn(a[i], n));
            if (i > 1) {
                if (a[i - 1] < a[i]) {
                    incre(1, n, 1);
                }
                int dp = qmn(a[i - 1], a[i - 1]);
                if (ndp < dp) {
                    incre(a[i - 1], a[i - 1], ndp - dp);
                }
            }
        }
        cout << qmn(1, n) << 'n';
    }
}
```
 **Bonus**Solve the problem if you have to split the array into k subsequences, where k is given in the input (k=2 for the original problem).

 **Solution**
#### Modified statement

There is an array A of size N and an array T of size K. Initially, Ti=∞ for all 1≤i≤K. For each time t from 1 to N, the following will happen:

 * Select an index 1≤i≤K. If At>Ti, we increase the cost by 1. Then, we set Ti:=At.

Find the minimum possible cost after time N if we select the indices optimally.

#### Greedy

The order of T does not matter. Hence for convenience, we will maintain T in non-decreasing order. At each time t, we will use the following algorithm:

 1. If At>TK, do the operation on index 1.
2. Otherwise, find the smallest index 1≤i≤K where At≤Ti and do the operation on index i.

#### Proof

Suppose there exists an optimal solution that does not follow our algorithm. We will let OTt,i denote the value of Ti before the operation was done at time t in the optimal solution. Let et be the earliest time that the operation done by the optimal solution differs from that of the greedy solution.

 * Case 1: Aet>OTet,K. Since we are maintaining T in the sorted order, having Aet>OTet,K means that Aet is larger than all elements of T. This means that no matter which index i we choose to do the operation on, the cost will always increase by 1. Suppose an index i>1 was chosen in the optimal solution. We can always choose to do the operation on index 1 instead of index i and the answer will not be less optimal. This is because if we let T′ be the array T after the operation was done on index 1, T′p≤OTet+1,p for all 1≤p≤K since T′p={OTet,p+1if p<KAetif p=K while OTet+1,p={OTet,pif p<iOTet,p+1if i≤p<KAetif p=K.
* Case 2: Aet≤OTet,K. For convenience, we will denote that the operation was done on index i in the greedy solution while the operation was done on index j based on the optimal solution during time et.
	+ Case 2A: i<j. In this case, the cost does not increase for both the optimal solution and the greedy solution. However, we can always do an operation on index i instead of index j and the answer will not be less optimal. This is because if we let T′ be the array T after the operation was done on index i, T′p≤OTet+1,p for all 1≤p≤K since T′p={OTet,pif p≠iAetif p=i while OTet+1,p={OTet,pif p<iAetif p=iOTet,p−1if i<p≤jOTet,pif j<p≤K.
	+ Case 2B: i>j. For this case, the cost increases for the optimal solution while the cost does not change for the greedy solution. However, it is not trivial to prove that the greedy solution is more optimal as even though it has a smaller cost, it results in a less optimal array T. Hence, we will prove this case below.

**Case 2B**

We want to come up with a modified solution that does the same operations as the optimal solution for time 1≤t<et and does an operation on index i during time et. Adopting a similar notation to OT, we will let MTt,i denote the value of Ti before the operation was done at time t in this modified solution. Then, MTet+1,p={OTet,pif p≠iAetif p=i and OTet+1,p={OTet,pif p<jOTet,p+1if j≤p<i−1Aetif p=i−1OTet,pif i≤p≤K. Note that in this case, MTet+1,p≤OTet+1,p for all 1≤p≤K, which means that our modified solution results in a less optimal state than the optimal solution. However, since our modified solution requires one less cost up to this point, we will be able to prove that our modified solution will not perform worse than the optimal solution.

Notice that OTet+1,p≤MTet+1,p+1 for all 1≤p<K. We denote that the index that the optimal solution operates on during time t is xt. Let r be the minimum time where et+1≤r≤N and er=N. Due to the above property that OTet+1,p≤MTet+1,p+1 for all 1≤p<K, we can let our modified solution do the operation on index xt+1 for all time et+1≤t<r and the cost will not be more than the optimal solution. This is because the property that OTt+1,p≤MTt+1,p+1 for all 1≤p<K still holds throughout that time range even after each update. Note that if such an r does not exist, we can let our modified solution do the operation on index xt+1 for all time et+1≤t≤K and we completed coming up with the modified solution with a cost not more than the optimal solution.

However, if such an r exists, then at time r, since xr=N, we are no longer able to use the same method. However, let us consider what happens if we let our modified solution do an operation on index 1 during time r. 

If Ar>MTr,K, it will mean that MTr+1,p={MTr,p+1if p<KArif p=K while OTr+1,p={OTr,pif p<KArif p=K since OTr,K−1≤MTr,K<Ar. Even though during this time, it might be possible that the cost of the modified solution increases by 1 while the cost of the optimal solution remains the same, recall that previously during time i our modified solution used one less cost than the optimal solution. As a result, the modified solution will end up having a cost of not more than the optimal solution. At the same time, OTr+1,p≤MTr+1,p for all 1≤p≤K. Hence, for all time r<t≤K, we can let our modified solution do the operation on the same index as the optimal solution xt and the cost of our modified solution will not be more than that of the optimal solution.

On the other hand, suppose Ar≤MTr,K. Let v be the minimum position such that Ar≤MTr,v and let w be the minimum position such that Ar≤OTr,w. Then, MTr+1,p={MTr,p+1if p<v−1Arif p=v−1MTr,pif p≥v and OTr+1,p={OTr,pif p<wArif p=wOTr,p−1if p>w. In the same way, the cost of our modified solution might increase while the cost of the optimal solution stays the same, however, OTr+1,p≤MTr+1,p for all 1≤p≤K. - For p<v−1 and p>w, the condition holds since OTr,p≤MTr,p+1 for all 1≤p<K. Note that v−1≤w because of the same inequality as well. - Suppose v−1=w. Then for p=v−1, OTr+1,p=Ar≤Ar=MTr+1,p. From now on, we suppose v−1≠w - For p=v−1, OTr,v−1≤Ar as w is defined as the minimum position that Ar≤OTr,w and v−1<w. - For v≤p<w, OTr,p≤MTr,p as OTr,p<Ar≤MTr,p - For p=w, Ar≤MTr,w as v is defined as the minimum position that Ar≤MTr,v and v−1<w

Now that we managed to construct a modified solution which follows the greedy algorithm from time 1≤t≤et and is not less optimal than the optimal solution, we can let the optimal solution be our modified solution and find the new et to get a new modified solution. Hence by induction, our greedy solution is optimal.

### [1919D - 01 Tree](../problems/D._01_Tree.md "Hello 2024")

Author: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**What does the distance of two leaves that share the same parent look like?

 **Hint 2**What happens if we delete two leaves that share the same parent?

 **Solution**Consider two leaves that share the same parent. They will be adjacent to each other in the dfs order, so their distances will be adjacent in array a. Furthermore, their distances to the root will differ by exactly 1 since one of the edges from the parent to its children will have weight 0 while the other will have weight 1.

If we delete two leaves that share the same parent, the parent itself will become the leaf. Since one of the edges from the parent to the child has weight 0, the distance from the parent to the root is equal to the smaller distance between its two children. This means that deleting two leaves that share the same parent is the same as selecting an index i such that ai=ai−1+1 or ai=ai+1+1, then removing ai from array a.

Consider the largest value in a. If it is possible to delete it (meaning there is a value that is exactly one smaller than it to its left or right), we can delete it immediately. This is because keeping the largest value will not help to enable future operations as it can only help to delete elements that are 1 greater than it, which is not possible for the largest value.

Now, all we have to do is to maintain all elements that can be deleted and choose the element with the largest value each time. Then, whenever we delete an element, we need to check whether the two adjacent elements become deletable and update accordingly. We can do this using a priority_queue and a linked list in O(nlogn). Note that many other implementations exist, including several O(n) solutions.

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;
int a[MAXN];
int prv[MAXN],nxt[MAXN];
bool in[MAXN];

bool good(int i) {
    if (i < 1 || i > n) {
        return 0;
    }
    return a[prv[i]] == a[i] - 1 || a[nxt[i]] == a[i] - 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        priority_queue<pair<int, int>> pq;
        for (int i = 1; i <= n; i++) {
            prv[i] = i - 1;
            nxt[i] = i + 1;
            in[i] = 0;
            cin >> a[i];
        }
        a[n + 1] = a[0] = -2;
        for (int i = 1; i <= n; i++) {
            if (good(i)) {
                in[i] = 1;
                pq.push({a[i], i});
            }
        }
        while (!pq.empty()) {
            auto [_, i] = pq.top(); pq.pop();
            nxt[prv[i]] = nxt[i];
            prv[nxt[i]] = prv[i];
            if (!in[prv[i]] && good(prv[i])) {
                in[prv[i]]=1;
                pq.push({a[prv[i]], prv[i]});
            }
            if (!in[nxt[i]] && good(nxt[i])) {
                in[nxt[i]]=1;
                pq.push({a[nxt[i]], nxt[i]});
            }
        }
        int mn = n, bad = 0;
        for (int i = 1; i <= n; i++) {
            bad += !in[i];
            mn = min(a[i], mn);
        }
        if (bad == 1 && mn == 0) {
            cout << "YESn";
        } else {
            cout << "NOn";
        }
    }
}
```
### [1919E - Counting Prefixes](../problems/E._Counting_Prefixes.md "Hello 2024")

Author: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**Try solving the problem if the sum of elements of array a is equal to s. If we can do this in O(n) time, we can iterate through all possible values of p1≤s≤pn and sum up the number of ways for each possible sum.

 **Hint 2**Consider starting with array a=[1,1,…,1,−1,−1,…,−1] where there are pn occurences of 1 and pn−s occurrences of −1. Then, try inserting (−1,1) into the array to fix the number of occurrences of prefix sum starting from the largest value (pn) to the smallest value (p1).

 **Solution**Let us try to solve the problem if the sum of elements of array a is equal to s. Consider starting array a=[1,1,…,1,−1,−1,…,−1] where there are pn occurrences of 1 and pn−s occurrences of −1. Notice that when we insert (−1,1) into array a between positions i and i+1 where the sum of a from 1 to i is s, two new prefix sums s−1 and s will be formed while the remaining prefix sums remain the same. Let us try to fix the prefix sums starting from the largest prefix sum to the smallest prefix sum.

In the starting array a, we only have 1 occurrence of prefix sum with value pn. We can insert (−1,1) right after it k times to increase the number of occurrences of prefix sum with value pn by k. In the process of doing so, the number of occurrences of prefix sum with value pn−1 also increased by k. Now, we want to fix the number of occurrences of prefix sum with value pn−1. If we already have x occurrences but we require y>x occurrences, we can choose to insert y−1 pairs of (−1,1) right after any of the x occurrences. We can calculate the number of ways using [stars and bars](https://codeforces.com/https://en.wikipedia.org/wiki/Stars_and_bars_%28combinatorics%29) to obtain the formula (y−1y−x).

We continue using a similar idea to fix the number of occurrences of pn−2,pn−3,…,p1, each time considering the additional occurrences that were contributed from the previous layer. Each layer can be calculated in O(1) time after precomputing binomial coefficients, so the entire calculation to count the number of array a whose sum is s and has prefix sum consistent to the input takes O(n) time. Then, we can iterate through all possible p1≤s≤pn and sum up the answers to obtain a solution that works in O(n2) time.

 **Code**
```cpp
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int INF = 1000000005;
const int MAXN = 200005;
const int MOD = 998244353;

ll fact[MAXN * 2], ifact[MAXN * 2];
int t;
int n;
int f[MAXN * 2], d[MAXN * 2];

inline ll ncr(int n, int r) {
    if (r < 0 || n < r) {
        return 0;
    }
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}
// count number of a_1 + a_2 + ... + a_n = x
inline ll starbar(int n, int x) {
    if (n == 0 && x == 0) {
        return 1;
    }
    return ncr(x + n - 1, x);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i < MAXN * 2; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    ifact[0] = ifact[1] = 1;
    for (int i = 2; i < MAXN * 2; i++) {
        ifact[i] = MOD - MOD / i * ifact[MOD % i] % MOD;
    }
    for (int i = 2; i < MAXN * 2; i++) {
        ifact[i] = ifact[i - 1] * ifact[i] % MOD;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n * 2 + 5; i++) {
            f[i] = 0;
        }
        n++;
        for (int i = 1; i < n; i++) {
            int s; cin >> s;
            f[s + n]++;
        }
        f[n]++;
        int mn = INF, mx = -INF;
        for (int i = 0; i <= 2 * n; i++) {
            if (f[i]) {
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }
        bool bad = 0;
        for (int i = mn; i <= mx; i++) {
            if (!f[i]) {
                bad = 1;
                break;
            }
        }
        if (bad || mn == mx) {
            cout << 0 << 'n';
            continue;
        }
        ll ans = 0;
        for (int x = mx; x >= mn; x--) {
            d[mx - 1] = f[mx] + (mx > n) - (mx == x);
            for (int i = mx - 2; i >= mn - 1; i--) {
                d[i] = f[i + 1] - d[i + 1] + (i >= x) + (i >= n);
            }
            if (d[mn - 1] != 0) {
                continue;
            }
            ll res = 1;
            for (int i = mx - 1; i >= mn; i--) {
                res = res * starbar(d[i], f[i] - d[i]) % MOD;
            }
            ans += res;
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        cout << ans << 'n';
    }
}
```
 **Bonus**Solve the problem in O(n) time.

Unfortunately, it seems like [ARC146E](https://codeforces.com/https://atcoder.jp/contests/arc146/tasks/arc146_e) is identical to this problem :(

### [1919F1 - Wine Factory (Easy Version)](../problems/F1._Wine_Factory_(Easy_Version).md "Hello 2024")

Author: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**When ci and z equals 1018, it means that all the remaining water will always flow into the next water tower. Hence, the answer will be the sum of ai minus the amount of water remaining at tower n after the process.

 **Solution 1**From hint 1, our new task now is to determine the amount of water remaining at tower n after the process. Let vi=ai−bi. The remaining amount of water remaining at tower n is the maximum suffix sum of v, or more formally max1≤k≤n n∑i=kvi. We can use a segment tree where position p of the segment tree stores n∑i=pvi. The updates can be done using range prefix increment and the queries can be done using range maximum.

 **Solution 2**Code ReLU segment tree. A similar method can be used to solve the full problem if you combine even more ReLUs. However, it is not very elegant and is much more complicated than the intended solution below.

 **What is ReLU segment tree?**ReLU is a common activation function used in neural networks which is defined by f(x)=max(x,0). The objective of ReLU segment tree is to compose ReLU-like functions together. More precisely, ReLU segment tree can solve the following problem:

 
> You are given two arrays a and b of length n. You are required to answer the following queries:  
> - 1 p x y. Update ap=x and bp=y.  
> - 2 l r c. Output the value of fl(fl+1(…fr−1(fr(c)))), where fi(x)=max(x−ai,bi).

The main idea to solve the problem is to observe that composing ReLU functions still results in a ReLU function, so we just need to store in each node the resultant function f(x)=max(x−p,q) after composing the functions that fall in the range of the segment tree node. For the merge function, we just need to figure out the details of composing two ReLU functions together.

 **Code (Solution 1)**
```cpp
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const ll LINF = 1000000000000000005;
const int MAXN = 500005;

int n, q;
int a[MAXN], b[MAXN];
ll c[MAXN];
ll v[MAXN], sv[MAXN];

ll mx[MAXN * 4], lz[MAXN * 4];
void init(int u = 1, int lo = 1, int hi = n) {
    lz[u] = 0;
    if (lo == hi) {
        mx[u] = sv[lo];
    } else {
        int mid = lo + hi >> 1;
        init(u << 1, lo, mid);
        init(u << 1 ^ 1, mid + 1, hi);
        mx[u] = max(mx[u << 1], mx[u << 1 ^ 1]);
    }
}
void propo(int u) {
    if (lz[u] == 0) {
        return;
    }
    lz[u << 1] += lz[u];
    lz[u << 1 ^ 1] += lz[u];
    mx[u << 1] += lz[u];
    mx[u << 1 ^ 1] += lz[u];
    lz[u] = 0;
}
void incre(int s, int e, ll x, int u = 1, int lo = 1, int hi = n) {
    if (lo >= s && hi <= e) {
        mx[u] += x;
        lz[u] += x;
        return;
    }
    propo(u);
    int mid = lo + hi >> 1;
    if (s <= mid) {
        incre(s, e, x, u << 1, lo, mid);
    }
    if (e > mid) {
        incre(s, e, x, u << 1 ^ 1, mid + 1, hi);
    }
    mx[u] = max(mx[u << 1], mx[u << 1 ^ 1]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> c[i];
    }
    ll sma = 0;
    for (int i = n; i >= 1; i--) {
        v[i] = a[i] - b[i];
        sv[i] = v[i] + sv[i + 1];
        sma += a[i];
    }
    init();
    while (q--) {
        int p, x, y; ll z; cin >> p >> x >> y >> z;
        sma -= a[p];
        incre(1, p, -v[p]);
        a[p] = x;
        b[p] = y;
        v[p] = a[p] - b[p];
        sma += a[p];
        incre(1, p, v[p]);
        cout << sma - max(0ll, mx[1]) << 'n';
    }
}
```
### [1919F2 - Wine Factory (Hard Version)](../problems/F2._Wine_Factory_(Hard_Version).md "Hello 2024")

Author: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**Try modelling this problem into a maximum flow problem.

 **Hint 2**Try using minimum cut to find the maximum flow.

 **Hint 3**Speed up finding the minimum cut using a segment tree.

 **Solution**Consider a flow graph with n+2 vertices. Let the source vertex be s=n+1 and the sink vertex be t=n+2. For each i from 1 to n, add edge s→i with capacity ai and another edge i→t with capacity bi. Then for each i from 1 to n−1, add edge i→i+1 with capacity ci. The maximum flow from s to t will be the answer to the problem.

Let us try to find the minimum cut of the above graph instead.

**Claim**: The minimum cut will contain exactly one of s→i or i→t for all 1≤i≤n.

*Proof*: If the minimum cut does not contain both s→i and i→t, s can reach t through vertex i and hence it is not a minimum cut. Now, we will prove why the minimum cut cannot contain both s→i and i→t. Suppose there exists a minimum cut where there exists a vertex 1≤i≤n where s→i and i→t are both in the minimum cut. We will consider two cases:

 * Case 1: s can reach i (through some sequence of vertices s→j→j+1→…→i where j<i). If our minimum cut only contains i→t without s→i, nothing changes as s was already able to reach i when s→i was removed. Hence, s will still be unable to reach t and we found a minimum cut that has equal or smaller cost.
* Case 2: s cannot reach i. If our minimum cut only contains s→i without i→t, nothing changes as s is still unable to reach i, so we cannot make use of the edge i→t to reach t from s. Hence, s will still be unable to reach t and we found a minimum cut that has equal or smaller cost.

Now, all we have to do is select for each 1≤i≤n, whether to cut the edge s→i or the edge i→t. Let us use a string x consisting of characters A and B to represent this. xi=A means we decide to cut the edge s→i for a cost of ai and xi=B means we decide to cut the edge from i→t for a cost of bi. Notice that whenever we have xi=B and xi+1=A, s can reach t through s→i→i+1→t. To prevent this, we have to cut the edge i→i+1 for a cost of ci.

To handle updates, we can use a segment tree. Each node of the segment tree stores the minimum possible cost for each of the four combinations of the two endpoints being A or B. When merging the segment tree nodes, add a cost of c when the right endpoint of the left node is B and the left endpoint of the right node is A. The final time complexity is O(nlogn) as only a segment tree is used.

 **Code**
```cpp
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const ll LINF = 1000000000000000005ll;
const int MAXN = 500005;

int n, q;
int a[MAXN], b[MAXN];
ll c[MAXN];

ll st[MAXN * 4][2][2];
void merge(int u, int lo, int hi) {
    int mid = lo + hi >> 1, lc = u << 1, rc = u << 1 ^ 1;
    for (int l = 0; l < 2; l++) {
        for (int r = 0; r < 2; r++) {
            st[u][l][r] = min({st[lc][l][0] + st[rc][0][r],
                    st[lc][l][1] + st[rc][1][r],
                    st[lc][l][0] + st[rc][1][r],
                    st[lc][l][1] + st[rc][0][r] + c[mid]});
        }
    }
}
void init(int u = 1, int lo = 1, int hi = n) {
    if (lo == hi) {
        st[u][0][0] = a[lo];
        st[u][1][1] = b[lo];
        st[u][1][0] = st[u][0][1] = LINF;
        return;
    }
    int mid = lo + hi >> 1, lc = u << 1, rc = u << 1 ^ 1;
    init(lc, lo, mid);
    init(rc, mid + 1, hi);
    merge(u, lo, hi);
}
void upd(int p, int u = 1, int lo = 1, int hi = n) {
    if (lo == hi) {
        st[u][0][0] = a[lo];
        st[u][1][1] = b[lo];
        st[u][1][0] = st[u][0][1] = LINF;
        return;
    }
    int mid = lo + hi >> 1, lc = u << 1, rc = u << 1 ^ 1;
    if (p <= mid) {
        upd(p, lc, lo, mid);
    } else {
        upd(p, rc, mid + 1, hi);
    }
    merge(u, lo, hi);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> c[i];
    }
    init();
    while (q--) {
        int p, x, y; ll z; cin >> p >> x >> y >> z;
        a[p] = x; b[p] = y; c[p] = z;
        upd(p);
        cout << min({st[1][0][0], st[1][0][1], st[1][1][0], st[1][1][1]}) << 'n';
    }
}
```
### [1919G - Tree LGM](../problems/G._Tree_LGM.md "Hello 2024")

Author: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**Think about how you would construct matrix s if you were given the tree.

 **Hint 2**If si,i=0, what should the value of sj,i be for all 1≤j≤n?

 **Hint 3**For some i where si,i=1, let Z be a set containing all the vertices j where sj,i=0. More formally, Z={j | 1≤j≤n and sj,i=0}. Does Z have any special properties?

 **Hint 4**Using hint 3, can we break down the problem into smaller sub-problems?

 **Hint 5**Try solving the problem if the values in each column are a constant. In other words, si,j=sj,j for all 1≤i≤n and 1≤j≤n.

 **Solution**Let us consider how we can code the checker for this problem. In other words, if we are given a tree, how can we construct matrix s? We can solve this using dynamic programming. si,j=1 if and only if at least one child c of vertex j (when the tree is rooted at vertex i) has si,c=0. This is because the player can move the coin from vertex j to vertex c which will cause the opponent to be in a losing state.

For convenience, we will call a vertex i special if there exists some 1≤j≤n where sj,i≠si,i. Suppose there exist some i where si,i=0. This means that moving the coin to any of the neighbours of i results in a winning state for the opponent. If the tree was rooted at some other vertex j≠i, it will still be a losing state as it reduces the options that the player can move the coin to, so sj,i should be 0 for all 1≤j≤n. This means that special vertices must have si,i=1

Now, let us take a look at special vertices. Let x be a special vertex, meaning sx,x=1 and there exist some j where sj,x=0. Let Z be a set containing all the vertices j where sj,x=0. More formally, Z={j | 1≤j≤n and sj,x=0}. Z cannot be empty due to the property of special vertices. Notice that whenever we choose to root at some vertex j≠x, the number of children of x decreases by exactly 1. This is because the neighbour that lies on the path from vertex x to vertex j becomes the parent of x instead of the child of x. If rooting the tree at vertex x is a winning state but rooting the tree at some other vertex j results in a losing state instead, it means that the only winning move is to move the coin from vertex x to the neighbour that is on the path from vertex x to j.

Let y denote the only neighbour of vertex x where we can move the coin from vertex x to vertex y and win. In other words, y is the neighbour of vertex x where y lies on the path of the vertices in set Z and x. This means that Z is the set of vertices that are in the subtree of y rooted at vertex x.

Now, let us try to find vertex y. Notice that sy,y=1. This is because sy,x=0, so the coin can be moved from vertex y to vertex x to result in a losing state for the opponent. Furthermore, sj,y=0 if and only if j is not in Z, otherwise sj,y=1. This is because sx,y=0 since moving the coin from vertex x to vertex y is a winning move for the first player. For all other vertex u∈Z that is not y, this property will not hold as even if su,u=1 and sx,u=0, sy,u will be equal to 0 as well as the tree being rooted at x has the same effect as if it was rooted at y. Since y∈Z, sy,u=0 does not satisfy sj,u=1 for all j in Z.

Since y is a neighbour of vertex x, we know that there is an edge between vertex y and x. Furthermore, we know that if the edge between vertex y and x is removed, the set of vertices Z forms a single connected component containing y, while the set of vertices not in Z forms another connected component containing x. This means that we can recursively solve the problem for the two connected components to check whether the values in the matrix s are valid within their components.

After recursively solving for each connected component, we are only left with non-special vertices (sj,i=si,i for all 1≤j≤n) and some special vertices that already have an edge that connects to outside the component. Non-special vertices with si,i=1 has to be connected to at least 2 non-special vertices with si,i=0. The most optimal way to do this is to form a line 0 — 1 — 0 — 1 — 0 as it requires the least amount of si,i=0. If there is not enough si,i=0 to form the line, a solution does not exist. Otherwise, connect the left-over si,i=0 to any of si,i=1. On the other hand, special vertices can either be connected to nothing, connected to other special vertices, or connected to non-special vertices with si,i=1.

For the final step, we need to check whether si,j is consistent when i and j are in different components (i.e. (i∈Z and j∉Z) or (i∉Z and j∈Z)). Notice that si,j=sx,j for all i∈Z and j∉Z and j≠x, and si,j=sy,j for all i∉Z and j∈Z and j≠y. From the steps above, we managed to account for every value in the matrix, hence if matrix s is consistent through all the steps, the constructed tree would be valid as well.

We can make use of xor hash to find vertex x together with its corresponding vertex y. With xor hash, the time complexity is O(n2). Well-optimised bitset code with time complexity of O(n3w) can pass as well.

 **Code**
```cpp
#include <bits/stdc++.h> 
using namespace std;
 
const int MAXN = 5005;

mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
int n;
unsigned long long r[MAXN], hsh[MAXN], totr;
string s[MAXN];
vector<pair<int, int>> ans;
 
bool done[MAXN];
bool solve(vector<int> grp) {
    int pr = -1, pl = -1;
    vector<int> lft, rht;
    for (int i : grp) {
        if (s[i][i] == '0' || done[i] || hsh[i] == totr) {
            continue;
        }
        rht.clear();
        for (int j : grp) {
            if (s[j][i] == '0') {
                lft.push_back(j);
            } else {
                rht.push_back(j);
            }
        }
        if (!lft.empty()) {
            pr = i;
            break;
        }
    }
    if (pr == -1) {
        vector<int> dv, zero, one;
        for (int i : grp) {
            if (done[i]) {
                dv.push_back(i);
            } else if (s[i][i] == '0') {
                zero.push_back(i);
            } else {
                one.push_back(i);
            }
        }
        for (int i = 1; i < dv.size(); i++) {
            ans.push_back({dv[i - 1], dv[i]});
        }
        if (one.empty() && zero.empty()) {
            return 1;
        }
        if (one.size() >= zero.size()) {
            return 0;
        }
        if (one.empty()) {
            if (zero.size() >= 2 || !dv.empty()) {
                return 0;
            }
            return 1;
        }
        for (int i = 0; i < one.size(); i++) {
            ans.push_back({zero[i], one[i]});
            ans.push_back({one[i], zero[i + 1]});
        }
        for (int i = one.size() + 1; i < zero.size(); i++) {
            ans.push_back({one[0], zero[i]});
        }
        if (!dv.empty()) {
            ans.push_back({one[0], dv[0]});
        }
        return 1;
    }
    for (int i : lft) {
        if (s[i][i] == '0' || done[i] || ((hsh[i] ^ hsh[pr]) != totr)) {
            continue;
        }
        vector<int> trht;
        for (int j : grp) {
            if (s[j][i] == '0') {
                trht.push_back(j);
            }
        }
        if (trht == rht) {
            pl = i;
            break;
        }
    }
    if (pl == -1) {
        return 0;
    }
    for (int i : lft) {
        for (int j : rht) {
            if (j == pr) {
                continue;
            }
            if (s[i][j] != s[pr][j]) {
                return 0;
            }
        }
    }
    for (int i : rht) {
        for (int j : lft) {
            if (j == pl) {
                continue;
            }
            if (s[i][j] != s[pl][j]) {
                return 0;
            }
        }
    }
    ans.push_back({pl, pr});
    done[pl] = done[pr] = 1;
    return solve(lft) && solve(rht);
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        r[i] = rnd();
        totr ^= r[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') {
                hsh[j] ^= r[i];
            }
        }
    }
    bool pos = 1;
    for (int i = 0; i < n; i++) {
        if (s[i][i] == '1') {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (s[j][i] == '1') {
                pos = 0;
                break;
            }
        }
    }
    if (!pos) {
        cout << "NOn";
        return 0;
    }
    vector<int> v(n, 0);
    iota(v.begin(), v.end(), 0);
    if (!solve(v)) {
        cout << "NOn";
        return 0;
    }
    cout << "YESn";
    for (auto [u, v] : ans) {
        cout << u + 1 << ' ' << v + 1 << 'n';
    }
}
```
### [1919H - Tree Diameter](../problems/H._Tree_Diameter.md "Hello 2024")

Author: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")  
Full solution: [dario2994](https://codeforces.com/profile/dario2994 "International Grandmaster dario2994")

 **Background**The original problem allowed 5n type 1 queries and n type 2 queries and was used as the last problem of a Div. 2 round. When we opened the round for testing, [dario2994](https://codeforces.com/profile/dario2994 "International Grandmaster dario2994") solved the problem using 2n type 1 queries, and a few days later, he managed to improve his solution to use only n type 1 queries. This was what made us decide to change this round into a Div. 1 round instead of a Div. 2 round.

![Dario discord chat](images/7e0f6109355289bb3b62a92326171992b995552f.png)

 **Hint 1**Try rooting the tree at an **edge**.

 **Hint 2**Use n−2 of query 2 to find the distance of every edge to the root. For convenience, we will call the distance of an edge to the root the depth of the edge.

 **Hint 3**We start with only the root edge, then add edges of depth 0, followed by depth 1,2,…

 **Hint 4**If we want to add a new edge with depth i, we need to attach it to one of the edges with depth i−1. We can let the weight of the edge we want to attach be 109 to force the diameter to pass through it, then let the edges of depth i−1 have weights be different multiples of n. This way, we can determine which edges of depth i−1 are used in the diameter (unless the two largest edges are used).

 **Hint 5**Make use of isomorphism to handle the case in hint 4 where the largest two edges are used.

 **Hint 6**If isomorphism cannot be used, find a leaf edge of a lower depth than the query edge and force the diameter to pass through the leaf edge and the query edge. Then, only 1 edge of depth i−1 will be used and the edge weights for edges of depth i−1 can follow a similar structure as hint 4.

 **Solution**We will root the tree at edge 1. Then, use n−2 of query 2 to find the distance of every edge to the root. For convenience, we will call the distance of an edge to the root the depth of the edge. Our objective is to add the edges in increasing order of depth, so when we are inserting an edge of depth i, all edges of depth i−1 are already inserted and we just have to figure out which edge of depth i−1 we have to attach the edge of depth i to.

For convenience, the edge weights used in query 1 will be 1 by default unless otherwise stated. Let ci store the list of edges with depth i. Suppose we want to insert edge u into the tree and the depth of edge u is d. We let the weight of the edge u be 109 and the weight of edges in cd−1 be n,2n,3n,…,(|cd−1|−2)n,(|cd−1|−1)n,(|cd−1|−1)n. The diameter will pass through edge u, the parent edge of u, as well as one edge of weight (|cd−1|−1)n. If we calculate ⌊diameter−109n⌋−(|cd−1|−1), we will be able to tell the index of the parent edge of u.

However, there is one exception. When the parent edge of u is one of the last 2 edges of cd−1, we are unable to differentiate between the two of them as they have the same weight. This is not a problem if the last 2 edges are isomorphic to each other, as attaching u to either parent results in the same tree. For now, we will assume that the last 2 edges of cd−1 are isomorphic to each other.

However, after attaching edge u to one last 2 edges in cd−1, they are no longer isomorphic. Hence, we need to use a different method to insert the remaining edges of depth d. Let the new edge that we want to insert be v. Let the weight of edges u and v be 109 and the weights of edges in cd−1 be the same as before. Now, we can use ⌊diameter−2⋅109n⌋ to determine whether edge v share the same parent as u, and if it does not share the same parent, it can still determine the index of the parent edge of v. With the additional information of whether edge v shares the same parent as edge u, we will be able to differentiate the last 2 edges of cd−1 from each other.

Now, we just need to handle the issue where the last 2 edges of cd−1 are not isomorphic. When we only have the root edge at the start, the left and right ends of the edge are isomorphic (note that for the root edge, we consider it as 2 separate edges, one with the left endpoint and one with the right endpoint). We try to maintain the isomorphism as we add edges of increasing depth. Suppose the last two edges of cd−1 are isomorphic. Let the two edges be a and b. Then, we insert edges of depth d using the above method. Let the child edges attached to a and b be represented by sets Sa and Sb respectively. If either Sa or Sb has sizes at least 2, the two edges in the same set will be isomorphic, so we can let those 2 edges be the last 2 edges of cd. Now, the sizes of Sa and Sb are both strictly smaller than 2. If the sizes of both sets are exactly 1, the two edges from each set will be isomorphic as well as a and b are isomorphic. Now, the only case left is if at least one of the sets is empty.

Without loss of generality, assume that Sa is empty. Since it is no longer possible to maintain two isomorphic edges, we now change our objective to find a leaf (it will be clear why in the following paragraphs). If Sb is empty as well, both a and b are leaves so we can choose any one of them. If Sb is not empty, then a and b are no longer isomorphic due to their children. This means that we cannot simply use b as the leaf Sa might be children of b instead of a as we did not differentiate a and b in the previous paragraphs. To determine whether Sa belongs to a or b, we can make use of one type 2 query to find the distance between one of the edges in Sa and a. If the distance is 0, it means that Sa belongs to a. Otherwise, the distance will be 1 and Sa belongs to b.

Now that we found a leaf, we can use the following method to insert an edge u of depth d. We let the weight of the edge u and the leaf edge be 109 and the weight of edges in cd−1 be n,2n,3n,…,(|cd−1|−2)n,(|cd−1|−1)n,|cd−1|n. The diameter will pass through edge u, the leaf edge, and only one edge of depth d−1 which is the parent edge of u. Hence, after finding a leaf edge, we can uniquely determine the parent edge from ⌊diameter−2⋅109n⌋.

We used n−2 type 1 queries and n−1 type 2 queries in total. This is because we used a single type 1 query for each non-root edge. We used n−2 type 2 queries at the start, and we only used 1 additional type 2 query when we were no longer able to maintain two isomorphic edges and changed our methodology to use a leaf edge instead.

 **Code**
```cpp
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int INF = 1000000000;
const int MAXN = 1000;

int n;
int lvl[MAXN + 5];
int pe[MAXN + 5];
vector<int> ch[MAXN + 5];

ll query(vector<int> a) {
    cout << "? 1";
    for (int i = 1; i < n; i++) {
        cout << ' ' << a[i];
    }
    cout << endl;
    ll res; cin >> res;
    return res;
}
int query(int a, int b) {
    cout << "? 2 " << a << ' ' << b << endl;
    int res; cin >> res;
    return res;
}

int main() {
    cin >> n;
    for (int i = 2; i < n; i++) {
        lvl[i] = query(1, i);
    }
    int ptr = 3;
    vector<int> base = {1, 2};
    pe[1] = pe[2] = 1;
    bool iso = 1;
    int piv = -1;
    for (int l = 0; l < n; l++) {
        vector<int> a(n, 1);
        int m = base.size();
        for (int i = 0; i < m; i++) {
            a[pe[base[i]]] = min(i + 1, m - iso) * MAXN;
        }
        if (!iso) {
            a[pe[piv]] = INF;
        }
        bool ciso = 0;
        for (int u = 2; u < n; u++) {
            if (lvl[u] != l) {
                continue;
            }
            a[u] = INF;
            ll res = query(a) - INF;
            a[u] = 1;
            if (!iso || ciso) {
                res -= INF;
            }
            int id = res / MAXN;
            if (iso && l) {
                id -= m - 1;
            }
            int v = ptr++;
            pe[v] = u;
            if (ciso) {
                if ((l == 0 && id == 0) || id == -(m - 1)) {
                    ch[base[m - 2]].push_back(v);
                } else if (id == m - 1) {
                    ch[base[m - 1]].push_back(v);
                } else {
                    ch[base[id - 1]].push_back(v);
                }
            } else if (iso && id == m - 1) {
                ch[base[m - 2]].push_back(v);
                ciso = 1;
                a[u] = INF;
            } else {
                ch[base[id - 1]].push_back(v);
            }
        }
        if (m >= 2 && ch[base[m - 2]].size() > ch[base[m - 1]].size()) {
            swap(base[m - 2], base[m - 1]);
        }
        vector<int> nbase;
        for (int i = 0; i < m; i++) {
            for (int j : ch[base[i]]) {
                nbase.push_back(j);
            }
        }
        if (!iso || ch[base[m - 1]].size() >= 2 || ch[base[m - 2]].size() == 1) {
            base = nbase;
            continue;
        }
        if (ch[base[m - 1]].empty()) {
            piv = base[m - 1];
        } else {
            ll res = query(pe[ch[base[m - 1]][0]], pe[base[m - 1]]);
            if (res) {
                swap(base[m - 2], base[m - 1]);
                swap(ch[base[m - 2]], ch[base[m - 1]]);
            }
            piv = base[m - 2];
        }
        iso = 0;
        base = nbase;
    }
    cout << '!' << endl;
    cout << 1 << ' ' << 2 << endl;
    for (int u = 1; u <= n; u++) {
        for (int v : ch[u]) {
            cout << u << ' ' << v << endl;
        }
    }
}
```
