# Tutorial_(en)

Thanks for participating, hope you enjoyed the problems! Implementations for the problems are chosen randomly among testers, and I made some changes to their codes (for example, deleted meaningless comment lines). Please do not hesitate to provide feedback in the comments, so I can improve in setting problems next time.

**UPD**: Sorry but there is a checker bug in problem E. All submissions of problem E will be rejudged soon.

**UPD2:** Rejudge done, the round remains rated.

 **Statistics**Number of FST for rated participants:

 * Problem A: 29
* Problem B: 90
* Problem C: 12
* Problem D1: 4
* Problem D2: 0
* Problem E: 6

Number of AK: 22

Number of clarifications: 85

[1617A - Forbidden Subsequence](../problems/A._Forbidden_Subsequence.md "Codeforces Round 761 (Div. 2)")

 **Hint**When is the lexicographically smallest permutation of S (i.e. the sorted string) not the answer?

 **Solution**If there are no occurrences of `a`, `b` or `c` in S, sort S and output it.

Else, if T≠ `abc`, sort S and output it.

Else, output all `a`, then all `c`, then all `b`, then the rest of the string sorted.

 **Implementation (C++, I_Love_YrNameCouldBeHere)**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
int main() {
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        cin >> s >> t;
        sort(all(s));
        vector<int> cnt(26, 0);
        for(auto x: s)cnt[x - 'a']++;
        if(t != "abc" || !cnt[0] || !cnt[1] || !cnt[2])cout << s << "n";
        else{
            while(cnt[0]--)cout<<"a";
            while(cnt[2]--)cout<<"c";
            while(cnt[1]--)cout<<"b";
            for(int i = 3;i < 26; ++i){
                while(cnt[i]--)cout<<char('a' + i);
            }
            cout << "n";
        }
    }
}
```
 **Fun fact**Originally, the author and two testers' solutions are all wrong, but we didn't notice until the third tester submitted the real correct solution.

[1617B - GCD Problem](../problems/B._GCD_Problem.md "Codeforces Round 761 (Div. 2)")

 **Hint**There must exist a solution for c=1 under the given constraints.

 **Solution**Key observation: there always exists a solution with c=1 under the given constraints. We set n≥10 because there is no solution when 1≤n≤5 or n=7.

Solution 1: Brute force from a=2,3,4,… and calculate the value of b (b=n−a−1), then check whether gcd(a,b)=1. It works, because you will find a prime number p≤29 such that n−1 does not divide p.

Solution 2: Randomly choose a and calculate b (b=n−a−1). Repeating that for enough times will eventually get you a pair of (a,b) such that gcd(a,b)=1.

Solution 3: Constructive solution.

 * When n≡0(mod2), output (n−3,2,1).
* When n≡1(mod4), output (⌊n2⌋−1,⌊n2⌋+1,1).
* When n≡3(mod4), output (⌊n2⌋−2,⌊n2⌋+2,1).
 **Implementation (Solution 1, Java, SecondThread)**
```cpp
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner fs = new Scanner(System.in);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			for (int target=2; true; target++) {
				if (gcd(n-1-target, target)!=1)
					continue;
				System.out.println(n-1-target+" "+target+" "+1);
				if (n-1-target<=1) throw null;
				break;
			}
		}
	}
	
	static int gcd(int a, int b) {
		return b==0?a:gcd(b, a%b);
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
}
```
 **Implementation (Solution 2, C++, dbsic211)**
```cpp
#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
void solve(int tc) {
    int n; 
    cin >> n;
    while(1) {
        int k = uniform_int_distribution<int>(2, n-2)(rng);
        int l = n-k-1;
        if(k != l && k != 1 && l != 1 && gcd(k, l) == 1) {
            cout << k << ' ' << l << ' ' << 1 << endl;
            break;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) {
        solve(i);
    }
}
```
 **Implementation (Solution 3, C++, anthony123)**
```cpp
#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	if (n%2==0) cout<<"2 "<<(n-1)-2<<" 1n";
	else {
		int cur=(n-1)/2;
		if (cur%2==0) cout<<cur-1<<" "<<cur+1<<" "<<1<<endl;
		else cout<<cur-2<<" "<<cur+2<<" "<<1<<endl;
	}
}
signed main(){
	int t;
	cin>>t;
	while (t--) solve();
}
```
[1617C - Paprika and Permutation](../problems/C._Paprika_and_Permutation.md "Codeforces Round 761 (Div. 2)")

 **Hint 1**For any two positive integers x, y that satisfy x≥y, what is the maximum value of xmody?

 **Hint 2**Consider the following input: n=4, a=[3,3,10,10]. Sometimes, we don't need to do anything to some ai. When do we have to make operations, and when do we not have to?

 **Solution**Key observation: xmody<x2 if x≥y, and xmody=x if x<y. 

Notice that the bigger the x, the bigger the range of values that can be obtained after one mod operation. So, intuitively, we want to assign smaller ai to smaller numbers in the resulting permutation.

However, if ai satisfies 1≤ai≤n, we can just leave it there and use it in the resulting permutation (if multiple ai satisfy 1≤ai≤n and have the same value, just choose one). Let's suppose in the optimal solution, we change x to y and change z to x for some z>x>y (x, y, z are values, not indices). Then changing x to x (i.e. doing nothing) and changing z to y uses 1 less operation. And, if it is possible to change z to x, then it must be possible to change z to y. However, if it is not possible to change z to x, it might still be possible to change z to y.

Therefore, the solution is as follows: Sort the array. For each element i in the sorted array:

 * If 1≤ai≤n and it is the first occurrence of element with value ai, leave it there.
* Else, let the current least unassigned value in the resulting permutation be m, if m<ai2, we can assign the current element to value m and add the number of operations by 1. Else, output −1 directly.

The solution works in O(nlogn).

 **Implementation (C++, physics0523)**
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t>0){
        t--;
        int n;
        cin >> n;
        set<int> st;
        for(int i=1;i<=n;i++){st.insert(i);}
        vector<int> rem;
        for(int i=0;i<n;i++){
            int v;
            cin >> v;
            if(st.find(v)!=st.end()){st.erase(v);}
            else{rem.push_back(v);}
        }
        sort(rem.begin(),rem.end());
        reverse(rem.begin(),rem.end());
        int pt=0;
        bool err=false;
        for(auto &nx : rem){
            auto it=st.end();
            it--;
            int ctg=(*it);
            if(ctg>(nx-1)/2){err=true;break;}
            st.erase(it);
        }
        if(err){cout << "-1n";}
        else{cout << rem.size() << 'n';}
    }
    return 0;
}
```
[1617D1 - Too Many Impostors (easy version)](../problems/D1._Too_Many_Impostors_(easy_version).md "Codeforces Round 761 (Div. 2)")

 **Hint 1**The weird constraint, n3<k<2n3, is crucial.

 **Hint 2**If you know the index of one crewmate and one impostor, how to find the roles of other n−2 players in exactly n−2 queries?

 **Hint 3**Query players (1,2,3), (2,3,4), …, (n−1,n,1), (n,1,2). After that, you can surely find out the index of one crewmate and one impostor. Try to find out how.

 **Solution**Key observation: if result of query (a,b,c) ≠ result of query (b,c,d), since b and c are common, players a and d have different roles. Additionally, if result of query (a,b,c) = 1 then player a is a crewmate (and player d is an impostor), vice versa.

