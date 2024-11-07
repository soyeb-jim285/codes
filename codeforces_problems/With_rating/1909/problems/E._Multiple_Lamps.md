<h1 style='text-align: center;'> E. Multiple Lamps</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Kid2Will - Fire Aura](https://soundcloud.com/xgp/kid2will-fire-aura)⠀You have $n$ lamps, numbered from $1$ to $n$. Initially, all the lamps are turned off.

You also have $n$ buttons. The $i$-th button toggles all the lamps whose index is a multiple of $i$. When a lamp is toggled, if it was off it turns on, and if it was on it turns off.

You have to press some buttons according to the following rules.

* You have to press at least one button.
* You cannot press the same button multiple times.
* You are given $m$ pairs $(u_i, v_i)$. If you press the button $u_i$, you also have to press the button $v_i$ (at any moment, not necessarily after pressing the button $u_i$). 
## Note

 that, if you press the button $v_i$, you don't need to press the button $u_i$.

You don't want to waste too much electricity. Find a way to press buttons such that at the end at most $\lfloor n/5 \rfloor$ lamps are on, or print $-1$ if it is impossible.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \leq n \leq 2 \cdot 10^5$, $0 \leq m \leq 2 \cdot 10^5$) — the number of lamps and the number of pairs, respectively.

Each of the next $m$ lines contains two integers $u_i$, $v_i$ ($1 \leq u_i, v_i \leq n$, $u_i \neq v_i$). If you press the button $u_i$, you also have to press the button $v_i$. It is guaranteed that the pairs $(u_i, v_i)$ are distinct.

It is guaranteed that the sum of $n$ and the sum of $m$ over all test cases do not exceed $2 \cdot 10^5$.

### Output

For each test case: 

* If there is no choice of buttons that makes at most $\lfloor n/5 \rfloor$ lamps on at the end, output a single line containing $-1$.
* Otherwise, output two lines. The first line should contain an integer $k$ ($1 \le k \le n$) — the number of pressed buttons. The second line should contain $k$ integers $b_1, b_2, \dots, b_k$ ($1 \le b_i \le n$) — the indices of the pressed buttons (in any order). The $b_i$ must be distinct, and at the end at most $\lfloor n/5 \rfloor$ lamps must be turned on.
## Example

### Input


```text
44 05 24 15 115 97 88 99 1010 911 112 213 314 415 55 41 22 33 44 5
```
### Output

```text

-1
4
3 5 1 2
3
8 9 10
1
5
```
## Note

In the first test case, you need to turn at most $\lfloor 4/5 \rfloor$ lamps on, which means that no lamp can be turned on. You can show that no choice of at least one button turns $0$ lamps on.

In the second test case, you can press buttons $3$, $5$, $1$, $2$.

* Initially, all the lamps are off;
* after pressing button $3$, the lamps whose index is a multiple of $3$ (i.e., $3$) are toggled, so lamp $3$ is turned on;
* after pressing button $5$, the lamps whose index is a multiple of $5$ (i.e., $5$) are toggled, so lamps $3$, $5$ are turned on;
* after pressing button $1$, the lamps whose index is a multiple of $1$ (i.e., $1$, $2$, $3$, $4$, $5$) are toggled, so lamps $1$, $2$, $4$ are turned on;
* after pressing button $2$, the lamps whose index is a multiple of $2$ (i.e., $2$, $4$) are toggled, so lamp $1$ is turned on.

This is valid because 

* you pressed at least one button;
* you pressed all the buttons at most once;
* you pressed button $u_2 = 5$, which means that you had to also press button $v_2 = 1$: in fact, button $1$ has been pressed;
* at the end, only lamp $1$ is on.

In the third test case, pressing the buttons $8$, $9$, $10$ turns only the lamps $8$, $9$, $10$ on.



#### Tags 

#2400 #NOT OK #bitmasks #brute_force #constructive_algorithms #math #number_theory 

## Blogs
- [All Contest Problems](../Pinely_Round_3_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
