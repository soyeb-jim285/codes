# Editorial_(en)


### [1091A - New Year and the Christmas Ornament](../problems/A._New_Year_and_the_Christmas_Ornament.md "Good Bye 2018")

Consider some solution $Y$, $B$, $R$, where $Y + 1 = B$ and $B + 1 = R$. Let's add two yellow ornaments and one blue both to the solution and to the reserve, then we have $Y = B = R$. We can see that this new problem is equivalent to the old one. In this problem, the best solution is achieved when we use $\min(y,b,r)$ ornaments of each colour. Hence, we can find the said minimum, multiply by three and then remove the three extra ornaments again.

 **Code (by arsijo)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(a + 2, min(b + 1, c)) * 3 - 3;
}
```
 
### [1091B - New Year and the Treasure Geolocation](../problems/B._New_Year_and_the_Treasure_Geolocation.md "Good Bye 2018")

We know that there exists some permutation $p$ such that for all $i$ the following holds: $$(t_x, t_y) = (x_{p_i} + a_i, y_{p_i} + b_i) $$

Summing this for all $i$ we get:

$$n \cdot (t_x, t_y) = \sum (x_{p_i} + a_i, y_{p_i} + b_i) = \left(\sum (x_{p_i} + a_i), \sum (y_{p_i} + b_i)\right) = \left(\sum x_i + \sum a_i, \sum y_i + \sum b_i\right)$$

We can thus sum all $x$, respectively $y$, coordinates of both obelisks and clues, and divide by $n$. This takes $\mathcal O(n)$ time.

Alternative solution: Take the lexicographically smallest obelisk coordinate. It is clear that this needs to be paired with the lexicographically largest clue. We simply find minimum and maximum in $\mathcal O(n)$ and sum.

 **Code**
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

#define x first
#define y second

int main() {
    int N; cin >> N;
    vector<pii> O(N), T(N);
    for (int i = 0; i < N; i++) cin >> O[i].x >> O[i].y;
    for (int i = 0; i < N; i++) cin >> T[i].x >> T[i].y;
    sort(O.begin(),O.end());
    sort(T.begin(),T.end());
    reverse(T.begin(),T.end());

    vector<pii> Ans(N);
    for (int i = 0; i < N; i++) Ans[i] = {O[i].x+T[i].x, O[i].y+T[i].y};
    sort(Ans.begin(),Ans.end());
    cout << Ans[0].x << ' ' << Ans[0].y << endl;
}
```
 
### [1091C - New Year and the Sphere Transmission](../problems/C._New_Year_and_the_Sphere_Transmission.md "Good Bye 2018")

Subtract $1$ from all values for convenience. Fix the value of $k$. We get values of $a \cdot k \bmod n$ for all $a$ from $0$ until we reach $0$ again. This value can be also written as $a \cdot k - b \cdot n$. Due to Bezout's theorem, the equation $a \cdot k - b \cdot n = c$ has an integer solution for $a$ and $b$ if and only if $c$ is divisible by $\text{gcd}(k, n)$. 

Furthermore, all possible values of $c$ will be visited before it returns to $0$. This is because the element $k/\text{gcd}(k,n)$ generates the group $\mathbb{Z}_{n/\text{gcd}(k,n)}$.

