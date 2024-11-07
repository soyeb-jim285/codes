#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<string> vc;
vector<ll> reg(7, 0);
ll getnum(string &s, int &i) {
  ll res = 0;
  bool neg = false;
  if (s[i] == '-') {
    neg = true;
    i++;
  }
  if (s[i] == '+') {
    i++;
  }
  while (i < s.size() && s[i] != ' ') {
    res = res * 10 + s[i] - '0';
    i++;
  }
  if (neg)
    res = -res;
  return res;
}
int regist(char x) {
  if (x == 'P')
    x = 'G';
  return x - 'A';
}
void LOD() {
  int r = regist(vc[reg[6]][4]);
  int i = 6;
  int val = getnum(vc[reg[6]], i);
  reg[r] = val;
  reg[6]++;
}
void INC() {
  int r = regist(vc[reg[6]][4]);
  reg[r]++;
  reg[6]++;
}
void ADD() {
  int r1 = regist(vc[reg[6]][4]);
  int r2 = regist(vc[reg[6]][6]);
  reg[r1] += reg[r2];
  reg[6]++;
}
void MUL() {
  int r1 = regist(vc[reg[6]][4]);
  int r2 = regist(vc[reg[6]][6]);
  reg[r1] *= reg[r2];
  reg[6]++;
}
void JMP() {
  int i = 4;
  int val = getnum(vc[reg[6]], i);
  reg[6] = val;
}
void CMP() {
  int r1 = regist(vc[reg[6]][4]);
  int r2 = regist(vc[reg[6]][6]);
  if (reg[r1] == reg[r2]) {
    reg[2] = 0;
  } else if (reg[r1] > reg[r2]) {
    reg[2] = 1;
  } else {
    reg[2] = -1;
  }
  reg[6]++;
}
void JCZ() {
  int i = 4;
  int val = getnum(vc[reg[6]], i);
  if (reg[2] == 0) {
    reg[6] = val;
  } else {
    reg[6]++;
  }
}
void JCP() {
  int i = 4;
  int val = getnum(vc[reg[6]], i);
  if (reg[2] > 0) {
    reg[6] = val;
  } else {
    reg[6]++;
  }
}
void JCN() {
  int i = 4;
  int val = getnum(vc[reg[6]], i);
  if (reg[2] < 0) {
    reg[6] = val;
  } else {
    reg[6]++;
  }
}
void solve() {
  string s;
  while (getline(cin, s)) {
    if (s == "")
      break;
    vc.push_back(s);
  }
  string cmd = vc[reg[6]].substr(0, 3);
  while (cmd != "HLT") {
    if (cmd == "LOD") {
      LOD();
    } else if (cmd == "INC") {
      INC();
    } else if (cmd == "ADD") {
      ADD();
    } else if (cmd == "MUL") {
      MUL();
    } else if (cmd == "JMP") {
      JMP();
    } else if (cmd == "CMP") {
      CMP();
    } else if (cmd == "JCZ") {
      JCZ();
    } else if (cmd == "JCN") {
      JCN();
    } else {
      JCP();
    }
    cmd = vc[reg[6]].substr(0, 3);
  }
  for (auto ic : reg)
    cout << ic << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
/*
LOD A 5
LOD B 10
LOD C 15
LOD D 20
LOD E 25
LOD F 30
CMP A B
JCN 10
LOD A 40
JMP 12
LOD A 50
HLT

*/
