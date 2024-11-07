# Tutorial

[1701A - Grass Field](../problems/A._Grass_Field.md "Educational Codeforces Round 131 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1701A - Grass Field](../problems/A._Grass_Field.md "Educational Codeforces Round 131 (Rated for Div. 2)")

If there is no grass on the field, the answer is 0. If the whole field is filled with grass, the answer is 2, because there always will be one cell that we can't clear with one move. Otherwise, the answer is 1. This is because if the cell (i,j) is empty, we can just choose other row than i and other column than j and clear three other cells in one move.

 **Solution (vovuh)**
```cpp
for _ in range(int(input())):
    a = [list(map(int, input().split())) for i in range(2)]
    cnt = sum([sum(a[i]) for i in range(2)])
    if cnt == 0:
        print(0)
    elif cnt == 4:
        print(2)
    else:
        print(1)
```
[1701B - Permutation](../problems/B._Permutation.md "Educational Codeforces Round 131 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1701B - Permutation](../problems/B._Permutation.md "Educational Codeforces Round 131 (Rated for Div. 2)")

Let's notice that for a fixed value of d, the answer (the cost of permutation) does not exceed nd, because only numbers from 1 to nd can have a pair. It turns out that it is always possible to construct a permutation with the cost of exactly nd. It is enough to consider the number "chains" of the form: x,x⋅d,x⋅d2,…,x⋅dk, where x≠0(modd). It is not difficult to understand that each number is included in exactly one such chain. Therefore, if we append the chains one after another, then in such a permutation the answer will be equal to n−the_number_of_chains (because all numbers will have a pair except the last element in the chain). The number of chains is equal to n−nd, which means the cost of the permutation is equal to n−(n−nd)=nd. By choosing d=2 the permutation will have the maximum possible cost.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << 2 << 'n';
    for (int i = 1; i <= n; ++i) if (i % 2 != 0)
      for (int j = i; j <= n; j *= 2)
        cout << j << ' ';
    cout << 'n';
  }
} 
```
[1701C - Schedule Management](../problems/C._Schedule_Management.md "Educational Codeforces Round 131 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1701C - Schedule Management](../problems/C._Schedule_Management.md "Educational Codeforces Round 131 (Rated for Div. 2)")

The statement should instantly scream binary search at you. Clearly, if you can assign the workers in such a way that the tasks are completed by time t, you can complete them all by t+1 or more as well.

How to check if the tasks can be completed by some time t? What that means is that all workers have t hours to work on some tasks. If all tasks took 2 hours to complete, then each of them could complete ⌊t2⌋ of them. Thus, together they would be able to complete ⌊t2⌋⋅n tasks.

How to incorporate the 1-hour tasks into that? Well, we can redistribute the tasks in such a way that each worker first completes the tasks they are proficient in, then some other tasks if they have more time.

So the general idea is the following. Let each worker i complete min(t,cnti) 1-hour tasks, where cnti is the number of tasks the i-th worker is proficient in. Then remember how many 2-hour tasks they can complete, which is ⌊t−min(t,cnti)2⌋. Finally, remember how many tasks that they are proficient in they didn't have time to complete, which is cnti−min(t,cnti). If the sum of the number of incomplete tasks doesn't exceed the sum of the number of tasks they have time to complete, then everything can be completed in time t.

Worst case, it can take up to 2m hours to complete everything — if you assign all tasks to a single worker, and they are not proficient in any of them.

Overall complexity: O(nlogm) per testcase.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> a(m);
		forn(i, m){
			scanf("%d", &a[i]);
			--a[i];
		}
		vector<int> cnt(n);
		forn(i, m) ++cnt[a[i]];
		auto check = [&](int t){
			long long fr = 0, need = 0;
			forn(i, n){
				if (t >= cnt[i])
					fr += (t - cnt[i]) / 2;
				else
					need += cnt[i] - t;
			}
			return need <= fr;
		};
		int l = 0, r = 2 * m;
		int res = -1;
		while (l <= r){
			int m = (l + r) / 2;
			if (check(m)){
				res = m;
				r = m - 1;
			}
			else{
				l = m + 1;
			}
		}
		printf("%dn", res);
	}
	return 0;
}
```
[1701D - Permutation Restoration](../problems/D._Permutation_Restoration.md "Educational Codeforces Round 131 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1701D - Permutation Restoration](../problems/D._Permutation_Restoration.md "Educational Codeforces Round 131 (Rated for Div. 2)")

We have bi=⌊iai⌋ for each i, we can rewrite this as follows: ai⋅bi≤i<ai⋅(bi+1), or ibi+1<ai≤ibi. From here we can see that for each i there is a segment of values that can be assigned to ai. So we have to match each number from 1 to n with one of these segments.

To solve this problem, we can iterate from 1 to n. Let the current number be x, then it can be paired with a segment i without a pair such that ibi+1<x≤ibi and the right bound is minimum among all such segments (because it will be the first to end among these segments). To do this, it is enough to maintain a set with open segments that have not yet been assigned a pair and choose from it a segment with the minimum right bound. Before running this method, you can sort the segments by their left border so they can be easily added to this set when we go from x to x+1 (we will need to insert all segments that begin with x+1, that's why it's convenient to have them sorted by their left border beforehand).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x : b) cin >> x;
    vector<pair<int, int>> ev(n);
    for (int i = 0; i < n; ++i)
      ev[i] = {(i + 1) / (b[i] + 1) + 1, i};
    sort(ev.begin(), ev.end());
    set<pair<int, int>> s;
    int j = 0;
    for (int i = 1; i <= n; ++i) {
      while (j < n && ev[j].first == i) {
        int id = ev[j++].second;
        s.insert({b[id] ? (id + 1) / b[id] : n, id});
      }
      a[s.begin()->second] = i;
      s.erase(s.begin());
    }
    for (int& x : a) cout << x << ' ';
    cout << 'n';
  }
} 
```
[1701E - Text Editor](../problems/E._Text_Editor.md "Educational Codeforces Round 131 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1701E - Text Editor](../problems/E._Text_Editor.md "Educational Codeforces Round 131 (Rated for Div. 2)")

Of course, there is no need to press "home" more than once (and no need to press "end" at all), because suppose we did something on suffix, then pressed "home", did something on prefix and then pressed "end" and continue doing something on suffix. Then we can merge these two sequences of moves on suffix and press "home" after we did anything we wanted on suffix, and the answer will not get worse.

Now, let's iterate over the position pos at which we will press "home" (in range from 0 to n). In other words, we iterate over the position till which we press only "left" and "backspace" to fix the suffix. So now we have the string s[pos;n) and we want to get some suffix of t from this string, but we actually don't know which suffix of t we want. So let's iterate over the length of this suffix suf in a range from 0 to m. Now we have the string s[pos;n) and the string t[m−suf;m) and we have to check if we can obtain this suffix of t from this suffix of s. This part can be precalculated in O(n) greedily (we just can store for each suffix of t the rightmost position in s in which this suffix is obtainable). If we can obtain the current suffix, then we obviously can say the number of moves to do that — it is n−pos and actually do not depend on the suffix length (because if we meet the character we need, we just press "left" and move to the next character, otherwise we press "backspace" and move to the next character deleting the one we don't need).

After that, we press "home" and now we have to check if we can obtain t[0;m−suf) from s[0;pos). This part can also be precalculated greedily in O(n) like the part with rightmost positions for suffixes. But the minimum number of moves required to obtain the prefix is tricky. Actually, if we consider these prefixes from right to left, we want to match as many characters from the beginning as possible. In other words, if we reverse s[0;pos) and t[0;m−suf), we want to find their longest common prefix, and this will be the number of characters we don't want to touch at all (and if it is the longest common prefix, it means that the next character is bad, and we want to remove it anyway, so the length of LCP of these two reversed prefixes is the only thing affecting the number of moves on the prefix). This part can be precalculated in O(n2) with simple dynamic programming (using O(n2) memory) or with z-function in O(n2) time and O(n) memory — we just need to build a z-function on a string s[0;pos)−1+#+t−1, where + is the concatenation of strings and −1 is the reverse operation. The required value of the z-function for the fixed values pos and suf will be in the position pos+1+m−suf. And the answer for the prefix will be pos−suf (this is the number of extra characters on the prefix we have to delete) plus pos−zpos+1+m−suf plus 1 because we have to press "home". But there is a corner case. If the prefix is empty, then we don't need to do all of this and the answer for prefix will be 0.

Complexity: O(n2) time and O(n) memory.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> zf(const string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        string s, t;
        cin >> n >> m >> s >> t;
        
        int ans = 1e9;
        
        bool bad = false;
        vector<int> lpos(m), rpos(m);
        for (int i = 0; i < m; ++i) {
            if (i > 0) {
                lpos[i] = lpos[i - 1] + 1;
            } else {
                lpos[i] = 0;
            }
            while (lpos[i] < n && s[lpos[i]] != t[i]) {
                ++lpos[i];
            }
            if (lpos[i] >= n) {
                bad = true;
                break;
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            if (i + 1 < m) {
                rpos[i] = rpos[i + 1] - 1;
            } else {
                rpos[i] = n - 1;
            }
            while (rpos[i] >= 0 && s[rpos[i]] != t[i]) {
                --rpos[i];
            }
            if (rpos[i] < 0) {
                bad = true;
                break;
            }
        }
        if (bad) {
            cout << -1 << endl;
            continue;
        }
        
        for (int pos = 0; pos <= n; ++pos) {
            string tmp = s.substr(0, pos);
            reverse(tmp.begin(), tmp.end());
            tmp += "#" + t;
            reverse(tmp.begin() + pos + 1, tmp.end());
            vector<int> z = zf(tmp);
            for (int suf = 0; suf <= m; ++suf) {
                if (pos - suf < 0) {
                    continue;
                }
                if (suf < m && rpos[suf] < pos) {
                    continue;
                }
                if (suf - 1 >= 0 && lpos[suf - 1] > pos) {
                    continue;
                }
                int rg = 0;
                if (suf != 0) {
                    int sum = (pos - z[pos + 1 + m - suf]) + (pos - suf);
                    rg = (sum != 0) + sum;
                } else {
                    rg = pos;
                }
                ans = min(ans, (n - pos) + rg);
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
```
[1701F - Points](../problems/F._Points.md "Educational Codeforces Round 131 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1701F - Points](../problems/F._Points.md "Educational Codeforces Round 131 (Rated for Div. 2)")

We are going to calculate the answer as follows: for every point i, let f(i) be the number of points j such that 1≤j−i≤d (i. e. the number of points that are to the right of i and have distance at most d from it). Then, the number of beautiful triples where i is the leftmost point is f(i)(f(i)−1)2. We can sum these values over all points to get the answer; so, the solution should somehow maintain and update the sum of these values efficiently.

Let's see what happens when we add a new point or remove an existing point. For all points to the left of it with distance no more than d, the value of f(i) increases or decreases by 1. So, we need some sort of data structure that allows adding/subtracting 1 on segment and maintains the sum of f(i)(f(i)−1)2. This looks like a lazy segment tree, but updating the sum of f(i)(f(i)−1)2 can be tricky.

One way to do this is to notice that f(i)(f(i)−1)2=f(i)22−f(i)2. So maybe we can maintain the sum of f(i)2 and the sum of f(i) on the segment? It turns out we can. 

The model solution does this as follows: the leaf of the segment tree corresponding to the position i stores a vector with three values: (f(i)0,f(i)1,f(i)2). The inner nodes store the sums of these vectors in the subtree. We can find a matrix which, when multiplied by (x0,x1,x2), gets the vector ((x+1)0,(x+1)1,(x+1)2), and the inverse matrix to it. Then adding 1 to f(i) on segment means multiplying all vectors on segment by that matrix, and subtracting 1 means multiplying by the inverse matrix; and since matrix multiplication is both associative and distributive, the segment tree can handle these queries.

Side note: this method with matrices is asymptotically fine, but the constant factor in it is fairly large. You can speed this up by getting rid of the matrices and instead storing the sum of f(i) and the sum of f(i)2 in each node, and coding the formulas that allow you to add/subtract 1 on segment by hand, without any matrix operations. This can make a noticeable improvement in terms of actual time consumption, although it wasn't needed in this problem since the time limit was pretty generous.

Okay, there's only one small issue left: right now our structure can store the sum of f(i) and f(i)2 over all possible points (we build it on segment [0,200000], for example), but we only need the sum over existing points. One way to handle it is to use a flag for each leaf of the segment tree, and pull the value up from the leaf only if this flag is true. We will need a function that changes the value of this flag for a single leaf, but it's not very different from a function that changes one value in a lazy segment tree.

Time complexity of the solution is O(A+qlogA), where A is the maximum coordinate of the point, although the constant factor of the described approach is fairly large since it involves 3×3 matrix multiplications. You can improve the constant factor by getting rid of the matrices, as mentioned earlier.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 200043;
const int M = 200001;

typedef array<long long, 3> vec;
typedef array<vec, 3> mat;

vec operator+(const vec& a, const vec& b)
{
    vec c;
    for(int i = 0; i < 3; i++) c[i] = a[i] + b[i];
    return c;
}

vec operator-(const vec& a, const vec& b)
{
    vec c;
    for(int i = 0; i < 3; i++) c[i] = a[i] - b[i];
    return c;
}

vec operator*(const mat& a, const vec& b)
{
    vec c;
    for(int i = 0; i < 3; i++) c[i] = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            c[i] += a[i][j] * b[j];
    return c;
}

mat operator*(const mat& a, const mat& b)
{
    mat c;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            c[i][j] = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                c[i][k] += a[i][j] * b[j][k];
    return c;
}

mat F = {vec({1, 0, 0}), vec({1, 1, 0}), vec({1, 2, 1})};
mat B = {vec({1, 0, 0}), vec({-1, 1, 0}), vec({1, -2, 1})};
mat E = {vec({1, 0, 0}), vec({0, 1, 0}), vec({0, 0, 1})};

vec S = {1, 0, 0};
vec Z = {0, 0, 0};

vec t[4 * N];
mat f[4 * N];
bool active[4 * N];
bool has[N];
int d, q;

vec getVal(int v)
{
    if(!active[v]) return Z;
    return f[v] * t[v];
}

void recalc(int v)
{
    t[v] = getVal(v * 2 + 1) + getVal(v * 2 + 2);    
}

void build(int v, int l, int r)
{
    if(l == r - 1)
    {
        f[v] = E;
        t[v] = S;
        active[v] = false;                 
    }
    else
    {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        f[v] = E;
        recalc(v);
        active[v] = true;               
    }
}

void push(int v)
{
    if(f[v] == E) return;
    t[v] = f[v] * t[v];
    f[v * 2 + 1] = f[v] * f[v * 2 + 1];
    f[v * 2 + 2] = f[v] * f[v * 2 + 2];
    f[v] = E;
}

void updSegment(int v, int l, int r, int L, int R, bool adv)
{
    if(L >= R) return;
    if(l == L && r == R)
    {
        if(adv) f[v] = F * f[v];
        else f[v] = B * f[v];
        return;
    }
    push(v);
    int m = (l + r) / 2;
    updSegment(v * 2 + 1, l, m, L, min(m, R), adv);
    updSegment(v * 2 + 2, m, r, max(m, L), R, adv);
    recalc(v);
}

void setState(int v, int l, int r, int pos, bool val)
{
    if(l == r - 1)
    {   
        active[v] = val;
        return;
    }
    push(v);
    int m = (l + r) / 2;
    if(pos < m)
        setState(v * 2 + 1, l, m, pos, val);
    else
        setState(v * 2 + 2, m, r, pos, val);
    recalc(v);
}

void addPoint(int x)
{
    int lf = max(0, x - d);
    int rg = x;
    if(lf < rg)
        updSegment(0, 0, M, lf, rg, true);
    setState(0, 0, M, x, true);        
}

void delPoint(int x)
{
    int lf = max(0, x - d);
    int rg = x;
    if(lf < rg)
        updSegment(0, 0, M, lf, rg, false);
    setState(0, 0, M, x, false);        
}

void query(int x)
{
    if(has[x])
    {
        has[x] = false;
        delPoint(x);
    }
    else
    {
        has[x] = true;
        addPoint(x);
    }
    vec res = getVal(0);
    printf("%lldn", (res[2] - res[1]) / 2);
}

int main()
{
    scanf("%d %d", &q, &d);
    build(0, 0, M);
    for(int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        query(x);
    }
}
```