We can thus consider only values of $k$ that divide $n$. We can find all of them by trial division in $\mathcal O(\sqrt n)$. For each of them, we can find a closed form solution by summing arithmetic series.

 **Code**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ll N; cin >> N;
	vector<ll> ans;

	for (ll i = 1; i*i <= N; ++i) {
		if (N%i==0) {
			ans.push_back(N*(i-1)/2 + i);
			if (i*i!=N) {
				ans.push_back(N*(N/i-1)/2 + N/i);
			}
		}
	}
	sort(ans.begin(),ans.end());
	
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " n"[i==ans.size()-1];
	}

}
```
 
### [1091D - New Year and the Permutation Concatenation](../problems/D._New_Year_and_the_Permutation_Concatenation.md "Good Bye 2018")

There are two types of subarrays with length $n$: 

* They are fully formed from one permutations.
* They are a concatenation of a $k$ long suffix of one permutation, and a $n-k$ long prefix of the next permutation.

There are $n!$ such subarrays of the first type, and they all have the the correct sum. 

Let's investigate the second type. Recall the algorithm of finding the next permutation in lexicographical order. We find the longest suffix that is in decreasing order, let its length be $k$. We swap the preceding element $x$ with the smallest one from the decreasing sequence larger than $x$, and sort the suffix in increasing order. The prefix of length $n - k - 1$ is left unchanged, but all longer proper prefixes are different and also change their sum. 

Coming back to our problem, if the suffix of length $k$ is in decreasing order, than the prefix of length $n - k$ of the next permutation has different sum from the prefix of the same length of the current permutation, hence the subarray has incorrect sum. Conversely, if the suffix of length $k$ is not in decreasing order, then the prefix of length $n-k$ of the next permutation equals to the prefix of the current permutation, and its sum is $\frac{n(n+1)}{2}$. 

To find the answer, we must thus subtract the number of suffixes of all permutations that are decreasing. How many of them are there for a fixed $k$? This is simple – we choose the first $n-k$ elements freely, and permute them. The rest has to be sorted in a particular way. Hence the number of bad subarrays coming from a suffix of length $k$ equals $\frac{n!}{k!}$.

Convince yourself that this approach works correctly even for the last permutation, where there is no next permutation to concatenate its suffixes with.

The answer is: 

$$n \cdot n! - \sum_{k=1}^{n-1} \frac{n!}{k!}$$

This can be calculated in $\mathcal O(n)$ without the need of modular division.

There is also a simple recurrence counting the same answer, found by arsijo:

$$d(n) = \left(d(n-1) + (n-1)! - 1\right) \cdot n$$

 **Code**
```cpp
#include <iostream>
#include <vector>

using namespace std;

template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
	inline ui pow(ui a, ui p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%N;}e=((ull)e*e)%N;p>>=1;}return r;}
	inline ui inv(ui a){return pow(a,N-2);}
public:
    inline Field(int x = 0) : v(x) {}
	inline Field<N> pow(int p){return (*this)^p; }
	inline Field<N> operator^(int p){return {(int)pow(v,(ui)p)};}
    inline Field<N>&operator+=(const Field<N>&o) {if (v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
    inline Field<N>&operator-=(const Field<N>&o) {if (v<o.v) v -= o.v-N; else v-=o.v; return *this; }
    inline Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
    inline Field<N>&operator/=(const Field<N>&o) { return *this*=inv(o.v); }
    inline Field<N> operator+(const Field<N>&o) const {Field<N>r{*this};return r+=o;}
    inline Field<N> operator-(const Field<N>&o) const {Field<N>r{*this};return r-=o;}
    inline Field<N> operator*(const Field<N>&o) const {Field<N>r{*this};return r*=o;}
    inline Field<N> operator/(const Field<N>&o) const {Field<N>r{*this};return r/=o;}
    inline Field<N> operator-() {if(v) return {(int)(N-v)}; else return {0};};
    inline Field<N>& operator++() { ++v; if (v==N) v=0; return *this; }
    inline Field<N> operator++(int) { Field<N>r{*this}; ++*this; return r; }
    inline Field<N>& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline Field<N> operator--(int) { Field<N>r{*this}; --*this; return r; }
    inline bool operator==(const Field<N>&o) const { return o.v==v; }
	inline bool operator!=(const Field<N>&o) const { return o.v!=v; }
	inline explicit operator ui() const { return v; }
	inline static vector<Field<N>>fact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]*i;}return F;}
	inline static vector<Field<N>>invfact(int t){vector<Field<N>>F(t+1,1);Field<N> X{1};for(int i=2;i<=t;++i){X=X*i;}F[t]=1/X;for(int i=t-1;i>=2;--i){F[i]=F[i+1]*(i+1);}return F;}
private: ui v;
};
template<unsigned int N>istream &operator>>(std::istream&is,Field<N>&f){unsigned int v;is>>v;f=v;return is;}
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator-(int i,const Field<N>&f){return Field<N>(i)-f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}
template<unsigned int N>Field<N> operator/(int i,const Field<N>&f){return Field<N>(i)/f;}

typedef Field<998244353> FF;

