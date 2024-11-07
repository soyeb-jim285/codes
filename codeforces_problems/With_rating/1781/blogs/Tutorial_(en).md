# Tutorial_(en)

[1782A - Parallel Projection](https://codeforces.com/contest/1782/problem/A)

 **Explanation**
### [1782A - Parallel Projection](https://codeforces.com/contest/1782/problem/A "Codeforces Round 844 (Div. 1 + Div. 2, based on VK Cup 2022 - Elimination Round)")

Note that bending the cable on the wall is not necessary: we can always bend it on the floor and on the ceiling, while keeping the vertical part of the cable straight. Thus, we can just disregard the height of the room, view the problem as two-dimensional, and add $h$ to the answer at the end.

In the two-dimensional formulation, we need to connect points $(a, b)$ and $(f, g)$ with a cable that goes parallel to the coordinate axes and touches at least one side of the $(0, 0)$ — $(w, d)$ rectangle. We can now casework on the side of the rectangle (the sides are referred to as in the picture from the problem statement): 

* If the cable touches the front side, its length will be $b + |a - f| + g$.
* If the cable touches the left side, its length will be $a + |b - g| + f$.
* If the cable touches the back side, its length will be $(d - b) + |a - f| + (d - g)$.
* If the cable touches the right side, its length will be $(w - a) + |b - g| + (w - f)$.

Out of these four values, the smallest one (plus $h$) is the answer.

 **Source**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int w, d, h;
    cin >> w >> d >> h;
    int a, b;
    cin >> a >> b;
    int f, g;
    cin >> f >> g;
    int ans = b + abs(a - f) + g;
    ans = min(ans, a + abs(b - g) + f);
    ans = min(ans, (d - b) + abs(a - f) + (d - g));
    ans = min(ans, (w - a) + abs(b - g) + (w - f));
    cout << ans + h << 'n';
  }
  return 0;
}
```
[1782B - Going to the Cinema](https://codeforces.com/contest/1782/problem/B)

 **Explanation**
### [1782B - Going to the Cinema](https://codeforces.com/contest/1782/problem/B "Codeforces Round 844 (Div. 1 + Div. 2, based on VK Cup 2022 - Elimination Round)")

Let's fix the number of people going to the cinema k and try to choose a set of this exact size. What happens to people with different ai?

* If ai<k, person i definitely wants to go.
* If ai>k, person i definitely does not want to go.
* If ai=k, there is actually no good outcome for person i. If person i goes to the cinema, there are only k−1 other people going, so person i will be sad (since k−1<ai). If person i does not go, there are k other people going, so person i will be sad too (since k≥ai).

Thus, for a set of size k to exist, there must be no people with ai=k, and the number of people with ai<k must be exactly k. We can easily check these conditions if we use an auxiliary array cnt such that cnt[x] is equal to the number of people with ai=x.

Alternative solution:

Notice that if a set of k people can go to the cinema, it must always be a set of people with the smallest ai. Thus, we can start with sorting the array a in non-decreasing order.

Then, for each length k of a prefix of this array, we can check whether the first k elements are all smaller than k, and the remaining n−k elements are all greater than k.

However, since the array is sorted, it is enough to check that the k-th element is smaller than k, and the k+1-th element is greater than k.

 **Source 1**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      cnt[a] += 1;
    }
    int ans = 0;
    int sum = 0;
    for (int k = 0; k <= n; k++) {
      if (cnt[k] == 0 && sum == k) {
        ans += 1;
      }
      sum += cnt[k];
    }
    cout << ans << 'n';
  }
  return 0;
}
```
 **Source 2**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int k = 0; k <= n; k++) {
      if (k == 0 || a[k - 1] < k) {
        if (k == n || a[k] > k) {
          ans += 1;
        }
      }
    }
    cout << ans << 'n';
  }
  return 0;
}
```
[1782C - Equal Frequencies](https://codeforces.com/contest/1782/problem/C)

 **Explanation**
### [1782C - Equal Frequencies](https://codeforces.com/contest/1782/problem/C "Codeforces Round 844 (Div. 1 + Div. 2, based on VK Cup 2022 - Elimination Round)")

Instead of "finding $t$ that differs from $s$ in as few positions as possible", let's formulate it as "finding $t$ that matches $s$ in as many positions as possible", which is obviously the same.

First of all, let's fix $k$, the number of distinct characters string $t$ will have. Since the string must consist of lowercase English letters, we have $1 \le k \le 26$, and since the string must be balanced, we have $n \bmod k = 0$. For each $k$ that satisfies these conditions, we will construct a balanced string that matches $s$ in as many positions as possible. In the end, out of all strings we will have constructed, we will print the one with the maximum number of matches.

From now on, we are assuming $k$ is fixed. Suppose we choose some character $c$ to be present in string $t$. We need to choose exactly $\frac{n}{k}$ positions in $t$ to put character $c$.

Let $\operatorname{freq}_{c}$ be the number of occurrences of $c$ in $s$.

Then, in how many positions can we make $s$ and $t$ match using character $c$? The answer is: in $\min(\frac{n}{k}, \operatorname{freq}_{c})$ positions.

Now, since we want to maximize the total number of matches, we should choose $k$ characters with the largest values of $\min(\frac{n}{k}, \operatorname{freq}_{c})$. This is also equivalent to choosing $k$ characters with the largest values of $\operatorname{freq}_{c}$.

How to construct the desired string? For each chosen character $c$, pick any $\min(\frac{n}{k}, \operatorname{freq}_{c})$ of its occurrences in $s$ and put $c$ in the corresponding positions in $t$. Then, if $\operatorname{freq}_{c} < \frac{n}{k}$, save the information about $\frac{n}{k} - \operatorname{freq}_{c}$ unused characters $c$; otherwise, if $\operatorname{freq}_{c} > \frac{n}{k}$, save the information about $\operatorname{freq}_{c} - \frac{n}{k}$ empty positions in $t$. In the end, match the unused characters with the empty positions arbitrarily.

 **Source**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> at(26);
    for (int i = 0; i < n; i++) {
      at[(int) (s[i] - 'a')].push_back(i);
    }
    vector<int> order(26);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return at[i].size() > at[j].size();
    });
    string res = "";
    int best = -1;
    for (int cnt = 1; cnt <= 26; cnt++) {
      if (n % cnt == 0) {
        int cur = 0;
        for (int i = 0; i < cnt; i++) {
          cur += min(n / cnt, (int) at[order[i]].size());
        }
        if (cur > best) {
          best = cur;
          res = string(n, ' ');
          vector<char> extra;
          for (int it = 0; it < cnt; it++) {
            int i = order[it];
            for (int j = 0; j < n / cnt; j++) {
              if (j < (int) at[i].size()) {
                res[at[i][j]] = (char) ('a' + i);
              } else {
                extra.push_back((char) ('a' + i));
              }
            }
          }
          for (char& c : res) {
            if (c == ' ') {
              c = extra.back();
              extra.pop_back();
            }
          }
        }
      }
    }
    cout << n - best << 'n';
    cout << res << 'n';
  }
  return 0;
}
```
[1782D - Many Perfect Squares](https://codeforces.com/contest/1782/problem/D)

 **Explanation**
### [1782D - Many Perfect Squares](https://codeforces.com/contest/1782/problem/D "Codeforces Round 844 (Div. 1 + Div. 2, based on VK Cup 2022 - Elimination Round)")

The answer is obviously at least $1$.

Can we make it at least $2$? In this case, let's check all possible pairs of indices $i < j$ and try to figure out for what values of $x$ both $a_i + x$ and $a_j + x$ are perfect squares.

We can write down two equations: $a_i + x = p^2$ and $a_j + x = q^2$, for some non-negative integers $p < q$.

Let's subtract the first equation from the second one and apply the formula of difference of two squares: $a_j - a_i = q^2 - p^2 = (q - p)(q + p)$. It follows that $q - p$ is a positive integer divisor of $a_j - a_i$. It is well-known how to enumerate all divisors of $a_j - a_i$ in $O(\sqrt{a_j - a_i})$. For each such divisor $d$, we have a simple system of equations for $p$ and $q$:

$\begin{cases} q - p = d \\\ q + p = \frac{a_j - a_i}{d} \end{cases}$

that we can solve:

$\begin{cases} p = \frac{1}{2}(\frac{a_j - a_i}{d} - d) \\\ q = \frac{1}{2}(\frac{a_j - a_i}{d} + d) \\\ \end{cases}$

and if both $p$ and $q$ turn out to be integers, that means we have found a candidate value for $x$: $x = p^2 - a_i = q^2 - a_j$.

For each candidate value of $x$, we can just calculate its squareness and find the maximum.

The complexity of this solution is $O(n^2 \cdot \sqrt{a_n} + n^3 \cdot f(a_n))$, where $f(a_n)$ is the maximum number of divisors an integer between $1$ and $a_n$ can have. The first part corresponds to finding all divisors of $a_j - a_i$ for all pairs $i < j$. The second part corresponds to checking all candidate values of $x$: there are $O(n^2 \cdot f(a_n))$ of them, and we need $O(n)$ time to calculate the squareness of each.

Bonus: The first part can be optimized by using faster factorization methods. Can you see how to optimize the second part to $O(n^2 \cdot f(a_n))$?

 **Source**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 1;
    auto Test = [&](long long x) {
      int cnt = 0;
      for (int v : a) {
        long long u = llround(sqrtl(v + x));
        if (u * u == v + x) {
          cnt += 1;
        }
      }
      ans = max(ans, cnt);
    };
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int diff = a[j] - a[i];
        for (int k = 1; k * k <= diff; k++) {
          if (diff % k == 0) {
            long long q = k + diff / k;
            if (q % 2 == 0) {
              q /= 2;
              if (q * q >= a[j]) {
                Test(q * q - a[j]);
              }
            }
          }
        }
      }
    }
    cout << ans << 'n';
  }
  return 0;
}
```
[1782E - Rectangle Shrinking](https://codeforces.com/contest/1782/problem/E)

 **Explanation**
### [1782E - Rectangle Shrinking](https://codeforces.com/contest/1782/problem/E "Codeforces Round 844 (Div. 1 + Div. 2, based on VK Cup 2022 - Elimination Round)")

It turns out that it is always possible to cover all cells that are covered by the initial rectangles.

If the grid had height $1$ instead of $2$, the solution would be fairly simple. Sort the rectangles in non-decreasing order of their left border $l_i$. Maintain a variable $p$ denoting the rightmost covered cell. Then, for each rectangle, in order: 

* If $r_i \le p$, remove this rectangle (note that since we process the rectangles in non-decreasing order of $l_i$, it means that this rectangle is fully covered by other rectangles).
* Otherwise, if $l_i \le p$, set $l_i = p + 1$ (shrink the current rectangle). Then, set $p = r_i$ (this is the new rightmost covered cell).

Let's generalize this approach for a height $2$ grid. Again, sort the rectangles in non-decreasing order of $l_i$, and maintain two variables $p_1$ and $p_2$ denoting the rightmost covered cell in row $1$ and row $2$, respectively. Then, for each rectangle, in order: 

* If it is a height $1$ rectangle (that is, $u_i = d_i$), proceed similarly to the "height $1$ grid" case above:
	+ If $r_i \le p_{u_i}$, remove this rectangle.
	+ Otherwise, if $l_i \le p_{u_i}$, set $l_i = p_{u_i} + 1$. Then, set $p_{u_i} = r_i$.
* If it is a height $2$ rectangle (that is, $u_i = 1$ and $d_i = 2$):
	+ If $r_i \le p_1$, set $u_i = 2$ (remove the first row from the rectangle) and go back to the "height $1$ rectangle" case above.
	+ If $r_i \le p_2$, set $d_i = 1$ (remove the second row from the rectangle) and go back to the "height $1$ rectangle" case above.
	+ Otherwise, consider all processed rectangles $j$ that have $r_j \ge l_i$, i.e., intersect the $i$-th rectangle. If $l_j \ge l_i$, remove rectangle $j$; otherwise, shrink rectangle $j$ by setting $r_j = l_i - 1$. Finally, set $p_1 = p_2 = r_i$.

Here, only the last case is tricky and different from our initial "height $1$ grid" solution, but it is also necessary: in a height $2$ grid, sometimes we have to shrink rectangles on the right, not only on the left.

Now, if we implement this solution in a straightforward fashion, iterating over all $j < i$ for every $i$, we'll arrive at an $O(n^2)$ solution — again, purely because of the last case. To optimize it, note that once a rectangle is shrinked in this last case, it never has to be shrinked again. Thus, we can maintain all rectangles in a priority queue ordered by their $r_i$, and once we pop a rectangle from the priority queue, we will never have to push it again, which will help us arrive at an amortized $O(n \log n)$ solution.

Instead of a priority queue, we can use some stacks as well — one for each row and maybe an extra one for height $2$ rectangles. The overall time complexity will still be $O(n \log n)$ due to sorting.

 **Source**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> r1(n), c1(n), r2(n), c2(n);
    for (int i = 0; i < n; i++) {
      cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];
      assert(1 <= r1[i] && r1[i] <= r2[i] && r2[i] <= 2 && c1[i] <= c2[i]);
      --c1[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return c1[i] < c1[j];
    });
    set<pair<int, int>> s;
    int ans = 0;
    int p1 = -1;
    int p2 = -1;
    for (int i : order) {
      if (r1[i] == 1 && r2[i] == 2) {
        if (p1 >= c2[i]) {
          r1[i] = 2;
        }
        if (p2 >= c2[i]) {
          r2[i] = 1;
        }
        if (r1[i] > r2[i]) {
          continue;
        }
      }
      if (r1[i] == 1 && r2[i] == 2) {
        while (!s.empty()) {
          auto it = prev(s.end());
          if (it->first >= c1[i]) {
            c2[it->second] = c1[i];
            s.erase(it);
          } else {
            break;
          }
        }
        ans += (c2[i] - max(c1[i], p1)) + (c2[i] - max(c1[i], p2));
        p1 = p2 = c2[i];
        s.emplace(c2[i], i);
        continue;
      }
      assert(r1[i] == r2[i]);
      if (r1[i] == 1) {
        c1[i] = max(c1[i], p1);
        p1 = max(p1, c2[i]);
      } else {
        c1[i] = max(c1[i], p2);
        p2 = max(p2, c2[i]);
      }
      if (c1[i] < c2[i]) {
        ans += c2[i] - c1[i];
        s.emplace(c2[i], i);
      }
    }
    cout << ans << 'n';
    for (int i = 0; i < n; i++) {
      ++c1[i];
      if (r1[i] <= r2[i] && c1[i] <= c2[i]) {
        cout << r1[i] << " " << c1[i] << " " << r2[i] << " " << c2[i] << 'n';
      } else {
        cout << "0 0 0 0" << 'n';
      }
    }
  }
  return 0;
}
```
[1782F - Bracket Insertion](https://codeforces.com/contest/1782/problem/F)

 **Explanation**
### [1782F - Bracket Insertion](https://codeforces.com/contest/1782/problem/F "Codeforces Round 844 (Div. 1 + Div. 2, based on VK Cup 2022 - Elimination Round)")

Instead of looking at a probabilistic process, we can consider all possible ways of inserting brackets. There are $1 \cdot 3 \cdot 5 \cdot \ldots \cdot (2n - 1) = (2n - 1)!!$ ways of choosing places, and $2^n$ ways of choosing "()" or ")(" at every point. Let $r$ be the sum of $p^k \cdot (1-p)^{n-k}$ over all such ways that lead to a regular bracket sequence, where $k$ is the number of strings "()" inserted during the process (and $n - k$ is then the number of strings ")(" inserted). Then, $\frac{r}{(2n - 1)!!}$ is the answer to the problem.

Consider the sequence of "prefix balances" of the bracket sequence. The first (empty) prefix balance is $0$, and each successive balance is $1$ larger than the previous one if the next bracket is '(', and $1$ smaller if the bracket is ')'.

Initially, when the bracket sequence is empty, the sequence of prefix balances is $[0]$. Whenever we insert "()" into the bracket sequence in a place with prefix balance $x$, essentially we are replacing $x$ with $[x, x + 1, x]$ in the sequence of prefix balances. Whenever we insert ")(" instead, that's equivalent to replacing $x$ with $[x, x - 1, x]$.

A bracket sequence is regular if and only if its corresponding sequence of prefix balances does not have any negative integers (and ends with $0$; however, this is guaranteed in our setting).

Thus, we can reformulate the problem as follows: 

* Initially, we have an integer array $[0]$.
* $n$ times, we choose an integer from the array uniformly at random.
* Say this integer is $x$, then we replace $x$ with $[x, x + 1, x]$ with probability $p$, and with $[x, x - 1, x]$ with probability $1 - p$.
* What is the probability that the sequence will not contain negative integers at any point?

Let $f(n, x)$ be the sought probability multiplied by $(2n - 1)!!$ if we start with $[x]$ Here, we multiply by $(2n-1)!!$ to simplify the formulas, and to keep thinking about "numbers of ways" instead of "probabilities", as described in the first paragraph of this tutorial.

The base cases are $f(0, x) = 1$ if $x \ge 0$, and $f(0, x) = 0$ otherwise. When $n > 0$: 

 $f(n, x) =$$= \sum\limits_{i=0}^{n-1} \sum\limits_{j=0}^{n-1-i} p \cdot \binom{n-1}{i} \cdot \binom{n-1-i}{j} \cdot f(i, x) \cdot f(j, x + 1) \cdot f(n - 1 - i - j, x) +$

$+ \sum\limits_{i=0}^{n-1} \sum\limits_{j=0}^{n-1-i} (1 - p) \cdot \binom{n-1}{i} \cdot \binom{n-1-i}{j} \cdot f(i, x) \cdot f(j, x - 1) \cdot f(n - 1 - i - j, x)$. 

What does this formula mean? Essentially, since we start with an array of a single integer $[x]$, the first operation has to be applied to $x$. After that, once $x$ gets replaced with $[x, x \pm 1, x]$, $i$ operations will be applied to the left $x$ (including everything produced from it), $j$ operations will be applied to $x \pm 1$ (again, together with its production), and $n - 1 - i - j$ operations will be applied to the right $x$ (and to its production).

Thus, we can find the sum over $i$ and $j$ of the product of the corresponding values of $f$ and the binomial coefficients: since the sequences of $i$, $j$, and $n - 1 - i - j$ operations can be interleaved arbitrarily, we have $\binom{n-1}{i}$ ways to choose the positions of $i$ operations applied to the left $x$ in the global sequence of $n-1$ operations, and then $\binom{n-1-i}{j}$ ways to choose the positions of $j$ operations applied to $x \pm 1$ out of the remaining $n - 1 - i$ positions in the global sequence.

This results in an $O(n^4)$ solution, since there are $O(n^2)$ values of $f$ to calculate, and each of them is calculated in $O(n^2)$.

To optimize it, let's rewrite the formula a little bit by moving the loop over $j$ outside: 

 $f(n, x) = \sum\limits_{j=0}^{n-1} (p \cdot f(j, x + 1) + (1 - p) \cdot f(j, x - 1)) \cdot \binom{n-1}{j} \cdot \sum\limits_{i=0}^{n-1-j} \binom{n-1-j}{i} \cdot f(i, x) \cdot f(n - 1 - j - i, x)$. Now, let's introduce an auxiliary function: 

 $g(k, x) = \sum\limits_{i=0}^{k} \binom{k}{i} \cdot f(i, x) \cdot f(k - i, x)$. Now, let's rewrite the formula for $f$ using $g$: 

 $f(n, x) = \sum\limits_{j=0}^{n-1} (p \cdot f(j, x + 1) + (1 - p) \cdot f(j, x - 1)) \cdot \binom{n-1}{j} \cdot g(n - 1 - j, x)$. Now, both $g(n, x)$ and $f(n, x)$ can be computed in $O(n)$ time, resulting in an $O(n^3)$ solution.

 **Source**
```cpp
#include <bits/stdc++.h>

using namespace std;

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  Mint p;
  cin >> n >> p;
  p /= 10000;
  vector<vector<Mint>> C(n + 1, vector<Mint>(n + 1));
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  vector<vector<Mint>> dp(n + 1, vector<Mint>(n + 1));
  vector<vector<Mint>> aux(n + 1, vector<Mint>(n + 1));
  for (int b = 0; b <= n; b++) {
    dp[0][b] = aux[0][b] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int b = 0; b <= n - i; b++) {
      for (int y = 0; y <= i - 1; y++) {
        dp[i][b] += C[i - 1][y] * aux[i - 1 - y][b] * (dp[y][b + 1] * p + (b == 0 ? 0 : dp[y][b - 1] * (1 - p)));
      }
      for (int j = 0; j <= i; j++) {
        aux[i][b] += dp[j][b] * dp[i - j][b] * C[i][j];
      }
    }
  }
  auto ans = dp[n][0];
  for (int i = 1; i <= 2 * n; i += 2) {
    ans /= i;
  }
  cout << ans << 'n';
  return 0;
}
```
[1782G - Diverse Coloring](https://codeforces.com/contest/1782/problem/G)

 **Explanation**
### [1782G - Diverse Coloring](https://codeforces.com/contest/1782/problem/G "Codeforces Round 844 (Div. 1 + Div. 2, based on VK Cup 2022 - Elimination Round)")

It turns out that it is always possible to construct a diverse coloring with disbalance $0$ or $1$ (depending on the parity of $n$), except for the case of a tree with $4$ vertices with one vertex of degree $3$ (which is given in the example).

Let's traverse the tree from bottom to top. For each subtree, we will try to construct a diverse coloring where the subtree root is colored white. We will define the disbalance of the subtree coloring to be the number of vertices colored white, minus the number of vertices colored blue. This is equivalent to the original definition, except that now the number also has a sign.

We will aim at obtaining disbalances $0$ and $+1$, if possible. In some small cases, it will be impossible. We will say "subtree has disbalance $x$" or "vertex has disbalance $x$", meaning that we have constructed a coloring of the (vertex's) subtree with disbalance $x$.

Let $u$ be the root of the subtree (colored white): 

* If $u$ has no children, the only coloring has disbalance $+1$; however, it is not diverse. Thus, we will have to be careful about the leaf case in the future.
* If $u$ has one child $v$, flip the colors in $v$'s subtree to create a blue neighbor for $u$:
	+ If $v$ had disbalance $0$ before the flip, now $u$ has disbalance $+1$.
	+ If $u$ had disbalance $+1$ before the flip, now $u$ has disbalance $0$.
* If $u$ has two children $v$ and $w$:
	+ If both have disbalance $0$, flip the colors in at least one of $v$'s and $w$'s subtrees, now $u$ has disbalance $+1$.
	+ If both have disbalance $+1$, flip the colors in either $v$'s or $w$'s subtree, now $u$ has disbalance $+1$.
	+ If one has disbalance $0$ and the other has disbalance $+1$, flip the colors in the one with $0$, now $u$ has disbalance $0$.

The only issue happens when $u$ has two children that are both leaves: we have to recolor both $v$ and $w$ into blue, which will force $u$ to have disbalance $-1$. Let's add new cases to the analysis above based on the existence of subtrees with disbalance $-1$: 

* If $u$ has one child $v$ with disbalance $-1$:
	+ Flip the colors in $v$'s subtree, now $u$ has disbalance $+2$.
* If $u$ has two children $v$ and $w$, where $v$ has disbalance $-1$:
	+ If $w$ has disbalance $-1$, flip the colors in either $v$'s or $w$'s subtree, now $u$ has disbalance $+1$.
	+ If $w$ has disbalance $0$, flip the colors in $w$'s subtree, now $u$ has disbalance $0$.
	+ If $w$ has disbalance $+1$, flip the colors in both $v$'s and $w$'s subtrees, now $u$ has disbalance $+1$.

We can see that, once again, a new case appears where a subtree has disbalance $+2$ (described at the beginning of this tutorial), and unfortunately we can't avoid that. We can see that this case only happens for a specific subtree of $4$ vertices. Let's proceed with the case analysis...

* If $u$ has one child $v$ with disbalance $+2$:
	+ Flip $v$'s color (not the whole subtree, but just $v$), now $u$ has disbalance $+1$.
* If $u$ has two children $v$ and $w$, where $v$ has disbalance $+2$:
	+ If $w$ has disbalance $-1$, flip the colors in both $v$'s and $w$'s subtrees, now $u$ has disbalance $0$.
	+ If $w$ has disbalance $0$, flip $v$'s color, now $u$ has disbalance $+1$.
	+ If $w$ has disbalance $+1$, flip $v$'s color and the colors in $w$'s subtree, now $u$ has disbalance $0$.
	+ If $w$ has disbalance $+2$, flip the colors in either $v$'s or $w$'s subtree, now $u$ has disbalance $+1$.

It follows that for any other tree, except two special cases of a $3$-vertex tree and a $4$-vertex tree, it is possible to obtain disbalance $0$ or $+1$.

From this point, one way to implement the solution is to carefully consider all the cases. Note that whenever we say "flip the colors in $v$'s subtree", we can just set some flag in vertex $v$. Then, as we traverse the tree from top to bottom, we can construct the correct coloring in $O(n)$ time.

Another way is to use dynamic programming f(u, d, hasNeighbor) = true/false: whether it is possible to color $u$'s subtree to obtain disbalance $d$ so that all vertices except $u$ have neighbors of opposite color, and $u$ has such a neighbor iff hasNeighbor = true. Since it is enough to limit disbalance by $O(1)$, we can conclude that the number of states, the number of transitions, and the time complexity are all $O(n)$.

 **Source (2nd approach)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
      cin >> p[i];
      --p[i];
    }
    for (int i = 2; i <= n; i++) {
      if (i == 4 && p[1] == 0 && p[2] == 1 && p[3] == 1) {
        cout << 2 << 'n';
      } else {
        cout << i % 2 << 'n';
      }
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      g[p[i]].push_back(i);
    }
    string res = "";
    auto Solve = [&](int nn) {
      vector<vector<vector<bool>>> good(nn);
      vector<vector<vector<vector<int>>>> prevs(nn);
      vector<int> sz(nn);
      vector<int> L(nn);
      vector<int> R(nn);
      function<void(int)> Dfs = [&](int v) {
        sz[v] += 1;
        for (int u : g[v]) {
          Dfs(u);
          sz[v] += sz[u];
        }
        L[v] = sz[v] / 2;
        R[v] = L[v] + 1;
        good[v].assign(2, vector<bool>(R[v] - L[v] + 1, false));
        prevs[v].assign(2, vector<vector<int>>(R[v] - L[v] + 1));
        auto Set = [&](int c, int k, vector<int> pr) {
          if (k >= L[v] && k <= R[v]) {
            good[v][c][k - L[v]] = true;
            prevs[v][c][k - L[v]] = pr;
          }
        };
        if (g[v].size() == 0) {
          Set(0, 1, {});
        }
        if (g[v].size() == 1) {
          int u = g[v][0];
          for (int cu = 0; cu < 2; cu++) {
            for (int ku = L[u]; ku <= R[u]; ku++) {
              if (good[u][cu][ku - L[u]]) {
                Set(1, 1 + (sz[u] - ku), {cu, ku, 1});
                if (cu == 1) {
                  Set(0, 1 + ku, {cu, ku, 0});
                }
              }
            }
          }
        }
        if (g[v].size() == 2) {
          int u = g[v][0];
          int w = g[v][1];
          for (int cu = 0; cu < 2; cu++) {
            for (int ku = L[u]; ku <= R[u]; ku++) {
              if (good[u][cu][ku - L[u]]) {
                for (int cw = 0; cw < 2; cw++) {
                  for (int kw = L[w]; kw <= R[w]; kw++) {
                    if (good[w][cw][kw - L[w]]) {
                      Set(1, 1 + (sz[u] - ku) + (sz[w] - kw), {cu, ku, 1, cw, kw, 1});
                      if (cu == 1) {
                        Set(1, 1 + ku + (sz[w] - kw), {cu, ku, 0, cw, kw, 1});
                      }
                      if (cw == 1) {
                        Set(1, 1 + (sz[u] - ku) + kw, {cu, ku, 1, cw, kw, 0});
                      }
                      if (cu == 1 && cw == 1) {
                        Set(0, 1 + ku + kw, {cu, ku, 0, cw, kw, 0});
                      }
                    }
                  }
                }
              }
            }
          }
        }
      };
      Dfs(0);
      int best = nn + 1;
      int best_k = -1;
      for (int k = L[0]; k <= R[0]; k++) {
        if (good[0][1][k - L[0]]) {
          int val = abs(k - (nn - k));
          if (val < best) {
            best = val;
            best_k = k;
          }
        }
      }
      assert(best <= nn);
      res = string(nn, '.');
      function<void(int, int, int)> Restore = [&](int v, int c, int k) {
        int ptr = 0;
        for (int u : g[v]) {
          res[u] = (prevs[v][c][k - L[v]][ptr + 2] == 0 ? res[v] : (char) ('w' ^ 'b' ^ res[v]));
          Restore(u, prevs[v][c][k - L[v]][ptr], prevs[v][c][k - L[v]][ptr + 1]);
          ptr += 3;
        }
      };
      res[0] = 'w';
      Restore(0, 1, best_k);
      return best;
    };
    Solve(n);
    cout << res << 'n';
  }
  return 0;
}
```
[1782H1 - Window Signals (easy version)](https://codeforces.com/contest/1782/problem/H1)

 **Explanation**
### [1782H1 - Window Signals (easy version)](https://codeforces.com/contest/1782/problem/H1 "Codeforces Round 844 (Div. 1 + Div. 2, based on VK Cup 2022 - Elimination Round)")

Let's iterate over the dimensions of the bounding box of the image of windows with lights on, $h' \times w'$ ($1 \le h' \le h; 1 \le w' \le w$), count images with such bounding box, and sum all these values up.

An image has a bounding box of size exactly $h' \times w'$ if and only if: 

* it fits inside an $h' \times w'$ rectangle;
* it has a light on each of its four borders.

To account for the second condition, we can use inclusion-exclusion principle. This way, we will have an "it does not have a light on some of its borders" condition instead, at the cost of an extra $2^4$ time factor. We will disregard this condition in the rest of this tutorial.

There are $2^{h'w'}$ possible images fitting in an $h' \times w'$ rectangles. How many of them are impossible to show because of broken lights? Let's find this number and subtract it.

Consider all possible ways to place a rectangle of size $h' \times w'$ on the given $h \times w$ grid: 

* If there are no broken lights inside, any image of size $h' \times w'$ is possible to show, so we don't need to subtract anything for this size at all.
* If there is $1$ broken light inside, its relative position in the $h' \times w'$ rectangle must be turned on (for an image to be impossible to show).
* If there are $2$ broken lights inside, find their relative positions in the $h' \times w'$ rectangle. For an image to be impossible to show, at least one of the two positions must be turned on.

Unless a placement with no broken lights exists, we have some cells in the rectangle where the light must be turned on — let's call the set of these cells $X$, and some pairs of cells where at least one light must be turned on — let's call the set of these pairs $Y$.

If a pair from $Y$ contains a cell from $X$, this pair can be removed from $Y$. Once we do that, note that the pairs from $Y$ form several chains — that happens because the coordinate-wise distance between the cells in each pair is equal to the distance between the broken lights, which is $(r_2 - r_1, c_2 - c_1)$.

If we have a chain of length $p$, it can be seen that there are $f(p)$ ways to turn lights on so that every pair of neighboring cells has at least one light, where $f(p) = f(p - 1) + f(p - 2)$ are Fibonacci numbers.

Thus, the number to subtract is the product of: 

* $2^w$, where $w$ is the number of cells not included in $X$ and $Y$;
* $f(p)$ over all chains formed by $Y$, where $p$ is the length of a chain.

Every subgrid size $h' \times w'$ is processed in $O(hw)$ time, and there are $hw$ different sizes, thus, the overall time complexity is $O(h^2 w^2)$.

It is possible to optimize the constant factor of this solution to pass the hard version too. However, a solution of $O(h w^2)$ time complexity exists as well. Here is a sketch of it: 

* Instead of fixing both dimensions of the lights image, $h'$ and $w'$, let's only fix $w'$.
* Use inclusion-exclusion like described at the beginning of this tutorial; however, only use it for the top, left, and right borders. We will not use it for the bottom border, since we are not fixing the height of the image.
* Go through all top-left corners $(i, j)$ of the lights image in lexicographic order ($1 \le i \le h; 1 \le j \le w - w' + 1$).
* For each top-left corner, count how many images of width $w'$ can be shown using this top-left corner, which can not be shown using any previous top-left corner.
* Similarly to the previous solution, consider cases of $0$, $1$, and $2$ broken lights inside the current subgrid. Note, however, that we are not fixing the height of the subgrid, so just assume that it stretches all the way down to the bottom border of the whole grid.
* Maintain the set of cells $X$ using an array, and maintain the set of pairs $Y$ using linked lists.
* Once a cell joins set $X$, remove all pairs that touch it from set $Y$. Once a pair joins set $Y$, if neither of its ends belongs to $X$, merge two corresponding linked lists.
* Maintain a variable denoting the product of $f(p)$ over all chains formed by $Y$. Once any split or merge happens to the lists, update this variable using $O(1)$ multiplications/divisions.
* Whenever $i$ (the row number of the top-left corner) increases by $1$, the maximum available height of the lights image decreases by $1$. Thus, we have to "remove" the cells in the current bottom row: that is, for any future image, we won't be able to light up those cells. If any such cell belongs to $X$, just stop: we won't get any new images. Otherwise, if such a cell belongs to a pair in $Y$, add the second end of this pair to $X$.
* For fixed width $w'$ and for each top-left corner $(i, j)$, we need to spend $O(1)$ time. Moreover, for fixed width $w'$, once $i$ increases (which happens $O(h)$ times), we need to spend $O(w)$ time to process cell removals. Hence, the time complexity of both parts is $O(h w^2)$.
 **Source for easy version**
```cpp
#include <bits/stdc++.h>

