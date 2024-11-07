# Tutorial_(en)

[1896A - Jagged Swaps](../problems/A._Jagged_Swaps.md)
----------------------------------------------------------------------

Writer: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**Look at the samples.

 **Solution**Observe that since we are only allowed to choose i≥2 to swap ai and ai+1, it means that a1 cannot be modified by the operation. Hence, a1=1 must hold. We can prove that as long as a1=1, we will be able to sort the array.

Consider the largest element of the array. Let its index be i. Our objective is to move ai to the end of the array. If i=n, it means that the largest element is already at the end. Otherwise, since ai is the largest element, this means that ai−1<ai and ai>ai+1. Hence, we can do an operation on index i and move the largest element one step closer to the end. We repeatedly do the operation until we finally move the largest element to the end of the array. Then, we can pretend that the largest element does not exist and do the same algorithm for the prefix of size n−1. Hence, we will able to sort the array by doing this repeatedly.

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;
int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (arr[0] == 1) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << 'n';
    }
}
```
[1896B - AB Flipping](../problems/B._AB_Flipping.md)
---------------------------------------------------------------------

Writer: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**What happens when s starts with some B and ends with some A?

 **Solution**If the string consists of only A or only B, no operations can be done and hence the answer is 0. Otherwise, let x be the smallest index where sx=A and y be the largest index where xy=B. If x>y, this means that the string is of the form s=B…BA…A. Since all the B are before the A, no operation can be done and hence the answer is also 0.

Now, we are left with the case where x<y. Note that s[1,x−1]=B…B and s[y+1,n]=A…A by definition. Since the operation moves A to the right and B to the left, this means that s[1,x−1] will always consist of all B and s[y+1,n] will always consist of all A. Hence, no operation can be done from index 1 to x−1 as well as from index y to n−1. 

The remaining indices where an operation could be done are from x to y−1. It can be proven that all y−x operations can be done if their order is chosen optimally. Let array b store the indices of s between x and y that contain B in increasing order. In other words, x<b1<b2<…<bk=y and bi=B, where k is the number of occurences of B between x and y. For convenience, we let b0=x. Then, we do the operations in the following order: 

b1−1,b1−2,…,b0+1,b0,

b2−1,b2−2,…,b1+1,b1, 

b3−1,b3−2,…,b2+1,b2,

⋮

bk−1,bk−2,…,bk−1+1,bk

It can be seen that the above ordering does operation on all indices between x and y−1. To see why all of the operations are valid, we look at each row separately. Each row starts with bi−1, which is valid as sbi=B and sbi−1=A (assuming that it is not the last operation of the row). Then, the following operations in the same row move B to the left until position bi−1. To see why the last operation of the row is valid as well, even though sbi−1 might be equal to B initially by definition, either i=1 which means that sb0=sx=A, or an operation was done on index bi−1−1 in the previous row which moved A to index bi−1. Hence, all operations are valid.

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
char s[200005];
 
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc, n; cin >> tc;
	while (tc--) {
		cin >> n; s[n + 1] = 'C';
		for (int i = 1; i <= n; ++i) cin >> s[i];
		int pt1 = 1, pt2 = 1, ans = 0;
		while (s[pt1] == 'B') ++pt1, ++pt2;
		while (pt1 <= n) {
			int cntA = 0, cntB = 0;
			while (s[pt2] == 'A') ++pt2, ++cntA;
			while (s[pt2] == 'B') ++pt2, ++cntB;
			if (s[pt2 - 1] == 'B') ans += pt2 - pt1 - 1;
			if (cntB) pt1 = pt2 - 1;
			else break;
		}
		cout << ans << 'n';
	}
}
```
[1896C - Matching Arrays](../problems/C._Matching_Arrays.md)
-------------------------------------------------------------------------

Writer: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**Consider a greedy algorithm.

 **Solution**For simplicity, assume that both arrays a and b are sorted in increasing order. The final answer can be obtained by permuting the answer array using the same permutation to permute sorted array a to the original array a.

**Claim**: If the rearrangement bx+1,bx+2,…,bn,b1,b2,…,bx does not have beauty x, it is not possible to rearrange b to make the beauty equals to x.

