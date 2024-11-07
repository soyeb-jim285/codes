# Tutorial_(en)

Thanks for participating. We apologize for problem F that has appeared before. Still, we hope you all enjoy our round!

[1705A - Mark the Photographer](../problems/A._Mark_the_Photographer.md "Codeforces Round 807 (Div. 2)")
---------------------------------------------------------------------------------------------------------------

Author: [MarkBcc168](https://codeforces.com/profile/MarkBcc168 "Master MarkBcc168")

 **Hint 1**First, sort h1≤h2≤⋯≤h2n. There is a very explicit description to which hi's work.

 **Hint 2**What is the optimal arrangement that maximizes the minimum difference across all pairs?

 **Tutorial**We have a very explicit description of whether the arrangement is possible. Sort the heights so that h1≤h2≤⋯≤h2n. Then, there exists such arrangement if and only if all the following conditions hold.

 hn+1−h1≥xhn+2−h2≥x⋮h2n−hn≥xWe present two proofs.

 

---

*Proof 1 (Direct Proof).* Suppose that the arrangement is possible. We will show that for each i, we have hn+i−hi≥x.

To do so, note that n+1 people who have height in [hi,hn+i]. It's impossible that these n+1 people got assigned to different columns (because there are n columns), so there exist two people that got assigned to the same column. 

However, because these two people have height in [hi,hn+i], the difference in heights between these two people is at most hn+i−hi. As the difference is at least x by the arrangement, we must have that hn+i−hi≥x. ◼

 

---

*Proof 2 (Exchange Argument).* First, we look at two pairs. Suppose that the i-th person in the first and second row have heights a<b, while the j-th person in the first and second row have heights c<d. 

 …a…c……b…d… * Assume that b≥c, then we switch b,c. The arrangement still works since a−c≥a−b≥x and b−d≥c−d≥x.
* Similarly, a≥d yields a switch.

Thus, we can keep exchanging until anyone in the first row is at least as tall as anyone in the second row. Thus, the first row must be hn+1,hn+2,…,h2n, while the second row must be h1,h2,…,hn in some order.

Now, we look at the same picture again. Assume that a≥c but b≤d. then, we can switch b,d, and it still works because a−d≥c−d≥x and c−b≥c−d≥x. Thus, we can switch the second row until it matches the order of the first row.

Therefore, we force the first row to be hn+1,hn+2,…,h2n, while the second row must be h1,h2,…,hn in that order. This implies the conclusion. ◼

 

---

Time Complexity: O(nlogn) for sorting.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 0; i < n; ++i)
        if (a[n + i] - a[i] < x) ok = false;
    cout << (ok ? "YES" : "NO") << "n";
}

int main() {
    int tt; cin >> tt;
    while (tt--) solve();
}

```
[1705B - Mark the Dust Sweeper](../problems/B._Mark_the_Dust_Sweeper.md "Codeforces Round 807 (Div. 2)")
---------------------------------------------------------------------------------------------------------------

Author: [MarkBcc168](https://codeforces.com/profile/MarkBcc168 "Master MarkBcc168")

 **Hint**The optimal way is to fill all the zero entries first.

 **Tutorial**Delete the leading zeroes in the array a (i.e., the first t numbers of a that are zero) so that now a1≠0. Let k be the number of 0's in a1,a2,…,an−1. The answer is

 (a1+a2+⋯+an−1)+k.To see why, let Mark keep filling the *holes* (rooms with dust level 0) first by subtracting the first nonzero index and changing the first zero index to 1. This takes k moves to fill all zeroes in a1,a2,…,an−1. Then, we can start moving, from left to right, all dust to the n-th room, taking a1+a2+⋯+an−1 moves.

Finally, we argue that this is the minimum number of moves. To that end, we prove that each move decreases the answer by at most 1. We consider two cases.

 * If a move has j=n, then it decreases a1+a2+⋯+an−1 by 1 but does not decrease k.
* If j≠n, then the move doesn't decrease a1+a2+⋯+an−1 and decreases k by at most 1.

Thus, we are done. The time complexity is O(n).

 **Code**
```cpp
#include <iostream>
#include <vector>
#define ll long long

