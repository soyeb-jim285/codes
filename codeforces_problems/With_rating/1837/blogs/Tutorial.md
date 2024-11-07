# Tutorial

[1837A - Grasshopper on a Line](../problems/A._Grasshopper_on_a_Line.md "Educational Codeforces Round 149 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1837A - Grasshopper on a Line](../problems/A._Grasshopper_on_a_Line.md "Educational Codeforces Round 149 (Rated for Div. 2)")

When $x$ is not divisible by $k$, the grasshopper can reach $x$ in just one jump.

Otherwise, you can show that two jumps are always enough. For example, jumps $1$ and $x-1$. $1$ is not divisible by any $k > 1$. Also, $x$ and $x-1$ can't be divisible by any $k > 1$ at the same time.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	x, k = map(int, input().split())
	if x % k != 0:
		print(1)
		print(x)
	else:
		print(2)
		print(1, x - 1)
```
[1837B - Comparison String](../problems/B._Comparison_String.md "Educational Codeforces Round 149 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1837B - Comparison String](../problems/B._Comparison_String.md "Educational Codeforces Round 149 (Rated for Div. 2)")

Suppose there is a segment of length $k$ that consists of equal characters in $s$. This segment implies that there are at least $k+1$ distinct values in the answer: for example, if the segment consists of < signs, the first element should be less than the second element, the second element should be less than the third element, and so on, so the corresponding segment of the array $a$ contains at least $k+1$ different elements.

So, the answer is at least $m+1$, where $m$ is the length of the longest segment of the string that consists of equal characters. Can we construct the array $a$ which will contain exactly $m+1$ distinct values? It turns out we can do it with the following greedy algorithm: let's use integers from $0$ to $m$ for our array $a$, and let's construct it from left to right; every time we place an element, we choose either the largest possible integer we can use (if the next character is >) or the smallest possible integer we can use (if the next character is <). For example, for the string <><<<>, the first $6$ elements of the array will be $[0, 3, 0, 1, 2, 3]$ (and we can use any integer from $0$ to $2$ in the last position). That way, whenever a segment of equal characters begins, the current value in the array will be either $m$ or $0$, and we will be able to decrease or increase it $m$ times, so we won't arrive at a situation where, for example, the current value is $0$ and we have to find a smaller integer.

So, the problem basically reduces to finding the longest contiguous subsegment of equal characters in $s$.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 1, cur = 1;
        for(int i = 1; i < n; i++)
        {
            if(s[i] != s[i - 1]) cur = 1;
            else cur++;
            ans = max(ans, cur);
        }
        cout << ans + 1 << endl;
    }    
}
```
[1837C - Best Binary String](../problems/C._Best_Binary_String.md "Educational Codeforces Round 149 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1837C - Best Binary String](../problems/C._Best_Binary_String.md "Educational Codeforces Round 149 (Rated for Div. 2)")

First of all, let's try solving an easier problem — suppose we have a binary string, how many operations of the form "reverse a substring" do we have to perform so that it is sorted? To solve this problem, we need to consider substrings of the form 10 in the string (i. e. situations when a zero immediately follows a one). Sorted binary strings should not contain any such substrings, so our goal is to reduce the number of such strings to zero.

Let's try to analyze how can we reduce the number of substrings equal to 10 by reversing a substring. Suppose that we want to "remove" a particular substring 10 from the string without causing any new ones to appear. We can reverse the substring that consists of the block of ones and the block of zeroes adjacent to each other; that way, after reversing the substring, these two blocks will be swapped; the block of zeroes will either merge with the block of zeroes to the left, or move to the beginning of the string; the block of ones will either merge with the block of ones to the right, or move to the end of the string. For example, if, in the string 0011101, you reverse the substring from the $3$-rd to the $6$-th position, you get 0001111, and you reduce the number of substrings 10 by one.

What if we want to reduce this number by more than one in just one operation? Unfortunately, this is impossible. Suppose we want to affect two substrings 10 with one reverse operation. There will be a substring 01 between them, so, after reversing, it will turn into 10, and we'll reduce the number of substrings 10 only by one. The same when we try to affect three, four or more substrings 10. So, we can reduce the number of substrings 10 only by one in one operation. So, the answer to the problem "count the number of operations required to sort the binary string" is just the number of substrings 10.

Okay, back to the original problem. Now we want to replace every question mark so that the resulting string contains as few substrings 10 as possible. You can use dynamic programming of the form $dp_{i,j}$ — the minimum number of substrings if we considered $i$ first characters of the string and the last of them was $j$. Or you can try the following greedy instead: go through the string from left to right, and whenever you encounter a question mark, replace it with the same character as the previous character in the string (if the string begins with a question mark, it should be replaced with 0). That way, you will create as few "blocks" of characters as possible, so the number of times when a block of 1's changes into a block of 0's will be as small as possible.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    char x = '0';
    for (auto& c : s) {
      if (c == '?') c = x;
      x = c;
    }
    cout << s << 'n';
  }
}
```
[1837D - Bracket Coloring](../problems/D._Bracket_Coloring.md "Educational Codeforces Round 149 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1837D - Bracket Coloring](../problems/D._Bracket_Coloring.md "Educational Codeforces Round 149 (Rated for Div. 2)")

What properties do beautiful bracket sequences have? Well, each beautiful sequence is either an RBS (regular bracket sequence) or a reversed RBS. For RBS, the balance (the difference between the number of opening and closing brackets) is non-negative for every its prefix, and equal to zero at the end of the string. For a reversed RBS, the balance is non-positive for every prefix, and zero at the end of the string. So, every beautiful string has balance equal to $0$, and if the string $s$ has non-zero balance, it is impossible to color it. Let's consider the case when the balance of $s$ is $0$.

Suppose we calculated the balance on every prefix of $s$, and split it into parts by cutting it along the positions where the balance is $0$. For example, the string (()())())( will be split into (()()), () and )(. For every part of the string we obtain, the balance in the end is equal to $0$, and the balance in the middle of the part is never equal to $0$ (since positions with balance equal to $0$ were the positions where we split the string). So, the balance is either positive in all positions of the part, or negative in all positions of the part; and every string we obtain from cutting $s$ into parts will be beautiful.

A concatenation of two RBS'es is always an RBS. The same can be said about the strings which become RBS after reversing. So, for every part we obtain after cutting $s$ into parts, we can determine whether it is an RBS or a reversed RBS, concatenate all RBS'es into one big RBS (by coloring them into color $1$), and concatenate all reversed RBS'es into one string (by coloring them into color $2$). This construction shows that the maximum number of colors is $2$ and allows to obtain the coloring into two colors; so, all that's left to solve the problem is to check whether it's possible to use just one color (it is the case if and only if the given string $s$ is beautiful).

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> bal(n + 1);
        for(int j = 0; j < n; j++)
            if(s[j] == '(')
                bal[j + 1] = bal[j] + 1;
            else
                bal[j + 1] = bal[j] - 1;

        if(bal.back() != 0)
            cout << -1 << endl;
        else
        {
            if(*min_element(bal.begin(), bal.end()) == 0 || *max_element(bal.begin(), bal.end()) == 0)
            {
                cout << 1 << endl;
                for(int j = 0; j < n; j++)
                {
                    if(j) cout << " ";
                    cout << 1;
                }
                cout << endl;
            }
            else
            {
                cout << 2 << endl;
                vector<int> ans;
                int cur = 0;
                while(cur < n)
                {
                    int w = (s[cur] == '(' ? 1 : 2);
                    do
                    {
                        cur++;
                        ans.push_back(w);
                    }
                    while(bal[cur] != 0);
                }
                for(int j = 0; j < n; j++)
                {
                    if(j) cout << " ";
                    cout << ans[j];
                }
                cout << endl;
            }
        }
    }    
}
```
[1837E - Playoff Fixing](../problems/E._Playoff_Fixing.md "Educational Codeforces Round 149 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1837E - Playoff Fixing](../problems/E._Playoff_Fixing.md "Educational Codeforces Round 149 (Rated for Div. 2)")

Let's investigate the structure of the tournament, starting from the first round.

We know that teams from $2^{k-1}+1$ to $2^k$ have to lose during this round. At the same time, there are exactly $2^{k-1}$ losers in this round. So, every pairing has to look like this: a team from $1$ to $2^{k-1}$ versus a team from $2^{k-1}+1$ to $2^k$.

Let's try to solve for zero reserved seeds — all $a_i = -1$. So, we only have to count the number of valid tournaments.

Let's try to do that starting from the top. The winner is team $1$. The final is team $1$ against team $2$, but we have an option to choose their order in the finals. Next, the semifinal. One of teams $3$ and $4$ have to play against team $1$ and another one against team $2$. So we have the following options: choose a permutation of the losers on this stage, then choose the order of teams in every game.

If we extrapolate that argument further, we will see that the stage with $2^i$ teams multiplies the answer by $2^{i-1}! \cdot 2^{2^{i-1}}$ (arrange the losers, then fix the order in pairs). The product over all stages is the answer.

In order to add the reserved seeds, we have to go back to solving bottom-up. 

Consider the first stage. We want to calculate its contribution to the answer, then promote the winners of each pair to the next stage and continue solving for $k = k - 1$.

Some pairs have both teams reserved. If both or neither of the teams are from $1$ to $2^{k-1}$, then the answer is immediately $0$. Otherwise, the winner is known, so we can promote it further.

Some pairs have no teams reserved. Here, we can pick the order of the teams (multiply the answer by $2$). And we basically know the winner as well — this is marked as $-1$. The loser is yet to be determined.

Some pairs have one team reserved, and that team is from $1$ to $2^{k-1}$. That team has to win in this pair, so we know who to promote. We will determine the loser later as well.

Finally, some pairs have one team reserved, and the team is from $2^{k-1}+1$ to $2^k$. We know the loser here, but the winner is marked $-1$. Still, we can promote this $-1$ further and deal with it on the later stages.

How do we arrange the losers? Well, it's almost the same as in the case with zero reserved teams. There are some pairs that are missing losers, and there are loser teams yet to be placed. We only have to choose which team goes where. So, it's (the number of pairs with no reserved loser)!.

Why can we promote the "winner" $-1$'s furthers without dealing with them immediately? Basically, that factorial term is the only place where we assign the numbers to teams. Obviously, we want to assign each team a number exactly once. And that happens only when the team loses. Once we assign some number to it, we can uniquely trace back to where this team started, since we fixed the order of each pair beforehand.

We decrease $k$ until it's equal to $0$. The answer is still the product of the combinations for each stage.

Overall complexity: $O(2^k)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MOD = 998244353;

int main() {
	int k;
	scanf("%d", &k);
	vector<int> a(1 << k);
	forn(i, 1 << k){
		scanf("%d", &a[i]);
		if (a[i] != -1) --a[i];
	}
	int ans = 1;
	for (int st = k - 1; st >= 0; --st){
		int big = 1 << st, fr = 0;
		vector<int> na(1 << st);
		forn(i, 1 << st){
			int mn = min(a[2 * i], a[2 * i + 1]);
			int mx = max(a[2 * i], a[2 * i + 1]);
			if (mn == -1){
				if (mx >= (1 << st)){
					--big;
					na[i] = -1;
				}
				else if (mx != -1){
					na[i] = mx;
				}
				else{
					na[i] = -1;
					++fr;
				}
				continue;
			}
			if ((a[2 * i] < (1 << st)) == (a[2 * i + 1] < (1 << st))){
				puts("0");
				return 0;
			}
			na[i] = mn;
			--big;
		}
		forn(_, fr) ans = ans * 2ll % MOD;
		for (int i = 1; i <= big; ++i) ans = ans * 1ll * i % MOD;
		a = na;
	}
	printf("%dn", ans);
}
```
[1837F - Editorial for Two](../problems/F._Editorial_for_Two.md "Educational Codeforces Round 149 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1837F - Editorial for Two](../problems/F._Editorial_for_Two.md "Educational Codeforces Round 149 (Rated for Div. 2)")

In the problem, we are asked to first choose $k$ problems, then fix a split into a prefix and a suffix. But nothing stops us from doing that in reverse. Let's fix the split of an entire problemset first, then choose some $l$ ($0 \le l \le k$) and $l$ problems to the left of the split and the remaining $k - l$ problems to the right of it.

That allows us to proceed with some polynomial solution already. Having fixed the split and $l$, we only have to find $l$ shortest editorials to the left and $k - l$ shortest editorials to the right. It's trivial to show that it's optimal.

That can be done in $O(n^2 \log n)$ easily or $O(n^2)$ if you think a bit more. That solution doesn't really help with the full one, so I won't elaborate.

Next, when we see something along the lines of "minimize the maximum", we think about binary search.

Let's try to apply it here. Binary search over the answer — now we want the sum of the left and the right parts of the split to be less than or equal to some fixed $x$.

More specifically, there should exist some $l$ that the sum of $l$ smallest elements to the left is $\le x$ and the sum of $k - l$ smallest elements to the right is $\le x$. Let's say it differently. There should be at least $l$ elements to the left with their sum being $\le x$, same to the right. And once more. The largest set with the sum $\le x$ to the left is of size at least $l$, same to the right.

But that doesn't really require that $l$ now, does it? Find the largest set with the sum $\le x$ to the left and to the right. The sum of their sizes should be at least $k$.

Let's calculate the size of this largest set for all prefixes and all suffixes of the array. Then we will be able to check the condition in $O(n)$.

You can precalculate the sizes for all prefixes in $O(n \log n)$. The idea is the following. Take the set for some prefix $i$. Add the $(i+1)$-st element to it. If its sum is $\le x$, then it's the new set. Otherwise, keep removing the largest element from it until the sum becomes $\le x$.

That solution is $O(n \log A \log n)$, where $A$ is the sum of the array, so you should be careful with the constant factor. For example, doing it with a multiset or with a segment tree probably won't pass. priority_queue is fast enough, though.

However, we can do it faster. Imagine a solution with the multiset. Let's replace it with a doubly-linked list.

In particular, we want the following operations: 

* insert an element in it;
* check and remove the last element from it.

If we never removed any element, we would be able to determine where to insert each element. We can just precalculate that before the binary search in $O(n \log n)$. For each element, find the largest element less than or equal to it and to the left of it. That would be the previous element when this one is inserted.

When we remove elements, it can happen that this previous element was already removed when we attempt to insert this one. We can use the specificity of the problem to avoid that issue. Notice that if we removed an element less than or equal to the current one, then the current one could never be inside an optimal multiset. So we can just skip this element.

To implement such a list, we can renumerate all elements into values from $0$ to $n-1$ (in order of $(\mathit{value}, i)$). Then, for each $i$ store the value of the previous and the next elements existing in the list. For convenience, you can also add nodes $n$ and $n+1$, denoting the tail and the head of the list.

Then insert and remove is just rearranging some links to the previous and the next elements.

Overall complexity: $O(n \log A)$ per testcase, where $A$ is the sum of the array.

 **Solution 1 (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--){
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> a(n);
		forn(i, n) scanf("%d", &a[i]);
		
		vector<int> pr(n + 1), su(n + 1);
		auto check = [&](long long x){
			forn(_, 2){
				priority_queue<int> cur;
				pr[0] = 0;
				long long cursum = 0;
				forn(i, n){
					cur.push(a[i]);
					cursum += a[i];
					while (cursum > x){
						cursum -= cur.top();
						cur.pop();
					}
					pr[i + 1] = cur.size();
				}
				reverse(a.begin(), a.end());
				swap(pr, su);
			}
			reverse(su.begin(), su.end());
			forn(i, n + 1) if (pr[i] + su[i] >= k) return true;
			return false;
		};
		
		long long l = 1, r = accumulate(a.begin(), a.end(), 0ll);
		long long res = 0;
		while (l <= r){
			long long m = (l + r) / 2;
			if (check(m)){
				res = m;
				r = m - 1;
			}
			else{
				l = m + 1;
			}
		}
		printf("%lldn", res);
	}
}
```
 **Solution 2 (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--){
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> a(n);
		forn(i, n) scanf("%d", &a[i]);
		vector<pair<int, int>> xs(n);
		forn(i, n) xs[i] = {a[i], i};
		sort(xs.begin(), xs.end());
		forn(i, n) a[i] = lower_bound(xs.begin(), xs.end(), make_pair(a[i], i)) - xs.begin();
		
		vector<int> lstpr(n), lstsu(n);
		forn(_, 2){
			set<int> cur;
			forn(i, n){
				auto it = cur.insert(a[i]).first;
				if (it == cur.begin())
					lstpr[i] = n;
				else
					lstpr[i] = *(--it);
			}
			swap(lstpr, lstsu);
			reverse(a.begin(), a.end());
		}
		
		vector<int> pr(n + 1), su(n + 1);
		vector<int> prv(n + 2), nxt(n + 2);
		
		auto check = [&](long long x){
			forn(_, 2){
				int cnt = 0;
				prv[n + 1] = n;
				nxt[n] = n + 1;
				pr[0] = 0;
				int mn = 1e9;
				long long cursum = 0;
				forn(i, n){
					if (mn < a[i]){
						pr[i + 1] = cnt;
						continue;
					}
					nxt[a[i]] = nxt[lstpr[i]];
					prv[nxt[a[i]]] = a[i];
					prv[a[i]] = lstpr[i];
					nxt[prv[a[i]]] = a[i];
					cursum += xs[a[i]].first;
					++cnt;
					while (cursum > x){
						mn = min(mn, prv[n + 1]);
						cursum -= xs[prv[n + 1]].first;
						prv[n + 1] = prv[prv[n + 1]];
						nxt[prv[n + 1]] = n + 1;
						--cnt;
					}
					pr[i + 1] = cnt;
				}
				reverse(a.begin(), a.end());
				swap(lstpr, lstsu);
				swap(pr, su);
			}
			reverse(su.begin(), su.end());
			forn(i, n + 1) if (pr[i] + su[i] >= k) return true;
			return false;
		};
		
		long long l = 1, r = 0;
		for (int x : a) r += xs[x].first;
		long long res = 0;
		while (l <= r){
			long long m = (l + r) / 2;
			if (check(m)){
				res = m;
				r = m - 1;
			}
			else{
				l = m + 1;
			}
		}
		printf("%lldn", res);
	}
}
```
