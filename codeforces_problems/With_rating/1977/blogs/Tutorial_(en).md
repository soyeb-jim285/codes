# Tutorial_(en)

We hope you enjoyed the problems.

Problem [1977A - Little Nikita](../problems/A._Little_Nikita.md "Codeforces Round 948 (Div. 2)") was created by [Stefan2417](https://codeforces.com/profile/Stefan2417 "Master Stefan2417") and prepared by [alexchist](https://codeforces.com/profile/alexchist "Master alexchist").

Problem [1977B - Binary Colouring](../problems/B._Binary_Colouring.md "Codeforces Round 948 (Div. 2)") was created by [alexchist](https://codeforces.com/profile/alexchist "Master alexchist") and prepared by [Stefan2417](https://codeforces.com/profile/Stefan2417 "Master Stefan2417").

Problem [1977C - Nikita and LCM](../problems/C._Nikita_and_LCM.md "Codeforces Round 948 (Div. 2)") was created and prepared by [Stefan2417](https://codeforces.com/profile/Stefan2417 "Master Stefan2417").

Problem [1977D - XORificator](../problems/D._XORificator.md "Codeforces Round 948 (Div. 2)") was created and prepared by [alexchist](https://codeforces.com/profile/alexchist "Master alexchist").

Problem [1977E - Tensor](../problems/E._Tensor.md "Codeforces Round 948 (Div. 2)") was created and prepared by [Stefan2417](https://codeforces.com/profile/Stefan2417 "Master Stefan2417").

[1977A - Little Nikita](../problems/A._Little_Nikita.md "Codeforces Round 948 (Div. 2)")

 **Tutorial**Note that one action with the cube changes the parity of the number of cubes in the tower. Therefore, if the parities of n and m do not match, it is impossible to build the tower. Also, if n<m, the tower cannot be built either. In all other cases, it is possible to build a tower of height m in m operations, and then add and remove a cube until the operations are exhausted.

 **Author's code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    cout << (n >= m && (n%2) == (m%2) ? "Yes" : "No") << 'n';
  }
}
```
 **Feedback*** Good problem 


[*82*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*146*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*12*](https://codeforces.com/data/like?action=like "I like this")
[1977B - Binary Colouring](../problems/B._Binary_Colouring.md "Codeforces Round 948 (Div. 2)")

 **Tutorial**We will iterate over the prefix of i bits and construct a correct answer for the number formed by the prefix bits of the number x. We are interested in considering only the one bits, as they are the only ones that affect the value of the number x.

If we have already placed a one at position i in the answer, we need to somehow add 2i to the number. To do this, we simply zero out the i-th bit in the answer and set it at i+1 — this will add 2⋅2i=2i+1.

Now, the i-th position in the answer holds 0.

Let's consider what we placed at position i−1 in the answer. If it's 0, then everything is fine; we just place 1 at position i. If it's 1, we have a situation of [1 1], which we correct by making it [-1 0 1] — placing −1 at i−1, leaving 0 at i, and placing 1 at i+1. This will add 2i to the sum because 2i+2i−1=2i+1−2i−1. The remaining case is when i−1 holds −1, but this is impossible because our forward operations only place ones, and −1 is placed behind.

The final time complexity is O(log(x)) per test case.

 **Author's code**
```cpp
#include "bits/stdc++.h"

#define all(a) a.begin(), a.end()
#define pb push_back
typedef long long ll;
using namespace std;
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
 
/// Actual code starts here
const int N = 100005;
 
void solve() {
    ll x;
    cin >> x;
    vector<int> res(31, 0);
    for (int i = 0; i < 30; i++) {
        if (1ll & (x >> i)) {
            if (res[i]) {
                res[i + 1] = 1;
                res[i] = 0;
            } else if (i > 0) {
                if (res[i - 1] == 1) {
                    res[i + 1] = 1;
                    res[i - 1] = -1;
                } else {
                    res[i] = 1;
                }
            } else if (i == 0) {
                res[i] = 1;
            }
        }
    }
    cout << 31 << 'n';
    for (int i = 0; i <= 30; i++) {
        cout << res[i] << ' ';
    }
    cout << 'n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
}

```
 **Feedback*** Good problem 

 
[*309*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*24*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*180*](https://codeforces.com/data/like?action=like "I like this")
[1977C - Nikita and LCM](../problems/C._Nikita_and_LCM.md "Codeforces Round 948 (Div. 2)")

 **Hint**Try to check if the entire array a can be the answer.

 **Tutorial**First, let's understand if we can take the entire array a as the special subsequence.

To do this, find the LCM(a1,a2,…,an). If it is greater than max(a1,a2,…,an), then obviously such a number is not in the subsequence, because LCM≥max.

After this check, it becomes known that each ai | max(a1,a2,…,an).

Then we iterate over the divisors of the maximum and greedily check for the presence of a subsequence with such an LCM.

If we do this naively, it will be O(√C+n⋅d(C)⋅log(C)), but this is already sufficient.

Note that we can count the occurrence of each number and check only the distinct numbers. Then the complexity will be O(√C+d(C)2⋅log(C)).

 **Author's code**
```cpp
#include "bits/stdc++.h"
 
#define err(x) cerr << "["#x"]  " << (x) << "n"
#define errv(x) {cerr << "["#x"]  ["; for (const auto& ___ : (x)) cerr << ___ << ", "; cerr << "]n";}
#define errvn(x, n) {cerr << "["#x"]  ["; for (auto ___ = 0; ___ < (n); ++___) cerr << (x)[___] << ", "; cerr << "]n";}
#define all(a) a.begin(), a.end()
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD = 1000000007;
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
 
template<typename T1, typename T2>
inline bool relaxmi(T1 &a, const T2 &b) {
    return a > b ? a = b, true : false;
}
 
template<typename T1, typename T2>
inline bool relaxma(T1 &a, const T2 &b) {
    return a < b ? a = b, true : false;
}
 
double GetTime() { return clock() / (double) CLOCKS_PER_SEC; }
 
/// Actual code starts here
const int N = 100005;
 
int calc(vector<pair<int, int>> &t, int d) {
    int LCM = 0, cnt = 0;
    for (auto [j, c]: t) {
        if (d % j == 0) {
            if (LCM == 0) LCM = j;
            else LCM = lcm(LCM, j);
            cnt += c;
        }
    }
    if (LCM != d) cnt = 0;
    return cnt;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) cin >> i;
    ll LCM = 1;
    int mx = *max_element(all(v));
    for (auto i: v) {
        LCM = lcm(LCM, i);
        if (LCM > mx) {
            cout << n << 'n';
            return;
        }
    }
    map<int, int> cnt;
    for (auto i: v) cnt[i]++;
    vector<pair<int, int>> t;
    for (auto i: cnt)
        t.push_back(i);
    int res = 0;
    for (int i = 1; i * i <= mx; i++) {
        if (mx % i == 0) {
            if (!cnt.contains(i))
                relaxma(res, calc(t, i));
            if (!cnt.contains(mx / i))
                relaxma(res, calc(t, mx / i));
        }
    }
    cout << res << 'n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
}

```
 **Feedback*** Good problem 

 
[*337*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*19*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*94*](https://codeforces.com/data/like?action=like "I like this")
[1977D - XORificator](../problems/D._XORificator.md "Codeforces Round 948 (Div. 2)")

 **Hint**Try to fix the specialty of column i and the presence of a one in cell i,j.

 **Tutorial**Let's assume that the value in the i-th row and j-th column is strictly one and it is the only one in the column. 

Then the entire table is uniquely determined, as well as the XORificator. For each possible state of the XORificator that constructs the required table, 

Let's maintain a counter. Then the state that maximizes the number of columns with exactly one 1 has the maximum counter. 

To efficiently maintain the counter, it is necessary to maintain the hash of the XORificator and quickly recalculate it when moving to the next row.

The answer can be easily reconstructed by traversing the table again and counting the hash. If the desired hash is obtained, simply output the state of the XORificator.

The final time complexity is O(nmlog(nm)) or O(nm) if a hash map is used.

For hashing, it is convenient to use [Zobrist hashing](https://codeforces.com/https://en.wikipedia.org/wiki/Zobrist_hashing).

 **Author's code**
```cpp
#include "bits/stdc++.h"
 
using namespace std;
 
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> table(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            table[i][j] = c - '0';
        }
    }
    vector<long long> rands(n), rands2(n);
    for (int i = 0; i < n; ++i) {
        rands[i] = rnd();
        rands2[i] = rnd();
    }
    map<pair<long long, long long>, int> ans;
    int res = 0;
    pair<int, int> ind_ans = {0, 0};
    for (int j = 0; j < m; ++j) {
        long long summ = 0, summ2 = 0;
        for (int i = 0; i < n; ++i) {
            if (table[i][j]) {
                summ ^= rands[i];
                summ2 ^= rands2[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            summ ^= rands[i];
            summ2 ^= rands2[i];
            ans[{summ, summ2}]++;
            if (res < ans[{summ, summ2}]) {
                res = ans[{summ, summ2}];
                ind_ans = {j, i};
            }
            summ ^= rands[i];
            summ2 ^= rands2[i];
        }
    }
    cout << res << "n";
    string inds(n, '0');
    for (int i = 0; i < n; ++i) {
        if (table[i][ind_ans.first]) {
            if (i != ind_ans.second) {
                inds[i] = '1';
            }
        } else if (ind_ans.second == i) {
            inds[i] = '1';
        }
    }
    cout << inds << "n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
```
 **Feedback*** Good problem 

 
[*103*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*11*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*19*](https://codeforces.com/data/like?action=like "I like this")
[1977E - Tensor](../problems/E._Tensor.md "Codeforces Round 948 (Div. 2)")

 **Tutorial**First, let's understand why 2 colors are indeed sufficient.

Notice that the reachability relation in a graph defines a [Partially Ordered Set](https://codeforces.com/https://en.wikipedia.org/wiki/Partially_ordered_set).

According to [Dilworth's Theorem](https://codeforces.com/https://en.wikipedia.org/wiki/Dilworth%27s_theorem), the size of the maximum antichain is equal to the minimum number of chains that cover the Partially Ordered Set.

Note that the condition on the reachability of pairs of vertices within any triplet implies a constraint on the maximum size of the antichain. It is simply no more than 2. Therefore, 2 colors are indeed sufficient.

The remaining task is to understand how to explicitly construct these 2 chains.

We will build this inductively. Let's maintain 3 stacks — the last vertices painted in black, white, and red respectively. These will correspond to the chains we are building.

Suppose we have built chains on n vertices and want to build them on n+1:

 * If the white or black stacks are empty, simply add vertex n+1 to the empty stack.
* If the red stack is empty:
* + Ask about the reachability of the last vertices in the white and black stacks from vertex n+1.
* + If both vertices are reachable, put vertex n+1 in the red stack.
* + If only one vertex is reachable, put vertex n+1 in the stack whose last vertex is reachable from n+1.
* + The case where neither vertex is reachable is impossible as it contradicts the condition.
* If the red stack is not empty:
* + Ask about the reachability of the last vertex in the red stack from vertex n+1.
* + If it is reachable, put it in the red stack.
* + If it is not reachable, ask about the end of the white stack.
* + If the vertex at the end of the white stack is not reachable, then the vertex at the end of the black stack must be reachable, otherwise, it contradicts the problem's condition.
* + Color vertex n+1 black if the black vertex is reachable or white if the white vertex is reachable.
* + Recolor all vertices in the red stack to the opposite color relative to vertex n+1. We can do this because, by construction, all vertices in the white and black stacks are reachable from all vertices in the red stack.
* + Do not forget to clear the red stack.

Each time a new vertex is added, no more than 2 queries are used. Therefore, we will use no more than 2⋅n queries in total.

During the algorithm, all operations are performed in O(1) time, resulting in an overall complexity of O(n).

As an exercise for the reader, try to prove the lower bound on the number of queries.

 **Author's code**
```cpp
#include "bits/stdc++.h"
 
#define err(x) cerr << "["#x"]  " << (x) << "n"
#define errv(x) {cerr << "["#x"]  ["; for (const auto& ___ : (x)) cerr << ___ << ", "; cerr << "]n";}
#define errvn(x, n) {cerr << "["#x"]  ["; for (auto ___ = 0; ___ < (n); ++___) cerr << (x)[___] << ", "; cerr << "]n";}
#define all(a) a.begin(), a.end()
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD = 1000000007;
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
 
template<typename T1, typename T2>
inline bool relaxmi(T1 &a, const T2 &b) {
    return a > b ? a = b, true : false;
}
 
template<typename T1, typename T2>
inline bool relaxma(T1 &a, const T2 &b) {
    return a < b ? a = b, true : false;
}
 
double GetTime() { return clock() / (double) CLOCKS_PER_SEC; }
 
/// Actual code starts here
const int N = 100005;
 
bool ask(int i, int j) {
    cout << "? " << j << ' ' << i << endl;
    string resp;
    cin >> resp;
    if (resp == "-1") assert(false);
    if (resp == "YES") return true;
    else return false;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> st, st2, st3;
    st = {1};
    for (int i = 2; i <= n; i++) {
        if (st2.empty()) {
            if (ask(i, st.back())) {
                st.push_back(i);
            } else {
                st2.push_back(i);
            }
        } else if (st3.empty()) {
            int ok1 = ask(i, st.back()), ok2 = ask(i, st2.back());
            if (ok1 && ok2) {
                st3.push_back(i);
            } else if (ok1) {
                st.push_back(i);
            } else if (ok2) {
                st2.push_back(i);
            } else {
                assert(false);
            }
        } else {
            if (ask(i, st3.back())) {
                st3.push_back(i);
            } else {
                if (ask(i, st.back())) {
                    st.push_back(i);
                    for (auto j: st3)
                        st2.push_back(j);
                    st3.clear();
                } else {
                    st2.push_back(i);
                    for (auto j: st3)
                        st.push_back(j);
                    st3.clear();
                }
            }
        }
    }
    if (!st3.empty()) {
        for (auto i: st3)
            st.push_back(i);
        st3.clear();
    }
    vector<int> colors(n + 1);
    for (auto i: st2)
        colors[i] = 1;
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << colors[i] << ' ';
    cout << endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
}
```
 **Feedback*** Good problem 

 
[*73*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*0*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")
