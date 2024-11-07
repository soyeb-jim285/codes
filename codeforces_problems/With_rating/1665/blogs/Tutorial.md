# Tutorial

Again, I hope that you liked all the problems. Share your ideas and solutions in the comments, because there are always different ones! So, the editorial:

 **A: GCD vs LCM**[1665A - GCD vs LCM](../problems/A._GCD_vs_LCM.md "Codeforces Round 781 (Div. 2)")

 **Editorial**In this problem it is enough to print n−3, 1, 1, 1. It is easy to see that this answer is correct for any n≥4.

 **Implementation (C++, shishyando)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n;
        cin >> n;
        cout << n - 3 << ' ' << 1 << ' ' << 1 << ' ' << 1 << 'n';
    }
    return 0;
}
```
 **B: Array Cloning Technique**[1665B - Array Cloning Technique](../problems/B._Array_Cloning_Technique.md "Codeforces Round 781 (Div. 2)")

 **Editorial**We will use a greedy technique. Let's find the most common element in the array. Let it be x and let it occur k times in the array. Then let's make a copy where all elements are x. To do that we can make a copy of the given array and put all x in one array. Now we will repeat the algorithm for the new array until we get a copy with n numbers x.

 **Implementation (C++, shishyando)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T --> 0) {
        int n;
        cin >> n;
        map<int, int> q;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++q[x];
        }
        int am = 0;
        for (auto &[x, y] : q) {
            am = max(am, y);
        }
        int ans = 0;
        while (am < n) {
            int d = min(n - am, am);
            ans += 1 + d;
            am += d;
        }
        cout << ans << 'n';
    }
    return 0;
}
```
 **C: Tree Infection**[1665C - Tree Infection](../problems/C._Tree_Infection.md "Codeforces Round 781 (Div. 2)")

 **Editorial**Firstly, we can see that for any two different vertices, their children are independent. It means that infection can not spread from children of one vertex to children of another. Also it does not matter how the infection spreads among the children of some vertex, so we only need to know the amount of vertices with the same parent.

Using this knowledge we can reduce the problem to this one: You are given an array of k positive integers, each integer denotes the amount of healthy vertices with the same parent. Each second you can infect an integer in this array (by injection). Also each second all infected integers decrease by 1 (because of spreading).

Let's now use a greedy algorithm. We will sort this array in the decreasing order and infect all integers one by one. These injections are always needed because the integers are independent. After that each second all numbers decrease by 1 and we can choose one number to be decreased once more in the same second. This should be the max number.

This problem can be solved by simulating the whole process, because the sum of all integers in the beginning is n.

 **Implementation (C++, shishyando)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int ans;

void proc(vector<int>& a) {
    if (a.empty()) return;
    int n = a.size();
    int last = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == a[0]) {
            last = i;
        } else {
            break;
        }
    }
    --a[last];
    for (int i = 0; i < n; ++i) --a[i];
    ++ans;
    while (!a.empty() && a.back() <= 0) {
        a.pop_back();
    }
    proc(a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T --> 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        ans = 0;
        for (int i = 1; i < n; ++i) {
            int x;
            cin >> x;
            ++a[--x];
        }
        a.emplace_back(1);
        sort(a.rbegin(), a.rend());
        while (!a.empty() && a.back() <= 0) a.pop_back();
        n = a.size();
        for (int i = 0; i < n; ++i) {
            a[i] = a[i] - (n - i);
            ++ans;
        }
        sort(a.rbegin(), a.rend());
        while (!a.empty() && a.back() <= 0) a.pop_back();
        proc(a);
        cout << ans << 'n';
    }
    return 0;
}
```
 **D: GCD Guess**[1665D - GCD Guess](../problems/D._GCD_Guess.md "Codeforces Round 781 (Div. 2)")

 **Editorial****Solution 1**

Let's iteratively find the remainder of xmod each power of 2. Initially, we know that xmod20=xmod1=0. If we know that xmod2k=r, then how do we find xmod2k+1? To do that let's ask gcd(x+2k−r,2k+1)=gcd(x+2k−r,x+2k−r+2k+1). If gcd=2k+1, then xmod2k+1=r+2k−1 else xmod2k+1=r. Using this algorithm we will find xmod230 which is just x. It takes exactly 30 queries.

**Solution 2**

Let's consider a set of pairwise coprime numbers 23,19,17,13,11,9,7,5,4. Their lcm>109 that's why xmodlcm=x. Let's find xmod each of these numbers. To do that, for each 1≤i≤23 we can ask gcd(x+i,x+lcm+i) (the query is (i,lcm+i)). If the gcd is a multiple of some number from our set then xmod this number is −i. After that we can use the [chinese remainder theorem](https://codeforces.com/https://en.wikipedia.org/wiki/Chinese_remainder_theorem) to find x that gives the same remainders for numbers from the set. This solution asks only 23 queries.

*Observation 1*: It's enough to make only 22 queries, because if we did not find anything for 1≤i≤22 then we can guarantee that i=23 will do.

*Observation 2*: All moduli are small, that's why it is possible to use a simplified CRT (check the implementation).

 **Implementation (C++, Artyom123)**
```cpp
#include<bits/stdc++.h>

