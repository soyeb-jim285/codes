# Tutorial_(en)

[1780A - Hayato and School](../problems/A._Hayato_and_School.md "Codeforces Round 846 (Div. 2)")

Idea: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Master AndreyPavlov")   
 Preparation: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Master AndreyPavlov")   
 Editorialist: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Master AndreyPavlov")

 **Tutorial**Note that there are two variants of which numbers to take to make their amount odd: 3 odd number; 2 even and 1 odd. Let’s save all indices of even and odd numbers into two arrays, and check both cases.

 **Implementation (Python)**
```cpp
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    odd, even = [], []
    for i in range(n):
        if a[i] % 2 == 0:
            even.append(i + 1)
        else:
            odd.append(i + 1)
    if len(odd) >= 1 and len(even) >= 2:
        print("YES")
        print(odd[0], even[0], even[1])
    elif len(odd) >= 3:
        print("YES")
        print(odd[0], odd[1], odd[2])
    else:
        print("NO")
        
t = int(input())
for test in range(t):
    solve()
```
 **Implementation (C++)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> odd, even;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x % 2 == 0) {
                even.push_back(i);
            } else {
                odd.push_back(i);
            }
        }
        if (odd.size() >= 3) {
            cout << "YESn";
            cout << odd[0] << " " << odd[1] << " " << odd[2] << 'n';
        } else if (odd.size() >= 1 && even.size() >= 2) {
            cout << "YESn";
            cout << odd[0] << " " << even[0] << " " << even[1] << 'n';
        } else {
            cout << "NOn";
        }
    }
}
```
[1780B - GCD Partition](../problems/B._GCD_Partition.md "Codeforces Round 846 (Div. 2)")

Idea: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR")   
 Preparation: [qualdoom](https://codeforces.com/profile/qualdoom "Master qualdoom")   
 Editorialist: [qualdoom](https://codeforces.com/profile/qualdoom "Master qualdoom")

 **Tutorial**Let's note that it doesn't make sense for us to divide into more than k=2 subsegments. Let's prove it.

Let us somehow split the array a into m>2 subsegments : b1,b2,…,bm. Note that gcd(b1,b2,…,bm)≤gcd(b1+b2,b3,…,bm), since if b1 and b2 were multiples of gcd(b1,b2,…,bm), so b1+b2 is also a multiple of gcd(b1,b2,…,bm). This means that we can use b1+b2 instead of b1 and b2, and the answer will not worsen, thus it is always beneficial to use no more than k=2 subsegments.

How to find the answer? Let s be the sum of the array a. Let's say prefi=∑ij=1aj, then the answer is max1≤i<n(gcd(prefi,s−prefi).

 **Implementation (Python)**
```cpp
from math import gcd
t = int(input())
for test in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = 0
    for i in range(n):
        s += a[i]
    ans = 0
    pref = 0
    for i in range(n - 1):
        pref += a[i]
        ans = max(ans, gcd(pref, s - pref))
    print(ans)
```
 **Implementation (С++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long s = accumulate(a.begin(), a.end(), 0ll), cur = 0;
        long long ans = 1;
        for (int i = 0; i < n - 1; i++) {
            cur += a[i], s -= a[i];
            ans = max(ans, __gcd(s, cur));
        }
        cout << ans << "n";
    }
}
```
[1780D - Bit Guessing Game](../problems/D._Bit_Guessing_Game.md "Codeforces Round 846 (Div. 2)")

