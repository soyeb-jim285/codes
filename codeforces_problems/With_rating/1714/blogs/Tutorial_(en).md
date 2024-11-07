# Tutorial_(en)

[1714A - Everyone Loves to Sleep](../problems/A._Everyone_Loves_to_Sleep.md "Codeforces Round 811 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1714A - Everyone Loves to Sleep](../problems/A._Everyone_Loves_to_Sleep.md "Codeforces Round 811 (Div. 3)")

To begin with, let's learn how to determine how much time must pass before the ii alarm to trigger. If the alarm time is later than the current one, then obviously 60∗(hi−H)+mi−M60∗(hi−H)+mi−M minutes should pass. Otherwise, this value will be negative and then it should pass 24∗60+60∗(hi−H)+mi−M24∗60+60∗(hi−H)+mi−M since a full day must pass, not including the time from the alarm to the current time. We just need to find the minimum number of minutes among all the alarm clocks.

Due to small constrains, the problem can also be solved by stimulating the sleep process: increase the answer by 11 and check whether any alarm will work after this time.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(143);

const int inf = 1e15;
const int M = 1e9 + 7;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;

void solve(){
    int n;
    cin >> n;
    int time, h, m;
    cin >> h >> m;
    time = 60 * h + m;
    int ans = 24 * 60;
    for(int i = 0; i < n; ++i){
        cin >> h >> m;
        int t = 60 * h + m - time;
        if(t < 0) t += 24 * 60;
        ans = min(ans, t);
    }
    cout << ans / 60 << " " << ans % 60;
}

bool multi = true;

signed main() {
    int t = 1;
    if (multi)cin >> t;
    for (; t; --t) {
        solve();
        cout << endl;
    }
    return 0;
}
```
[1714B - Remove Prefix](../problems/B._Remove_Prefix.md "Codeforces Round 811 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1714B - Remove Prefix](../problems/B._Remove_Prefix.md "Codeforces Round 811 (Div. 3)")

Let's turn the problem around: we'll look for the longest suffix that will make Polycarp happy, since it's the same thing.

Let's create an array cnt, in which we will mark the numbers already encountered. Let's go along a from right to left and check if ai does not occur to the right (in this case it is marked in cnt), if it occurs to the right, then removing any prefix that does not include i, we get an array where ai occurs twice, so we have to delete prefix of length i.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
        bool yes = false;
        set<int> c;
        for (int i = n - 1; i >= 0; i--) {
            if (c.count(a[i])) {
                cout << i + 1 << endl;
                yes = true;
                break;
            }
            c.insert(a[i]);
        }
        if (!yes)
            cout << 0 << endl;
    }
}
```
[1714C - Minimum Varied Number](../problems/C._Minimum_Varied_Number.md "Codeforces Round 811 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**Tutorial is loading... **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int s;
        cin >> s;
        string result;
        for (int d = 9; d >= 1; d--)
            if (s >= d) {
                result = char('0' + d) + result;
                s -= d;
            }
        cout << result << endl;
    }
}
```
[1714D - Color with Occurrences](../problems/D._Color_with_Occurrences.md "Codeforces Round 811 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1714D - Color with Occurrences](../problems/D._Color_with_Occurrences.md "Codeforces Round 811 (Div. 3)")

The first step is to find the word that covers the maximum length prefix. If there is no such word, we cannot color the string.

Then go through the positions inside the found prefix and find the next word, which is a tweak of t, has the maximal length, and ends not earlier than the previous found word, and not later than the text t. If there is no such word, it is impossible to color t.

After the second word is found, similarly continue looking for the next ones.

 **Solution**
```cpp
#include<bits/stdc++.h>
#define len(s) (int)s.size()
#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;
int ans = 0;
bool ok = true;

void Find(int a, int b, string &t, vector<string>&str, vector<pair<int, int>>&match){
    int Max = 0, id = -1, pos = -1;
    for(int i = a; i <= b; i++){
        for(int j = 0; j < len(str); j++){
            string s = str[j];
            if(i + len(s) > len(t) || i + len(s) <= b) continue;
            if(t.substr(i, len(s)) == s) {
                if(i + len(s) > Max){
                    Max = i + len(s);
                    id = j;
                    pos = i;
                }
            }
        }
    }
    if(id == -1) {
        ok = false;
        return;
    }
    else{
        match.emplace_back(id, pos);
        ans++;
        if(Max == len(t)) return;
        else Find(max(pos + 1, b +1), Max, t, str, match);
    }
}


void solve(){
    ans = 0;
    ok = true;

    string t;
    cin >> t;
    int n;
    cin >> n;

    vector<string>s(n);
    vector<pair<int, int>>match;

    forn(i, n) {
        cin >> s[i];
    }

    Find(0, 0, t, s, match);
    if(!ok) cout << "-1n";
    else{
        cout << ans << endl;
        for(auto &p : match) cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }

}