using namespace std;

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w, k;
    cin >> h >> w >> k;
    vector<Mint> fib(h * w + 1);
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i <= h * w; i++) {
      fib[i] = fib[i - 1] + fib[i - 2];
    }
    vector<pair<int, int>> p(k);
    for (int i = 0; i < k; i++) {
      cin >> p[i].first >> p[i].second;
      --p[i].first; --p[i].second;
    }
    long long Q = 0;
    Mint ans = 0;
    for (int ww = 1; ww <= w; ww++) {
      for (int hh = 1; hh <= h; hh++) {
        for (int top = 0; top < 2; top++) {
          for (int bottom = 0; bottom < 2; bottom++) {
            for (int left = 0; left < 2; left++) {
              for (int right = 0; right < 2; right++) {
                int sign = ((top + bottom + left + right) % 2 == 0 ? 1 : -1);
                int rh = max(0, hh - top - bottom);
                int rw = max(0, ww - left - right);
                Q += rh * rw + (h - hh) * (w - ww);
                ans += sign * power(Mint(2), rh * rw);
                vector<vector<int>> g(hh * ww);
                vector<bool> must(hh * ww, false);
                bool any = false;
                for (int i = 0; i <= h - hh; i++) {
                  for (int j = 0; j <= w - ww; j++) {
                    vector<pair<int, int>> here;
                    for (auto& c : p) {
                      if (c.first >= i + top && c.first < i + hh - bottom && c.second >= j + left && c.second < j + ww - right) {
                        here.emplace_back(c.first - i - top, c.second - j - left);
                      }
                    }
                    if (here.size() == 0) {
                      any = true;
                    }
                    if (here.size() == 1) {
                      int x = here[0].first * rw + here[0].second;
                      must[x] = true;
                    }
                    if (here.size() == 2) {
                      int x = here[0].first * rw + here[0].second;
                      int y = here[1].first * rw + here[1].second;
                      g[x].push_back(y);
                      g[y].push_back(x);
                    }
                  }
                }
                if (!any) {
                  Mint ways = 1;
                  vector<bool> was(rh * rw, false);
                  for (int i = 0; i < rh * rw; i++) {
                    if (!was[i] && g[i].empty()) {
                      was[i] = true;
                      if (!must[i]) {
                        ways *= 2;
                      }
                    }
                  }
                  for (int i = 0; i < rh * rw; i++) {
                    if (!was[i] && g[i].size() == 1) {
                      vector<bool> seq;
                      int x = i;
                      while (true) {
                        was[x] = true;
                        seq.push_back(must[x]);
                        int to = -1;
                        for (int y : g[x]) {
                          if (!was[y]) {
                            to = y;
                            break;
                          }
                        }
                        if (to == -1) {
                          break;
                        }
                        x = to;
                      }
                      int sz = (int) seq.size();
                      int beg = 0;
                      while (beg < sz) {
                        if (seq[beg]) {
                          beg += 1;
                          continue;
                        }
                        int end = beg;
                        while (end + 1 < sz && !seq[end + 1]) {
                          end += 1;
                        }
                        int len = end - beg + 1;
                        ways *= fib[len];
                        beg = end + 1;
                      }
                    }
                  }
                  assert(was == vector<bool>(rh * rw, true));
                  ans -= sign * ways;
                }
              }
            }
          }
        }
      }
    }
    cout << ans << 'n';
  }
  return 0;
}
```
 **Source for hard version**
```cpp
#include <bits/stdc++.h>

