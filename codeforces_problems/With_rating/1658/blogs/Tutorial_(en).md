# Tutorial_(en)

Thank you for participating in the contest! We hope you enjoy the problems. You can also give feedback on each problem, it will help us much in future problem settings. By the way, feel free to share your solution!

[1658A - Marin and Photoshoot](../problems/A._Marin_and_Photoshoot.md "Codeforces Round 779 (Div. 2)")

 **Hint 1**How will you solve this problem if there are just 2 male cosplayers?

 **Hint 2**Notice the distance between 2 consecutive male cosplayers.

 **Tutorial**It is easy to see, in a beautiful picture, there must be at least 2 female cosplayers between 2 consecutive male cosplayers. It is also the sufficient condition, as if there are x male cosplayers in a subsegment, there are at least 2(x−1)=2x−2≥x for all x≥2.

 **Solution****C++**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int n;
string s;
vector<int> v;
 
void solve() {
    v.clear();
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') v.push_back(i);
    }
    for (int i = 0; i < (int)v.size() - 1; ++i) {
        if (v[i + 1] - v[i] <= 2) ans += 2 - (v[i + 1] - v[i]) + 1;
    }
    cout << ans << 'n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}
```
 **Python**
```cpp
t = int(input())
for _ in range(t):
    n = input()
    s = input()
    ans = 0
    cnt = 2
    for c in s:
        if c == '1': cnt += 1
        else:
            ans += max(2 - cnt, 0)
            cnt = 0
    print(ans)
 
 
```
 **Feedback*** Didn't solve 


[*43*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*140*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*159*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*132*](https://codeforces.com/data/like?action=like "I like this")
[1658B - Marin and Anti-coprime Permutation](../problems/B._Marin_and_Anti-coprime_Permutation.md "Codeforces Round 779 (Div. 2)")

 **Hint 1**Let's g=gcd(1⋅p1,2⋅p2,…,n⋅pn). What is the maximum value of g?

 **Hint 2**For each value of g, can you construct a satisfying permutation?

 **Tutorial**We can prove that g≤2.

 **Proof**Assuming g>2:

 * If there exists a prime number p>2 that p∣g, there are ⌊np⌋ numbers divisible by p, so we can match at most 2⌊n3⌋ numbers into pairs, which is smaller than n.
* Otherwise, we can match odd numbers with even positions, and even numbers with odd positions, which leads to 2∣g. Because p2 is odd, 2⋅p2 is not divisible by 2k with k>1.

Therefore, g≤2.

Therefore:

 * If n is odd, the answer is 0 since the number of odd is greater than the number of even.
* Otherwise, we will match odd with even and vice versa. For odd number in even position, we have (n2)! ways. According to the multiplicative rule, the answer will be ((n2)!)2.
 **Solution****C++**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    if (n & 1) {
        cout << "0n";
        return;
    }
    long long ans = 1;
    for (int i = 1; i <= n / 2; ++i) {
        ans *= 1LL * i * i % MOD;
        ans %= MOD;
    }
    cout << ans << 'n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

```
 **Python**
```cpp
MOD = 998244353
t = int(input())

for _ in range(t):
	n = int(input())
	if n & 1:
	    print(0)
	    continue
	ans = 1
	for i in range(1, n // 2 + 1):
		ans = ans * i % MOD
	ans = ans * ans % MOD
	print(ans)
```
 **Feedback*** Didn't solve 

 
[*47*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*343*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*24*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*29*](https://codeforces.com/data/like?action=like "I like this")
[1658C - Shinju and the Lost Permutation](../problems/C._Shinju_and_the_Lost_Permutation.md "Codeforces Round 779 (Div. 2)")

 **Hint 1**There is exactly one 1 in array c (in (i−1)-th cyclic shift, ci>1 if p1≠n, and ci=1 if p1=n), so if the number of 1s is greater or less than one, the answer is NO. 

 **Hint 2**We can rotate the array such that c1=1 (initial state) because we don't have to construct the permutation, so if there exists a permutation with p1=n, the answer is YES.

 **Hint 3**Notice the difference of ci and ci+1.

 **Tutorial**In the i-th cyclic shift, if p1>p2 then ci+1≤ci, otherwise ci+1−ci=1, so if there exists a position i such that ci+1−ci>1, the answer is NO.

This is the sufficient condition. It can be shown that, if ci+1−ci≤1 for all 1≤i<n, then there exists a permutation that satisfies.

Here is a sketch of the construction: [Tutorial_(en).md?#comment-899523](Tutorial_(en).md?#comment-899523)

 **Solution****C++**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &v: a) cin >> v;
    if (count(a.begin(), a.end(), 1) != 1) {
        cout << "NOn";
        return;
    }
    int p = find(a.begin(), a.end(), 1) - a.begin();
    rotate(a.begin(), a.begin() + p, a.end());
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > 1) {
            cout << "NOn";
            return;
        }
    }
    cout << "YESn";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```
 **Python**
```cpp
import sys
input = sys.stdin.readline
 
