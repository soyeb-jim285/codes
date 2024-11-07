# Tutorial_2_(ru)

[1263A - Sweet Problem](../problems/A._Sweet_Problem.md "Codeforces Round 603 (Div. 2)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1263A - Сладкая задача](../problems/A._Sweet_Problem.md "Codeforces Round 603 (Div. 2)")

Отсортируем значения $r$, $g$, $b$ так, чтобы $r \geq g \geq b$. Может возникнуть два случая. 

Если $r \geq g+b$, тогда Таня сможет брать $g$ конфет из кучек $r$ и $g$, а затем — $b$ конфет из кучек $r$ и $b$. После этого, возможно, в кучке $r$ останется некоторое количество конфет, которые Таня никак не сможет съесть, поэтому ответ $g + b$.

Иначе, добьёмся равенства количества конфет $r$, $g$, $b$. Сначала сравняем $r$ и $g$, съев $r - g$ конфет в кучках $r$ и $b$ (это всегда можно сделать, так как $r < g + b$). Затем сравняем $g$, $b$, съев $g - b$ конфет в кучках $r$ и $g$. После этого $r = g = b$, и у нас могут получиться три разных случая.

* $r = g = b = 0$ — ничего делать не нужно, Таня уже съела все конфеты;
* $r = g = b = 1$ — можно взять по конфете из любых двух кучек, ведь в итоге всегда останется одна конфета в какой-либо из кучек;
* $r = g = b \geq 2$ — уменьшим все кучки на 2, взяв, к примеру, по конфете из кучек $r$ и $g$, $g$ и $b$, $r$ и $b$. Такими действиями Таня рано или поздно дойдёт до двух предыдущих случаев, так как размеры кучек уменьшаются на 2.

Так как при этой стратегии у нас всегда остаётся 0 или 1 конфета, то получаем, что Таня сможет есть конфеты $\lfloor \frac{r+g+b}{2} \rfloor$ дней.

 **Solution (MikeMirzayanov)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {   
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[2] <= a[0] + a[1])
            cout << (a[0] + a[1] + a[2]) / 2 << endl;
        else
            cout << a[0] + a[1] << endl;
    }
}
```
[1263B - PIN Codes](../problems/B._PIN_Codes.md "Codeforces Round 603 (Div. 2)")

Idea: [Stepavly](https://codeforces.com/profile/Stepavly "Candidate Master Stepavly")

 **Tutorial**
### [1263B - ПИН-коды](../problems/B._PIN_Codes.md "Codeforces Round 603 (Div. 2)")

Сгруппируем все числа в группы из одинаковых элементов. Заметим, что размер каждой такой группы не превышает $10$. Поэтому в каждом числе нам нужно изменить не больше $1$ цифры, а именно, если группа состоит из 1 элемента, то мы ничего не делаем, иначе мы берём все числа, кроме одного из этой группы и изменяем в них ровно одну цифру так, чтобы новое число было уникальным. Нужно также не забывать добиваться того, чтобы в разных группах ПИН-коды также различались, и постоянно это поддерживать (на данных ограничениях это возможно всегда).

 **Solution (Stepavly)**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<char> calced(n);
	vector<string> a(n);
	set<string> have;
	int res = 0;

	for (string &pin : a) {
		cin >> pin;
		have.insert(pin);
	}

	for (int i = 0; i < n; i++) {
		if (calced[i]) {
			continue;
		}

		vector<int> sameIds;

		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				sameIds.push_back(j);
				calced[j] = 1;
				res++;

				for (int k = 0; k < 4 && a[i] == a[j]; k++) {
					for (char c = '0'; c <= '9'; c++) {
						string t = a[j];
						t[k] = c;

						if (!have.count(t)) {
							have.insert(t);
							a[j] = t;
							break;
						}
					}
				}
			}
		}
	}

	cout << res << "n";

	for (string& s : a) {
		cout << s << "n";
	}
}

int main() {
	int test;
	cin >> test;

	while (test--) {
		solve();
	}
}
```
[1263C - Everyone is a Winner!](../problems/C._Everyone_is_a_Winner!.md "Codeforces Round 603 (Div. 2)")

