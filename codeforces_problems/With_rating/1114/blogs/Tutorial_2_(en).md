# Tutorial_2_(en)

*Model solutions are now available.*  
*[GreenGrape](https://codeforces.com/profile/GreenGrape "Master GreenGrape") and I will write more about problem F, including an alternative data structures (still quite tight on time limit) ;)*

[1114A - Got Any Grapes?](../problems/A._Got_Any_Grapes_.md "Codeforces Round 538 (Div. 2)")
---------------------------------------------------------------------------------------------------------

Author: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [GreenGrape](https://codeforces.com/profile/GreenGrape "Master GreenGrape")  
Development: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [GreenGrape](https://codeforces.com/profile/GreenGrape "Master GreenGrape"), [neko_nyaaaaaaaaaaaaaaaaa](https://codeforces.com/profile/neko_nyaaaaaaaaaaaaaaaaa "Master neko_nyaaaaaaaaaaaaaaaaa")  
Editorialist: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus") 

 **Tutorial**First of all, we can see the grape preference is hierarchically inclusive: the grapes' types Andrew enjoys are some of those that Dmitry does, and Dmitry's favorites are included in Michal's.

Let's distribute the grapes to satisfy Andrew first, then to Dmitry, then Michal. If any of the following criteria is not satisfied (which means one of our friends is not happy), then we can immediately say that no distributions are available:

 * Andrew must have at least *a* green grapes. So we need, *x* ≤ *a*.
* Dmitry can have purple grapes and/or the remaining green grapes. In other words, *y* ≤ *a* + *b* - *x* (the minus *x* is because *x* green grapes have been given to Andrew already).
* Michal can have grapes of any kinds. In other words, *z* ≤ *a* + *b* + *c* - *x* - *y* (similar explanations like above for both minus *x* and minus *y*).

If all three criteria are satisfied, then a grape distribution is possible.

Total complexity: ![](images/c49c1b7e387d521abbea6a5b59931c15c56dca9b.png).

 **Solution (Akikaze)**Submission link: [49737634](https://codeforces.com/contest/1114/submission/49737634 "Submission 49737634 by AkiLotus")

 **Source code in plain text**
```cpp
#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl 'n'

int x, y, z, a, b, c;

void Input() {
	cin >> x >> y >> z;
	cin >> a >> b >> c;
}

void Solve() {
	if (x > a) {cout << "NOn"; return;}
	if (x + y > a + b) {cout << "NOn"; return;}
	if (x + y + z > a + b + c) {cout << "NOn"; return;}
	cout << "YESn";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); Input(); Solve();
	return 0;
}
```
[1114B - Yet Another Array Partitioning Task](../problems/B._Yet_Another_Array_Partitioning_Task.md "Codeforces Round 538 (Div. 2)")
-----------------------------------------------------------------------------------------------------------------------------

Author: [xuanquang1999](https://codeforces.com/profile/xuanquang1999 "Grandmaster xuanquang1999")  
Development: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [xuanquang1999](https://codeforces.com/profile/xuanquang1999 "Grandmaster xuanquang1999")  
Editorialist: [xuanquang1999](https://codeforces.com/profile/xuanquang1999 "Grandmaster xuanquang1999"), [neko_nyaaaaaaaaaaaaaaaaa](https://codeforces.com/profile/neko_nyaaaaaaaaaaaaaaaaa "Master neko_nyaaaaaaaaaaaaaaaaa") 

 **Tutorial**In a perfect scenario, the maximum beauty of the original array is just a sum of *m*·*k* largest elements. 

In fact, such scenario is always available regardless of the elements.

Let's denote *A* as the set of these *m*·*k* largest elements. The solution for us will be dividing the array into *k* segments, such that each segment contains exactly *m* elements of *A*. Just make a split between corresponding elements in the set *A*.

Depending on the way we find *m*·*k* largest elements, the time complexity might differ.

If we simply do so after sorting the entire array by usual means, the time complexity will be ![](images/0d8aa761c1935375e54d4ae05c77815a3bc26901.png).

However, we can use [`std::nth_element` function](https://codeforces.com/http://www.cplusplus.com/reference/algorithm/nth_element/) instead of sorting the entire array. The idea is to sort the array in such a way that, every elements not higher than a value *v* will be stored in the left side, other elements will stay on the right, and this works in linear time (a.k.a. ![](images/75c1cc685b678543b1630d9159eed84639cf6a8e.png) time complexity).

An example implementation of such ordering can be shown [here](https://codeforces.com/https://cp-algorithms.com/sequences/k-th.html).

 **Solution (xuanquang1999)**Submission link: [49737896](https://codeforces.com/contest/1114/submission/49737896 "Submission 49737896 by AkiLotus")

 **Source code in plain text**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end(), greater<pii>());

    vector<int> ind(m*k);
    ll sumBeauty = 0;
    for(int i = 0; i < m*k; ++i) {
        sumBeauty += a[i].first;
        ind[i] = a[i].second;
    }

    sort(ind.begin(), ind.end());

    vector<int> division(k-1);
    for(int i = 0; i < k-1; ++i)
        division[i] = ind[(i+1)*m - 1];

    cout << sumBeauty << endl;
    for(int p: division)
        cout << p + 1 << " ";

    return 0;
}
```
[1114C - Trailing Loves (or L'oeufs?)](../problems/C._Trailing_Loves_(or_L'oeufs_).md "Codeforces Round 538 (Div. 2)")
----------------------------------------------------------------------------------------------------------------------

Author: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus")  
Development: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [majk](https://codeforces.com/profile/majk "International Grandmaster majk"), [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot")  
Editorialist: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus") 

 **Tutorial**The problem can be reduced to the following: finding the maximum *r* that *n* ! is divisible by *b**r*.

By prime factorization, we will have the following: *b* = *p*1*y*1·*p*2*y*2·...·*p**m**y**m*.

In a similar manner, we will also have: *n* ! = *p*1*x*1·*p*2*x*2·...·*p**m**x**m*·*Q* (with *Q* being coprime to any *p**i* presented above).

The process of finding *p*1, *p*2, ..., *p**m*, *y*1, *y*2, ..., *y**m* can be done by normal prime factorization of the value *b*.

The process of finding *x*1, *x*2, ..., *x**m* is a little bit more tricky since the integer they were originated (*n* !) is too huge to be factorized manually. Still the factorial properties gave us another approach: for each *p**i*, we can do the following:

 * Initially, denote *x**i* = 0.
* Repeatedly do the following: add ![](images/39e8e6da50420d3b2652aaa25427f36b605d55b0.png) to *x**i*, then divide *n* by *p**i*. The loop ends when *n* is zero.

After all, we can obtain the final value *r* as of following: ![](images/49455eb6083bdc6538d540bbfddd0fc734a41fab.png).

Total complexity: ![](images/85fc20c8566b05180d80228077d5747fcabdcc98.png) (as the number of prime factors of an integer *b* will not surpass ![](images/a2d5a43faf30159f1fbfedd840fedceb806abedf.png)).

 **Solution (Akikaze)**Submission link: [49738076](https://codeforces.com/contest/1114/submission/49738076 "Submission 49738076 by AkiLotus")

 **Source code in plain text**
```cpp
#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl 'n'

long long n, b;

void Input() {
	cin >> n >> b;
}

void Solve() {
	long long ans = 1000000000000000000LL;
	for (long long i=2; i<=b; i++) {
		if (1LL * i * i > b) i = b;
		int cnt = 0;
		while (b % i == 0) {b /= i; cnt++;}
		if (cnt == 0) continue;
		long long tmp = 0, mul = 1;
		while (mul <= n / i) {mul *= i; tmp += n / mul;}
		ans = min(ans, tmp / cnt);
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
```
[1114D - Flood Fill](../problems/D._Flood_Fill.md "Codeforces Round 538 (Div. 2)")
----------------------------------------------------------------------------------------------------

Author: [neko_nyaaaaaaaaaaaaaaaaa](https://codeforces.com/profile/neko_nyaaaaaaaaaaaaaaaaa "Master neko_nyaaaaaaaaaaaaaaaaa")  
Development: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [neko_nyaaaaaaaaaaaaaaaaa](https://codeforces.com/profile/neko_nyaaaaaaaaaaaaaaaaa "Master neko_nyaaaaaaaaaaaaaaaaa"), [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot")  
Editorialist: [neko_nyaaaaaaaaaaaaaaaaa](https://codeforces.com/profile/neko_nyaaaaaaaaaaaaaaaaa "Master neko_nyaaaaaaaaaaaaaaaaa"), [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot") 

 **Tutorial**This problem was inspired by the game Flood-it. It is apparently NP-hard. You can try out the game here. https://www.chiark.greenend.org.uk/\%7Esgtatham/puzzles/js/flood.html

**The first solution is rather straightforward.** Suppose squares [*L*, *R*] are flooded, then they are either of color *c**L* or *c**R*. We can define ![](images/38d46bdd4bd15e4a14b68f6d804e78ce7c80dc8a.png) as the minimum number of moves required to make the segment [*L*, *R*] monochromic:

 * ![](images/f2909ee2b2ff4d0aad96b15b230dc95fcb102d78.png) is the least moves required to make the segment having color *c**L*.
* ![](images/fc7d5e0c46176edf5a3d098604a9cf073a6eebca.png) is the least moves required to make the segment having color *c**R*.

**The second solution, which is the author's intended solution, is less so.** Note that the size of the component doesn't matter, so first "compress" the array so that every adjacent elements are different. We will work on this compressed array instead.

We want to maximize the number of turns that we can fill two adjacent squares instead of one. From a starting square, this maximum number of "saved" turns is equal to the longest common subsequence (LCS) of the array expanding to the two sides. The answer is the *N* — (maximum LCS over all starting squares)

This is equivalent to finding the longest odd size palindrome subsequence. In fact, it is the longest palindrome subsequence. For every even-sized palindrome subsequence, since adjacent elements are different, we can just insert an element in the middle and obtain a longer palindrome subsequence.

To find the longest palindrome subsequence, we can make a reversed copy of the array and find LCS of it with the original array.

Alternatively, we can also use the first solution on the compressed array, without needing the third parameter.

Time complexity: ![](images/a5c1bdb62f55c836c0ae70ab80c99ad6cdd0bbed.png).

 **Solution 1 (_kun_)**Submission link: [49738289](https://codeforces.com/contest/1114/submission/49738289 "Submission 49738289 by AkiLotus")

 **Source code in plain text**
```cpp
// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

int dp[5000][5000][2];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    vector<int> a(n);
    input_seq(ALL(a));

    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            dp[i][j][0] = dp[i][j][1] = (i == j ? 0 : TYPEMAX(int) / 2);
    

    for (int r = 0; r != n; ++r)
        for (int l = r; l >= 0; --l)
            for (int it = 0; it != 2; ++it) {
                int c = (it == 0 ? a[l] : a[r]);
                
                if (l)
                    dp[l - 1][r][0] = min(dp[l - 1][r][0], dp[l][r][it] + int(c != a[l - 1]));

                if (r + 1 != n)
                    dp[l][r + 1][1] = min(dp[l][r + 1][1], dp[l][r][it] + int(c != a[r + 1]));
            }

    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << "n";
    
    return 0;
}
```
 **Solution 2 (neko_nyaa)**Submission link: [49738394](https://codeforces.com/contest/1114/submission/49738394 "Submission 49738394 by AkiLotus")

 **Source code in plain text**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxN = 5008;

int n;
int dp[maxN][maxN];
vector<int> a(1), b;
vector<int> ans;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x != a.back()) a.push_back(x);
	}
	n = a.size() - 1;

	b = a;
	reverse(b.begin() + 1, b.end());
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) {dp[i][j] = dp[i-1][j-1] + 1;}
			else {dp[i][j] = max(dp[i-1][j], dp[i][j-1]);}
		}
	}
}

void output() {
	cout << n - (dp[n][n] + 1)/2 << 'n';
}

int main() {
	
	input();
	solve();
	output();
	
	return 0;
}
```
[1114E - Arithmetic Progression](../problems/E._Arithmetic_Progression.md "Codeforces Round 538 (Div. 2)")
----------------------------------------------------------------------------------------------------------------

Author: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus")  
Development: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [GreenGrape](https://codeforces.com/profile/GreenGrape "Master GreenGrape")  
Editorialist: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [xuanquang1999](https://codeforces.com/profile/xuanquang1999 "Grandmaster xuanquang1999") 

 **Tutorial**The `>` query type allows you to find the max value of the array through binary searching, which will cost ![](images/bbc77edea90c1ded03bf8dca871e18e39f9d41d2.png) queries.

The remaining queries will be spent for the queries of the `?` type to get some random elements of the array. *d* will be calculated as greatest common divisors of all difference between all consecutive elements, provided all elements found (yes, including the `max` one) is kept into a list sorted by increasing order.

Having `d` and `max`, we can easily find the `min` value: *min* = *max* - *d*·(*n* - 1).

The number of allowed queries seem small (30 queries to be exact), yet it's enough for us to have reasonable probability of passing the problem.

*By some maths, we can find out the probability of our solution to fail being relatively small — approximately 1.86185·10- 9.*

 **Proof on the probability, written by xuanquang1999**For simplicity, assumed that the sequence *a* is [0, 1, 2, ..., *n* - 1]. Suppose that we randomly (and uniformly) select a subsequence *S* containing *k* elements from sequence *a* (when *k* is the number of `?` query asked). Denote *S* = [*s*1, *s*2, ..., *s**k*]. 

Let *D* the GCD of all difference between consecutive elements in *S*. In other word, ![](images/d4cb33976c0819d88da8c93e6da1e30f0e2a515a.png). Our solution will success if *D* = 1 and will fail otherwise. Let *P* the probability that our solution will pass (*D* = 1). Then the failing probability is 1 - *P*.

We will apply [Möbius inversion](https://codeforces.com/blog/entry/53925) to calculate *P*: Let *f*(*x*) the probability that *D* is divisible by *x*. Then, ![](images/b884f5679f342a3c1d056982bfe2ca11cb49a61b.png) (where μ(*x*) is the Möbius function).

Now we need to calculate *f*(*x*). It can be shown that *D* is divisible by *x* if and only if ![](images/910abdac77ffc5a5e4fd04de8b316d754b17c09e.png) for all 2 ≤ *i* ≤ *k*. In other word, there is some *r* from 0 to *x* - 1 such that ![](images/c8f530998ab41edcc70982e671e8f21f16109730.png) for all 1 ≤ *i* ≤ *k*.

Let *g*(*r*) the number of ways to select a subsequence *S* such that ![](images/c8f530998ab41edcc70982e671e8f21f16109730.png) for all 1 ≤ *i* ≤ *k*. Then, according to definition: 

![](images/054f51e4235dca832bcda559601d98e14322ad69.png)

The denominator is simply ![](images/3b6fb2d742f7434e0b1d8be541f1896f7422081e.png). To calculate *g*(*r*), notice that for each *i*, the value of *s**i* can be *x*·*j* + *r* for some integer *j*. In other word, *S* must be a subsequence of the sequence *a**r* = [*r*, *x* + *r*, 2*x* + *r*, ...]. Let ![](images/fe3ab82380275a6174833989bf9fd184e68baf54.png).

 * If ![](images/f58b4393bc8cfd90f455a0c6b1b0bb818add67c4.png), *a**r* has *q* + 1 elements. Therefore, ![](images/23c8043fa8a48cac2637c6da0c60677b211a572a.png)
* If ![](images/8bcc22bdfeb738db1736fab5273d438362f7a185.png), *a**r* has *q* elements. Therefore, ![](images/4495db96569f8c098827c795817e681dc55765f8.png).

In summary:

![](images/878f3296b60cfb91d682e5d338adcb71b850ae4a.png)

The complexity of this calculating method is *O*(*n*). My implementation of the above method can be found [here](https://codeforces.com/https://ideone.com/IHmndY).

Keep in mind to use a good random number generator and a seed which is hard to obtain, thus making your solution truly random and not falling into corner cases.

Some of the tutorials of [neal](https://codeforces.com/profile/neal "International Grandmaster neal") might be helpful:

[Don't use rand(): a guide to random number generators in C++](https://codeforces.com/blog/entry/61587)  
[How randomized solutions can be hacked, and how to make your solution unhackable](https://codeforces.com/blog/entry/61675)

 **Solution (Akikaze)**Submission link: [49739271](https://codeforces.com/contest/1114/submission/49739271 "Submission 49739271 by AkiLotus")

 **Source code in plain text**
```cpp
#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl 'n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

int n, Max = -1000000000, d = 0;
int queryRemaining = 60; vector<int> id;

void findMax() {
	int top = -1000000000, bot = +1000000000;
	while (top <= bot) {
		int hasHigher;
		int mid = (top + bot) / 2;
		cout << "> " << mid << endl;
		fflush(stdout); cin >> hasHigher;
		queryRemaining--;
		if (hasHigher) top = mid + 1;
		else {bot = mid - 1; Max = mid;}
	}
}

void findD() {
	vector<int> List; int RandomRange = n;
	while (queryRemaining > 0 && RandomRange > 0) {
		int demandedIndex = rng32() % RandomRange;
		cout << "? " << id[demandedIndex] << endl; fflush(stdout);
		int z; cin >> z; List.push_back(z);
		RandomRange--; queryRemaining--;
		swap(id[demandedIndex], id[RandomRange]);
	}
	sort(List.begin(), List.end());
	if (List.back() != Max) List.push_back(Max);
	for (int i=1; i<List.size(); i++) {
		d = __gcd(d, List[i] - List[i-1]);
	}
}

void Input() {
	cin >> n; id.resize(n);
	for (int i=0; i<n; i++) id[i] = i+1;
}

void Solve() {
	findMax(); findD();
	int Min = Max - d * (n - 1);
	cout << "! " << Min << " " << d;
	cout << endl; fflush(stdout);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	Input(); Solve(); return 0;
}
```
[1114F - Please, another Queries on Array?](../problems/F._Please,_another_Queries_on_Array_.md "Codeforces Round 538 (Div. 2)")
---------------------------------------------------------------------------------------------------------------------------

Author: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot")  
Development: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [GreenGrape](https://codeforces.com/profile/GreenGrape "Master GreenGrape"), [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot")  
Editorialist: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [GreenGrape](https://codeforces.com/profile/GreenGrape "Master GreenGrape"), [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot") 

 **Tutorial**There's a few fundamentals about Euler's totient we need to know:

 * φ(*p*) = *p* - 1 and φ(*p**k*) = *p**k* - 1·(*p* - 1), provided *p* is a prime number and *k* is a positive integer. You can easily prove these equations through the definition of the function itself.
* Euler's totient is a **multiplicative function**. *f*(*x*) is considered a multiplicative function when ![](images/56be750d1b80485d64aa09138a04c51659bf83f5.png) means *f*(*a*)·*f*(*b*) = *f*(*a*·*b*).

Keep in mind that we can rewrite φ(*p**k*) as of following: ![](images/30c53e477789d35253523b18c801d0c2cad7e540.png).

Let's denote *P* as the set of prime factors of ![](images/66ffde9ad104df54167d646a96e4a566f4279583.png).

Thus, the answer for each query will simply be: ![](images/67dab5c7e4cfa06fe316b76654942075656f4c1d.png).

So, for each query we'll need to know the product of the elements, and which primes are included in that product.

There are a few ways to work around with it. One of the most effective way is as following:

 * Create a product segment tree to maintain the segment products.
* Since ![](images/d4353050eb004a4cb99885196096a42912ad7c36.png) only depends on the appearance or non-appearance of the primes, and the constraints guaranteed us to have at most 62 prime factors, we can use bitmasks and an or-sum segment tree to maintain this part.

Also, the bitmasks and range products can be maintained in a sqrt-decomposition fashion (please refer to [GreenGrape](https://codeforces.com/profile/GreenGrape "Master GreenGrape")'s solution), making each query's complexity to be somewhat around ![](images/df2e6b06a1b79c80d0fd56d707697d8c26801437.png). Still, this complexity is quite high and surpassed time limit on a pretty thin margin.

Complexity for initializing segment trees: ![](images/143ad93bdeff80c2f3c41631e7377ab44d9b9caa.png).

Complexity for each update query: ![](images/185d58accd05908ace68200a6dc258d95e1eaa79.png).

Complexity for each return query: ![](images/185d58accd05908ace68200a6dc258d95e1eaa79.png).

 **Solution 1a (_kun_)**Submission link: [49739509](https://codeforces.com/contest/1114/submission/49739509 "Submission 49739509 by AkiLotus")

 **Source code in plain text**
```cpp
// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

const int mod = 1000 * 1000 * 1000 + 7;

int add(int a, int b) {
    return (a + b >= mod ? a + b - mod : a + b);
}

int sub(int a, int b) {
    return (a >= b ? a - b : mod + a - b);
}

int mult(int a, int b) {
    return (int64_t(a) * b) % mod;
}

int fpow(int a, int n, int r = 1) {
    while (n) {
        if (n % 2)
            r = mult(r, a);

        n /= 2;
        a = mult(a, a);
    }

    return r;
}


const int max_n = 4.1e5;
int tree[4 * max_n];
int modif[4 * max_n];
int64_t pmask[4 * max_n], pushmask[4 * max_n];

vector<int> primes, revprimes;

void build(int v, int l, int r, vector<int>& a) {
    modif[v] = 1;
    
    if (l == r - 1) {
        tree[v] = a[l];

        for (int i = 0; i != SZ(primes); ++i)
            if (a[l] % primes[i] == 0)
                pmask[v] |= (int64_t(1) << int64_t(i));
    } else {
        int m = l + (r - l) / 2;
        build(2 * v + 1, l, m, a);
        build(2 * v + 2, m, r, a);

        tree[v] = mult(tree[2 * v + 1], tree[2 * v + 2]);
        pmask[v] = pmask[2 * v + 1] | pmask[2 * v + 2];
    }
}

void push(int v, int vl, int vr) {
    if (modif[v] != 1)
        tree[v] = fpow(modif[v], vr - vl, tree[v]);

    pmask[v] |= pushmask[v];
    
    if (vl != vr - 1) {
        modif[2 * v + 1] = mult(modif[2 * v + 1], modif[v]);
        modif[2 * v + 2] = mult(modif[2 * v + 2], modif[v]);

        pushmask[2 * v + 1] |= pushmask[v];
        pushmask[2 * v + 2] |= pushmask[v];
    }

    modif[v] = 1;
    pushmask[v] = 0;
}

pair<int, int64_t> get(int v, int vl, int vr, int l, int r) {
    if (vr <= l or r <= vl)
        return make_pair<int, int64_t>(1, 0);
    
    push(v, vl, vr);

    if (l <= vl and vr <= r)
        return make_pair(tree[v], pmask[v]);

    int vm = vl + (vr - vl) / 2;
    
    auto r1 = get(2 * v + 1, vl, vm, l, r);
    auto r2 = get(2 * v + 2, vm, vr, l, r);

    return make_pair(mult(r1.first, r2.first), r1.second | r2.second);
}

void multiply(int v, int vl, int vr, int l, int r, int x, int64_t mask) {
    if (vr <= l or r <= vl)
        return;

    push(v, vl, vr);
    
    if (l <= vl and vr <= r) {
        pushmask[v] = mask;
        modif[v] = x;
        return;
    }

    int vm = vl + (vr - vl) / 2;
    
    multiply(2 * v + 1, vl, vm, l, r, x, mask);
    multiply(2 * v + 2, vm, vr, l, r, x, mask);

    pmask[v] = pmask[2 * v + 1] | pmask[2 * v + 2] | pushmask[2 * v + 1] | pushmask[2 * v + 2];
    tree[v] = fpow(x, min(vr, r) - max(l, vl), tree[v]);
}


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    for (int i = 2; i <= 300; ++i) {
        bool ok = true;
        for (int j = 2; j * j <= i and ok; ++j)
            if (i % j == 0)
                ok = false;

        if (ok) {
            primes.push_back(i);
            revprimes.push_back(fpow(i, mod - 2));
        }
    }

    int n = input<int>();
    int q = input<int>();

    vector<int> a(n);
    input_seq(ALL(a));

    build(0, 0, n, a);

    for (int it = 0; it != q; ++it) {
        if (input<string>() == "TOTIENT") {
            int l = input<int>() - 1;
            int r = input<int>() - 1;
            
            pair<int, uint64_t> prod = get(0, 0, n, l, r + 1);
            for (int i = 0; i != SZ(primes); ++i)
                if (prod.second & (int64_t(1) << int64_t(i)))
                    prod.first = mult(mult(prod.first, primes[i] - 1), revprimes[i]);

            cout << prod.first << "n";
        } else {
            int l = input<int>() - 1;
            int r = input<int>() - 1;
            int x = input<int>();

            int64_t msk = 0;
            for (int i = 0; i != SZ(primes); ++i)
                if (x % primes[i] == 0)
                    msk |= (int64_t(1) << int64_t(i));

            multiply(0, 0, n, l, r + 1, x, msk);
        }
    }
    
    return 0;
}
```
 **Solution 1b (Akikaze) [literally kun's solution, yet shorter, and a bit uglier :P]**Submission link: [49740091](https://codeforces.com/contest/1114/submission/49740091 "Submission 49740091 by AkiLotus")

 **Source code in plain text**
```cpp
#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl 'n'

const int Mod = 1000000007;

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137
,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293}; // (size = 62)

int modPow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 0) {a = (1LL * a * a) % Mod; b /= 2;}
        else {res = (1LL * res * a) % Mod; b -= 1;}
    }
    return res;
}

struct ProTree {
	vector<int> Tree, Lazy;
	ProTree() {}
	ProTree(int n) {Tree.resize(n*4, 1); Lazy.resize(n*4, 1);}
	
	void Propagate(int node, int st, int en) {
		if (Lazy[node] == 1) return;
		Tree[node] = (1LL * Tree[node] * modPow(Lazy[node], (en - st + 1))) % Mod;
		if (st != en) {
			Lazy[node*2+1] = (1LL * Lazy[node*2+1] * Lazy[node]) % Mod;
			Lazy[node*2+2] = (1LL * Lazy[node*2+2] * Lazy[node]) % Mod;
		}
		Lazy[node] = 1;
	}
	
	void Multiply(int node, int st, int en, int L, int R, int val) {
		Propagate(node, st, en);
		if (st > en || en < L || R < st) return;
		if (L <= st && en <= R) {
			Lazy[node] = (1LL * Lazy[node] * val) % Mod;
			Propagate(node, st, en); return;
		}
		Multiply(node*2+1, st, (st+en)/2+0, L, R, val);
		Multiply(node*2+2, (st+en)/2+1, en, L, R, val);
		Tree[node] = (1LL * Tree[node*2+1] * Tree[node*2+2]) % Mod;
	}
	
	int Product(int node, int st, int en, int L, int R) {
		Propagate(node, st, en);
		if (st > en || en < L || R < st) return 1;
		if (L <= st && en <= R) return Tree[node];
		int p1 = Product(node*2+1, st, (st+en)/2+0, L, R);
		int p2 = Product(node*2+2, (st+en)/2+1, en, L, R);
		return ((1LL * p1 * p2) % Mod);
	}
};

struct OrTree {
	vector<long long> Tree, Lazy;
	OrTree() {}
	OrTree(int n) {Tree.resize(n*4); Lazy.resize(n*4);}
	
	void Propagate(int node, int st, int en) {
		if (Lazy[node] == 0) return;
		Tree[node] |= Lazy[node];
		if (st != en) {
			Lazy[node*2+1] |= Lazy[node];
			Lazy[node*2+2] |= Lazy[node];
		}
		Lazy[node] = 0;
	}
	
	void Update(int node, int st, int en, int L, int R, long long val) {
		Propagate(node, st, en);
		if (st > en || en < L || R < st) return;
		if (L <= st && en <= R) {
			Lazy[node] |= val;
			Propagate(node, st, en); return;
		}
		Update(node*2+1, st, (st+en)/2+0, L, R, val);
		Update(node*2+2, (st+en)/2+1, en, L, R, val);
		Tree[node] = (Tree[node*2+1] | Tree[node*2+2]);
	}
	
	long long Or(int node, int st, int en, int L, int R) {
		Propagate(node, st, en);
		if (st > en || en < L || R < st) return 0;
		if (L <= st && en <= R) return Tree[node];
		long long p1 = Or(node*2+1, st, (st+en)/2+0, L, R);
		long long p2 = Or(node*2+2, (st+en)/2+1, en, L, R);
		return (p1 | p2);
	}
};

int N, Q, l, r, x; string cmd;
vector<int> invPrime(62);
vector<int> A; ProTree PrTree; OrTree OSTree;
vector<long long> Mask(301, 0);

void PreprocessMask() {
	for (int z=1; z<=300; z++) {
		for (int i=0; i<62; i++) {
			if (z % prime[i] != 0) continue;
			Mask[z] |= (1LL << i);
		}
	}
}

void Input() {
    for (int i=0; i<62; i++) invPrime[i] = modPow(prime[i], Mod-2); PreprocessMask();
	cin >> N >> Q; A.resize(N); PrTree = ProTree(N); OSTree = OrTree(N);
	for (int i=0; i<N; i++) {
		cin >> A[i];
		PrTree.Multiply(0, 0, N-1, i, i, A[i]);
		OSTree.Update(0, 0, N-1, i, i, Mask[A[i]]);
	}
}

void Solve() {
	while (Q--) {
		cin >> cmd >> l >> r; l--; r--;
		if (cmd == "MULTIPLY") {
			cin >> x;
			PrTree.Multiply(0, 0, N-1, l, r, x);
			OSTree.Update(0, 0, N-1, l, r, Mask[x]);
		}
		else if (cmd == "TOTIENT") {
			int res = PrTree.Product(0, 0, N-1, l, r);
			long long SegMask = OSTree.Or(0, 0, N-1, l, r);
			for (int i=0; i<62; i++) {
			    if ((SegMask & (1LL << i)) == 0) continue;
			    res = (1LL * res * (prime[i] - 1)) % Mod;
			    res = (1LL * res * invPrime[i]) % Mod;
			}
			cout << res << endl;
		}
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
```
 **Solution 2 (GreenGrape)**Submission link: [49739611](https://codeforces.com/contest/1114/submission/49739611 "Submission 49739611 by AkiLotus")

 **Source code in plain text**
```cpp
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <set>
#include <cassert>
#include <functional>
#include <iomanip>
#include <queue>
#include <numeric>
#include <bitset>
#include <iterator>

using namespace std;

const int N = 100001;

mt19937 gen(time(NULL));
#define forn(i, n) for (int i = 0; i < n; i++)
#define ford(i, n) for (int i = n - 1; i >= 0; i--)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define mp make_pair
#define endl 'n'
#define vi vector<int>

typedef long long ll;

template<typename T = int>
inline T read() {
	T val = 0, sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	return sign * val;
}

const int mod = 1e9 + 7;
const int phi = 1e9 + 6;

const int M = 301, B = 500;
int P = 0;

inline int mul(int a, int b) {
	return (a * 1LL * b) % mod;
}

int mpow(int u, int p) {
	if (!p) return 1;
	return mul(mpow(mul(u, u), p / 2), (p & 1) ? u : 1);
}

vector<int> primes;
vector<int> pi;

int pw[M];
int lg[N];

bool pr(int x) {
	if (x <= 1) return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

void precalc() {
	forn(i, M)
		if (pr(i)) {
			primes.push_back(i);
			P++;
		}
	pi.resize(P);
	forn(i, M) {
		int x = 1;
		forn(j, B) {
			x = mul(x, i);
		}
		pw[i] = x;
	}

	forn(i, P)
		pi[i] = mpow(primes[i], phi - 1);
}

struct product_tree {
	vector<int> arr, block_product, block_update, single_update;
	int n;

	product_tree(vector<int>& a) : n(a.size()) {
		arr = a;
		while (n % B) {
			n++, arr.push_back(1);
		}
		block_product.resize(n / B, 1);
		block_update.resize(n / B, -1);
		single_update.resize(n / B, -1);

		for (int i = 0; i < n; i += B) {
			int x = 1;
			int pos = i / B;
			forn(j, B)
				x = mul(x, arr[i + j]);
			block_product[pos] = x;
		}
	}

	inline void add(int& u, int x, int mode) {
		if (mode) {
			if (u == -1)
				u = x;
			else
				u = mul(u, x);
		}
		else {
			if (u == -1)
				u = pw[x];
			else
				u = mul(u, pw[x]);
		}
	}

	void update(int pos, int x) {
		add(block_update[pos], x, 0);
		add(single_update[pos], x, 1);
	}

	void reconstruct(int pos) {
		int e = single_update[pos];
		if (e == -1) return;
		int x = 1;

		int l = pos * B, r = l + B;
		for (int i = l; i < r; i++) {
			arr[i] = mul(arr[i], e);
			x = mul(x, arr[i]);
		}

		single_update[pos] = block_update[pos] = -1;
		block_product[pos] = x;
	}

	void apply(int l, int r, int x) {
		int L = l / B, R = r / B;
		if (L == R) {
			reconstruct(L);
			for (int i = l; i <= r; i++) {
				arr[i] = mul(arr[i], x);
				block_product[L] = mul(block_product[L], x);
			}
			return;
		}
		reconstruct(L);
		for (int i = l; i < (L + 1) * B; i++) {
			arr[i] = mul(arr[i], x);
			block_product[L] = mul(block_product[L], x);
		}
		reconstruct(R);
		for (int i = R * B; i <= r; i++) {
			arr[i] = mul(arr[i], x);
			block_product[R] = mul(block_product[R], x);
		}
		for (int j = L + 1; j < R; j++)
			update(j, x);
	}

	int get(int l, int r) {
		int L = l / B, R = r / B;
		int ans = 1;
		if (L == R) {
			reconstruct(L);
			for (int i = l; i <= r; i++) {
				ans = mul(ans, arr[i]);
			}
			return ans;
		}
		reconstruct(L);
		for (int i = l; i < (L + 1) * B; i++) {
			ans = mul(ans, arr[i]);
		}
		reconstruct(R);
		for (int i = R * B; i <= r; i++) {
			ans = mul(ans, arr[i]);
		}
		for (int j = L + 1; j < R; j++) {
			ans = mul(ans, block_product[j]);
			if (block_update[j] != -1)
				ans = mul(ans, block_update[j]);
		}
		return ans;
	}
};

struct prime_tree {
	vector<ll> t, d;
	int n;

	prime_tree(vector<ll>& a) : n(a.size()) {
		t.resize(4 * n);
		d.resize(4 * n, -1);
		build(1, 0, n, a);
	}

	ll build(int u, int l, int r, vector<ll>& a) {
		if (l == r - 1) {
			return t[u] = a[l];
		}
		int m = (l + r) / 2;
		return t[u] = build(u << 1, l, m, a) | build(u << 1 | 1, m, r, a);
	}

	inline void add(ll& u, ll x) {
		if (u == -1)
			u = x;
		else
			u |= x;
	}

	void push(int u, int l, int r) {
		if (d[u] == -1) return;
		t[u] |= d[u];
		if (r - l > 1) {
			add(d[u << 1], d[u]);
			add(d[u << 1 | 1], d[u]);
		}
		d[u] = -1;
	}

	void update(int u, int l, int r, int L, int R, ll x) {
		push(u, l, r);
		if (L >= R || l > L || r < R) return;
		if (l == L && r == R) {
			add(d[u], x);
			push(u, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(u << 1, l, m, L, min(m, R), x);
		update(u << 1 | 1, m, r, max(L, m), R, x);

		t[u] = t[u << 1] | t[u << 1 | 1];
	}

	ll get(int u, int l, int r, int L, int R) {
		push(u, l, r);
		if (L >= R || l > L || r < R) return 0;
		if (l == L && r == R) {
			return t[u];
		}
		int m = (l + r) / 2;
		return get(u << 1, l, m, L, min(m, R)) | get(u << 1 | 1, m, r, max(L, m), R);
	}

	ll get(int l, int r) {
		return get(1, 0, n, l, r + 1);
	}
	void apply(int l, int r, ll x) {
		update(1, 0, n, l, r + 1, x);
	}
};

ll transform(int x) {
	ll mask = 0;
	forn(i, P)
		if (x % primes[i] == 0) {
			mask |= (1LL << i);
		}
	return mask;
}

void solve() {
	int n, q; cin >> n >> q;

	vi a(n);
	vector<ll> _a;

	for (auto& v : a) {
		cin >> v;
		_a.push_back(transform(v));
	}

	auto Ptree = product_tree(a);
	auto Mtree = prime_tree(_a);

	int l, r, x;
	forn(i, q) {
		string s; cin >> s;
		if (s == "MULTIPLY") {
			cin >> l >> r >> x;
			l--, r--;
			Ptree.apply(l, r, x);
			Mtree.apply(l, r, transform(x));
		}
		else {
			cin >> l >> r;
			l--, r--;

			int product = Ptree.get(l, r);
			ll mask = Mtree.get(l, r);

			forn(j, 63)
				if (mask >> j & 1) {
					product = mul(product, primes[j] - 1);
					product = mul(product, pi[j]);
				}

			cout << product << endl;
		}
	}
}

signed main() {
	int t = 1;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	precalc();

	while (t--) {
		clock_t z = clock();
		solve();
		debug("Total Time: %.3fn", (double)(clock() - z) / CLOCKS_PER_SEC);
	}
}
```