t = int(input())
for _ in range (t):
    n = int(input())
    a = list(map(int, input().split()))
 
    if a.count(1) != 1:
        print("NO")
        continue
 
    a.append(a[0])
    ok = True
    for i in range (0, n):
        if a[i + 1] - a[i] > 1:
            ok = False
            break
    
    if ok: print("YES")
    else: print("NO")

```
 **Feedback*** Didn't solve 

 
[*210*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*208*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*48*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*424*](https://codeforces.com/data/like?action=like "I like this")
[1658D1 - 388535 (Easy Version)](../problems/D1._388535_(Easy_Version).md "Codeforces Round 779 (Div. 2)")

 **Tutorial**Let's look at the binary representation of numbers from 0 to 7:

 * 000
* 001
* 010
* 011
* 100
* 101
* 110
* 111

Let us look at the i-th bit only (maybe i=2), we will get a sequence like [0,0,1,1,0,0,1,1]. Notice that the number of zeroes equals the number of ones in a prefix only when the length of the prefix is a multiple of 2i. Otherwise, there will be more zeros than ones.

So, we will count the number of flipped and unflipped bits for each bit position. 

 * If the number of ones is greater than the number of zeros, the i-th bit of x must be 1.
* If the number of zeros is greater than the number of ones, the i-th bit of x must be 0.
* If the number of ones is equal to the number of zeros, that i-th bit of x can either be 0 or 1.

However, if the number of ones is equal to the number of zeros, we can assign the i-th bit anything we like. The rough sketch of the proof is that if x is inside a then x⊕2i is also inside a.

 **Solution****C++**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int p[N], cnt[32][2];
 
void solve() {
    memset(cnt, 0, sizeof cnt);
    int l, r; cin >> l >> r;
    for (int i = l; i <= r; ++i) {
    	int x; cin >> x;
    	for (int j = 0; j <= 30; ++j, x >>= 1)
    		cnt[j][x & 1]++;
    }
    int ans = 0;
    for (int i = 0; i <= 30; ++i) {
    	ans |= ((cnt[i][0] < cnt[i][1]) * (1 << i));
    }
    cout << ans << 'n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

```
 **Python**
```cpp
import sys
input = sys.stdin.readline
 
t = int(input())
for _ in range (t):
    l, r = map(int, input().split())
    a = list(map(int, input().split()))
    cnt = [[0] * 2 for _ in range (32)]
 
    for x in a:
        for i in range (31):
            cnt[i][x & 1] += 1
            x >>= 1
 
    ans = 0
    for i in range (31):
        if (cnt[i][0] < cnt[i][1]):
            ans |= (1 << i)
    
    print(ans)

```
[1658D2 - 388535 (Hard Version)](../problems/D2._388535_(Hard_Version).md "Codeforces Round 779 (Div. 2)")

 **Hint 1**If a⊕b=1, then (a⊕x)⊕(b⊕x)=1.

 **Hint 2**if l is even and r is odd, the last bit of x can be either 0 or 1 (we can pair ai with ai⊕1).

 **Tutorial**There are two solutions to this problem.

If l is even and r is odd, we can skip the last bit and divide the range by two, then recursively solve it. Otherwise, we will pair ai with ai⊕1, and we will left with at most 2 candidates for x to check.

There is also another solution: we can iterate all possibilities of x (by assuming ai is l⊕x for all 1≤i≤n). If x is the hidden number, l≤ai⊕x≤r for all 1≤i≤n, so the problem reduce to "count the number of ai that l≤ai⊕x≤r", which can be solved with binary trie.

 **Solution****C++**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], l, r; 
