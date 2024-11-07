#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
void primes(ll n, vector<ll> &prime_divisors) {
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      prime_divisors.push_back(i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    prime_divisors.push_back(n);
  }
}
void solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  vector<ll> a(n), prime_divisors, prms;
  prime_divisors.push_back(1);
  primes(n, prime_divisors);
  prime_divisors.push_back(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < (int)prime_divisors.size(); i++) {
    ll p = prime_divisors[i];
    /* cout << "p: " << p << "\n"; */
    vector<vector<ll>> pos(p), difs(p);
    for (int j = 0; j < n; j++) {
      ll kp = j % p;
      pos[kp].push_back(a[j]);
    }
    /* cout << "pos: "; */
    /* for (int j = 0; j < p; j++) { */
    /*   for (int k = 0; k < (int)pos[j].size(); k++) { */
    /*     cout << pos[j][k] << ' '; */
    /*   } */
    /*   cout << "\n"; */
    /* } */
    /* cout << "\n"; */
    for (int j = 0; j < p; j++) {
      for (int k = 1; k < (int)pos[j].size(); k++) {
        difs[j].push_back(abs(pos[j][k] - pos[j][k - 1]));
      }
    }
    /* cout << "difs: "; */
    /* for (int j = 0; j < p; j++) { */
    /*   for (int k = 0; k < (int)difs[j].size(); k++) { */
    /*     cout << difs[j][k] << ' '; */
    /*   } */
    /*   cout << "\n"; */
    /* } */
    /* cout << "\n"; */
    vector<ll> g(p, 0);
    for (int j = 0; j < p; j++) {
      for (int k = 0; k < (int)difs[j].size(); k++) {
        g[j] = __gcd(g[j], difs[j][k]);
      }
    }
    /* cout << "g: "; */
    /* for (int j = 0; j < p; j++) { */
    /*   cout << g[j] << ' '; */
    /* } */
    /* cout << "\n"; */
    ll gg = 0;
    for (int j = 0; j < p; j++) {
      gg = __gcd(gg, g[j]);
    }
    /* cout << gg << "---\n"; */
    if (gg > 1 || gg == 0) {
      prms.push_back(p);
    }
  }
  /* cout << "prms: "; */
  /* for (int i = 0; i < (int)prms.size(); i++) { */
  /*   cout << prms[i] << ' '; */
  /* } */
  /* cout << "\n"; */
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      for (int j = 0; j < (int)prms.size(); j++) {
        if (i % prms[j] == 0) {
          ans++;
          break;
        }
      }
      ll kl = n / i;
      if (kl != i) {
        /* if (kl == n) { */
        /*   ans++; */
        /*   continue; */
        /* } */
        for (int j = 0; j < (int)prms.size(); j++) {
          if (kl % prms[j] == 0) {
            ans++;
            break;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