*Proof*: Suppose there exists an alternative rearrangement different from above represented by permutation p where bp1,bp2,…,bpn results in a beauty of x. Let array q represent the x indices where ai>bpi in increasing order. In other words, 1≤q1<q2<…<qx≤n and aqi>bpqi. Let i be the largest index where qi≠n−i+1 (qi<n−i+1 also holds due to strict inequality above). We know that aqi>bpqi and an−i+1≤bpn−i+1. Since a is sorted and qi<n−i+1, we have aqi≤an−i+1, and hence, an−i+1>bpqi and aqi≤bpn−i+1. This means that we can swap pqi with pn−i+1 without changing the beauty of the array, while allowing qi=n−i+1. Hence, by doing the swapping repeatedly, we will get qi=n−i+1 for all i between 1 and x.

An alternative interpretation to the result above is that we managed to obtain a solution where for all i between 1 and n−x, we have ai≤bpi. On the other hand, for all i between n−x+1 and n, we have ai>bpi. Let i be the largest index between 1 and n−x where pi≠i+x (pi<i+x due to maximality). Then, let j be the index where pj=i+x. Consider two cases:

 * j≤n−x. Since i is the largest index where pi≠i+x, this means that j<i and hence aj≤ai. We have ai≤bpi≤bi+x=bpj and aj≤ai≤bpi. Hence, we can swap pi and pj without changing the beauty of the array, while allowing pi=i+x.
* j>n−x. We have ai≤bpi≤bi+x=bpj and aj>bpj=bi+x>bpi. Hence, we can swap pi and pj without changing the beauty of the array, while allowing pi=i+x.

By repeating the above repeatedly, we can obtain a solution where pi=i+x for all i between 1 and n−x. Let i be the smallest index between n−x+1 and n where pi≠i−n+x (pi>i−n+x by minimality). Then, let j be the index where pj=i−n+x. Note that j>n−x as well since pi=i+x for all i between 1 and n−x. Since i is the smallest index where pi≠i−n+x, this means that i<j and hence ai≤aj. We have ai>bpi≥bi−n+x=bpj and aj≥ai>bpi. Hence, we can swap pi and pj without changing the beauty of the array, while allowing pi=i−n+x. By doing this repeatedly, we can obtain a solution where pi=i−n+x for all i between n−x+1 and n. Now, p=[x+1,x+1,…,n,1,2,…,x], which matches the rearrangement in our claim.

 **Implementation**
```cpp
#include <bits/stdc++.h> 
using namespace std;
 
#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
 
const int INF = 1000000005;
const int MAXN = 200005;
 
int t;
int n, x;
int a[MAXN], b[MAXN], aid[MAXN];
int ans[MAXN];
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        REP (i, 0, n) {
            cin >> a[i];
        }
        REP (i, 0, n) {
            cin >> b[i];
        }
        iota(aid, aid + n, 0);
        sort(aid, aid + n, [&] (int l, int r) {
                return a[l] < a[r];
                });
        sort(b, b + n);
        REP (i, 0, x) {
            ans[aid[n - x + i]] = b[i];
        }
        REP (i, x, n) {
            ans[aid[i - x]] = b[i];
        }
        REP (i, 0, n) {
            x -= a[i] > ans[i];
        }
        if (x == 0) {
            cout << "YESn";
            REP (i, 0, n) {
                cout << ans[i] << ' ';
            }
            cout << 'n';
        } else {
            cout << "NOn";
        }
    }
    return 0;
}
```
[1896D - Ones and Twos](../problems/D._Ones_and_Twos.md)
-----------------------------------------------------------------------

