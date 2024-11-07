# Tutorial_(en)

Thank you for participating. I hope you enjoyed the contest!

[1401A - Distance and Axis](../problems/A._Distance_and_Axis.md "Codeforces Round 665 (Div. 2)")

 **Tutorial**
### [1401A - Distance and Axis](../problems/A._Distance_and_Axis.md "Codeforces Round 665 (Div. 2)")

If n is less than k, we have to move A to coordinate k, and set the coordinate of B as 0 or k. So the answer is k−n.

If n is not less than k, let's define the coordinate of B as m(m×2≤n). By the condition in the problem, the difference between (m−0) and (n−m) should be equal to k. That is, (n−m)−(m−0) is k, and summarizing the formula, m=(n−k)/2. Because the coordinate of B is integer, if the parity of n and k is same the answer is 0, otherwise the answer is 1(If we increase the coordinate of A by 1, m becomes integer).

Time complexity : O(1)

 **Solution Code**
```cpp
#include<bits/stdc++.h>

#define endl 'n'

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k, n, t;

    cin >> t;
    for(;t--;)
    {
        cin >> n >> k;

        if(n < k)
            cout << k - n << endl;

        else if(n % 2 == k % 2)
            cout << 0 << endl;

        else
            cout << 1 << endl;
    }

    return 0;
}
```
 **Behind Story**After 2 problems got rejected, I made this problem but it has 2D coordinate originally.

[1401B - Ternary Sequence](../problems/B._Ternary_Sequence.md "Codeforces Round 665 (Div. 2)")

 **Tutorial**
### [1401B - Ternary Sequence](../problems/B._Ternary_Sequence.md "Codeforces Round 665 (Div. 2)")

We can find the kind of the value of ci is three (−2,0,2). And ci is −2 only if ai is 1 and bi is 2, and ci is 2 only if ai is 2 and bi is 1. Otherwise ci is 0. So we have to make (ai,bi) pair (1,2) as little as possible, and pair (2,1) as much as possible. To do this, first we can make (1,0) pair, (0,2) pair, and (2,1) pair as much as possible. After that, pairing the remaining values doesn't affect the sum of ci. (It ai in which value is 1 and bi in which value is 2 are all left, we have to pair them although the sum decreases.)

Time complexity : O(1)

 **Solution Code**
