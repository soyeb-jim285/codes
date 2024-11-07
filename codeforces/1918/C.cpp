#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  ll a, b, r;
  cin >> a >> b >> r;
  if (a < b)
    swap(a, b);
  vector<bool> va(63), vb(63), vr(63);
  ll aa = a, bb = b, rr = r;
  for (int i = 0; i < 63; i++) {
    if (aa & 1)
      va[i] = true;
    if (bb & 1)
      vb[i] = true;
    if (rr & 1)
      vr[i] = true;
    bb >>= 1;
    rr >>= 1;
    aa >>= 1;
  }
  vector<bool> vva(63), vvb(63), vvr(63);
  vva = va;
  vvb = vb;
  vvr = vr;
  bool don = 0, paisi = 0, boroa = 0, borob = 0, pa = 0, pb = 0, ovr = 0;
  for (int i = 63 - 1; i >= 0; i--) {
    if (vr[i])
      paisi = 1;
    if (va[i]) {
      pa = 1;
    }
    if (vb[i]) {
      pb = 1;
    }
    if (va[i] != vb[i] && (boroa || borob) == 0 && paisi == 0) {
      if (va[i])
        boroa = 1;
      else
        borob = 1;
    }
    if (paisi) {
      bool ba = (va[i] == vb[i]);
      if (ba) {
        if (vr[i]) {
          ovr = 1;
          vvr[i] = 0;
        }
      } else {
        if (boroa) {
          if (va[i]) {
            if (vr[i] || ovr) {
              va[i] = 0;
              vb[i] = 1;
              vvr[i] = 1;
            }
          } else {
            if (vr[i]) {
              ovr = 1;
              vvr[i] = 0;
            }
          }
        } else if (borob) {
          if (vb[i]) {
            if (vr[i] || ovr) {
              vb[i] = 0;
              va[i] = 1;
              vvr[i] = 1;
            }
          } else {
            if (vr[i]) {
              ovr = 1;
              vvr[i] = 0;
            }
          }
        } else {
          if (vr[i] || ovr) {
            va[i] = 0;
            vb[i] = 1;
            vvr[i] = 1;
            borob = 1;
          }
        }
      }
    }
  }
  don = 0, ovr = 0, paisi = 0, boroa = 0, borob = 0, pa = 0, pb = 0;
  for (int i = 63 - 1; i >= 0; i--) {
    if (vr[i])
      paisi = 1;
    if (vva[i]) {
      pa = 1;
    }
    if (vvb[i]) {
      pb = 1;
    }
    if (vva[i] != vvb[i] && (boroa || borob) == 0 && paisi == 0) {
      if (vva[i])
        boroa = 1;
      else
        borob = 1;
    }
    if (paisi) {
      bool ba = (vva[i] == vvb[i]);
      if (ba) {
        if (vr[i]) {
          ovr = 1;
          vvr[i] = 0;
        }
      } else {
        if (boroa) {
          if (vva[i]) {
            if (vr[i] || ovr) {
              vva[i] = 0;
              vvb[i] = 1;
              vvr[i] = 1;
            }
          } else {
            if (vr[i]) {
              ovr = 1;
              vvr[i] = 0;
            }
          }
        } else if (borob) {
          if (vvb[i]) {
            if (vr[i] || ovr) {
              vvb[i] = 0;
              vva[i] = 1;
              vvr[i] = 1;
            }
          } else {
            if (vr[i]) {
              ovr = 1;
              vvr[i] = 0;
            }
          }
        } else {
          vva[i] = 1;
          vvb[i] = 0;
          boroa = 1;
          if (vr[i]) {
            ovr = 1;
          }
        }
      }
    }
  }
  a = 0, b = 0, rr = 0;
  for (int i = 0; i < 63; i++) {
    if (va[i])
      a += (1LL << i);
    if (vb[i])
      b += (1LL << i);
    if (vva[i])
      aa += (1LL << i);
    if (vvb[i])
      bb += (1LL << i);
    if (vvr[i])
      rr += (1LL << i);
  }
  /* cout << a << " " << b << " " << rr << "\n"; */
  cout << min(abs(a - b), abs(aa - bb)) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