The first step is to query players (1,2,3), (2,3,4), …, (n−1,n,1), (n,1,2).

If the results of any two adjacent queries (or queries (1,2,3) and (n,1,2)) are different, we instantly know the roles of the two players that are only included in one query — one is a crewmate, one is an impostor. Since the number of impostors k and crewmates n−k satisfy k>n3 and n−k>n3, there must be one pair of adjacent queries that are different.

After we know one crewmate and one impostor (let's call them a, d), we can query these two players with each one of the rest of the players. If a query (a,d,x) (1≤x≤n, x≠a and x≠d) returns 0, player x is an impostor, else player x is a crewmate.

In total, 2n−2 queries are used.

 **Implementation (C++, dbsic211)**
```cpp
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N; 
    cin >> N;
    int res[N];
    for(int i=0; i<N; i++) {
        cout << "? " << i + 1 << " " << (i+1) % N + 1 << " " << (i+2) % N + 1 << endl;
        cin >> res[i];
    }
    vector<int> imp;
    for(int i=0; i<N; i++) {
        if(res[i] != res[(i+1) % N]) {
            if(res[i] == 0) imp.push_back(i + 1);
            else imp.push_back((i+3) % N + 1);
            for(int j=0; j<N; j++) {
                if(j != i && j != (i+3) % N) {
                    cout << "? " << i + 1 << " " << (i+3) % N + 1 << " " << j + 1 << endl;
                    int r;
                    cin >> r;
                    if(r == 0) imp.push_back(j + 1);
                }
            }
            break;
        }
    }
    cout << "! " << imp.size();
    for(int x : imp) cout << " " << x;
    cout << endl;
}
int main() {
    int T;
    cin >> T;
    for(int i=1; i<=T; i++) {
        solve();
    }
}
```
[1617D2 - Too Many Impostors (hard version)](../problems/D2._Too_Many_Impostors_(hard_version).md "Codeforces Round 761 (Div. 2)")

Thanks must be given to [arvindf232](https://codeforces.com/profile/arvindf232 "Grandmaster arvindf232") and [generic_placeholder_name](https://codeforces.com/profile/generic_placeholder_name "Master generic_placeholder_name") for the solution.

 **Hint 1**Aim to find an impostor and a crewmate's index in n3+c queries, with c being a small constant.

 **Hint 2**Consider splitting the n players into groups of 3 (and query each group) in order to reach the goal in Hint 1. What is special about the results of the n3 queries?

 **Solution (Step 1)**Firstly query (1,2,3), (4,5,6), …, (n−2,n−1,n). Due to the constraint n3<k<2n3, among the results of these n3 queries, there must be at least one 0 and one 1. Now, let's call a tuple (a,b,c) that returns 0 a 0-majority tuple, and vice versa. 

From the easy version, notice that finding one crewmate and one impostor is very helpful in determining the roles of the remaining players. Let's make use of the above observation, and pick one adjacent 0-majority tuple and 1-majority tuple. 

Let's say we picked (i,i+1,i+2) and (i+3,i+4,i+5). Then, we query (i+1,i+2,i+3) and (i+2,i+3,i+4). Among the four queries (i,i+1,i+2), (i+1,i+2,i+3), (i+2,i+3,i+4), (i+3,i+4,i+5), there must be a pair of adjacent queries with different results. From the easy version, we can directly find the index of an impostor and a crewmate.

In all the above cases, we end up knowing an impostor and a crewmate using n3+2 queries, including the first step.

 **Hint 3**You have the index of an impostor and a crewmate now, and around 2n3 queries left. 

Consider using at most 2 queries to find out roles of each player in each group of 3 from Step 1, which should add up to 2n3 queries. 

Make use of the information you know about each group (whether it is 0-majority or 1-majority).

 **Hint 4**Assume a tuple (group of 3) is 0-majority. There are 4 possibilities of roles of the 3 players in the tuple, which are:

 * impostor, impostor, impostor
* crewmate, impostor, impostor (and its permutations)

In each query, reduce half of the possibilities.

 **Solution (Step 2)**It remains to figure out how we can find the roles of the remaining players using 2n3 queries. For each tuple (i,i+1,i+2) queried in the first step, let's assume the tuple is 0-majority (because the other case can be solved similarly). Then, there are only four possibilities:

 * All players i, i+1, i+2 are impostors.
* Player i is a crewmate, players i+1, i+2 are impostors.
* Player i+1 is a crewmate, players i, i+2 are impostors.
* Player i+2 is a crewmate, players i, i+1 are impostors.

Earlier, we found the index of a crewmate and an impostor, let the index of the crewmate be a and the impostor be b.

If the tuple (i,i+1,a) is 1-majority, either player i or player i+1 is a crewmate. So, we reduced the number of possibilities to 2. To check which player is the crewmate, query it with a and b like we did in the easy version.

Else, either there are no crewmates or player i+2 is a crewmate. So, we reduced the number of possibilities to 2. To check the role of player i+2, query it with a and b like we did in the easy version.

In both cases, we use 2 queries for each initial tuple (i,i+1,i+2). So, we used n+2 queries in total, but we gave you a bit more, in case you used some more queries to find a crewmate and an impostor.

There is one corner case we should handle: if the tuple (i,i+1,i+2) contains a or b, we can just naively query for each unknown role in the tuple, since we won't use more than 2 queries anyway.

 **Implementation (C++, dbsic211)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int query(int a, int b, int c) {
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int r; cin >> r;
    return r;
}
void solve(int tc) {
    int n; cin >> n;
    int a[n+1], role[n+1];
    for(int i=1; i+2<=n; i+=3) a[i] = query(i, i+1, i+2);
    int imp, crew;
    for(int i=1; i<=n; i++) role[i] = -1;
    for(int i=1; i+5<=n; i+=3) {
        if(a[i] != a[i+3]) {
            a[i+1] = query(i+1, i+2, i+3), a[i+2] = query(i+2, i+3, i+4);
            for(int j=i; j<i+3; j++) {
                if(a[j] != a[j+1]) {
                    if(a[j] == 0) {
                        imp = j, crew = j+3;
                        role[j] = 0, role[j+3] = 1;
                    }
                    else {
                        imp = j+3, crew = j;
                        role[j+3] = 0, role[j] = 1;
                    }
                }
            }
            break;
        }
    }
    for(int i=1; i+2<=n; i+=3) {
        if(i == imp || i+1 == imp || i+2 == imp || i == crew || i+1 == crew || i+2 == crew) {
            for(int j=i; j<i+3; j++) {
                if(role[j] == -1) {
                    role[j] = query(imp, crew, j);
                }
            }
        }
        else if(a[i] == 0) {
            if(query(i, i+1, crew) == 1) {
                if(query(i, imp, crew) == 0) role[i] = 0, role[i+1] = 1;
                else role[i] = 1, role[i+1] = 0;
                role[i+2] = 0; 
            }
            else {
                role[i] = role[i+1] = 0;
                role[i+2] = query(i+2, imp, crew);
            }
        }
        else {
            if(query(i, i+1, imp) == 0) {
                if(query(i, imp, crew) == 0) role[i] = 0, role[i+1] = 1;
                else role[i] = 1, role[i+1] = 0;
                role[i+2] = 1; 
            }
            else {
                role[i] = role[i+1] = 1;
                role[i+2] = query(i+2, imp, crew);
            }
        }
    }
    cout << "! ";
    queue<int> q;
    for(int i=1; i<=n; i++) if(role[i] == 0) q.push(i);
    cout << q.size();
    while(q.size()) {
        cout << " " << q.front();
        q.pop();
    }
    cout << endl;
}
int main() {
    int T; cin >> T;
    for(int i=1; i<=T; i++) solve(i);
}
```
[1617E - Christmas Chocolates](../problems/E._Christmas_Chocolates.md "Codeforces Round 761 (Div. 2)")

 **Hint 1**Translate the problem into a graph problem. What feature of the graph is it asking about?

 **Hint 2**Draw out the graph, for ai≤10. What special property does the graph have?

 **Hint 3**Any specific algorithm to solve the problem (in Hint 1)?

 **Solution (Step 1)**In graph terms, the problem is as follows: in a graph with infinite nodes, two nodes x and y are connected if x+y=2k for some k≥0. Among n special nodes, find the pair of nodes (i,j) with maximum shortest distance.

Here comes the key observation: For any i≥1, there exists only one j (0≤j<i) such that i+j=2k for some k≥0.

The proof is as follows: let's say that 0≤j1,j2<i, j1≥j2, i+j1=2k1, i+j2=2k2. Then, j1−j2=2k2⋅(2k1−k2−1). So, j1≡j2(mod2k2). Since i≤2k2, j1=j2.

Then, we realize we can build a graph as follows: add an edge between x and y (x,y≥0) if x+y=2k for some k≥0. Because of the first key observation, the graph must be **a tree**. We can root the tree at node 0.

Our problem is equivalent to finding the pair of nodes which have maximum distance in a tree, which can be solved using the diameter of tree algorithm.

 **Hint 4**We can't build the entire tree as it has 109+1 nodes. Try to notice something about the depth of the tree, then think of how this could help us solve the problem (by building the tree, or otherwise).

 **Solution (Step 2)**Since 0≤ai≤109, it is impossible to build the entire tree. A final observation is that: Consider any node v with degree ≥2 in the tree, then v>pv and pv>ppv, therefore v+pv>pv+ppv (px denotes the parent of node x in the tree). 

Hence the depth of the tree is ⌈log(max(ai))⌉=30, since there are only ⌈log(max(ai))⌉ possible k (0≤k<30) for the sum of two nodes connected by an edge.

So, there are two ways to do it: the first way is to build parts of the tree: only the n given nodes and the ancestors of the n nodes. There will be at most O(nlogmax(ai)) nodes, which should fit into the memory limit. The second way is to not build the tree at all, and calculate the LCA (Lowest Common Ancestor) of two nodes to find their distance. Since the depth of the tree is 30, LCA of two nodes can be computed by simply checking every ancestor of both nodes.

In both ways, the time complexity is O(nlogmax(ai)).

 **Implementation (C++, physics0523)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int f(int x){
    for(int i=0;;i++){
        if((1<<i)>=x){
            return (1<<i)-x;
        }
    }
}

using pi=pair<int,int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int,pair<pi,pi>> mp;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        pq.push(v);
        mp[v].first=make_pair(0,i+1);
    }
    while(!pq.empty()){
        int od=pq.top();pq.pop();
        if((!pq.empty()) && od==pq.top()){continue;}
        if(od!=1){
            int nx=f(od);
            pq.push(nx);
            pi send=mp[od].first;
            send.first++;
            if(mp[nx].first<send){
                mp[nx].second=mp[nx].first;
                mp[nx].first=send;
            }
            else if(mp[nx].second<send){mp[nx].second=send;}
        }
    }
    int ra=0,rb=0,rc=-1;
    for(auto &nx : mp){
        pair<pi,pi> tg=nx.second;
        if(tg.first.second==0 || tg.second.second==0){continue;}
        if(rc<tg.first.first+tg.second.first){
            rc=tg.first.first+tg.second.first;
            ra=tg.first.second;
            rb=tg.second.second;
        }
    }
    cout << ra << ' ' << rb << ' ' << rc << 'n';
    return 0;
}
```