using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll ans = 0;
    int ptr = 0;
    while(ptr < n && a[ptr] == 0)
        ptr++;
    for(int i = ptr; i < n-1; ++i){
        ans += a[i];
        if(a[i] == 0) ans++;
    }
    cout << ans << "n";
}
int main(){
    int tt; cin >> tt;
    while(tt--) solve();
}
```
[1705C - Mark and His Unfinished Essay](../problems/C._Mark_and_His_Unfinished_Essay.md "Codeforces Round 807 (Div. 2)")
-----------------------------------------------------------------------------------------------------------------------

Author: [MarkBcc168](https://codeforces.com/profile/MarkBcc168 "Master MarkBcc168")

 **Hint 1**What's in common between all letters that were copied at the same time?

 **Hint 2**The answer is the difference between the current position and the position where it came from. That's what you need to store.

 **Hint 3**By tracking the difference, you can recurse to the previously-copied substring.

 **Tutorial**This is an implementation problem. What you need to do is after the i-th copying operation, we need to keep track of the beginning point ai and the ending point bi of the appended string. Moreover, we also keep track the *subtraction distance* ti=ai−li so that for k∈[ai,bi], the k-th letter is the same as the (k−ti)-th letter. Thus, we have recursed the position to the smaller position k−ti, so we keep doing that until we reach the initial string.

Therefore, to solve this problem, we iterate from i=c,c−1,…,1. If k is in [ai,bi], subtract k by ti. After all operations, k should be at the inital string, and we output the k-th letter.

The time complexity of this solution is O(cq). However, less efficient solutions of O((clogc)q) (using binary search each time) or O(c2q) (by going through all intervals in each iteration) pass as well.

 **Code**
```cpp
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int n, c, q; cin >> n >> c >> q;
    string s; cin >> s;

    vector<ll> left(c+1), right(c+1), diff(c+1);
    left[0] = 0;
    right[0] = n;

    for(int i=1; i<=c; ++i){
    	ll l, r; cin >> l >> r;
    	l--; r--;
    	left[i] = right[i-1];
    	right[i] = left[i] + (r-l+1);
    	diff[i] = left[i] - l;
    }

    while(q--){
    	ll k; cin >> k;
    	k--;
    	for(int i=c; i>=1; --i){
    		if(k < left[i]) continue;
    		else k -= diff[i];
    	}
    	cout << s[k] << "n";
    }

}

int main(){
    int tt; cin >> tt;
    while(tt--) solve();
}
```
[1705D - Mark and Lightbulbs](../problems/D._Mark_and_Lightbulbs.md "Codeforces Round 807 (Div. 2)")
-------------------------------------------------------------------------------------------------------------

Author: [MarkBcc168](https://codeforces.com/profile/MarkBcc168 "Master MarkBcc168")

 **Hint 1**Look at all the 01's and 10's carefully.

 **Hint 2**The sum of the number of 01's and 10's is constant.

 **Hint 3**Consider all positions of 01's and 10's. How does it change in each operation?

 **Tutorial**As explained in the sample explanations, the operation cannot change the first or the last bit. Thus, if either s1≠t1 or sn≠tn, simply return -1.

Now, the key idea is to consider a binary ¯s=(s1⊕s2)(s2⊕s3)…(sn−1⊕sn) of length n−1, where a⊕b denotes the XOR operation of bits a and b. Then, it's easy to verify that the operation acts on ¯s by just swapping two different bits. An example is shown below

 s¯s00010100111↓↓00110101011↓↓01110110011↓↓01100110101↓↓01101110110↓↓01001111010Thus, the operation is possible if and only if ¯s and ¯t has the same number of 1's. Moreover, if a1,a2,…,ak are the positions of 1's in ¯s and b1,b2,…,bk are the positions of 1's in ¯t. Then, the minimum number of moves is given by

 |a1−b1|+|a2−b2|+⋯+|ak−bk|,which can be evaluated in O(n).

This is a well-known fact, but for completeness, here is the proof. Note that the operation is moving 1 to left or right by one position. Thus, to achieve that number of moves, simply move the first 1 from a1 to b1, move the second 1 from a2 to b2, …, and move the k-th 1 from ak to bk. For the lower bound, notice that the i-th 1 cannot move past the (i−1)-th or (i+1)-th 1. Thus, it takes at least |ai−bi| moves to move the i-th 1 from ai to bi. Summing gives the conclusion.

Note that another way to think about this problem is to look at the block of 1's and 0's and notice that the number of blocks remains constant. This is more or less the same as the above solution.

 **Code**
```cpp
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int n; cin >> n;
    string s,t; cin >> s >> t;
    vector<ll> pos_s, pos_t;

    if(s[0] != t[0] || s[n-1] != t[n-1]){
        cout << -1 << "n";
        return;
    }
    for(int i=0; i<n-1; i++){
        if(s[i] != s[i+1]) pos_s.push_back(i);
        if(t[i] != t[i+1]) pos_t.push_back(i);
    }
    if(pos_s.size() != pos_t.size()){
        cout << -1 << "n";
    }
    else{
        int k = pos_s.size();
        ll ans = 0;
        for(int i=0; i<k; ++i){
            ans += abs(pos_s[i] - pos_t[i]);
        }
        cout << ans << "n";
    }
}

