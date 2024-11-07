# Tutorial_(en)

All problem ideas belong to [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"). And he prepared all problems himself. I just helped with testing, reviewing and tutorial writing.

[1352A - Sum of Round Numbers](../problems/A._Sum_of_Round_Numbers.md "Codeforces Round 640 (Div. 4)")

 **Tutorial**
### [1352A - Sum of Round Numbers](../problems/A._Sum_of_Round_Numbers.md "Codeforces Round 640 (Div. 4)")

Firstly, we need to understand the minimum amount of round numbers we need to represent $n$. It equals the number of non-zero digits in $n$. Why? Because we can "remove" exactly one non-zero digit in $n$ using exactly one round number (so we need at most this amount of round numbers) and, on the other hand, the sum of two round numbers has at most two non-zero digits (the sum of three round numbers has at most three non-zero digits and so on) so this is useless to try to remove more than one digit using the sum of several round numbers.

So we need to find all digits of $n$ and print the required number for each of these digits. For example, if $n=103$ then $n=1 \cdot 10^2 + 0 \cdot 10^1 + 3 \cdot 10^0$, so we need two round numbers: $1 \cdot 10^2$ and $3 \cdot 10^0$.

Because the last digit of $n$ is $n \% 10$ (the remainder of $n$ modulo $10$) and we can remove the last digit of the number by integer division on $10$, we can use the following code to solve the problem:


```cpp
int n;  
cin >> n;  
vector<int> ans;  
int power = 1;  
while (n > 0) {  
	if (n % 10 > 0) {  
		ans.push_back((n % 10) * power);  
	}  
	n /= 10;  
	power *= 10;  
}  
cout << ans.size() << endl;  
for (auto number : ans) cout << number << " ";  
cout << endl;  

```
 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ans;
		int power = 1;
		while (n > 0) {
			if (n % 10 > 0) {
				ans.push_back((n % 10) * power);
			}
			n /= 10;
			power *= 10;
		}
		cout << ans.size() << endl;
		for (auto number : ans) cout << number << " ";
		cout << endl;
	}
}
```
[1352B - Same Parity Summands](../problems/B._Same_Parity_Summands.md "Codeforces Round 640 (Div. 4)")

 **Tutorial**
### [1352B - Same Parity Summands](../problems/B._Same_Parity_Summands.md "Codeforces Round 640 (Div. 4)")

Consider two cases: when we choose all odd numbers and all even numbers. In both cases let's try to maximize the maximum. So, if we choose odd numbers, let's try to take $k-1$ ones and the remainder $n-(k-1)$. But we need to sure that $n-k+1$ is greater than zero and odd. And in case of even numbers, let's try to take $k-1$ twos and the remainder $n-2(k-1)$. We also need to check that the remainder is greater than zero and even. If none of these cases is true, print "NO".

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int n1 = n - (k - 1);
		if (n1 > 0 && n1 % 2 == 1) {
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; ++i) cout << "1 ";
			cout << n1 << endl;
			continue;
		}
		int n2 = n - 2 * (k - 1);
		if (n2 > 0 && n2 % 2 == 0) {
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; ++i) cout << "2 ";
			cout << n2 << endl;
			continue;
		}
		cout << "NO" << endl;
	}
}
```
[1352C - K-th Not Divisible by n](../problems/C._K-th_Not_Divisible_by_n.md "Codeforces Round 640 (Div. 4)")

 **Tutorial**
### [1352C - K-th Not Divisible by n](../problems/C._K-th_Not_Divisible_by_n.md "Codeforces Round 640 (Div. 4)")

Suppose the answer is just $k$-th positive integer which we should "shift right" by some number. Each multiplier of $n$ shifts our answer by $1$. The number of such multipliers is $need = \lfloor\frac{k-1}{n-1}\rfloor$, where $\lfloor \frac{x}{y} \rfloor$ is $x$ divided by $y$ rounded down. So the final answer is $k + need$ ($k$-th positive integer with the required number of skipped integers multipliers of $n$).

You can also use a binary search to solve this problem :)

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int need = (k - 1) / (n - 1);
		cout << k + need << endl;
	}
}
```
[1352D - Alice, Bob and Candies](../problems/D._Alice,_Bob_and_Candies.md "Codeforces Round 640 (Div. 4)")

 **Tutorial**
### [1352D - Alice, Bob and Candies](../problems/D._Alice,_Bob_and_Candies.md "Codeforces Round 640 (Div. 4)")

This is just an implementation problem and it can be solved in $O(n)$ time but we didn't ask for such solutions so you could solve it in $O(n^2)$ or maybe even in $O(n^2 log n)$. I'll describe $O(n)$ solution anyway.

Firstly, we need to maintain several variables: $cnt$ (initially $0$, the number of moves passed), $l$ (the position of the leftmost remaining candy, initially $0$), $r$ (the position of the rightmost remaining candy, initially $n-1$), $ansl$ (the sum of candies eaten by Alice, initially $0$), $ansr$ (the sum of candied eaten by Bob, initially $0$), $suml$ (the sum of candies eaten by Alice during her last move, initially $0$) and $sumr$ (the sum of candies eaten by Bob during his last move, initially $0$).

So, let's just simulate the following process while $l \le r$: if the number of moves $cnt$ is even then now is Alice's move and we need to maintain one more variable $nsuml = 0$ — the sum of candies Alice eats during this move. How to calculate it? While $l \le r$ and $nsuml \le sumr$, let's eat the leftmost candy, so variables will change like this: $nsuml := nsuml + a_l, l := l + 1$. After all, let's add $nsuml$ to $ansl$, replace $suml$ with $nsuml$ (assign $suml := nsuml$) and increase $cnt$ by $1$. If the number of moves $cnt$ is odd then the process is the same but from the Bob's side.

I'll also add a simply implemented $O(n^2)$ solution written by Gassa below :)

 **Solution in O(n)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		int l = 0, r = n - 1;
		int suml = 0, sumr = 0;
		int cnt = 0, ansl = 0, ansr = 0;
		while (l <= r) {
			if (cnt % 2 == 0) {
				int nsuml = 0;
				while (l <= r && nsuml <= sumr) {
					nsuml += a[l++];
				}
				ansl += nsuml;
				suml = nsuml;
			} else {
				int nsumr = 0;
				while (l <= r && nsumr <= suml) {
					nsumr += a[r--];
				}
				ansr += nsumr;
				sumr = nsumr;
			}
			++cnt;
		}
		cout << cnt << " " << ansl << " " << ansr << endl;
	}
}
```
 **Solution in O(n^2)**
