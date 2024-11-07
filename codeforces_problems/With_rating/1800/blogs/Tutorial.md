# Tutorial

[1800A - Is It a Cat?](../problems/A._Is_It_a_Cat_.md "Codeforces Round 855 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1800A - Is It a Cat?](../problems/A._Is_It_a_Cat_.md "Codeforces Round 855 (Div. 3)")

To solve the problem, you may convert the string to lower case, strip all duplicated characters from it and compare the result to "meow" string.

To exclude duplicate characters, you can, for example, use the unique function in C++.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), [] (char c) {
        return tolower(c);
    });
    s.erase(unique(s.begin(), s.end()), s.end());
    cout << (s == "meow" ? "YES" : "NO") << "n";
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
```
[1800B - Count the Number of Pairs](../problems/B._Count_the_Number_of_Pairs.md "Codeforces Round 855 (Div. 3)")

Idea: [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1800B - Count the Number of Pairs](../problems/B._Count_the_Number_of_Pairs.md "Codeforces Round 855 (Div. 3)")

Count two arrays big and small, such that big[i] contains the number of occurrences of ith letter of the alphabet in the string in upper case, while small[i] — in lower case.

Let's add all existing pairs to the answer, so let's add min(small[i],big[i]) to it for each letter. Subtract this minimum from small[i] and big[i] to get the number of unpaired identical letters.

Next, we will act greedily: if there is some set of at least two identical letters in the same case, we can apply the operation to half of them and get new pairs. Therefore, for each letter we will add min(k,max(small[i],big[i]))2 to the answer and decrease k by that amount.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 26;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int>big(N, 0), small(N, 0);
    for(auto &i : s){
        if('A' <= i && 'Z' >= i) big[i - 'A']++;
        else small[i - 'a']++;
    }
    int answer = 0;
    for(int i = 0; i < N; i++){
        int pairs = min(small[i], big[i]);
        answer += pairs;
        small[i] -=pairs; big[i] -= pairs;
        int add = min(k, max(small[i], big[i]) / 2);
        k -= add; answer += add;
    }
    cout << answer << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
```
[1800C1 - Powering the Hero (easy version)](../problems/C1._Powering_the_Hero_(easy_version).md "Codeforces Round 855 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1800C1 - Powering the Hero (easy version)](../problems/C1._Powering_the_Hero_(easy_version).md "Codeforces Round 855 (Div. 3)")

To solve it, it should be noted that despite the way the deck with bonuses works, the order in which they will be applied is not important. Then, when we meet the hero card, we just need to add to the answer the maximum of the available bonuses.

Constraints allow you to sort the current array with bonus values each time and remove the maximum element.

 **Solution**
```cpp
def solve():
    n = int(input())
    s = [int(x) for x in input().split()]
    ans = 0
    buffs = [0] * n
    for e in s:
        if e > 0:
            buffs += [e]
            j = len(buffs) - 1
            while buffs[j] < buffs[j - 1]:
                buffs[j], buffs[j - 1] = buffs[j - 1], buffs[j]
                j -= 1
        else:
            ans += buffs.pop()
    print(ans)


t = int(input())
for _ in range(t):
    solve()
```
[1800C2 - Powering the Hero (hard version)](../problems/C2._Powering_the_Hero_(hard_version).md "Codeforces Round 855 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1800C2 - Powering the Hero (hard version)](../problems/C2._Powering_the_Hero_(hard_version).md "Codeforces Round 855 (Div. 3)")

To solve it, it should be noted that despite the way the deck with bonuses works, the order in which they will be applied is not important. Then, when we meet the hero card, we just need to add to the answer the maximum of the available bonuses.

Constraints make you use structures such as a priority queue to quickly find and extract the maximum.

 **Solution**
```cpp
from queue import PriorityQueue


def solve():
    n = int(input())
    s = [int(x) for x in input().split()]
    ans = 0
    buffs = PriorityQueue()
    for e in s:
        if e > 0:
            buffs.put(-e)
        elif not buffs.empty():
            ans -= buffs.get()
    print(ans)


t = int(input())
for _ in range(t):
    solve()
```
[1800D - Remove Two Letters](../problems/D._Remove_Two_Letters.md "Codeforces Round 855 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1800D - Remove Two Letters](../problems/D._Remove_Two_Letters.md "Codeforces Round 855 (Div. 3)")

Consider deleting characters with numbers i and i+1, as well as characters with numbers i+1 and i+2. In the first case, the symbol with the number i+2 remains, in the second - i. Symbols with numbers less than i or more than i+2 remain in both cases. Therefore, the same strings will be obtained if the characters with the numbers i and i+2 match. Therefore, we just need to count the number of i:1≤i≤n−2:si=si+2, and subtract this value from n−1.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = n - 1;
    for (int i = 1; i + 1 < n; ++i) {
        if (s[i - 1] == s[i + 1]) {
            res--;
        }
    }
    cout << res << 'n';
}

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}
```
[1800E1 - Unforgivable Curse (easy version)](../problems/E1._Unforgivable_Curse_(easy_version).md "Codeforces Round 855 (Div. 3)")

Idea: [Aris](https://codeforces.com/profile/Aris "Candidate Master Aris"), [talant](https://codeforces.com/profile/talant "International Master talant")

 **Tutorial**
### [1800E1 - Unforgivable Curse (easy version)](../problems/E1._Unforgivable_Curse_(easy_version).md "Codeforces Round 855 (Div. 3)")

In these constraints , the problem could be solved as follows:

Note that for strings of length 6 and more, it is enough to check that the strings s and t match character by character, that is, up to permutation, since each character can be moved to the desired half, and then moved to the desired side by length 1 by applying two operations on the length is 3 and 4.

For example, there was a string "abudance" and we want to shift the c character to the left, then we can first get the string "acudab" and then the string "aaudcb". Well, we can restore the used symbols by putting them in their place "budka". That is, we were able to simply swap two adjacent characters.

Thus, with such a clipping, it was possible to solve the problem by brute force for n≤5. To iterate, it was possible to store map of strings, which we can get and iterate through all the strings using bfs.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back


void slow_solve(int n, int k, string s, string t) {
    set<string> was;

    queue<string> q;
    q.push(s);
    was.insert(s);

    auto add = [&](string& s, int i, int j) {
        if (i >= 0 && i < j && j < n) {
            swap(s[i], s[j]);
            if (!was.count(s)) {
                was.insert(s);
                q.push(s);
            }
            swap(s[i], s[j]);
        }

    };

    while (!q.empty()) {
        s = q.front(); q.pop();
        for (int i = 0; i < n; ++i) {
            add(s, i, i+k);
            add(s, i, i+k+1);
            add(s, i-k, i);
            add(s, i-k-1, i);
        }
    }
    cout << (was.count(t) ? "Yes" : "No") << 'n';
}

void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    string t; cin >> t;

    if (n <= 5) {
        slow_solve(n, k, s, t);
        return;
    }
    map<char, int> cnt;
    for (char c : s) {
        cnt[c]++;
    }

    for (char c : t) {
        cnt[c]--;
    }

    bool ok = true;
    for (auto [c, x] : cnt) {
        ok &= x == 0;
    }
    cout << (ok ? "Yes" : "No") << 'n';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
```
[1800E2 - Unforgivable Curse (hard version)](../problems/E2._Unforgivable_Curse_(hard_version).md "Codeforces Round 855 (Div. 3)")

Idea: [Aris](https://codeforces.com/profile/Aris "Candidate Master Aris"), [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1800E2 - Unforgivable Curse (hard version)](../problems/E2._Unforgivable_Curse_(hard_version).md "Codeforces Round 855 (Div. 3)")

The solution of the problem E1 hints to us that with the help of such operations, it is possible to move the symbol in the right direction by 1 using two operations. Then we can show that among the symbols that we can swap with at least one other symbol, we can get any permutation.

For example, you can apply such a greedy solution: we will build an answer from the boundaries of the string t to the middle. Since we can move the symbol by a distance of 1, we can move it to the border and thus we can build any string t.

Thus, it is enough to check that the sets of characters that can be swapped with some other match. And for the rest of the characters, check that they just match.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string t; cin >> t;
    vector<int> cnt(26, 0);

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (i >= k || i+k < n){
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        } else {
            ok &= s[i] == t[i];
        }
    }

    cout << (ok && count(all(cnt), 0) == 26 ? "YES" : "NO") << 'n';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
```
[1800F - Dasha and Nightmares](../problems/F._Dasha_and_Nightmares.md "Codeforces Round 855 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1800F - Dasha and Nightmares](../problems/F._Dasha_and_Nightmares.md "Codeforces Round 855 (Div. 3)")

Observation 1: the product of odd numbers is odd, so the condition for the length of nightmare is automatically completed.

Denote by f(x) the number of ones in binary representation of x. Let's enumerate the letters of the Latin alphabet from 0 to 25.

Observation 2: for each word, it is enough to know the set of letters included in it and the evenness of their numbers. There are only 26 letters in the alphabet, so it is convenient to store the word characteristic si as a pair of masks ⟨ai,bi⟩. The bit with the number j in ai will be responsible for the availability of the letter j in si. The bit with the number j in bi will be responsible for the evenness of the number of letters j in si.

Observation 3: strings sisj creates nightmare if and only if f(ai|aj)=f(bi⊕bj)=25.

Let's fix the number k — the index of the letter that will not be in nightmares. Let's throw out all the words with the letter k, now we can look at the words in turn and look for a pair of them among those already considered. It is easy to see that the condition f(ai|aj)=25 follows from the condition f(bi⊕bj)=25 if one letter is banned.

To count the number of pairs that include our word, we need to count the number of words with the characteristic bj=bi⊕(226−1). We can do this by bin-searching through a sorted array of b or using standard data structures. We got the solution for O(∑|s|+26⋅n⋅logn).

 **Solution**
```cpp
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,avx,fma,bmi2")

#include <bits/stdc++.h>
#include <immintrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl 'n'
//#define int long long
#define all(arr) arr.begin(), arr.end()
#define multitest() int _gorilla_silverback; cin >> _gorilla_silverback; while (_gorilla_silverback --> 0)
#define pikachu push_back
#define ls(id) (id << 1 | 1)
#define rs(id) ((id << 1) + 2)
#define sqr(x) ((x) * (x))
#define dlg(x) (31 - __builtin_clz(x))
#define ulg(x) (32 - __builtin_clz(x))

typedef pair<int, int> ipair;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> treap;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 200200;
const int L = 26;

int n;
string srr[MAXN];
int arr[MAXN], brr[MAXN], crr[MAXN];

void build() {
	for (int i = 0; i < n; ++i) {
		for (char c: srr[i]) {
			arr[i] ^= (1 << (c - 'a'));
			brr[i] |= (1 << (c - 'a'));
		}
	}
}

long long calc(int c) {
	int k = 0;
	for (int i = 0; i < n; ++i)
		if (brr[i] >> c & 1 ^ 1) crr[k++] = arr[i];
	sort(crr, crr + k);
	int mask = -1 & ((1 << L) - 1) ^ (1 << c);
	long long ans = 0;
	for (int i = 0; i < k; ++i) {
		auto itl = lower_bound(crr, crr + k, crr[i] ^ mask);
		auto itr = upper_bound(crr, crr + k, crr[i] ^ mask);
		ans += itr - itl;
	}
	return ans >> 1LL;
}

long long solve() {
	long long ans = 0;
	for (int c = 0; c < L; ++c)
		ans += calc(c);
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> srr[i];
	build();
	cout << solve() << endl;
}
```
[1800G - Symmetree](../problems/G._Symmetree.md "Codeforces Round 855 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1800G - Symmetree](../problems/G._Symmetree.md "Codeforces Round 855 (Div. 3)")

Note that if one subtree is a mirror image of another, then they are isomorphic (that is, equal without taking into account the vertex numbers). To check the subtrees for isomorphism, we use hashing of root trees.

Now we just have to learn how to check trees for symmetry. To do this, let's calculate how many children of each type our vertex has (let's denote the hash of its subtree by the vertex type). In order for the vertex subtree to be symmetric, each child must have a pair of the same type, except perhaps one, which must also be symmetric. We can calculate the symmetry of the subtrees while counting their hash to simplify this task.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(time(nullptr));

const int inf = 2e18;
const ll M = 1e9;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;

int last;
map<vector<int>, int> eq;
map<int, bool> symmetrical;

int dfs(int v, int p, vector<vector<int>> &sl){
    vector<int> children;
    for(int u: sl[v]){
        if(u == p) continue;
        children.emplace_back(dfs(u, v, sl));
    }
    sort(all(children));
    if(!eq.count(children)){
        map<int, int> cnt;
        for(int e: children){
            cnt[e]++;
        }
        int odd = 0, bad = 0;
        for(auto e: cnt){
            if(e.y & 1){
                odd++;
                bad += !symmetrical[e.x];
            }
        }
        eq[children] = last;
        symmetrical[last] = odd < 2 && bad == 0;
        last++;
    }
    return eq[children];
}

void solve(int tc){
    int n;
    cin >> n;
    eq.clear();
    symmetrical.clear();
    eq[vector<int>(0)] = 0;
    symmetrical[0] = true;
    last = 1;
    vector<vector<int>> sl(n);
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        sl[--u].emplace_back(--v);
        sl[v].emplace_back(u);
    }
    cout << (symmetrical[dfs(0, 0, sl)]? "YES" : "NO");
}

bool multi = true;

signed main() {
    int t = 1;
    if (multi)cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        cout << "n";
    }
    return 0;
}
```