Writer: [lanhf](https://codeforces.com/profile/lanhf "Master lanhf")

 **Hint 1**Consider some small examples and write down every possible value of subarray sums. Can you see some patterns?

 **Solution**Denote s[l,r] as the sum of subarray from l to r.

**Claim**: If there is any subarray with sum v≥2, we can find a subarray with sum v−2.

*Proof*: Suppose s[l,r]=v, consider 3 cases:

 * a[l]=2, we have s[l+1,r]=v−2.
* a[r]=2, we have s[l,r−1]=v−2.
* a[l]=a[r]=1, we have s[l+1,r−1]=v−2.

So to check if there exists a subarray whose sum equals v, we can find the maximum subarray sum having the same parity with v and compare it with v.

The case where (s[1,n]−v)%2=0 is obvious, suppose the opposite happens. If array a is full of 2-s, the answer is NO. Otherwise, let x and y be the positions of the first 1 and last 1 in a. Any subarray with l≤x≤y≤r will have a different parity with v. So we will compare max(s[x+1,n],s[1,y−1]) with v to get the answer.

 **Implementation**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n);
        set<int> pos;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) pos.insert(i);
        }
        while (q--) {
            int cmd; cin >> cmd;
            if (cmd == 1) {
                int v; cin >> v;
                int num = pos.size();
                if ((v - num) & 1) {
                    if (num == 0) cout << "NO";
                    else {
                        int s1 = 2 * *pos.rbegin() - (num - 1);
                        int s2 = 2 * (n - *pos.begin() - 1) - (num - 1);
                        if (v <= max(s1, s2)) cout << "YES";
                        else cout << "NO";
                    }
                } else {
                    if (v <= 2 * n - num) cout << "YES";
                    else cout << "NO";
                }
                cout << 'n';
            } else {
                int i; cin >> i; i--;
                pos.erase(i);
                cin >> a[i];
                if (a[i] == 1) pos.insert(i);
            }
        }
    }
}
```
[1896E - Permutation Sorting](../problems/E._Permutation_Sorting.md)
-----------------------------------------------------------------------------

Writer: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**For each index i from 1 to n, let hi denote the number of cyclic shifts needed to move ai to its correct spot. In other words, hi is the minimum value such that (i+hi−1) % n+1=ai. How can we get the answer from hi?

 **Solution**For convenience, we will assume that the array is cyclic, so aj=a(j−1) % n+1. The answer for each index i from 1 to n is hi (defined in hint 1) minus the number of indices j where i<j<i+hi and i<aj<i+hi (or i<aj+n<i+hi to handle cyclic case when i+hi>n). This is because the value that we are calculating is equal to the number of positions that ai will skip during the rotation as the index is already good.

To calculate the above value, it is convenient to define an array b of size 2n where bi=ai for all i between 1 to n, and bi=ai−n+n for all i between n+1 to 2n to handle cyclicity. We will loop from i=2n to i=1, and do a point increment to position ai if ai≥i, otherwise, do a point increment to position ai+n. Then, to get the answer for index i, we do a range sum query from i+1 to i+hi−1. Point increment and range sum query can be done using a binary indexed tree in O(logn) time per query/update. Hence, the problem can be solved in O(nlogn) time.

 **Implementation**
```cpp
#include <bits/stdc++.h> 
using namespace std;
 
#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
 
const int INF = 1000000005;
const int MAXN = 1000005;
 
int t;
int n;
int p[MAXN];
int ans[MAXN];
 
int fw[MAXN * 2];
void incre(int i, int x) {
    for (; i <= 2 * n; i += i & -i) {
        fw[i] += x;
    }
}
int qsm(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) {
        res += fw[i];
    }
    return res;
}
inline int qsm(int s, int e) {
    return qsm(e) - qsm(s - 1);
}
 
int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 1, n + 1) {
            cin >> p[i];
        }
        REP (i, 0, 2 * n + 5) {
            fw[i] = 0;
        }
        vector<pair<int, int>> rgs;
        REP (i, 1, n + 1) {
            if (i <= p[i]) {
                rgs.push_back({i, p[i]});
                rgs.push_back({i + n, p[i] + n});
            } else {
                rgs.push_back({i, p[i] + n});
            }
        }
        sort(ALL(rgs), greater<pair<int, int>>());
        for (auto [l, r] : rgs) {
            if (l <= n) {
                ans[p[l]] = r - l - qsm(l, r);
            }
            incre(r, 1);
        }
        REP (i, 1, n + 1) {
            cout << ans[i] << ' ';
        }
        cout << 'n';
    }
    return 0;
}