```cpp
// Author: Ivan Kazmenko (gassa@mail.ru)
import std.algorithm;
import std.conv;
import std.range;
import std.stdio;
import std.string;

void main ()
{
	auto tests = readln.strip.to !(int);
	foreach (test; 0..tests)
	{
		auto n = readln.strip.to !(int);
		auto a = readln.splitter.map !(to !(int)).array;
		int [2] total;
		int prev = 0;
		int moves = 0;
		while (!a.empty)
		{
			moves += 1;
			int cur = 0;
			while (!a.empty && cur <= prev)
			{
				cur += a[0];
				a = a[1..$];
			}
			total[moves % 2] += cur;
			prev = cur;
			reverse (a);
		}
		writeln (moves, " ", total[1], " ", total[0]);
	}
}
```
[1352E - Special Elements](../problems/E._Special_Elements.md "Codeforces Round 640 (Div. 4)")

 **Tutorial**
### [1352E - Special Elements](../problems/E._Special_Elements.md "Codeforces Round 640 (Div. 4)")

The intended solution for this problem uses $O(n^2)$ time and $O(n)$ memory. Firstly, let's calculate $cnt_i$ for each $i$ from $1$ to $n$, where $cnt_i$ is the number of occurrences of $i$ in $a$. This part can be done in $O(n)$.

Then let's iterate over all segments of $a$ of length at least $2$ maintaining the sum of the current segment $sum$. We can notice that we don't need sums greater than $n$ because all elements do not exceed $n$. So if the current sum does not exceed $n$ then add $cnt_{sum}$ to the answer and set $cnt_{sum} := 0$ to prevent counting the same elements several times. This part can be done in $O(n^2)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> cnt(n + 1);
		int ans = 0;
		for (auto &it : a) {
			cin >> it;
			++cnt[it];
		}
		for (int l = 0; l < n; ++l) {
			int sum = 0;
			for (int r = l; r < n; ++r) {
				sum += a[r];
				if (l == r) continue;
				if (sum <= n) {
					ans += cnt[sum];
					cnt[sum] = 0;
				}
			}
		}
		cout << ans << endl;
	}
}
```
[1352F - Binary String Reconstruction](../problems/F._Binary_String_Reconstruction.md "Codeforces Round 640 (Div. 4)")

 **Tutorial**
### [1352F - Binary String Reconstruction](../problems/F._Binary_String_Reconstruction.md "Codeforces Round 640 (Div. 4)")

Consider case $n_1 = 0$ separately and print the sting of $n_0 + 1$ zeros or $n_2 + 1$ ones correspondingly.

Now our string has at least one pair "10" or "01". Let's form the pattern "101010 ... 10" of length $n_1 + 1$. So, all substrings with the sum $1$ are satisfied. Now let's insert $n_0$ zeros before the first zero, in this way we satisfy the substrings with the sum $0$. And then just insert $n_2$ ones before the first one, in this way we satisfy the substrings with the sum $2$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n0, n1, n2;
		cin >> n0 >> n1 >> n2;
		if (n1 == 0) {
			if (n0 != 0) {
				cout << string(n0 + 1, '0') << endl;
			} else {
				cout << string(n2 + 1, '1') << endl;
			}
			continue;
		}
		string ans;
		for (int i = 0; i < n1 + 1; ++i) {
			if (i & 1) ans += "0";
			else ans += "1";
		}
		ans.insert(1, string(n0, '0'));
		ans.insert(0, string(n2, '1'));
		cout << ans << endl;
	}
}

```
[1352G - Special Permutation](../problems/G._Special_Permutation.md "Codeforces Round 640 (Div. 4)")

 **Tutorial**
### [1352G - Special Permutation](../problems/G._Special_Permutation.md "Codeforces Round 640 (Div. 4)")

If $n < 4$ then there is no answer. You can do some handwork to be sure. Otherwise, the answer exists and there is one simple way to construct it: firstly, let's put all odd integers into the answer in decreasing order, then put $4$, $2$, and all other even numbers in increasing order. To test that it always works, you can run some kind of checker locally (you can check all $1000$ tests very fast, in less than one second, this may be very helpful sometimes).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n < 4) {
			cout << -1 << endl;
			continue;
		}
		for (int i = n; i >= 1; --i) {
			if (i & 1) cout << i << " ";
		}
		cout << 4 << " " << 2 << " ";
		for (int i = 6; i <= n; i += 2) {
			cout << i << " ";
		}
		cout << endl;
	}
}
```