int main(){
    int tt; cin >> tt;
    while(tt--) solve();
}
```
[1705E - Mark and Professor Koro](../problems/E._Mark_and_Professor_Koro.md "Codeforces Round 807 (Div. 2)")
-----------------------------------------------------------------------------------------------------------------

Author: [abc241](https://codeforces.com/profile/abc241 "Specialist abc241")

 **Hint 1**Find a concise description of the answer first.

 **Hint 2**Think about power of two.

 **Hint 3**The sum 2a1+2a2+⋯+2an is constant. Show that the answer must be the most significant bit of that.

 **Hint 4**Use either bitset or lazy segment tree to simulate the addition/subtraction.

 **Tutorial**The key observation is the following.

**Claim:** The answer is ⌊log2(2a1+2a2+⋯+2an)⌋.

*Proof:* The upper bound is pretty clear, as the operation doesn't change the ∑2ai. Moreover, the sum must be at least 2ans, giving the result.

For the construction, let Mark keep performing the operation until he cannot. At this point, all numbers must be distinct, and the ∑2ai is unchanged. Let the current numbers on the board be b1<b2<⋯<bk. Then,

 ∑ni=12ai=2b1+2b2+⋯+2bk≤21+22+⋯+2bk<2bk+1.Thus, Mark can make the final number be bk=⌊log2(2a1+2a2+⋯+2an)⌋ as desired. ◼

 

---

Finally, we need a data structure to maintain the ∑2ai and simulate base 2 addition. There are many ways to proceed, including the following:

 * Using bitsets, partition the bits into many chunks of w bits (w between 50 and 64 is fine). This gives O(n2/w) complexity, but its low constant factor makes it enough to pass comfortably.
* Use lazy segment augmented with O(logn) binary search. For each bit added, find where the longest streak of 1's to the left of that bit ends, and update accordingly. Similarly, for each bit subtracted, find where the longest streak of 0's to the left of that bit ends, and update accordingly. The total complexity is O(nlogn).
 **Code (Bitsets, by errorgorn)**
```cpp
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Super Idol的笑容
//    都没你的甜
//  八月正午的阳光
//    都没你耀眼
//  热爱105°C的你
// 滴滴清纯的蒸馏水

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl 'n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct bitset{
    unsigned long long arr[3130]={};
    unsigned long long AF=-1ull;
    
    void flip(int l,int r){
        arr[l/64]^=(1ull<<(l%64))-1;
        if (r%64==63) arr[r/64]^=AF;
        else arr[r/64]^=(1ull<<(r%64+1))-1;
        l/=64,r/=64;
        if (l==r) return;
        arr[l]^=AF;
        
        for (int x=l+1;x<r;x++) arr[x]^=AF;
    }
    
    int get(int i){
        if (arr[i/64]&(1ull<<(i%64))) return 1;
        else return 0;
    }
    
    int get1(int i){
        //search [i%64,64) on i/64 first
        unsigned long long mask=AF^((1ull<<(i%64))-1);
        
        i=i/64;
        unsigned long long temp=arr[i]&mask;
        if (temp) return i*64+__builtin_ctzll(temp);
        i++;
        while (true){
            if (arr[i]==0) i++;
            else return i*64+__builtin_ctzll(arr[i]);
        }
    }
    
    int get0(int i){
        //search [i%64,64) on i/64 first
        unsigned long long mask=AF^((1ull<<(i%64))-1);
        
        i=i/64;
        unsigned long long temp=(arr[i]^AF)&mask;
        if (temp) return i*64+__builtin_ctzll(temp);
        i++;
        while (true){
            if (arr[i]==AF) i++;
            else return i*64+__builtin_ctzll(arr[i]^AF);
        }
    }
    
    int gethigh(){
        int i=3129;
        while (true){
            if (arr[i]==0) i--;
            else return i*64+63-__builtin_clzll(arr[i]);
        }
    }
} BS;

int n,q;
int arr[200005];

