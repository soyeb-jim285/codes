<h1 style='text-align: center;'> C. Carrying Conundrum</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice has just learned addition. However, she hasn't learned the concept of "carrying" fully — instead of carrying to the next column, she carries to the column two columns to the left.

For example, the regular way to evaluate the sum $2039 + 2976$ would be as shown: 

 ![](images/6cb0cb293dab7ce533fb10c4da8e27610d5181b9.png) However, Alice evaluates it as shown: 

 ![](images/98f8d3960e701645917956668cbe390f5a807d04.png) In particular, this is what she does: 

* add $9$ and $6$ to make $15$, and carry the $1$ to the column two columns to the left, i. e. to the column "$0$ $9$";
* add $3$ and $7$ to make $10$ and carry the $1$ to the column two columns to the left, i. e. to the column "$2$ $2$";
* add $1$, $0$, and $9$ to make $10$ and carry the $1$ to the column two columns to the left, i. e. to the column above the plus sign;
* add $1$, $2$ and $2$ to make $5$;
* add $1$ to make $1$.

 Thus, she ends up with the incorrect result of $15005$.Alice comes up to Bob and says that she has added two numbers to get a result of $n$. However, Bob knows that Alice adds in her own way. Help Bob find the number of ordered pairs of positive integers such that when Alice adds them, she will get a result of $n$. ## Note

 that pairs $(a, b)$ and $(b, a)$ are considered different if $a \ne b$.

## Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains an integer $n$ ($2 \leq n \leq 10^9$) — the number Alice shows Bob.

## Output

For each test case, output one integer — the number of ordered pairs of positive integers such that when Alice adds them, she will get a result of $n$. 

## Example

## Input


```

5
100
12
8
2021
10000

```
## Output


```

9
4
7
44
99

```
## Note

In the first test case, when Alice evaluates any of the sums $1 + 9$, $2 + 8$, $3 + 7$, $4 + 6$, $5 + 5$, $6 + 4$, $7 + 3$, $8 + 2$, or $9 + 1$, she will get a result of $100$. The picture below shows how Alice evaluates $6 + 4$: 

 ![](images/704366959d40aa707742d72e1e660c9027ff73cc.png) 

#### tags 

#1600 #bitmasks #combinatorics #dp #math 