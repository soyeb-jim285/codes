<h1 style='text-align: center;'> B. Astrophysicists</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In many, many years, far, far away, there will be a launch of the first flight to Mars. To celebrate the success, $n$ astrophysicists working on the project will be given bonuses of a total value of $k$ gold coins.

You have to distribute the money among the astrophysicists, and to make it easier, you have to assign bonuses in silver coins. Each gold coin is worth $g$ silver coins, so you have to distribute all $k \cdot g$ silver coins among $n$ people.

Unfortunately, the company has some financial troubles right now. Therefore, instead of paying the number of silver coins written on the bonus, they decided to round this amount to the nearest integer number of gold coins.

The rounding procedure is as follows. If an astrophysicist has bonus equal to $x$ silver coins, and we denote $r = x \bmod g$, then: 

* If $r \geq \lceil \frac{g}{2} \rceil$, the astrophysicist receives $x + (g - r)$ silver coins;
* Otherwise, an astrophysicists receives $x - r$ silver coins.

 
## Note

 that due to rounding, the total sum of actually paid money is not, in general, equal to $k \cdot g$ silver coins. The operation $a \bmod b$ denotes the remainder of the division of $a$ by $b$. Sum of values before rounding has to be equal to $k \cdot g$ silver coins, but some workers can be assigned $0$ silver coins.You aim to distribute the bonuses so that the company saves as many silver coins due to rounding as possible. Please note that there is always a distribution in which the company spends no more than $k \cdot g$ silver coins.

### Input

In the first line of input, there is one integer $t$ ($1 \leq t \leq 10^4$) denoting the number of test cases.

Each of the following $t$ lines describes one test case and contains three integers $n$, $k$, $g$ ($1 \le n \le 10^9$, $0 \le k \le 10^9$, $2 \le g \le 10^9$) — respectively the number of astrophysicists in the company, total number of gold coins to assign and the number of silver coins that one gold coin corresponds to.

### Output

In a separate line for each test case, output a single integer — the maximum number of silver coins that could be saved due to rounding.

## Example

### Input


```text
53 3 1002 1 1491 2 1336 16 673 8 22
```
### Output

```text

100
0
26
72
176

```
## Note

In the first test case, one of the optimal assignments could be the following:

* First person: $x = 30$ silver coins: company pays $0$, saves $30$ silver coins,
* Second person: $x = 140$ silver coins: company pays $100$, saves $40$ silver coins,
* Third person: $x = 130$ silver coins: company pays $100$, saves $30$ silver coins.

In the second test case, we could have the following assignment: 

* First person: $x = 8$ silver coins: company pays $14$, spends extra $6$ silver coins,
* Second person: $x = 6$ silver coins: company pays $0$, saves $6$ silver coins.

If the bonuses are assigned to $7$ silver coins for both astrophysicists, then the company would have to pay an additional gold coin to cover the bonuses.



#### Tags 

#1100 #NOT OK #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_880_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
