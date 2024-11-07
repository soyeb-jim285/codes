<h1 style='text-align: center;'> D. Vika and Bonuses</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A new bonus system has been introduced at Vika's favorite cosmetics store, "Golden Pear"!

The system works as follows: suppose a customer has $b$ bonuses. Before paying for the purchase, the customer can choose one of two options: 

* Get a discount equal to the current number of bonuses, while the bonuses are not deducted.
* Accumulate an additional $x$ bonuses, where $x$ is the last digit of the number $b$. As a result, the customer's account will have $b+x$ bonuses.

For example, if a customer had $24$ bonuses, he can either get a discount of $24$ or accumulate an additional $4$ bonuses, after which his account will have $28$ bonuses.

At the moment, Vika has already accumulated $s$ bonuses.

The girl knows that during the remaining time of the bonus system, she will make $k$ more purchases at the "Golden Pear" store network.

After familiarizing herself with the rules of the bonus system, Vika became interested in the maximum total discount she can get.

Help the girl answer this question.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. The description of the test cases follows.

The test case consists of a single line containing two integers $s$ and $k$ ($0 \le s \le 10^9$, $1 \le k \le 10^9$) — the current number of bonuses in Vika's account and how many more purchases the girl will make.

## Output

For each test case, output a single integer — the maximum total discount that can be obtained through the bonus system.

## Example

## Input


```

61 311 30 1795 1000000000723252212 856168102728598293 145725253
```
## Output


```

4
33
0
9999999990
1252047198518668448
106175170582793129

```
## Note

In the first test case, Vika can accumulate bonuses after the first and second purchases, after which she can get a discount of $4$.

In the second test case, Vika can get a discount of $11$ three times, and the total discount will be $33$.

In the third example, regardless of Vika's actions, she will always get a total discount of $0$.



#### tags 

#2200 #binary_search #brute_force #math #ternary_search 