int main(int argc, char* argv[]) {
    int n; cin >> n;
    auto F = FF::fact(n);
    auto I = FF::invfact(n);
    FF ans = n * F[n];
    for (int i = 1; i < n; ++i) ans -= F[n]*I[i];
    cout << ans << endl;
}
```
 
### [1091E - New Year and the Acquaintance Estimation](../problems/E._New_Year_and_the_Acquaintance_Estimation.md "Good Bye 2018")

The first observation is that using the Handshaking lemma, we know the parity of $a_{n+1}$. 

Secondly, on the integers of same parity, the answer always forms a continuous interval, that is if $a_{n+1} = X$ is one possible answer and $a_{n+1} = Y$ is another with $X < Y$, then every $X < Z < Y$ satisfying $X \bmod 2 == Z \bmod 2$ is also an answer. We should thus look into some binary search approaches.

We use the Erdos-Gallai theorem linked in the statement to determine whether a sequence is graphic. If it is not the case, we must determine whether the answer is too big or too small. This depends on whether the $a_{n+1}$ is on the left or the right side of the inequality when it is not satisfied. If it is on the left, it means that it is too big – clearly making it larger is never going to change the sign of the inequality. On the contrary, if $a_{n+1}$ is on the right, it is clearly too small. 

It can also happen that the inequality is false for some $k$ where $a_{n+1}$ is on the left and for some other $k$ it is on the right. Then there clearly is no solution.

Checking the inequality naively takes $\mathcal O(n^2)$ time, but we can also do it in $\mathcal O(n)$: for left side we need a prefix sum, and for right side we maintain the sum and also how many times a particular value occurs. The sum of values at most $k$ can then be maintained in $\mathcal O(1)$. This yields an algorithm in $\mathcal O(n \log n)$.

Alternatively, we can perform a similar binary search using Havel-Hakimi algorithm, using a segment tree or a multiset and tracking whether the $a_{n+1}$ was already processed or not to find out whether the answer is too small or too big. This yields $\mathcal O(n \log^2 n)$ algorithm.

 **Code**
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 500000

int N;
int A[MAXN];
long long sum;

#define TOO_SMALL -1
#define OK 0
#define TOO_BIG 1

int is_score(int value) {
    vector<int> C(N+1,0);
    for (int i = 0; i < N; ++i) ++C[A[i]];
    ++C[value];

    int less = 0;
    long long left = 0, right = 0;
    for (int k = 0, i = 0; k <= N; k++) {
        int val = (i == k && (i == N || A[i] < value)) ? value : A[i++];
        left += val;
        --C[val];
        right -= min(val, k);
        less += C[k];
        right += N-k-less;
        if (left > right + (long long)(k+1)*k) {
            return (i == k) ? TOO_BIG : TOO_SMALL;
        }
    }
    return OK;
}

int main(int,char**) {
    ios_base::sync_with_stdio(false);
    
    scanf("%d", &N);
    sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", A + i);
        sum += A[i];
    }

    sort(A,A+N,greater<int>());
    int parity = sum & 1;
    int lo = 0, hi = (N - parity) / 2, lores = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (is_score(2*mid + parity) == TOO_SMALL) {
            lo = mid + 1;
        } else {
            lores = mid;
            hi = mid - 1;
        }
    }
    
    lo = lores; 
    hi = (N - parity) / 2; 
    int hires = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (is_score(2*mid + parity) == TOO_BIG) {
            hi = mid - 1;
        } else {
            hires = mid;
            lo = mid + 1;
        }
    }
    
    if (lores == -1 || hires == -1) printf("-1n"); 
    else {
        for (int i = lores; i <= hires; ++i) printf("%d ", 2*i+parity);
        printf("n");
    }
}
```
 
### [1091F - New Year and the Mallard Expedition](../problems/F._New_Year_and_the_Mallard_Expedition.md "Good Bye 2018")

We start with a greedy solution. This means that we fly over lava, swim on water and walk on grass, keeping track of time and the stamina. There are two types of issues that may happen – either we don't have enough stamina to fly over lava, or we have some leftover stamina at the end.

If we lack some stamina, we can walk or swim "in place" for some amount of time to gain it. This "in place" movement can be perform by simply walking or swimming half a meter backwards and then half a meter forwards. This gains $1$ stamina. It is more effective to do on water, as we move faster there, so we may as well do it on the first water on the journey. If there was no water before the lava we are flying across, we use slightly more expensive ground.

On the other hand, if we have some unused stamina in the end, we should convert some previous movement to flying to save time. Note that converting $1$ meter of movement costs us $2$ stamina, not one, since we consume $1$ stamina and also gain $1$ stamina less. Since moving on grass is slower, we prefer to convert such movements. However, we must take care not to convert a walking segment that is too early – we should not modify the journey in such a way that we run out of stamina at some point. We thus keep track of the length of grass that we travelled across during our journey. Consider the end of some patch of terrain. Let the total length of grass that we've travelled through until now be $G$, and let the current stamina be $S$. We may never convert more than $G$ grass, and also no more than $S/2$ since if not, we would have run out of stamina at the current location. We simply lower the amount of grass $G$ that is available to be converted, to $S/2$. In the end, we convert $G$ walking to flying, and $S/2 - G$ swimming to flying to save some time.

