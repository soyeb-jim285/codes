# Tutorial_(en)

Thank you for participating! We put a lot of effort into this contest. Special thanks to [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse") for contributing to these problems.

 **Rating Predictions**

| Person | A | B | C1 | C2 | D | E | F | G | H |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [oursaco](https://codeforces.com/profile/oursaco "International Master oursaco") | 800 | 1200 | 1500 | 1800 | 2200 | 2400 | 2800 | 2700 | 3400 |
| [priyanshu.p](https://codeforces.com/profile/priyanshu.p "Expert priyanshu.p") | 800 | 1200 | 1300 | 1600 | 2200 |  |  |  |  |
| [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse") | 800 | 1200 | 1400 | 1700 | 2100 | 2300 | 2900 | 2900 | 3500 |
| [cry](https://codeforces.com/profile/cry "Candidate Master cry") | 800 | 1000 | 1300 | 1700 | 2100 | 2200 | 2800 | 2900 | 3500 |
| [buffering](https://codeforces.com/profile/buffering "Expert buffering") | 800 | 1000 | 1500 | 1900 | 2100 | 2200 | 2700 | 2800 | 3500 |
| [JagguBandar](https://codeforces.com/profile/JagguBandar "Master JagguBandar") | 800 | 1200 | 1700 | 2000 | 1800 | 2300 |  |  |  |
| [omeganot](https://codeforces.com/profile/omeganot "Master omeganot") | 900 | 1000 | 1400 | 1800 | 2200 | 2300 | 2600 |  |  |
| [drdilyor](https://codeforces.com/profile/drdilyor "Master drdilyor") | 800 | 1300 | 1500 | 1800 | 2100 | 2200 |  |  |  |
| [jay_jayjay](https://codeforces.com/profile/jay_jayjay "Master jay_jayjay") | 900 | 1400 | 1300 | 1600 | 1800 | 2300 | 2600 | 2800 | 3500 |
| [chromate00](https://codeforces.com/profile/chromate00 "Expert chromate00") | 900 | 1300 | 1400 | 1700 | 2200 | 2400 | 2700 | 2900 | 3400 |
| [maxrgby](https://codeforces.com/profile/maxrgby "Candidate Master maxrgby") | 800 | 1200 | 1300 | 1700 | 2100 |  |  |  |  |
| [SunShine11](https://codeforces.com/profile/SunShine11 "Expert SunShine11") | 800 | 1300 | 1500 | 1800 | 2100 |  |  |  |  |
| [MridulAhi](https://codeforces.com/profile/MridulAhi "Master MridulAhi") | 800 | 1200 | 1500 | 2000 | 1900 | 2200 | 2600 | 2800 |  |
| [WAtoAC2001](https://codeforces.com/profile/WAtoAC2001 "Master WAtoAC2001") | 800 | 1300 | 1600 | 2000 | 2300 |  |  | 2800 |  |
| [rainboy](https://codeforces.com/profile/rainboy "Master rainboy") |  |  |  |  | 2100 | 2400 | 2800 | 2700 | 3400 |
| [Geothermal](https://codeforces.com/profile/Geothermal "Legendary Grandmaster Geothermal") | 800 | 900 | 1300 | 1700 | 1800 | 2300 | 2600 | 2800 | 3500 |
| [lethan3](https://codeforces.com/profile/lethan3 "Master lethan3") | 800 | 1100 | 1500 | 1900 | 2200 |  |  |  |  |
| [awesomeguy856](https://codeforces.com/profile/awesomeguy856 "Master awesomeguy856") | 800 | 1200 | 1000 | 1500 | 2100 | 2100 |  | 2400 |  |
| [camc](https://codeforces.com/profile/camc "Master camc") | 800 | 1100 | 1500 | 1900 | 2100 | 2200 |  |  |  |
| [rqi](https://codeforces.com/profile/rqi "International Grandmaster rqi") | 1000 | 1500 | 1600 | 1900 | 2000 | 2300 | 2700 |  |  |
| [sum](https://codeforces.com/profile/sum "Master sum") |  |  |  |  | 2000 | 2200 | 2600 |  |  |

 

|  | A | B | C1 | C2 | D | E | F | G | H |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Average | 811 | 1189 | 1455 | 1810 | 2100 | 2273 | 2709 | 2770 | 3463 |
| Actual | 800 | 1100 | 1300 | 1700 | 2100 | 2300 | 2700 | 2800 | 3500 |

#### Solutions

##### [1942A - Farmer John's Challenge](../problems/A._Farmer_John's_Challenge.md)

Problem Credits: [buffering](https://codeforces.com/profile/buffering "Expert buffering")   
Analysis: [buffering](https://codeforces.com/profile/buffering "Expert buffering")

 **Hint 1**Solve for k=1.

 **Answer**a=1,2,3…n works. Why?

 **Hint 2**Solve for k=n.

 **Answer**a=1,1,1…1 works. Why?

 **Hint 3**What other k work for a given n?

 **Answer**Only k=1 and k=n have possible answers.

 **Solution**Read the hints.

For k=1, the construction 1,2,3…n will always work because in any other cyclic shift, n will be before 1. 

Now, consider what happens if we want to find an array with two or more cyclic shifts that are sorted. If we consider two of these cyclic shifts, notice they are actually shifts of each other as well.

So, there should be a sorted array, and a shift of it which is also sorted. What this means is that some of the first elements in the array move to the back and stays sorted, which can **only happen if all values in the array are equal.**

If the array has all equal values, this gives us our construction for k=n. As we have seen, for k>1, only k=n is possible. Thus, for any other k not equal to 1 or n, we can print −1.

 **Code (C++)**
```cpp
#include <iostream>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		if(k == 1) for(int i = 0; i < n; i++) cout << i + 1 << " ";
		else if(k == n) for(int i = 0; i < n; i++) cout << 1 << " ";
		else cout << -1;
		cout << "n";
	}
}
```
##### [1942B - Bessie and MEX](../problems/B._Bessie_and_MEX.md)

Problem Credits: [buffering](https://codeforces.com/profile/buffering "Expert buffering")   
Analysis: [buffering](https://codeforces.com/profile/buffering "Expert buffering")

Solution 1

 **Hint 1**We will construct the solution forward.

 **Hint 2**Separate the ai's given into negative and positive cases. What does this tell us about the MEX?

 **Solution**We can find p1,p2,...,pn in order, looking at positive and negative cases. Note that ai≠0 because pi would equal MEX(p1…pi), which can never happen.

 * If ai>0, then MEX(p1,p2,...pi) must increase from MEX(p1,p2,...pi−1), so we know pi must equal MEX(p1,p2,...pi−1).
* Otherwise, the MEX stays the same, so pi is just simply MEX(p1,p2,...pi−1) — ai.

Thus, we can just maintain the MEX and find each pi as we go forward.

 **Here's more justification about specific differences leading to specific MEX changes**There are only 2 things the MEX can do: increase or stay the same (it can never decrease since larger prefixes contain smaller ones).

 * In the case of a positive difference, consider what would happen if the MEX stayed the same. Since the difference is positive, the MEX would have to be greater than the current value, which is impossible because that value had to appear earlier on in the prefix. Since the MEX is calculated on a permutation that can’t happen. So the MEX has to increase.

 * In the case of a negative value, the MEX has to be less than the current value. But if it increased that means the current value changed its the MEX, meaning its the MEX is now at least (current value + 1) and it is actually greater. So it has to stay the same.
Note that this is also a way to show p is always unique.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for(int& i: a) cin >> i;
	vector<int> p(n), has(n + 1);
	int mex = 0;
	for(int i = 0; i < n; i++){
		if(a[i] >= 0){
			p[i] = mex;
		}
		else{
			p[i] = mex - a[i];
		}
		has[p[i]] = true;
		while(has[mex]) mex++;
	}
	for(int i: p) cout << i << " ";
	cout << "n";
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
}

/*   /_/
*   (= ._.)
*   / >  >
*/
```
Solution 2

 **Hint 1**We will construct the solution backwards.

 **Hint 2**The MEX is determined at the last index, since all of 0,1…n−1 appear in p.

 **Solution**Read the hints.

Since we know the MEX of the last position is n, then n−pn=an. From this equation, we can find that pn=n−an. 

Now, because we know pn, we can determine the MEX of the first n−1 numbers. Like how we found pn, we can do a similar process for finding pn−1. Doing this for i=n,n−1…1 will get us a valid answer p.

Note that this is also a way to show p is always unique.

##### [1942C1 - Bessie's Birthday Cake (Easy Version)](../problems/C1._Bessie's_Birthday_Cake_(Easy_Version).md) and [1942C2 - Bessie's Birthday Cake (Hard Version)](../problems/C2._Bessie's_Birthday_Cake_(Hard_Version).md)

Problem Credits: [cry](https://codeforces.com/profile/cry "Candidate Master cry")   
Analysis: [cry](https://codeforces.com/profile/cry "Candidate Master cry")

 **Solution (Easy Version)**Ignoring n for now, let's just focus on the x chosen vertices. Sort the x vertices and connect adjacent vertices to form its own smaller polygon. By drawing out some cases or if you're familiar with triangulation ([video that proves by induction](https://codeforces.com/https://www.youtube.com/watch?v=2x4ioToqe_c)), you can form x−2 triangles by drawing diagonals in a polygon with x vertices. If you don't know it, one possible construction that always work is fixing one vertex v and drawing diagonals to every other vertex not adjacent to v. Now, let's consider the original n-sided polygon. In additional to the aforementioned construction, to close the x-sided polygon up: for every non-adjacent vertex in the chosen vertices based on the bigger n-sided polygon, draw a diagonal between them. Through this construction, we can always guarantee x−2 triangles. 

However, this doesn't account for all triangles, as some triangles can form sides with the bigger n-sided polygon. These triangles occur exactly when two adjacent vertex in x have exactly one vertex not in x between them but part of the bigger polygon. This is because one side is from the diagonals we drew, and the other two sides form from the n-sided polygon.

Therefore, the answer is x−2 + (number of adjacent chosen vertices 2 apart). Note that the first chosen vertex is also adjacent to last chosen vertex in x.

 **Solution (Hard Version)**Read the solution to the easy version first.

We can now reduce the problem to the following: For every vertex we choose, we can make one more triangle. For every chosen vertices two apart, we can make one more triangle. Let's focus on the latter condition. To maximize the effect of our y vertices, we want to prioritize vertices v that satisfy the following: the vertex is not included in x and there is a chosen vertex two apart. Let's denote such v as good.

Let vertex a and b (a<b) be adjacent chosen vertices in the x-sided polygon. There are g=b−a−1 vertices for us to choose between them. There are two cases: if g is odd, then we can choose ⌊g2⌋ vertices to form ⌊g2⌋+1 extra triangles. This is because all of the vertices we choose will be good. if g is even, then we can choose g2 vertices to make g2 extra triangles. This is because one of the vertices we choose will not be good. This shows that it is always optimal to process smaller and odd g first. 

After processing these adjacent gaps, if we have any leftover vertices, we can just ignore them. This is because since we have maximized the number of good vertices, even though any further vertex we place will increase the answer by 1, it will break two good vertices which will decrease the answer by 1.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, x, y; cin >> n >> x >> y;
	int initial_y = y;
	vector<int> chosen(x);
	for(int& i: chosen) cin >> i;
	sort(chosen.begin(), chosen.end());
	int ans = x - 2;
	int triangles_from_even_g = 0;
	vector<int> odd_g;
	auto process_gap = [&](int g) -> void{
		if(g <= 1){
			// already two apart
			ans += g;
		}
		else if(g % 2 == 1){
			odd_g.push_back(g / 2);
		}
		else{
			triangles_from_even_g += g / 2;
		}
	};
	for(int i = 0; i < x - 1; i++){
		process_gap(chosen[i + 1] - chosen[i] - 1);
	}
	process_gap((chosen[0] + n) - chosen[x - 1] - 1);
	sort(odd_g.begin(), odd_g.end());
	for(int g: odd_g){
		if(y >= g){
			// all vertices are good, so we can make g + 1 triangles
			ans += g + 1;
			y -= g;
		}
		else{
			ans += y;
			y = 0;
			break;
		}
	}
	int even_triangles = min(triangles_from_even_g, y);
	y -= even_triangles;
	ans += even_triangles;
	int used_vertices = initial_y - y;
	ans += used_vertices;
	cout << ans << "n";
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
}

/*   /_/
*   (= ._.)
*   / >  >
*/
```
#### [1942D - Learning to Paint](../problems/D._Learning_to_Paint.md)

Problem Credits: [sum](https://codeforces.com/profile/sum "Master sum")   
Analysis: [sum](https://codeforces.com/profile/sum "Master sum")

 **Hint 1**We can solve this with dynamic programming. Let dp[i] store a list of all min(k,2i) highest beauties of a painting in **non-increasing** order if you only paint cells 1,2,…,i. 

 **Hint 2**Transitioning boils down to finding the k largest elements from n **non-increasing** lists. Try to do this in O((n+k)logn) time.

 **Solution**Let dp[i] store a list of all min(k,2i) highest beauties of a painting in **non-increasing** order if you only paint cells 1,2,…,i. 

Let's define **merging** two lists as creating a new list that stores the k highest values from the two lists. 

First, let's look at a slow method of transitioning. We iterate over the left endpoint l such that l…i is a maximal painted interval. At each l, we merge dp[l−2], with al,i added to each value, into dp[i]. We also merge dp[i−1] into dp[i] to handle the case in which we do not paint cell i. If implemented well, transitioning takes O(nk) time leading to an O(n2k) solution which is too slow.

We can speed this up. This merging process boils down to finding the k largest elements from n **non-increasing** lists in O((n+k)logn) time. We can use a priority queue that stores (element,index) for each list. We can do the following k times: add the top of the priority queue to our answer, advance its index, and update the priority queue accordingly. This allows us to transition in O((n+k)logn) time which leads to an O((n2+nk)logn) solution.

Bonus: find an O(n2+k) solution.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, k;
    cin >> n >> k;
 
    int A[n + 1][n + 1];
 
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cin >> A[i][j];
    
    // dp[i] = Answer if we consider 1...i
    vector<int> dp[n + 1];
    dp[0] = {0};
 
    for (int i = 1; i <= n; i++){
        priority_queue<array<int, 3>> pq;
 
        // Don't create an interval
        pq.push({dp[i - 1][0], i - 1, 0});
 
        // Create interval j+2...i (transition from j)
        for (int j = i - 2; j >= -1; j--){
            pq.push({(j < 0 ? 0 : dp[j][0]) + A[j + 2][i], j, 0});
        }
 
        while (pq.size() and dp[i].size() < k){
            auto [val, j, num] = pq.top(); pq.pop();
            dp[i].push_back(val);
            
            if (j < 0 or num + 1 >= dp[j].size())
                continue;
            
            // Don't create interval
            if (j == i - 1)
                pq.push({dp[i - 1][num + 1], i - 1, num + 1});
            
            // Create interval j+2...i (transition from j)
            else 
                pq.push({dp[j][num + 1] + A[j + 2][i], j, num + 1});
        }
    }
    for (int i : dp[n])
        cout << i << " ";
    cout << "n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int tc; 
    cin >> tc;
 
    while (tc--) 
        solve();
}
```
#### [1942E - Farm Game](../problems/E._Farm_Game.md)

Problem Credits: [cry](https://codeforces.com/profile/cry "Candidate Master cry")   
Analysis: [sum](https://codeforces.com/profile/sum "Master sum")

 **Hint 1**Think about the gaps between (a1,b1),(a2,b2),...,(an,bn). Let the gaps be g1,g2,...,gn. What effect do the moves have on the gaps?

 **Hint 2**WLOG let the first cow be FJ's cow. FN wins if all gi are even. Otherwise FJ wins. Note that the game will always end.

 **Hint 3**Try to count the number of ways FN wins. We can iterate over the sum of gi and use stars and bars as well as other counting techniques.

 **Solution**Consider the gaps between (a1,b1),(a2,b2),...,(an,bn). In the example below, 'a' represents FJ's cow, 'b' represents FN's cow, and '.' represents an empty space. The gaps are [2,3].

 |.a..b....a...b.|Consider the gaps g1,g2,...,gn. When a farmer moves, they choose some non-empty subset of non-zero gi and add or subtract 1 from every element in the subset (so long such move is possible). The game ends when some farmer cannot move (which implies that all gi must be 0 when the game ends).

WLOG let the first cow be FJ's cow. The winner of the game is determined as follows:

1) If all gi are even, then FN wins. If FJ pushes the cows corresponding to gaps i1,i2,…,ik some direction in a move, then gi1,gi2,…gik will change by 1 and become odd. FN can then push the cows corresponding to gaps i1,i2,…,ik **left** so that gi1,gi2,…gik will become even again. Therefore, all gi will be even when it's FJ's turn and at least one gi will be odd when it's FN's turn. Since the game ends when all gi are 0 (which is even), then FJ will lose. **Note that the game will always end.** This is since the sum of positions of FN's cows will always be decreasing since FN will always push some cow left.

2) Otherwise, FJ wins since he can subtract 1 to all odd gi in his first move to make all elements even. Then it's FN's turn and all gi are even so by the reasoning above, FJ wins.

Let's use complementary counting and determine the number of ways **FN** wins (which is when all gi are even). We can iterate over the sum, s (s is even), of all gi. At each s, we can use stars and bars to find how many such g1,g2,...,gn (all gi are even) sum to s. Specifically, the number of ways are (s2+n−1n−1). The number of ways to place the cows in the available positions given the gaps will be 2⋅(l−s−nn). We multiply by 2 since we can alternate starting with either FJ's cow or FN's cow. 

Finally, we subtract this result from the total number of configurations, 2⋅(l2⋅n), to get the number of ways FJ wins. This runs in O(l) time.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 2e6 + 5, MOD = 998244353;

ll fact[MAX], ifact[MAX];

ll bpow(ll a, int p){
    ll ans = 1;

    for (;p; p /= 2, a = (a * a) % MOD) 
        if (p & 1) 
            ans = (ans * a) % MOD;

    return ans;
}
ll ncr(int n, int r){
    if (n < 0)
        return 0;
    if (r > n)
        return 0;

    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}
void solve(){
    int l, n;
    cin >> l >> n;
 
    ll all_even = 0;
 
    for (int s = 0; s <= l; s += 2){
        all_even += 2 * ncr(s / 2 + n - 1, n - 1) % MOD * ncr(l - s - n, n) % MOD;
        all_even %= MOD;
    }
    cout << (2 * ncr(l, 2 * n) % MOD - all_even + MOD) % MOD << "n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    for (int i = 0; i < MAX; i++)
        fact[i] = !i ? 1 : fact[i - 1] * i % MOD;
    
    for (int i = MAX - 1; i >= 0; i--)
        ifact[i] = (i == MAX - 1) ? bpow(fact[MAX - 1], MOD - 2) : ifact[i + 1] * (i + 1) % MOD;

    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
```
#### [1942F - Farmer John's Favorite Function](../problems/F._Farmer_John's_Favorite_Function.md)

Problem Credits: [sum](https://codeforces.com/profile/sum "Master sum")   
Analysis: [sum](https://codeforces.com/profile/sum "Master sum")

 **Hint 1**Consider the case where all f(i) are integers. Decreasing **any** ai will decrease ⌊f(n)⌋. So solutions that iterate over the last few elements will not work.

 **Hint 2**If n≥6, changing a1 will only affect ⌊f(n)⌋ by at most 1.

 **Hint 3**We can take the floor each time we square root. Specifically, we can define f as:

 * f(1)=⌊√a1⌋
* For all i>1, f(i)=⌊√f(i−1)+ai⌋

This allows us to work with integers.

 **Hint 4**We can divide our array into blocks of size b≥6 (note that the value of b depends on the solution). How can we use hint 2? What should we store for each block?

 **Solution**Let's first look at the impact of earlier numbers on the final result. Earlier numbers can still influence ⌊f(n)⌋ when n is large. Suppose that all f(i) are integers. Then decreasing **any** ai will decrease ⌊f(n)⌋. 

However, it is clear that the impact of earlier number on ⌊f(n)⌋ is still extremely small. A key observation is that when n≥6, changing a1 will only affect ⌊f(n)⌋ by at most 1.

Another observation is that we can take the floor each time we square root. Specifically, we can define f as:

 * f(1)=⌊√a1⌋
* For all i>1, f(i)=⌊√f(i−1)+ai⌋

This allows us to work with integers. From here on, we work with this new definition of f.

Let's divide our array into blocks of size b=6. We can append zeroes to the front of the array to make n a multiple of b. 

Consider some block representing range [l,r]. Let's consider the subarray al,al+1,…,ar. Let v be the value of f(r) if we let f(l−1)=0. Using our first observation, we know that f(r) will be either v or v+1 depending on f(l−1). So let's find the smallest value c such that if f(l−1)=c, then f(r)=v+1. This can be done by iterating over the elements of the block backwards.

For each block, we store its corresponding (v,c). We can build a segment tree over the blocks for an O((n+q)logn) solution. 

Alternatively, we can do square root decomposition by having b=√n which leads to an O(n+q√n) solution (in practice, we should set b to something small like 100).

 **Code (C++)****Segment Tree**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>

const int B = 6, MAX = 2e5 + B + 5;

int n, q, offset, numBlocks; ll A[MAX]; pll seg[MAX];

pll comb(pll a, pll b){
    auto [vl, cl] = a;
    auto [vr, cr] = b;

    // Not defined
    if (vl == -1)
        return b;
    if (vr == -1)
        return a;

    // Doesn't cross cutoff
    if (vl < cr - 1)
        return {vr, (ll)2e18};
    if (vl >= cr)
        return {vr + 1, (ll)2e18};
    
    // If vl == cr - 1
    return {vr, cl};
}
void updSeg(int i, pll v){
    seg[i += numBlocks] = v;

    for (i /= 2; i > 0; i /= 2) 
        seg[i] = comb(seg[i * 2], seg[i * 2 + 1]);
}
ll qry(int l = 0, int r = numBlocks - 1){ 
    pll retL = {-1, -1};
    pll retR = {-1, -1};

    for (l += numBlocks, r += numBlocks; l <= r; r /= 2, l /= 2){
        if (l % 2 == 1) 
            retL = comb(retL, seg[l++]);
        if (r % 2 == 0) 
            retR = comb(seg[r--], retR);
    }
    return comb(retL, retR).first;
}
void updBlock(int blk){
    int l = blk * B;
    int r = l + B - 1;

    ll val = 0;
    for (int i = l; i <= r; i++)
        val = floor(sqrtl((long double)val + A[i]));
    
    ll req = val + 1;
    for (int i = r; i >= l; i--){
        if (req > 2e9){
            updSeg(blk, {val, (ll)2e18});
            return;
        }
        req = req * req - A[i];
    }
    updSeg(blk, {val, req});
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cin >> n >> q;

    offset = (B - n % B) % B;
    n += offset;
    numBlocks = n / B;

    for (int i = offset; i < n; i++)
        cin >> A[i];
    
    for (int b = 0; b < numBlocks; b++)
        updBlock(b);

    while (q--){
        ll k, x;
        cin >> k >> x;
        k--; 
        k += offset;

        A[k] = x;
        updBlock(k / B);

        cout << qry() << "n";
    }
}
```
 **Square Root Decomposition**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int B = 100, MAX = 2e5 + B + 5;

int n, q, offset, numBlocks; ll A[MAX], val[MAX], cut[MAX];

void buildBlock(int blk){
    int l = blk * B;
    int r = l + B - 1;

    ll cur = 0;

    for (int i = l; i <= r; i++)
        cur = floor(sqrtl((long double)cur + A[i]));
    
    val[blk] = cur;

    ll req = cur + 1;

    for (int i = r; i >= l; i--){
        if (req > 2e9){
            cut[blk] = 2e18;
            return;
        }
        req = req * req - A[i];
    }
    cut[blk] = req;
}
ll qry(){
    ll cur = 0;

    for (int b = 0; b < numBlocks; b++)
        cur = (cur >= cut[b]) ? val[b] + 1 : val[b];
    
    return cur;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cin >> n >> q;

    offset = (B - n % B) % B;
    n += offset;
    numBlocks = n / B;

    for (int i = offset; i < n; i++)
        cin >> A[i];
    
    for (int b = 0; b < numBlocks; b++)
        buildBlock(b);

    while (q--){
        ll k, x;
        cin >> k >> x;
        k--; 
        k += offset;

        A[k] = x;
        buildBlock(k / B);

        cout << qry() << "n";
    }
}
```
#### [1942G - Bessie and Cards](../problems/G._Bessie_and_Cards.md)

Problem Credits: [smax](https://codeforces.com/profile/smax "Grandmaster smax")   
Analysis: [smax](https://codeforces.com/profile/smax "Grandmaster smax")

 **Hint 1**"Draw 1" cards do not matter because we can immediately play them when we draw them.

 **Hint 2**Treat "draw 2" as +1 and "draw 0" as −1. We start with a balance of +5. We draw all the cards up to the first prefix where the balance dips to 0. We are interested in the number of ways where the special cards lie in this prefix.

 **Solution**Read the hints.

Treat the special cards as "draw 0" cards and multiply by the appropriate binomial coefficient at the end. Also treat cards of the same type as indistinguishable and multiply by the appropriate factorials at the end.

Enumerate the length of the prefix where the balance first hits 0. This dictates how many +1 and −1 we have. Now we want to count the number of ways of arranging +1 and −1 such that the balance never dips to 0, assuming we start with +5.

To solve this subproblem, we can draw inspiration from the [path counting interpretation](https://codeforces.com/https://en.wikipedia.org/wiki/Catalan_number#Second_proof) for counting balanced bracket sequences. We have n open and n close brackets and want to count the number of balanced bracket sequences starting with `((((` (note that there are only 4 instead of 5 open brackets to shift from all balances being strictly positive to all balances being non-negative). The number of sequences ignoring the balance constraint is (2n−4n). Any bracket sequence where some balance dips negative corresponds to a path that walks above the line y=x. For those paths, we reflect over the line y=x+1 at the first point where it steps over the line. So there is a bijection between these paths and paths that reach the point (n−1,n+1), of which there are (2n−4n+1). So the total number of ways is (2n−4n)−(2n−4n+1).

Our final answer is summing up the number of ways over all prefix lengths. Make sure to handle the case where you draw the entire deck correctly. The complexity is O(min(a,c)).

 **Code (C++)**
#### [1942H - Farmer John's Favorite Intern](../problems/H._Farmer_John's_Favorite_Intern.md)

Problem Credits: [oursaco](https://codeforces.com/profile/oursaco "International Master oursaco")   
Analysis: [oursaco](https://codeforces.com/profile/oursaco "International Master oursaco") / [rainboy](https://codeforces.com/profile/rainboy "Candidate Master rainboy")

 **Solution 1**Model this as a flow problem where growth events are an input of some flow to a node and harvest events and the necessary amount of fruits are an output of flow to the sink. We will define the ai edge to be the input edge of every node, bi to be the output edge for necessary fruits, and ci to be the output edge for growth events. The connections for each individual node will look like:

(source,ai,
# of growth events)

(ai,temporary node,INF)

(temporary node,bi,INF)

(temporary node,ci,INF)

(bi,sink,
# of required peaches)

(ci,sink,
# of harvest events)

To simulate growth events affecting the subtree, every temporary node has infinite capacity directed edges down to the temporary nodes of its children. To simulate growth events affecting the parent, every temporary node has an infinite capacity directed edge to its parent's bi. To simulate harvest events affecting subtree, every node has infinite capacity directed edges to all its ancestors' ci nodes. Lets try to find the min cut of the graph. If we don't put cut some node's ai, then we must cut both bi and ci for all of its descendants. If we don't cut some node's ai, then we also must cut ci for all its ancestors and bi for its parent. Thus, we can model a dp[i][0/1/2] to know if we are currently cutting the a_i input edge, cutting the b_i and c_i output edge, or cutting the a_i edge but there is some node in the subtree where we did not cut the a_i edge, in which case we need to cut the c_i edge as well. Transitions look like:

dp[i][0]=ai+∑jdp[j][0] 

dp[i][1]=bi+ci+∑jdp[j][1]

dp[i][2]=ai+ci+min(∑jmin(dp[j][0],dp[j][2]),bi+∑jmin(dp[j][0],dp[j][1],dp[j][2])) where at least one child is a dp[j][2] or dp[j][1]

dp[i][2] can be rewritten as:

dp[i][2]=ai+ci+min(min(dp[j][2]−min(dp[j][0],dp[j][2]))+∑jmin(dp[j][0],dp[j][2]), min(dp[j][1]−min(dp[j][0],dp[j][1],dp[j][2]))+bi+∑jmin(dp[j][0],dp[j][1],dp[j][2])))

Use dynamic dp by representing dp transitions as a matrix where all the light children dp values are known and the heavy child dp values are variable. Then, we can accelerate each chain in the heavy light decomposition of the tree. To get the matrix representation of each transition to the heavy child, there are 5 cases when considering a dp[j][0/1/2] -> dp[j][2] transiton where dp[j][0] is the min, dp[j][1] is the min, and dp[j][2] is the min, dp[j][2]−min(dp[j][0],dp[j][2]) is the optimal added value, or dp[j][0]−min(dp[j][0],dp[j][1],dp[j][2]), is the optimal added value. For each cell in the matrix, put the min of the 5 cases.

Since you will only ever change hld chains logn times, the total complexity will be nlog2n⋅33. If we use balanced hld or other nlogn hld techniques, then the complexity becomes nlog2n. Both solutions should pass under the given constraints.

 **Code (C++)**
```cpp
    #ifndef LOCAL
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx,avx2,fma")
    #pragma GCC target("sse4,popcnt,abm,mmx,tune=native")
    #endif
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    using namespace std;
    
    #define pb push_back
    #define ff first
    #define ss second
    
    typedef long long ll;
    typedef long double ld;
    typedef pair<int, int> pii;
    typedef pair<ll, ll> pll;
    typedef pair<ld, ld> pld;
    
    const int INF = 1e9;
    const ll LLINF = 1e18;
    const int MOD = 1e9 + 7;
    
    template<class K> using sset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
    
    inline ll ceil0(ll a, ll b) {
        return a / b + ((a ^ b) > 0 && a % b);
    }
    
    void setIO() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    
    struct Matrix {
    
        array<array<ll, 3>, 3> mat;
    
        array<ll, 3> &operator[](int x){
            return mat[x];
        }
    
        const array<ll, 3> &operator[](int x) const {
            return mat[x];
        }
    
        Matrix(){
            for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) mat[i][j] = 0;
        }
    
        Matrix operator*(const Matrix &x){
            Matrix ret;
            for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) ret[i][j] = LLINF;
            for(int i = 0; i < 3; i++){
                for(int k = 0; k < 3; k++){
                    for(int j = 0; j < 3; j++){
                        ret[i][j] = min(ret[i][j], mat[i][k] + x[k][j]);
                    }
                }
            }
            return ret;
        }
    
        Matrix &operator*=(const Matrix &x){
            (*this) = (*this) * x;
            return *this;
        }
    };
    
    struct fastset {
    
        priority_queue<ll, vector<ll>, greater<ll>> q, rem;
    
        void insert(ll x){
            q.push(x);
        }
    
        void erase(ll x){
            rem.push(x);
        }
    
        ll query(){
            while(rem.size() && q.top() == rem.top()){
                rem.pop();
                q.pop();
            }
            return q.top();
        }
    
        void clear(){
            while(q.size()) q.pop();
            while(rem.size()) rem.pop();
        }
    };
    
    vector<int> g[500005];
    int sub[500005];
    int head[500005];
    int par[500005];
    int tim = 0;
    vector<int> chain[500005];
    int weight[500005];
    
    void dfs1(int x){
        sub[x] = 1;
        for(int &i : g[x]){
            dfs1(i);
            sub[x] += sub[i];
            if(sub[i] > sub[g[x][0]]) swap(i, g[x][0]);
        }
    }
    
    int in[500005], out[500005];
    int dir[500005];
    
    void dfs2(int x, int p){
        chain[head[x]].pb(x);
        par[x] = p;
        weight[x] = 1;
        in[x] = tim++;
        for(int i : g[x]){
            head[i] = (i == g[x][0] ? head[x] : i);
            dfs2(i, x);
            if(i != g[x][0]) weight[x] += sub[i];
        }
        out[x] = tim - 1;
    }
    
    Matrix dp[500005]; 
    Matrix cum[500005];
    int rt[500005];
    int left0[500005], right0[500005], ppar[500005];
    
    int dnq(int l, int r, int p, const vector<int> &v){
        if(l > r) return 0;
        int sum = 0;
        for(int i = l; i <= r; i++) sum += weight[v[i]];
        int cur = 0;
        int mid = -1;
        for(int i = l; i <= r; i++){
            cur += weight[v[i]];
            if(cur >= sum/2){
                mid = i;
                break;
            }
        }
        if(p == -1) ppar[v[mid]] = v[mid];
        else ppar[v[mid]] = p;
        left0[v[mid]] = dnq(l, mid - 1, v[mid], v);
        right0[v[mid]] = dnq(mid + 1, r, v[mid], v);
        return v[mid];
    }
    
    void merge(int x){
        if(right0[x] && left0[x]){
            cum[x] = cum[left0[x]]*dp[x]*cum[right0[x]];
        } else if(left0[x] && !right0[x]){
            cum[x] = cum[left0[x]]*dp[x];
        } else if(right0[x] && !left0[x]){
            cum[x] = dp[x]*cum[right0[x]];
        } else {
            cum[x] = dp[x];
        }
    }
    
    void pull(int x){
        while(x != rt[x]){
            merge(x); 
            x = ppar[x];
        }
        merge(x);
    }
    
    ll a[500005], b[500005], c[500005];
    ll dp0[500005][3];
    
    void dfs3(int x){
        dp0[x][0] = a[x];
        dp0[x][2] = b[x] + c[x];
        ll deg1 = a[x] + c[x], deg2 = b[x] + a[x] + c[x];
        ll mn1 = LLINF, mn2 = LLINF;
        for(int i : g[x]){
            dfs3(i);
            dp0[x][0] += dp0[i][0];
            dp0[x][2] += dp0[i][2];
            deg1 += min(dp0[i][0], dp0[i][1]);
            deg2 += min({dp0[i][0], dp0[i][1], dp0[i][2]});
            mn1 = min(mn1, max((ll)0, dp0[i][1] - dp0[i][0]));
            mn2 = min(mn2, max((ll)0, min(dp0[i][1], dp0[i][2]) - dp0[i][0]));
        }
        dp0[x][1] = min(deg1 + mn1, deg2 + mn2);
    }
    
    fastset deg1[500005], deg2[500005];
    ll sum0[500005], sum2[500005], sum01[500005], sum012[500005];
    
    void rebuild(int x){
        dp[x][0][0] = a[x] + sum0[x];
        dp[x][0][1] = LLINF;
        dp[x][0][2] = LLINF;
        if(g[x].size()){
            dp[x][1][0] = min(a[x] + b[x] + c[x] + deg2[x].query() + sum012[x], a[x] + c[x] + deg1[x].query() + sum01[x]);
            dp[x][1][1] = min(a[x] + c[x] + sum01[x], a[x] + b[x] + c[x] + sum012[x]);
            dp[x][1][2] = a[x] + b[x] + c[x] + sum012[x];
        } else {
            dp[x][1][0] = dp[x][1][1] = dp[x][1][2] = LLINF;
        }
        dp[x][2][0] = LLINF;
        dp[x][2][1] = LLINF;
        dp[x][2][2] = b[x] + c[x] + sum2[x];
    }
    
    ll eval(int x, int ind){
        return min({cum[rt[x]][ind][0], cum[rt[x]][ind][1], cum[rt[x]][ind][2]});
    }
    
    void rem(int x){
        while(head[x] != 1){
            if(x == head[x]){
                ll v0 = eval(x, 0), v1 = eval(x, 1), v2 = eval(x, 2);
                deg1[par[x]].erase(max((ll)0, v1 - v0));
                deg2[par[x]].erase(max((ll)0, min(v1, v2) - v0));
                sum012[par[x]] -= min({v0, v1, v2});
                sum01[par[x]] -= min(v0, v1);
                sum0[par[x]] -= v0;
                sum2[par[x]] -= v2;
                x = par[x];
            }
            x = head[x];
        }
    }
    
    void add(int x){
        while(head[x] != 1){
            if(x == head[x]){
                ll v0 = eval(x, 0), v1 = eval(x, 1), v2 = eval(x, 2);
                deg1[par[x]].insert(max((ll)0, v1 - v0));
                deg2[par[x]].insert(max((ll)0, min(v1, v2) - v0));
                sum012[par[x]] += min({v0, v1, v2});
                sum01[par[x]] += min(v0, v1);
                sum0[par[x]] += v0;
                sum2[par[x]] += v2;
                rebuild(par[x]);
                pull(par[x]);
                x = par[x];
            }
            x = head[x];
        }
    }
    
    int main(){
        setIO();
        int t;
        cin >> t;
        while(t--){
            int n, q;
            cin >> n >> q;
            for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                g[x].pb(i);
            }
            ll sum = 0;
            for(int i = 1; i <= n; i++) cin >> b[i], sum += b[i];
            dfs1(1);
            head[1] = 1;
            dfs2(1, 1);
            dfs3(1);
            for(int i = 1; i <= n; i++){
                if(chain[i].size()){
                    int p = dnq(0, chain[i].size() - 1, -1, chain[i]);
                    for(int j : chain[i]) rt[j] = p;
                }
            }
            for(int i = 1; i <= n; i++){
                deg1[i].insert(LLINF);
                deg2[i].insert(LLINF);
                for(int j : g[i]){
                    if(head[j] == head[i]) continue;
                    deg1[i].insert(max((ll)0, dp0[j][1] - dp0[j][0]));
                    deg2[i].insert(max((ll)0, min(dp0[j][1], dp0[j][2]) - dp0[j][0]));
                    sum012[i] += min({dp0[j][0], dp0[j][1], dp0[j][2]});
                    sum01[i] += min(dp0[j][0], dp0[j][1]);
                    sum0[i] += dp0[j][0];
                    sum2[i] += dp0[j][2];
                }
                rebuild(i);
                pull(i);
            } 
            while(q--){
                int t, x, v;
                cin >> t >> x >> v;
                rem(x);
                if(t == 1) a[x] += v;
                else c[x] += v, sum += v;
                rebuild(x);
                pull(x);
                add(x);
                cout << (min({eval(1, 0), eval(1, 1), eval(1, 2)}) == sum ? "YES" : "NO") << "n";
            }
            tim = 0;
            for(int i = 1; i <= n; i++){
                a[i] = b[i] = c[i] = 0;
                g[i].clear();
                chain[i].clear();
                deg1[i].clear();
                deg2[i].clear();
                sum0[i] = sum2[i] = sum01[i] = sum012[i] = 0;
            }
        }
    }
```
 **Solution 2**There also exists a solution without flows. Thanks to [rainboy](https://codeforces.com/profile/rainboy "Master rainboy") for discovering it during testing!

Lets greedily assign the growth events. We will always try to use the growth events to satisfy harvest events or required peaches in its subtree, and if there is any excess then we give it to the parent's required peaches. Similarly, we will always use harvest events on growth events in its subtree. Lets define a dp[u] for each node u. If dp[x]>0 then it means we can give dp[u] growths to u's parent. Otherwise, it means dp[u] requires −dp[u] growths from its ancestors. Let posu denote the sum of positive dp[v] where v is a child a of u, and negu denote the sum of negative dp[v]. First we used the excess growth to satisfy the required peaches, so we can set bu=max(0,bu−posu). Then we distribute the growth events at node u to satisfy the requirements in the subtree. Define ai as the number of growth events on node i and ci as the number of harvest events on node i. To account for the harvest events at node i, we can define balu=sum of ai in u's subtree−sum of bi in u's subtree−sum of ci in u's subtree. We know that dp[u]≤balu, and as it turns out, as long as we keep balu as an upper bound on dp[u], the harvest events will always be satisfied. Why? au+negu−max(0,bu−posu) is the assignment of growth events without considering harvest events. The amount of unused growth events in the subtree of u is given by balu−(au+negu−max(0,bu−posu))+cu. If au+negu−max(0,bu−posu)≤balu, then it means we can use all of our harvest events on unused growth events in the subtree. If au+negu−max(0,bu−posu)>balu, then it means we will use all of our harvest events but still have balu−(au+negu−max(0,bu−posu)) harvest events remaining. Thus, we can formulate our dp as dp[u]=min(au+negu−max(0,bu−posu),balu). Let v be the heavy child of u and pos′u be the sum of positive dp excluding v and neg′u be the sum of positive dp excluding v. Then, we can rewrite our dp as dp[u]=min(dp[v]+au+neg′u−max(0,bu−pos′u),au+neg′u,balu). Define xu=au+neg′u−max(0,bu−pos′u) and yu=au+neg′u. Then dp[u]=min(dp[v]+xu,yu,balu). This can be accelerated by representing the transition as a matrix and accelerating it using dynamic dp. However, we can also notice that the dp can be represented as the smallest x1+x2+…+xi−1+min(yi,bali) over all prefixes of each heavy light decomposition chain. Thus, we can maintain the dp by using a range add and prefix min segment tree.

 **Code (C++)**
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N	300000
#define N_	(1 << 19)	/* N_ = pow2(ceil(log2(N))) */
#define INF	0x3f3f3f3f3f3f3f3fLL

long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }

int *ej[N], eo[N], n;

void append(int i, int j) {
	int o = eo[i]++;

	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}

int dd[N], pp[N], qq[N], jj[N], ta[N], tb[N], qu[N];
int bb[N]; long long aa[N], zz[N], zzp[N], zzn[N];

int dfs1(int i, int d) {
	int o, s, k_, j_;

	dd[i] = d;
	s = 1, k_ = 0, j_ = -1;
	zz[i] = -bb[i];
	for (o = eo[i]; o--; ) {
		int j = ej[i][o], k = dfs1(j, d + 1);

		s += k;
		if (k_ < k)
			k_ = k, j_ = j;
		zz[i] += zz[j];
	}
	qq[i] = j_, jj[i] = j_ == -1 ? i : jj[j_];
	return s;
}

int t_;

void dfs2(int i, int q) {
	int o, j_;

	qu[ta[i] = t_++] = i;
	j_ = qq[i], qq[i] = q;
	if (j_ != -1)
		dfs2(j_, q);
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		if (j != j_)
			dfs2(j, j);
	}
	tb[i] = t_;
}

long long stx[N_ * 2], sty[N_ * 2], stz[N_ * 2], lz[N_]; int h_, n_;

void put(int i, long long x) {
	stz[i] += x;
	if (i < n_)
		lz[i] += x;
}

void pus(int i) {
	if (lz[i])
		put(i << 1 | 0, lz[i]), put(i << 1 | 1, lz[i]), lz[i] = 0;
}

void pul(int i) {
	if (!lz[i]) {
		int l = i << 1, r = l | 1;

		stx[i] = stx[l] + stx[r];
		sty[i] = min(sty[l], stx[l] + sty[r]);
		stz[i] = min(stz[l], stx[l] + stz[r]);
	}
}

void push(int i) {
	int h;

	for (h = h_; h > 0; h--)
		pus(i >> h);
}

void pull(int i) {
	while (i > 1)
		pul(i >>= 1);
}

void build() {
	int i, j, a, o;
        h_ = 0;

	while (1 << h_ < n)
		h_++;
	n_ = 1 << h_;
	memset(stx, 0, n_ * 2 * sizeof *stx);
	memset(sty, 0, n_ * 2 * sizeof *sty);
	memset(stz, 0, n_ * 2 * sizeof *stz);
	memset(lz, 0, n_ * sizeof *lz);
	memset(aa, 0, n * sizeof *aa);
	memset(zzp, 0, n * sizeof *zzp);
	memset(zzn, 0, n * sizeof *zzn);
	for (i = 0; i < n; i++) {
		a = ta[i];
		stz[n_ + a] = zz[i];
		for (o = eo[i]; o--; ) {
			j = ej[i][o];
			if (qq[j] == j)
				zzn[i] += -zz[j];
		}
		stx[n_ + a] = -zzn[i] - bb[i];
		sty[n_ + a] = -zzn[i];
	}
	for (i = n_ - 1; i > 0; i--)
		pul(i);
}

void upd(int i) {
	int i_ = n_ + ta[i];

	push(i_);
	stx[i_] = aa[i] - zzn[i] - max(bb[i] - zzp[i], 0);
	sty[i_] = aa[i] - zzn[i];
	pull(i_);
}

void update_z(int l, int r, long long x) {
	int l_ = l += n_, r_ = r += n_;

	push(l_), push(r_);
	for ( ; l <= r; l >>= 1, r >>= 1) {
		if ((l & 1) == 1)
			put(l++, x);
		if ((r & 1) == 0)
			put(r--, x);
	}
	pull(l_), pull(r_);
}

long long query(int l, int r) {
	long long xl, yl, zl, xr, yr, zr;

	push(l += n_), push(r += n_);
	xl = 0, yl = INF, zl = INF, xr = 0, yr = INF, zr = INF;
	for ( ; l <= r; l >>= 1, r >>= 1) {
		if ((l & 1) == 1) {
			yl = min(yl, xl + sty[l]), zl = min(zl, xl + stz[l]), xl += stx[l];
			l++;
		}
		if ((r & 1) == 0) {
			yr = min(sty[r], yr == INF ? INF : stx[r] + yr), zr = min(stz[r], zr == INF ? INF : stx[r] + zr), xr += stx[r];
			r--;
		}
	}
	return min(min(xl + xr, min(yl, yr == INF ? INF : xl + yr)), min(zl, zr == INF ? INF : xl + zr));
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int q_, i, p, q;

		scanf("%d%d", &n, &q_);
		for (i = 0; i < n; i++)
			ej[i] = (int *) malloc(2 * sizeof *ej[i]), eo[i] = 0;
		pp[0] = -1;
		for (i = 1; i < n; i++) {
			scanf("%d", &pp[i]), pp[i]--;
			append(pp[i], i);
		}
		for (i = 0; i < n; i++)
			scanf("%d", &bb[i]);
		dfs1(0, 0);
		t_ = 0, dfs2(0, 0);
		build();
		while (q_--) {
			int t, x;

			scanf("%d%d%d", &t, &i, &x), i--;
			if (t == 2)
				x = -x;
			if (t == 1)
				aa[i] += x, upd(i);
			while (i >= 0) {
				q = qq[i], p = pp[q];
				if (p >= 0) {
					if (zz[q] > 0)
						zzp[p] -= zz[q];
					else
						zzn[p] -= -zz[q];
				}
				update_z(ta[q], ta[i], x);
				zz[q] = query(ta[q], ta[jj[q]]);
				if (p >= 0) {
					if (zz[q] > 0)
						zzp[p] += zz[q];
					else
						zzn[p] += -zz[q];
					upd(p);
				}
				i = p;
			}
			printf(zz[0] >= 0 ? "YESn" : "NOn");
		}
		for (i = 0; i < n; i++)
			free(ej[i]);
	}
	return 0;
}
```
