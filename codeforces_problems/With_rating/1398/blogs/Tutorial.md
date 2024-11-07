# Tutorial

[1398A - Bad Triangle](../problems/A._Bad_Triangle.md "Educational Codeforces Round 93 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1398A - Bad Triangle](../problems/A._Bad_Triangle.md "Educational Codeforces Round 93 (Rated for Div. 2)")

The triangle with side $a \ge b \ge c$ is degenerate if $a \ge b + c$. So we have to maximize the length of the longest side ($a$) and minimize the total length of other sides ($b + c$).

Thus, if $a_n \ge a_1 + a_2$ then we answer if $1, 2, n$, otherwise the answer is -1.

 **Solution (Roms)**
```cpp
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if a[0] + a[1] > a[-1]:
        print(-1)
    else:
        print(1, 2, n)
```
[1398B - Substring Removal Game](../problems/B._Substring_Removal_Game.md "Educational Codeforces Round 93 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1398B - Substring Removal Game](../problems/B._Substring_Removal_Game.md "Educational Codeforces Round 93 (Rated for Div. 2)")

The following greedy strategy works: during each turn, delete the largest possible substring consisting of $1$-characters. So we have to find all blocks of $1$-characters, sort them according to their length and model which blocks are taken by Alice, and which — by Bob.

Why does the greedy strategy work? It's never optimal to delete some part of the block of ones — because we either have to spend an additional turn to delete the remaining part, or allow our opponent to take it (which is never good). Why don't we need to delete zeroes? If we delete a whole block of zeroes, our opponent can take the newly formed block of $1$'s during their turn, and it is obviously worse than taking a part of that block. And deleting some part of a block of zeroes doesn't do anything — our opponent will never delete the remaining part because it's suboptimal.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

void solve() {
	string s;
	cin >> s;
	vector<int> a;
	forn(i, sz(s)) if (s[i] == '1') {
		int j = i;
		while (j + 1 < sz(s) && s[j + 1] == '1')
			++j;
		a.push_back(j - i + 1);
		i = j;
	}
	sort(a.rbegin(), a.rend());
	int ans = 0;
	for (int i = 0; i < sz(a); i += 2)
		ans += a[i];
	cout << ans << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
}
```
[1398C - Good Subarrays](../problems/C._Good_Subarrays.md "Educational Codeforces Round 93 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1398C - Good Subarrays](../problems/C._Good_Subarrays.md "Educational Codeforces Round 93 (Rated for Div. 2)")

We use zero indexing in this solution. We also use half-closed interval (so subarray $[l, r]$ is $a_l, a_{l + 1}, \dots, a_{r-1}$).

Let's precalculate the array $p$, where $p_i = \sum\limits_{j = 0}^{i - 1} a_j$ (so $p_x$ if sum of first $x$ elements of $a$).

Then subarray $[l, r]$ is good if $p_r - p_l = r - l$, so $p_r - r = p_l - l$.

Thus, we have to group all prefix by value $p_i - i$ for $i$ from $0$ to $n$. And if the have $x$ prefix with same value of $p_i - i$ then we have to add $\frac{x (x-1)}{2}$ to the answer.

 **Solution (Roms)**
```cpp
for _ in range(int(input())):
    n = int(input())
    a = input()
    d = {0 : 1}
    res, s = 0, 0
    
    for i in range(n):
        s += int(a[i])
        x = s - i - 1
        if x not in d:
            d[x] = 0
        d[x] += 1
        res += d[x] - 1
        
    print(res)
```
[1398D - Colored Rectangles](../problems/D._Colored_Rectangles.md "Educational Codeforces Round 93 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1398D - Colored Rectangles](../problems/D._Colored_Rectangles.md "Educational Codeforces Round 93 (Rated for Div. 2)")

Let's build some rectangles and take a look at the resulting pairings. For example, consider only red/green rectangles. Let the rectangles be $(r_{i1}, g_{i1})$, $(r_{i2}, g_{i2})$, .... Sort them in a non-decreasing order of $r_{ij}$. I claim that in the most optimal set $g_{ij}$ are also sorted in a non-decreasing order. It's easy to prove with some induction.

Moreover, if there are some green or red sticks that are not taken and that are longer than the smallest taken corresponding sticks, then it's always optimal to take those instead.

These facts helps us to conclude that from each set only some suffix of the largest sticks are taken. And they also give us the idea of the solution: sort the sticks in each set and pick the largest from any of the two sets into a pair until no pairs can be taken.

However, the greedy approach of "take from any two of the three sets" is incorrect. We need to choose these two sets smartly. Let $dp[r][g][b]$ store the maximum total area that can be obtained by taking $r$ largest red sticks, $g$ largest green sticks and $b$ largest blue sticks. Each transition chooses a pair of colors and takes the next pairs in both of them.

The answer is the maximum value in all the $dp$.

Overall complexity: $O(RGB + R \log R + G \log G + B \log B)$.

 **Solution (pikmike)**
```cpp
n = [int(x) for x in input().split()]
a = []
for i in range(3):
	a.append([int(x) for x in input().split()])
	a[i].sort(reverse=True)

dp = [[[0 for i in range(n[2] + 1)] for j in range(n[1] + 1)] for k in range(n[0] + 1)]
ans = 0
for i in range(n[0] + 1):
	for j in range(n[1] + 1):
		for k in range(n[2] + 1):
			if i < n[0] and j < n[1]:
				dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + a[0][i] * a[1][j])
			if i < n[0] and k < n[2]:
				dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + a[0][i] * a[2][k])
			if j < n[1] and k < n[2]:
				dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + a[1][j] * a[2][k])
			ans = max(ans, dp[i][j][k])

