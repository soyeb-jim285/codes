# Tutorial

[1490A - Dense Array](../problems/A._Dense_Array.md "Codeforces Round 702 (Div. 3)")

Problem author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**
### [1490A - Dense Array](../problems/A._Dense_Array.md "Codeforces Round 702 (Div. 3)")

Note that adding elements between positions i (1≤i≤n−1) and i+1 will not change the ratio of the adjacent elements, except for the ones just added. Therefore, for each pair of adjacent numbers, the problem can be solved independently.

Let us solve the problem for a adjacent pair of numbers ai and ai+1 for which the inequality from the statements does not hold. Suppose that 2ai≤ai+1 (if not, we will swap them). Then between ai and ai+1 it requires to insert ⌈log2(ai+1ai)−1⌉ elements of the form: 2ai,4ai,...,2⌈log2(ai+1ai)−1⌉ai

It is better not to use explicit formula, but to use the following cycle: 


```cpp
while a[i] * 2 < a[i + 1]:  
  a[i] *= 2  
  ans += 1  

```
 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int last;
  cin >> last;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int nw;
    cin >> nw;
    int a = min(last, nw), b = max(last, nw);
    while (a * 2 < b) {
      ans++;
      a *= 2;
    }
    last = nw;
  }
  cout << ans << "n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
[1490B - Balanced Remainders](../problems/B._Balanced_Remainders.md "Codeforces Round 702 (Div. 3)")

Problem author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**
### [1490B - Balanced Remainders](../problems/B._Balanced_Remainders.md "Codeforces Round 702 (Div. 3)")

Note that the numbers in the a array are not important to us, so initially we will calculate the values of c0, c1, c2. Now applying a move for the number ai is equivalent to: 

* decreasing cai mod 3 by 1;
* and increasing c(ai+1) mod 3 by 1;

We will perform the following greedy algorithm: 

* while the array a have no balanced remainders, find any i (0≤i≤2) such that ci>n3;
* we apply the move for ci, that is, replace ci with ci−1, and c(i+1) mod 3 with c(i+1) mod 3+1.

It is easy to prove the correctness of this greedy algorithm by cyclically shifting the values c0, c1, and c2 so that the first element is equal to the maximum of them.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  int res = 0;
  vector<int> cnt(3);
  for (int x = 0; x <= 2; x++) {
      for (int i = 0; i < n; i++) {
          if (a[i] % 3 == x) {
              cnt[x]++;
          }
      }
  }
  
  while (*min_element(cnt.begin(), cnt.end()) != n / 3) {
      for (int i = 0; i < 3; i++) {
          if (cnt[i] > n / 3) {
              res++;
              cnt[i]--;
              cnt[(i + 1) % 3]++;
          }
      }
  }
  cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
[1490C - Sum of Cubes](../problems/C._Sum_of_Cubes.md "Codeforces Round 702 (Div. 3)")

Problem author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**
### [1490C - Sum of Cubes](../problems/C._Sum_of_Cubes.md "Codeforces Round 702 (Div. 3)")

In this problem, we need to find a and b such that x=a3+b3 and a≥1,b≥1.

Since a and b are positive, a3 and b3 are also positive. Hence a3≤a3+b3≤x. Therefore, the number a can be iterated from 1 to 3√x. Since in all tests x≤1012, then a≤104.

For each a , you can find b by the formula b=3√x−a3. This is a positive number. It remains to check that b is an integer.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll N = 1'000'000'000'000L;

unordered_set<ll> cubes;

void precalc() {
  for (ll i = 1; i * i * i <= N; i++) {
    cubes.insert(i * i * i);
  }
}

void solve() {
  ll x;
  cin >> x;
  for (ll i = 1; i * i * i <= x; i++) {
    if (cubes.count(x - i * i * i)) {
      cout << "YESn";
      return;
    }
  }
  cout << "NOn";
}

int main() {
  precalc();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
[1490D - Permutation Transformation](../problems/D._Permutation_Transformation.md "Codeforces Round 702 (Div. 3)")

Problem author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**
### [1490D - Permutation Transformation](../problems/D._Permutation_Transformation.md "Codeforces Round 702 (Div. 3)")

We will construct the required tree recursively. Let us describe the state of tree construction by three values (l,r,d), where [l,r] — is the segment of the permutation, and d — is the current depth. Then the following transitions can be described: 

* find the position m of the maximum element on the segment [l,r], that is, am=rmaxi=lai;
* the depth of the vertex am is equal to d;
* if l<m, then make the transition to the state (l,m−1,d+1);
* if m<r, then make the transition to the state (m+1,r,d+1);

Then, in order to construct the required tree, it is necessary to take (1,n,0) as the initial state.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void build(int l, int r, vector<int> const &a, vector<int> &d, int curD = 0) {
  if (r < l) {
    return;
  }
  if (l == r) {
    d[l] = curD;
    return;
  }
  int m = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[m] < a[i]) {
      m = i;
    }
  }
  d[m] = curD;
  build(l, m - 1, a, d, curD + 1);
  build(m + 1, r, a, d, curD + 1);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vector<int> d(n);
  build(0, n - 1, a, d);
  for (int x :d) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
[1490E - Accidental Victory](../problems/E._Accidental_Victory.md "Codeforces Round 702 (Div. 3)")

Problem authors: [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly"), [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz")

 **Editorial**
