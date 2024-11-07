# Tutorial

[1582A - Luntik and Concerts](../problems/A._Luntik_and_Concerts.md "Codeforces Round 750 (Div. 2)") 

Idea: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "Grandmaster 74TrAkToR")

 **Tutorial**
### [1582A - Luntik and Concerts](../problems/A._Luntik_and_Concerts.md "Codeforces Round 750 (Div. 2)")

Let $S$ be the sum of durations of all songs, that is $S = a + 2 \cdot b + 3 \cdot c$.

Let's notice that since $a, b, c \ge 1$, it is possible to make a concert of any duration from $0$ to $S$ (indeed, if we just execute a greedy algorithm and take three-minute songs while possible, then take two-minute songs, and then one-minute ones, we can get any duration we need). 

Now, the answer is the remainder of $S$ modulo $2$, because if $S$ is even, then it's possible to from the first concert with duration $\frac{S}{2}$, and the second one will be left with duration $S-\frac{S}{2}=\frac{S}{2}$, and the difference between the durations will be $0$. If $S$ is odd, then the smallest possible difference is equal to $1$, let's form the first concert with duration $\left \lfloor{\frac{S}{2}}\right \rfloor$, and the second one is left with duration $\left \lceil{\frac{S}{2}}\right \rceil$

 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << (a + c) % 2 << 'n';
    }
    return 0;
}
```
[1582B - Luntik and Subsequences](../problems/B._Luntik_and_Subsequences.md "Codeforces Round 750 (Div. 2)") 

Idea: [AlFlen](https://codeforces.com/profile/AlFlen "Master AlFlen")

 **Tutorial**
### [1582B - Luntik and Subsequences](../problems/B._Luntik_and_Subsequences.md "Codeforces Round 750 (Div. 2)")

It can be noticed that all subsequences with sum $s-1$ appear if we erase some $0$-es from the array and also erase exactly one $1$. We can independently calculate the number of ways to erase some $0$-es from the array (that way the sum will remain the same), then calculate the number of ways to erase exactly one $1$ from the array (that way the sum will become equal to $s-1$), and then multiply these two numbers. Therefore, the answer is equal to $2^{c_0} \cdot c_1$, where $c_0$ is the number of $0$-es in the array, and $c_1$ is the number of $1$-s.

 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            if (x == 0) cnt0++;
            if (x == 1) cnt1++;
        }
        cout << (1ll << cnt0) * (ll)cnt1 << 'n';
    }
    return 0;
}
```
[1582C - Grandma Capa Knits a Scarf](../problems/C._Grandma_Capa_Knits_a_Scarf.md "Codeforces Round 750 (Div. 2)") 