print(ans)
```
[1398E - Two Types of Spells](../problems/E._Two_Types_of_Spells.md "Educational Codeforces Round 93 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms") and [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1398E - Two Types of Spells](../problems/E._Two_Types_of_Spells.md "Educational Codeforces Round 93 (Rated for Div. 2)")

Let's solve this problem for fixed set of spells. For example, we have a fireball spells with powers $f_1, f_2, \dots , f_m$ and lighting spells with powers $l_1, l_2, \dots, l_k$. We reach the maximum total damage if we can double all $k$ spells with maximum damage. It's possibly iff the set of $k$ largest by power spell (let's denote this set as $s$) contains at least one fireball spell. Otherwise (if set $s$ contains only lightning spells) the maximum damage reach when we double $k-1$ largest spells in set $s$ and one largest spell not from set $s$ (if such spell exist).

Now how do you solve the original problem when spells are added and removed? All we have to do it maintain the set of $x$ largest by power spells (where $x$ is current number of lightning spells), and change this set by adding or removing one spell. Also you have to maintain the sum of spells power in set this set and the number of fireball spells in this set. You can do it by set in C++ or TreeSet on Java.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 9;

int n;
set <int> sDouble;
long long sum[2];
set <int> s[2];
int cntDouble[2];

// 0: 0 -> 1
// 1: 1 -> 0
void upd(int id) {
    assert(s[id].size() > 0);
    int x = *s[id].rbegin();
    if (id == 1) x = *s[id].begin();
    bool d = sDouble.count(x);
    
    sum[id] -= x, sum[!id] += x;
    s[id].erase(x), s[!id].insert(x);
    cntDouble[id] -= d, cntDouble[!id] += d;
}


int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tp, x;
        cin >> tp >> x;// tp = 1 if double
        
        if (x > 0) {
            sum[0] += x;
            s[0].insert(x);
            cntDouble[0] += tp;
            if (tp) sDouble.insert(x);
        } else {
            x = -x;
            int id = 0;
            if (s[1].count(x)) id = 1;
            else assert(s[0].count(x));
            
            sum[id] -= x;
            s[id].erase(x);
            cntDouble[id] -= tp;
            if (tp) { 
                assert(sDouble.count(x));
                sDouble.erase(x);
            }
        }
        
        int sumDouble = cntDouble[0] + cntDouble[1];
        while (s[1].size() < sumDouble) upd(0);
        while (s[1].size() > sumDouble) upd(1);
        while (s[1].size() > 0 && s[0].size() > 0 && *s[0].rbegin() > *s[1].begin()) {
            upd(0);
            upd(1);
        }
        assert(s[1].size() == sumDouble);
        
        long long res = sum[0] + sum[1] * 2;
        if (cntDouble[1] == sumDouble && sumDouble > 0) {
            res -= *s[1].begin();
            if (s[0].size() > 0) res += *s[0].rbegin();
        }
        cout << res << endl;
    }
    return 0;
}
```
[1398F - Controversial Rounds](../problems/F._Controversial_Rounds.md "Educational Codeforces Round 93 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1398F - Controversial Rounds](../problems/F._Controversial_Rounds.md "Educational Codeforces Round 93 (Rated for Div. 2)")

Let's consider the following function $f(pos, x)$: minimum index $npos$ such that there is a substring of string $s_{pos}, s_{pos+1}, \dots, s_{npos-1}$ of length $x$ consisting of only characters $1$ and $?$ or $0$ and $?$. If this function has asymptotic $O(1)$ then we can solve problem for $O(n log n)$.

Now, let's precalculate two array $nxt0$ and $nxt1$; $nxt0[i]$ is equal the maximum integer $len$ such that substring $s_i, s_{i+1}, \dots, s_{i+len-1}$ consist only characters $1$ and $?$. $nxt1[i]$ is equal the maximum integer $len$ such that substring $s_i, s_{i+1}, \dots, s_{i+len-1}$ consist only characters $0$ and $?$. 

Also let's precalculate the arrays $p0$ and $p1$ of size $n$; $p0[len]$ contain all positions $pos$ such that substring $s_{pos}, s_{pos+1}, \dots, s_{pos+len-1}$ consist only characters $1$ and $?$ and $pos = 0$ or $s_{pos - 1} = 0$; $p1[len]$ contain all positions $pos$ such that substring $s_{pos}, s_{pos+1}, \dots, s_{pos+len-1}$ consist only characters $0$ and $?$ and $pos = 0$ or $s_{pos - 1} = 1$. 

After that let's solve problem for some $x$. Suppose, that now we already processed first $pos$ elements of $s$. If $nxt0[pos] \ge x$ or $nxt1[pos] \ge x$ then we increase the answer and change $pos = pos + x$. Otherwise we have to find the minimum element (denote this element as $npos$) in $p0[x]$ or $p1[x]$ such that $npos \ge pos$. If there is no such element then we found the final answer . Otherwise let's increase answer and change $pos = npos + x$ and continue this algorithm.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(1e6) + 99;
const int INF = int(1e9) + 99;

int n;
string s;
vector <int> p[2][N];
int nxt[2][N];
int ptr[2];
char buf[N];

int main(){
    cin >> n >> s;
    
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != '0') nxt[0][i] = 1 + nxt[0][i + 1];
        if (s[i] != '1') nxt[1][i] = 1 + nxt[1][i + 1];
    }
    
    for (int b = 0; b <= 1; ++b) {
        int l = 0;
        while (l < n) {
            if (s[l] == char('0' + b)) {
                ++l;
                continue;
            }
            int r = l + 1;
            while (r < n && s[r] != char('0' + b)) ++r;
            for (int len = 1; len <= r - l; ++len)
                p[b][len].push_back(l);
            l = r;
        }
    }

    for (int len = 1; len <= n; ++len) {
        int pos = 0, res = 0;
        ptr[0] = ptr[1] = 0;
        
        while (pos < n) {
            int npos = INF;
            for (int b = 0; b <= 1; ++b) {
                if (nxt[b][pos] >= len) 
                    npos = min(npos, pos + len);
                while (ptr[b] < p[b][len].size() && pos > p[b][len][ ptr[b] ]) 
                    ++ptr[b];
                if (ptr[b] < p[b][len].size()) 
                    npos = min(npos, p[b][len][ ptr[b] ] + len);
            }
            if (npos != INF) 
                ++res;
            pos = npos;
        }
        
        cout << res << ' ';
    }
    cout << endl;
    
    return 0;
}
```
[1398G - Running Competition](../problems/G._Running_Competition.md "Educational Codeforces Round 93 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1398G - Running Competition](../problems/G._Running_Competition.md "Educational Codeforces Round 93 (Rated for Div. 2)")

First of all, let's find all possible lengths of the laps (after doing that, we can just check every divisor of $l_i$ to find the maximum possible length of a lap for a given query). A lap is always a rectangle — you can't construct a lap without using any vertical segments or using an odd number of vertical segments, and if you try to use $4$ or more vertical segments, you can't go back to the point where you started because both horizontal segments are already partially visited. So, a lap is a rectangle bounded by two vertical segments; and if we use vertical segments $i$ and $j$, the perimeter of this rectangle is $2(a_i - a_j + y)$.

Let's find all values that can be represented as $a_i - a_j$. A naive $O(n^2)$ approach will be too slow, we have to speed it up somehow. Let's build an array $b$ of $n + 1$ numbers where $b_j = K - a_j$ ($K$ is some integer greater than $200000$). Each number that can be represented as $a_i - a_j$ can also be represented as $a_i + b_j - K$, so we have to find all possible sums of two elements belonging to different arrays.

The key observation here is that, if $a_i$ and $b_j$ are small, we can treat each array as a polynomial: let $A(x) = \sum \limits_{i=0}^{n} x^{a_i}$, and similarly, $B(x) = \sum \limits_{j=0}^{n} x^{b_j}$. Let's look at the product of that polynomials. The coefficient for $x^k$ is non-zero if and only if there exist $i$ and $j$ such that $a_i + b_j = k$, so finding all possible sums (and all possible differences) can be reduced to multiplying two polynomials, which can be done faster than $O(n^2)$ using Karatsuba's algorithm or FFT.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)
#define sz(a) ((int)(a).size())

const int LOGN = 20;
const int N = (1 << LOGN);
const int K = 200043;
const int M = 1000043;

typedef double ld;
typedef long long li;

const ld PI = acos(-1.0);

struct comp 
{
    ld x, y;
    comp(ld x = .0, ld y = .0) : x(x), y(y) {}
    inline comp conj() { return comp(x, -y); }
};

inline comp operator +(const comp &a, const comp &b) 
{
    return comp(a.x + b.x, a.y + b.y);
}

inline comp operator -(const comp &a, const comp &b) 
{
    return comp(a.x - b.x, a.y - b.y);
}

inline comp operator *(const comp &a, const comp &b) 
{
    return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

inline comp operator /(const comp &a, const ld &b) 
{
    return comp(a.x / b, a.y / b);
}

vector<comp> w[LOGN];
vector<int> rv[LOGN];

void precalc() 
{
    for(int st = 0; st < LOGN; st++) 
    {
        w[st].assign(1 << st, comp());
        for(int k = 0; k < (1 << st); k++) 
        {
            double ang = PI / (1 << st) * k;
            w[st][k] = comp(cos(ang), sin(ang));
        }
        
        rv[st].assign(1 << st, 0);
        if(st == 0) 
        {
            rv[st][0] = 0;
            continue;
        }
        int h = (1 << (st - 1));
        for(int k = 0; k < (1 << st); k++)
            rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
    }
}

inline void fft(comp a[N], int n, int ln, bool inv) 
{
    for(int i = 0; i < n; i++) 
    {
        int ni = rv[ln][i];
        if(i < ni)
            swap(a[i], a[ni]);
    }
    
    for(int st = 0; (1 << st) < n; st++) 
    {
        int len = (1 << st);
        for(int k = 0; k < n; k += (len << 1)) 
        {
            for(int pos = k; pos < k + len; pos++) 
            {
                comp l = a[pos];
                comp r = a[pos + len] * (inv ? w[st][pos - k].conj() : w[st][pos - k]);
                
                a[pos] = l + r;
                a[pos + len] = l - r;
            }
        }
    }
    
    if(inv) for(int i = 0; i < n; i++)
        a[i] = a[i] / n;
}

comp aa[N];
comp bb[N];
comp cc[N];

inline void multiply(comp a[N], int sza, comp b[N], int szb, comp c[N], int &szc) 
{
    int n = 1, ln = 0;
    while(n < (sza + szb))
        n <<= 1, ln++;
    for(int i = 0; i < n; i++)
        aa[i] = (i < sza ? a[i] : comp());
    for(int i = 0; i < n; i++)
        bb[i] = (i < szb ? b[i] : comp());
        
    fft(aa, n, ln, false);
    fft(bb, n, ln, false);
    
    for(int i = 0; i < n; i++)
        cc[i] = aa[i] * bb[i];
        
    fft(cc, n, ln, true);
    
    szc = n;
    for(int i = 0; i < n; i++)
        c[i] = cc[i];
}

comp a[N];
comp b[N];
comp c[N];
int used[M];
int dp[M];

int main()
{
    precalc();
    int n, x, y;
    for(int i = 0; i < M; i++)
        dp[i] = -1;
    scanf("%d %d %d", &n, &x, &y);
    vector<int> A(n + 1);
    for(int i = 0; i <= n; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i <= n; i++)
    {
        a[A[i]] = comp(1.0, 0.0);
        b[K - A[i]] = comp(1.0, 0.0);
    }
    int s = 0;
    multiply(a, K + 1, b, K + 1, c, s);
    for(int i = K + 1; i < s; i++)
        if(c[i].x > 0.5)
            used[(i - K + y) * 2] = 1;
    for(int i = 1; i < M; i++)
    {
        if(!used[i]) continue;
        for(int j = i; j < M; j += i)
            dp[j] = max(dp[j], i);
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int l;
        scanf("%d", &l);
        printf("%d ", dp[l]);
    }
}
```
