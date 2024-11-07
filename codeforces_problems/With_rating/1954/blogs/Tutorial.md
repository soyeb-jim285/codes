# Tutorial

[1954A - Painting the Ribbon](../problems/A._Painting_the_Ribbon.md "Educational Codeforces Round 164 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1954A - Painting the Ribbon](../problems/A._Painting_the_Ribbon.md "Educational Codeforces Round 164 (Rated for Div. 2)")

When is Bob able to get a ribbon where each part has color $i$? There should be at least $n-k$ parts of color $i$. So if the number of parts with color $i$ is less than $n-k$, Bob cannot repaint the whole ribbon into color $i$.

So, Alice has to paint the ribbon in such a way that for every color, there are at most $n-k-1$ parts of that color. There are at least two ways to check if it is possible: for example, you can calculate the maximum possible length of the ribbon such that it contains no more than $n-k-1$ parts of every color; or you can calculate the maximum number of parts among all colors if you try to color the ribbon as evenly as possible.

 **Solution (BledDest)**
```cpp
t = int(input())
for i in range(t):
    n, m, k = map(int, input().split())
    max_color = (n + m - 1) / m
    if max_color + k >= n:
        print('NO')
    else:
        print('YES')
```
[1954B - Make It Ugly](../problems/B._Make_It_Ugly.md "Educational Codeforces Round 164 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1954B - Make It Ugly](../problems/B._Make_It_Ugly.md "Educational Codeforces Round 164 (Rated for Div. 2)")

As given in the problem statement, the definition of a beautiful array is not very interesting to us, since checking the beauty of an array is quite complex. Let's try to simplify it.

First of all, the first and last elements will never be changed, as it is impossible to choose such $i$ for operations. If they are different, then the array is definitely not beautiful. Moreover, if the array is beautiful, then all its elements at the end will be equal to the first and the last elements.

The second idea is a bit more complicated. Notice that each element can be changed at most once. Consider an arbitrary operation. We choose some $i$ for which $a_{i - 1} = a_{i + 1}$, and change $a_i$ to $a_{i - 1}$. Now both $a_{i - 1}$ and $a_{i + 1}$ will always remain equal to their current values, because in any operation involving them, $a_i$ will also be involved. This means that $a_i$ will also remain equal to the new value.

The next idea is as follows. We know what all the elements should be equal to in the end. This means that we need to apply operations to all elements that are not equal to this value. According to the previous idea, this is possible if and only if there are no two consecutive numbers in the array that are not equal to this value. The sufficiency of this condition is obvious, and the necessity is left as an exercise to the reader.

In other words, the check looks like this: $a_1 = a_n$, and $a_i = a_1$ or $a_{i + 1} = a_1$ (or both are equal) for all $i$.

What elements should be removed so that the check does not pass? There are two options: break the first or second condition. So, you can do the following: 

* remove the entire prefix of numbers equal to $a_1$;
* remove the entire suffix of numbers equal to $a_1$ (or $a_n$ — they are equal to each other, since the given array is beautiful);
* choose two numbers that are not equal to $a_1$, and remove all the numbers between them, so that these two numbers become adjacent.

The third condition can be simplified. If other numbers not equal to $a_1$ are encountered between the selected numbers, then another pair can be chosen, for which fewer numbers have to be removed. Therefore, it is only optimal to choose a pair for which all the numbers between them are equal to $a_1$.

Then the solution is as follows. Find the shortest block of numbers equal to $a_1$. Remove it from the array. It can be at the prefix or at the suffix — then the first condition will be broken. Or it can be somewhere in the middle — then the second condition will be broken.

To find such a block, you can go through the array from left to right, maintaining the position of the previous element not equal to $a_1$. If the current element is not equal to $a_1$, update the answer with the difference between the saved and current positions, and update the saved position.

The only case when the answer is -1 is when all the elements of the array are the same. Otherwise, it is always possible to make the array not beautiful.

Overall complexity: $O(n)$ for each testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    lst = -1
    ans = n
    for i in range(n):
        if a[i] != a[0]:
            ans = min(ans, i - lst - 1)
            lst = i
    ans = min(ans, n - lst - 1)
    if ans == n:
        print(-1)
    else:
        print(ans)
```
[1954C - Long Multiplication](../problems/C._Long_Multiplication.md "Educational Codeforces Round 164 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1954C - Long Multiplication](../problems/C._Long_Multiplication.md "Educational Codeforces Round 164 (Rated for Div. 2)")

There are two observations to solve the problem: 

* applying the operation does not change the sum of the numbers;
* the smaller the difference of the numbers, the greater their product (the proof is given below).

Proof: let's denote the sum of the numbers as $s$, the smallest number as $\frac{s}{2} - a$ and the largest number as $\frac{s}{2} + a$. Then the product is equal to $\left(\frac{s}{2} - a\right)\left(\frac{s}{2} + a\right) = \left(\frac{s}{2}\right)^2 - a^2$. We can see that, the smaller $a$ (the half of difference), the larger the product.

In order to get the minimum difference, we can use the following algorithm: let $i$ be the smallest index (the most significant digit) such that $x_i \ne y_i$ and set the maximum digit among $x_i$ and $y_i$ to the number $x$ and smallest to the number $y$; thus $x$ is definitely greater than $y$, then the less significant digits should be the maximum possible for the number $y$ (i. e. the inequality $x_j \le y_j$ must hold for all $j > i$).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;
    int n = x.size();
    bool f = false;
    for (int i = 0; i < n; ++i) {
      if ((x[i] > y[i]) == f) swap(x[i], y[i]);
      f |= (x[i] != y[i]);
    }
    cout << x << 'n' << y << 'n';
  }
}
```
[1954D - Colored Balls](../problems/D._Colored_Balls.md "Educational Codeforces Round 164 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1954D - Colored Balls](../problems/D._Colored_Balls.md "Educational Codeforces Round 164 (Rated for Div. 2)")

For a fixed set of colors, this is a standard problem with the following solution: let's denote the total number of balls as $s$, then the value of the set is $\left\lceil\frac{s}{2}\right\rceil$; but there is an exception in the case when there is a color with more than $\frac{s}{2}$ balls, then the value is the number of balls of this color.

So the answer depends only on whether there is a color that has more balls than all the others combined.

Using the aforementioned fact, we can come up with the following solution: let's iterate over the total number of balls in the set (denote it as $j$) and increase the answer by $\left\lceil\frac{j}{2}\right\rceil$ for each subset of colors with exactly $j$ balls in it. The number of subsets with the fixed number of balls can be calculated using simple knapsack dynamic programming.

It remains to consider the subsets of colors with a "dominant" color, because we added the wrong value to the answer for them. Let the "dominant" color be $i$ and the total number of balls in all other colors be $j$ ($j < a_i$). The answer should be increased by $a_i - \left\lceil\frac{a_i + j}{2}\right\rceil$ (the correct value of this set is $a_i$, but we have already added the wrong value in the answer — $\left\lceil\frac{a_i + j}{2}\right\rceil$, so we should compensate it) for each subset of colors with exactly $j$ balls in it (we can use the same dp as in previous case). Note that if you consider only $j < a_i$, you don't have to deal with the possibility that the "dominant" color could already be included in the subset.

This solution works in $O(nS)$ time, where $S$ is the total number of balls.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 998244353;
 
int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
} 
 
int mul(int x, int y) {
  return x * 1LL * y % MOD;
}
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int s = accumulate(a.begin(), a.end(), 0);
  vector<int> dp(s + 1);
  dp[0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = s - a[i]; j >= 0; --j) 
      dp[j + a[i]] = add(dp[j + a[i]], dp[j]);
  int ans = 0;
  for (int j = 0; j <= s; ++j) 
    ans = add(ans, mul((j + 1) / 2, dp[j]));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < a[i]; ++j) 
      ans = add(ans, mul(a[i] - (a[i] + j + 1) / 2, dp[j]));
  cout << ans << 'n';
}
```
[1954E - Chain Reaction](../problems/E._Chain_Reaction.md "Educational Codeforces Round 164 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1954E - Chain Reaction](../problems/E._Chain_Reaction.md "Educational Codeforces Round 164 (Rated for Div. 2)")

Let's solve the problem for a single $k$. We'll start with $k = 1$ for simplicity.

The first lightning can be launched at any monster, as it will always spread to all of them. We will continue launching lightnings until a monster dies. When one or more monsters die, the problem breaks down into several independent subproblems, because no lightning will pass through dead monsters. This means that there is no concept of "minimum number of seconds" — the answer does not depend on the choice of monsters to launch the lightnings.

Great, so how do we calculate this answer? The idea is as follows. We will attack the first monster until it dies. This will take $a_1$ seconds. We then move on to the second monster. If it has more health than the first one, we need to launch an additional $a_2 - a_1$ lightnings to kill it. Otherwise, it will already be dead. How much damage will the third monster receive in both cases? Let's say it has a lot of health. In the first case, it will receive $a_2$ damage, because all the lightnings will reach it. But in the second case, it will also receive $a_2$ damage, because the lightnings launched at the first monster after the death of the second one will not reach the third one. This means that we now need to compare the health of the second monster with the third one in the same way. And so on. This means that the $i$-th monster needs to be hit with $\max(0, a_i - a_{i - 1})$ lightnings.

Then the answer for $k = 1$ is equal to $a_1 + \sum\limits_{i = 2}^{n} \max(0, a_i - a_{i - 1})$.

How to calculate the answer for any $k$? In fact, the difference is not very significant. It is sufficient to change the health of each monster from $a_i$ to $\lceil \frac{a_i}{k} \rceil$, and the entire process described earlier will remain the same. Therefore, the answer for any $k$ is equal to $\lceil \frac{a_1}{k} \rceil + \sum\limits_{i = 2}^{n} \max(0, \lceil \frac{a_i}{k} \rceil - \lceil \frac{a_{i - 1}}{k} \rceil)$.

To further optimize this solution, another transformation is needed. Ideally, we would like each $a_i$ to contribute to the answer independently of other values. And this can almost be achieved. Notice that the maximum returns $0$ only if $a_i < a_{i - 1}$ for any $k$, not just for $k = 1$. This may require proof, but it is quite obvious.

This means that the coefficient for $\lceil \frac{a_i}{k} \rceil$ in the answer depends on two conditions: 

* it is increased by $1$ if $i = 1$ or $a_i \ge a_{i - 1}$;
* it is decreased by $1$ if $i < n$ and $a_i < a{i + 1}$.

Let's call this coefficient for the $i$-th monster $c_i$. Therefore, we need to calculate $\sum\limits_{i = 1}^n c_i \cdot \lceil \frac{a_i}{k} \rceil$.

There are two ways to optimize the solution further.

The first option is to notice that $\lceil \frac{a_i}{k} \rceil$ doesn't take a lot of different values for different $k$. More precisely, it is $O(\sqrt{a_i})$. This can be shown as follows. Consider $\lceil \frac{a_i}{k} \rceil = x$. Either $k \le \sqrt{a_i}$, or $x \le \sqrt{a_i}$. Therefore, $x$ takes no more than $2 \sqrt{a_i}$ different values.

Then the solution can be implemented as follows. For each $a_i$, we will identify all possible values that the rounding result takes. For each of them, we will find the range of $k$ for which the result is equal to that. And we will add the contribution of the $i$-th monster within this range of values to the result. This can be done using a difference array to achieve a complexity of $O(n \cdot \sqrt{A})$.

The second option is a bit smarter. Let's take another look at the formula for calculating the answer for a fixed $k$: $\sum\limits_{i = 1}^n c_i \cdot \lceil \frac{a_i}{k} \rceil$. Let's group the terms by equal values of $\lceil \frac{a_i}{k} \rceil$. What do they look like? Numbers from $1$ to $k$ give the value $1$. Numbers from $k + 1$ to $2k$ give the value $2$, and so on. This means that for a certain $k$, there are $\frac{A}{k}$ segments, on each of which we need to calculate the sum of $c_i$ for those $i$ for which $a_i$ fall into this segment. The total number of segments for all $k$ is $O(A \log A)$. The complexity of the solution will then be $O(n + A \log A)$.

 **Solution 1 (awoo)**
```cpp
#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
int divup(int a, int b){
    return (a + b - 1) / b;
}
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    vector<long long> ans(mx + 1);
    forn(i, n){
        int coef = 0;
        if (i == 0 || a[i] > a[i - 1]) ++coef;
        if (i + 1 < n && a[i] < a[i + 1]) --coef;
        int r = a[i];
        ans[r] += coef;
        while (r > 0){
            int val = divup(a[i], r);
            int l = divup(a[i], val);
            ans[l - 1] += coef * val;
            ans[r] -= coef * val;
            r = l - 1;
        }
    }
    forn(i, mx) ans[i + 1] += ans[i];
    forn(i, mx) cout << ans[i] << ' ';
    cout << 'n';
    return 0;
}
```
 **Solution 2 (awoo)**
```cpp
#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    vector<long long> pr(mx + 1);
    forn(i, n){
        int coef = 0;
        if (i == 0 || a[i] > a[i - 1]) ++coef;
        if (i + 1 < n && a[i] < a[i + 1]) --coef;
        pr[a[i]] += coef;
    }
    forn(i, mx) pr[i + 1] += pr[i];
    for (int k = 1; k <= mx; ++k){
        long long ans = 0;
        for (int l = 1, val = 1; l <= mx; l += k, ++val)
            ans += val * 1ll * (pr[min(mx, l + k - 1)] - pr[l - 1]);
        cout << ans << ' ';
    }
    cout << 'n';
    return 0;
}
```
[1954F - Unique Strings](../problems/F._Unique_Strings.md "Educational Codeforces Round 164 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1954F - Unique Strings](../problems/F._Unique_Strings.md "Educational Codeforces Round 164 (Rated for Div. 2)")

What's common in all strings we can get: each string has no more than $c + k$ ones and at least $c$ consecutive ones.

So let's loosen up our constraints a little and just calculate the number of strings with no more than $c + k$ ones and at least $c$ consecutive ones, i. e. this block of ones can be anywhere, can even start at the end and continue at the beginning. Let's name such strings as good strings.

Note that the number of unique good strings is exactly equal to the answer of the initial task, since we can shift each good string and make it start from the block of ones.

How to calculate the number of good strings? Using Burnside's lemma! Since the group of transformations is just a group of cyclic shifts, we can calculate the answer as following $$\mathrm{ans} = \frac{1}{n} \sum_{i=1}^{n}{\mathrm{FixedPoints}(i)}$$ where $\mathrm{FixedPoints(i)}$ is the number of fixed points, or the number of strings that won't change after a cyclical shift by $i$ characters.

Note that if the string doesn't change while shifting by $i$ characters, then it means that $s[p] = s[(p + i) \mod |s|]$ for all $p$. Further investigation reveals that all characters will be split into exactly $g = \gcd(i, n)$ groups and each group will contain exactly $\frac{n}{g}$ equal characters.

It means that if $\gcd(i, n) = \gcd(j, n)$ then $\mathrm{FixedPoints}(i) = \mathrm{FixedPoints}(j)$ since in both cases we'll get exactly the same group division. So, we can rewrite the answer as following: $$\mathrm{ans} = \frac{1}{n} \sum_{g | n}{cnt[g] \cdot \mathrm{FixedPoints}(g)}$$ where $cnt[g]$ is the number of cyclic shifts $i$ with $\gcd(i, n) = g$ and can be easily counted.

So, it's time to calculate $\mathrm{FixedPoints}(g)$ for some divisor $g$ of $n$. It's not hard to see that if $s[p] = s[(p + g) \mod |s|]$ then the first $g$ characters of $s$ will uniquely define the whole string $s$. So it's enough to work with only a prefix of length $g$, remembering that each character will be copied $\frac{n}{g}$ times.

Remember that a good string is a string with at most $c + k$ ones, and since each character will be copied $\frac{n}{g}$ times, we can place at most $on = \frac{(c + k) g}{n}$ ones in our prefix (or at least $zr = g - on$ zeroes).

Also, since a good string has $c$ consecutive ones, our prefix should also have $c$ consecutive ones, including the case where the ones go "cyclically" starting at the end of the prefix. In case if $c \ge g$ then the whole prefix should consist of ones, and it's either possible (if $c + k = n$) or impossible (if $c + k < n$).

In case $c < g$ we need to calculate the number of good prefixes that can be described as "the cyclic strings of length $g$ that has no more than $on$ ones and contains $c$ consecutive ones". Instead of good prefixes, let's calculate bad prefixes and subtract them from all possible prefixes.

All prefixes are just strings with at most $on$ ones and there are $all = \sum\limits_{i=0}^{on}{\binom{g}{i}}$ such strings.

Bad prefixes are cyclic strings with at most $on$ ones, where all blocks of ones have length less than $c$. In order to calculate bad prefixes, let's precalc the following dp: $d[z][l]$ is the number of strings of length $l$ with $z$ zeroes where all blocks of ones have length less than $c$ and the last character of the string is $0$.

Why did we use the number of zeroes in the state, and why did we add the last zero in $d[z][l]$? Because it will help us to calculate dp fast. $d[0][0] = 1$. Now, if we have value $d[z][l]$, we can add a block of $i$ ones ($0 \le i < c$) and zero to the end of the string and update the value in $d[z + 1][l + i + 1]$. Note that we are updating a segment of row $z + 1$ from $l + 1$ to $l + c$ with value $d[z][l]$ — we can do it in $O(1)$. So, we can precalc the whole dp in $O(n^2)$ time.

Now, it's time to calculate the number of bad strings: if we iterate over the length of the prefix of ones, length of the suffix of ones and the number of zeroes in between, we'll get $$bad = \sum_{p=0}^{c - 1}\sum_{s = 0}^{c - p - 1}\sum_{z = zr - 1}^{g - p - s - 1}{d[z][g - p - s - 1]}$$ where $p$ is the number of ones on prefix, $s$ is the number of ones on suffix, and $z$ is the number of zeroes in the "middle part". Since each bad string will look like "($p$ ones)–0–(middle part ending at 0)–($s$ ones)", you can place in the middle part at least $zr - 1$ zeroes and at most $g - p - 1 - s$ zeroes.

If we play a little with the sum, we can simplify it in the following way: $$bad = \sum_{p = 0}^{c - 1}\sum_{z = \max(0, zr - 1)}^{g - p - 1}{\mathrm{sumD}(z, g - c, g - p - 1)}$$ where $\mathrm{sumD}(z, g - c, g - p - 1)$ is the sum of dp on the row $z$ from $g - c$ to $g - p - 1$, and you can take it in $O(1)$ if you precalc prefix sums of dp.

Good prefixes are just $all - bad$ and since $bad$ can be calculated in $O(g^2)$, the total complexity of $\mathrm{FixedPoints}(g)$ is $O(g^2)$.

The resulting complexity is $O(n^2) + \sum\limits_{g|n}{O(g^2)}$ that looks like just $O(n^2)$.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
 
typedef long long li;
typedef pair<int, int> pt;
 
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    fore(i, 0, sz(v)) {
        if(i) out << " ";
        out << v[i];
    }
    return out;
}
 
const int MOD = int(1e9) + 7;
int add(int a, int b) {
    a += b;
    while (a >= MOD)
        a -= MOD;
    while (a < 0)
        a += MOD;
    return a;
}
void upd(int &ans, int val) {
    ans = add(ans, val);
}
int mul(int a, int b) {
    return int(a * 1ll * b % MOD);
}
int binPow(int a, int k) {
    int ans = 1;
    while (k > 0) {
        if (k & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        k >>= 1;
    }
    return ans;
}
 
const int N = 3055;
int f[N], invf[N];
 
void precalcFact() {
    f[0] = invf[0] = 1;
    fore (i, 1, N) {
        f[i] = mul(f[i - 1], i);
        invf[i] = binPow(f[i], MOD - 2);
    }
}
int C(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return mul(f[n], mul(invf[k], invf[n - k]));
}
 
int n, c, k;
 
inline bool read() {
    if(!(cin >> n >> c >> k))
        return false;
    return true;
}
 
int d[N][N], sum[N][N];
 
// d[z][l] - number of strings of length l, with z zeroes and blocks of 1-s shorter than mx
void precalcShort(int mx) {
    memset(d, 0, sizeof d);
    d[0][0] = 1;
    fore (z, 0, n) {
        fore (l, 0, n) {
            if (d[z][l] == 0)
                continue;
            upd(d[z + 1][l + 1], +d[z][l]);
            upd(d[z + 1][min(n, l + mx) + 1], -d[z][l]);
        }
        fore (l, 0, n + 1)
            upd(d[z + 1][l + 1], d[z + 1][l]);
    }
        
    memset(sum, 0, sizeof sum);
    fore (z, 0, n + 1) fore (l, 0, n + 1)
        sum[z][l + 1] = add(sum[z][l], d[z][l]);
    
}
 
//[lf, rg)
int getSum(int z, int lf, int rg) {
    if (z < 0 || z > n || lf >= rg)
        return 0;
    return add(sum[z][rg], -sum[z][lf]);
}
 
// cnt[g] is a number of x <= n with gcd(x, n) = g
vector<int> precalcCnt(int n) {
    vector<int> cnt(n + 1, 0);
    fore (x, 1, n + 1)
        cnt[gcd(x, n)]++;
    return cnt;
}
 
int calcFixedPoints(int g) {
    if (c >= g)
        return c + k >= n;
    
    int cntOnes = (c + k) / (n / g);
    int cntZeros = g - cntOnes;
    
    int all = 0;
    fore (ones, 0, cntOnes + 1)
        upd(all, C(g, ones));
    
    int bad = 0;
    fore (pref, 0, c) {
        int minZeros = max(0, cntZeros - 1);
        int minMid = g - c;
        int sufLen = g - pref - 1;
        fore (z, minZeros, sufLen + 1)
            upd(bad, getSum(z, minMid, sufLen + 1));
    }
    return add(all, -bad);
}
 
inline void solve() {
    precalcFact();
    precalcShort(c);
    auto cnt = precalcCnt(n);
    
    int ans = 0;
    fore (g, 1, n + 1) {
        if (n % g != 0)
            continue;
        
        int cntFP = calcFixedPoints(g);
//      cerr << "g = " << g << " += " << cnt[g] << " * " << cntFP << endl;
        upd(ans, mul(cnt[g], cntFP));
    }
    
//  cerr << "ans/n = " << ans << " " << n << endl;
    cout << mul(ans, binPow(n, MOD - 2)) << endl;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    if(read()) {
        solve();
        
#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}
```
