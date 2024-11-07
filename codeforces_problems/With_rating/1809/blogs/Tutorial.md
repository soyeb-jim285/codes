# Tutorial

[1809A - Garland](../problems/A._Garland.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1809A - Garland](../problems/A._Garland.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Note that there are only a few configuration classes: 1111, 1112, 1122, 1123 and 1234. Let's discuss each of them.

If all 4 bulbs are of the same color, then it is impossible to turn all the bulbs on, because after you switch one light bulb, it is impossible to turn the others on.

If there is a color with 3 bulbs, then it is impossible to turn all the bulbs on in 4 operations, which means there is a bulb that turns on, turns off and then turns on again, i.e. the answer is at least 6 operations. And there is a sequence of exactly 6 operations (such an example was shown in the problem notes).

For configurations like 1122 and 1123, it is enough to turn on the 1 color bulbs not in a row (i.e. in order [1,2,1,2] for the first case and [1,2,1,3] for the second one). So the answer for such configurations is 4.

If all the bulbs are of different colors, then nothing prevents you from turning them all on in 4 operations.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    vector<int> cnt(10);
    for (auto c : s) ++cnt[c - '0'];
    int mx = *max_element(cnt.begin(), cnt.end());
    if (mx == 4) cout << -1;
    else if (mx == 3) cout << 6;
    else cout << 4;
    cout << 'n';
  }
}
```
[1809B - Points on Plane](../problems/B._Points_on_Plane.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1809B - Points on Plane](../problems/B._Points_on_Plane.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Suppose, the answer is k. What's the maximum number of chips we can place? Firstly, the allowed points (x,y) to place chips are such that |x|+|y|≤k. We can group them by x-coordinate: for x=k there is only one y=0, for x=k−1 possible y are −1,0,1; for x=k−2 possible y are in segment [−2,…,2] and so on. For x=0 possible y are in [−k,…,k]. The negative x-s are the same.

Let's calculate the maximum number of chips we can place at each "row": for x=k it's 1; for x=k−1 there are three y-s, but since we can't place chips at the neighboring y-s, we can place at most 2 chips; for x=k−2 we have 5 places, but can place only 3 chips; for x=0 we have 2k+1 places, but can occupy only k+1 points.

In total, for x∈[0,…,k] we can place at most 1+2+⋯+(k+1)=(k+1)(k+2)2 chips. Analogically, for x∈[−k,…,−1] we can place at most 1+2+⋯+k=k(k+1)2 chips.

In total, we can place at most (k+1)(k+2)2+k(k+1)2=(k+1)2 chips with cost at most k. Note that (k+1)2 can actually be reached since the distance between chips on the different rows is greater than 1. 

So, to solve our task, it's enough to find minimum k such that (k+1)2≥n that can be done with Binary Search.

Or we can calculate k=⌈√n⌉−1. Note that √n can lose precision, since n is cast to double before taking the square root (for example, 975461057789971042 transforms to 9.754610577899711⋅1017=975461057789971100 when converted to double). So you should either cast long long to long double (that consists of 80 bits in some C++ compilers) or check value k+1 as a possible answer.

 **Solution 1 (adedalic)**
```cpp
fun main() {
    repeat(readln().toInt()) {
        val n = readln().toLong()
        var l = (-1).toLong()
        var r = 1e9.toLong()
        while (r - l > 1) {
            val mid = (l + r) / 2
            if (mid * mid >= n)
                r = mid
            else
                l = mid
        }
        println(r - 1)
    }
}
```
 **Solution 2 (adedalic)**
```cpp
import kotlin.math.sqrt

fun main() {
    repeat(readln().toInt()) {
        val n = readln().toLong()
        var ans = sqrt(n.toDouble()).toLong()
        while (ans * ans > n)
            ans--
        while (ans * ans < n)
            ans++
        println(ans - 1)
    }
}
```
[1809C - Sum on Subarrays](../problems/C._Sum_on_Subarrays.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1809C - Sum on Subarrays](../problems/C._Sum_on_Subarrays.md "Educational Codeforces Round 145 (Rated for Div. 2)")

There are many ways to solve this problem. I will describe the following recursive solution:

* if k<n, let's compose an array where every segment ending with the k-th element is positive, and every other segment is negative. This array can be [−1,−1,−1,…,200,−400,−1,−1,−1], where 200 is the k-th element of the array (note that when k=0, 200 doesn't belong to the array, so it consists of only negative numbers).
* but if k≥n, solve the same problem with n−1 and k−n recursively, get an array of length n−1 with k−n positive subarrays, and append 1000 to it to make all n segments ending with the last element positive.
 **Solution (BledDest)**
```cpp
def solve(n, k):
    if n == 0:
        return []
    if k < n:
        a = [-1 for i in range(n)]
        if k > 0:
            a[k - 1] = 200
        a[k] = -400
    else:
        a = solve(n - 1, k - n)
        a.append(1000)
    return a

