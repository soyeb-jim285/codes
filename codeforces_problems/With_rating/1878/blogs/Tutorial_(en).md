# Tutorial_(en)

Thank you for participating in the first ever Serbian Div. 3 Codeforces round!

 **Sorry**Before the editorial, we are sorry for the big gap between problems C and D.

This was the first round we ever created (except for [wxhtzdy](https://codeforces.com/profile/wxhtzdy "Master wxhtzdy")).

We are striving to become better problem-setters and create more balanced problems-sets in the future.

Also a massive thanks to [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya") for giving us a chance to create a divison 3 round!

[1878A - How Much Does Daytona Cost?](../problems/A._How_Much_Does_Daytona_Cost_.md "Codeforces Round 900 (Div. 3)")

 **Problem was authored and prepared by**Author: [wxhtzdy](https://codeforces.com/profile/wxhtzdy "Master wxhtzdy")

Prepared by: [ognjentesic](https://codeforces.com/profile/ognjentesic "Pupil ognjentesic"), [AndrewPav](https://codeforces.com/profile/AndrewPav "Specialist AndrewPav"), [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

 **Hints****Hint 1**When is the answer definitely "NO"?

 **Hint 2**What happens if there is no element equal to k in the array?

 **Hint 3**What happens if there is an element equal to k in the array?

 **Tutorial**
### [1878A - How Much Does Daytona Cost?](../problems/A._How_Much_Does_Daytona_Cost_.md "Codeforces Round 900 (Div. 3)")

It's enough to check if there even exists the element equals to $K$, since $K$ is obviously the most common element in the subsegment of length $1$ which contains it. 

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; //read the number of test cases
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k; //read n and k
		bool ys=0; //bool value if true then there exists a subsegment which satisfies the condition, else it doesn't exist
		for(int i=0; i< n; i++){
			int a; //read the i-th element of the array
			cin >> a;
			if(a==k)ys=1; //if the element is equal to k, then the subsegment [i, i] has the most common element equal to k
		}
		if(ys)cout << "YESn"; //output the answer
		else cout << "NOn";
	}
}

```
[1878B - Aleksa and Stack](../problems/B._Aleksa_and_Stack.md "Codeforces Round 900 (Div. 3)")

 **Problem was authored and prepared by**Author: [ognjentesic](https://codeforces.com/profile/ognjentesic "Pupil ognjentesic")

Prepared by: [ognjentesic](https://codeforces.com/profile/ognjentesic "Pupil ognjentesic"), [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

 **Hints****Hint 1**Watch parity.

 **Hint 2**What does the parity of 3⋅x depend on?

 **Hint 3**What parity are numbers which divide odd numbers?

 **Tutorial**
### [1878B - Aleksa and Stack](../problems/B._Aleksa_and_Stack.md "Codeforces Round 900 (Div. 3)")

There are many solutions to this problem, but the intended one is the following:

By selecting the first $n$ odd positive integers $1, 3, 5, \dots, 2n - 1$, we find that $3\cdot a_{i + 2}$ is also an odd number, while the number $a_i + a_{i + 1}$ is even, and an odd number can never be divisible by an even number, so the construction is correct.

Time complexity: $\mathcal{O}(n)$

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; //read the number of test cases
	cin >> t;
	while(t--){
		int n; //read n
		cin >> n;
		for(int i=0; i< n; i++)cout << i*2+1 << " "; //write the first n odd numbers in order
		cout << 'n';
	}
}
```
[1878C - Vasilije in Cacak](../problems/C._Vasilije_in_Cacak.md "Codeforces Round 900 (Div. 3)")

 **Problem was authored and prepared by**Author: [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

Prepared by: [ognjentesic](https://codeforces.com/profile/ognjentesic "Pupil ognjentesic"), [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

 **Hints****Hint 1**Prove that the answer for the second test case is "NO".

 **Hint 2**1+2+3>5

 **Hint 3**Determine the minimum and maximum sum achievable.

 **Hint 4**Prove that it's possible to construct the desired sequence for any requested sum between the minimum and maximum possible sum.

 **Tutorial**
### [1878C - Vasilije in Cacak](../problems/C._Vasilije_in_Cacak.md "Codeforces Round 900 (Div. 3)")

It is clear that the minimum sum is obtained for the numbers $1, 2, 3, \dots, k$, and its value is $\frac{k\cdot(k+1)}{2}$ (the sum of the first $k$ natural numbers).

Furthermore, it is evident that the maximum sum is achieved for the numbers $n, n-1, n-2, \dots, n-k+1$, and its value is $\frac{n\cdot(n+1)-(n-k)\cdot(n-k+1)}{2}$ (the sum of all numbers from $1$ to $n$ minus the sum of all numbers from $1$ to $n-x$ elements).

Let's prove that among any $k$ numbers (whose sum is not maximal), there exists a number $a < n$ such that $a+1$ is not among those $k$ numbers. Let's assume the opposite, that is, there exist $k$ numbers whose sum is not maximal, and for each of those $k$ numbers, $k + 1$ is also among those numbers. Let $v$ be the smallest among them. Consequently, $v + 1$ is also among these $k$ numbers. Since $v + 1$ is in these $k$ numbers, then $v + 2$ is also among these $k$ numbers. Similarly, we can conclude that $v, v + 1, v + 2, v + 3, \dots$ are all among these $k$ numbers. However, since we have $k$ of them, these are the $k$ numbers that would yield the maximum sum ($n, n-1, n-2, \dots, n-k+1$). This is a contradiction!

So, among any $k$ numbers (whose sum is not maximal), there exists a number $a < n$ such that $a+1$ is not among those $k$ numbers. Based on this, starting from the minimum sum $S$, we can obtain $S + 1$ (by replacing the number $a$ with $a + 1$, the sum increases by $1$), then from the sum $S + 1$, we obtain the sum $S + 2$, and so on. 

Therefore, by applying the principle of mathematical induction, we can obtain any sum that is greater than or equal to minumum sum and less than or equal to maximum sum.

 **Solution**
```cpp
#include <iostream>

using namespace std;

int main(){
	int t; //read the number of test cases
	cin >> t;
	while(t--){
		long long n, x, k; //read n, x, k for each test case
		cin >> n >> x >> k;
		if(2*k>=x*(x+1) && 2*k<=n*(n+1)-(n-x)*(n-x+1)){ //check if k is between the minimum and maximum sum 
			cout << "YESn";
		}
		else cout << "NOn";
	}	
}
```
[1878D - Reverse Madness](../problems/D._Reverse_Madness.md "Codeforces Round 900 (Div. 3)")

 **Problem was authored and prepared by**Author: [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

Prepared by: [ognjentesic](https://codeforces.com/profile/ognjentesic "Pupil ognjentesic"), [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

 **Hints****Hint 1**For each i, (1≤i≤k), we can treat the substring [li,ri] as a seperate test case.

 **Hint 2**What happens when we make the same modification twice?

 **Hint 3**Does the order of the operations matter?

 **Hint 4**Try pre-processing the queries

 **Tutorial**
### [1878D - Reverse Madness](../problems/D._Reverse_Madness.md "Codeforces Round 900 (Div. 3)")

Observation 1: if we look at [$l_i, r_i$] as subsegments for each $i$, notice that they are disjoint, and that two modifications do not interfere with each other if they are from different subsegments. Because of this observation we can basically treat subsegments as separate test cases.

Now, without loss of generality, because of the first observation, we can consider the same problem but with $l_1=1$ and $r_1=n$.

It is easy to see that the modifications $x$ and $n-x+1$ are equivalent, because the first one will reverse the subsegment [$\min(x, n-x+1), \max(x, n-x+1)$], and the second one will do the same thing. Using this we can consider without loss of generality for all modifications the following holds true: $2\cdot x_i \le n$.

Now try visualizing the modifications: 

if $x=1$ then we reverse the whole string.

if $x=2$ then we reverse the whole string except the first and the last element.

if $x=3$ then we reverse the whole string except the first two and last two elements.

We can logically conclude that the modifications are symmetrical with respect to the middle of the string.

From this symmetry, we can conclude that if a modification "touches" index $i$ it also touches index $n-i+1$, and also because of the symmetry, $i$ will always be swapped with $n-i+1$, and no other index.

This means that the order of modifications doesn't matter, because for each index it only matters how many modifications affect it.

Another thing to note is that for a given index $i$, all modifications such that $x \le i$ affect this index. This gives us the following solution:

Let's store the number of modifications for each index in an array, and if $x> \frac{n}{2}$ then store it as $n-x+1$. Next we just iterate over the array while maintaining the sum of the number of operations, and if it's odd we swap elements $i$ and $n-i+1$, else we just continue iterating. 

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t; //number of test cases
	cin >> t;
	while(t--){
		int n, k; //read the input
		cin >> n >> k;
		string s;
		cin >> s;
		int a[k]; int b[k];
		for(int i=0; i< k; i++){cin >> a[i]; a[i]--;}
		for(int i=0; i< k; i++){cin >> b[i]; b[i]--;}
		int q;
		cin >> q;
		int cnt[n+1]={0}; //read and preprocess queries
		for(int i=0; i< q; i++){
			int x; cin >> x; cnt[x-1]++;
		}
		string ans="";
		for(int i=0; i<k; i++){ //treat each interval as a seperate test case
			string s1=s.substr(a[i], b[i]-a[i]+1);
			int sum=0;
			int l=a[i];
			int r=b[i];
			for(int j=l; j<=(l+r)/2; j++){
				sum+=cnt[j]+cnt[r-j+l];
				if(sum&1)swap(s1[j-l], s1[r-j]);
			}
			ans+=s1;
		}
		cout << ans << 'n';
	}
}
```
[1878E - Iva & Pav](../problems/E._Iva_&_Pav.md "Codeforces Round 900 (Div. 3)")

 **Problem was authored and prepared by**Author: [AndrewPav](https://codeforces.com/profile/AndrewPav "Specialist AndrewPav"), [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

Prepared by: [ognjentesic](https://codeforces.com/profile/ognjentesic "Pupil ognjentesic"), [AndrewPav](https://codeforces.com/profile/AndrewPav "Specialist AndrewPav"), [OAleksa](https://codeforces.com/profile/OAleksa "Specialist OAleksa"), [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

 **Hints****Hint 1**Try calculating f(l,r) bit by bit

 **Hint 2**Which condition has to hold true for all elements on a subsegment [l,r], and for a certain bit, for that bit to be present in f(l,r)?

 **Hint 3**How can we check if that condition is true for a certain bit fast?

 **Hint 4**Try prefix sums.

 **Hint 5**Try binary search.

 **Tutorial**
### [1878E - Iva & Pav](../problems/E._Iva_&_Pav.md "Codeforces Round 900 (Div. 3)")

We can, for each bit, calculate the prefix sums of the array ($pref[i][j]$ is the number of occurrences of the $j$-th bit in the first $i$ elements of the array. This can be calculated in $\mathcal{O}(n \log(max(a)))$. We know that if $pref[r][j] − pref[l − 1][j] = r − l + 1$, then the $j$-th bit is present in all elements of the subsegment [$l, r$] of the array $a$, which means the value of $f(l, r)$ is equal to the sum of all bits for which this condition is true on the subsegment from $l$ to $r$, and we can calculate that in $\mathcal{O}(\log(max(a)))$. 

Next, for each query, we can use binary search to find $r$, by calculating $f(l, mid)$. If $f(l, r) \ge k$ then we found an index for which the condition is true, so we move the left to $mid + 1$, else we move the right to $mid-1$. This solution works in $\mathcal{O}(Q\cdot\log(N)\cdot\log(max(a)))$ which is around $4\cdot10^7$ operations, with a low constant factor.

It is possible to optimize the solution even more by using sparse tables, to calculate $f(l, r)$ in $\mathcal{O}(1)$ therefore removing the $\log(max(a))$ factor, but we think that sparse tables are a little bit too advanced of a topic for div3 E, so we didn't make that solution necessary.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
 
const int N =200003;
const int bits=30;
int pref[N][bits];
int a[N];
void Buildprefix(int n){ //Builds the prefix sums for each bit
    for(int i=0; i< n; i++){
        for(int j=0; j<30; j++){
            if(a[i]&(1<<j)){
                pref[i+1][j]=pref[i][j]+1;
            }
            else{
                pref[i+1][j]=pref[i][j];
            }
        }
    }
}
void solve(){
    int n;
    cin >> n;
    for(int i=0; i< n; i++){
        cin >> a[i];
    }
    Buildprefix(n);
    int q;
    cin >> q;
    while(q--){
        int l, k;
        cin >> l >> k;
        if(a[l-1]<k){
            cout << -1 << 'n';
            continue;
        }
        int lo=l;
        int hi=n;
        int ans=l;
        while(lo<=hi){
            int s=(lo+hi)/2;
            int num=0;
            for(int j=0; j< bits; j++){
                if(pref[s][j]-pref[l-1][j]==s-l+1){
                    num+=(1<<j);
                }
            }
            if(num>=k){
                lo=s+1;
                ans=max(ans, s);
            }
            else hi=s-1;
        }
        cout << ans << 'n';
    }
}
 
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
```
[1878F - Vasilije Loves Number Theory](../problems/F._Vasilije_Loves_Number_Theory.md "Codeforces Round 900 (Div. 3)")

 **Problem was authored and prepared by**Author: [ognjentesic](https://codeforces.com/profile/ognjentesic "Pupil ognjentesic"), [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

Prepared by: [ognjentesic](https://codeforces.com/profile/ognjentesic "Pupil ognjentesic"), [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

 **Hints****Hint 1**What does the condition gcd(a,n)=1 allow us to do?

 **Hint 2**How does any allowed operation affect d(a⋅n)?

 **Hint 3**Try to prove that the answer is "YES" if d(n) divides n.

 **Hint 4**Try to prove that the answer is "NO" otherwise.

 **Hint 5**How can you find and maintain the number of divisors quickly?

 **Hint 6**To make the implementation easier, try using the condition d(n)≤109.

 **Tutorial**
### [1878F - Vasilije Loves Number Theory](../problems/F._Vasilije_Loves_Number_Theory.md "Codeforces Round 900 (Div. 3)")

Answer: a solution exists if and only if $d(n)$ divides $n$.

Proof: consider the prime factorization of the number $n = p_1^{\alpha_1} \cdot p_2^{\alpha_2} \cdots p_k^{\alpha_k}$, where $p_i$ represents the $i$-th prime number, and $\alpha_i$ represents the highest power of the $i$-th prime number such that $p_i^{\alpha_i}$ divides $n$. Knowing this we can calculate the number of divisors of $n$ with the following formula: $d(n) = (\alpha_1+1) \cdot (\alpha_2+1) \cdots (\alpha_k+1)$.

Let's now consider the operations we are performing. We are multiplying the number $n$ by a number $a$ that has no common prime factors with $n$ (condition $gcd(a, n) = 1$).

Multiplying $n$ by any integer will only bring new prime factors to $n$, which means that we can not change what is already in the brackets of the formula for the number of divisors $d(n)$, but we can add new brackets. Therefore, $d(n)$ will always be a divisor of the number $d(n\cdot a)$. So, we can write $d(n \cdot a) = v \cdot d(n)$. In order to achieve $d(n \cdot a) = n$, we must also have $v \cdot d(n) = n$. Therefore, it is necessary for $d(n)$ to be a divisor of $n$. Let's show that this is also sufficient. Let's denote $k = \frac{n}{d(n)}$. Choose any prime number $p$ that is not a factor of $n$ (such a prime exists because there are infinitely many prime numbers, while $n$ has a finite number of prime factors). By multiplying $n$ by $a = p^{k-1}$, we obtain $d(n\cdot a) = d(n) \cdot k = n$.

Using this fact, we just need to efficiently check whether $d(n)$ divides $n$ after each type 1 query. How do we do this?

First we pre-calculate for each positive integer less than $10^6$ its smallest prime factor. This allows us to factorize all numbers smaller than or equal to $10^6$ in logarithmic time. We also factorize $n$ and find its number of divisors using the formula mentioned above, and store for each prime factor its highest power which still divides $n$. We can do this using an array, or using a map, either way, let's call this structure $power$.

Now we need to deal with the queries:

For type 2 query we just need to reset everything.

For the first query, we factorize $x$ in $\mathcal{O}(\log{x})$ operations and let $x = r_1^{\beta_1} \cdot r_2^{\beta_2} \cdots r_\ell^{\beta_\ell}$ be the factorization of the number $x$. We update the $d(n)$ by doing the following: for each prime $r_i$ in $x$, divide $d(n)$ by $power[r_i]+1$, then add $\beta_i$ to $power[r_i]$, and then multiply $d(n)$ by $power[r_i]+1$. After we calculate $d(n)$, we should check if $n$ is divisible by it. We can do this in 2 ways:

Solution 1:

We do this by multiplying the value of all previous type $1$ queries (after the last type $2$ query), and the value of the starting $n$ by modulo $d(n)$, because $n$ can get really large, and we can't store it in a 64-bit integer. If the value mod $d(n)$ is $0$, then its divisible and the answer to our query is "YES", else it is "NO".

Time complexity $\mathcal{O}(Q \cdot (Q + \log{x}) + \log{n})$.

Solution 2:

This solution is even faster, but it might be harder to implement, and that's why we didn't make it necessary.

Instead of storing queries, we just need to use another map to store the prime divisors of $d(n)$, now we can compare each prime divisor and its power for $d(n)$ and for the product of $n$ and all queries after the last reset. Now for each prime in $d(n)$, the power of that prime has to be smaller or equal to than the power of that prime in the product of $n$ and queries. Since $d(n) \le 10^9$, the map for $d(n)$ will have at most $\log(max(d(n))$ entries, so this solution runs in $\mathcal{O}(Q \cdot (\log(max(d(n)) \cdot log(log(max(d(n))) + \log(x))+ t \cdot \log(n))$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int N = 1000003;
map<int, int> powers; //key is a prime number, value is te highest powert
map<int, int> original_divisors; //same as map powers but isn't updated during queries, it's used to reset the powers
int smallest_divisor[N]; //precalculated smallest divisors to make factorization O(logx) 
bool mark[N]; //marks numbers which aren't prime (used for sieve)
ll divisor_count = 1; //the number of divisors (updated during queries)

void prime(){ //calculates the smallers divisor for each number from 1 to N (sieve of erathosetenes)
	smallest_divisor[1]=1;
	smallest_divisor[2]=2;
	for(int i=4; i<N; i+=2){
		mark[i]=true;
		smallest_divisor[i]=2;
	}	
	for(int i=3; i<N; i+=2){
		if(!mark[i]){
			smallest_divisor[i]=i;
			for(ll j = i*1ll*i; j<N; j+=2*i){
				if(!mark[j]){
					smallest_divisor[j]=i;
					mark[j]=1;
				}
			}
		}
	}
}
//a function for factorizing a number (used to process queries and factorize n in the beginning)
//it also updates the highest prime which divides n (powers map), and the number of divisors of n (divisor_count)
void factorize(int x){ 
	int p=0;
	int current_divisor = 1;
	while(x>1){ //while x has non 1 divisors, divide it by it's smallest divisor which isn't 1(smallers divisor if always prime)
		if(smallest_divisor[x]!=current_divisor){
			if(p>0){
				divisor_count/=powers[current_divisor]+1;
				powers[current_divisor]+=p;
				divisor_count*=powers[current_divisor]+1;
			}
			p=1;
			current_divisor=smallest_divisor[x];
		}
		else{
			p++;
		}
		x/=smallest_divisor[x];
	}
	if(p>0){
		divisor_count/=powers[current_divisor]+1;
		powers[current_divisor]+=p;
		divisor_count*=powers[current_divisor]+1;
	}
	return;
}

int main(){
	prime(); //precalculate smallest divisors
	int t;
	cin >> t;
	while(t--){
	    //read n and q
    	int n; int q;
    	cin >> n >> q;
    	//factorize n
    	factorize(n);
    	//since factorize updates the powers map, update the origional_divisors map too
    	for(auto prime : powers){
    		original_divisors[prime.first]=prime.second;
    	}
    	int original_divisor_count = divisor_count; //since factorize updates the divisor_count we update the original_divisor_count too
    	vector<int> queries; //storing previous queries
    	//processing queries
    	while(q--){
    		int query_type;
    		cin >> query_type;
    		if(query_type==1){ //query of type 1 (multiply n by x)
    			int x;
    			cin >> x;
    			factorize(x); //factorize x, update the powers map, and the number of divisors
    			queries.push_back(x); //add x to the list of previous queries
    			ll num=n;
    			for(int query : queries){ //check if the product of all previous queries and n is divisible by d(n)
    				num*=query;
    				num%=divisor_count;
    			}
    			if(num==0){ //if it is the answer is yes else the answer is no
    				cout << "YESn";
    			}
    			else cout << "NOn";
    		}
    		else{ //here we should reset everything related to the type 1 query
    			powers.clear(); //clear the powers map and set it to original divisors and powers
    			for(auto original_div : original_divisors){
    				powers[original_div.first]=original_div.second;
    			}
    			divisor_count=original_divisor_count; //restart the divisor_count
    			queries.clear(); //clear the queries (since we only need the queries since the previous type 2 query)
    		}
    	}
    	original_divisors.clear();
    	powers.clear();
    	divisor_count=1;
    	original_divisor_count =1;
    	if(t) cout << "n";
	}
}
```
[1878G - wxhtzdy ORO Tree](../problems/G._wxhtzdy_ORO_Tree.md "Codeforces Round 900 (Div. 3)")

 **Problem was authored and prepared by**Author: [wxhtzdy](https://codeforces.com/profile/wxhtzdy "Master wxhtzdy")

Prepared by: [ognjentesic](https://codeforces.com/profile/ognjentesic "Pupil ognjentesic"), [OAleksa](https://codeforces.com/profile/OAleksa "Specialist OAleksa"), [AlphaMale06](https://codeforces.com/profile/AlphaMale06 "Expert AlphaMale06")

 **Hints****Hint 1**How many vertices actually matter on the path from x to y?

 **Hint 2**How do we find them?

 **Hint 3**Root the tree arbitrarily.

 **Hint 4**Try calculating the number of occurrences for each bit on the path from the root to a certain vertex.

 **Hint 5**Try binary search.

 **Hint 6**Try LCA (Lowest common ancestor).

 **Tutorial**
### [1878G - wxhtzdy ORO Tree](../problems/G._wxhtzdy_ORO_Tree.md "Codeforces Round 900 (Div. 3)")

Observation 1: it's enough to only consider $2 \cdot \log(max(a))$ vertices on the shortest path from $x$ to $y$ as candidates for $z$ for each query. Why? Because at most $\log(max(a))$ vertices can add a bit to $g(x, z)$ and we only need to maximize the number of bits in $g(x, z)$ + the number of bits in $g(y, z)$, and all the other vertices will not contribute to the sum at all so we don't even need to consider them for $z$.

Now we need to find those vertices. We know that for each bit, the vertex which we will consider can give this bit to $g(x, z)$ will be the closest one to vertex $x$ (on the path from $x$ to $y$).

How do we find these vertices qucikly? First let's arbitrarily root the tree. Now let's precalculate for each vertex and bit $cnt[vertex][bit]$ as the number of vertices on the path from the root to this vertex which have this bit set in their value. Then for each bit, we can binary search to find it's first occurenece on the path from $x$ to $y$, and the path from $y$ to $x$. 

We do binary search by taking $mid$ from vertex $x$ to vertex $y$ and calculating the number of vertices which have the current bit set, by using the $cnt$ matrix combined with range minimum query or binary lifting to find the lowest common ancestor. We are searching for the first position where the number of those is >0. Once we find all the vertices, we can for each of those, in $O(log(max(a))$, calculate it's niceness, and take the maximum out of those.

Time complexity: $O(q \cdot (\log n + \log(max(a)) \cdot \log n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
#define int long long
const int maxn = 2e5 + 69;
const int k = 19;
const int bits = 30;
vector<int> g[maxn];
int n, q, a[maxn], up[maxn][k], tin[maxn], tout[maxn], timer, d[maxn];
int r[maxn][k];
int bst[maxn][bits];
void dfs(int v, int p, vector<int> b) {
	tin[v] = ++timer;
	up[v][0] = p;
	r[v][0] = a[p];
	d[v] = d[p] + 1;
	for (int i = 0;i < bits;i++) {
		bst[v][i] = b[i];
		if (a[v] & (1 << i))
			b[i] = v;
	}
	for (int i = 1;i < k;i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		r[v][i] = r[v][i - 1] | r[up[v][i - 1]][i - 1];
	}
	for (auto u : g[v]) {
		if (u != p)
			dfs(u, v, b);
	}
	tout[v] = timer;
}

bool is_anc(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if(is_anc(u, v))
		return u;
	else if(is_anc(v, u))
		return v;
	for (int i = k - 1;i >= 0;i--) {
		if (!is_anc(up[u][i], v) && up[u][i] > 0)
			u = up[u][i];
	}
	return up[u][0];
}

int OR(int u, int dis) {
	int res = a[u];
	for (int j = 0;j < bits;j++) {
		if (dis & (1 << j)) {
			res |= r[u][j];
			u = up[u][j];
		}
	}
	return res;
}

int Qry(int u, int v) {
	int lc = lca(u, v);
	return OR(u, d[u] - d[lc]) | OR(v, d[v] - d[lc]);
}

signed main()
{
	int tt = 1;
	cin >> tt;
	while(tt--) {
		cin >> n;
		timer = 0;
		for (int i = 1;i <= n;i++)
            g[i].clear();
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		for (int i = 1;i <= n - 1;i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		vector<int> temp(30, -1);
		dfs(1, 0, temp);
		cin >> q;
		for (int i = 1;i <= q;i++) {
			int x, y;
			cin >> x >> y;
			int LCA = lca(x, y);
			vector<int> t;
			t.push_back(x);
			t.push_back(y);
			for (int i = 0;i < bits;i++) {
				if (bst[x][i] != -1 && is_anc(LCA, bst[x][i]))
					t.push_back(bst[x][i]);
				if (bst[y][i] != -1 && is_anc(LCA, bst[y][i]))
					t.push_back(bst[y][i]);
			}
			int ans =  __builtin_popcount(a[x]) + __builtin_popcount(a[y]);
			for (auto p : t) {
				int x1 = a[x], x2 = a[y];
				x1 |= Qry(x, p);
				x2 |= Qry(y, p);
				ans = max(ans, 1ll * __builtin_popcount(x1) + __builtin_popcount(x2));
			}
			cout << ans << " ";
		}
		cout << "n";
	}
   return 0;
}
```