```cpp
#include<bits/stdc++.h>

#define endl 'n'

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;
    for(;t--;)
    {
	int m, sum = 0, x0, x1, x2, y0, y1, y2;

	cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;

	m = min(x0, y2);
	x0 -= m;
	y2 -= m;

	m = min(x1, y0);
	x1 -= m;
	y0 -= m;

	m = min(x2, y1);
	x2 -= m;
	y1 -= m;
	sum += 2 * m;

	sum -= 2 * min(x1, y2);

	cout << sum << endl;
    }
}
```
 **Behind Story**One tester suggested to swap A and B but I and [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic") thought it is not good idea, so the order didn't changed.

[1401C - Mere Array](../problems/C._Mere_Array.md "Codeforces Round 665 (Div. 2)")

 **Tutorial**
### [1401C - Mere Array](../problems/C._Mere_Array.md "Codeforces Round 665 (Div. 2)")

Let's define the minimum element of a as m. We can find the position of the elements which is not divisible by m cannot be changed because these elements don't have m as factor. But we can rearrange elements divisible by m whatever we want in the following way:

∙ Let's suppose m = ax, and there is two elements ay, az in which x, y, z are all different. Swap(ax, ay), swap(ay, az), and swap(az, ax). Then only ay and az are swapped from the initial state. Repeat this process.

So we can rearrange elements divisible by m in non-descending order. After that if whole array is non-descending the answer is YES, otherwise NO.

Time complexity : O(nlogn)

 **Solution Code**
```cpp
#import<bits/stdc++.h>

#define endl 'n'

using namespace std;

int a[100005], b[100005];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(;t--;)
    {
	int k = 0, m = 1000000000, n;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
	    cin >> a[i];
            b[i] = a[i];
	    m = min(m, a[i]);
	}

        sort(b, b + n);

	for(int i = 0; i < n; i++)
	    if(a[i] != b[i] && a[i] % m > 0)
		k = 1;

	if(k)
	    cout<<"NO"<<endl;
	else
	    cout<<"YES"<<endl;
    }
}
```
 **Behind Story**Most testers especially liked this problem.

[1401D - Maximum Distributed Tree](../problems/D._Maximum_Distributed_Tree.md "Codeforces Round 665 (Div. 2)")

 **Tutorial**
### [1401D - Maximum Distributed Tree](../problems/D._Maximum_Distributed_Tree.md "Codeforces Round 665 (Div. 2)")

Let's define wi as the product of the number of vertices belonging to each of the two components divided when the ith edge is removed from the tree, and zi as the number on ith edge. Now a distribution index is equal to ∑n−1i=1(wi×zi). Now there are two cases:

A : m≤n−1

In this case, we have to label p1,p2,…pm to m distinct edges because we have to minimize the number of 1-s. And to maximize distribution index, we can label a larger pi to the edge in which wi is larger because the following holds:

∙ For four positive integers a,b,c,d (a≥b,c≥d), ac+bd≥ad+bc

Let's suppose a=b+x,c=d+y (x,y≥0). Then the equation can be written as follows:

(b+x)(d+y)+bd≥(b+x)d+b(d+y)

bd+by+xd+xy+bd≥bd+xd+bd+by

xy≥0

Because x,y≥0, we proved it.

And label 1 to the remaining edges.

B : m>n−1

In this case, we can make no 1-s exist out of n−1 integers, and some of n−1 number would be composite. And to maximize distribution index, we can label the product of m−n+2 largest pi to the edge in which wi is largest, and label the remaining pi to the remaining edges in the same way as case A because the following holds:

∙ For five positive integers a,b,c,d,e (a≥b,d≥e), acd+be≥bcd+ae

Substituting f=cd in the above equation, we can find the equation is same as before. So we proved it.

After filling in the edge, calculate it and find the answer.

Time complexity : O(max(n,m)logmax(n,m))

 **Solution Code**
```cpp
#include<bits/stdc++.h>

#define endl 'n'

using namespace std;

typedef long long LL;

struct H{int x, y;};

int ii, n;
const int q = 1e9 + 7;
LL p[100005], pv[100005], vi[100005], w[100005];
H e[200040];

int C(H a, H b){return a.x < b.x;}
int G(LL a, LL b){return a > b;}

LL dfs(int v)
{
    LL d = 1;

    vi[v] = 1;

    for(int i = pv[v]; i < pv[v+1]; i++)
	if(!vi[e[i].y])
	    d += dfs(e[i].y);

    w[ii] = d * (n - d);
    ii++;

    return d;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    for(;t--;)
    {
	int k = 0, m;
	LL x = 1;

	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
	    cin >> e[i].x >> e[i].y;
	    e[i + n - 1].x = e[i].y;
	    e[i + n - 1].y = e[i].x;
	}

	int sz = 2 * n - 2;

	sort(e, e + sz, C);

	for(int i = 1; i < sz; i++)
	{
	    if(e[i].x > e[i - 1].x)
	    {
		for(int j = e[i - 1].x + 1; j <= e[i].x; j++)
		    pv[j] = i;
	    }
	}
	for(int j = e[sz - 1].x + 1; j <= n + 2; j++)
	    pv[j] = sz;

	ii = k = 0;
	dfs(1);

	cin >> m;

	for(int i = 0; i < m; i++)
	    cin >> p[i];

	sort(p, p + m, G);
	sort(w, w + n - 1, G);

	if(m < n)
	    for(int i = m; i < n - 1; i++)
		p[i] = 1;
	else
	{
	    int i;

	    for(i = m - 1; i > m - n; k = i, i--)
		w[i] = w[i - m + n - 1];

	    for(; i; i--)
		w[i] = w[0];
	}

	int l = max(m, n - 1);
	
	int i;
	for(i = 0, x = w[0]; i <= k; i++)
	    x = x * p[i] % q;

	for(;i < l; i++)
	    x = (x + w[i] * p[i]) % q;

	cout << x << endl;

	for(int i = 1; i <= n; i++)
	    vi[i] = 0;
    }
}
```
 **Behind Story**This problem was inspired by [1187E - Tree Painting](https://codeforces.com/contest/1187/problem/E "Educational Codeforces Round 67 (Rated for Div. 2)") and [1281E - Jeremy Bearimy](https://codeforces.com/contest/1281/problem/E "Codeforces Round 607 (Div. 2)"). Originally this was proposed as E, but after some fixing it became more easier than original one. And the modulo was new one originally, but I changed it later by myself.

[1401E - Divide Square](../problems/E._Divide_Square.md "Codeforces Round 665 (Div. 2)")

 **Tutorial**
### [1401E - Divide Square](../problems/E._Divide_Square.md "Codeforces Round 665 (Div. 2)")

Under given condition, there are only two cases in which the number of pieces increases.

∙ When a segment intersects with two sides (facing each other) of the square, the number of pieces increases by one.

∙ When two segment intersects in the square (not including sides), the number of pieces increases by one.

So the answer is equal to (the number of segment intersecting with two sides of the square) + (the number of intersection in the square). You can sort the segments by ascending order of y-coordinate (Set the start and end points of vertical lines separately.) and do sweeping using segment tree to calculate the number of intersections in the square.

Time complexity : O(nlogn+mlogm)

 **Solution Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

struct H{int k, l, r;};

const int p = 1048576;

LL l[2100000], r[2100000], z[2100000];

H h[100005], v[200040];

int C(H a, H b){return a.k < b.k;}
int D(H a, H b){return a.l < b.l || a.l == b.l && a.r > b.r;}

LL sum(int x, int y, int d) // find the sum of range [x, y]
{
    if(x <= l[d] && r[d] <= y)
	return z[d];

    if(x > r[d] || y < l[d])
	return 0;

    return sum(x, y, d << 1) + sum(x, y, (d << 1) + 1);
}

void REP(int i, LL k) // add k to i-th number
{
    i += p;

    for(z[i] += k; i >>= 1;)
	z[i] = z[i << 1] + z[(i << 1) + 1];
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LL m, n, s = 1;

    cin >> n >> m;

    for(int i = 0; i < p; i++)
	l[i + p] = r[i + p] = i;

    for(int i = p; --i;)
    {
	l[i] = l[i << 1];
	r[i] = r[(i << 1) + 1];
    }

    for(int i = 0; i < n; i++)
    {
	cin >> h[i].k >> h[i].l >> h[i].r;

	if(h[i].r - h[i].l == 1000000)
	    s++;
    }

    sort(h, h + n, C);

    for(int i = 0; i < m; i++)
    {
	int j = i << 1;

	cin >> v[j].k >> v[j].l >> v[j+1].l;

	v[j + 1].k = v[j].k;
	v[j].r = 1;
	v[j + 1].r = -1;

	if(v[j + 1].l - v[j].l == 1000000)
	    s++;
    }

    sort(v, v + 2 * m, D);

    for(int i = 0, j = 0; i < n && j < 2 * m;)
    {
	if(h[i].k < v[j].l || h[i].k == v[j].l && v[j].r < 0)
	{
	    s += sum(h[i].l, h[i].r, 1);
	    i++;
	}
	else
	{
	    REP(v[j].k, v[j].r);
	    j++;
	}
    }

    cout << s;

    return 0;
}
```
 **Behind Story**This problem was inspired by [1075C - The Tower is Going Home](https://codeforces.com/contest/1075/problem/C "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 2)"). Originally the restriction of n,m was small so O(n2) solution could pass, but [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic") suggested to increase them up to 105. In fact, I only knew brute forces solution until he tells me the solution using segment tree. And the size of the square was 109×109 so coordinate compression would be done additionally, but we eliminated it to avoid too many implementation.

[1401F - Reverse and Swap](../problems/F._Reverse_and_Swap.md "Codeforces Round 665 (Div. 2)")

 **Tutorial**
### [1401F - Reverse and Swap](../problems/F._Reverse_and_Swap.md "Codeforces Round 665 (Div. 2)")

Let's consider the sequence as $0$-based. Then we can find the following two facts:

$\bullet$ If we do $Reverse(k)$ operation once, $a_i$ becomes $a_{i\text{^}(2^k-1)}$.

$\bullet$ If we do $Swap(k)$ operation once, $a_i$ becomes $a_{i\text{^}(2^k)}.$

So in any state there is an integer $x$ that makes the current $a_i$ equal to the initial $a_{i\text{^}x}$ and current $a_{i\text{^}x}$ is equal to the initial $a_i$ for each $i$ ($0 \le i \le 2^n-1$). (Don't consider the change of the values by $Replace(x,k)$ operation.)

Therefore, if we can calculate $\sum_{i=l}^r a_{i\text{^}x}$ fast for arbitrary $x$, also can solve the problem, and it can be done using segment tree. When processing $Replace(i,k)$ queries, replace $a_{i\text{^}x}$ as $k$. And when processing $Reverse(k)$ or $Swap(k)$ queries, just replace $x$ as $x\text{^}(2^k-1)$ or $x\text{^}(2^k)$.

And $Sum(l,r)$ queries are left. To calculate this value, divide the segment $[l, r]$ into smaller segments, in which length of each segment is power of $2$ and can be found in the segment tree. (ex : segment $[3, 9]$ is divided into three segments - $[3, 3]$, $[4, 7]$, $[8, 9]$)

Next, find the sum of numbers in which index is in each segment. For divided segment $[l, r]$ in which length is $2^k$, the values $l\text{^}x, (l+1)\text{^}x, \ldots (r-1)\text{^}x, r\text{^}x$ are, when sorted, form another segment $[l\text{^}(x\text{&~}(2^k-1)), r\text{^}(x\text{&~}(2^k-1))]$, which $x\text{&~}(2^k-1)$ means the largest of multiples of $2^k$ not greater than $x$. So you can find the sum of numbers in each divided segment $\sum_{i=l}^r$(current $a_i$) as $\sum_{i=l\text{^}(x\text{&~}(2^k-1))}^{r\text{^}(x\text{&~}(2^k-1))}$(initial $a_i$). Repeat this and we can find the answer for each $Sum$ query.

Time complexity : $O(nq)$

 **Solution Code**
```cpp
#include<bits/stdc++.h>

#define endl 'n'

using namespace std;

typedef long long LL;

LL p, a[528000], ll[528000], rr[528000];

LL SUM(LL l, LL r, LL d)
{
    LL x, y, z;

    x = ll[d];
    y = rr[d];
    z = b & ~(y - x);

    x ^= z;
    y ^= z;

    if(x > r || y < l)
	return 0;

    else if(x < l || y > r)
	return(SUM(l, r, z << 1) + SUM(l, r, (z << 1) + 1));

    else
	return a[z];
}

void REP(LL i,LL k)
{
    i += p;

    for(a[i] = k; i >>= 1;)
	a[i] = (a[i << 1] + a[(i << 1) + 1]);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int b = 0, i, n, q;

    cin >> n >> q;
    p = 1 << n;

    for(i = 0; i < p; i++)
    {
	cin >> a[p + i];
	ll[p + i] = rr[p + i] = i;
    }

    for(; i < p; i++)
	ll[p + i] = rr[p + i] = i;

    for(; --i;)
    {
	a[i] = (a[i << 1] + a[(i << 1) + 1]);
	ll[i] = ll[i << 1];
	rr[i] = rr[(i << 1) + 1];
    }

    for(; q--;)
    {
	int m;

	cin >> m;

	if(m == 1)
	{
	    int k, x;

	    cin >> x >> k;

	    REP((x - 1) ^ b, k);
	}

	else if(m == 2)
	{
	    int k;

	    cin >> k;

	    b ^= (1 << k) - 1;
	}

	else if(m == 3)
	{
	    int k;

	    cin >> k;

	    b ^= 1 << k;
	}

	else
	{
	    int l, r;

	    cin >> l >> r;

	    cout << SUM(l - 1, r - 1, 1) << endl;
	}
    }
}
```
 **Behind Story**This problem has 6 generators, and I most liked it among 6 problems.

