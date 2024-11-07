<h1 style='text-align: center;'> F. Chemistry Lab</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Monocarp is planning on opening a chemistry lab. During the first month, he's going to distribute solutions of a certain acid.

First, he will sign some contracts with a local chemistry factory. Each contract provides Monocarp with an unlimited supply of some solution of the same acid. The factory provides $n$ contract options, numbered from $1$ to $n$. The $i$-th solution has a concentration of $x_i\%$, the contract costs $w_i$ burles, and Monocarp will be able to sell it for $c_i$ burles per liter. 

Monocarp is expecting $k$ customers during the first month. Each customer will buy a liter of a $y\%$-solution, where $y$ is a real number chosen uniformly at random from $0$ to $100$ independently for each customer. More formally, the probability of number $y$ being less than or equal to some $t$ is $P(y \le t) = \frac{t}{100}$.

Monocarp can mix the solution that he signed the contracts with the factory for, at any ratio. More formally, if he has contracts for $m$ solutions with concentrations $x_1, x_2, \dots, x_m$, then, for these solutions, he picks their volumes $a_1, a_2, \dots, a_m$ so that $\sum \limits_{i=1}^{m} a_i = 1$ (exactly $1$ since each customer wants exactly one liter of a certain solution).

The concentration of the resulting solution is $\sum \limits_{i=1}^{m} x_i \cdot a_i$. The price of the resulting solution is $\sum \limits_{i=1}^{m} c_i \cdot a_i$.

If Monocarp can obtain a solution of concentration $y\%$, then he will do it while maximizing its price (the cost for the customer). Otherwise, the customer leaves without buying anything, and the price is considered equal to $0$.

Monocarp wants to sign some contracts with a factory (possibly, none or all of them) so that the expected profit is maximized — the expected total price of the sold solutions for all $k$ customers minus the total cost of signing the contracts from the factory.

Print the maximum expected profit Monocarp can achieve.

###### Input

The first line contains two integers $n$ and $k$ ($1 \le n \le 5000$; $1 \le k \le 10^5$) — the number of contracts the factory provides and the number of customers.

The $i$-th of the next $n$ lines contains three integers $x_i, w_i$ and $c_i$ ($0 \le x_i \le 100$; $1 \le w_i \le 10^9$; $1 \le c_i \le 10^5$) — the concentration of the solution, the cost of the contract and the cost per liter for the customer, for the $i$-th contract.

###### Output

Print a single real number — the maximum expected profit Monocarp can achieve.

Your answer is considered correct if its absolute or relative error does not exceed $10^{-6}$.

Formally, let your answer be $a$, and the jury's answer be $b$. Your answer is accepted if and only if $\frac{|a - b|}{\max{(1, |b|)}} \le 10^{-6}$.

## Examples

###### Input


```text
2 10
0 10 20
100 15 20
```
###### Output


```text
175.000000000000000
```
###### Input


```text
2 10
0 100 20
100 150 20
```
###### Output


```text
0.000000000000000
```
###### Input


```text
6 15
79 5 35
30 13 132
37 3 52
24 2 60
76 18 14
71 17 7
```
###### Output


```text
680.125000000000000
```
###### Input


```text
10 15
46 11 11
4 12 170
69 2 130
2 8 72
82 7 117
100 5 154
38 9 146
97 1 132
0 12 82
53 1 144
```
###### Output


```text
2379.400000000000000
```


#### Tags 

#2200 #NOT OK #dp #geometry #probabilities 

## Blogs
- [All Contest Problems](../2022-2023_ICPC,_NERC,_Southern_and_Volga_Russian_Regional_Contest_(Online_Mirror,_ICPC_Rules,_Preferably_Teams).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
