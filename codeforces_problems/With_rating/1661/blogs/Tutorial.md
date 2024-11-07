# Tutorial

[1661A - Array Balancing](../problems/A._Array_Balancing.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1661A - Array Balancing](../problems/A._Array_Balancing.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Let's look at our arrays $a$ and $b$. Note that for any position $p$ such that $|a_{p-1} - a_p| + |b_{p-1} - b_p| > |a_{p-1} - b_p| + |b_{p-1} - a_p|$ we can always "fix it" by swapping all positions $i$ from $p$ to $n$. In that case, contribution from all $i < p$ won't change, contribution of pair $(p - 1, p)$ will decrease and contribution from all $i > p$ won't change again, since we swapped all of them.

It means that we already can use the following algorithm: while exists such $p$ that $|a_{p-1} - a_p| + |b_{p-1} - b_p| > |a_{p-1} - b_p| + |b_{p-1} - a_p|$ just swap all $i$ from $p$ to $n$. This solution works for $O(n^2)$ per test, that should be enough.

But we can optimize our approach by realizing that we can (instead of searching $p$ each time) just go from $2$ to $n$ and fix pairs one by one: if $|a_1 - a_2| + |b_1 - b_2| > |a_1 - b_2| + |b_1 - a_2|$ then swap $a_2$ with $b_2$; next, if $|a_2 - a_3| + |b_2 - b_3| > |a_2 - b_3| + |b_2 - a_3|$ then swap $a_3$ with $b_3$ and so on. In such way, solution works in $O(n)$.

 **Solution (adedalic)**
```cpp
import kotlin.math.abs

fun sum(a1: Int, a2: Int, b1: Int, b2: Int) = abs(a1 - a2) + abs(b1 - b2)

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val b = readLine()!!.split(' ').map { it.toInt() }.toIntArray()

        var sum = 0L
        for (i in 1 until n) {
            if (sum(a[i - 1], a[i], b[i - 1], b[i]) > sum(a[i - 1], b[i], b[i - 1], a[i]))
                a[i] = b[i].also { b[i] = a[i] }
            sum += sum(a[i - 1], a[i], b[i - 1], b[i])
        }
        println(sum)
    }
}
```
[1661B - Getting Zero](../problems/B._Getting_Zero.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1661B - Getting Zero](../problems/B._Getting_Zero.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Note that $32768 = 2^{15}$, so you can make any value equal to $0$ by multiplying it by two $15$ times, since $(v \cdot 2^{15}) \bmod 2^{15} = 0$. So, the answer for each value $a_i$ is at most $15$.

Now, let's note that there is always an optimal answer that consists of: at first, add one $cntAdd$ times, then multiply by two $cntMul$ times — and $cntAdd + cntMul$ is the minimum answer. In other words, let's just iterate over all $cntAdd \le 15$ and $cntMul \le 15$ and check that $(v + cntAdd) \cdot 2^{cntMul} \bmod 32768 = 0$. The answer is minimum $cntAdd + cntMul$ among them.

To prove that it's optimal to add at first and only then to multiply, note that it's not optimal to add more than once after muptiplying ($v \rightarrow 2v \rightarrow 2v + 2$ can be replaced by $v \rightarrow v + 1 \rightarrow 2(v + 1)$). So there is at most one $+1$ between two $\cdot 2$, but it's not optimal to make even one $+1$ since we need to make $v$ divisible by $2^{15}$ and $+1$ break divisibility.

There are many other approaches to this task except this one: for example, since $a_i < 32768$ you can write bfs to find the shortest paths from $0$ to all $a_i$.

 **Solution (adedalic)**
```cpp
fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()

    for (v in a) {
        var ans = 20
        for (cntAdd in 0..15) {
            for (cntMul in 0..15) {
                if (((v + cntAdd) shl cntMul) % 32768 == 0)
                    ans = minOf(ans, cntAdd + cntMul)
            }
        }
        print("$ans ")
    }
}
```
[1661C - Water the Trees](../problems/C._Water_the_Trees.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1661C - Water the Trees](../problems/C._Water_the_Trees.md "Educational Codeforces Round 126 (Rated for Div. 2)")

The first observation we need to solve this problem: the required height is either $max$ or $max + 1$, where $max$ is the maximum initial height of some tree. We don't need heights greater than $max + 1$, because, for example, if the height is $max + 2$, we can remove some moves and get the answer for the height $max$. The same thing applies to all heights greater than $max + 1$. Why do we even need the height $max + 1$? In some cases (like $[1, 1, 1, 1, 1, 1, 2]$) the answer for the height $max + 1$ is better than the answer for the height $max$ (in this particular case, it is $9$ vs $11$).

Now, we have two ways to solve the problem: either use some gross formulas, or just write a binary search on the answer. I won't consider the solution with formulas (but we have one), so let's assume we use binary search. Let the current answer be $mid$. Then let $cnt_1 = \lceil\frac{mid}{2}\rceil$ be the number of $+1$ operations we can do and $cnt_2 = \lfloor\frac{mid}{2}\rfloor$ be the number of $+2$ operations we can do. We can use $+2$ operations greedily and then just check if the number of $+1$ operations is sufficient to grow up the remaining heights.

Time complexity: $O(n \log{n})$ per test case.

 **Solution 1 (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        vector<int> h(n);
        for (auto &it : h) {
            scanf("%d", &it);
        }
        
        int mx = *max_element(h.begin(), h.end());
        long long ans = 1e18;
        for (auto need : {mx, mx + 1}) {
            long long l = 0, r = 1e18;
            long long res = -1;
            while (l <= r) {
                long long mid = (l + r) >> 1;
                long long cnt1 = (mid + 1) / 2, cnt2 = mid - cnt1;
                long long need1 = 0;
                for (auto ch : h) {
                    long long cur = (need - ch) / 2;
                    if ((need - ch) % 2 == 1) {
                        ++need1;
                    }
                    if (cnt2 >= cur) {
                        cnt2 -= cur;
                    } else {
                        cur -= cnt2;
                        cnt2 = 0;
                        need1 += cur * 2;
                    }
                }
                if (need1 <= cnt1) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans = min(ans, res);
        }
        
        printf("%lldn", ans);
    }
        
    return 0;
}
```
 **Solution 2 (awoo)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

int main(){
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        forn(i, n) scanf("%d", &a[i]);
        long long ans = 1e18;
        int mx = *max_element(a.begin(), a.end());
        for (int x : {mx, mx + 1}){
            long long cnt1 = 0, cnt2 = 0;
            forn(i, n){
                cnt2 += (x - a[i]) / 2;
                cnt1 += (x - a[i]) % 2;
            }
            long long dif = max(0ll, cnt2 - cnt1 - 1) / 3;
            cnt1 += dif * 2;
            cnt2 -= dif;
            ans = min(ans, max(cnt1 * 2 - 1, cnt2 * 2));
            if (cnt2 > 0){
                cnt1 += 2;
                --cnt2;
                ans = min(ans, max(cnt1 * 2 - 1, cnt2 * 2));
            }
        }
        printf("%lldn", ans);
    }
}
```
[1661D - Progressions Covering](../problems/D._Progressions_Covering.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1661D - Progressions Covering](../problems/D._Progressions_Covering.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Let's solve the problem greedily. But not from the beginning, because if we solve it from the beginning, we can't be sure what option is more optimal for the next elements (e.g. for the second element it is not clear if we need to add $2$ to it starting our segment from the first position or add $1$ to it starting our segment from the second position). So, let's solve the problem from right to left, then anything becomes clearer.

Actually, let's operate with the array $b$ and decrease its elements instead of using some other array. Let's carry some variables: $sum$, $cnt$ and the array $closed$ of length $n$ (along with the answer). The variable $sum$ means the value we need to subtract from the current element from currently existing progressions, $cnt$ is the number of currently existing progressions, and $closed_i$ means the number of progressions that will end at the position $i+1$ (i.e. will not add anything from the position $i$ and further to the left).

When we consider the element $i$, firstly let's fix $sum$ (decrease it by $cnt$). Then, let's fix $cnt$ (decrease it by $closed_i$). Then, let's decrease $b_i$ by $sum$, and if it becomes less than or equal to zero, just proceed. Otherwise, the number by which we can decrease the $i$-th element with one progression, equals to $el = min(k, i + 1)$ (zero-indexed). Then the number of progressions we need to satisfy this element is $need = \lceil\frac{b_i}{el}\rceil$. Let's add this number to the answer, increase $sum$ by $el \cdot need$, increase $cnt$ by $need$, and if $i - el \ge 0$ then we need to end these progressions somewhere, so let's add $need$ to $closed_{i - el}$.

Time complexity: $O(n)$.

 **Solution (vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d %d", &n, &k);
    vector<long long> b(n);
    for (auto &it : b) {
        scanf("%lld", &it);
    }
    
    vector<long long> closed(n);
    long long sum = 0, cnt = 0, ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum -= cnt;
        cnt -= closed[i];
        b[i] -= sum;
        if (b[i] <= 0) {
            continue;
        }
        int el = min(i + 1, k);
        long long need = (b[i] + el - 1) / el;
        sum += need * el;
        cnt += need;
        ans += need;
        if (i - el >= 0) {
            closed[i - el] += need;
        }
    }
    
    printf("%lldn", ans);
    
    return 0;
}
```
[1661E - Narrow Components](../problems/E._Narrow_Components.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1661E - Narrow Components](../problems/E._Narrow_Components.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Consider the naive approach to the problem.

Cut off the columns directly and count the connected components. There are two main solutions to this problem: either DFS (or BFS) or DSU. I personally found the DSU method easier to adjust to the full problem.

So, to count connected components with DSU, you should do the following. Initialize the structure without edges: every free cell is its own connected component. Then add edges one by one. Each edge connects two cells either vertically or horizontally. When an edge connects different components, they merge, and the number of components decreases by one.

Thus, the number of components on a range of columns is the number of free cells on it minus the number of meaningful edges on it (the ones that will merge components if the algorithm is performed only on these columns — the spanning forest edges).

Let's try to adjust this algorithm to the full problem. It would be great if we could just calculate the spanning forest of the entire matrix, and then print the number of free cells minus the number of its edges on the segment. Unfortunately, it's not as easy as that. For components that lie fully in the segment, it works. However, if a component is split by a border of a segment, it can both stay connected or fall apart. If we determine its outcome, we can fix the answer.

There are probably a lot of ways to adjust for that, but I'll tell you the one I found the neatest to code. Let's add the edges into DSU in the following order. Go column by column left to right. First add all vertical edges in any order, then all horizontal edges to the previous column in any order.

If you start this algorithm at the first column, you will be able to answer all queries with $l=1$. Since the algorithm adds columns iteratively, the spanning forest it's building is correct after every column. So the answer for each query is indeed the number of cells minus the number of edges on the range.

Let's investigate the difference between starting at the first column and an arbitrary column $l$.

Look at the column $l$. If it contains $1$ or $3$ free cells or $2$ that are adjacent, then the cells are always in the same component, regardless of what has been before column $l$. If there are no free cells, nothing to the left matters, too. This tells us that the spanning forest that the first algorithm has built, is correct for any queries that start in this $l$.

The only non-trivial case is when only rows $1$ and $3$ of the $l$-th column contain a free cell. Then we can't tell if the algorithm is correct or not, because these two cells can be in the same component already or not. Let's call this a "101" column.

Imagine you started processing from the leftmost column of the query, left to right to the rightmost column. Our previous observations tell us that once we encounter a column that is not a "101", the algorithm onwards will be correct. Until then, we only have some "101" columns to deal with.

We can add the part from the first non-"101" column onwards to the answer (the number of cells minus the number of edges). And then handle the prefix with some easy casework:

* if the leftmost column is not "101", then add nothing;
* if all columns in the query are "101", then the answer is $2$;
* if the first non-"101" column is "111", then add nothing (since the "101"s get merged into the component of this column);
* if the first non-"101" column is "000" or "010", then add $2$ components (since neither row $1$ nor row $3$ is merged anywhere);
* otherwise, add $1$ component.

The number of free cells and edges on a segment can be precalculated with some prefix sums. The closest non-"101" column can also be precalculated with a linear algorithm.

Overall complexity: $O(n \cdot \alpha(n) + q)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

int main(){
    cin.tie(0);
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> s(3);
	forn(i, 3) cin >> s[i];
	vector<int> pr(n + 1);
	forn(i, n){
		pr[i + 1] += pr[i];
		forn(j, 3) pr[i + 1] += (s[j][i] == '1');
	}
	
	vector<int> p(3 * n), rk(3 * n, 1);
	iota(p.begin(), p.end(), 0);
	function<int(int)> getp;
	getp = [&](int a) -> int {
		return a == p[a] ? a : p[a] = getp(p[a]);
	};
	auto unite = [&](int a, int b) -> bool {
		a = getp(a), b = getp(b);
		if (a == b) return false;
		if (rk[a] < rk[b]) swap(a, b);
		p[b] = a;
		rk[a] += rk[b];
		return true;
	};
	
	vector<int> prhe(n + 1), prve(n + 1);
	
	forn(j, n){
		forn(i, 2) if (s[i][j] == '1' && s[i + 1][j] == '1' && unite(i * n + j, (i + 1) * n + j))
			++prve[j + 1];
		forn(i, 3) if (j > 0 && s[i][j] == '1' && s[i][j - 1] == '1' && unite(i * n + j, i * n + (j - 1)))
			++prhe[j];
	}
	forn(i, n) prve[i + 1] += prve[i];
	forn(i, n) prhe[i + 1] += prhe[i];
	
	vector<int> nxt(n + 1, 0);
	for (int i = n - 1; i >= 0; --i)
		nxt[i] = (s[0][i] == '1' && s[1][i] == '0' && s[2][i] == '1' ? (nxt[i + 1] + 1) : 0);
	
	int m;
	cin >> m;
	forn(_, m){
		int l, r;
		cin >> l >> r;
		--l, --r;
		int non101 = l + nxt[l];
		if (non101 > r){
		    cout << "2n";
		    continue;
		}
		int tot = pr[r + 1] - pr[non101];
		int in = (prve[r + 1] - prve[non101]) + (prhe[r] - prhe[non101]);
		int res = tot - in;
		if (non101 != l){
			if (s[0][non101] == '1' && s[1][non101] == '1' && s[2][non101] == '1');
			else if (s[0][non101] == '0' && s[2][non101] == '0') res += 2;
			else ++res;
		}
		cout << res << "n";
	}
	
	return 0;
}
```
[1661F - Teleporters](../problems/F._Teleporters.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1661F - Teleporters](../problems/F._Teleporters.md "Educational Codeforces Round 126 (Rated for Div. 2)")

Initial $n+1$ portals divide the path from $0$ to $a_n$ into $n$ separate sections. If we place a new portal between two given ones, it only affects the section between these two portals.

Let's suppose we want to place $k$ new portals into a section of length $x$. This will divide it into $(k+1)$ sections, and it's quite easy to prove that these sections should be roughly equal in size (to prove it, we can show that if the sizes of two sections differ by more than $1$, the longer one can be shortened and the shorter one can be elongated so the sum of squares of their lengths decreases). So, a section of length $x$ should be divided into $x \bmod (k+1)$ sections of length $\lceil \frac{x}{k+1} \rceil$ and $(k+1) - x \bmod (k+1)$ sections of length $\lfloor \frac{x}{k+1} \rfloor$. Let's denote the total energy cost of a section of length $x$ divided by $k$ new portals as $f(x, k)$; since we divide it in roughly equal parts, it's easy to see that

$$f(x, k) = (x \bmod (k+1)) \cdot (\lceil \frac{x}{k+1} \rceil)^2 + ((k+1) - x \bmod (k+1)) \cdot (\lfloor \frac{x}{k+1} \rfloor)^2$$

The key observation that we need to make now is that $f(x, k) - f(x, k+1) \ge f(x, k+1) - f(x, k+2)$; i. e. if we add more portals to the same section, the energy cost change from adding a new portal doesn't go up. Unfortunately, we can't give a simple, strict proof of this fact, but we have faith and stress (this would be easy to prove if it was possible to place portals in non-integer points, we could just analyze the derivative, but in integer case, it's way more difficult).

Okay, what should we do with the fact that $f(x, k) - f(x, k+1) \ge f(x, k+1) - f(x, k+2)$ for a section of length $x$? The main idea of the solution is binary search over the value of $f(x, k) - f(x, k+1)$; i. e., we use binary search to find the minimum possible change that a new portal would give us. Let's say that we want to check that using the portals that give the cost change $\ge c$ is enough; then, for each section, we want to find the number of new portals $k$ such that $f(x, k-1) - f(x, k) \ge c$, but $f(x, k) - f(x, k+1) < c$; we can use another binary search to do that. For a fixed integer $c$, we can calculate not only the number of new portals that we can add if the cost change for each portal should be at least $c$, but also the total cost of the path after these changes; let's denote $g(c)$ as the total cost of the path if we place new portals until the cost change is less than $c$, and $h(c)$ is the number of portals we will place in that case.

We have to find the minimum value of $c$ such that $g(c) \le m$. Now, it looks like $h(c)$ is the answer, but this solution gives WA on one of the sample tests. The key observation we are missing is that, for the value $c$, we don't have to add all of the portals that change the answer by $c$; we might need only some of them. To calculate the answer, let's compute four values:

* $g(c+1)$;
* $h(c+1)$;
* $g(c)$;
* $h(c)$.

If we place $h(c+1)$ portals and add new portals one by one, until the total cost becomes not greater than $m$, the cost change from each new portal will be equal to $\frac{g(c+1) - g(c)}{h(c) - h(c+1)}$ (or just $c$ if we consider the fact that we start using the portals which change the cost by $c$). So, we can easily calculate how many more additional portals we need to add if we start from $h(c+1)$ portals and cost $g(c+1)$.

The total complexity of our solution is $O(n \log^2 A)$: we have a binary search over the cost change for each new portal; and for a fixed cost change, to determine the number of portals we place in each section, we run another binary search in every section separately.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

int n;
vector<int> lens;

long long sqr(int x)
{
    return x * 1ll * x;
}

long long eval_split(int len, int k)
{
    return sqr(len / k) * (k - len % k) + sqr(len / k + 1) * (len % k);
}

pair<int, long long> eval_segment(int len, long long bound)
{
    // only take options with value >= bound
    if(bound <= 2 || len == 1)
        return make_pair(len - 1, len);
    int lf = 0;
    int rg = len - 1;
    while(rg - lf > 1)
    {
        int mid = (lf + rg) / 2;
        if(eval_split(len, mid) - eval_split(len, mid + 1) >= bound)
            lf = mid;
        else
            rg = mid;    
    }
    return make_pair(lf, eval_split(len, lf + 1));
}

pair<int, long long> eval_full(long long bound)
{
    pair<int, long long> ans;
    for(auto x : lens)
    {
        pair<int, long long> cur = eval_segment(x, bound);
        ans.first += cur.first;
        ans.second += cur.second;
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    int pr = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        lens.push_back(x - pr);
        pr = x;
    }
    long long w;
    scanf("%lld", &w);
    long long lf = 0ll;
    long long rg = (long long)(1e18) + 43;
    if(eval_full(rg).second <= w)
    {
        cout << 0 << endl;
        return 0;
    }
    while(rg - lf > 1)
    {
        long long mid = (lf + rg) / 2;
        pair<int, long long> res = eval_full(mid);
        if(res.second <= w)
            lf = mid;
        else
            rg = mid;
    }   
    pair<int, long long> resL = eval_full(lf);
    pair<int, long long> resR = eval_full(rg);
    assert(resL.second <= w && resR.second > w);
    long long change = (resR.second - resL.second) / (resR.first - resL.first);
    cout << resL.first + (w - resL.second) / change << endl;
}
```