Idea: [AlFlen](https://codeforces.com/profile/AlFlen "Master AlFlen")

 **Tutorial**
### [1582C - Grandma Capa Knits a Scarf](../problems/C._Grandma_Capa_Knits_a_Scarf.md "Codeforces Round 750 (Div. 2)")

Let's iterate over the letter that we will erase from the string (from 'a' to 'z'), and for each letter independently find the minimal number of erased symbols required to make the string a palindrome.

Let's say we are currently considering a letter $c$. Let's use the two pointers method: we will maintain two pointers $l$, $r$, initially $l$ points at the beginning of the string, and $r$ points at the end of the string. Now we will form a palindrome: each time we will compare $s_l$ and $s_r$, if they are equal, then we can add both of them to the palindrome at corresponding positions and iterate to symbols $l+1$ and $r-1$. If $s_l \neq s_r$, then we need to erase one of these symbols (otherwise, we won't get a palindrome), if $s_l=c$, let's erase it (we'll add to the number of erased symbols $1$ and iterate to $l+1$-th symbol), similarly, if $s_r=c$, we'll add to the number of the erased symbols $1$ and iterate to $r-1$-th symbol. And the last case, if $s_l \neq c$ and $s_r \neq c$, then it's impossible to get a palindrome from $s$ by erasing only letters equal to $c$.

The asymptotic behaviour of this solution is $O(|C| \cdot n)$, where $|C|$ is the size of the alphabet, i.e. $26$.

 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        string s;
        cin >> n >> s;
        int ans = n + 1;
        for (int c = 0; c < 26; ++c) {
            int l = 0, r = n - 1, cnt = 0;
            while (l <= r) {
                if (s[l] == s[r]) {
                    l++, r--;
                }
                else if (s[l] == char('a' + c)) {
                    cnt++, l++;
                }
                else if (s[r] == char('a' + c)) {
                    cnt++, r--;
                }
                else {
                    cnt = n + 1;
                    break;
                }
            }
            ans = min(ans, cnt);
        }
        if (ans == n + 1) ans = -1;
        cout << ans << 'n';
    }
    return 0;
}

```
[1582D - Vupsen, Pupsen and 0](../problems/D._Vupsen,_Pupsen_and_0.md "Codeforces Round 750 (Div. 2)") 

Idea: [AlFlen](https://codeforces.com/profile/AlFlen "Master AlFlen")

 **Tutorial**
### [1582D - Vupsen, Pupsen and 0](../problems/D._Vupsen,_Pupsen_and_0.md "Codeforces Round 750 (Div. 2)")

Let's consider two cases: when $n$ is even, and when $n$ is odd. 

If $n$ is even, let's split all numbers into pairs: let $a_1$ and $a_2$ be in one pair, $a_3$ and $a_4$ in one pair as well and so on. In the pair $a_i$, $a_{i+1}$, let $b_i=a_{i+1}$ and $b_{i+1}=-a_i$, then the sum $a_i \cdot b_i + a_{i+1} \cdot b_{i+1}$ in every pair will be equal to $0$ ($a_i \cdot a_{i+1} + a_{i+1} \cdot (-a_i)=0$), so the overall sum $a_1 \cdot b_1 + a_2 \cdot b_2 + \ldots + a_n \cdot b_n$ will be equal to $0$ as well. Notice that the sum of the $|b_i|$ is equal to the sum of $|a_i|$, therefore the sum $|b_1| + |b_2| + \ldots + |b_n|$ does not exceed $MAXA \cdot MAXN = 10^9$.

If $n$ is odd, then let's cut off the last $3$ numbers and calculate $b$ for the array $a_1, a_2, \ldots, a_{n-3}$ the way we did it for even $n$ ($n-3$ is even since $n$ is odd). Then for the last $3$ numbers $a_{n-2}, a_{n-1}, a_n$ let's find two numbers with sum not equal to $0$ (by the Dirichlet principle, there will always exist two numbers out of three not equal to $0$, which are both positive or both negative, and the sum of those two numbers cannot be equal to $0$), let them be $a_i$, $a_j$, and the third one $a_k$. Then let $b_i=-a_k$, $b_j=-a_k$, $b_k=(a_i+a_j)$, the sum of $a_i \cdot b_i + a_j \cdot b_j + a_k \cdot b_k = 0$, and numbers of $b$ are not equal to $0$. The sum $|b_1| + |b_2| + \ldots + |b_{n-3}|$ does not exceed $MAXA \cdot (MAXN - 1 - 3)$ (since $MAXN$ is even, and we consider a case with odd $n$) and the sum $b_{n-2}+b_{n-1}+b_n$ does not exceed $MAXA + MAXA + 2 \cdot MAXA = 4 \cdot MAXA$, so the overall sum of $|b_i|$ does not exceed $MAXA \cdot MAXN = 10^9$.

 **Solution (AlFlen)**
```cpp
ttt = int(input())
for t in range(ttt):
	n = int(input())
	a = [int(x) for x in input().split()]
	start = 0
	if n % 2 == 1:
		if (a[0] + a[1] != 0):
			print(-a[2], -a[2], a[0] + a[1], end = " ")
		elif (a[1] + a[2] != 0):
			print(a[2] + a[1], -a[0], -a[0], end = " ")
		else:
			print(-a[1], a[0] + a[2], -a[1], end = " ")
		start = 3
	while start < n:
		print(-a[s + 1], a[s], end = " ")
		start += 2
	print()
```
[1582E - Pchelyonok and Segments](../problems/E._Pchelyonok_and_Segments.md "Codeforces Round 750 (Div. 2)") 

Idea: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "Grandmaster 74TrAkToR")

 **Tutorial**
### [1582E - Pchelyonok and Segments](../problems/E._Pchelyonok_and_Segments.md "Codeforces Round 750 (Div. 2)")

Let's notice that $k$ can be the answer, only if the sum of lengths of the segments does not exceed the number of elements in the array, that is $\frac{k \cdot (k + 1)}{2} \le n$. From this inequation we can get that $k$ is less than $\sqrt{2n}$, and when $n$ hits its maximal value, it does not exceed $447$.

Let $dp_{i,j}$ be the maximal sum on the segment of length $j$, with that we have already considered all elements on the suffix $i$ (that is, elements with indices $i, i + 1, \ldots, n$) and have already chosen segments with lengths $j, j - 1, \ldots, 1$, in which the sums increase. Let's learn to recalculate the values of dynamics. We can either not include the $i$-th element in the segment of length $j$, then we need refer to the value of dynamics $dp_{i+1,j}$, or include the $i$-th element, and then we are interested in the value of dynamics $dp_{i+j,j-1}$ — if it's greater than the sum on the segment $i, i + 1, \ldots, i + j - 1$, then we can take $j$ segments with lengths from $j$ to $1$ on the suffix $i$, answ otherwise we cannot take such segments on the suffix $i$. We need to take the maximum among these two cases in order to maximize the sum. To calculate the sum on a segment you can use prefix sums.

Asymptotic behavior of this solution — $O(n \cdot \sqrt{n})$.

 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 1e5 + 5, maxk = 450;
int a[maxn], dp[maxn][maxk];
int inf = 1e9 + 7;
ll pref[maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }
        int k = 0;
        while (k * (k + 1) / 2 <= n) k++;
        for (int j = 0; j < k; ++j) {
            dp[n + 1][j] = -inf;
        }
        dp[n + 1][0] = inf;
        for (int i = n; i >= 1; --i) {
            for (int j = 0; j < k; ++j) {
                dp[i][j] = dp[i + 1][j];
                if (j && i + j - 1 <= n && pref[i + j - 1] - pref[i - 1] < dp[i + j][j - 1]) {
                    dp[i][j] = max(dp[i][j], (int)(pref[i + j - 1] - pref[i - 1]));
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < k; ++j) {
            if (dp[1][j] > 0) ans = j;
        }
        cout << ans << 'n';
    }
    return 0;
}
```
[1582F2 - Korney Korneevich and XOR (hard version)](../problems/F2._Korney_Korneevich_and_XOR_(hard_version).md "Codeforces Round 750 (Div. 2)") 

Idea: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "Grandmaster 74TrAkToR")

 **Tutorial**