using namespace std;

int ask(int a, int b) {
    cout << '?' << " " << a << " " << a + b << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int r = 0;
    for (int i = 1; i <= 30; i++) {
        int ans = ask((1 << (i - 1)) - r, (1 << i));
        if (ans == (1 << i)) r += (1 << (i - 1));
    }
    cout << '!' << " " << r << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```
 **Implementation with CRT (C++, TheScrasse)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define nl "n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
 
#define INF (ll)1e18
#define mod 998244353
#define maxn 110
#define lc 1338557220
 
ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll x, rs[maxn], p;
vector<ll> pw = {23, 19, 17, 13, 11, 9, 7, 5, 4};
 
ll ask(ll a, ll b) {
    cout << "?" _ a _ b << nf;
    ll x; cin >> x; return x;
}
 
void clm(ll x) {
    cout << "!" _ x << nf;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */
 
    // kudos for automatic wa
 
    cin >> t;
    while (t--) {
        for (i = 1; i <= 23; i++) {
            k = ask(x + i, lc + i);
            for (j = 0; j < 9; j++) {
                if (k % pw[j] == 0) rs[j] = i % pw[j];
            }
        }
 
        k = 1; p = 1;
        for (j = 0; j < 9; j++) {
            // cout << "p =" _ p << nf;
            while (p % pw[j] != rs[j]) p += k;
            k *= pw[j];
        }
 
        clm(lc - p);
    }
 
    return 0;
}
```
 **E: MinimizOR**[1665E - MinimizOR](../problems/E._MinimizOR.md "Codeforces Round 781 (Div. 2)")

 **Editorial**The key idea for the solution is that the answer always lies among no more than 31 minimal numbers. According to this idea, it is possible to build a segment tree for minimum on a segment. After that we only need to find no more than 31 minimums on the segment (each time we find one we change it to ∞) and, finally, we can find all $OR$s pairwise among these 31 numbers.

It is also possible to use the Merge Sort Tree and the same idea.

Now let's prove the key idea: let's prove by induction that if all numbers are less than 2k then it's enough to consider k+1 minimal numbers.

**Base case**: k=1, all numbers are from 0 to 1 and the proof is obvious.

**Inductive step**: 

Let's show that for any k≥1 if for k the statement is true then it's true for k+1.

If all numbers have 1 in k-th bit then the k-th bit of the answer is also 1, that's why we only have to minimize the remaining bits. For these bits we can apply the induction hypothesis that k+1 minimal numbers are enough. If at least two numbers have 0 in their k-th bit then the k-th bit in the answer is also 0. That's why we only consider only numbers with 0 in k-th bit and we have to minimize the remaining bits. Again applying the induction hypothesis, k+1 minimal numbers are enough. If there is exactly one number with 0 in k-th bit then the k-th bit in the answer is 1 and we have to find k+1 minimal numbers over k bits. They are among k+2 minimal numbers over k+1 bits, so k+2 minimal numbers are enough.

 **Implementation (C++, Artyom123)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MAXK = 31;
const int INF = (1 << 30);

vector<pair<int, int>> t;

pair<int, int> get(int v, int vl, int vr, int l, int r) {
    if (vl >= l && vr <= r) return t[v];
    if (r <= vl || l >= vr) return make_pair(INF, INF);
    int vm = (vl + vr) / 2;
    return min(get(2 * v + 1, vl, vm, l, r), get(2 * v + 2, vm, vr, l, r));
}

void mod(int v, int vl, int vr, int id, int val) {
    if (vr - vl == 1) {
        t[v] = make_pair(val, id);
        return;
    }
    int vm = (vl + vr) / 2;
    if (id < vm) mod(2 * v + 1, vl, vm, id, val);
    else mod(2 * v + 2, vm, vr, id, val);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    t.resize(4 * n);
    for (int i = 0; i < n; i++) mod(0, 0, n, i, a[i]);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        vector<pair<int, int>> b;
        for (int i = 0; i < min(r - l, MAXK); i++) {
            auto now = get(0, 0, n, l, r);
            b.push_back(now);
            mod(0, 0, n, now.second, INF);
        }
        int ans = (1LL << 31) - 1;
        for (int i = 0; i < (int)b.size(); i++) {
            for (int j = i + 1; j < (int)b.size(); j++) ans = min(ans, b[i].first | b[j].first);
        }
        for (auto &c : b) mod(0, 0, n, c.second, c.first);
        cout << ans << "n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```
 **Other solutions (?)****MO's algorithm + van Emde Boas tree :) (C++, wery0)**
```cpp
#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
 
#include <bits/stdc++.h>
 
#define F first
#define S second
#define vec vector
#define pb push_back
#define cld complex<ld>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define all(m) m.begin(), m.end()
#define uid uniform_int_distribution
#define fast cin.tie(0); cout.tie(0); cin.sync_with_stdio(0); cout.sync_with_stdio(0);
using namespace std;
using str = string;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> bool chmin(T& a, const T& b) {return b < a ? a = b, 1 : 0;}
template<typename T> bool chmax(T& a, const T& b) {return b > a ? a = b, 1 : 0;}
 
const uint NO = 1<<30;
template<unsigned K>
struct VebTree{
    uint mn, mx;
    VebTree<(K>>1)> *m[1<<((K+1)>>1)];
    VebTree<((K+1)>>1)> *aux;
 
    VebTree(){
        memset(m, 0, sizeof(m));
        aux = 0;
        mn = mx = NO;
    }
 
    inline bool empty() const{
        return mx==NO;
    }
 
    inline uint high(uint x) const{
        return x>>(K>>1);
    }
 
    inline uint low(uint x) const{
        return x&((1<<(K>>1))-1);
    }
 
    inline uint merge(uint x, uint y) const{
        return (x<<(K>>1))+y;
    }
 
    bool find(uint x){
        if(x==mn || x==mx) return 1;
        return m[high(x)] && m[high(x)]->find(low(x));
    }
 
    void insert(uint x){
        if(mx==NO) mn = mx = x;
        else if(mn==mx) mn = min(mn, x), mx = max(mx, x);
        else if(x<mn || x>mx){
            uint add = x<mn ? mn : mx;
            mn = min(mn, x);
            mx = max(mx, x);
            insert(add);
        }
        else if(K>1){
            uint hi = high(x), lo = low(x);
            if(!m[hi]) m[hi] = new VebTree<(K>>1)>();
            if(m[hi]->empty()){
                if(!aux) aux = new VebTree<((K+1)>>1)>();
                aux->insert(hi);
            }
            m[hi]->insert(lo);
        }
    }
 
    void rem(uint x){
        if(mn==mx){
            mn = mx = NO;
            return;
        }
        if(x==mn){
            if(!aux || aux->empty()) {mn=mx; return;}
            else mn = x = merge(aux->mn, m[aux->mn]->mn);
        }
        else if(x==mx){
            if(!aux || aux->empty()) {mx = mn; return;}
            else mx = x = merge(aux->mx, m[aux->mx]->mx);
        }
        uint hi = high(x), lo = low(x);
        m[hi]->rem(lo);
        if(m[hi]->empty()) aux->rem(hi);
    }
 
    uint next(uint x){
        if(empty() || x>=mx) return NO;
        if(x<mn) return mn;
        if(K==1) return mx;
        uint hi = high(x), lo = low(x);
        if(m[hi] && !m[hi]->empty() && m[hi]->mx > lo) return merge(hi, m[hi]->next(lo));
        uint next_hi = aux ? aux->next(hi) : NO;
        return next_hi==NO ? mx : merge(next_hi, m[next_hi]->mn);
    }
 
    uint prev(uint x){
        if(empty() || x<=mn) return NO;
        if(x>mx) return mx;
        if(K==1) return mn;
        uint hi = high(x), lo = low(x);
        if(m[hi] && !m[hi]->empty() && m[hi]->mn < lo) return merge(hi, m[hi]->prev(lo));
        uint prev_hi = aux ? aux->prev(hi) : NO;
        return prev_hi==NO ? mn : merge(prev_hi, m[prev_hi]->mx);
    }
};
 
const int G = 1e5 + 5, SZB = 300;
int a, z;
int m[G], ans[G];
int cng[G], cnt[G];
array<int, 3> que[G];
int cl, cr;
VebTree<32> veb, lox;
 
void add(int ps) {
    int res = ++cnt[cng[ps]];
    if(res==1){
        veb.insert(m[ps]);
    }
    if(res==2){
        lox.insert(m[ps]);
    }
}
 
void rem(int ps) {
    int res = --cnt[cng[ps]];
    if(res==0){
        veb.rem(m[ps]);
    }
    if(res==1){
        lox.rem(m[ps]);
    }
}
 
uint go() {
    uint o = 0;
    uint mn = NO;
    vec<int> del;
    for(int k=29; k>=0; k--){
        uint x = o+(1<<k);
        uint cur = veb.prev(x), sz = 0;
        if(cur!=NO && cur>=o){
            ++sz;
            cur = veb.prev(cur);
            if(cur!=NO && cur>=o){
                ++sz;
            }
        }
        if(sz==0) o += 1<<k;
        else if(sz==1){
            uint c = veb.prev(x)+(1<<k);
            if(veb.find(c)) chmin(mn, c);
            else {
                veb.insert(c);
                del.pb(c);
            }
            o += 1<<k;
        }
    }
    for(uint i : del) veb.rem(i);
    return min({mn, o, lox.mn});
}
 
void compress(){
    vec<int> kek(a);
    for(int q=0; q<a; q++) kek[q] = m[q];
    sort(all(kek));
    kek.erase(unique(all(kek)), kek.end());
    for(int q=0; q<a; q++){
        cng[q] = lower_bound(all(kek), m[q])-kek.begin();
    }
}
 
void solve() {
    cin >> a;
    for (int q = 0; q < a; q++) cin >> m[q];
    cin >> z;
    for (int q = 0; q < z; q++) {
        int l, r; cin >> l >> r; l--; r--;
        que[q] = {l, r, q};
    }
    sort(que, que + z, [](array<int, 3> & p1, array<int, 3> & p2) {
        int l1 = p1[0] / SZB;
        int l2 = p2[0] / SZB;
        if (l1 != l2) return l1 < l2;
        return l1 % 2 == 0 ? p1[1] < p2[1] : p1[1] > p2[1];
    });
    cl = cr = 0;
    compress();
    fill(cnt, cnt+a, 0);
    add(0);
    for (int i = 0; i < z; i++) {
        int ql = que[i][0];
        int qr = que[i][1];
        for (; cr + 1 <= qr; ) add(++cr);
        for (; cl - 1 >= ql; ) add(--cl);
        for (; cr > qr;) rem(cr--);
        for (; cl < ql; ) rem(cl++);
        ans[que[i][2]] = go();
    }
    for(; cl<=cr;) rem(cr--);
    for (int q = 0; q < z; q++) cout << ans[q] << "n";
}
 
int main() {
    fast;
    int z; cin >> z;
    for (; z--;) {
        solve();
    }
}
```
 **DATA STRUCTURES!!! (C++, AlperenT)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const size_t MEMSIZE = 1e9 / 3.8;  // in bytes
 
constexpr size_t MX_ALIGN = alignof(std::max_align_t);
char __attribute__((aligned(MX_ALIGN))) memory[MEMSIZE];
size_t memorypos;
void * operator new(size_t n){
  if (memorypos + n >= MEMSIZE) {
    memorypos = MEMSIZE / 3;
  }
  char *ret = memory + memorypos;
  memorypos = size_t((memorypos+n+MX_ALIGN-1)&-MX_ALIGN);
  return (void*)ret;
}
void operator delete(void *){}
void operator delete(void *, size_t){}

struct Node{
    int l, r, cnt, val;

    Node *lptr = nullptr, *rptr = nullptr;

    Node(int l, int r, int cnt = 0, int val = -1) : l(l), r(r), cnt(cnt), val(val){}

    Node(Node* lptr, Node* rptr) : lptr(lptr), rptr(rptr) {
        l = lptr->l, r = rptr->r;

        cnt = lptr->cnt + rptr->cnt;

        val = max(lptr->val, rptr->val);
    }

    void extend(){
        if(!lptr && l != r){
            int m = l + (r - l) / 2;

            lptr = new Node(l, m);
            rptr = new Node(m + 1, r);
        }
    }

    pair<int, int> merge(pair<int, int> a, pair<int, int> b){
        return {a.first + b.first, max(a.second, b.second)};
    }

    pair<int, int> query(int lq, int rq){
        if(lq > rq) return {0, -1};

        extend();

        if(lq == l && rq == r) return {cnt, val};
        else{
            int m = l + (r - l) / 2;

            pair<int, int> a = lptr->query(lq, min(m, rq)), b = rptr->query(max(m + 1, lq), rq);

            return merge(a, b);
        }
    }
};

Node* update(Node* v, int k, int indx){
    v->extend();

    if(v->l == v->r) return new Node(v->l, v->r, v->cnt + 1, indx);
    else{
        if(k <= v->lptr->r) return new Node(update(v->lptr, k, indx), v->rptr);
        else return new Node(v->lptr, update(v->rptr, k, indx));
    }
}

const int N = 1e5 + 5;

int t, n, q, arr[N], l, r, curnum;

Node* roots[N];

vector<int> vec;

pair<int, int> query(int l, int r, int lnum, int rnum){
    pair<int, int> p;

    p.first = roots[r]->query(lnum, rnum).first - roots[l - 1]->query(lnum, rnum).first;
    p.second = (p.first ? roots[r]->query(lnum, rnum).second : -1);

    for(auto i : vec) if(i >= lnum && i <= rnum) p.first++;
    
    return p;
}

void solve(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> arr[i];

    roots[0] = new Node(0, 1 << 30);

    for(int i = 1; i <= n; i++) roots[i] = update(roots[i - 1], arr[i], i);

    cin >> q;

    while(q--){
        cin >> l >> r;

        curnum = 0;

        vec.clear();

        for(int i = 29; i >= 0; i--){
            pair<int, int> p = query(l, r, curnum, curnum + (1 << i) - 1);

            if(p.first >= 2) continue;
            else if(p.first >= 1 && p.second != -1){
                vec.push_back(arr[p.second] | (1 << i));
                curnum += 1 << i;
            }
            else{
                curnum += 1 << i;
                for(auto &j : vec) j |= (1 << i);
            }
        }

        cout << curnum << "n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
        
    cin >> t;

    while(t--){
        solve();
    }
}
```
 **No data structures... (C++, vsinitsynav)**
```cpp
#include <bits/stdc++.h>
 
#define F first
#define S second
#define all(a) a.begin(), a.end()
 
using namespace std;
using ll = long long;
 
template<class T> bool ckmin(T &a, T b) { return a > b ? a = b, true : false; }
template<class T> bool ckmax(T &a, T b) { return a < b ? a = b, true : false; }
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &x : a) cin >> x;
    vector<unordered_map<int, vector<int>>> cnt(30);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 30; ++j) {
            cnt[29-j][a[i]>>j].push_back(i);
        }
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; l--; r--;
        int x = 0, pref = 0;
        vector<int> tmp;
        for (int j = 0; j < 30; ++j) {
            pref*=2;
            vector<int> newtmp;
            int k = upper_bound(all(cnt[j][pref]), r) - lower_bound(all(cnt[j][pref]), l);
            int k0 = k;
            for (auto y : tmp) {
                if (((y>>(29-j))&1) == 0) k++, newtmp.push_back(y);
            }
            if (k0 == 1) {
                int id = lower_bound(all(cnt[j][pref]), l) - cnt[j][pref].begin();
                tmp.push_back(a[cnt[j][pref][id]]);
            }
            if (k < 2) pref++;
            else tmp.swap(newtmp);
        }
        cout << pref << "n";
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 228/1337;
}
```
 **Who did what?*** Problem A
	+ Idea: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* Problem B
	+ Idea: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* Problem C
	+ Idea: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* Problem D
	+ Idea: [Artyom123](https://codeforces.com/profile/Artyom123 "Grandmaster Artyom123")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* Problem E
	+ Idea: [Kirill22](https://codeforces.com/profile/Kirill22 "International Grandmaster Kirill22")
	+ Polygon: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* English translation: [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")
* Special thanks: [KAN](https://codeforces.com/profile/KAN "Legendary Grandmaster KAN") for coordinating the coordinator and double checking everything
* Another special thanks: [NEAR](https://codeforces.com/https://near.org/) for supporting the Codeforces Community!
* Yet another special thanks: everyone who participated and tested!