### [1490E - Accidental Victory](../problems/E._Accidental_Victory.md "Codeforces Round 702 (Div. 3)")

How can a player be checked if he can win the championship? Obviously, he must participate in all the games (otherwise we will increase the number of tokens of the opponents). So you can sort out all the people and play greedily with the weakest ones. Such a check will work in linear time after sorting, so we got a solution for O(n2).

The simplest solution to this problem is — binary search for the answer. We will sort all the players by the number of tokens they have. Let's prove that if player i can win, then player i+1 can also win (the numbers are dealt after sorting). If the player i was able to win, then based on the strategy above, he was able to defeat all the players on the prefix [0…i+1]. The player i+1 can also defeat all these players since he has at least as many tokens. Now both players have to defeat all opponents with numbers [i+2…n] and the number of chips both players have is equal to the sum of the first i+1 numbers in the array. So if the player i has a strategy, then the player i+1 can use the same strategy.

Hence the answer to the problem is — sorted suffix of the input array. You can find this suffix using binary search and linear time checking.

Bonus: this problem also has a fully linear (after sorting) solution.

 **Solution**
```cpp
def win(pos : int, a : list):
    power = a[pos]
    for i in range(len(a)):
        if i == pos:
            continue
        if power < a[i]:
            return False
        power += a[i]
    return True

t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    a = list(map(int, input().split(' ')))
    b = a.copy()
    a.sort()

    l = -1
    r = n - 1
    while r - l > 1:
        m = (l + r) // 2
        if (win(m, a)):
            r = m
        else:
            l = m

    winIds = []
    for i in range(n):
        if b[i] >= a[r]:
            winIds.append(i + 1)

    print(len(winIds))
    print(*winIds)
```
[1490F - Equalize the Array](../problems/F._Equalize_the_Array.md "Codeforces Round 702 (Div. 3)")

Problem author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Editorial**
### [1490F - Equalize the Array](../problems/F._Equalize_the_Array.md "Codeforces Round 702 (Div. 3)")

Let's calculate the value of cntx — how many times the number x occurs in the array a. We will iterate over the value of C and look for the minimum number of moves necessary for each number to appear in the a array either 0 times, or C times. Note that if there is no such number y that cnty=C, then such a value of C will not give the minimum answer (because we have removed unnecessary elements).

Then, for a specific C, the answer is calculated as follows: ∑cntx<Ccntx+∑cntx≥C(cntx−C)

Since the number of candidates for the value of C is no more than n, this method works in O(n2).

Then there are two ways to optimize our solution: 

* you can consider only unique values of C (there are no more than O(√n)), and get a solution in O(n√n);
* you can sort the values cntx and use prefix sums, this solution works for O(nlogn) or for O(n) (if you use counting sort).
 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  map<int, int> groupedByCnt;
  for (auto[x, y] : cnt) {
    groupedByCnt[y]++;
  }

  int res = n;
  int left = 0, right = n, rightCnt = (int) cnt.size();
  for (auto[x, y] : groupedByCnt) {
    res = min(res, left + right - rightCnt * x);
    left += x * y;
    right -= x * y;
    rightCnt -= y;
  }
  cout << res << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
```
[1490G - Old Floppy Drive](../problems/G._Old_Floppy_Drive_.md "Codeforces Round 702 (Div. 3)") 

Problem authors: [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly"), [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [sodafago](https://codeforces.com/profile/sodafago "Specialist sodafago")

 **Editorial**
### [1490G - Old Floppy Drive](../problems/G._Old_Floppy_Drive_.md "Codeforces Round 702 (Div. 3)")

Let's denote for S the sum of all the elements of the array, and for pref the array of its prefix sums.

If the drive runs for t seconds, the sum is ⌊ts⌋⋅S+pref[tmodn].

This formula immediately shows that if n−1maxi=0pref[i]<x and S≤0, then the disk will run indefinitely. Otherwise, the answer exists.

The disk cannot make less than, ⌈x−n−1maxi=0pref[i]S⌉ full spins, otherwise the required amount simply will not be achived. The disk can't make more spins either, because when it reaches the position of the maximum prefix sum, x will already be achived. So we know how to determine the number of full spins of the disk. Let's make these spins: x:=x−⌈x−n−1maxi=0pref[i]S⌉⋅S.

Now we have a new problem, given x, find the first position i in the array, such that pref[i]≥x. This problem can be solved using binary search. If pref is not sorted into the array, that is, there is j, such that pref[j−1]>pref[j], then pref[j] can simply be thrown out of the array (the answer will never be reached on it).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  ll allSum = 0;
  vector<ll> pref;
  vector<int> ind;
  int curInd = 0;
  for (ll &e : a) {
    cin >> e;
    allSum += e;
    if (pref.empty() || allSum > pref.back()) {
      pref.push_back(allSum);
      ind.push_back(curInd);
    }
    curInd++;
  }
  for (int q = 0; q < m; q++) {
    ll x;
    cin >> x;
    if (pref.back() < x && allSum <= 0) {
      cout << -1 << " ";
      continue;
    }
    ll needTimes = 0;
    if (pref.back() < x) {
      needTimes = (x - pref.back() + allSum - 1) / allSum;
    }
    x -= needTimes * allSum;
    cout << needTimes * n + ind[lower_bound(pref.begin(), pref.end(), x) - pref.begin()] << " ";
  }
  cout << "n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