Idea: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Master AndreyPavlov")   
 Preparation: [qualdoom](https://codeforces.com/profile/qualdoom "Master qualdoom"), [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Master AndreyPavlov")   
 Editorialist: [qualdoom](https://codeforces.com/profile/qualdoom "Master qualdoom"), [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Master AndreyPavlov")

 **Tutorial**There are two similar solutions to this problem, we will tell you both.

 **Tutorial (AndreyPavlov)**Subtract 1. What can we say now about the number of units at the beginning of the binary notation of a number? There are exactly cnt−cntw+1, where cnt is the number of unit bits after subtracting the unit, and cntw is — before subtracting. Now we subtract them, for this we need to subtract the number 2cnt−cntw+1−1 and continue the algorithm. But such an algorithm makes at worst 60 requests. To save queries, note that we know the number of units after we remove the units from the beginning, therefore it is useless to make another request for this. Then at the same time, as we remove the units from the beginning, we will immediately subtract the unit. As a result, there will be absolutely no more than cnt operations, where cnt is the initial number of single bits in the record of the number n. This number does not exceed O(log2(n)), in turn, log2(n) does not exceed 30, which fits into the restrictions.

 **Tutorial (qualdoom)**Let ans be the desired number n, and was be the initial number of bits in the number n. Let's subtract the powers of two : 20,21,22,...2k, while was it will not become 0. We will support the Shift flag — whether there was a bit transfer to n when subtracting any power of two. Suppose we subtracted 2k at the kth step and the number of bits became equal to cntnew, and before the subtraction was cnt, then consider two cases.

1) cnt−cntnew=1, then bit k was included in n at the kth step, and if Shift=false, then we add to ans — 2k, since there was no bit transfer, which means bit k is also in the original number, and subtract from was — 1. If Shift=true, then we added this bit during previous operations, and it does not need to be taken into account.

2) cnt−cntnew≠1, then we know that the number of bits has not decreased, also that in the number n there was such a bit m that 2m>2k, and at the same time the bit m is in n. Moreover, m−k−1=cntnew−cnt. So m=k+1+cntnew−cnt. Let's add 2m to the answer, subtract from was — 1 and assign the Shift flag the value true, since there was a bit transfer.

Thus, we found the initial number n, which is equal to ans, and also made no more than O(log2(n)) queries, since k≤log2(n). 

Thus, the solution spends no more than 30 requests, which fits into the limitations of the task.

 **Implementation (Python)**
```cpp
t = int(input())
def ask (x):
	print('-', x)
	return int(input())
for i in range(t):
	cur = int(input())
	add = 0
	ans = 0
	while cur > 0:
		x = ask(add + 1)
		back = x - cur + 1
		add = 2 ** back - 1
		ans += 2 ** back
		cur = x - back
	print('!', ans)
```
 **Implementation (С++)**
```cpp
#include <iostream>
 
using namespace std;
 
int ask (int x) {
    cout << "- " << x << endl;
    if (x == -1)
        exit(0);
    cin >> x;
    return x;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int cnt;
        cin >> cnt;
        int n = 0;
        int was = 0;
        while (cnt > 0) {
            n += 1;
            int nw = ask(1 + was);
            int back = nw - cnt + 1;
            n += (1 << back) - 1;
            was = (1 << back) - 1;
            cnt = nw - back;
        }
        cout << "! " << n << endl;
    }
}
```
[1780E - Josuke and Complete Graph](../problems/E._Josuke_and_Complete_Graph.md "Codeforces Round 846 (Div. 2)")

Idea: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey")   
 Preparation: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey")   
 Editorialist: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey")

 **Tutorial**Let’s fix g and check that the g weight edge exists in G′. The first number, which is divided into g, starting with L — ⌈Lg⌉⋅g, and the second — (⌈Lg⌉+1)⋅g, note that their gcd is g, so the edge between these vertices weighs g. If the second number is greater R, the edge with weight g in the G′ doesn't exist, because on the segment from L to R at most one vertex, which is divided by g. That is, we should calculate the number of such g, which is (⌈Lg⌉+1)⋅g≤R.

For g≥L: (⌈Lg⌉+1)⋅g=2⋅g. Get the upper limit on the g≤⌊R2⌋. That is, all g on segment from L to ⌊R2⌋ occur in the G′ as weight some edge. Add them to the answer.

Look at g<L.

Note that ⌈Lg⌉ takes a O(√L) of different values. Let's fix some f=⌈Lg⌉. Note that f corresponds to a consecutive segment l≤g≤r. Let's brute this segments in ascending order f. Then, if there is a left border l of the segment, you can find r either by binary search or by writing the formula. The next left border is r+1. Then note, if f is fixed, then (f+1)⋅g≤R is equivalent to g≤⌊Rf+1⌋. That is, with a fixed segment from l to r, g occurs in the G′ as weight some edge if l≤g≤min(r,⌊Rf+1⌋). Then brute all these segments and sum up of all good g.