using namespace std;

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

class dsu {
 public:
  vector<int> p;
  vector<int> sz;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.assign(n, 1);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      return true;
    }
    return false;
  }
};

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w, k;
    cin >> h >> w >> k;
    vector<Mint> fib(h * w + 1);
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i <= h * w; i++) {
      fib[i] = fib[i - 1] + fib[i - 2];
    }
    vector<pair<int, int>> p(k);
    for (int i = 0; i < k; i++) {
      cin >> p[i].first >> p[i].second;
      --p[i].first; --p[i].second;
    }
    Mint ans = 0;
    for (int ww = 1; ww <= w; ww++) {
      for (int top = 0; top < 2; top++) {
        for (int left = 0; left < 2; left++) {
          for (int right = 0; right < 2; right++) {
            if (ww == 1 && left + right > 0) {
              continue;
            }
            int sign = ((top + left + right) % 2 == 0 ? 1 : -1);
            dsu d(h * ww);
            vector<vector<int>> g(h * ww);
            vector<bool> must(h * ww);
            bool done = false;
            Mint prod = power(Mint(2), (h - top) * (ww - left - right));
            for (int i = 0; i < h; i++) {
              for (int j = 0; j <= w - ww; j++) {
                vector<pair<int, int>> here;
                for (auto& c : p) {
                  if (c.first >= i + top && c.second >= j + left && c.second < j + ww - right) {
                    here.emplace_back(c.first - i, c.second - j);
                  }
                }
                if (here.size() == 0) {
                  ans += sign * prod;
                  done = true;
                  break;
                }
                if (here.size() == 1) {
                  int x = here[0].first * ww + here[0].second;
                  if (!must[x]) {
                    must[x] = true;
                    int px = d.get(x);
                    prod /= fib[d.sz[px]];
                    d.sz[px] -= 1;
                    int sub = 0;
                    for (int y : g[x]) {
                      if (!must[y]) {
                        sub += 1;
                      }
                    }
                    ans += sign * prod * fib[d.sz[px] - sub];
                    prod *= fib[d.sz[px]];
                  }
                }
                if (here.size() == 2) {
                  int x = here[0].first * ww + here[0].second;
                  int y = here[1].first * ww + here[1].second;
                  int px = d.get(x);
                  int py = d.get(y);
                  assert(px != py);
                  prod /= fib[d.sz[px]];
                  prod /= fib[d.sz[py]];
                  if (!must[x] && !must[y]) {
                    int subx = 1;
                    for (int t : g[x]) {
                      if (!must[t]) {
                        subx += 1;
                      }
                    }
                    int suby = 1;
                    for (int t : g[y]) {
                      if (!must[t]) {
                        suby += 1;
                      }
                    }
                    ans += sign * prod * fib[d.sz[px] - subx] * fib[d.sz[py] - suby];
                    g[x].push_back(y);
                    g[y].push_back(x);
                  }
                  d.unite(px, py);
                  prod *= fib[d.sz[py]];
                }
              }
              if (done) {
                break;
              }
              for (int j = left; j < ww - right; j++) {
                int x = (h - 1 - i) * ww + j;
                if (must[x]) {
                  done = true;
                  break;
                }
                int px = d.get(x);
                prod /= fib[d.sz[px]];
                d.sz[px] -= 1;
                prod *= fib[d.sz[px]];
                for (int y : g[x]) {
                  if (!must[y]) {
                    must[y] = true;
                    int py = d.get(y);
                    prod /= fib[d.sz[py]];
                    d.sz[py] -= 1;
                    prod *= fib[d.sz[py]];
                  }
                }
              }
              if (done) {
                break;
              }
            }
          }
        }
      }
    }
    cout << ans << 'n';
  }
  return 0;
}
```
