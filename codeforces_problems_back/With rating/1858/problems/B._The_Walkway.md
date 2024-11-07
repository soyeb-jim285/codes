<h1 style='text-align: center;'> B. The Walkway</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ benches near the Main Walkway in Summer Infomatics School. These benches are numbered by integers from $1$ to $n$ in order they follow. Also there are $m$ cookie sellers near the Walkway. The $i$-th ($1 \le i \le m$) cookie sellers is located near the $s_i$-th bench.

Petya is standing in the beginning of the Walkway. He will pass near all benches starting from the $1$-st bench and ending with the $n$-th bench. Petya passes the distance between two consecutive benches in $1$ minute. He has a knapsack with an infinite amount of cookies. Petya is going to eat cookies from his knapsack and buy them from cookie sellers during the walk.

Petya eats cookies only near the benches according to the following rule: he will eat the cookie near the $i$-th ($1 \le i \le n$) bench if and only if at least one of the following conditions holds:

* There is a cookie seller near the $i$-th bench. Then Petya will buy a cookie from cookie seller and eat it immediately.
* Petya has not yet eaten a cookie. Then Petya will take a cookie from his knapsack and eat it immediately.
* At least $d$ minutes passed since Petya ate the previous cookie. In other words, Petya has not eaten a cookie near the benches $i-1, i-2, \ldots, \max(i-d+1, 1)$. Then Petya will take a cookie from his knapsack and eat it immediately.

You may assume that Petya eats cookies instantly. Petya will not eat two or more cookies near the same bench.

You want to minimize the number of cookies Petya will eat during his walk. In order to do this, you will ask the administration of the Summer Informatics School to remove exactly one cookie seller from the Walkway before Petya starts his walk.

Please determine the minimum possible number of cookies Petya can eat after removing exactly one cookie seller. Also determine the number of cookie sellers, such that if you remove one of them, Petya will eat the minimum possible number of cookies.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^3$) — the number of test cases.

The first line of each test case contains three integers $n$, $m$ and $d$ ($2 \le d \le n \le 10^9$, $2 \le m \le \min(10^{5}, n)$) — the number of benches, the number of cookie sellers and the value of parameter $d$ from the statement, respectively.

The second line of each test case contains $m$ integers $s_1, s_2, \ldots, s_m$ ($1 \le s_i \le n$) — the locations of the cookie sellers. It is guaranteed that $s_{i} < s_{i+1}$ for all $1 \leq i \leq m - 1$.

It is guaranteed that the sum of $m$ over all test cases does not exceed $10^5$.

## Output

For each test case print two integers — the minimum number of cookies that Petya can eat if exactly one cookie seller is removed, and the number of cookie sellers such that if one of them is removed, Petya will eat the minimum possible number of cookies.

## Example

## Input


```

86 2 22 58 3 23 5 810 4 92 8 9 1030 5 86 8 15 24 2930 5 86 8 12 20 278 8 31 2 3 4 5 6 7 82 2 21 21000000000 3 2000000057008429 66778899 837653445
```
## Output


```

3 1
4 1
4 4
6 4
5 2
7 7
1 1
51 1

```
## Note

In the first test case $n=6$, $m=2$, $d=2$ and $s=[2, 5]$. If no cookie seller is removed, then Petya will eat $4$ cookies during his walk (note that you have to remove exactly one cookie seller; this case is explained only to show how Petya decides whether to eat a cookie): 

* Petya will eat a cookie near the $1$-st bench since he has not yet eaten a cookie.
* Petya will eat a cookie near the $2$-nd bench since there is a cookie seller near this bench.
* Petya will not eat a cookie near the $3$-rd bench since only $1<d$ minute passed since he ate a cookie.
* Petya will eat a cookie near the $4$-th bench since $2\ge d$ minutes passed since he ate a cookie.
* Petya will eat a cookie near the $5$-th bench since there is a cookie seller near this bench.
* Petya will not eat a cookie near the $6$-th bench since only $1<d$ minute passed since he ate a cookie.

If the $1$-st cookie seller is removed, Petya will eat $3$ cookies (near the benches $1$, $3$ and $5$). If the $2$-nd cookie seller is removed, Petya will eat $4$ cookies (near the benches $1$, $2$, $4$ and $6$).

Thus, the minimum number of cookies Petya will eat is $3$; there is only one cookie seller such that removing it results in minimizing the number of cookies Petya will eat.

In the second test case 

* the removal of the $1$-st or the $2$-nd cookie seller results in Petya eating $5$ cookies near the benches $1$, $3$, $5$, $7$, $8$;
* the removal of the $3$-rd cookie seller results in Petya eating $4$ cookies near the benches $1$, $3$, $5$, $7$.

## Note

 that the second integer you should output is the number of (that is, amount) cookie sellers, not the index of a cookie seller to remove. Thus, the answer to the second test case is 4 1 because there is only one cookie seller such that removing it results in Petya eating four cookies, which is the minimum possible.

In the third test case Petya will eat $4$ cookies no matter what cookie seller is removed.

## Note

 that Petya is not interested in minimizing the number of cookies he will eat, so he eats cookies whenever it is possible under the rule from the statement.



#### tags 

#1500 #brute_force #dp #greedy #math #number_theory 