### [1582F2 - Korney Korneevich and XOR (hard version)](../problems/F2._Korney_Korneevich_and_XOR_(hard_version).md "Codeforces Round 750 (Div. 2)")

Let's iterate over all numbers of the array and for each number $t$ maintain a list $g_t$ of all numbers $y$, such that it's possible to choose an increasing subsequence on the current prefix, in which $xor$ of numbers is equal to $y$, and the last number of that increasing subsequence is less than $t$.

Let us currently consider the element $a_i$. Then let's consider elements of $g_{a_i}$ — there will be all values of $xor$-s of the subsequences to which we can append the element $a_i$. If $g_{a_i}$ contains a value $f$, then it's possible to get a value $f \oplus a_i$, then let's add the value $f \oplus a_i$ to all lists $g$ from $a_i + 1$ to the maximal value of $a$ (if the value that is being added is already in some $g$-s, it's unnecessary to add it there again).

Let's perform some optimizations for this solution.

1. Let's stop considering the values $g_t$ that have already been considered. That is, if we have already considered $g_t$ at some iteration, then let's erase it, but remember that we never need to add the values of $xor$, that are being erased. That optimization is sufficient to get the asymptotic behaviour $O((max\\_a)^3)$, where $max\\_a$ is the greatest one among all numbers of the array $a$ (for every number $t$ and its possible value of $xor$ $f$ we will pass over the value $t \oplus f$ to all states $t + 1, \ldots, max\\_a$; the amount of different $t$ is $O(max\\_a)$, the amount of $f$ is $O(max\\_a)$ as well, and the passing of the value each time is performed in $O(max\\_a)$).
2. Let's notice that when we pass some value of $xor$ equal to $f$ to elements $t + 1, \ldots, max\\_a$, and find the element $r$, in which that value of $xor$ has already been, then the value $f$ is already in all elements greater than $r$, and that's why we don't have to add the value $f$ any further. Using this optimization we can finally get a solution in $O(max\\_a^2)$, since for every value of $xor$ (the amount of them is $O(max\\_a)$), we perform $O(max\\_a)$ operations.