```
[1896F - Bracket Xoring](../problems/F._Bracket_Xoring.md)
------------------------------------------------------------------------

Writer: [maomao90](https://codeforces.com/profile/maomao90 "Grandmaster maomao90")

 **Hint 1**The operation is equivalent to toggling s at every odd i where bi is an open bracket and every even i where bi is a closed bracket.

 **Proof**Suppose there are x open brackets and y close brackets between positions 1 and i. Note that x≥y by definition of balanced bracket sequences. - Case 1: bi is an open bracket. Position i will be toggled exactly x−y times as y of the open brackets will be matched before position i, and the remaining x−y open brackets will only be matched after position i. This means that position i will be toggled only if x−y is odd, and hence, x−y+2y=x+y=i must be odd as well. - Case 2: bi is a close bracket. Position i will be toggled exactly x−y+1 times as y−1 of the open brackets will be matched before i, 1 of the open bracket will be matched with position i, and the remaining x−y open brackets will be matched after position i. This means that position i will be toggled only if x−y is even, and hence, x−y+2y=x+y=i must be even as well.

 **Hint 2**Every operation will always toggle s1 and sn. Furthermore, every operation will always toggle an even number of positions.

 **Proof**If s is toggled at an open bracket, s will be toggled at its matching close bracket as well.

 **Hint 3**If s1≠sn or there is an odd number of 1s in s, it is not possible to change all elements of s to 0. Otherwise, it is always possible.

 **Hint 4**If it is possible to change all elements of s to 0, at most 3 operations are needed.

 **Solution 1**From hint 3, we know the cases where it is impossible to change all elements of s to 0. We will now only consider the case where it is possible to change all elements of s to 0.

Using hint 1, we can easily check whether it is possible to change all elements of s to 0 using only one operation by first constructing the bracket sequence and then checking whether the resultant bracket sequence is balanced. From now on, we will assume that it is not possible to change all elements of s to 0 using one operation.

Suppose s1=sn=1. We know from hint 2 that each operation will always toggle s1 and sn, so since it is not possible to change all elements of s to 0 using one operation, we will need three operations. If we let the first operation be b=(()()…()()), s1 and sn will be toggled while the remaining elements stay the same. Now, s1=sn=0, so if we can solve this case using only two operations, it means that we can solve the s1=sn=1 case using only three operations.

To solve the final case where s1=sn=0, we will look at a special balanced bracket sequences b=(()()…()()). Notice that if we do an operation using this bracket sequence, only s1 and sn will be toggled. Suppose there exist an index i between 2 and 2n−2 where we want to toggle both si and si+1. We can take the special balanced bracket sequence b=(()()…()()), then swap bi and bi+1. This will always result in a balanced bracket sequence that will toggle s1, sn, as well as the desired si and si+1. This will allow us to change all elements of s to 0 in 2n moves as we can scan from i=2 to i=2n−2 and do an operation toggling si and si+1 if si=1. Since there is an even number of 1s in s from hint 3, toggling adjacent positions will always change all elements of s to 0.

To reduce the number of operations from 2n to 2, notice that a lot of the operations can be parallelized into a single operation. Let A0 represent the set of even indices between 2 and 2n−2 where we want to toggle si and si+1. Similarly, let A1 represent the set of odd indices between 2 and 2n−2 where we want to toggle si and si+1. In a single operation, we can take the special balanced bracket sequence b=(()()…()()), and swap bi and bi+1 for all i that is in the set A0. Since A0 only contains even indices, the swaps are non-intersecting, and hence, the resultant bracket sequence will still be balanced and s1, sn, as well as si and si+1 will be toggled for all the desired even indices i. We can use the same strategy with A1, starting with the same special balanced bracket sequence and then swapping bi and bi+1 for all i that is in set A1. Hence, after using these two operations, all elements of s will change to 0.

 **Solution 2**We will demonstrate a way to use 2 bracket sequence to solve any binary string whose first and last element is 0 and who also has an even number of $\texttt{1}$s.

Defined the balance of an (incomplete) bracket sequence as the number of open brackets minus the number of closed brakcets. For example, `((()` has balance 2, `(()()((` has balance 3 and `()` has balance 0.

Using hint 1 we can see that the resulting binary string will contain `0` at position i iff the character at position i in both bracket sequences is the same. Suppose the balance of your current bracket sequences is (a,b). You can change it (a±1,b±1). If both ± have the same parity, then the resulting binary string will contain 0 at that position.

Now, we will demonstrate a greedy algorithm.

(0,0)→(1,1)→(0,2),(2,2)→(1,3),(1,1)→(0,2),(2,2)→…→(1,1)→(0,0)

One can show by a simple parity argument that the second last balance must necessarily be (1,1) since the number of $\texttt{1}$s in the string is even.

 **Solution 3**Similar to solution 2, we will demonstrate a way to use 2 bracket sequence to solve any binary string whose first and last element is 0 and who also has an even number of $\texttt{1}$s.

Using the same greedy argument in solution 2 (or by guessing), we know that we can always use two bracket sequences where the number of open brackets minus the number of close brackets is always between 0 and 3 for all prefixes of the bracket sequence. For convenience, we will define "balance" as the number of open brackets minus the number of close brackets. 

Hence, we can do dynamic programming using the states dp[i][balance1][balance2] which returns whether it is possible to create two bracket sequences b1 and b2 of length i such that the balance of b1 and b2 are balance1 and balance2 respectively and s[1,i] becomes all 0. The transition can be done by making sure that the balances stay between 0 and 3 and that b1i≠b2i if si=1 and vice versa.

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(int n, string s) {
	vector<int> a;
	for (char &i : s) {
		a.push_back(i & 1);
	}
	
	if (a.front() != a.back()) {
		cout << -1 << endl;
		return ;
	}
	
	if (count(a.begin(), a.end(), 1) % 2) {
		cout << -1 << endl;
		return ;
	}
	
	bool flipped = false;
	if (a.front() == 1 && a.back() == 1) {
		for (int &i : a) i ^= 1;
		flipped = true;
	}
	
	string l(2 * n, '-'), r(2 * n, '-');
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (a[i]) {
			l[i] = (cnt) ? '(' : ')';
			r[i] = (cnt ^ 1) ? '(' : ')';
			cnt ^= 1;
		}
	}
	
	int tot = count(a.begin(), a.end(), 0) / 2;
	cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (!a[i]) {
			if (cnt < tot) l[i] = '(', r[i] = '(';
			else l[i] = ')', r[i] = ')';
			cnt++;
		}
	}
	
	if (flipped) {
		cout << 3 << endl;
		cout << l << endl;
		cout << r << endl;
		for (int i = 0; i < n; i++) cout << "()";
		cout << endl;
	} else {
		cout << 2 << endl;
		cout << l << endl;
		cout << r << endl;
	}
}

int main() {	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		solve(n, s);
	}
	
	return 0;
}
```
[1896G - Pepe Racing](../problems/G._Pepe_Racing.md)
---------------------------------------------------------------------

Writer: [thenymphsofdelphi](https://codeforces.com/profile/thenymphsofdelphi "International Grandmaster thenymphsofdelphi")

 **Hint 1**Find the fastest pepe in n+1 queries.

 **Hint**Divide n2 pepes into n groups G1,G2,…,Gn. For each group Gi, use 1 query to find the fastest pepe in the group, let's call him the *head* of Gi. Finally, use 1 query to find the fastest pepe of all the heads.

 **Hint 2**After knowing the fastest pepe, find the second fastest pepe in n+1 queries.

 **Hint**Just remove the fastest pepe and repeat the process from hint 1. One of the groups will have size n−1, but we can "steal" one non-head pepe from another already-queried group.

 **Hint 3**Note that the above process for Hint 2 uses a lot of repeated queries. Can we optimize it to 2 queries?

 **Hint**Assume that the fastest pepe is the head of Gi. After removing him, we can recalculate the head of Gi using 1 query similar to hint 2. Then, use the second query on all the heads, similar to the last query of hint 1.

 **Hint 4**Solve the problem using 2n2−n+1 queries.

 **Hint**Our algorithm has three phases:

 * Phase 1: Divide n2 pepes into n groups G1,G2,…,Gn. For each group Gi, use 1 query to find the fastest pepe in the group, let's call this guy the *head* of Gi.
* Phase 2: Until there are 2n−1 pepes, repeat these two steps:
	+ Use 1 query to find the fastest pepe of the heads of all groups, then remove him. Assume that this pepe is the head of Gi.
	+ Steal non-head pepes from other groups so that |Gi|=n, then use 1 query to recalculate its head.
* Phase 3: Until there are n−1 pepes, repeatedly find the fastest pepe using 2 queries (or 1 if there are only n pepes left), then remove him.

Total number of queries is n+2(n2−2n+1)+2(n−1)+1=2n2−n+1.

 **Solution 1**Call a pepe *slow* if it does not belong in the fastest n2−n+1 pepes. Note that there are n−1 slow pepes, and we do not care for their relative speed. After each query, we know that the fastest pepe cannot be slow.

We use the algorithm in hint 4 until there are 2n−1 pepes left. Since the head of n groups cannot be slow, we are left with exactly (2n−1)−n=n−1 candidates for slow pepes. Once we determine the n−1 slow pepes, we only need to find the ranking of the other n pepes, which can be done using n−1 queries.

Total number of queries is n+2(n2−2n+1)+(n−1)=2n2−2n+1.

 **Solution 2**We will try to decrease the number of queries based on the fact that we can omit one query for recalculation when the size of a group decreases from 2 to 1.

We modify the algorithm in hint 4 to maintain an invariant: |Gi|−|Gj|≤1 ∀1≤i<j≤n. In other words, we want to make the sizes of these groups as balanced as possible.

To maintain this, whenever we have |Gj|−|Gi|=2 after removing some pepe, we can transfer any non-head pepe from Gj to Gi to balance these groups out. Next, to recalculate the head of Gi, we will "borrow" instead of "steal" from other groups. If the fastest pepe is borrowed from Gj, then we transfer a random non-head pepe in Gi back to Gj. This works since the head of Gj is faster than the head of Gi, which in turn is faster than the random pepe.

Finally, when there are 2n pepes left, all groups have the size of 2, and we only need to use 1 query for each pepe from later on.

Total number of queries is n+2(n2−2n)+(n+1)=2n2−2n+1.

 **Implementation (Solution 1)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 30;

vector<int> buc[N];
int buc_id[N * N], buc_max[N];
int n;

int ask(vector<int> que) {
  cout << "?";
  for (int i : que) cout << ' ' << i + 1;
  cout << endl;
  int res; cin >> res;
  return res - 1;
}

int ask_all() {
  vector<int> que;
  for (int i = 0; i < n; i++)
    if (buc[i].size())
      que.push_back(buc_max[i]);
  for (int i = 0; i < n; i++)
    for (int j : buc[i])
      if (int(que.size()) < n && j != buc_max[i])
        que.push_back(j);
  return ask(que);
}

void answer(vector<int> ans) {
  cout << "!";
  for (int i : ans) cout << ' ' << i + 1;
  cout << endl;
}

void add(int id, int pepe) {
  buc[id].push_back(pepe);
  buc_id[pepe] = id;
}

void remove(int id, int pepe) {
  buc[id].erase(find(buc[id].begin(), buc[id].end(), pepe));
}

void send(int id, vector<int> &que) {
  for (int pepe : buc[id])
    if (int(que.size()) < n && pepe != buc_max[id])
      que.push_back(pepe);
}

void check_balance() {
  size_t min_size = n, max_size = 0;
  for (int id = 0; id < n; id++) {
    min_size = min(min_size, buc[id].size());
    max_size = max(max_size, buc[id].size());
  }
  assert(max_size - min_size <= 1);
}


int main() {
  cout << endl;
  int t; cin >> t;
  while (t--) {
    cin >> n;
    for (int id = 0; id < n; id++)
      buc[id].clear();
      
    for (int pepe = 0; pepe < n * n; pepe++) {
      buc_id[pepe] = pepe / n;
      buc[pepe / n].push_back(pepe);
    }
    
    for (int id = 0; id < n; id++)
      buc_max[id] = ask(buc[id]);
      
    vector<int> ans;
    
    /// balancing phase
    for (int step = 0; step < n * n - 2 * n; step++) {
      ans.push_back(ask_all());
      int last_id = buc_id[ans.back()];
      remove(last_id, ans.back());
      
      vector<int> que;
              
      for (int pepe : buc[last_id])
        que.push_back(pepe);
        
      /// find bucket with largest size != last_id
      int max_id = (last_id == 0);
      for (int id = 0; id < n; id++)
        if (id != last_id && buc[id].size() > buc[max_id].size())
          max_id = id;
          
      
      send(max_id, que);
      
      for (int id = 0; id < n; id++)
        if (id != max_id && id != last_id)
          send(id, que);
      
      buc_max[last_id] = ask(que);
      int move_id = buc_id[buc_max[last_id]];
      if (move_id != last_id) {
        remove(move_id, buc_max[last_id]);
        add(move_id, buc[last_id].back());
        remove(last_id, buc[last_id].back());
        add(last_id, buc_max[last_id]);
      }        
      
      if (buc[last_id].size() == buc[max_id].size() - 2) {
        if (move_id == max_id) {
          add(last_id, buc[move_id].back());
          remove(move_id, buc[move_id].back());
        } else {
          for (int pepe : buc[max_id])
            if (pepe != buc_max[max_id]) {
              add(last_id, pepe);
              remove(max_id, pepe);
              break;
            }
        }
      }
      
      check_balance();
    }
  
    
    for (int step = 0; step < n + 1; step++) {
      ans.push_back(ask_all());
      int last_id = buc_id[ans.back()];
      remove(last_id, ans.back());
      if (buc[last_id].size())
        buc_max[last_id] = buc[last_id][0];
    }
    
    answer(ans);
  }
}
```
 **Implementation (Solution 2)**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
vector<int> v[25];

int ask(vector<int> v){
	cout<<"? "; for (auto it:v) cout<<it<<" "; cout<<endl;
	int res; cin>>res;
	return res;
}

vector<int> fix(vector<int> v){
	int t=ask(v);
	rep(x,0,n) if (v[x]==t) swap(v[0],v[x]);
	return v;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n){
			v[x].clear();
			rep(y,1,n+1) v[x].pub(x*n+y);
		}
		
		rep(x,0,n) v[x]=fix(v[x]);
		
		vector<int> ans;
		rep(x,0,n*n-2*n+1){
			vector<int> t;
			rep(x,0,n) t.pub(v[x][0]);
			int best=ask(t);
			
			int idx=-1;
			rep(x,0,n) if (t[x]==best) idx=x;
			
			ans.pub(best);
			v[idx].erase(v[idx].begin());
			
			rep(x,0,n) if (x!=idx){
				while (sz(v[x])>1 && sz(v[idx])<n){
					v[idx].pub(v[x].back());
					v[x].pob();
				}
			}
			v[idx]=fix(v[idx]);
		}
		
		vector<int> a,b;
		rep(x,0,n){
			rep(y,0,sz(v[x])){
				if (y==0) a.pub(v[x][y]);
				else b.pub(v[x][y]);
			}
		}
		set<int> bad=set<int>(all(b));
		
		rep(x,0,n-1){
			a=fix(a);
			ans.pub(a[0]);
			a.erase(a.begin());
			a.pub(b.back()); b.pob();
		}
		
		for (auto it:a) if (!bad.count(it)) ans.pub(it);
		
		cout<<"! "; for (auto it:ans) cout<<it<<" "; cout<<endl;
	}
	
}
```
[1896H2 - Cyclic Hamming (Hard Version)](../problems/H2._Cyclic_Hamming_(Hard_Version).md)
-----------------------------------------------------------------------------------------

Writer: [xuanquang1999](https://codeforces.com/profile/xuanquang1999 "Grandmaster xuanquang1999")

 **Hint 1**For any c which is a cyclic shift of t, what will happen if h(s,c)>2k?

 **Hint 2**Try finding some useful relationship between 1-s of s and 1-s of c.

 **Hint**There are exactly n/2 positions i such that s[i]=c[i]=1.

 **Hint 3**Think about polynomial multiplication.

 **Hint 1**Consider S⋅T, where S=∑s[i]xi and T=∑t[2n−i−1]xi (reversed coefficients).

 **Hint 2**What are some properties that the coefficients of S⋅T tell us?

 **Hint**Denote A=S⋅T, we have A[xi]+A[xi+2n]=n/2.

 **Hint 3**Try factoring S⋅T into some irreducible polynomials.

 **Hint 4**Sort 0,1,…,2n−1 based on their bit-reversal values and build a binary tree on top of it. What condition should be satisfied on each level of the tree?

 **Solution**Consider the polynomial product A=S⋅T, where S=∑s[i]xi and T=∑t[2n−i−1]xi (reversed coefficients).

**Claim 1.** For all 0≤i<2n, we have A[xi]+A[xi+2n]=n/2, where A[xk] denote the coefficient of xk in A.

**Claim 2.** We can express A=(x+1)(x2+1)(x4+1)…(xn+1)(n/2+C(x−1)) where C is some polynomial with degree not greater than 2n−2.

 **Proof**(x+1)(x2+1)(x4+1)…(xn+1)(n/2+C(x−1))= C(x2n−1)+n/2⋅(x0+x1+x2+…+x2n−1)It is easy to see that this satisfies claim 1.

**Claim 3.** Since x2p+1 is cyclotomic polynomial and hence irreducible for all p, each factor in x+1,x2+1,…,xn+1 must divide at least one of S and T. And under the constraints that each of s and t must have exactly n 1-s, this condition is also sufficient.

 **Proof**Let A=(x+1)(x2+1)(x4+1)…(xn+1)⋅D. We have A(1)=n2, hence D(1)=n/2, which means that D has the form of n/2+C(x−1). Therefore A satisfies claim 2.

Recall n=2k, define fs(mask) (0≤mask<2n) as the number of string s such that for each p where p-th bit of mask is on, S is divisible by xp+1. Define ft similarly for T. Define f′t such that f′t(mask)=ft(mask⊕(2n−1)) where ⊕ denotes bitwise XOR.

The answer to the problem is ∑maskfs(mask)⋅μ(f′t(mask)) where μ denote [Mobius transform](https://codeforces.com/blog/entry/72488). The reason we need Mobius transform is that masks does not represent all divisors, just a subset of it.

Let rearrange elements of s into a new array s′ so that s′[reverse_bit(i)]=s[i] (for example, with n=8, the new order will be [0,8,4,12,2,6,10,14,1,9,5,13,3,11,7,15]). Construct a perfect binary tree based on the array s′. This binary will have k+2 levels from 0 to k+1, starting at the root.

**Claim 4.** S is divisible by x2p+1 if only if for every tree node at p-th level, the number of 1-s of s′ under both children are equal (the proof is left as an exercise for readers).

 **Hint**Group the positions by the remainder when divided by 2p, find the necessary condition for each group, and consider its position on the tree.

Consider the following dynamic programming: dps[i][mask][num], where the levels in mask satisfy claim 4 and num is the number of 1-s under i-th node on the tree. Denote l as level of i-th node, transitions are:

 * dps[i][mask][num1+num2] += dps[2i][mask][num1]⋅dps[2i+1][mask][num2]
* dps[i][mask+2l][2⋅num] += dps[2i][mask][num]⋅dps[2i+1][mask][num]

The above dp took O(n3), which is sufficient to solve the easy version.

To solve the hard version, we will optimize the above transitions:

 * The first transition is actually the convolution of dps[2i][mask] and dps[2i+1][mask], we can use FFT to optimize it.
* In the second transition, because num is multiplied by 2 every time, we can omit it and just make the transition to dps[i][mask+2l][num], reduce the length of dps[i][mask+2l] by two.

By careful analysis, we can show that the time complexity is now O(3k⋅k) (recall n=2k) with a fair constant factor, which solved the hard version.