int main(){
    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
```
[1714E - Add Modulo 10](../problems/E._Add_Modulo_10.md "Codeforces Round 811 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1714E - Add Modulo 10](../problems/E._Add_Modulo_10.md "Codeforces Round 811 (Div. 3)")

Let's see which remainders modulo 10 change into which ones.

If the array contains a number divisible by 10, then it cannot be changed. If there is a number that has a remainder of 5 modulo 10, then it can only be replaced once.

Thus, if the array contains a number divisible by 5, then we apply this operation to all elements of the array once and check that all its elements are equal.

The remaining odd balances (1,3,7,9) immediately turn into even ones. The even remainders (2,4,6,8) change in a cycle, while the array element increases by 20 in 4 operations. Thus, we will apply the operation to each element of the array until its remainder modulo 10 becomes, for example, 2, and then check that the array does not contain both remainders 2 and 12 modulo 20.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int next(int x) {
    return x + x % 10;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 5 == 0) {
            flag = true;
            a[i] = next(a[i]);
        }
    }
    if (flag) {
        cout << (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end()) ? "Yes": "No") << 'n';
    } else {
        bool flag2 = false, flag12 = false;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            while (x % 10 != 2) {
                x = next(x);
            }
            if (x % 20 == 2) {
                flag2 = true;
            } else {
                flag12 = true;
            }
        }
        cout << ((flag2 & flag12) ? "No" : "Yes") << 'n';
    }
}

int main() {
    int t = 1;
    cin >> t;
    for (int it = 0; it < t; ++it) {
        solve();
    }
    return 0;
}
```
[1714F - Build a Tree and That Is It](../problems/F._Build_a_Tree_and_That_Is_It.md "Codeforces Round 811 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1714F - Build a Tree and That Is It](../problems/F._Build_a_Tree_and_That_Is_It.md "Codeforces Round 811 (Div. 3)")

If the answer exists, you can hang the tree by some vertex such that the distances d12,d23 and d31 can be expressed through the sums of distances to vertices 1,2 and 3. Then from the system of equations we express the required values of distances to vertices 1,2,3 and construct a suitable tree. If the distance to a vertex is 0, then that vertex is the root. There cannot be two roots, nor can there be negative distances.

If none of the vertices of 1,2,3 is the root, then make vertex 4 the root. 

Next we build the required tree: add the required number of unique vertices on the path from the root to vertices 1,2,3. Note also that if the sum of distances is greater than or equal to n, then we cannot build the tree either.

The remaining vertices can be simply joined to the root.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> d(3);
        forn(i, 3)
            cin >> d[i];
        int sum = d[0] + d[1] + d[2];
        if (sum % 2 == 0) {
            vector<int> w(3);
            forn(i, 3)
                w[i] = sum / 2 - d[(i + 1) % 3];
            vector<int> sw(w.begin(), w.end());
            sort(sw.begin(), sw.end());
            if (sw[0] >= 0 && sw[1] >= 1) {
                vector<pair<int,int>> edges;
                int num = 3;
                int center;
                if (sw[0] == 0)
                    center = min_element(w.begin(), w.end()) - w.begin();
                else
                    center = num++;
                forn(i, 3) {
                    int before = center;
                    forn(j, w[i] - 1) {
                        edges.push_back({before, num});
                        before = num++;
                    }
                    if (w[i] > 0)
                        edges.push_back({before, i});
                }
                if (num <= n) {
                    while (num < n)
                        edges.push_back({center, num++});
                    cout << "YES" << endl;
                    for (auto& [u, v]: edges)
                        cout << u + 1 << " " << v + 1 << endl;
                    continue;
                }
            }
        }
        cout << "NO" << endl;
    }
}
```
[1714G - Path Prefixes](../problems/G._Path_Prefixes.md "Codeforces Round 811 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1714G - Path Prefixes](../problems/G._Path_Prefixes.md "Codeforces Round 811 (Div. 3)")

Note that all bj are positive, which means that the amount on the prefix only increases. This allows us to use binary search to find the answer for the vertex. It remains only to learn how to quickly find the sum of bj on the path prefix. Let's run a depth-first search and store the prefix sums of the current path in stack: going to the vertex, add the sum to the end of the path and delete it when exiting.

 **Solution**
```cpp
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn=2e5+5;
vector<int> ch[maxn];
int a[maxn];
int b[maxn];
int ans[maxn];
vector<int> vb;
int curb=0;
int cura=0;

void dfs(int x){
    curb+=b[x];
    cura+=a[x];
    vb.push_back(curb);
    ans[x]=upper_bound(vb.begin(),vb.end(),cura)-vb.begin();
    for(int v:ch[x]){
        dfs(v);
    }
    curb-=b[x];
    cura-=a[x];
    vb.pop_back();
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;++i) ch[i].clear();
        for(int i=1;i<n;++i){
            int pr,a1,b1;
            cin>>pr>>a1>>b1;
            --pr;
            ch[pr].push_back(i);
            a[i]=a1;
            b[i]=b1;
        }
        dfs(0);
        for(int i=1;i<n;++i) cout<<ans[i]-1<<' ';
        cout<<'n';
    }
    return 0;
}
```
