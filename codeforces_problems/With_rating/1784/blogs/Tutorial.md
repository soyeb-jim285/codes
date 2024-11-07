# Tutorial

[1786A2 - Alternating Deck (hard version)](https://codeforces.com/contest/1786/problem/A2 "Codeforces Round 850 (Div. 2, based on VK Cup 2022 - Final Round)")

Problem author: [KAN](https://codeforces.com/profile/KAN "Legendary Grandmaster KAN")

 **Explanation**
### [1786A2 - Alternating Deck (hard version)](https://codeforces.com/contest/1786/problem/A2 "Codeforces Round 850 (Div. 2, based on VK Cup 2022 - Final Round)")

Note that on the $i$-th step, Alice takes $i$ cards from the deck. It means that after $k$ steps, $\frac{k(k + 1)}{2}$ steps are taken from the deck. Thus, after $O(\sqrt{n})$ steps, the deck is empty. We can simulate the steps one by one by taking care of whose turn it is and what is the color of the top card. Using this information, we can keep track of how many cards of what color each player has. Print this information in the end.

 **Code by KAN**
```cpp
NT = int(input())
 
for T in range(NT):
	n = int(input())
	answer = [0, 0, 0, 0]
	first_card = 1
	for it in range(1, 20000):
		who = 0 if it % 4 == 1 or it % 4 == 0 else 1
		cnt = it
		if n < cnt:
			cnt = n
		cnt_white = (cnt + first_card % 2) // 2
		cnt_black = cnt - cnt_white
		answer[who * 2 + 0] += cnt_white
		answer[who * 2 + 1] += cnt_black
		first_card += cnt
		n -= cnt
		if n == 0:
			break
	assert(n == 0)
	print(*answer)
 
```
[1786B - Cake Assembly Line](https://codeforces.com/contest/1786/problem/B "Codeforces Round 850 (Div. 2, based on VK Cup 2022 - Final Round)")

Problem author: [KAN](https://codeforces.com/profile/KAN "Legendary Grandmaster KAN")

 **Explanation**Tutorial is loading... **Code by KAN**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int minshift = -inf;
    int maxshift = inf;
    for (int i = 0; i < n; i++) {
      minshift = max(minshift, (b[i] + h) - (a[i] + w));
      maxshift = min(maxshift, (b[i] - h) - (a[i] - w));
    }
    if (minshift <= maxshift) {
      cout << "YES" << 'n';
    } else {
      cout << "NO" << 'n';
    }
  }
  return 0;
}
```
[1785A - Monsters (easy version)](https://codeforces.com/contest/1785/problem/A "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

Problem author: [tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist")

 **Explanation**
### [1785A - Monsters (easy version)](https://codeforces.com/contest/1785/problem/A "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

First, let's prove that it's always optimal to use a spell of type 2 as your last spell in the game and kill all monsters with it. Indeed, suppose you use a spell of type 2 earlier and it deals $x$ damage to all monsters. Suppose that some monsters are still alive. For any such monster, say they had $y$ health points before the spell of type 2, and $y > x$. Then, you will need to cast $y-x$ more spells of type 1 to kill it afterwards. But you could just cast these $y-x$ spells of type 1 on this monster before casting the spell of type 2. Thus, you can move all usages of spells of type 1 before the usage of the spell of type 2 without changing the answer.

Without loss of generality, assume that $a_1 \le a_2 \le \ldots \le a_n$. Let $b_i$ be the amount of health points monster $i$ has right before the spell of type 2 is cast ($1 \le b_i \le a_i$). Then, the number of spells of type 1 needed is $\sum \limits_{i=1}^n (a_i - b_i)$, which means we want to maximize $\sum \limits_{i=1}^n b_i$.

Note that we can rearrange $b$ so that $b_1 \le b_2 \le \ldots \le b_n$: since $a$ is sorted too, the $b_i \le a_i$ condition will still hold.

Also, since all monsters must be killed by a spell of type 2 afterwards, $b_{i+1} - b_i \le 1$ must hold.

Thus, we should go through all monsters in non-decreasing order of $a_i$ and decide their $b_i$ greedily, picking the largest value satisfying both $b_i \le a_i$ and $b_i \le b_{i-1} + 1$. Specifically, we should choose $b_1 = 1$ and $b_i = \min(a_i, b_{i-1} + 1)$.

 **Code by tourist**
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
    vector<int> b(n);
    b[0] = 1;
    for (int i = 1; i < n; i++) {
      b[i] = min(b[i - 1] + 1, a[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += a[i] - b[i];
    }
    cout << ans << 'n';
  }
  return 0;
}
```
[1785B - Letter Exchange](https://codeforces.com/contest/1785/problem/B "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

Problem author: [tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist")

 **Explanation**
### [1785B - Letter Exchange](https://codeforces.com/contest/1785/problem/B "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

For each person, there are three essential cases of what they could initially have: 

1. Three distinct letters: "win". No need to take part in any exchanges.
2. Two equal letters and another letter, e.g. "wii". An extra 'i' must be exchanged with someone's 'n'.
3. Three equal letters, e.g. "www". One 'w' must be exchanged with someone's 'i', another 'w' must be exchanged with someone's 'n'.

Let's create a graph on three vertices: 'w', 'i', 'n'. Whenever person $i$ has an extra letter $x$ and is lacking letter $y$, create a directed edge $x \rightarrow y$ marked with $i$.

Once the graph is built, whenever you have a cycle of length $2$, that is, $x \xrightarrow{i} y \xrightarrow{j} x$, it means person $i$ needs to exchange $x$ for $y$, while person $j$ needs to exchange $y$ for $x$. Thus, both of their needs can be satisfied with just one exchange.

Finally, once there are no cycles of length $2$, note that the in-degree and the out-degree of every vertex are equal. If e.g. there are $p$ edges 'w' $\rightarrow$ 'i', it follows that there are $p$ edges 'i' $\rightarrow$ 'n' and $p$ edges 'n' $\rightarrow$ 'w'. It means we can form $p$ cycles of length $3$. (The cycles could also go in the opposite direction: 'w' $\rightarrow$ 'n' $\rightarrow$ 'i' $\rightarrow$ 'w'.) In any case, each cycle of length $3$ can be solved using $2$ exchanges. 

 **Code by PavelKunyavskiy**
```cpp
private fun IntArray.countOf(value: Int) = count { it == value }

private fun solve() {
    val s = "win"
    fun IntArray.bad() = (0 until 3).singleOrNull { c -> count { it == c } > 1 }
    val data = List(readInt()) { readLn().map { s.indexOf(it) }.toIntArray() }
    val ans = mutableListOf<String>()
    fun exchange(c1: Int, c2: Int, i1: Int, i2: Int) {
        ans.add("${i1+1} ${s[c1]} ${i2+1} ${s[c2]}")
        val index1 = data[i1].indexOf(c1)
        val index2 = data[i2].indexOf(c2)
        data[i1][index1] = c2
        data[i2][index2] = c1
    }
    val todo = List(3) { List(3) { mutableListOf<Int> () } }
    for (i in data.indices) {
        val bad = data[i].bad() ?: continue
        for (j in 0 until 3) {
            if (data[i].countOf(j) == 0) {
                todo[bad][j].add(i)
            }
        }
    }

    for (i in 0 until 3) {
        for (j in 0 until 3) {
            if (i != j) {
                while (todo[i][j].isNotEmpty() && todo[j][i].isNotEmpty()) {
                    exchange(i, j, todo[i][j].removeLast(), todo[j][i].removeLast())
                }
            }
        }
    }
    while (todo[0][1].isNotEmpty() && todo[1][2].isNotEmpty() && todo[2][0].isNotEmpty()) {
        val a = todo[0][1].removeLast()
        val b = todo[1][2].removeLast()
        val c = todo[2][0].removeLast()
        exchange(0, 1, a, b)
        exchange(0, 2, b, c)
    }
    while (todo[1][0].isNotEmpty() && todo[2][1].isNotEmpty() && todo[0][2].isNotEmpty()) {
        val a = todo[1][0].removeLast()
        val b = todo[2][1].removeLast()
        val c = todo[0][2].removeLast()
        exchange(1, 0, a, c)
        exchange(2, 1, b, c)
    }
    println(ans.size)
    println(ans.joinToString("n"))
}

fun main() {
    repeat(readInt()) {
        solve()
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
```
[1785C - Monsters (hard version)](https://codeforces.com/contest/1785/problem/C "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

Problem author: [tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist")

 **Explanation**
### [1785C - Monsters (hard version)](https://codeforces.com/contest/1785/problem/C "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

Continuing on the solution to the easy version: now we have a set of integers $A$, we need to add elements into $A$ one by one and maintain the answer to the problem.

Recall that for every $i$, either $b_i = b_{i-1}$ or $b_i = b_{i-1} + 1$. Note that $b_i = b_{i-1}$ can only happen when $b_i = a_i$. Let's call such an element useless. If we remove a useless element, the answer does not change.

If there are no useless elements, we have $b_1 = 1$ and $b_i = b_{i-1} + 1$ for $i > 1$: that is, $b_i = i$. Thus, the answer to the problem can be easily calculated as $\sum \limits_{i=1}^m (a_i - b_i) = \sum \limits_{i=1}^m a_i - \frac{m(m+1)}{2}$, where $m$ is the current size of the set.

We can formulate the condition "there are no useless elements" as follows. For any $x$, let $k_x$ be the number of elements in $A$ not exceeding $x$. Then, $k_x \le x$.

On the other hand, suppose that for some $x$, we have $k_x > x$. Let's find the smallest such $x$. Then, we can see that $A$ contains a useless element equal to $x$, and we can safely remove it.

We can check this condition after adding each new element to $A$ using a segment tree. In every cell $x$ of the array maintained by the segment tree, we will store the difference $x - k_x$. Initially, cell $x$ contains value $x$. When a new element $v$ appears, we should subtract $1$ from all cells in range $[v; n]$. Then, if a cell with a negative value appears (that is, $x - k_x < 0$, which is equivalent to $k_x > x$), we should find the leftmost such cell $x$ and remove an element equal to $x$. In particular, we should add $1$ to all cells in range $[x; n]$.

Thus, we can use a segment tree with "range add" and "global min". At most one useless element can appear every time we enlarge $A$, and if that happens, we can identify and remove it in $O(\log n)$, resulting in an $O(n \log n)$ time complexity.

 **Code by tourist**
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
    vector<int> mn(2 * n - 1);
    vector<int> add(2 * n - 1, 0);
    vector<int> pos(2 * n - 1);
    auto Pull = [&](int x, int z) {
      mn[x] = min(mn[x + 1], mn[z]) + add[x];
      pos[x] = (mn[x + 1] <= mn[z] ? pos[x + 1] : pos[z]);
    };
    function<void(int, int, int, int, int, int)> Modify = [&](int x, int l, int r, int ll, int rr, int v) {
      if (ll <= l && r <= rr) {
        mn[x] += v;
        add[x] += v;
        return;
      }
      int y = (l + r) >> 1;
      int z = x + 2 * (y - l + 1);
      if (ll <= y) {
        Modify(x + 1, l, y, ll, rr, v);
      }
      if (rr > y) {
        Modify(z, y + 1, r, ll, rr, v);
      }
      Pull(x, z);
    };
    function<void(int, int, int)> Build = [&](int x, int l, int r) {
      if (l == r) {
        mn[x] = l;
        pos[x] = l;
        return;
      }
      int y = (l + r) >> 1;
      int z = x + 2 * (y - l + 1);
      Build(x + 1, l, y);
      Build(z, y + 1, r);
      Pull(x, z);
    };
    Build(0, 1, n);
    long long s = 0;
    long long m = 0;
    for (int i = 0; i < n; i++) {
      s += a[i];
      m += 1;
      Modify(0, 1, n, a[i], n, -1);
      if (mn[0] < 0) {
        s -= pos[0];
        m -= 1;
        Modify(0, 1, n, pos[0], n, +1);
      }
      cout << s - m * (m + 1) / 2 << " n"[i == n - 1];
    }
  }
  return 0;
}
```
[1785D - Wooden Spoon](https://codeforces.com/contest/1785/problem/D "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

Problem author: [tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist")

 **Explanation**
### [1785D - Wooden Spoon](https://codeforces.com/contest/1785/problem/D "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

Let's focus on the sequence of players beating each other $1 = a_0 < a_1 < \ldots < a_n$: $a_0$ is the tournament champion, $a_0$ beats $a_1$ in the last match, $a_1$ beats $a_2$ in the second-to-last match, $\ldots$, $a_{n-1}$ beats $a_n$ in the first match.

For a fixed such sequence, how many ways are there to fill the tournament bracket?

Let's look at the sequence in reverse.

There are $2^n$ ways to put player $a_n$ somewhere.

Player $a_{n-1}$ has to be the opponent of player $a_n$ in the first match.

Player $a_{n-2}$ has to beat some player $b > a_{n-2}$ in the first match, and then beat $a_{n-1}$ in the second match. There are $2^n - a_{n-2} - 2$ ways to choose player $b$ (since it can not be equal to $a_{n-1}$ and $a_n$), and there are also $2$ ways to order $a_{n-2}$ and $b$.

Player $a_{n-3}$ has to be the winner of a subbracket containing $3$ other players $c_1, c_2, c_3 > a_{n-3}$, and then beat $a_{n-2}$ in the third match. There are $2^n - a_{n-3} - 4$ players to choose $c_i$ from (since they can not be equal to $a_{n-2}$, $a_{n-1}$, $a_n$, and $b$), and there are $\binom{2^n - a_{n-3} - 4}{3}$ ways to do so, and there are also $4!$ ways to order $a_{n-3}$, $c_1$, $c_2$, and $c_3$.

In general, player $a_{n - i}$ has to be the winner of a subbracket containing $2^{i-1} - 1$ other players, and there are $2^n - a_{n-i} - 2^{i-1}$ players to choose from, and there are $\binom{2^n - a_{n-i} - 2^{i-1}}{2^{i-1} - 1}$ ways to choose, and also $(2^{i-1})!$ ways to order this subbracket.

You can see that the total number of brackets for a fixed sequence $1 = a_0 < a_1 < \ldots < a_n$ can be represented as $f(a_0, 0) \cdot f(a_1, 1) \cdot \ldots \cdot f(a_{n-1}, n-1) \cdot f(a_n, n)$, where $f(a_i, i)$ is some function of a player number and a round number.

Now let's use dynamic programming: let $d(a_i, i)$ be the sum of products of $f(a_0, 0) \cdot f(a_1, 1) \cdot \ldots \cdot f(a_i, i)$ over all sequences $1 = a_0 < a_1 < \ldots < a_i$. Then: 

* $d(1, 0) = f(1, 0)$;
* $d(a_0, 0) = 0$ for $a_0 > 1$;
* $d(a_i, i) = f(a_i, i) \cdot \sum \limits_{a_{i-1}=1}^{a_i-1} d(a_{i-1}, i-1)$ for $i > 0$.

The answer for player $x$ is $d(x, n)$.

This DP has $O(n \cdot 2^n)$ states, and note that the inner sums in the formulas for $d(a_i, i)$ and $d(a_i + 1, i)$ only differ by one summand. Thus, by using cumulative sums for transitions, we can achieve an $O(n \cdot 2^n)$ time complexity.

 **Code by tourist**
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
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }

 private:
  Type value;
};

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  C(1 << n, 0);
  vector<Mint> dp(1 << n);
  dp[0] = (1 << n) * fact[1 << (n - 1)];
  for (int rd = n - 2; rd >= 0; rd--) {
    vector<Mint> new_dp(1 << n);
    Mint sum = 0;
    for (int i = 0; i < (1 << n); i++) {
      new_dp[i] = sum * C((1 << n) - 1 - i - (1 << rd), (1 << rd) - 1) * fact[1 << rd];
      sum += dp[i];
    }
    swap(dp, new_dp);
  }
  Mint sum = 0;
  for (int i = 0; i < (1 << n); i++) {
    cout << sum() << 'n';
    sum += dp[i];
  }
  return 0;
}
```
[1785E - Infinite Game](https://codeforces.com/contest/1785/problem/E "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

Problem author: [tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist")

 **Explanation**
### [1785E - Infinite Game](https://codeforces.com/contest/1785/problem/E "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

For a fixed game scenario $s$, let's build a weighted functional graph on $4$ vertices that correspond to set scores $0:0$, $1:0$, $0:1$, and $1:1$. For each score $x$, traverse the scenario from left to right, changing the score after each letter, and starting a new set whenever necessary. If the set score by the end of the scenario is $y$, add a directed edge from $x$ to $y$. The weight of this edge is the number of sets Alice wins during the process, minus the number of sets Bob wins.

When we have built such a graph for a game scenario $s$, we can easily decide whether $s$ is winning for Alice, tied, or winning for Bob. Starting from vertex $0:0$, move by the outgoing edges until you arrive at a cycle. In the cycle, find the sum the edge weights. If the sum is positive, the scenario is winning for Alice; if the sum is $0$, the scenario is tied; if the sum is negative, the scenario is winning for Bob.

Now we can use dynamic programming. Let $f(i, \{u_0, u_1, u_2, u_3\}, \{w_0, w_1, w_2, w_3\})$ be the number of ways to choose $s_1 s_2 \ldots s_i$ so that edges from vertices $0, 1, 2, 3$ go to vertices $u_0, u_1, u_2, u_3$ and have weights $w_0, w_1, w_2, w_3$, respectively. Even though this DP has $O(n^5)$ states, it might be possible to get this solution accepted if you only visit reachable states and optimize your solution's constant factor.

However, here's an idea that drastically improves the time complexity. Note that in the end, we are only interested in the sum of some $w_j$, and not in every value separately. Outside of our DP, let's fix the mask of vertices that will lie on the cycle reachable from $0:0$. In the DP state, we can just store the sum $s$ of $w_j$ over $j$ belonging to this mask: $f(i, \{u_0, u_1, u_2, u_3\}, s)$. In the end, we will look at the values of $u_0, u_1, u_2, u_3$ and check if the cycle in our graph is indeed the one we want; only if that's true, we will add the DP value to the overall answer.

This way, at the cost of running the DP $2^4$ times, we have cut the number of states to $O(n^2)$. The overall time complexity of this solution is $O(n^2)$ too, although the constant factor is huge.

 **Code by tourist**
```cpp
#include <bits/stdc++.h>

using namespace std;

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
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int len = (int) s.size();
  vector<Mint> ans(3);
  for (int use = 1; use < (1 << 4); use++) {
    int pw = 1 << 8;
    int init = 0;
    for (int i = 0; i < 4; i++) {
      init += i << (2 * i);
    }
    vector<vector<int>> go_state(pw, vector<int>(2));
    vector<vector<int>> go_diff(pw, vector<int>(2));
    for (int state = 0; state < pw; state++) {
      for (int put = 0; put < 2; put++) {
        int new_diff = 0;
        int new_state = 0;
        for (int i = 0; i < 4; i++) {
          int to = (state >> (2 * i)) & 3;
          if (put == 0) {
            if (to & 1) {
              if (use & (1 << i)) {
                new_diff += 1;
              }
              to = 0;
            } else {
              to |= 1;
            }
          } else {
            if (to & 2) {
              if (use & (1 << i)) {
                new_diff -= 1;
              }
              to = 0;
            } else {
              to |= 2;
            }
          }
          new_state += to << (2 * i);
        }
        go_state[state][put] = new_state;
        go_diff[state][put] = new_diff;
      }
    }
    int limit = (len + 1) / 2 * 2 * __builtin_popcount(use);
    vector<vector<Mint>> dp(2 * limit + 1, vector<Mint>(pw));
    dp[limit][init] = 1;
    for (char c : s) {
      vector<vector<Mint>> new_dp(2 * limit + 1, vector<Mint>(pw));
      for (int sum = 0; sum < (int) dp.size(); sum++) {
        for (int state = 0; state < pw; state++) {
          if (dp[sum][state] == 0) {
            continue;
          }
          for (int put = 0; put < 2; put++) {
            if ((put == 0 && c == 'b') || (put == 1 && c == 'a')) {
              continue;
            }
            int new_sum = sum + go_diff[state][put];
            int new_state = go_state[state][put];
            new_dp[new_sum][new_state] += dp[sum][state];
          }
        }
      }
      swap(dp, new_dp);
    }
    for (int sum = 0; sum < (int) dp.size(); sum++) {
      for (int state = 0; state < pw; state++) {
        if (dp[sum][state] == 0) {
          continue;
        }
        vector<int> to(4);
        for (int i = 0; i < 4; i++) {
          to[i] = (state >> (2 * i)) & 3;
        }
        vector<int> seq(1, 0);
        while (true) {
          int nxt = to[seq.back()];
          bool done = false;
          for (int i = 0; i < (int) seq.size(); i++) {
            if (seq[i] == nxt) {
              done = true;
              seq.erase(seq.begin(), seq.begin() + i);
              break;
            }
          }
          if (done) {
            break;
          }
          seq.push_back(nxt);
        }
        int real_use = 0;
        for (int x : seq) {
          real_use |= (1 << x);
        }
        if (use == real_use) {
          ans[sum > limit ? 0 : (sum < limit ? 2 : 1)] += dp[sum][state];
        }
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    cout << ans[i]() << 'n';
  }
  return 0;
}
```
[1785F - Minimums or Medians](https://codeforces.com/contest/1785/problem/F "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

Problem author: [tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist")

 **Explanation**
### [1785F - Minimums or Medians](https://codeforces.com/contest/1785/problem/F "Codeforces Round 850 (Div. 1, based on VK Cup 2022 - Final Round)")

Let's denote removing minimums with L, and removing medians with M. Now a sequence of Vika's actions can be described with a string $s$ of length $k$ consisting of characters L and M.

Observe that if we have a substring LMM, we can replace it with MLM, and the set of removed numbers will not change. We can keep applying this transformation until there are no LMM substrings in $s$.

Now, a string $s$ of our interest looks as a concatenation of: 

1. $p$ letters M, for some $0 \le p \le k$;
2. if $p < k$, then a letter L;
3. $\max(0, k - 1 - p)$ letters L and M, without two letters M in a row.

Let's denote the number of letters M in part 3 above as $q$.

Can different strings still lead to equal sets in the end?

First, let's suppose that $k \le \frac{n - 1}{2}$. We will prove that all strings that match the above pattern result in distinct integer sets.

Part 1 in the above concatenation means that integers from $n-p+1$ to $n+p$ are removed. Since there are $k-p-q$ letters L in $s$ in total, integers from $1$ to $2(k-p-q)$ are removed too. However, integers in the range $[2(k-p-q) + 1; n-p]$ are not removed, and note that $2(k-p-q)+1 \le n-p$ is equivalent to $k \le \frac{n+p+2q-1}{2}$. Hence, this range is never empty when $k \le \frac{n - 1}{2}$. Thus, we can see that for all pairs of $p$ and $q$, the leftmost non-removed ranges are distinct.

Now, also note that in part 3 of the concatenation, any letter M always removes some two consecutive integers (since there is no substring MM), and letters L serve as "shifts" for these removals, and different sets of "shifts" result in different final sets of integers. This finishes the proof.

It is easy to find the number of ways to fill part 3 for fixed $p$ and $q$: there are $\binom{(k - 1 - p) - (q - 1)}{q}$ ways to choose $q$ positions out of $(k - 1 - p)$ so that no two consecutive positions are chosen. Now we have just iterate over all valid pairs of $p$ and $q$ to get an $O(n^2)$ solution for the $k \le \frac{n - 1}{2}$ case.

Before optimizing it to $O(n)$, let's get back to the $k > \frac{n - 1}{2}$ case. Some strings can result in the same final set. Let $x$ be the smallest integer in the final set. Note that $x$ is always odd. We will only look for a string that contains $\frac{x - 1}{2}$ letters L: that is, a string that removes integers from $1$ to $x-1$ only via removing minimums. We can see that there is always a unique such string.

Recall the uniqueness proof for $k \le \frac{n - 1}{2}$. When $p > 0$, we will now force that leftmost non-removed range, $[2(k-p-q) + 1; n-p]$, to be non-empty. If the range is empty, our sequence of actions does not satisfy the condition from the previous paragraph, so we can skip this pair of $p$ and $q$. 

When $p = 0$, things are a bit different. Suppose we have fixed $q$. It means there are $k-q$ letters L in the string. These operations remove integers from $1$ to $2(k-q)$. Thus, we need the first letter M to remove integers strictly greater than $2(k-q)+1$, which gives us a lower bound on the number of letters L at the start of the string. Otherwise, we can use the same binomial coefficient formula for counting.

This should finish the $O(n^2)$ solution for any $k$.

To optimize it, let's iterate over $q$ first and iterate over $p$ inside. It turns out that all valid values of $p$ form a range, and if we look at what we are summing up, it is $\binom{0}{q} + \binom{1}{q} + \ldots + \binom{r}{q}$ for some integer $r$. This sum is equal to $\binom{r+1}{q+1}$ by the hockey-stick identity. Thus, we finally have an $O(n)$ solution.

 **Code by tourist, O(n^2)**
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
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }

 private:
  Type value;
};

template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  Mint ans = 1;
  for (int p = 1; p <= k; p++) {
    for (int q = 0; q <= max(0, k - 1 - p); q++) {
      if (2 * (k - p - q) + 1 <= n - p) {
        ans += (q == 0 ? 1 : C((k - 1 - p) - (q - 1), q));
      }
    }
  }
  for (int q = 1; q <= k - 1; q++) {
    int pos = 2 * (k - q) + 2;
    int shifts = max(1, pos - n);
    int left = k - shifts;
    ans += C(left - (q - 1), q);
  }
  cout << ans() << 'n';
  return 0;
}
```
 **Code by tourist, O(n)**
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
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }

 private:
  Type value;
};

template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  Mint ans = 1;
  for (int q = 0; q <= k - 1; q++) {
    int bound = k - q - max(1, 2 * (k - q) - n + 1);
    ans += C(bound + 1, q + 1);
  }
  for (int q = 1; q <= k - 1; q++) {
    int pos = 2 * (k - q) + 2;
    int shifts = max(1, pos - n);
    int left = k - shifts;
    ans += C(left - (q - 1), q);
  }
  cout << ans() << 'n';
  return 0;
}
```
