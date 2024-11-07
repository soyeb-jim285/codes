# Tutorial_(en)

I'm very very sorry to all Div2 participants for unclearness in statement of A, and not including notes in the statement of B, hope it didnt ruined a contest for you. Thank you all for participating, I hope you enjoyed non-empty subset of the problems! You can rate the problems of the round in the corresponding spoilers.

[1894A - Secret Sport](https://codeforces.com/contest/1894/problem/A "Codeforces Round 908 (Div. 2)")  


  **Hint 1**  You can always bruteforce X and Y, and check every pair of (X,Y) separately, but there is a tRiCkY solution that involves zero implementation.   **Hint 2**  Have you ever watched a game of tennis, a game of volleyball, e.t.c?   **Tutorial**  
### [1894A - Secret Sport](https://codeforces.com/contest/1894/problem/A "Codeforces Round 908 (Div. 2)")

The winner will be the player who wins the last play. This is true because the winner will be the player who wins the last set, because, if this were not the case, the last set would not be played. And in a set, the player who wins the last play wins, because if this were not the case, the last play would not be played.

 **Solution**[231849364](https://codeforces.com/contest/1894/submission/231849364 "Submission 231849364 by sevlll777")

 
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  cout << s.back() << 'n';
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
 **Rate the problem*** Didnt solve 


[*49*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*204*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*110*](https://codeforces.com/data/like?action=like "I like this")
* tROlll pRoBlEm 

 
[*956*](https://codeforces.com/data/like?action=like "I like this")
[1894B - Two Out of Three](https://codeforces.com/contest/1894/problem/B "Codeforces Round 908 (Div. 2)")  


  **Hint 1**  Everything is symmetrical, so you can fix beforehand any exact two conditions you are aimed to satisfy.   **Hint 2**  You need to not satisfy 3rd condition, so it doesnt really make sense to color any elements that not used in satisfying conditions 1 and 2 in colors bi=2,bi=3. And to satisfy conditions 1 and 2 one element is enough.   **Tutorial**  
### [1894B - Two Out of Three](https://codeforces.com/contest/1894/problem/B "Codeforces Round 908 (Div. 2)")

By symmetry, it doesn't matter which two conditions are satisfied. Let's assume it's the conditions $(1, 2)$ and $(1, 3)$. Then the elements with $b_i = 2$ and the elements with $b_i = 3$ should not intersect. Therefore, it is sufficient to assign $b_i = 2$ and $b_i = 3$ to only one element that is common with the elements of the form $b_i = 1$ in order to satisfy the conditions $(1, 2)$ and $(1, 3)$. And these elements must be distinct in order to not satisfy the condition $(2, 3)$. Thus, we obtain the necessary condition for the existence of an answer: the array must have at least two elements that occur more than once. It is easy to see that this condition is also sufficient by constructing an example: let $x, y$ be two numbers that occur more than once in the array. Then we can assign $a_i = x \to b_i = 2$ to one of the occurrences, $a_i = y \to b_i = 3$ to one of the occurrence, and assign $b_i = 1$ to all other numbers, and this will be a suitable answer.

 **Solution**[231849397](https://codeforces.com/contest/1894/submission/231849397 "Submission 231849397 by sevlll777")

 
```cpp
#include <bits/stdc++.h>
 
using namespace std;
const int N = 100;
 
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n, 1);
  vector<vector<int>> inds(N + 1);
  for (int i = 0; i < n; i++) {
    inds[a[i]].push_back(i);
  }
  int k = 2;
  for (int x = 1; x <= N; x++) {
    if ((int) inds[x].size() >= 2) {
      b[inds[x][0]] = k;
      k++;
      if (k > 3) {
        break;
      }
    }
  }
  if (k <= 3) {
    cout << "-1n";
  } else {
    for (int i = 0; i < n; i++) {
      cout << b[i] << ' ';
    }
    cout << 'n';
  }
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
 **Rate the problem*** Didnt solve 

 
[*61*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*340*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*141*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*111*](https://codeforces.com/data/like?action=like "I like this")
[1893A - Anonymous Informant](../problems/A._Anonymous_Informant.md "Codeforces Round 908 (Div. 1)")  


  **Hint 1**  How to rollback one operation? Is rollback uniquely determined?   **Hint 1.1**  Of course it is.   **Hint 2**  After performing operation ax=x always becomes a last element of array.   **Tutorial**  
### [1893A - Anonymous Informant](../problems/A._Anonymous_Informant.md "Codeforces Round 908 (Div. 1)")

The key idea is that after applying an operation with the number $x$, the last element of the resulting array will be equal to $x$. Since after $x$ cyclic shifts, the array $[a_1, a_2, \ldots, a_n]$ will become $[a_{x+1}, \ldots, a_n, a_1, \ldots, a_x]$, and $a_x = x$, as $x$ was a fixed point of the array $a$.

From this idea, we can deduce that the operation can always be undone in at most one way: we need to look at the last element ($a_n$), and if $a_n > n$, it is not possible to undo the operation. Otherwise, we need to cyclically shift the array to the right $a_n$ times.

Therefore, the solution to the problem will be to undo the operation on the array by $1$ step $k$ times. If at any point it becomes impossible to undo the operation, the answer is "No". Otherwise, the answer is "Yes".

To avoid explicitly shifting the array, we can store a variable $s$ representing the index of the initial element, indicating that the current array is equal to $[a_s, a_{s+1}, \ldots, a_n, a_1, \ldots, a_{s-1}]$. When cyclically shifting the array to the right by $x$, $s$ decreases by $x$, initially $s = 1$.

Also, since $k$ in the problem can be up to $10^9$, simulating $k$ undo operations would be very time-consuming. However, we can notice that if we manage to undo the operation $n$ times without breaking anything, we have entered a cycle. Therefore, if we successfully undo the operation $n$ times, the answer is definitely "Yes". In other words, it was sufficient to do k = min(k, n).

Time complexity: $O(n)$

 **Solution**[231849420](https://codeforces.com/contest/1893/submission/231849420 "Submission 231849420 by sevlll777")

 
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  k = min(k, n);
  int last = n - 1;
  for (int _ = 0; _ < k; _++) {
    if (a[last] > n) {
      cout << "Non";
      return;
    }
    last += n - a[last];
    if (last >= n) {
      last -= n;
    }
  }
  cout << "Yesn";
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
 **Rate the problem*** Didnt solve 

 
[*122*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*593*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*43*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*98*](https://codeforces.com/data/like?action=like "I like this")
[1893B - Neutral Tonality](../problems/B._Neutral_Tonality.md "Codeforces Round 908 (Div. 1)")  


  **Hint 1**  Lower bound for answer: LIS(a)   **Hint 2**  Upper bound for answer: LIS(a)+1, you can insert b's in decreasing order anywhere. When you can't achieve LIS(a)?   **Hint 3**  Solve for m=1   **Tutorial**  
### [1893B - Neutral Tonality](../problems/B._Neutral_Tonality.md "Codeforces Round 908 (Div. 1)")

First observation: $\text{LIS}(c) \geq \text{LIS}(a)$. This is true because the array $c$ will always contain $a$ as a subsequence, and therefore any subsequence of $a$ as well.

Notice that it is always possible to achieve $\text{LIS}(c) \leq \text{LIS}(a) + 1$. Let $b_1 \geq \ldots \geq b_m$. This can be achieved by inserting $b_1, \ldots, b_m$ in a non-increasing order at any positions in the array $a$, because in this case, any increasing subsequence of $c$ can have at most one element from the array $b$, which means $\text{LIS}(c) \leq \text{LIS}(a) + 1$.

Therefore, we need to understand when we can achieve $\text{LIS}(c) = \text{LIS}(a)$. It turns out that this can always be achieved!

Let's understand how to insert one number ($x$) into the array while preserving $\text{LIS}(a)$. If $x < \min(a_1, \ldots, a_n)$, then we insert $x$ at the end of the array $a$, so that $x$ cannot be present in any increasing subsequence of length at least $2$, and $\text{LIS}(a)$ will not increase. Otherwise, we can insert $x$ before the first index $i$ such that $x \geq a_i$. Then, both $x$ and $a_i$ cannot be present in the same increasing subsequence. However, in any increasing subsequence where $x$ is present, we can replace $x$ with $a_i$ and the subsequence will still remain increasing. Thus, $\text{LIS}(a)$ will not increase.

Now we can apply this solution $m$ times, inserting the numbers $b_1 \geq b_2 \geq \ldots \geq b_m$ one by one. The final algorithm turns out to be surprisingly simple and similar to the merge(a, b) function. Specifically, iterate on arrays $a$ and $b$ with two pointers, at each step adding the larger of the two numbers ($a_i$ or $b_j$) to the answer and moving the corresponding pointer.

Time complexity: $O(n + m \log m)$

 **Solution**[231849445](https://codeforces.com/contest/1893/submission/231849445 "Submission 231849445 by sevlll777")

 
```cpp
#include <bits/stdc++.h>
 
#define pb push_back
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
using namespace std;
 
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m), c(n + m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(rall(b));
  merge(all(a), all(b), c.begin(), greater<int>());
  for (int i = 0; i < n + m; i++) {
    cout << c[i] << ' ';
  }
  cout << 'n';
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
 **Rate the problem*** Didnt solve 

 
[*44*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*410*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*54*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*79*](https://codeforces.com/data/like?action=like "I like this")
[1893C - Freedom of Choice](../problems/C._Freedom_of_Choice.md "Codeforces Round 908 (Div. 1)")  


  **Hint 1**  It makes sense to try to solve case m=1 first, to get general understanding of the problem, some observations will be usefull in full solution.   **Hint 1.1**  What size can a multiset X have?   **Hint 1.2**  If r−l>n, the answer to the problem is 0. Now we are left in the case of r−l≤n. So we can iterate over all sizes from l to r, for each of them find the minimum anti-beauty that can have a set of this size, and take the minimum of all this for the answer.   **Hint 2**  For bigger m you need to find a fast enough way to count minimal anti-beauty with fixed size, everything else remains the same.   **Tutorial**  
### [1893C - Freedom of Choice](../problems/C._Freedom_of_Choice.md "Codeforces Round 908 (Div. 1)")

Note that after performing all operations, the multiset $X$ can have any integer size from $\sum l_i$ to $\sum r_i$. And the number of distinct numbers that can potentially be in $X$ is definitely not greater than $\sum n_i$. Therefore, if $\sum r_i - \sum l_i > \sum n_i$, there will always be a number from $\sum l_i$ to $\sum r_i$ that is not present in any of the $m$ given multisets, and thus will not be in $X$. By making $X$ of such size, we will have the anti-beauty of $X$ equal to $0$, which is the minimum achievable anti-beauty. So, if $\sum r_i - \sum l_i > \sum n_i$, we can output $0$ and terminate. Then we solve the problem under the condition $\sum r_i - \sum l_i \leq \sum n_i$.

$\sum n_i$ is limited to $10^5$. Therefore, we can explicitly iterate through all possible sizes of the multiset $X$, from $\sum l_i$ to $\sum r_i$, and for a fixed size $s$, determine the minimum anti-beauty if $X$ has size $s$. Then we take the minimum of these values as the answer.

For a fixed size $s$, to minimize the anti-beauty, we want to include as many numbers not equal to $s$ in $X$ as possible. For the multisets where $s$ is not present, we want to take $r_i$. To calculate this sum, we can take the sum of all $r_i$ and subtract from it the sum of $r_i$ for the multisets in which $s$ is present. And for those multisets where $s$ is present, we can explicitly iterate through them and use simple formulas to calculate how many $s$ we are obligated to take from each multiset. This will take at most $O(\sum n_i)$. For specific formulas, refer to the code.

 **Solution**[231849477](https://codeforces.com/contest/1893/submission/231849477 "Submission 231849477 by sevlll777")

 
```cpp
#include <bits/stdc++.h>
 
#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
using namespace std;
 
void solve() {
  int m;
  cin >> m;
  vector<int> n(m), l(m), r(m);
  vector<vector<int>> a(m);
  vector<vector<int>> c(m);
  vector<int> sumc(m);
  int suml = 0, sumr = 0, sumn = 0;
  for (int i = 0; i < m; i++) {
    cin >> n[i] >> l[i] >> r[i];
    sumn += n[i];
    suml += l[i];
    sumr += r[i];
    a[i].resize(n[i]);
    for (int j = 0; j < n[i]; j++) {
      cin >> a[i][j];
    }
    c[i].resize(n[i]);
    for (int j = 0; j < n[i]; j++) {
      cin >> c[i][j];
      sumc[i] += c[i][j];
    }
  }
  
  if (sumr - suml > sumn) {
    cout << "0n";
    return;
  }
 
  map<int, int> sumr_a;
  map<int, vector<pair<int, int>>> indexes;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n[i]; j++) {
      sumr_a[a[i][j]] += r[i];
      indexes[a[i][j]].pb({i, j});
    }
  }
 
  int ans = (int) 2e18;
  for (int len = suml; len <= sumr; len++) {
    int xsize = 0, must_len = 0;
    xsize += sumr - sumr_a[len];
    for (auto &[i, pos] : indexes[len]) {
      int cnt_not_len = sumc[i] - c[i][pos];
      if (cnt_not_len < l[i]) {
        xsize += l[i];
        must_len += l[i] - cnt_not_len;
      } else {
        xsize += min(cnt_not_len, r[i]);
      }
    }
    ans = min(ans, must_len + max(0LL, len - xsize));
  }
  cout << ans << 'n';
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
 **Rate the problem*** Didnt solve 

 
[*36*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*91*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*44*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*151*](https://codeforces.com/data/like?action=like "I like this")
[1893D - Colorful Constructive](../problems/D._Colorful_Constructive.md "Codeforces Round 908 (Div. 1)")  


  **Hints: Natural Way**   **Hint 1**  Solve the problem if si=di for all i.   **Hint 1.1**  Simple greedy should work.   **Hint 2**  Solve the problem if si=2⋅di for all i.   **Hint 3**  Solve the problem if di divides si for all i.   **Hint 4**  You can treat remainder (simoddi) separately, as an individual shelf.    **Hints: Believers Way**   **Hint -1**  What is the most obvious greedy you can do?   **Hint -2**  What is the second most obvious greedy you can do?   **Hint -3**  What is the third most obvious greedy you can do?   **Hint -4**  It's probably correct at this point, just proof by AC!    **Tutorial**  
### [1893D - Colorful Constructive](../problems/D._Colorful_Constructive.md "Codeforces Round 908 (Div. 1)")

Let's try to come up with a condition equivalent to "A set of cubes $a_1, \ldots, a_n$ can be distributed on a shelf of size $n$ such that the colorfulness of the shelf is $\geq d$" in such a way that this condition can be conveniently combined for $m$ shelves.

Let's find the necessary condition (the condition that must be satisfied) if the set of cubes $a_1 \ldots a_n$ can be correctly placed on a shelf with parameters $(n, d)$. In such an arrangement, every $\leq d$ adjacent cubes must have different colors. This means that we can divide the shelf into subsegments as follows: $(a_1, \ldots, a_d), (a_{d+1}, \ldots, a_{2d}), \ldots, (a_{d \cdot (\lfloor \frac{n}{d} \rfloor - 1) + 1}, \ldots, a_{d \cdot \lfloor \frac{n}{d} \rfloor}), (a_{d \cdot \lfloor \frac{n}{d} \rfloor + 1}, \ldots, a_{n})$ such that the colors of all cubes in each subsegment are different. From this, the necessary condition follows: "The set of cubes $a_1, \ldots, a_n$ can be divided into $\lfloor \frac{n}{d} \rfloor$ groups of size $d$, as well as a group of size $n \mod d$, such that the colors of all cubes in each group are different."

It turns out that this same condition is also sufficient! We will show this by presenting a way to place all the cubes from the "$\lfloor \frac{n}{d} \rfloor$ groups of size $d$, and the group of size $n \mod d$ (where the colors of all cubes in each group are different)" on a shelf of size $n$ such that the colorfulness of the shelf is $\geq d$.

How to do it: place the cubes from the group of size $n \mod d$ in the first positions. Then consider the groups of size $d$ in any order. Place the cubes whose colors are already present in the previously placed array at the same indices as in the previous array, at a distance of $d$, and place the rest of the cubes however you like. It is easy to see that in this construction, the distance between any two identical colors is at least $d$.

Example for understanding: let $d = 3$ and the given groups be: $[1, 2, 3], [3, 4, 5], [1, 3, 4], [1, 2]$. Then we proceed as follows: first, place $[1, 2]$. Then we want to add the group $[1, 2, 3]$: $[1, 2, ?, ?, ?]$. The elements $1$ and $2$ were present in the previous array, so we place them at a distance of $d = 3$ from the previous occurrences: $[1, 2, ?, 1, 2]$. Fill in the remaining element: $[1, 2, 3, 1, 2]$. Now append $[3, 4, 5]$: $[1, 2, 3, 1, 2, ?, ?, ?]$. The element $3$ is present in the previous array, so we place it: $[1, 2, 3, 1, 2, 3, ?, ?]$. Fill in the remaining elements in any order: $[1, 2, 3, 1, 2, 3, 4, 5]$. After that, append the group $[1, 3, 4]$ and obtain the final arrangement: $[1, 2, 3, 1, 2, 3, 4, 5, 3, 4, 1]$. The colorfulness is $\geq 3$.

What to do with this information now? If we replace the conditions for all $m$ shelves with equivalent ones, we get: "The cubes can be placed on shelves $(s_1, d_1), \ldots, (s_m, d_m)$" is equivalent to "The cubes can be divided into groups of sizes $[\underbrace{d_1, \ldots, d_1}_{\lfloor \frac{s_1}{d_1} \rfloor}, s_1\mod d_1, \ldots, \underbrace{d_m, \ldots, d_m}_{\lfloor \frac{s_m}{d_m} \rfloor}, s_m \mod d_m]$, such that all colors are different in each group."

Thus, we have reduced the problem to a simpler one: given $a_1, \ldots, a_n$ and a set $w_1, \ldots, w_k$ with a sum of $n$. We need to divide the numbers $a_1, \ldots, a_n$ into arrays of sizes $w_1, \ldots, w_k$ such that all numbers in each array are different.

This problem can be solved using a simple greedy algorithm. Let $[a_1, \ldots, a_n]$ consist of $cnt_1$ copies of element $b_1$, $cnt_2$ copies of element $b_2$, ..., $cnt_t$ copies of element $b_t$ ($\sum cnt_i = n$). Then we consider the elements $b_1, \ldots, b_t$ in any order and place all copies of the current element in arrays of the largest length. If there are fewer arrays with non-zero length remaining than $cnt_i$, there is no solution. After adding, the length of the arrays in which the number was added decreases by $1$. It is easy to see that if we obtain a solution, then the numbers in all arrays will indeed be different. This solution can be easily implemented using std::set.

The correctness of the greedy algorithm follows from the fact that if there are two arrays of lengths $n_1 > n_2$ consisting of different numbers, then in the array of length $n_1$, there must be some number that is not present in the array of length $n_2$, so any number from the array of length $n_2$ can be swapped with someone from the array of length $n_1$ to maintain the property that the numbers in both arrays are different. From this, it follows that if we have some solution to the problem and a fixed element, we can obtain a solution in which this fixed element is only present in the largest arrays, which proves our solution.

Second solution:

Ultra Greedy Algorithm. We go through shelves and places on the shelf, and at each moment we place a cube of a color that occurs the most times among the remaining cubes, naturally excluding colors that would break the condition of having different colors (i.e., excluding colors other than the {$\max(0, d_i - 1)$} colors of the previous cubes on this shelf). The proof of why this solution works will remain behind the scenes.

 **Solution**[231849510](https://codeforces.com/contest/1893/submission/231849510 "Submission 231849510 by sevlll777")

 
```cpp
#include <bits/stdc++.h>
 
#define pb push_back
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
using namespace std;
 
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> s(m), d(m);
  for (int i = 0; i < m; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
 
  set<pair<int, int>> cubes;
  for (int x = 1; x <= n; x++) {
    if (cnt[x] == 0) continue;
    cubes.insert({cnt[x], x});
  }
 
  vector<vector<int>> ans(m);
 
  for (int i = 0; i < m; i++) {
    ans[i].assign(s[i], 0);
    for (int j = 0; j < s[i]; j++) {
      if (j >= d[i]) {
        if (cnt[ans[i][j - d[i]]] > 0) {
          cubes.insert({cnt[ans[i][j - d[i]]], ans[i][j - d[i]]});
        }
      }
      if (cubes.empty()) {
        cout << "-1n";
        return;
      }
      ans[i][j] = (*cubes.rbegin()).second;
      cubes.erase(*cubes.rbegin());
      cnt[ans[i][j]]--;
    }
    for (int j = s[i]; j < s[i] + d[i]; j++) {
      if (cnt[ans[i][j - d[i]]] > 0) {
        cubes.insert({cnt[ans[i][j - d[i]]], ans[i][j - d[i]]});
      }
    }
  }
 
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < s[i]; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << 'n';
  }
 
}
 
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
 **Rate the problem*** Didnt solve 

 
[*26*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*47*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*8*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*112*](https://codeforces.com/data/like?action=like "I like this")
[1893E - Cacti Symphony](../problems/E._Cacti_Symphony.md "Codeforces Round 908 (Div. 1)")  


  **Hint 1**  Cacti is a trap, don't think about it for now, it will help later.   **Hint 2**  Well, you need to make some observations. Start with observations about determining edges weights, it seems reasonable because edge always have exactly 2 adjacent vertices.   **Hint 3**  Edge is good <=> Exactly one of the adjacent vertexes have a same weight as an edge.   **Hint 4**  Direct edges, such that every edge goes from vertex with same weight as edge to another vertex. In this reality try to find easier equivalent condition for ``vertice is good``.   **Hint 5**  Vertex is good <=> InDegree of vertex is an odd integer.   **Hint 6**  Now you just have two separate problems: 1) Direct all edges, such that InDegree of each vertex is odd; 2) Color all vertexes in 3 colors such that any 2 adjacent vertexes have different color. Time to remember about cacti.   **Tutorial**  
### [1893E - Cacti Symphony](../problems/E._Cacti_Symphony.md "Codeforces Round 908 (Div. 1)")

First observation: for each edge, the vertices connected by it have different weights, otherwise the XOR of the weights of the adjacent vertices of this edge is equal to $0$.

Second observation: for each edge, one of its adjacent vertices has a weight equal to the weight of the edge, since $1 \oplus 2 \oplus 3 = 0$.

From these two observations, it follows that each edge has the same weight as EXACTLY one of the vertices it is connected to. Let's say that a vertex controls all the adjacent edges with the same weight. Then each edge is controlled by exactly one vertex.

Third observation: if a vertex has an even degree, then the number of edges controlled by it must be odd, and this is a sufficient condition for the vertex to be good.

Fourth observation: if a vertex has an odd degree, then the number of edges controlled by it must be even, and this is a sufficient condition for the vertex to be good.

Therefore, in order for all vertices to be good, it is necessary to choose who controls each edge in such a way that the parity of the vertex degree and the parity of the number of edges controlled by it are different.

And in order for all edges to be good, it is necessary to assign weights from $1$ to $3$ to the vertices in such a way that no two adjacent vertices have the same weight. The weight of each edge will then be equal to the weight of the vertex it is controlled by.

Now the problem is divided into two independent parts: finding the number of ways to assign weights to the vertices, and finding the number of ways to orient the edges. The answer to the original problem will be the product of the answers to these two parts.

1. How many ways are there to color the vertices with $3$ colors, such that two adjacent vertices are colored differently?
2. How many ways are there to orient the edges, such that a vertex with an even degree has an odd number of outgoing edges, and a vertex with an odd degree has an even number of outgoing edges?

Solution to problem 1: note that if there is a bridge in the graph $G$, and it divides the graph into graphs $G1$ and $G2$, then the answer for $G$ is the product of the answers for $G1$ and $G2$ multiplied by $\frac{2}{3}$. Then we can identify all the bridges, and since the graph is a vertex cactus, after removing the bridges, the graph will be divided into cycle components. For a cycle of length $n$, the number of ways to color the vertices can be calculated using simple dynamic programming: $dp_1 = 3, dp_3 = 6, dp_4 = 18, dp_n = dp_{n - 1} + 2 \cdot dp_{n - 2}$. To prove this dynamic programming, consider any two vertices that are one apart in a cycle of length $n$. If they have the same color, then the vertex between them has $2$ possible colors, and the rest have $dp_{n-2}$ possibilities. If they have different colors, then there are $dp_{n-1}$ possibilities. Knowing the transition formula, we can notice that $dp_n = 2^n + 2 \cdot (-1)^n$. This formula can be trivially proved by induction.

Solution to problem 2: we will solve the same problem, but requiring that each vertex has an odd number of outgoing edges (if we invert all the edges in such a graph, we will get what is required). If $n$ and $m$ have different parity, then the answer is $0$, since the sum of $n$ odd numbers, which are the degrees of the vertices, must be equal to $m$. Otherwise, the answer is $2^{number of cycles}$. At any moment, we can remove any leaf, as it does not solve anything. We will remove the leaves as long as they exist. After this, one of the cycles in the graph will be a "leaf" - connected only to one other cycle. For all vertices of this cycle, the necessary parities of the degrees are known. Choose any edge of the cycle and orient it (there are $2$ ways to orient it, both will work). After that, all other edges in the cycle are oriented uniquely. After that, the bridge between this cycle and the other one is also uniquely oriented. Now we have one less cycle, and we also know all the necessary parities of the vertices (the parity changes for the vertex where the bridge came in). In this way, we can gradually reduce the number of cycles. With each removal of a cycle, the answer is multiplied by $2$, since there are $2$ ways to orient the edge in the cycle. In the end, we get $2^{number of cycles}$ ways.

The final answer to the problem if $n$ and $m$ have same parity is:

$ans = \frac{2}{3}^{number of bridges} \cdot 2^{number of cycles} \cdot (2^{c_1} + 2 \cdot (-1)^{c_1}) \cdot \ldots \cdot (2^{c_k} + 2 \cdot (-1)^{c_k})$ where $c_1, \ldots, c_k$ are the sizes of cycles (cycle can be a single vertice if it did not lie on any other cycle, and $c_i = 0$ in this case).

 **Solution**[231849553](https://codeforces.com/contest/1893/submission/231849553 "Submission 231849553 by sevlll777")

 
```cpp
#include <bits/stdc++.h>
 
typedef long long ll;
#define pb push_back
 
using namespace std;
 
const int M = 998244353;
const int N = 500500;
vector<pair<int, int>> g[N];
set<int> bridgesV[N];
bitset<N> used;
int h[N], d[N];
ll bridges = 0;
ll solo = 0;
 
int binpow(ll a, ll x) {
  ll ans = 1;
  while (x) {
    if (x % 2) {
      ans *= a;
      ans %= M;
    }
    a *= a;
    a %= M;
    x /= 2;
  }
  return (int) ans;
}
 
void dfs(int v, int p = -1) {
  if (p != -1) {
    d[v] = h[p] + 1;
    h[v] = h[p] + 1;
  }
  used[v] = true;
  for (auto &[u, w] : g[v]) {
    if (u == p) continue;
    if (!used[u]) {
      dfs(u, v);
      d[v] = min(d[v], d[u]);
      if (h[v] < d[u]) {
        bridgesV[v].insert(u);
        bridgesV[u].insert(v);
        bridges += w + 1;
        solo += w;
      }
    } else {
      d[v] = min(d[v], h[u]);
    }
  }
}
 
int calc_dp(ll n) {
  n %= (M - 1);
  if (n == 1) return 3;
  if (n == 2) return 0;
  int val = binpow(2, n);
  if (n % 2 == 1) {
    val += M - 2;
  } else {
    val += 2;
  }
  val %= M;
  return val;
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    g[a].pb({b, w});
    g[b].pb({a, w});
  }
  if (n % 2 != m % 2) {
    cout << "0n";
    return 0;
  }
  dfs(0);
  used.reset();
 
  ll ans = 1;
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      ll cs = 0;
      vector<int> q = {v};
      used[v] = true;
      while (!q.empty()) {
        int u = q.back();
        q.pop_back();
        for (auto &[uu, w] : g[u]) {
          if (bridgesV[u].find(uu) != bridgesV[u].end()) continue;
          cs += w + 1;
          if (!used[uu]) {
            used[uu] = true;
            q.pb(uu);
          }
        }
      }
      cs /= 2;
      cs = max(cs, 1LL);
      ans *= calc_dp(cs);
      ans %= M;
    }
  }
  ans *= binpow(3, solo);
  ans %= M;
  int w = (2 * binpow(3, M - 2)) % M;
  ans *= binpow(w, bridges);
  ans %= M;
  int cycles = (m + 1) - n;
  ans *= binpow(2, cycles);
  ans %= M;
  cout << ans << 'n';
}
```
 **Rate the problem*** Didnt solve 

 
[*54*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*18*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*28*](https://codeforces.com/data/like?action=like "I like this")
