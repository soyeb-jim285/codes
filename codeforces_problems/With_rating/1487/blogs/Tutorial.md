# Tutorial

[1487A - Arena](../problems/A._Arena.md "Educational Codeforces Round 104 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1487A - Arena](../problems/A._Arena.md "Educational Codeforces Round 104 (Rated for Div. 2)")

If for some hero $i$, no other hero is weaker than $i$, then the $i$-th hero cannot win any fights and is not a possible winner. Otherwise, the hero $i$ is a possible winner — he may fight the weakest hero $100^{500}$ times and be declared the winner.

So the solution to the problem is calculating the number of minimum elements in the array $a$, since all other elements denote possible winners of the tournament.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    cout << n - count(a.begin(), a.end(), *min_element(a.begin(), a.end())) << endl;
  }
}
```
[1487B - Cat Cycle](../problems/B._Cat_Cycle.md "Educational Codeforces Round 104 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1487B - Cat Cycle](../problems/B._Cat_Cycle.md "Educational Codeforces Round 104 (Rated for Div. 2)")

If $n$ is even, then each hour A and B are on the spots with different parity, so they will never meet. Otherwise, let's look closely what happens.

At the start, A in $n$ and B in $1$. But since we can form a cycle from spots then it means that $n$ and $1$ in reality are neighbors. After that, A and B (starting from neighboring positions) just go in opposite directions and meet each other in the opposite spot after exactly $\left\lfloor \frac{n}{2} \right\rfloor$ steps.

After meeting B "jumps over" A making $1$ extra step and the situation become practically the same: A and B are neighbors and move in the opposite direction.

In other words, each $f = \left\lfloor \frac{n}{2} \right\rfloor$ steps B makes one extra step, so the answer (if both $k$ and spots are $0$-indexed) is $$(k + (n \bmod 2) \cdot \left\lfloor \frac{k}{f} \right\rfloor) \bmod n$$

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readLine()!!.toInt()) {
        var (n, k) = readLine()!!.split(' ').map { it.toInt() }
        k--
        val floor = n / 2
        println((k + (n % 2) * k / floor) % n + 1)
    }
}
```
[1487C - Minimum Ties](../problems/C._Minimum_Ties.md "Educational Codeforces Round 104 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1487C - Minimum Ties](../problems/C._Minimum_Ties.md "Educational Codeforces Round 104 (Rated for Div. 2)")

If $n$ is odd, then we can solve the problem without any ties: each team should win exactly $\lfloor\frac{n}{2}\rfloor$ matches and lose the same number of matches. Finding which matches each team wins and which matches each team loses can be done with some graph algorithms (like Eulerian cycles or circulations), or with a simple construction: place all teams in a circle in any order, and let the $i$-th team win against the next $\lfloor\frac{n}{2}\rfloor$ teams after it in the circle, and lose to all other teams.

Unfortunately, if $n$ is even, we need to use some ties since the total sum of scores over all teams is exactly $\frac{3n(n-1)}{2}$ when there are no ties, and this number is not divisible by $n$ when $n$ is even. Each tie reduces the total sum by $1$, and the minimum number of ties to make $\frac{3n(n-1)}{2} - t$ divisible by $n$ is $t = \frac{n}{2}$ (since $\frac{3n(n-1)}{2} \bmod n = \frac{n}{2}$). So, if we find an answer with exactly $\frac{n}{2}$ ties, it is optimal. And it's easy to find one: once again, place all teams in a circle in any order; make the $i$-th team win against $\frac{n - 2}{2}$ next teams in the circle, lose against $\frac{n - 2}{2}$ previous teams in the circle, and tie with the opposite team in the circle.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        if(n % 2 == 1)
        {
            for(int i = 0; i < n; i++)
                for(int j = i + 1; j < n; j++)
                    if(j - i <= n / 2)
                        cout << 1 << " ";
                    else
                        cout << -1 << " ";
            cout << endl;
        }
        else
        {
            for(int i = 0; i < n; i++)
                for(int j = i + 1; j < n; j++)
                    if(j - i < n / 2)
                        cout << 1 << " ";
                    else if(j - i == n / 2)
                        cout << 0 << " ";
                    else
                        cout << -1 << " ";
            cout << endl;
        }
    }
}
```
[1487D - Pythagorean Triples](../problems/D._Pythagorean_Triples.md "Educational Codeforces Round 104 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1487D - Pythagorean Triples](../problems/D._Pythagorean_Triples.md "Educational Codeforces Round 104 (Rated for Div. 2)")

We have to find the number of triples ($a, b, c$) such that equations $a^2+b^2=c^2$ and $a^2-b=c$ are satisfied. Let's subtract one equation from another and get that $b^2+b=c^2-c \implies b(b+1)=c(c-1)$. So we know that $c=b+1$ and after substituting, we get that $a^2=2b+1$. We can see that there is only one correct value of $b$ (and $c$) for every odd value of $a$ (greater than $1$). So we can iterate over the value of $a$ and check that the corresponding value of $c$ doesn't exceed $n$. This solution works in $O(\sqrt{n})$ because $a \approx \sqrt{c} \le \sqrt{n}$, but you can also solve it in $O(1)$.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 3; i * i <= 2 * n - 1; i += 2)
      ++ans;
    cout << ans << 'n';
  }
}
```
[1487E - Cheap Dinner](../problems/E._Cheap_Dinner.md "Educational Codeforces Round 104 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1487E - Cheap Dinner](../problems/E._Cheap_Dinner.md "Educational Codeforces Round 104 (Rated for Div. 2)")

The main solution is dynamic programming: let $dp_i$ for every possible dish $i$ be the minimum cost to assemble a prefix of a dinner ending with the dish $i$ (here, $i$ can be a dish of any type: first course, second course, drink, or dessert). Then, the answer to the problem is the minimum value among all desserts.

The number of transitions in this dynamic programming is too big, since, for example, when transitioning from first courses to second courses, we need to check $O(n_1 n_2$) options. To speed this up, we need some sort of data structure built over the values of $dp_i$ for all first courses $i$ that allows to recalculate $dp_j$ for a second course $j$ quickly. There are two main approaches to this:

* build any version of RMQ over the values of dynamic programming for the first courses. Then, when we want to calculate the answer for some second course $j$, sort all types of first courses which don't go well with it, and make several RMQ queries to find the minimum value over all non-forbidden first courses;
* store all values of $dp_i$ in a data structure that supports adding an element, deleting an element, and finding the minimum element (this DS should allow duplicate elements as well). When we want to calculate the answer for some second course $j$, remove all values of $dp_i$ corresponding to the first courses that don't go well with it from the data structure, query the minimum in it, and insert the removed elements back.

The same approach can be used to advance from second courses to drinks and from drinks to desserts (you can even use the same code in a for-loop with $3$ iterations, so the resulting solution is actually short and simple).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;


int main()
{   
    vector<int> ns(4);
    for(int i = 0; i < 4; i++)
        scanf("%d", &ns[i]);
    vector<vector<int>> cs(4);
    for(int i = 0; i < 4; i++)
    {
        cs[i].resize(ns[i]);
        for(int j = 0; j < ns[i]; j++)
            scanf("%d", &cs[i][j]);
    }
    vector<vector<vector<int>>> bad(3);
    for(int i = 0; i < 3; i++)
    {
        bad[i].resize(ns[i + 1]);
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            x--;
            y--;
            bad[i][y].push_back(x);
        }
    }                   
    vector<vector<int>> dp(4);
    dp[0] = cs[0];
    for(int i = 0; i < 3; i++)
    {
        dp[i + 1].resize(ns[i + 1]);                
        multiset<int> s;
        for(int j = 0; j < ns[i]; j++)
            s.insert(dp[i][j]);
        for(int j = 0; j < ns[i + 1]; j++)
        {
            for(auto k : bad[i][j])
                s.erase(s.find(dp[i][k]));
            if(s.empty())
                dp[i + 1][j] = int(4e8 + 43);
            else
                dp[i + 1][j] = *s.begin() + cs[i + 1][j];
            for(auto k : bad[i][j])
                s.insert(dp[i][k]);       
        }
    }
    int ans = *min_element(dp[3].begin(), dp[3].end());
    if(ans > int(4e8))
        ans = -1;
    cout << ans << endl;
}
```
[1487F - Ones](../problems/F._Ones.md "Educational Codeforces Round 104 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1487F - Ones](../problems/F._Ones.md "Educational Codeforces Round 104 (Rated for Div. 2)")

Let's build the number from the lowest digit to the highest digit with the following dynamic programming: $dp_{i,carry,cp,cn}$ — the minimum number of ones, if $i$ least significant digits are already fixed, the carry to the next digit is $carry$ (can be negative), there are $cp$ positive numbers (of the form $111 \cdots 111$) of length greater than or equal to $i$ and $cn$ negative numbers of length greater than or equal to $i$.

First, consider the transitions when we reduce the values of $cp$ and/or $cn$. Such transitions correspond to the fact that in the optimal answer there were several numbers of length exactly $i$, and they should not be considered further.

If the value of $(cp-cn+carry) \mod 10$ matches the $i$-th least significant digit in $n$, then we can use transition to $(i+1)$-th state with the new value of $carry$ and the number of ones in the answer increased by $cp+cn$.

It remains to estimate what the maximum value of $cp$ ($cn$) and $carry$ we need. The value of $cp$ doesn't exceed the total number of numbers that we use in the answer. Using at most $5$ numbers we can decrease the length of $n$ by at least $1$. Thus, the maximum value of $cp$ and $cn$ is at most $5|n|$ (where |n| is the length of the number $n$). For the value of $carry$, the condition $carry \ge \frac{carry+cp}{10}$ should be met (similarly for a negative value). Thus, we can assume that the absolute value of $carry$ doesn't exceed $\frac{5|n|}{9}$. 

The total complexity of this solution is $O(|n|^4)$, yet with a high constant factor.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 250;
const int M = 28;
const int INF = 1e9;

int dp[2][M * 2 + 1][N][N];

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  s += "0";
  
  forn(carry, M * 2 + 1) forn(cp, N) forn(cn, N) dp[0][carry][cp][cn] = INF;
  dp[0][M][N - 1][N - 1] = 0;
  
  forn(i, sz(s)) {
    forn(carry, M * 2 + 1) forn(cp, N) forn(cn, N) dp[1][carry][cp][cn] = INF;
    forn(carry, M * 2 + 1) for (int cp = N - 1; cp >= 0; --cp) for (int cn = N - 1; cn >= 0; --cn) if (dp[0][carry][cp][cn] != INF) {
      if (cp > 0) dp[0][carry][cp - 1][cn] = min(dp[0][carry][cp - 1][cn], dp[0][carry][cp][cn]);
      if (cn > 0) dp[0][carry][cp][cn - 1] = min(dp[0][carry][cp][cn - 1], dp[0][carry][cp][cn]);
      int rcarry = carry - M;
      int val = rcarry + cp - cn;
      int digit = val % 10;
      if (digit < 0) digit += 10;
      int ncarry = val / 10;
      if (val < 0 && digit != 0) --ncarry;
      if (digit == s[i] - '0') dp[1][ncarry + M][cp][cn] = min(dp[1][ncarry + M][cp][cn], dp[0][carry][cp][cn] + cp + cn);
    }
    swap(dp[0], dp[1]);
  }
  
  int ans = INF;
  forn(i, N) forn(j, N) ans = min(ans, dp[0][M][i][j]);
  cout << ans << endl;
}

```
[1487G - String Counting](../problems/G._String_Counting.md "Educational Codeforces Round 104 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1487G - String Counting](../problems/G._String_Counting.md "Educational Codeforces Round 104 (Rated for Div. 2)")

Suppose there is no constraint on the number of letters used. Then this problem can be solved with the following dynamic programming: let $dp_{i, j, k}$ be the number of strings of length $i$ ending with characters $j$ and $k$ that don't contain palindromes of odd length greater than $1$ (obviously, each forbidden palindrome contains a subpalindrome of length $3$, so we only need to ensure that there are no palindromes of length $3$).

The thing we are going to use in order to ensure that all the constraints on the number of characters are met is inclusion-exclusion. Since each $c_i > \frac{n}{3}$, at most two characters can violate their constraints in a single string, so we will iterate on some character of the alphabet and subtract the number of strings violating the constraint on this character from the answer, then iterate on a pair of characters and add the number of strings violating the constraints on these two characters to the answer.

Okay, how to calculate the number of strings violating the constraint on some fixed character? Let's use dynamic programming $f_{i, j, k, l}$ — the number of strings such that they contain $i$ characters, $j$ of them have the same type that we fixed, the previous-to-last character is $k$ and the last character is $l$. The number of states here seems to be something about $n^2 \cdot 26^2$, but in fact, $k$ and $l$ can be optimized to have only two different values since we are interested in two types of characters: the ones that coincide with the character we fixed, and the ones that don't.

Okay, what about violating the constraints on two characters? The same method can be used here: let $g_{i, j, k, l, m}$ be the number of strings consisting of $i$ characters such that the number of occurrences of the first fixed character is $j$, the number of occurrences of the second fixed character is $k$, the previous-to-last character is $l$ and the last character is $m$. Again, at first it seems that there are up to $n^3 \cdot 26^2$ states, but $l$ and $m$ can be optimized to have only $3$ different values, so the number of states is actually $n^3 \cdot 3^2$.

It seems that we have to run this dynamic programming for each pair of characters, right? In fact, no, it is the same for every pair of characters, the only difference is which states violate the constraints and which don't. We can run this dp only once, and when we need an answer for the pair of characters $(x, y)$, we can use two-dimensional prefix sums to query the sum over $g_{i, j, k, l, m}$ with $i = n$, $j > c_x$ and $k > c_y$ in $O(1)$. In fact, this dynamic programming can also be used for the first and the second part of the solution (calculating the strings that don't violate any constraints and the strings that violate the constraints on one character), so the hardest part of the solution runs in $O(n^3)$, though with a pretty big constant factor.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 402;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int sub(int x, int y)
{
    return add(x, -y);
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int c[26];
int dp[2][N][N][3][3];
int sumDp[N][N];
int p1[N][N];
int p2[N][N];
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < 26; i++)
        cin >> c[i];
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            for(int k = 0; k < 26; k++)
                if(i != k)
                {                                                                    
                    multiset<int> s = {i, j, k};
                    dp[1][s.count(0)][s.count(1)][min(2, j)][min(2, k)]++;
                }
    for(int i = 4; i <= n; i++)
    {
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                for(int x = 0; x < 3; x++)
                    for(int y = 0; y < 3; y++)
                    {
                        dp[0][j][k][x][y] = dp[1][j][k][x][y];
                        dp[1][j][k][x][y] = 0;
                    }
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                for(int x = 0; x < 3; x++)
                    for(int y = 0; y < 3; y++)
                    {
                        int cur = dp[0][j][k][x][y];
                        if(cur == 0) continue;
                        for(int z = 0; z < 3; z++)
                        {                      
                            int& nw = dp[1][j + (z == 0 ? 1 : 0)][k + (z == 1 ? 1 : 0)][y][z];
                            nw = add(nw, mul(cur, (z == 2 ? 24 : 1) - (z == x ? 1 : 0)));
                        }
                    }
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < 3; k++)
                for(int l = 0; l < 3; l++)
                    sumDp[i][j] = add(sumDp[i][j], dp[1][i][j][k][l]);
    for(int i = 0; i < N; i++)
    {
        p1[i][N - 1] = sumDp[i][N - 1];
        for(int j = N - 2; j >= 0; j--)
            p1[i][j] = add(sumDp[i][j], p1[i][j + 1]);
    }
    for(int j = 0; j < N; j++)
    {
        p2[N - 1][j] = p1[N - 1][j];
        for(int i = N - 2; i >= 0; i--)
            p2[i][j] = add(p1[i][j], p2[i + 1][j]);
    }
    int ans = p2[0][0]; 
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < N; j++)
            for(int k = c[i] + 1; k < N; k++)
                ans = sub(ans, sumDp[k][j]);
    }
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < i; j++)
            ans = add(ans, p2[c[i] + 1][c[j] + 1]);
    cout << ans << endl;    
}
```