Overall time complexity is O(√L) or O(√L⋅log(L)).

 **Implementation (Python)**
```cpp
def solve():
    L, R = map(int, input().split())
    ans = max(0, R // 2 - L + 1)
    left = 1
    while left < L:
        C = (L + left - 1) // left
        right = (L + C - 2) // (C - 1) - 1
        ans += max(0, min(right, R // (C + 1)) - left + 1)
        left = right + 1
    print(ans)
t = int(input())
for test in range(t):
    solve()
```
 **Implementation (С++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int test_case = 0; test_case < t; test_case++){
        ll L, R;
        cin >> L >> R;
        ll ans = max(0ll, R / 2 - L + 1);
        for (ll left = 1, right; left < L; left = right + 1){
            ll C = (L + left - 1) / left;
            right = (L + C - 2) / (C - 1) - 1;
            ans += max(0ll, min(right, R / (C + 1)) - left + 1);
        }
        cout << ans << 'n';
    }
}
```
[1780F - Three Chairs](../problems/F._Three_Chairs.md "Codeforces Round 846 (Div. 2)")

Idea: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Master AndreyPavlov")   
 Preparation: [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Master AndreyPavlov")   
 Editorialist: [qualdoom](https://codeforces.com/profile/qualdoom "Master qualdoom")

 **Tutorial**Let's sort the array and process the triples i,j,k, assuming that i<j<k and ai<aj<ak. Now if gcd(ai,ak)=1, then the number of ways to take the index j is k−i−1.

We will consider the answer to the problem for each k from 1 to n, assuming that ak is the maximum number in the triple. Now let c be the number of numbers that are mutually prime with ak on the prefix from 1 to k−1, and sum is the sum of their indices. Then you need to add c⋅i−sum−c to the answer.

It remains to find out the number of numbers that are mutually prime with ak and the sum of their indices. This can be done using the inclusion and exclusion method. Let cnti be the number of numbers aj that are divisible by i, si be the sum of the indices j of numbers aj that are divisible by i. Let's look at the prime numbers p1,p2,...,pm included in the factorization of the number ak.

Then let c initially be equal to the number of numbers on the prefix, and sum to the sum of the indices on the prefix. Note that then we took into account the extra elements — numbers that are divisible by p1,p2,...,pm, since they will not be mutually simple with ak, we subtract them from c and sum. But having done this, we again took into account the extra elements that are multiples of the numbers of the form pi∗pj, where i≠j, add them back, etc. So we can iterate over the mask mask of the primes p1,p2,...,pm. And depending on the parity of the bits in the mask, we will subtract or add elements that are multiples of d, where d is the product of the primes included in mask. Having received c and sum, we can recalculate the answer for the position i.

To move from position i to position i+1, update the values of cnt and s by adding the element ai−1 by iterating over the mask of the simple element ai−1.

 **Implementation (С++)**
```cpp
#include "bits/stdc++.h"
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
#define sz(v) ((int)(v).size())
#define all(a) (a).begin(),  (a).end()
#define rall(a) a.rbegin(), a.rend()
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define time ((double)clock() / (double)CLOCKS_PER_SEC)
 
using pii = pair<int, int>;
using ll = long long;
using int64 = long long;
using ld = double;
 
const ll infll = (ll) 1e18 + 27;
const ll inf = (ll) 1e9;
 
#define dbg(x) cout << #x << " = " << (x) << endl
 
template<class T>
using pq = priority_queue<T, vector<T>, less<T>>;
template<class T>
using pqr = priority_queue<T, vector<T>, greater<T>>;
 
template<typename T, typename T2>
istream &operator>>(istream &in, pair<T, T2> &b) {
    in >> b.first >> b.second;
    return in;
}
 
template<typename T, typename T2>
ostream &operator<<(ostream &out, const pair<T, T2> &b) {
    out << "{" << b.first << ", " << b.second << "}";
    return out;
}
 
