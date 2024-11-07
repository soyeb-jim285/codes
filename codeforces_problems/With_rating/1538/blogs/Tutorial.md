# Tutorial

[1538A - Stone Game](../problems/A._Stone_Game.md "Codeforces Round 725 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1538A - Stone Game](../problems/A._Stone_Game.md "Codeforces Round 725 (Div. 3)")

If we want to destroy the largest and smallest stone, then there are only four options: 

* Destroy the stones on the left until we destroy the smallest stone. Then destroy the stones on the right, until we destroy the largest stone.
* Destroy the stones on the right until we destroy the smallest stone. Then destroy the stones on the left, until we destroy the largest stone.
* Destroy the stones on the left until we destroy both stones.
* Destroy the stones on the right until we destroy both stones.
	You need to check all four options and choose the minimum answer.
 **Solution**
```cpp
#include <bits/stdc++.h>
#include "random"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &e : v) {
        cin >> e;
    }
    int maxPos = max_element(v.begin(), v.end()) - v.begin();
    int minPos = min_element(v.begin(), v.end()) - v.begin();
    cout << min({
            max(maxPos, minPos) + 1,
            (n - 1) - min(maxPos, minPos) + 1,
            (n - 1) - maxPos + minPos + 2,
            (n - 1) - minPos + maxPos + 2
    }) << "n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1538B - Friends and Candies](../problems/B._Friends_and_Candies.md "Codeforces Round 725 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1538B - Friends and Candies](../problems/B._Friends_and_Candies.md "Codeforces Round 725 (Div. 3)")

Let's denote for $s$ the number of candies all friends have: $s = \sum\limits_{i=1}^{n} a_i$. Note that at the end, each friend must have $\frac{s}{n}$ of candy. If $s$ is not completely divisible by $n$, then there is no answer.

How to get the answer if it exists? If the $i$-th friend has more candies than $\frac{s}{n}$, then he must be chosen by Polycarp (otherwise this friend will have more candies than the others). If the $i$-th friend has no more than $\frac{s}{n}$, then Polycarp may not choose it.

Then, if the answer exists, it is equal to the number of $a_i > \frac{s}{n}$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s % n != 0) {
    cout << "-1" << endl;
    return;
  }
  s /= n;
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (s < a[i]) {
      res++;
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
  return 0;
}
```
[1538C - Number of Pairs](../problems/C._Number_of_Pairs.md "Codeforces Round 725 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1538C - Number of Pairs](../problems/C._Number_of_Pairs.md "Codeforces Round 725 (Div. 3)")

The problem can be divided into two classic ones: 

* Count the number of pairs $a_i+a_j \le r$;
* Count the number of pairs $a_i+a_j \le l-1$.

Let $A$ — be the answer to the first problem, and $B$ — be the answer to the second problem. Then $A-B$ is the answer to the original problem.

The new problem can be solved by binary search. Iterate over the first element of the pair. Then you need to count the number of elements such that $a_j \le r - a_i$. If you sort the array, this value can be calculated by running a single binary search.

 **Solution**
```cpp
#include <bits/stdc++.h>
#include "random"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int &e : v) {
        cin >> e;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += upper_bound(v.begin(), v.end(), r - v[i]) - v.begin();
        ans -= lower_bound(v.begin(), v.end(), l - v[i]) - v.begin();
        if (l <= 2 * v[i] && 2 * v[i] <= r) {
            ans--;
        }
    }
    cout << ans / 2 << "n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1538D - Another Problem About Dividing Numbers](../problems/D._Another_Problem_About_Dividing_Numbers.md "Codeforces Round 725 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1538D - Another Problem About Dividing Numbers](../problems/D._Another_Problem_About_Dividing_Numbers.md "Codeforces Round 725 (Div. 3)")

Let's denote for $n$ the maximum number of moves for which the numbers $a$ and $b$ can be made equal. It is easy to understand that the number of moves is maximum when $a=b=1$ and each time we divided $a$ or $b$ by a prime number. That is, $n=$ sum of exponents of prime divisors of $a+$ sum of exponents of prime divisors of $b$.

Let's denote by $m$ the minimum number of moves for which the numbers $a$ and $b$ can be made equal. Consider a few cases: 

* If $a=b$, then $m=0$;
* If $gcd (a, b)=a$ or $gcd (a, b)=b$, then $m=1$;
* Otherwise, then $m=2$.

Then, the answer "Yes" is possible in the following cases: 

* $m \le k \le n$ and $k=1$ and $m = 1$,
* or, $m \le k \le n$ and $k \ne 1$.
 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int N = 50'000;

bool isPrime[N];
vector<int> primes;

void precalc() {
  fill(isPrime + 2, isPrime + N, true);
  for (int i = 2; i * i < N; i++) {
    for (int j = i * i; j < N; j += i) {
      isPrime[j] = false;
    }
  }
  for (int i = 2; i < N; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }
}

int calcPrime(int n) {
  int res = 0;
  for (int i : primes) {
    if (i * i > n) {
      break;
    }
    while (n % i == 0) {
      n /= i;
      res++;
    }
  }
  if (n > 1) {
    res++;
  }
  return res;
}

map<int, int> decompose(int n) {
  map<int, int> a;
  for (int i : primes) {
    if (i * i > n) {
      break;
    }
    int p = 0;
    while (n % i == 0) {
      n /= i;
      p++;
    }
    if (p > 0) {
      a[i] = p;
    }
  }
  if (n > 1) {
    a[n] = 1;
  }
  return a;
}

bool check(const map<int, int> &divs,
           map<int, int>::const_iterator it,
           map<int, int> &divsA,
           map<int, int> &divsB,
           int low,
           int high,
           int k) {
  if (it == divs.end()) {
    return __builtin_popcount(low) <= k && k <= high;
  }
  for (int p = 0; p <= it->second; p++) {
    int pa = divsA[it->first];
    int pb = divsB[it->first];
    int nextLow = low;
    if (p != pa) {
      nextLow |= 1;
    }
    if (p != pb) {
      nextLow |= 2;
    }
    if (check(divs, next(it), divsA, divsB, nextLow, high + pa + pb - 2 * p, k)) {
      return true;
    }
  }
  return false;
}

void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  int g = __gcd(a, b);
  int low = 0;
  int high = 0;
  {
    int t;
    int ta = 1;
    while ((t = __gcd(a, g)) != 1) {
      a /= t;
      ta *= t;
    }
    high += calcPrime(a);
    if (a != 1) {
      low |= 1;
    }
    a = ta;
  }
  {
    int t;
    int tb = 1;
    while ((t = __gcd(b, g)) != 1) {
      b /= t;
      tb *= t;
    }
    high += calcPrime(b);
    if (b != 1) {
      low |= 2;
    }
    b = tb;
  }
  auto divs = decompose(g);
  auto divsA = decompose(a);
  auto divsB = decompose(b);
  cout << (check(divs, divs.begin(), divsA, divsB, low, high, k) ? "YES" : "NO") << endl;
}

int main() {
  precalc();

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
```
[1538E - Funny Substrings](../problems/E._Funny_Substrings.md "Codeforces Round 725 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1538E - Funny Substrings](../problems/E._Funny_Substrings.md "Codeforces Round 725 (Div. 3)")

We can't model this process directly, since the maximum string length reaches $2^{50}$ (look at the second example from the statements).

To optimize this process, you can store each row as a set of the following values. 

* Number of occurrences of haha in the string  — $cnt$.
* String length  — $length$.
* The first three characters of the string are  — $pref$.
* The last three characters of the string are  — $suff$.

Then, to process the second type of request and combine the two strings $a$ and $b$ into the string $c$, you need: 

* $c.length = a.length + b.length$.
* $c.cnt = a.cnt + b.cnt + count(a.suff + b.pref, haha)$. (New occurrences may be added at the junction of two words)
* $c. pref = a. pref$ (However, if the string length is less than $6=3+3$, then you need to handle this case carefully with your hands)
* $c. suff = b. suff$ (Similarly, you need to process small strings separately).
 **Solution**
```cpp
#include <bits/stdc++.h>
#include "random"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

vector<string> split(const string& s, char p) {
    vector<string> res(1);
    for (char c : s) {
        if (c == p) {
            res.emplace_back();
        } else {
            res.back() += c;
        }
    }
    return res;
}

struct Word {
    ll len;
    ll cnt;
    string s;
};

string getFirst(string s) {
    if (s.size() < 3) {
        return s;
    }
    return s.substr(0, 3);
}

string getLast(string s) {
    if (s.size() < 3) {
        return s;
    }
    return s.substr(s.size() - 3, 3);
}

int count(const string& s, const string& p) {
    int cnt = 0;
    for (int i = 0; i + p.size() <= s.size(); i++) {
        if (s.substr(i, p.size()) == p) {
            cnt++;
        }
    }
    return cnt;
}

Word merge(const Word& a, const Word& b) {
    Word c;
    c.len = a.len + b.len;
    c.s = a.s + b.s;
    c.cnt = a.cnt + b.cnt + count(getLast(a.s) + getFirst(b.s), "haha");
    if (c.s.size() >= 7) {
        c.s = getFirst(c.s) + "@" + getLast(c.s);
    }
    return c;
}

void solve() {
    int n;
    cin >> n;
    map<string, Word> vars;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string var;
        cin >> var;
        string opr;
        cin >> opr;
        if (opr == "=") {
            string a, plus, b;
            cin >> a >> plus >> b;
            vars[var] = merge(vars[a], vars[b]);
        } else {
            string str;
            cin >> str;
            Word word;
            word.len = str.length();
            word.cnt = count(str, "haha");
            word.s = str;
            vars[var] = word;
        }
        ans = vars[var].cnt;
    }
    cout << ans << "n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1538F - Interesting Function](../problems/F._Interesting_Function.md "Codeforces Round 725 (Div. 3)")

Author: [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz"), [Stepavly](https://codeforces.com/profile/Stepavly "Candidate Master Stepavly")

 **Tutorial**
### [1538F - Interesting Function](../problems/F._Interesting_Function.md "Codeforces Round 725 (Div. 3)")

For each digit, we will count how many times it has changed.

The number of changes for the first digit (the lowest) is calculated using the formula $r-l$.

The number of changes for the second digit is calculated by the formula $\left\lfloor\frac{r}{10}\right\rfloor-\left\lfloor\frac{l}{10}\right\rfloor$. That is, it is equivalent to the number of first-digit changes for numbers from $\left\lfloor\frac{l}{10}\right\rfloor$ to $\left\lfloor\frac{r}{10}\right\rfloor$.

To calculate the number of changes for the remaining digits, you need to apply similar reasoning with dividing the numbers by $10$.

 **Solution**
```cpp
#include <iostream>

using namespace std;

void solve () {
  int L, R;
  cin >> L >> R;

  int ans = 0;
  while (L != 0 || R != 0) {
    ans += R - L;
    L /= 10;
    R /= 10;
  }
  cout << ans << 'n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}
```
[1538G - Gift Set](../problems/G._Gift_Set.md "Codeforces Round 725 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1538G - Gift Set](../problems/G._Gift_Set.md "Codeforces Round 725 (Div. 3)")

In this problem, we can use a binary search for the answer (If we can make $x$ sets, then we can make $y < x$ sets). So, we need to come up with the following test, whether we can make $n$ sets knowing the parameters $x, y, a, b$.

Let $a > b$ (otherwise we will swap them). If $a == b$, the answer is $\lfloor\frac{min(x, y)}{a}\rfloor$.

Otherwise, let's say we want to make $k$ sets of the first kind. Then we get a system of inequalities $$x \le a \cdot k + b \cdot (n - k)$$ $$y \le a \cdot (n - k) + b \cdot k$$

Let's express $k$from here

$$\frac{(x - b \cdot n)}{a - b} \le k$$ $$\frac{(x - a \cdot n)}{b - a} \ge k$$ $$0 \le k$$ $$n \ge k$$

We need to check whether these four equations have an intersection in integers. If there is, then the division into $n$ gifts exists.

 **Solution**
```cpp
#include <bits/stdc++.h>
#include "random"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll l = 0, r = 1e9 + 100;
    if (a == b) {
        cout << min(x, y) / a << "n";
        return;
    }
    if (a < b) {
        swap(a, b);
    }
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll right = floorl((x - m * b) * 1.0l / (a - b));
        ll left = ceill((y - m * a) * 1.0l / (b - a));
        if (max(left, 0ll) <= min(right, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << "n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