void add(int i){
    BS.flip(i,BS.get0(i));
}

void del(int i){
    BS.flip(i,BS.get1(i));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);
    
    cin>>n>>q;
    rep(x,1,n+1) cin>>arr[x];
    rep(x,1,n+1) add(arr[x]);
    
    int a,b;
    while (q--){
        cin>>a>>b;
        del(arr[a]);
        arr[a]=b;
        add(arr[a]);
        
        cout<<BS.gethigh()<<endl;
    }
}
```
 **Code (Lazy Segment)**
```cpp
#include<bits/stdc++.h>
using namespace std;

struct LazySeg {
    int l, r;
    int val = 0, tag = 0;
    bool is_lazy = false;
    LazySeg * l_child = NULL, * r_child = NULL;

    LazySeg(int _l, int _r) {
        l = _l;
        r = _r;
        if (r - l > 1) {
            int m = (l + r) / 2;
            l_child = new LazySeg(l, m);
            r_child = new LazySeg(m, r);
        }
    }~LazySeg() {
        delete l_child;
        delete r_child;
    }
    void unlazy() {
        if (!is_lazy) return;
        val = (r - l) * tag;
        if (r - l <= 1) return;
        l_child -> tag = tag;
        l_child -> is_lazy = true;
        r_child -> tag = tag;
        r_child -> is_lazy = true;
        tag = 0;
        is_lazy = false;
    }
    void update(int from, int to, int x) {
        unlazy();
        if (from >= r || l >= to) return;
        if (from <= l && to >= r) {
            tag = x;
            is_lazy = true;
            unlazy();
        } else {
            l_child -> update(from, to, x);
            r_child -> update(from, to, x);
            val = l_child -> val + r_child -> val;
        }
    }
    int query(int from, int to) {
        if (from >= r || l >= to) return 0;
        unlazy();
        if (from <= l && to >= r) return val;
        else {
            if (l_child == NULL) return 0;
            return l_child -> query(from, to) + r_child -> query(from, to);
        }
    }
    //pre = prefix in [l,k)
    int max_right(int k, int pre, int v) {
        unlazy();
        if (r - l == 1) {
            if (val == v) return l;
            else return l - 1;
        }
        l_child -> unlazy();
        int mid = (l + r) / 2;
        if (mid <= k) {
            return r_child -> max_right(k, pre - l_child -> val, v);
        } else if (l_child -> val - pre == v * (mid - k)) {
            //left to mid-1 has all 1's => answer must be >= mid-1
            return r_child -> max_right(mid, 0, v);
        } else {
            return l_child -> max_right(k, pre, v);
        }
    }
    //suff = suffix
    int get_answer() {
        unlazy();
        if (r - l == 1) {
            if (val == 1) return l;
            else return l - 1;
        }
        r_child -> unlazy();
        if (r_child -> val == 0) {
            //[mid to end] are all 0
            return l_child -> get_answer();
        } else {
            return r_child -> get_answer();
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    LazySeg tr(0, 200100);

    auto add = [ & ](int x) {
        int y = tr.max_right(x, tr.query(0, x), 1) + 1;
        if (y == x) { //no carry; just change 0 to 1
            tr.update(x, x + 1, 1);
        } else { //there is a carry; set the whole block of 1's to 0
            tr.update(x, y, 0);
            tr.update(y, y + 1, 1);
        }
    };

    auto remove = [ & ](int x) {
        int y = tr.max_right(x, tr.query(0, x), 0) + 1;
        if (y == x) {
            tr.update(x, x + 1, 0);
        } else {
            tr.update(x, y, 1);
            tr.update(y, y + 1, 0);
        }
    };
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        add(a[i]);
    }
    while (q--) {
        int k, l; cin >> k >> l;
        k--; 
        remove(a[k]); add(l);
        a[k] = l;
        cout << tr.get_answer() << "n";
    }
}
```
[1705F - Mark and the Online Exam](../problems/F._Mark_and_the_Online_Exam.md "Codeforces Round 807 (Div. 2)")
------------------------------------------------------------------------------------------------------------------

Author: [MarkBcc168](https://codeforces.com/profile/MarkBcc168 "Master MarkBcc168")

Unfortunately, a harder version of this problem has appeared in a Chinese contest [here](https://codeforces.com/https://www.luogu.com.cn/problem/P7848) and [here](https://codeforces.com/https://www.luogu.com.cn/problem/T183641). You can look at their solution [here](https://codeforces.com/https://www.luogu.com.cn/blog/1973224568qq/kao-shi-2021-coe-iii-d#). We thank many contestants who pointed it out.

 **Hint 0**It's possible to solve this problem without any randomization. See the subsequent hints for how to do so.

 **Hint 1**Observe that we can take differences between two very close queries to get the number of T's in a small subsequence.

 **Hint 2**You can take the difference against a pre-computed query. Applying this with a group of two questions.

 **Hint 3**You have three possibilities: either TT, FF, and TF,FT. If the third possibility happens, simultaneously figure out whether is TF or FT and answer one question within one query.

 **Hint 4**You will need to precompute the query TFTF…TF.

 **Tutorial**There are many possible approaches, including using randomized algorithms. However, I will present the solution that takes about 2n3 queries deterministically.

We pre-query TTT...T and TFTF...TF. Then, for i=1,2,…,⌊n3⌋, we take the difference when both the (2i−1)-th and the 2i-th question in TTT...T is changed to F.

 * If the difference is +2, then both answers must be F.
* If the difference is −2, then both answers must be T.
* Else, the answers must be TF or FT in some order.

Now, here is the key idea: if the last case happens, then we can figure out if it's TF or FT **as well as** the answer to one more question in one query. To do so, compare the previous TFTF...TF with a new query that has 3 differences:

 TFTF…TF…T…TFTFTF…FT…F…TF(Note: we assume that the third question corresponds to T in the query. If it's F, just change to T and proceed analogously.)

There are four possible scenarios.

 * If the answers are TF and T, then the difference is −3.
* If the answers are TF and F, then the difference is −1.
* If the answers are FT and T, then the difference is +1.
* If the answers are FT and F, then the difference is +3.

Therefore, we can distinguish these four scenarios in one go.

Finally, if the first two cases happen, we can easily figure out the answer to one more question in one query (say, by changing that question to F and compare with the TT...T query). Either way, we can deduce the answer to 3 questions in 2 queries, leading to a solution with 2n3 queries.

Note that this solution can be easily improved to 3n5 on average by randomly shuffling the questions.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;

int query(string s){
    cout << s << endl;
    cout.flush();
    int x; cin >> x;
    if(x==n) exit(0);
    return x;
}

int main(){
    cin >> n;

    //query true count
    string all_T(n, 'T'), ans(n, '?');
    int cnt_T = query(all_T);
    
    //query TF
    string all_TF(n, 'T');
    for(int i=1; i<n; i+=2) all_TF[i] = 'F';
    int cnt_TF = query(all_TF);

    //begin the loop
    int l = 0, r = n-1;
    while(r >= l){
        if(r==l){ //only l is undetermined
            string s(all_T);
            s[l] = 'F';
            int k = query(s);

            if(k > cnt_T){
                ans[l] = 'F';
            }
            else{
                ans[l] = 'T';
            }
            l++; r--;
        }
        else{
            string s(all_T);
            s[l] = 'F'; s[l+1] = 'F';
            int k = query(s) - cnt_T;

            if(k == 2){
                ans[l] = 'F'; ans[l+1] = 'F';
                l += 2;
            }
            else if(k == -2){
                ans[l] = 'T'; ans[l+1] = 'T';
                l += 2;
            }
            else{
                if(r == l+1){ //only l and l+1 left; figure out the order
                    string s(all_T);
                    s[l] = 'F';
                    int k = query(s);
                    
                    if(k > cnt_T){
                        ans[l] = 'F'; ans[l+1] = 'T';
                    }
                    else{
                        ans[l] = 'T'; ans[l+1] = 'F';
                    }
                    l += 2;
                }
                else{ //determine l, l+1, r
                    string s(all_TF);
                    s[l] = 'F'; s[l+1] = 'T';

                    if(s[r] == 'F') s[r] = 'T';
                    else s[r] = 'F';

                    int k = query(s) - cnt_TF;
                    if(k == 3){
                        ans[l] = 'F'; ans[l+1] = 'T'; ans[r] = s[r];
                    }
                    else if(k == 1){
                        ans[l] = 'F'; ans[l+1] = 'T'; ans[r] = all_TF[r];
                    }
                    else if(k == -1){
                        ans[l] = 'T'; ans[l+1] = 'F'; ans[r] = s[r];
                    }
                    else{
                        ans[l] = 'T'; ans[l+1] = 'F'; ans[r] = all_TF[r];
                    }
                    l += 2; r--;
                }
            }
        }
    }
    query(ans);
}
```