This works in $\mathcal O(n)$.

 **Code**
```cpp
#include <iostream>
#include <vector>
#include <string>

typedef long long ll;
using namespace std;

int main() {
    int N; cin >> N;
    vector<ll> L(N); 
    for (ll &l: L) cin >> l;
    string T; cin >> T;
    bool hadWater = false;
    ll time = 0, stamina = 0, twiceGrass = 0;
    for (int i = 0; i < N; ++i) {
        if (T[i] == 'L') {
            time += L[i];
            stamina -= L[i];
            if (stamina < 0) {
                /* not enough stamina, walk or swim "in place" to gain it */
                time -= stamina * (hadWater ? 3 : 5);
                stamina = 0;
            }
        } else if (T[i] == 'W') {
            hadWater = true;
            stamina += L[i];
            time += 3 * L[i];
        } else {
            stamina += L[i];
            time += 5 * L[i];
            twiceGrass += 2*L[i];   
        }
        /* no more than stamina/2 of walking can be converted to flying to save time,
         * otherwise there would not be enough stamina at this point */
        twiceGrass = min(twiceGrass, stamina);
    }

    if (stamina > 0) {
        // convert walking to flying
        time -= (5-1) * twiceGrass/2;

        // convert swimming to flying
        time -= (3-1) * (stamina - twiceGrass)/2;
    }

    cout << time << endl;
}
```
 
### [1091G - New Year and the Factorisation Collaboration](../problems/G._New_Year_and_the_Factorisation_Collaboration.md "Good Bye 2018")

Most of the operations we're given are useless, as we can perform them on our own. However, we cannot perform the square root ourselves, so we should be able to use the information given us by the square root oracle to find the factorisation.

First let's solve the task for a product of two primes. 

Select $x$ uniformly at random and assign $z = x^2$. Let $y$ be the answer to the query sqrt z. We have $$x^2 \equiv y^2 \pmod n$$ $$(x+y)(x-y) \equiv 0 \pmod n$$ For a fixed $x$, thanks to Chinese remainder theorem there are four solutions to this equation for $y$, two of them being $x$ and $-x$. If that is not the case, then as $p$ and $q$ are coprime, then $p$ divides one of the factors while $q$ divides the other. Hence, one factor can be computed as $\text{gcd}(x-y, n)$. Since we selected $x$ at random, the probability that the interactor returns $x$ or $-x$ is exactly $\frac{1}{2}$ and $2$ queries are needed in expectation.

Let's take a look what happens when there are more than two prime factors. Some of them will be accumulated in $x+y$, and the others in $x-y$. Collect all these values (again, after taking gcd of them with $n$) over multiple queries. We can find the prime factor $p_j$ if and only if for $i \neq j$ we have seen a value $t$ such that $\text{gcd}(t, p_i \cdot p_j) = p_j$. This is because we can take gcd of exactly all values containing $p_i$ as a factor and to get $p_i$. 

We do not know which values contain the prime factor before we know the prime factor, but we simply calculate gcd of all subsets of retrieved values. Since gcd is a commutative and associative operation, and all values we get this way must be factors of $n$, we can perform this step in $\mathcal O(f \cdot 4^f)$ time, where $f$ is the number of prime factors of $n$. We can then a primality checking algorithm to check which of these are primes. Alternatively, we can just greedily pick the smallest of all values (except $1$) that is coprime to all the values that have been selected so far – this will always be a prime.

It remains to show what is the probability of success. We need each pair of primes to be separated at least once. The probability of that happening in one query is $1/2$. Over the course of $q$ queries, we have probability $2^{-q}$ that we are still unable to separate the two primes. Taking union bound over all prime pairs yields an upper bound on the error probability $4 * 10^{-14}$.

Implementation note: To find the square root, we use Chinese remainder theorem and find the square roots in the respective finite fields. The primes are of form $4x + 3$ for a simple reason – we can find the square root of $x$ modulo $p$ by simply calculating $x^{\frac{p+1}{2}}$. For primes of form $4x + 1$, we need Tonelli-Shanks, which empirically uses about $5$ modular exponentiations. With the number of queries and prime factors, and the size of the numbers, it was suddenly impossible for the interactor to fit into the time limit.

 **Code (by winger)**