template<typename T>
istream &operator>>(istream &in, vector<T> &b) {
    for (auto &v : b) {
        in >> v;
    }
    return in;
}
 
template<typename T>
ostream &operator<<(ostream &out, vector<T> &b) {
    for (auto &v : b) {
        out << v << ' ';
    }
    return out;
}
 
template<typename T>
ostream &operator<<(ostream &out, deque<T> &b) {
    for (auto &v : b) {
        out << v << ' ';
    }
    return out;
}
 
template<typename T>
void print(T x, string end = "n") {
    cout << x << end;
}
 
 
template<typename T1, typename T2>
bool chkmin(T1 &x, const T2 &y) { return x > y && (x = y, true); }
 
template<typename T1, typename T2>
bool chkmax(T1 &x, const T2 &y) { return x < y && (x = y, true); }
 
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
const int N = 3e5 + 10;
 
ll s[N];
ll cnt[N];
 
ll d[N][20];
int ptr[N];
bool u[N];
 
ll Cnt = 0;
ll Sum = 0;
 
ll Ans = 0;
 
void Answer (int x, int pos) {
	ll C = Cnt;
	ll X = Sum;
	int K = (1ll << ptr[x]);
	for (int mask = 1; mask < K; mask++) {
		ll k = 1;
		for (int j = 0; j < ptr[x]; j++) {
			if ((mask >> j) & 1) {
				k *= d[x][j];
			}
		}
		int bits = __builtin_popcount(mask);
		int D = k;
		if (bits % 2 == 1) {
			C -= cnt[D];
			X -= s[D];
		} else {
			C += cnt[D];
			X += s[D];
		}
	}
	Ans += C * pos - X;
}
 
void add (int x, int pos) {
	Cnt += 1;
	Sum += pos + 1;
	auto v = d[x];
	int K = (1ll << ptr[x]);
	for (int mask = 1; mask < K; mask++) {
		ll k = 1;
		for (int j = 0; j < ptr[x]; j++) {
			if ((mask >> j) & 1) {
				k *= d[x][j];
			}
		}
		int D = k;
		s[D] += pos + 1;
		cnt[D] += 1;
	}
}
 