set <int> s, s2;
 
void solve() {
    int mul = 1;
    s.clear();
    cin >> l >> r; 
    for (int i = l; i <= r; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }

    for (; l % 2 == 0 && r % 2 == 1; l >>= 1, r >>= 1, mul <<= 1) {
        s2.clear();
        for (int i: s) s2.insert(i >> 1);
        swap(s, s2);   
    }

    int ans;
    if (l % 2 == 0) ans = r;
    else ans = l;

    for (int i: s) {
        if (s.find(i ^ 1) == s.end()) {
            int cur = i ^ ans;
            bool f = true;
            for (int j : s)
                f &= ((cur ^ j) >= l && (cur ^ j) <= r);
            if (f) {
                ans = cur;
                break;
            }
        }
    }
    cout << ans * mul << 'n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

```
 **Python**
```cpp
import sys
input = sys.stdin.readline
 
def solve(l: int, r: int, s: set):
    if l % 2 == 0 and r % 2 == 1:
        t = set()
        for v in s: t.add(v >> 1)
        return solve(l >> 1, r >> 1, t) << 1
    else:
        for v in s:
            if (v ^ 1) not in s:
                ok = True
                ans = v
                if l % 2 == 0: ans ^= r
                else: ans ^= l
                for x in s:
                    if (x ^ ans) < l or (x ^ ans) > r:
                        ok = False
                        break
                if ok: return ans
            
 
t = int(input())
for _ in range (t):
    l, r = map(int, input().split())
    s = set(map(int, input().split()))
    print(solve(l, r, s))

```
 **Feedback*** Didn't solve 

 
[*145*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*282*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*54*](https://codeforces.com/data/like?action=like "I like this")
[1658E - Gojou and Matrix Game](../problems/E._Gojou_and_Matrix_Game.md "Codeforces Round 779 (Div. 2)")

 **Hint 1**What if a player is forced to play in a cell where they get fewer points than the previous move?

 **Hint 2**Rephrase the problem, then solve it with dynamic programming.

 **Tutorial**Suppose that Marin places a token at (a,b). If Gojou places a token at (c,d) where Vc,d<Va,b, then Gojou would not have any advantage as Marin can play at (a,b) again. After a very huge number of turns, Marin will have more points than Gojou. Generally, if a player is forced to play in a cell where they get fewer points than the previous move, they would instantly lose.

Therefore, we can rephrase the problem as such:

 * Apart from the first move, the token placed by a player must be more than Manhattan distance *k* away from the previous token placed on the matrix.
* Apart from the first move, the token placed by a player must be on a cell with more points than the cell with the token placed by the previous player.
* The player who plays the last token is the winner.

This turns out to be a standard dynamic programming.

Let dp[i][j] return 1 if the player who places a token at (i,j) wins.

Let Va,b=n2, then we have dp[a][b]=1 as a base case.

Then we will fill the values of dp in decreasing values of Vi,j. dp[i][j]=1 if for all (i′,j′) such that |i−i′|+|j−j′|>k, we have dp[i′][j′]=0. Note that by taking the contrapositive, this is equivalent to for all (i′,j′) such that dp[i′][j′]=1, we have |i−i′|+|j−j′|≤k.

Let us maintain a set S that stores the pairs (i′,j′) such that dp[i′][j′]=1, then our operations are:

 * adding point (i,j) to S
* given (i,j), check if for all (i′,j′) in S, |i−i′|+|j−j′|≤k

Notice that |i−i′|+|j−j′|≤k⇔max(|(i+j)−(i′+j′)|,|(i−j)−(i′−j′)|)≤k.

Checking max(|(i+j)−(i′+j′)|,|(i−j)−(i′−j′)|)≤k is very simple as we only need to store the minimum and maximum of all (i+j) and (i−j).

 **Solution****C++**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
bool f[N][N];
int l, r, u, d, n, k;
vector<array<int, 5>> v;

bool check(int i, int j) {
    return (abs(i - u) <= k && abs(i - d) <= k && abs(j - l) <= k && abs(j - r) <= k);
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = false;
            int x; cin >> x;
            v.push_back({x, i, j, i + j, j - i});
        }
    }

    sort(v.begin(), v.end(), greater<array<int, 5>>());
    l = v[0][4], r = v[0][4], u = v[0][3], d = v[0][3];
    for (array<int, 5> cell: v) {
        if (check(cell[3], cell[4])) {
            f[cell[1]][cell[2]] = true;
            l = min(l, cell[4]);
            r = max(r, cell[4]);
            u = min(u, cell[3]);
            d = max(d, cell[3]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (f[i][j]) cout << 'M';
            else cout << 'G';
        }
        cout << 'n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

```
 **Feedback*** Didn't solve 

 
[*15*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*82*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")
[1658F - Juju and Binary String](../problems/F._Juju_and_Binary_String.md "Codeforces Round 779 (Div. 2)")

 **Hint 1**Let b be the number of black balls and w be the number of white balls.

The answer will be impossible if m is not a multiple of b+wgcd(b,w).

 **Observation**It is easy to show that the cuteness of s is bn.

What is the number of 1 in the concatenated string needed so that the answer exists?

 **Proof**The cuteness of s is bn=bb+w by definition.

Now consider t=s[l1,r1]+[l2,r2]+⋯+s[lk,rk], the cuteness of the concatenated string.

The cuteness of t is bb+w, so the number of 1 needed is k=m⋅wb+w.

If k is not an integer then there will be no answer, so m must be a multiple of b+wgcd(b,w).

 **Hint 2**We don't need more than 2 parts, or to say k≤2 is needed in this problem.

 **Observation**Let ci= (the number of 1 in s[i…i+m−1]).

For convenient, from now let assume the array and string is wrapped around: s[i]=s[i+n] and ci=ci+n.

We have |ci−ci+1|≤1 and there exists ci=y for all y that min(ci)≤y≤max(ci).

 **Contestant's Proof**GM+ [smax](https://codeforces.com/profile/smax "Grandmaster smax") provides a simple and clean answer [here](Tutorial_(en).md?#comment-899678).

 **Author's Proof**Let L=min(ci), R=max(ci) and we are doing with wrap around arrays for convenient.

We want to prove that for any y that L≤y≤R there will be some ci=y.

Let di=max(cp,cp+1,…,ci) for p is the minimal position that cp=L.

Let fx is the first position i starting p that di=x, we have dfx=cfx

[1] Since L≤y≤R and, we have L=dp≤dp+1≤⋯≤dp+n−1=R.

[2] Since |ci+1−ci|≤1 we can show that.

 ∀p<i<p+n→[di=di−1di=di−1+1[3] Since ci∈N, we also have di∈N

From [1], [2], [3], if there is di=v>L then there will be dj=v−1 for some j that p+(v−L)≤j<i.

⇔∀v,min(di)≤v≤max(di)→∃dfi=v

⇔∃dfi=y

⇔∃cfi=y

 **Tutorial**The answer will be impossible if m is not a multiple of b+wgcd(b,w).

Otherwise, it is proved that k≤2 is needed.

Since we need to select a minimum k, let's first check if there is a solution with k=1

 **Spoiler**If there exist such position p that 1≤p≤n−m+1 and s[p,p+m−1] have the same cuteness as s[1,n] then we found an answer.

Otherwise there must be an answer with k=2, and it is simple too

 **Spoiler**If there exist such position p that 1≤p<m and s[1,p]∪s[n−(m−p)+1,n] have the same cuteness as s[1,n] then we found an answer.

Both can be done in linear O(n) with the sliding window technique or prefixsum.

 **Solution****C++**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int one = count_if(s.begin(), s.end(), [](char c) { return c == '1'; });
        if (1LL * one * k % n != 0) {
            cout << "-1n";
        } else {
            one = 1LL * one * k / n;
            vector<int> suf(2 * n + 1);
            for (int i = 1; i <= 2 * n; i++) {
                suf[i] = suf[i - 1] + (s[(i - 1) % n] == '1');
                if (i >= k && suf[i] == suf[i - k] + one) {
                    if (i <= n) {
                        cout << "1n";
                        cout << i - k + 1 << " " << i << 'n';
                    } else {
                        cout << "2n";
                        cout << 1 << " " << i - n << 'n';
                        cout << i - k + 1 << " " << n << 'n';
                    }
                    break;
                }
            }
        }
    }
}
```
 **Feedback*** Didn't solve 

 
[*39*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*40*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*9*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*19*](https://codeforces.com/data/like?action=like "I like this")