```cpp
import random

def isPrime(n):
    """
    Miller-Rabin primality test.

    A return value of False means n is certainly not prime. A return value of
    True means n is very likely a prime.
    """
    if n!=int(n):
        return False
    n=int(n)
    #Miller-Rabin test for prime
    if n==0 or n==1 or n==4 or n==6 or n==8 or n==9:
        return False

    if n==2 or n==3 or n==5 or n==7:
        return True
    s = 0
    d = n-1
    while d%2==0:
        d>>=1
        s+=1
    assert(2**s * d == n-1)

    def trial_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True

    for i in range(20):#number of trials
        a = random.randrange(2, n)
        if trial_composite(a):
            return False

    return True

def gcd(x, y):
    return x if y == 0 else gcd(y, x % y)

n = int(input())

divs = [n]

def split(parts):
    global divs
    divs = [gcd(d, p) for d in divs for p in parts if gcd(d, p) != 1]

while not all([isPrime(x) for x in divs]):
    x = random.randint(0, n - 1)
    g = gcd(n, x)
    if gcd(n, x) != 1:
        split([g, n // g])
        continue
    y = int(input('sqrt {}n'.format(x * x % n)))
    if x == y:
        continue
    a, b = abs(x - y), x + y
    g = gcd(x, y)
    split([a // g, b // g, g])

print('!', len(divs), ' '.join(str(d) for d in sorted(divs)))
```
 
### [1091H - New Year and the Tricolore Recreation](../problems/H._New_Year_and_the_Tricolore_Recreation.md "Good Bye 2018")

If you represent the row state as a pair $(x,y)$ where $x$ is the distance between blue and white token and $y$ is the distance between white and red, we can see that each player has one operation that reduces $x$ by $k$, and a second operation which reduces $y$ by $k$. In other words, each $x$ and $y$ defines a symmetric game, and all games are independent. This is an impartial game after all! 

Once we have the Grundy numbers for each pile, we can use Sprague-Grundy theorem to find the answer. How to find the Grundy numbers? We find the set of primes and semiprime by sieving. To find the value of pile of size $n$, we can collect the Grundy numbers of each pile size reachable from $n$ (i.e. $n - p$ where p is a prime or semiprime), and then find the mex. This takes $\mathcal O(m^2)$, where $m$ is the maximum distance between two tokens ($2*10^5$) and is too slow.

To improve upon this, we can use bitset, but that's not enough. We actually need more of these! Maintain $k$ bitsets $G_0$, ..., $G_m$ where $i$-th bitset contains true at $j$-th position when there is a transition from state $j$ to state with grundy number $i$.

How do you do that? You have one bitset $P$ storing all primes and semiprimes. For each $i$, preform linear search for the mex, let the grundy number be $j$. Then or $G_j$ with $P « i$.

This works in $O(n^2/w)$. The maximum Grundy number given the input constraints is less than 100, so we can safely pick $k = 100$. 

 **Code**
```cpp
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

typedef unsigned int ui;
typedef long long ll;

struct Sieve : public std::vector<bool> {
    // ~10ns * n
	explicit Sieve(ui n) : vector<bool>(n+1, true), n(n) {
		at(0) = false;
		if (n!=0) at(1) = false;
		for (ui i = 2; i*i <= n; ++i) {
			if (at(i)) for (int j = i*i; j <= n; j+=i) (*this)[j] = false;
		}
	}

	vector<int> primes() const {
		vector<int> ans;
		for (int i=2; i<=n; ++i) if (at(i)) ans.push_back(i);
		return ans;
	}

private:
	int n;
};

constexpr int M = 2e5;
auto P = Sieve{M}.primes();

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<int> G(M, 0);
    int Q = P.size();
    for (int i = 0; i < Q; ++i) {
        for (int j = i; j < Q; ++j) {
            if (ll(P[i])*P[j] >= M) break;
            P.push_back(P[i]*P[j]);
        }
    }
    
    bitset<M> PB;
    for (int p : P) PB[p] = true;
    
    int N, F; cin >> N >> F;
    PB[F] = false;
    
    vector<bitset<M>> W(100);
    W[0] = PB;
    for (int i = 1; i < M; ++i) {
        while (W[G[i]][i]) G[i]++;
        W[G[i]] |= PB << i;
    }
    cerr << *max_element(G.begin(),G.end()) << endl;

    int g = 0;
    for (int i = 0; i < N; i++) {
        int r,w,b;
        cin >> r >> w >> b;
        g ^= G[w-r-1];
        g ^= G[b-w-1];
    }
    if (g == 0) {
        cout << "BobnAlicen";
    } else {
        cout << "AlicenBobn";
    }
}
```