void solve() {
	for (int i = 2; i < N; i++) {
		if (!u[i]) {
			for (int j = i; j < N; j += i) {
				u[j] = true;
				d[j][ptr[j]] = i;
				ptr[j]++;
			}
		}
	}
	int n;
	cin >> n;
	vector<int> a(n);
	cin >> a;
	sort(all(a));
	for (int i = 0; i < n; i++) {
		Answer(a[i], i);
		if (i > 0) {
			add(a[i - 1], i - 1);
		}
	}
	cout << Ans << "n";
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
```
[1780G - Delicious Dessert](../problems/G._Delicious_Dessert.md "Codeforces Round 846 (Div. 2)")

Idea: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey")   
 Preparation: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey"), [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Master AndreyPavlov")   
 Editorialist: [IzhtskiyTimofey](https://codeforces.com/profile/IzhtskiyTimofey "Master IzhtskiyTimofey"), [AndreyPavlov](https://codeforces.com/profile/AndreyPavlov "Master AndreyPavlov")

 **Tutorial**This problem has several solutions using different suffix structures. We will tell two of them — using suffix array, and using suffix automaton.

 **Suffix array (t4m0fey)**Let's build suffix array suf and array lcp (largest common prefixes) on the string s. Fix some k>1 и consider about all substring s length k. Match 1 to positions i array lcp, such that lcpi≥k, and match 0 to other positions. One in position i means that the substrings length k starting at sufi and sufi+1 are equal. Consider any block of units length len, then for len+1 substrings length k number of occurrences in s — len+1, then in order for the substrings in this block to be delicious, it is necessary that len+1 divided by k.

Let's brute k from n to 2 и sustain all sizes blocks. Then, when shift to a new k should events — change 0 to 1, for all i, such that lcpi=k. To do this you can sustain DSU (Disjoint set union). Then for each block size we know the number of blocks with this size. Then it is enough to consider all blocks of length len, such as len+1 — divider k. It can be done explicitly, just brute k, 2⋅k, ..., as len+1. And this works in sum of harmonic series: ∑nk=2⌊nk⌋ =O(n⋅log(n)).

For k=1, obviously, any substring length 1 satisfies, so you can just add n to the answer.

Overall time complexity is O(n⋅log(n)).

 **Suffix automaton (AndreyPavlov)**The solution with the suffix automaton is as follows: let's build the suffix automaton itself, now we calculate for each vertex of the suffix automaton the dynamics dpv — this is the number of paths from the vertex v to the terminal vertices. This dynamics means the number of occurrences of the substring corresponding to this vertex in the entire string. Let's introduce the function f(v) — the length of the longest substring leading to the vertex v. We know that all substrings of length from lv to rv lead to the vertex v of the suffix automaton — each once. Where rv=f(v) and lv=f(suffv)+1, where suffv is the suffix link of v. Why is it so? All substrings of the form s[x:k],s[x+1:k],...,s[y:k] lead to the vertex v of the suffix automaton, and there is a suffix link suffv to which lead all substrings of the form s[x+1:k],s[y+2:k],...,s[t:k].

In order to solve the problem, let's go through the v vertex and look at the number of occurrences of any substring that leads to the v — dpv vertex, then fix c — the number of such lv≤x≤rv, that dpv is evenly divisible by x. Therefore, dpv⋅c must be added to the answer. All divisors can be stored in O(n⋅log(n)) and each time find the number of such x by binsearch.

Asymptotics O(n⋅log(n))

 **Implementation (t4m0fey)**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> suffix_array(string s){
    int n = s.size();
    vector<int> a(n), c(n), h(n);
    vector<pair<char, int>> t;
    for (int i = 0; i < n; i++) t.push_back({s[i], i});
    sort(t.begin(), t.end());
    int cur = -1;
    for (int i = 0; i < n; i++){
        if (i == 0 || t[i].first != t[i - 1].first){
            cur++;
            h[cur] = i;
        }
        a[i] = t[i].second;
        c[a[i]] = cur;
    }
    vector<int> a1(n), c1(n);
    for (int len = 1; len < n; len *= 2){
        for (int i = 0; i < n; i++){
            int j = (n + a[i] - len) % n;
            a1[h[c[j]]++] = j;
        }
        a = a1;
        cur = -1;
        for (int i = 0; i < n; i++){
            if (i == 0 || c[a[i]] != c[a[i - 1]] || c[(a[i] + len) % n] != c[(a[i - 1] + len) % n]){
                cur++;
                h[cur] = i;
            }
            c1[a[i]] = cur;
        }
        c = c1;
    }
    return a;
}
vector<int> build_lcp(string s, vector<int> suf){
    int n = s.size();
    vector<int> rsuf(n), lcp(n);
    for (int i = 0; i < n; i++) rsuf[suf[i]] = i;
    int cur = 0;
    for (int i = 0; i < n; i++){
        int j = rsuf[i];
        if (j != n - 1){
            while (s[suf[j] + cur] == s[suf[j + 1] + cur]) cur++;
            lcp[j] = cur;
        }
        if (cur > 0) cur--;
    }
    return lcp;
}
const int N = 1e6 + 1;
int r[N], l[N], us[N], cnt[N];
vector<int> pos[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += '$';
    vector<int> suf = suffix_array(s);
    vector<int> lcp = build_lcp(s, suf);
    for (int i = 0; i < lcp.size(); i++) {
        pos[lcp[i]].push_back(i);
    }
    ll ans = n;
    for (int k = n; k >= 2; k--) {
        for (int i : pos[k]) {
            // add i
            us[i] = true;
            cnt[1]++;
            l[i] = r[i] = i;
            if (i != 0 && us[i - 1]) {
                cnt[i - l[i - 1]]--;
                cnt[1]--;
                cnt[i - l[i - 1] + 1]++;
                l[i] = l[i - 1];
                r[l[i - 1]] = i;
            }
            if (i + 1 < lcp.size() && us[i + 1]) {
                cnt[r[i + 1] - i]--;
                cnt[i - l[i] + 1]--;
                cnt[r[i + 1] - l[i] + 1]++;
                l[r[i + 1]] = l[i];
                r[l[i]] = r[i + 1];
            }
        }
        for (int x = k; x <= n; x += k) {
            ans += 1ll * x * cnt[x - 1];
        }
    }
    cout << ans << "n";
}
```
 **Implementation (AndreyPavlov)**
```cpp
/* Includes */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

/* Using libraries */
using namespace std;

/* Defines */
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ld long double
#define pb push_back
#define vc vector
#define sz(a) (int)a.size()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define pii pair <int, int>
#define vec pt
#define all(a) a.begin(), a.end()

const int K = 26;
const int N = 1e6 + 1;

struct node {
    int next[K];
    int suf = -1, pr = -1, dp = 0, len = 0, ch = -1;
    node () {
        forn (i, K) next[i] = -1;
    }
};

int get (char c) {
    if (c >= 'a')
        return c - 'a';
    return c - 'A';
}

int lst = 0, sz = 1;
node t[N * 2];
int used[N * 2];

int add (int a, int x) {
    int b = sz++;
    t[b].pr = a;
    t[b].suf = 0;
    t[b].ch = x;
    for (; a != -1; a = t[a].suf) {
        if (t[a].next[x] == -1) {
            t[a].next[x] = b;
            t[b].len = max(t[b].len, t[a].len + 1);
            continue;
        }
        int c = t[a].next[x];
        if (t[c].pr == a) {
            t[b].suf = c;
            break;
        }
        int d = sz++;
        forn (i, K) t[d].next[i] = t[c].next[i];
        t[d].suf = t[c].suf;
        t[c].suf = t[b].suf = d;
        t[d].pr = a;
        t[d].ch = x;
        for (; a != -1 && t[a].next[x] == c; a = t[a].suf) {
            t[a].next[x] = d;
            t[d].len = max(t[d].len, t[a].len + 1);
        }
        break;
    }
    return b;
}

void add (char c) {
    lst = add(lst, get(c));
}

void dfs (int u) {
    used[u] = 1;
    for (int i = 0; i < K; ++i) {
        if (t[u].next[i] == -1) continue;
        int v = t[u].next[i];
        if (!used[v])
            dfs(v);
        t[u].dp += t[v].dp;
    }
}

vc <int> p[N], pr;
int dr[N];
vc <pii> d;
int l, r, cur = 0;

int cnt_log (int x, int y) {
    int z = 1, res = 0;
    while (y >= z) {
        z *= x;
        ++res;
    }
    return res - 1;
}

void rec (int i, int x) {
    if (i == sz(d)) {
        cur += l <= x;
        return;
    }
    rec(i + 1, x);
    for (int j = 1; j <= d[i].second; ++j) {
        x *= d[i].first;
        if (x > r)
            break;
        rec(i + 1, x);
    }
}

void solve () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c : s)
        add(c);
    for (int a = lst; a != -1; a = t[a].suf)
        t[a].dp = 1;
    dfs(0);
    for (int i = 2; i <= n; ++i) {
        if (dr[i] == 0) {
            dr[i] = i;
            pr.pb(i);
        }
        for (int j = 0; j < sz(pr) && pr[j] <= dr[i] && i * pr[j] <= n; ++j)
            dr[i * pr[j]] = pr[j];
    }
    long long ans = 0;
    forn (i, sz) {
        if (t[i].len == 0) continue;
        l = t[t[i].suf].len + 1;
        r = t[i].len;
        int x = t[i].dp;
        d.clear();
        while (x > 1) {
            int y = dr[x];
            if (d.empty() || d.back().first != y)
                d.pb({y, 1});
            else
                d.back().second++;
            x /= y;
        }
        rec(0, 1);
        ans += t[i].dp * cur;
        cur = 0;
    }
    cout << ans << 'n';
}

/* Starting and precalcing */
signed main() {
    /* freopen("input.txt","r",stdin);freopen("output.txt","w",stdout); */
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
```
