# Tutorial_(en)

[991A - If at first you don't succeed...](../problems/A._If_at_first_you_don't_succeed....md "Codeforces Round 491 (Div. 2)")

 **Editorial**There are 4 groups of students — those who visited only the first restaurant, who visited only the second, who visited both places and who stayed at home. One of the easiest ways to detect all the incorrect situations is to calculate number of students in each group. For the first group it is *A* - *C*, for the second: *B* - *C*, for the third: *C* and for the fourth: *N* - *A* - *B* + *C*. Now we must just to check that there are non-negative numbers in the first three groups and the positive number for the last group. If such conditions are met the answer is the number of students in the fourth group.

 
```cpp
	int n1 = a - c;
	int n2 = b - c;
	int n3 = c;
	int n4 = n - n1 - n2 - n3;

	if (n1 >= 0 && n2 >= 0 && n3 >= 0 && n4 > 0)
		cout << n4;
	else
		cout << -1;
```
In general you are recommended to view [inclusion–exclusion principle](https://codeforces.com/https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle).

Moreover the limitations allow to go over all possible numbers of students for each group (except for the third) in *O*(*N*3) and to check whether such numbers produce a correct solution. If no correct numbers found, just print  - 1:

 
```cpp
	int n3 = c;
	for (int n1 = 0; n1 <= n; n1++)
		for (int n2 = 0; n2 <= n; n2++)
			for (int n4 = 1; n4 <= n; n4++)
				if (n1 + n3 == a && n2 + n3 == b && n1 + n2 + n3 + n4 == n) {
					cout << n4;
					return 0;
				}
	cout << -1;
```
[Solution1](https://codeforces.com/https://pastebin.com/Zy6F6Zhz)

[Solution2](https://codeforces.com/https://pastebin.com/YB289ebH)

[991B - Getting an A](../problems/B._Getting_an_A.md "Codeforces Round 491 (Div. 2)")

 **Editorial**It is necessary to use the greedy approach: of course Vasya should redo the lowest grades firstly. So we have to sort the values in the ascending order and begin to replace the values by 5 until we get the desired result. In order to check whether the current state is suitable we may calculate the mean value after each iteration (*O*(*N*2) complexity in total), or just update sum of the grades and calculate the arithmetic mean in *O*(1) with *O*(*N*) total complexity (excluding sorting). For example:

 
```cpp
bool check(int sum, int n) {
	// integer representation of sum / n >= 4.5
	return sum * 10 >= n * 45;
}

int main() {
	... // read integers to vector v and calculate sum
	sort(v.begin(), v.end());
	int ans = 0;
	while (!check(sum, n)) {
		sum += 5 - v[ans];
		ans++;
	}
	cout << ans;
}

```
Of course, both approaches easily fit TL.

Finally, it is recommended to avoid floating-point operations while calculating the mean value.

[Solution](https://codeforces.com/https://pastebin.com/cwYqVdLC)

[991C - Candies](../problems/C._Candies.md "Codeforces Round 491 (Div. 2)")

 **Editorial**It is easy to check that if for some value *k* the necessary condition is met (Vasya eats at least half of the candies), then it is met for each integer greater *k*.

 **Proof**Let's consider the number of candies remaining at the evening of each day for some selected *k*1 — let *a**i* candies remain at day *i*. If Vasya will use another number *k*2 > *k*1 we will have less candies in the first day: *b*1 < *a*1. So Petya will eat no more candies than in the first case (for *k*1), but in the next day the number of candies will be not greater than in the first case (if *n*1 > *n*2 then *n*1 - *n*1 / 10 ≥ *n*2 - *n*2 / 10). The same way, including that *k*2 > *k*1 at the evening of the second day we get *b*2 < *a*2 and so on. In general, for each *i* we have *b**i* < *a**i*, so Petya will eat not more candies than in the first case in total. It means that Vasya will eat not less candies than in the first case.

So this problem can be solved using the binary search (answer) approach. In order to check whether selected *k* is applicable it necessary just to implement the process described in the problem statement. 

 
```cpp
bool check(long long k, long long n) {
	long long sum = 0;
	long long cur = n;
	while (cur > 0) {
		long long o = min(cur, k);
		sum += o;
		cur -= o;
		cur -= cur / 10;
	}
	return sum * 2 >= n;
}
```
Since Petya eats 10% of candies, its amount decreases **exponentially**, so there will be only few days before all the candies will be eaten. In the worst case it is necessary 378 days. Formally the complexity of the solution is *O*(*log*(*n*)2).

Like in the previous problem it is recommended to avoid floating operations and to use only integer types.

[Solution](https://codeforces.com/https://pastebin.com/cYNpvWrQ)

[991D - Bishwock](../problems/D._Bishwock.md "Codeforces Round 491 (Div. 2)")

 **Editorial**In this problem we may use the greedy approach. Let's go through columns from left to right. If we are currently considering column *i* and we may place a figure occupying only cells at columns *i* and *i* + 1, we have to place this figure. Really if the optimal solution doesn't contain a bishwock at column *i* then column *i* + 1 may be occupied by at most one bishwock. So we can remove this figure and place it at columns *i* and *i* + 1, the result will be at least the same. 

A bit harder question is — how exactly we should place the figure if all 4 cells of columns *i* and *i* + 1 are empty (in other cases there will be only one way to place a bishwock)? Of course, we should occupy both cells of column *i*. Moreover it does not matter which cell we will occupy at column *i* + 1 in this case. The cells of *i* + 1 may be used only for placing a bishwock in columns *i* + 1,*i* + 2. If column *i* + 2 has at most one empty cell we are unable to place such figure and the remaining empty cells of column *i* + 1 are useless at all. If both cells of column *i* + 2 are empty we may place a bishwock regardless of the position of the remaining empty cell at column *i* + 1.

It means that we don't have to place the figures actually — we have to calculate and update number of empty cells in columns. According to the described algorithm we may write such code:

 
```cpp
	... // read strings s[0] and s[1]
	int ans = 0;
	int previous = 0;
	for (int i = 0; i < n; i++) {
		int current = (s[0][i] == '0') + (s[1][i] == '0');
		if (current == 0)
			previous = 0;
		if (current == 1) {
			if (previous == 2) {
				ans++;
				previous = 0;
			}
			else
				previous = 1;
		}
		if (current == 2) {
			if (previous > 0) {
				ans++;
				if (previous == 2)
					previous = 1;
				else
					previous = 0;
			}
			else
				previous = 2;
		}
	}
```
Moreover this implementation can be simplified to just two cases:

 
```cpp
	int ans = 0;
	int empty = 0;
	for (int i = 0; i < n; i++) {
		int current = (s[0][i] == '0') + (s[1][i] == '0');
		empty += current;
		if (empty >= 3) {
			empty -= 3;
			ans++;
		}
		else
			empty = current;
	}
```
Formally such algorithm may be considered as the dynamic programming. Of course it is not necessary to have a deep understanding of DP to write such implementation and solve the problem.

This problem also can be solved by more ''obvious'' DP approach (for example we may consider index of current column and state of the cells of the previous column as a state of DP). In this case the implementation will be a bit more complicated but it won't be necessary to prove described solution.

[Solution1](https://codeforces.com/https://pastebin.com/4L3kwNWZ)

[Solution2](https://codeforces.com/https://pastebin.com/4dnyBusL)

[991E - Bus Number](../problems/E._Bus_Number.md "Codeforces Round 491 (Div. 2)")

 **Editorial**According to the statement, digits of original bus number form a subset of digits of the number seen by Vasya. It is possible to iterate through all the subsets in 2*k* operations (where *k* is length of *n*). For each subset we need to check whether it is correct (contains all necessary digits) and transform it to ''normal'' state (sort the digits for example), in order to avoid conflicts with another subsets which differ only at the digits order. We have to keep only unique subsets.

 
```cpp
	long long ans = 0;
	for (int i = 1; i <= (1 << k); i++) {
		string c;
		for (int j = 0; j < k; j++)
			if (i & (1 << j))
				c += n[j];
		ans += getans(c);
	}
```
Now for each subset of digits we have to calculate amount of corresponding correct bus numbers. It can be calculated in *O*(*k*) operations using permutations of multisets formula (see ''Permutations of multisets'' at the article about [permutations](https://codeforces.com/https://en.wikipedia.org/wiki/Permutation#Permutations_of_multisets) and [multinomial coefficients](https://codeforces.com/https://en.wikipedia.org/wiki/Multinomial_theorem))

*C* = *k*! / (*c*0! * *c*1! * ... * *c*9!), 

where *k* — total number of digits in the subset and *c**i* — number of digits *i*:

 
```cpp
long long fact[20];
int c[10];

void split(string s, int *c) {
	for (int i = 0; i < 10; i++)
		c[i] = 0;
	for (char ch : s)
		c[ch - 48]++;
}

long long getCount() {
	long long ans = fact[accumulate(c, c + 10, 0)];
	for (int i = 0; i < 10; i++)
		ans /= fact[c[i]];
	return ans;
}
```
Now, we have to subtract amount of bus numbers with leading zeroes from the result for this subset if it contains digit 0. This can be done in the very same way: if we place digit 0 at the first position of the number, we have to decrease *k* by 1 and decrease *c*0 by 1; the formula described above will calculate amount of ways to place remaining digits of the subset and this number should be subtract from the answer:

 
```cpp
long long getans(string s) {
	split(s, c);

	// check whether the string contains all digits
	for (int i = 0; i < 10; i++)
		if (c0[i] && !c[i])
			return 0;

	// check whether we already processed such string
	sort(s.begin(), s.end());
	if (was.count(s))
		return 0;
	was.insert(s);

	long long ans = getCount();
	if (c[0] > 0) {
		c[0]--;
		ans -= getCount();
	}
	return ans;
}
```
In total, even with such rough evaluation of complexity and naive implementation we get *O*(2*k* * *k*) operations, where *k* ≤ 19 — amount of digits in *n*. It is easy to check that the answer doesn't exceed 1018 so the standard 64-bit integer type will be enough.

[Solution](https://codeforces.com/https://pastebin.com/CY5V5dDz)

[991F - Concise and clear](../problems/F._Concise_and_clear.md "Codeforces Round 491 (Div. 2)")

 **Editorial**All the problem numbers (except for 1010, which is given in the samples) contain at most 10 digits. It means that we have to use at most 9 digits if we want to find a shorter representation. Notice that the length of sum of two integers is not greater than sum of the lengths of these integers, so in the optimal representation at most one term is a number while other terms are expressions containing `*` and/or `^`. Each expression (not a number) contains at least 3 symbols, so the optimal representation can contain at most 3 terms. The maximal integer that can be represented in such manner is `9^9+9^9+9`, but it contains only 9 digits while expressions with 3 terms always contain at least 9 symbols. So we proved that there always exists an optimal representation which is a sum of at most two terms.

So there exist only 3 types of representation of the original number:

 1. `n = a^b`
2. `n = x+y`
3. `n = x*y`

where *x* and *y* — some expressions (in the first case *a* and *b* are numbers), which doesn't contain `+`. Moreover in all the cases such expressions should contain at most 7 digits.

Let's find for each *x* ≤ *n* a shortest valid representation *m*[*x*], containing at most 7 symbols (if it exists and contains less digits than simple number *x*), and for each length *d* — set of integers *s*[*d*] which can be represented by an expression of length *d*. The standard containers (std::map and std::set в C++) are suitable for that:

 
```cpp
map<long long, string> m;
set<long long> s[10];

string get(long long x) {
	if (m.count(x))
		return m[x];
	return toString(x);
}

void relax(long long x, string str) {
	// obviously not optimal
	if (x > n || str.length() >= getlen(x))
		return;

	// already have better
	if (m.count(x) && m[x].length() <= str.length())
		return;

	s[m[x].length()].erase(x);
	m[x] = str;
	s[str.length()].insert(x);
}
```
Firstly let's add all expressions `a^b`, there are about `sqrt(n)` such expressions. 

 
```cpp
void generatePowers() {
	for (long long x = 2; x * x <= n; x++) {
		long long c = x * x;
		int p = 2;
		while (c <= n) {
			string tmp = toString(x) + "^" + toString(p);
			relax(c, tmp);
			c *= x;
			p++;
		}
	}
}
```
Now lets consider the expressions containing several multipliers. The same way (as for addition) in such representation at most one multiplier is a number. Including that the expression can contain at most 7 digits we have only 2 possible ways:

 1. `x = a^b*c^d`
2. `x = a^b*c`

where *a*, *b*, *c* and *d* are some numbers. Lets iterate through *i* — the length of the representation of the first multiplier and go over all values stored in *s*[*i*]. The second multiplier can have length at most *d* = 7 - *i* - 1 and the total number of ways to choose two multipliers will be small enough. The second multiplier should be selected from containers *s*[*j*] for length at most *d* (in the first case), or we should iterate from 1 to 10*d* (in the second case). After that we will have about *k* = 150000 numbers in *m* in total:

 
```cpp
void generatePowerAndPower(int maxlen) {
	for (int i = 1; i <= maxlen; i++)
		for (int j = i; i + j + 1 <= maxlen; j++)
			for (auto x : s[i])
				for (auto y : s[j])
					relax(x * y, get(x) + "*" + get(y));
}

void generateSimpleAndPower(int maxlen) {
	for (int i = 1; i + 2 <= maxlen; i++)
		for (long long x = 1; x < p10[maxlen - 1 - i]; x++)
			for (long long y : s[i])
				relax(x * y, toString(x) + "*" + get(y));
}

void precalc() {
	generatePowers();
	generatePowerAndPower(7);
	generateSimpleAndPower(7);
}
```
Now lets go back to the representation of the original number. For the first case — `a^b` — we have already stored such values in *m*. For the cases `x+y` and `x*y` we may assume that the length of expression of *x* is not greater than 4. Now lets iterate through *x* among found representations of length up to 4, and among integers from 1 to 104. For each such *x* and for each of 2 cases we determine value of *y* uniquely, and the optimal representation of *y* is already stored in *m* or it is just a number. So, for each such *x* we can find optimal answer for *n* by at most two addressing to *m* i.e. in *log*(*k*) operations. 

 
```cpp
string ans;
void relaxAns(string s) {
	if (ans.length() > s.length())
		ans = s;
}

void check2() {
	for (int i = 1; i * 2 + 1 < ans.length(); i++) {
		for (long long x = 1; x <= p10[i]; x++) {
			relaxAns(get(n - x) + "+" + get(x));
			if (n % x == 0)
				relaxAns(get(n / x) + "*" + get(x));
		}
		for (auto x : s[i]) {
			relaxAns(get(n - x) + "+" + get(x));
			if (n % x == 0)
				relaxAns(get(n / x) + "*" + get(x));
		}
	}
}

int main() {
	... // read n, calculate powers of 10
	precalc();
	ans = get(n);
	check2();
	cout << ans;
}
```
Finally, the total algorithm complexity is *O*((*sqrt*(*n*) + *k* + 104) * *log*(*k*)).

[Solution](https://codeforces.com/https://pastebin.com/77nTfkWQ)