In total (considering all optimizations), the asymptotic behaviour of the solution is $O(n + (max\\_a)^2)$.

 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int const max_value = (1 << 13);
vector < int > g[max_value];
int ans[max_value], r[max_value];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    ans[0] = 1;
    for (int i = 0; i < max_value; ++i) {
        g[i].push_back(0);
    }
    for (int i = 0; i < max_value; ++i) {
        r[i] = max_value;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (auto key : g[x]) {
            int to = (key^x);
            ans[to] = 1;
            while (r[to] > x) {
                r[to]--;
                if (r[to] != x) g[r[to]].push_back(to);
            }
        }
        g[x] = {};
    }
    int k = 0;
    for (int i = 0; i < max_value; ++i) {
        k += ans[i];
    }
    cout << k << 'n';
    for (int i = 0; i < max_value; ++i) {
        if (ans[i]) cout << i << " ";
    }
    cout << 'n';
    return 0;
}
```
[1582G - Kuzya and Homework](../problems/G._Kuzya_and_Homework.md "Codeforces Round 750 (Div. 2)") 

Idea: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "Grandmaster 74TrAkToR")

 **Tutorial**
### [1582G - Kuzya and Homework](../problems/G._Kuzya_and_Homework.md "Codeforces Round 750 (Div. 2)")

Notice that the segment is simple, if for any prime number we will get a bracket sequence, which has the minimal balance greater of equal to $0$. The bracket sequence is formed the following way: we will iterate over the segment and add an opening bracket if we multiply by that number, and a closing bracket, if we divide by that number.

Let's consider the elements of the array $a$ and calculate the array $nxt_i$, wich contains the greatest left bound, such that we can do the $i$-th operations in integer numbers with every $l \le nxt_i$. To calculate such bounds, for each prime number let's maintain all indices of its occurences in the numbers of $a$ in a stack (if the prime numbers occurs in a number several times, we need to store the index several times). If the $i$-th operation is the operation of multiplying, then $nxt_i$ is equal to $i$, and for all prime divisors of the number $a_i$ we need to add the index $i$, and if it's the operation of division,then for all prime divisors of $a_i$ we need to delete indices (in the same amount as the prime divisor occurs in $a_i$) and save the smallest erased index in $nxt_i$. If for any prime divisor we had to erase an index from an empty stack, then we got a non-integer result, so $nxt_i=-1$.

Now that we know the values of the array $nxt$, we need to calculate the number of segments $1 \le l \le r \le n$, such that $l \le min(l, r)$, where $min(l, r)$ is the minimal value of $nxt_i$ on segment $l, r$. 

We can do that using segment tree on minimum in $O(n \log_2 n)$ (iterate over the left bound and traversing the tree from the root find the greatest right bound for current left one) or using linear algorithms with a stack (to do that, let's iterate over all left bounds in decreasing order and maintain a stack on minimum on the array $nxt$).

 **Solution (74TrAkToR)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int const maxn = 1e6 + 5;
int a[maxn];
int prime[maxn];
int L[maxn];
vector < int > pos[maxn];

inline void add(int x, int l) {
    L[l] = l;
    while (x > 1) {
        pos[prime[x]].push_back(l);
        x /= prime[x];
    }
}

inline void del(int x, int l) {
    if (x == 1) {
        L[l] = l;
        return;
    }
    L[l] = l;
    while (x > 1) {
        if ((int)pos[prime[x]].size() == 0) {
            L[l] = 0;
            return;
        }
        L[l] = min(L[l], pos[prime[x]].back());
        pos[prime[x]].pop_back();
        x /= prime[x];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 2; i < maxn; ++i) {
        if (prime[i] == 0) {
            prime[i] = i;
            if (i > 1000) continue;
            for (int j = i * i; j < maxn; j += i) {
                prime[j] = i;
            }
        }
    }

    char type;
    for (int i = 1; i <= n; ++i) {
        cin >> type;
        if (type == '*') add(a[i], i);
        else del(a[i], i);
    }

    ll answer = 0;
    vector < pair < int, int > > f_min;
    for (int i = n; i >= 1; --i) {
        int cnt = 1;
        while ((int)f_min.size() > 0 && f_min.back().first >= L[i]) {
            cnt += f_min.back().second;
            f_min.pop_back();
        }
        f_min.push_back({L[i], cnt});
        if (L[i] == i) answer += (ll)cnt;
    }
    cout << answer << 'n';
    return 0;
}

```
