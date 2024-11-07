#include <bits/stdc++.h>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll area(vector<pair<ll, ll>> &vc) {
  ll res = 0;
  for (int i = 0; i < vc.size(); i++) {
    res += vc[i].first * vc[(i + 1) % vc.size()].second -
           vc[i].second * vc[(i + 1) % vc.size()].first;
  }
  return abs(res);
}
void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> vc(n);
  map<pair<ll, ll>, ll> indx;
  for (int i = 0; i < n; i++) {
    cin >> vc[i].first >> vc[i].second;
    indx[vc[i]] = i;
  }
  ll total_A = area(vc);
  ll bg_ind;
  deque<pair<ll, ll>> q;
  ll cur_A = 0, last_A = 0;
  pair<ll, ll> fst, lst;
  for (int i = 0; i < n; i++) {
    if (q.size() > 0) {
      last_A = cur_A;
      fst = q.front();
      cur_A += q.back().first * vc[i].second - q.back().second * vc[i].first;
      cur_A += vc[i].first * fst.second - vc[i].second * fst.first;
      cur_A -= q.back().first * fst.second - q.back().second * fst.first;
    }
    q.push_back(vc[i]);
    if (abs(cur_A) * 3 >= total_A) {
      bg_ind = i;
      break;
    }
  }
  q.pop_back();
  cur_A = last_A;
  map<ll, vector<ll>> mp;
  for (int i = 0; i < n; i++) {
    /* cout << cur_A << " " << total_A << "\n"; */
    ll ind = (i + bg_ind) % n;
    if (q.size() > 0) {
      fst = q.front();
      cur_A +=
          q.back().first * vc[ind].second - q.back().second * vc[ind].first;
      /* cout << q.back().first << " " << q.back().second << " " <<
       * vc[ind].first */
      /*      << " " << vc[ind].second << " " << cur_A << " --1\n"; */
      cur_A += vc[ind].first * fst.second - vc[ind].second * fst.first;
      /* cout << vc[ind].first << " " << vc[ind].second << " " << fst.first << "
       * " */
      /*      << fst.second << " " << cur_A << " --2\n"; */
      cur_A -= q.back().first * fst.second - q.back().second * fst.first;

      /* << q.back().second << " " << cur_A << " --3\n"; */
    }
    q.push_back(vc[ind]);

    /* cout << ind << " --\n"; */
    if (3 * abs(cur_A) < total_A) {
      cur_A -=
          q.back().first * q.front().second - q.back().second * q.front().first;
      cur_A += lst.first * q.front().second - lst.second * q.front().first;
      cur_A += q.back().first * lst.second - q.back().second * lst.first;
      q.push_front(lst);
    }
    /* cout << cur_A << " " << total_A << " " << q.size() << "\n"; */
    while (abs(cur_A) * 3 >= total_A) {
      lst = q.front();
      fst = q.front();
      q.pop_front();
      last_A = cur_A;
      if (q.size() == 0) {
        cur_A = 0;
      } else {
        cur_A -= fst.first * q.front().second - fst.second * q.front().first;
        cur_A -= q.back().first * fst.second - q.back().second * fst.first;
        cur_A += q.back().first * q.front().second -
                 q.back().second * q.front().first;
      }
    }
    mp[ind].push_back(last_A);
    mp[ind].push_back(cur_A);
    /* cout << last_A << " " << cur_A << " " << q.size() << " -*-\n"; */
  }
  // reverse
  /* cout << "-----------\n"; */
  q.clear();
  cur_A = 0, last_A = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (q.size() > 0) {
      last_A = cur_A;
      fst = q.front();
      cur_A -= q.back().first * vc[i].second - q.back().second * vc[i].first;
      cur_A -= vc[i].first * fst.second - vc[i].second * fst.first;
      cur_A += q.back().first * fst.second - q.back().second * fst.first;
    }
    q.push_back(vc[i]);
    if (abs(cur_A) * 3 >= total_A) {
      bg_ind = i;
      break;
    }
  }
  q.pop_back();
  /* cout << cur_A << " " << total_A << "\n"; */
  cur_A = last_A;
  /* cout << bg_ind << " --*\n"; */
  for (int i = n - 1; i >= 0; i--) {
    ll ind = bg_ind % n;
    if (q.size() > 0) {
      fst = q.front();
      cur_A -=
          q.back().first * vc[ind].second - q.back().second * vc[ind].first;
      /* cout << q.back().first << " " << q.back().second << " " <<
       * vc[ind].first */
      /*      << " " << vc[ind].second << " " << cur_A << " --1\n"; */
      cur_A -= vc[ind].first * fst.second - vc[ind].second * fst.first;
      /* cout << vc[ind].first << " " << vc[ind].second << " " << fst.first << "
       * " */
      /*      << fst.second << " " << cur_A << " --2\n"; */
      cur_A += q.back().first * fst.second - q.back().second * fst.first;
      /* cout << fst.first << " " << fst.second << " " << q.back().first << " "
       */
      /*      << q.back().second << " " << cur_A << " --3\n"; */
    }
    q.push_back(vc[ind]);
    /* cout << cur_A << " " << total_A << "\n"; */
    /* cout << ind << " --\n"; */
    if (3 * abs(cur_A) < total_A) {
      cur_A +=
          q.back().first * q.front().second - q.back().second * q.front().first;
      cur_A -= lst.first * q.front().second - lst.second * q.front().first;
      cur_A -= q.back().first * lst.second - q.back().second * lst.first;
      q.push_front(lst);
    }
    /* cout << cur_A << " " << total_A << " " << q.size() << "\n"; */
    while (abs(cur_A) * 3 >= total_A) {
      lst = q.front();
      fst = q.front();
      q.pop_front();
      last_A = cur_A;
      if (q.size() == 0) {
        cur_A = 0;
      } else {
        cur_A += fst.first * q.front().second - fst.second * q.front().first;
        cur_A += q.back().first * fst.second - q.back().second * fst.first;
        cur_A -= q.back().first * q.front().second -
                 q.back().second * q.front().first;
      }
    }
    mp[ind].push_back(last_A);
    mp[ind].push_back(cur_A);
    /* cout << last_A << " " << cur_A << " " << q.size() << " -*-\n"; */
    bg_ind--;
    if (bg_ind < 0)
      bg_ind += n;
  }
  /* for (auto ic : mp) { */
  /*   cout << ic.first << " : \n"; */
  /*   for (auto jc : ic.second) { */
  /*     cout << jc << " "; */
  /*   } */
  /*   cout << "\n"; */
  /* } */
  ll ans = 1e18;
  for (auto ic : mp) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        ll rem = total_A - abs(ic.second[i]) - abs(ic.second[j]);
        ll kkk = abs(3 * abs(ic.second[i]) - total_A) +
                 abs(3 * abs(ic.second[j]) - total_A) +
                 abs(3 * abs(rem) - total_A);
        ans = min(ans, kkk);
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