t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    b = solve(n, k)
    print(*b)
```
[1809D - Binary String Sorting](../problems/D._Binary_String_Sorting.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1809D - Binary String Sorting](../problems/D._Binary_String_Sorting.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Note that the price of operations is much greater than the difference between them. Therefore, first of all, we have to minimize the number of operations, and then maximize the number of operations of the first type.

Swapping two elements if at least one of them will be deleted later is not optimal. Therefore, first let's delete some elements of the string, and then sort the remaining elements using swaps. The number of swaps for sorting is equal to the number of inversions (i. e. the number of pairs such that sj>si and j<i). From here we can notice that if the number of inversions is greater than 1, then there is an element that produces at least 2 inversions. So it is more profitable for us to remove it, to minimize the number of operations.

From the above we get that the number of operations of the first type is at most 1. If all operations are only of the second type, then we need to find a subsequence of the maximum length of the form 0000111111. To do this, we can iterate over the number of zeros that we include in the final string, and then add the number of ones from the remaining suffix of the string (that goes after the fixed number of zeros). If there is an operation of the first type, then it is enough to iterate over the pair that creates the inversion, to the left of it take all zeros, and to the right of it take all ones (you can notice that in fact it is enough to iterate over only a pair of neighboring elements of the string).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const long long pw10 = 1e12;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    int n = s.size();
    int cnt0 = 0, cnt1 = count(s.begin(), s.end(), '1');
    long long ans = 1e18;
    if (n == 1) ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      cnt0 += s[i] == '0';
      cnt1 -= s[i] == '1';
      int k = cnt0 + cnt1 + (s[i] == '1') + (s[i + 1] == '0');
      long long cur = (n - k) * (pw10 + 1);
      if (s[i] > s[i + 1]) cur += pw10;
      ans = min(ans, cur); 
    }
    cout << ans << 'n';
  }
}
```
[1809E - Two Tanks](../problems/E._Two_Tanks.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1809E - Two Tanks](../problems/E._Two_Tanks.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Consider a naive solution. Iterate over all pairs (c,d) and apply all operations. The complexity is O(a⋅b⋅n). The constraints obviously imply that it's too much. What can we cut from it? Well, surely O(n) will still remain there. Both of a and b also should. So we can probably only hope to turn this O(ab) into O(a+b). Let's try that.

Notice that no matter what operations are applied, c+d never changes. You can also peek at the examples and see that the patterns are suspiciously diagonal-shaped in the matrix. Let's try to solve the problem by fixing c+d and calculating the answer for all values of c.

I will call the fixed c+d variable cd. Consider case where cd≤a and cd≤b. Here, all cd can fit into both a and b, so we can avoid caring about one restriction on the operations. We'll think what to do with large volumes later.

If there are no operations, the answer for each initial c is c for all c from 0 to cd. Now consider an operation x for some x>0. For c=0, nothing changes. Actually, for all c≤x the result of the operation is the same as for c=0. Hmm, but if the result is the same, it will remain the same until the end. Same from the other side. The answers for x<0 and d≤−x also get merged together. To me it kind of looks like a primitive form of DSU on these volume states: you merge some prefix of the answers together and merge some suffix of the answers together.

If the state was merged to either c=0 or d=0, then it's easy to calculate the actual answer for that state. What happens to the remaining states? Well, since they weren't merged anywhere, the operation for them was applied fully: if x was requested, all x was poured.

How to deal with multiple operations then? I propose the following idea. When applying an operation, we only want to know which of the previously non-merged states become merged. Basically, we can squish all previous operations into one: just sum up the signed amounts of water. Since they all were applied fully to the non-merged states, it's completely valid. After the squish, check for the new merges.

You can actually study the structure of the answers and see that they go like that: [l,l,…,l,l+1,l+2,…,r−1,r,…,r,r] for some values of l and r such that l≤r. It isn't that important, but it makes the code easier. You can basically calculate the length of the merged prefix, the length of the merged suffix, then calculate the answer at the end of the prefix in O(n) and restore all answers from it.

We neglected larger values of cd earlier, time to return to them. Another kind of limit to each operation is added: when x extra water doesn't fit in another tank. Well, it doesn't change that much. It only makes more prefix/suffix merges. To come up with the exact formulas, I followed these points. Something merges on an operation x, when any of these holds: 

* c<x (not enough water in the first tank);
* b−d<x (not enough space in the second tank);
* d<−x (not enough water in the second tank);
* a−c<−x (not enough space in the first tank).

Replace all d with cd−c, and you get the constraints for prefix and suffix merges.

Overall complexity: O(n⋅(a+b)).

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	vector<int> v(n);
	forn(i, n) scanf("%d", &v[i]);
	vector<vector<int>> ans(a + 1, vector<int>(b + 1));
	forn(cd, a + b + 1){
		int l = max(0, cd - b), r = min(a, cd);
		int sum = 0;
		for (int x : v){
			sum += x;
			l = max({l, sum, cd + sum - b});
			r = min({r, a + sum, sum + cd});
		}
		if (l > r) l = r = max(0, cd - b);
		int res = l;
		for (int x : v){
			if (x > 0)
				res -= min({res, x, b - (cd - res)});
			else
				res += min({cd - res, -x, a - res});
		}
		forn(c, cd + 1) if (c <= a && cd - c <= b){
			ans[c][cd - c] = (c < l ? res : (c > r ? res + r - l : res + c - l));
		}
	}
	forn(i, a + 1){
		forn(j, b + 1)
			printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}
```
[1809F - Traveling in Berland](../problems/F._Traveling_in_Berland.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial (Neon)**
### [1809F - Traveling in Berland](../problems/F._Traveling_in_Berland.md "Educational Codeforces Round 145 (Rated for Div. 2)")

The problem has a rather obvious naive solution in O(n) for each starting city, but it's too slow. So we have to speed up this solution somehow. Binary lifting is one of the options, but here we have a problem that it is difficult to connect two consecutive groups of steps, because after the first group there is a certain amount of fuel left. Therefore, one of the solutions is to switch to such steps that 0 liters of fuel remains after it.

Let's consider one of such "greedy" steps. Suppose we are in the city i with 0 fuel, then the following situations are possible: 

* bi=2, let's buy exactly ai liters of fuel to reach the next city, then the step length is 1 and the cost is 2ai;
* bi=1 and cnt=0 (where cnt is the maximum number such that bi+1=2, bi+2=2, ..., bi+cnt=2, i.e. the number of consecutive cities with the cost 2), let's buy exactly ai liters of fuel to reach the next city, then the step length is 1 and the cost is ai;
* bi=1 and cnt>0, let's find a minimum j such that sum=ai+ai+1+⋯+aj≥k and j≤i+cnt (i.e. such j that you can reach it by spending all k of liters):
	+ sum≤k, let's buy exactly sum liters with the cost 1 in the city i, then the step length is j−i+1 and the cost is sum;
	+ sum>k, let's buy k liters with the cost 1 in the city i, and the remainder of sum−k liters with the cost 2 in the city j, then the step length is j−i+1 and the cost is k+2(sum−k).

Now using these types of steps, we maintain an important invariant — after each step, the amount of fuel is 0. So we can easily calculate the total distance and cost for several consecutive steps. Which leads us to a solution using binary lifting: for each city i calculate the length and cost of the path with 2pw (for all pw up to logn) greedy steps. And then, using this data, we can calculate the answer for each starting city in O(logn).

 **Solution (awoo)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

void solve(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	vector<int> b(n);
	forn(i, n) scanf("%d", &b[i]);
	
	vector<long long> pr(2 * n + 1);
	forn(i, 2 * n) pr[i + 1] = pr[i] + a[i % n];
	
	vector<long long> dist(n);
	vector<long long> cost(n);
	int cnt = 0;
	for (int i = 2 * n - 1; i >= 0; --i){
		if (i < n){
			if (b[i] == 2){
				dist[i] = 1;
				cost[i] = a[i] * 2;
			}
			else if (cnt == 0){
				dist[i] = 1;
				cost[i] = a[i];
			}
			else{
				int j = lower_bound(pr.begin() + i, pr.begin() + i + cnt + 1, pr[i] + k) - pr.begin();
				assert(j > i);
				dist[i] = j - i;
				if (pr[j] - pr[i] <= k)
					cost[i] = pr[j] - pr[i];
				else
					cost[i] = 2 * (pr[j] - pr[i]) - k;
			}
		}
		if (b[i % n] == 2) ++cnt;
		else cnt = 0;
	}
	
	int pw = 0;
	while ((1 << pw) <= n) ++pw;
	
	vector<vector<long long>> distk(pw, dist);
	vector<vector<long long>> costk(pw, cost);
	for (int j = 1; j < pw; ++j) forn(i, n){
		distk[j][i] = distk[j - 1][i] + distk[j - 1][(i + distk[j - 1][i]) % n];
		costk[j][i] = costk[j - 1][i] + costk[j - 1][(i + distk[j - 1][i]) % n];
	}
	
	forn(i, n){
		int pos = i;
		long long tot = 0;
		long long ans = 0;
		for (int j = pw - 1; j >= 0; --j) if (tot + distk[j][pos] <= n){
			tot += distk[j][pos];
			ans += costk[j][pos];
			pos = (pos + distk[j][pos]) % n;
		}
		if (tot < n) ans += pr[i + n] - pr[i + tot];
		printf("%lld ", ans);
	}
	puts("");
}

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) solve();
}
```
[1809G - Prediction](../problems/G._Prediction.md "Educational Codeforces Round 145 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1809G - Prediction](../problems/G._Prediction.md "Educational Codeforces Round 145 (Rated for Div. 2)")

We need some sort of better criterion other than "all matches can be predicted" first. Suppose the ratings of the participants are r1,r2,…,rn in the order of their indices. Then, if all games are predictable, the i-th game should be won by the participant with the rating equal to i+1maxj=1rj; and in the (i+1)-th game, they will play against the participant with rating ri+2. So, in order for each game to be predictable, the maximum on each prefix should be different from the next element by at least k+1. This is the criterion we will use.

So, we will try to count the number of orderings meeting this condition. One very important observation we need to make is that, if we remove several participants with the lowest ratings from the ordering, that ordering still satisfies the condition (for each element, either the prefix before it is removed completely, or the maximum on it is unchanged). So, this allows us to construct the correct ordering by placing the sportsmen from the maximum rating to the minimum rating, and making sure that on every step, the order stays correct.

Okay. Let's reverse the ratings array, and try to write the following dynamic programming: dpi is the number of correct orderings of the first i sportsmen (the i highest-rated sportsmen, since we reversed the ratings array). Let's try to place the next sportsman. We run into the following issue: for some orderings of the first i sportsmen, it is possible to place the next one anywhere (these orderings are where the first sportsman in the ordering doesn't conflict with the sportsman we are trying to place); but for other orderings, some positions might be forbidden. And to keep track of which positions are forbidden, and for which sportsmen, we probably need some additional states for the dynamic programming, which we don't really want to since O(n) states is probably the most we can allow.

Okay, so let's avoid this issue entirely. We don't like the orderings where the next sportsman can't be placed anywhere, so let's find a way to "ignore" them:

* discard the previous definition of dpi. Now, let dpi is the number of correct orderings of the i highest-rated sportsmen where the first element in the ordering doesn't conflict with any of the elements we haven't placed yet;
* when we place the next sportsman, in case it becomes the first element and conflicts with some of the elements we haven't placed yet, we place those conflicting elements as well.

So, this leads to the following transitions in the dynamic programming:

* if we place the (i+1)-th sportsman on any position other than the first one, there are i ways to do it, and we transition from dpi to dpi+1;
* otherwise, if we place the (i+1)-th sportsman on the first position, let f(i+1) be the last sportsman "conflicting" with the sportsman i+1. Let's try placing all sportsmen from i+2 to f(i+1) before placing the sportsman i+1. They cannot be placed on the first position (otherwise they will conflict either with each other or with the sportsman i+1), so the first one can be placed in i ways, the second one — in (i+1) ways, and so on; this product can be easily calculated in O(1) by preparing factorials and inverse factorials. So, then we transition from dpi to dpf(i+1).

There is a special case in our dynamic programming. It should start with dp1=1, but what if the 1-st sportsman conflicts with someone? Then the ordering of the first i=1 sportsmen is incorrect. In this case, the answer is 0 since the 1-st and the 2-nd sportsmen are conflicting.

Overall complexity of this solution is O(nlogMOD) or O(n+logMOD) depending on your implementation.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;   
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);    
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for(int i = 0; i < n; i++)    
        scanf("%d", &a[i]);
    
    reverse(a.begin(), a.end());

    vector<int> fact(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = mul(fact[i - 1], i);

    // for each player, we find the first player which doesn't conflict with them
    vector<int> first_no_conflict(n);
    for(int i = 0; i < n; i++)
    {
        if(i) first_no_conflict[i] = first_no_conflict[i - 1];
        while(first_no_conflict[i] < n && a[first_no_conflict[i]] >= a[i] - k)
            first_no_conflict[i]++;
    }

    vector<int> dp(n + 1);
    if(a[0] - a[1] > k) dp[1] = 1;
    for(int i = 1; i < n; i++)
    {
        // first choice: put a[i] on the first position
        // then we put all which conflict with a[i] on any position other than 1
        int no_of_conflicting = first_no_conflict[i] - i - 1;
        // put all conflicting with a[i] on any position other than 1
        // the first one chooses from i positions, the second - from i+1 positions, and so on
        // so the number of ways is fact[i + no_of_conflicting - 1] / fact[i - 1]
        dp[i + no_of_conflicting + 1] = add(dp[i + no_of_conflicting + 1], mul(dp[i], divide(fact[i + no_of_conflicting - 1], fact[i - 1])));

        // second choice: put a[i] on any other position
        dp[i + 1] = add(dp[i + 1], mul(dp[i], i));
    }

    printf("%dn", dp[n]);
}
```
