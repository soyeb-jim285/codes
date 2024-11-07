# Tutorial_(en)

This was our first time setting a Div.4 contest. We sincerely hope you enjoyed the problems!

##### [1985A - Creating Words](../problems/A._Creating_Words.md "Codeforces Round 952 (Div. 4)")

Problem Credits: [cry](https://codeforces.com/profile/cry "Master cry")   
 Analysis: [cry](https://codeforces.com/profile/cry "Master cry")

 **Solution**To swap the first character of the strings, you can use the built-in method std::swap in C++, or for each string, separate the first character from the rest of the string and concatenate it with the other string.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		swap(a[0], b[0]);
		cout << a << " " << b << endl;
	}
}
```
##### [1985B - Maximum Multiple Sum](../problems/B._Maximum_Multiple_Sum.md "Codeforces Round 952 (Div. 4)")

Problem Credits: [cry](https://codeforces.com/profile/cry "Master cry")   
 Analysis: [cry](https://codeforces.com/profile/cry "Master cry")

 **Solution**To maximize the number of multiples of x less than n, it optimal to choose a small x, in this case, 2. The only exception is n=3, where it is optimal to choose 3 instead, since both 2 and 3 have only one multiple less than 3.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << (n == 3 ? 3 : 2) << endl;
 	}
}
```
##### [1985C - Good Prefixes](../problems/C._Good_Prefixes.md "Codeforces Round 952 (Div. 4)")

Problem Credits: [sum](https://codeforces.com/profile/sum "Master sum")   
 Analysis: [cry](https://codeforces.com/profile/cry "Master cry")

 **Solution**The only element that can be the sum of all other elements is the maximum element, since all elements are positive. Therefore, for each prefix i from 1 to n, check if sum(a1,a2,...,ai)−max(a1,a2,...,ai)=max(a1,a2,...,ai). The sum and max of prefixes can be tracked with variables outside the loop.

 **Code (C++)**
```cpp
#include <iostream>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		long long sum = 0;
		int mx = 0, ans = 0;;
		for(int i = 0; i < n; i++){
			sum += a[i];
			mx = max(mx, a[i]);
			if(sum - mx == mx) 
				ans++;
		}
		cout << ans << endl;
	}
}
```
##### [1985D - Manhattan Circle](../problems/D._Manhattan_Circle.md "Codeforces Round 952 (Div. 4)")

Problem Credits: [cry](https://codeforces.com/profile/cry "Master cry")   
 Analysis: [cry](https://codeforces.com/profile/cry "Master cry")

 **Solution**Note that the manhattan circle is always in a diamond shape, symmetric from the center. Let's take notice of some special characteristics that can help us. One way is to find the top and bottom points of the circle. Note that these points will have columns at the center of the circle, so here we can acquire the value of k. To find h, since the circle is symmetric, it is just the middle of the rows of the top and bottom points. 

Note that we never needed to find the value of r.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<vector<char>> g(n, vector<char>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> g[i][j];
			}
		}
		pair<int, int> top = {INF, INF}, bottom = {-INF, -INF};
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(g[i][j] == '#'){
					top = min(top, {i, j});
					bottom = max(bottom, {i, j});
				}
			}
		}
		assert(top.second == bottom.second);
		cout << (top.first + bottom.first) / 2 + 1 << " " << top.second + 1 << endl;
	}
}
```
##### [1985E - Secret Box](../problems/E._Secret_Box.md "Codeforces Round 952 (Div. 4)")

Problem Credits: [cry](https://codeforces.com/profile/cry "Master cry")   
 Analysis: [cry](https://codeforces.com/profile/cry "Master cry")

 **Solution**Since the side lengths of S has to multiply to k, all three side lengths of S has to be divisors of k. Let's denote the side lengths of S along the x, y, and z axes as a, b, and c respectively. For S to fit in B , a≤x, b≤y, and c≤z must hold. Because of the low constraints, we can afford to loop through all possible values of a and b, and deduce that c=ka⋅b (make sure c≤z and c is an integer). To get the amount of ways we can place S, we can just multiply the amount of shifting space along each axes, and that just comes down to (x−a+1)⋅(y−b+1)⋅(z−c+1). The answer is the maximum among all possible values of a, b, and c . 

The time complexity is O(n2) where n is at most 2000.

 **Code (C++)**
```cpp
#include <iostream>
using namespace std;
using ll = long long;

