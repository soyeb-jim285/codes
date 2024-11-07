<h1 style='text-align: center;'> A. Only Pluses</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kmes has written three integers $a$, $b$ and $c$ in order to remember that he has to give Noobish_Monk $a \times b \times c$ bananas.

Noobish_Monk has found these integers and decided to do the following at most $5$ times:

* pick one of these integers;
* increase it by $1$.

For example, if $a = 2$, $b = 3$ and $c = 4$, then one can increase $a$ three times by one and increase $b$ two times. After that $a = 5$, $b = 5$, $c = 4$. Then the total number of bananas will be $5 \times 5 \times 4 = 100$.

What is the maximum value of $a \times b \times c$ Noobish_Monk can achieve with these operations?

## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains three integers $a$, $b$ and $c$ ($1 \le a, b, c \le 10$) — Kmes's integers.

## Output

For each test case, output a single integer — the maximum amount of bananas Noobish_Monk can get.

## Example

## Input


```

22 3 410 1 10
```
## Output


```

100
600

```


#### tags 

#800 #brute_force #constructive_algorithms #greedy #math #sortings 