Idea: [unreal.eugene](https://codeforces.com/profile/unreal.eugene "Candidate Master unreal.eugene")

 **Tutorial**
### [1263C - Вы все уже победители!](../problems/C._Everyone_is_a_Winner!.md "Codeforces Round 603 (Div. 2)")

Для этой задачи существует два подхода к её решению.

Математическое решение

Заметим, что в ответе всегда будут присутствовать числа $0 \le x < \lfloor \sqrt{n} \rfloor$. В этом можно убедиться, решив уравнение $\lfloor \frac{n}{k} \rfloor = x$, эквивалентное неравенству $x \le \frac{n}{k} < x + 1$, для целых значений $k$. Решением двойного неравенства является промежуток $k \in \left( \frac{n}{x+1};\; \frac{n}{x} \right]$, длина которого равна $\frac{n}{x^2+x}$. При $x < \lfloor \sqrt{n} \rfloor$ $\frac{n}{x^2+x} > 1$, а на промежутке длины большей, чем 1, всегда найдётся целое решение $k = \lfloor \frac{n}{x} \rfloor$ $\implies$ все целые числа $0 \le x < \lfloor \sqrt{n} \rfloor$ принадлежат ответу.

Теперь заметим, что нам больше не требуется перебирать значения $k > \lfloor \sqrt{n} \rfloor$, ведь этим числам всегда соответствуют значения $0 \le x < \lfloor \sqrt{n} \rfloor$. Таким образом, можно, как в наивном решении, перебрать все значения $k$ до $\lfloor \sqrt{n} \rfloor$ и добавить $x = \lfloor \frac{n}{k} \rfloor$ к ответу. Остаётся только аккуратно обработать случай $k = \lfloor \sqrt{n} \rfloor$.

Асимптотика решения: $\mathcal{O} (\sqrt{n} \log n)$ или $\mathcal{O}(\sqrt{n})$

Алгоритмическое решение

В задаче можно было предположить, что чисел в ответе не так уж и много (ведь их же всех ещё нужно вывести, на что тратится основное время выполнения программы). Очевидно, что $n$ всегда принадлежит ответу. Заметим также, что при увеличении $k$ значение $x = \lfloor \frac{n}{k} \rfloor$ уменьшается. Таким образом, можно с помощью бинарного поиска находить такое наименьшее значение $k'$, что $\frac{n}{k'} < x$. $x' = \frac{n}{k'}$ и будет являться предыдущим для $x$ в ответе на эту задачу.

Асимптотика решения: $\mathcal{O}(\sqrt{n} \log n)$

 **Solution (unreal.eugene)**
```cpp
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mkp make_pair
#define pb push_back
#define sqr(s) ((s) * (s))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

#ifdef EUGENE
	mt19937 rng(1337);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

void solve() {
	int n;
	cin >> n;
	vector<int> ans;
	int s = (int)sqrtl(n);
	for (int i = 0; i <= s; i++)
		ans.pb(i);
	for (int i = 1; i <= s; i++)
		ans.pb(n / i);
	sort(ALL(ans));
	ans.resize(unique(ALL(ans)) - ans.begin());
	cout << sz(ans) << endl;
	for (int &x : ans)
		cout << x << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	#ifdef EUGENE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "r", stdout);
	#endif

	int t;
	cin >> t;
	while (t--)
		solve();
}
```
[1263D - Secret Passwords](../problems/D._Secret_Passwords.md "Codeforces Round 603 (Div. 2)")