int main(){
	int t; cin >> t;
	while(t--){
		ll x, y, z, k; cin >> x >> y >> z >> k;
		ll ans = 0;
		for(int a = 1; a <= x; a++){
			for(int b = 1; b <= y; b++){
				if(k % (a * b)) continue;
				ll c = k / (a * b);
				if(c > z) continue;
				ll ways = (ll)(x - a + 1) * (y - b + 1) * (z - c + 1);
				ans = max(ans, ways);
			}
		}
		cout << ans << "n";
	}
}
```
##### [1985F - Final Boss](../problems/F._Final_Boss.md "Codeforces Round 952 (Div. 4)")

Problem Credits: [cry](https://codeforces.com/profile/cry "Master cry"), [sum](https://codeforces.com/profile/sum "Master sum")   
 Analysis: [cry](https://codeforces.com/profile/cry "Master cry"), [sum](https://codeforces.com/profile/sum "Master sum")

 **About Hacks**Unfortunately, there was a lot of hacks on this problem, and we're sorry for it. Since our intended solution is not binary search, we didn't really take overflow using binary search seriously. I ([cry](https://codeforces.com/profile/cry "Master cry")) prepared this problem and I only took into account about overflow with big cooldown, but I forgot overflow can happen on attacks as well. I apologize and we will do better next time!

 **Solution**Since the sum of h is bounded by 2⋅105, and each attack deals at least 1 damage. If we assume every turn we can make at least one attack, the sum of turns to kill the boss in every test case is bounded by 2⋅105. This means that we can afford to simulate each turn where we make at least one attack. 

But what if we cannot make an attack on this turn? Since the cooldown for each attack can be big, we cannot increment turns one by one. We must jump to the next turn we can make an attack. This can be done by retrieving the first element of a sorted set, where the set stores pairs {t, i} which means {next available turn you can use this attack, index of this attack} for all i. Here, we can set the current turn to t and use all attacks in the set with first element in the pair equal to t. Remember to insert the pair to {ci+t, i} back into the set after processing the attacks.

The time complexity is O(hlogn).

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int h, n; cin >> h >> n;
		vector<int> a(n), c(n);
		for(int& i: a) cin >> i;
		for(int& i: c) cin >> i;
		set<pair<long long, int>> S;
		for(int i = 0; i < n; i++){
			S.insert({1, i});
		}
		long long last_turn = 1;
		while(h > 0){
			auto [turn, i] = *S.begin();
			S.erase(S.begin());
			last_turn = turn;
			h -= a[i];
			S.insert({turn + c[i], i});
		}
		cout << last_turn << "n";
	}
}

// comment "tomato" if you see this comment
```
 **Bonus**Try to solve this if 1≤h≤109.

 **Solution**We can do this by binary searching for the answer. For some time t, we know that we can perform an attack of cooldown c exactly ⌊t−1c⌋+1 times. The total damage we will do in time t will be:

 n∑i=1ai(⌊t−1ci⌋+1)So we binary search for the first t such that the total damage we do in time t is greater than or equal to h. This runs in O(nlog(h⋅maxci)). Be careful of long long overflow!

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll h, n;
    cin >> h >> n;

    vector<ll> A(n), C(n);

    for (ll &i : A)
        cin >> i;
    for (ll &i : C)
        cin >> i;
    
    auto chk = [&](ll t){
        ll dmg = 0;
        for (int i = 0; i < n and dmg < h; i++){
            ll cnt = (t - 1) / C[i] + 1;

            if (cnt >= h)
                return true;

            dmg += cnt * A[i];
        }
        return dmg >= h;
    };

    ll L = 1, H = 1e12;

    while (L < H){
        ll M = (L + H) / 2;
        chk(M) ? H = M : L = M + 1;
    }
    cout << L << "n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