Idea: [Stepavly](https://codeforces.com/profile/Stepavly "Candidate Master Stepavly")

 **Tutorial**
### [1263D - Секретные пароли](../problems/D._Secret_Passwords.md "Codeforces Round 603 (Div. 2)")

Эта задача решается множеством способов (СНМ, двудольный граф, std::set и прочее). Здесь будет описано решение с помощью двудольного графа.

Рассмотрим двудольный граф, в левой доле которого находятся $26$ вершин, соответствующие каждой букве латинского алфавита, а правой доле — $n$ вершин, соответствующие паролям. Соединим ребром пароли и буквы, которые входят в этот пароль хотя бы один раз. Тогда из определения эквивалентности паролей нетрудно понять, что ответ на задачу — это количество компонент связности в данном двудольном графе.

Асимптотика решения: $\mathcal{O}(n)$.

 **Solution (Stepavly)**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 100;

vector<int> g[N];
char used[N];

void addEdge(int v, int u) {
	g[v].push_back(u);
	g[u].push_back(v);
}

void dfs(int v) {
	used[v] = 1;

	for (int to : g[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (char c : s) {
			addEdge(i, n + c - 'a');
		}
	}

	int res = 0;

	for (int i = n; i < n + 26; i++) {
		if (!g[i].empty() && !used[i]) {
			dfs(i);
			res++;
		}
	}

	cout << res;

	return 0;
}
```
[1263E - Editor](../problems/E._Editor.md "Codeforces Round 603 (Div. 2)")

Idea: [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz")

 **Tutorial**
### [1263E - Редактор](../problems/E._Editor.md "Codeforces Round 603 (Div. 2)")

Чтобы отвечать на запросы, можно поддерживать два стека. В первом стеке будут находиться все скобки на позициях не больше, чем позиция курсора, а во втором все оставшиеся.

Также для каждой закрывающей скобки в первом стеке будем поддерживать максимальную глубину правильной скобочной последовательности (ПСП) заканчивающейся этой скобкой. Аналогично во втором стеке будем поддерживать максимальную глубину ПСП начинающейся в этой скобке. Так как скобки добавляются в стек в конец и по одной, то можно легко пересчитывать эту величину.

Еще в левом стеке нужно поддерживать количество открывающих скобок, не имеющих парной закрывающей скобки, а в правом количество закрывающих скобок, не имеющих парной открывающей скобки.

Если прошлые две величины равны, значит текущая строка является ПСП. Иначе найдется либо одна не закрытая скобка, либо одна скобка не имеющая открывающей.

Ответом на задачу, после каждого запроса, будет максимум из трех величин - максимальная глубина в левом стеке, максимальная глубина в правом стеке и количество незакрытых скобок (количество неоткрытых скобок в правом стеке учитывать не нужно, так как если строка является ПСП, то оно равно количеству незакрытых скобок в левом).

Асимптотика этого решения $\mathcal{O}(n)$.

 **Solution (Supermagzzz)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

struct MyStack {
    int cnt = 0;
    int allOpens = 0;
    stack<int> s;
    stack<int> minValue;
    stack<int> maxValue;

    void push(int x) {
        s.push(x);
        cnt += x;
        if (x == 1) {
            allOpens += 1;
        }
        minValue.push((minValue.size() ? min(minValue.top(), cnt) : cnt));
        maxValue.push((maxValue.size() ? max(maxValue.top(), cnt) : cnt));
    }

    void pop() {
        if (s.size() == 0) {
            return;
        }
        cnt -= s.top();
        if (s.top() == 1) {
            allOpens -= 1;
        }
        s.pop();
        minValue.pop();
        maxValue.pop();
    }

    int top() {
        return s.top();
    }

    bool isCorrect() {
        return (minValue.size() == 0 || minValue.top() >= 0);
    }

    int depth() {
        return (maxValue.size() ? maxValue.top() : 0);
    }
};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    MyStack left, right;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        right.push(0);
    }
    left.push(0);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            if (pos != 0) {
                pos--;
                right.push(-left.top());
                left.pop();
            }
        } else if (s[i] == 'R') {
            pos++;
            left.push(-right.top());
            right.pop();
        } else if (s[i] == '(') {
            left.pop();
            left.push(1);
        } else if (s[i] == ')') {
            left.pop();
            left.push(-1);
        } else {
            left.pop();
            left.push(0);
        }
        if (left.isCorrect() && right.isCorrect() && left.cnt == right.cnt) {
            cout << max({left.depth(), right.depth(), left.cnt}) << " ";
        } else {
            cout << "-1 ";
        }
    }
}           	
```
[1263F - Economic Difficulties](../problems/F._Economic_Difficulties.md "Codeforces Round 603 (Div. 2)")

Idea: [AdvancerMan](https://codeforces.com/profile/AdvancerMan "Candidate Master AdvancerMan")

 **Tutorial**
### [1263F - Экономические проблемы](../problems/F._Economic_Difficulties.md "Codeforces Round 603 (Div. 2)")

Для удобства будем считать, что листья деревьев пронумерованы так же как пронумерованы приборы, к которым присоединены данные листья.

Посчитаем $cost_{l, r}$ ($l \le r$) для каждого дерева (назовем их $upperCost_{l, r}$ и $lowerCost_{l, r}$) — максимальное количество ребер, которые могут быть удалены так, чтобы на отрезке $[l, r]$ существовал путь от каждого листа до корня противоположного дерева. Посчитаем $cost_{l, r}$ для какого-то фиксированного $l$. Назовем «бамбуком» листа $v$ связное множество предков вершины $v$ такое, что у каждой вершины не больше $1$-го ребенка, причем сама вершина $v$ находится в этом множестве. Очевидно, $cost_{l, l}$ — максимальная длина «бамбука» $l$.

Пусть мы уже посчитали $cost_{l, r - 1}$. Посчитаем $cost_{l, r}$. Очевидно, что мы можем удалить все ребра, посчитанные в $cost_{l, r - 1}$. Также можем удалить получившийся «бамбук» листа $r$ (так как нам не нужно иметь пути из листьев $[l, r]$ до корня в дереве, для которого считаем $cost$). Покажем, что больше ребер удалить не можем. Так как для каждой сети существует такой порядок обхода в глубину из вершины $1$, что листы появляются в данном обходе в порядке нумерации соответствующих приборов, то для каждой вершины $v$ множество индексов листьев в ее поддереве представляет собой отрезок. Если в отрезке для вершины $v$ есть $r$, то $r$-й лист находится в поддереве вершины $v$.

Рассмотрим вершины, в поддереве которых нет листа $r$. Если в их поддереве есть вершины не из отрезка $[l, r]$, то мы не можем ребро до родителя этой вершины, так как мы потеряем путь до корня для вершины не из отрезка $[l, r]$ (мы считаем ответ только для отрезка $[l, r]$). Тогда остались вершины, в поддереве которых листья только из отрезка $[l, r]$. Если в поддереве только листья из отрезка $[l, r - 1]$, то мы все такие вершины обработали в $cost_{l, r - 1}$. Тогда отрезок для оставшихся вершин имеет вид $[i, r], l \le i$. Тогда мы можем удалить ребро из каждой такой вершины до ее родителя. А множество таких вершин будет «бамбуком» из листа $r$, потому что все «бамбуки» на отрезке $[l, r - 1]$ мы уже удалили.

Получили, что для подсчета $cost_{l, r}$ достаточно знать $cost_{l, r - 1}$ и максимальную длину «бамбука» $r$, что можно посчитать за $\mathcal{O}(n(a + b))$.

Посчитаем $dp_i$ — ответ для $i$-го префикса. Рассмотрим ответ: какой-то суффикс листьев имеет путь до корня только в одном дереве, а остальной префикс имеет максимальный ответ (если нет, то возьмем максимальный ответ для префикса, чем улучшим общий ответ). Тогда получим формулу $dp_i = \max\limits_{0 \le j < i}(dp_{j} + \max(upperCost_{j, i-1}, lowerCost_{j, i-1}))$ (и $dp_0 = 0$), которую можно посчитать за время $\mathcal{O}(n^2)$. Тогда ответ хранится в $dp_n$.

Challenge: Можете ли вы решить данную задачу за линейную временную сложность (например, $\mathcal{O}(n + a + b)$)?

 **Solution (Rox)**
```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

#ifdef LOCAL
    #define eprint(x) cerr << #x << " = " << (x) << endl
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprint(x)
    #define eprintf(...)
#endif

vector<vector<int>> precalc(int n, vector<int> p, vector<int> id) {
    vector<vector<int>> res(n, vector<int>(n));

    for (int l = 0; l < n; l++) {
        vector<int> deg(sz(p));
        for (int i = 1; i < sz(p); i++)
            deg[p[i]]++;

        int val = 0;
        for (int r = l; r < n; r++) {
            int v = id[r];
            while (v != 0 && deg[v] == 0) {
                deg[p[v]]--;
                v = p[v];
                val++;
            }
            res[l][r] = val;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> p(2);
    vector<vector<int>> id(2);
    for (int i = 0; i < 2; i++) {
        int vn;
        cin >> vn;
        p[i].resize(vn);
        for (int v = 1; v < vn; v++) {
            cin >> p[i][v];
            p[i][v]--;
        }
        id[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> id[i][j];
            id[i][j]--;
        }
    }

    vector<vector<vector<int>>> cost(2);
    for (int i = 0; i < 2; i++)
        cost[i] = precalc(n, p[i], id[i]);

    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dp[j] = max(dp[j], dp[i] + max(
                cost[0][i][j - 1],
                cost[1][i][j - 1]
            ));
        }
    }

    cout << dp[n] << endl;
}
```