```
##### [1985G - D-Function](../problems/G._D-Function.md "Codeforces Round 952 (Div. 4)")

Problem Credits: [cry](https://codeforces.com/profile/cry "Master cry")   
 Analysis: [cry](https://codeforces.com/profile/cry "Master cry")

 **Solution**To satisfy D(k⋅n)=k⋅D(n), each digit d in n must become k⋅d after multiplying n by k. In other words, none of n's digits can carry over to the next digit upon multiplication. From this, we can deduce that each digit in n must be less than or equal to ⌊9k⌋. Only thing left is to count all such numbers in the range of 10l inclusive and 10r exclusive.

Every number below 10r has r or less digits. For numbers with less than r digits, let's pad the beginning with zeroes until it becomes a r digit number (for example, if r=5, then 69 becomes 00069). This allows us to consider numbers with less than r digits the same way as numbers with exactly r digits. For each digit, we have ⌊9k⌋+1 choices (including zero), and there are r digits, so the total number of numbers that satisfies the constraint below 10r is (⌊9k⌋+1)r.

To get the count of numbers in range, it suffices to subtract all valid numbers less than 10l. Therefore, the answer is (⌊9k⌋+1)r−(⌊9k⌋+1)l. To exponentiate fast, we can use [modular exponentiation](https://codeforces.com/https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/).

 **Code (Python)**
```cpp
MOD = int(1e9+7)
t = int(input())
for _ in range(t):
    l, r, k = map(int, input().split())
    print((pow(9 // k + 1, r, MOD) - pow(9 // k + 1, l, MOD) + MOD) % MOD)
```
##### [1985H1 - Maximize the Largest Component (Easy Version)](../problems/H1._Maximize_the_Largest_Component_(Easy_Version).md "Codeforces Round 952 (Div. 4)")

Problem Credits: [sum](https://codeforces.com/profile/sum "Master sum")   
 Analysis: [sum](https://codeforces.com/profile/sum "Master sum")

 **Solution**Let's first solve the problem if we can only select and fill **rows**. Columns can be handled in the exact same way.

For each row r, we need to find the size of the component formed by filling row r (i.e. the size of the component **containing** row r if we set all cells in row r to be #).

The size of the component **containing** row r if we set all cells in row r to be 
# will be the **sum** of:

 1. The number of . in row r since these cells will be set to #. Let Fr denote this value for some row r.
2. The sum of sizes of components containing a cell in either row r−1, r, or r+1 (i.e. components that are touching row r). This is since these components will be part of the component containing row r. Let Rr denote this value for some row r.

The challenge is computing the second term quickly. For some component, let s be the size of the component and let rmin and rmax denote the minimum and maximum row of a cell in the component. This means that the component will contain cells with rows rmin,rmin+1,...,rmax. Note that we can find these values with a dfs. Since the component will contribute s to rows in [rmin−1,rmin,…rmax+1], we add s to Rrmin−1,Rrmin,…,Rrmax+1. This can be done naively or with prefix sums.

We find the maximum Fr+Rr and then handle columns in the same way. This solution runs in O(nm) time.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, minR, maxR, minC, maxC, sz, ans; vector<int> R, C, freeR, freeC; 
vector<vector<bool>> vis; vector<vector<char>> A;

void dfs(int i, int j){
    if (i <= 0 or i > n or j <= 0 or j > m or vis[i][j] or A[i][j] == '.')
        return;
    
    vis[i][j] = true;

    sz++;
    minR = min(minR, i);
    maxR = max(maxR, i);
    minC = min(minC, j);
    maxC = max(maxC, j);

    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

void solve(){
    cin >> n >> m;

    R.assign(n + 5, 0);
    C.assign(m + 5, 0);
    freeR.assign(n + 5, 0);
    freeC.assign(m + 5, 0);
    vis.assign(n + 5, vector<bool>(m + 5, false));
    A.assign(n + 5, vector<char>(m + 5, ' '));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> A[i][j];

            if (A[i][j] == '.'){
                freeR[i]++;
                freeC[j]++;
            }
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (vis[i][j] or A[i][j] == '.')
                continue;

            // Reset
            sz = 0;
            minR = 1e9;
            maxR = -1e9;
            minC = 1e9;
            maxC = -1e9;

            dfs(i, j);

            // Expand by 1 since adjacent cells also connect
            minR = max(minR - 1, 1);
            maxR = min(maxR + 1, n);
            minC = max(minC - 1, 1);
            maxC = min(maxC + 1, m);
            
            // Update prefix sums
            R[minR] += sz;
            R[maxR + 1] -= sz;

            C[minC] += sz;
            C[maxC + 1] -= sz;
        }
    }

    ans = 0;

    for (int i = 1; i <= n; i++){
        R[i] += R[i - 1];
        ans = max(ans, freeR[i] + R[i]);
    }
    for (int i = 1; i <= m; i++){
        C[i] += C[i - 1];
        ans = max(ans, freeC[i] + C[i]);
    }

    cout << ans << "n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
```
##### [1985H2 - Maximize the Largest Component (Hard Version)](../problems/H2._Maximize_the_Largest_Component_(Hard_Version).md "Codeforces Round 952 (Div. 4)")

Problem Credits: [sum](https://codeforces.com/profile/sum "Master sum")   
 Analysis: [sum](https://codeforces.com/profile/sum "Master sum")

 **Solution**For each row r and column c, we need to find the size of the component formed by filling both row r and column c (i.e. the size of the component **containing** row r and column c if we set all cells in both row r and column c to be #).

Extending the reasoning in H1, for some row r and column c, consider the sum of:

 1. The number of . in row r or column c since these cells will be set to #. Let Fr,c denote this value for some row r and column c.
2. The sum of sizes of components containing a cell in either row r−1, r, or r+1 (i.e. components that are touching row r). This is since these components will be part of the component containing row r and column c. Let Rr denote this value for some row r.
3. The sum of sizes of components containing a cell in either column c−1, c, or c+1 (i.e. components that are touching column c). This is since these components will be part of the component containing row r and column c. Let Cc denote this value for some column c.

However, components that contain a cell in either row r−1, r, or r+1 as well as in either column c−1, c, or c+1 will be **overcounted** (since it will be counted in both terms 2 and 3) (you can think of it as components touching both row r and column c). Thus, we need to subtract the sum of sizes of components that contain a cell in either row r−1, r, or r+1 as well as in either column c−1, c, or c+1. Let Br,c denote this for some row r and column c.

Then the size of the component formed by filling both row r and column c will be Fr,c+Rr+Cc−Br,c and we want to find the maximum value of this.

Let's try to calculate these values efficiently. Consider some component.

 1. Let s be its size.
2. Let rmin and rmax denote the minimum and maximum row of a cell in the component. This means that the component contains cells with rows rmin,rmin+1,...,rmax.
3. Let cmin and cmax denote the minimum and maximum column of a cell in the component. This means that the component contains cells with columns cmin,cmin+1,...,cmax.

All these values can be found with a dfs. We then do the following updates:

 1. Add s to Rrmin−1,Rrmin,…,Rrmax+1. This can be done naively or with prefix sums.
2. Add s to Ccmin−1,Ccmin,…,Ccmax+1. This can be done naively or with prefix sums.
3. Add s to the subrectangle of B with top left at (rmin−1,cmin−1) and bottom right at (rmax+1,cmax+1). This can be done with 2D prefix sums. (Note that doing this naively will pass because of low constant factor and the fact that we could not cut this solution without cutting slow correct solutions.)

We do this for each component. Also, calculating Fr,c can be done by looking at the number of . in row r, column c, and checking whether we overcounted a . at (r,c). In all, this solution runs in O(nm) time.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, minR, maxR, minC, maxC, sz, ans; vector<int> R, C, freeR, freeC; 
vector<vector<int>> RC; vector<vector<bool>> vis; vector<vector<char>> A;

void dfs(int i, int j){
    if (i <= 0 or i > n or j <= 0 or j > m or vis[i][j] or A[i][j] == '.')
        return;
    
    vis[i][j] = true;

    sz++;
    minR = min(minR, i);
    maxR = max(maxR, i);
    minC = min(minC, j);
    maxC = max(maxC, j);

    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

void solve(){
    cin >> n >> m;

    R.assign(n + 5, 0);
    C.assign(m + 5, 0);
    freeR.assign(n + 5, 0);
    freeC.assign(m + 5, 0);
    RC.assign(n + 5, vector<int>(m + 5, 0));
    vis.assign(n + 5, vector<bool>(m + 5, false));
    A.assign(n + 5, vector<char>(m + 5, ' '));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> A[i][j];

            if (A[i][j] == '.'){
                freeR[i]++;
                freeC[j]++;
            }
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (vis[i][j] or A[i][j] == '.')
                continue;

            // Reset
            sz = 0;
            minR = 1e9;
            maxR = -1e9;
            minC = 1e9;
            maxC = -1e9;

            dfs(i, j);

            // Expand by 1 since adjacent cells also connect
            minR = max(minR - 1, 1);
            maxR = min(maxR + 1, n);
            minC = max(minC - 1, 1);
            maxC = min(maxC + 1, m);
            
            // Update prefix sums
            R[minR] += sz;
            R[maxR + 1] -= sz;

            C[minC] += sz;
            C[maxC + 1] -= sz;

            RC[minR][minC] += sz;
            RC[maxR + 1][minC] -= sz;
            RC[minR][maxC + 1] -= sz;
            RC[maxR + 1][maxC + 1] += sz;
        }
    }

    for (int i = 1; i <= n; i++)
        R[i] += R[i - 1];

    for (int i = 1; i <= m; i++)
        C[i] += C[i - 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            RC[i][j] += RC[i - 1][j] + RC[i][j - 1] - RC[i - 1][j - 1];
    
    ans = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, (R[i] + C[j] - RC[i][j]) + (freeR[i] + freeC[j] - (A[i][j] == '.')));
    
    cout << ans << "n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
```
