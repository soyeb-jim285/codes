<h1 style='text-align: center;'> A. The Enchanted Forest</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The enchanted forest got its name from the magical mushrooms growing here. They may cause illusions and generally should not be approached.—Perfect Memento in Strict SenseMarisa comes to pick mushrooms in the Enchanted Forest. 

The Enchanted forest can be represented by $n$ points on the $X$-axis numbered $1$ through $n$. Before Marisa started, her friend, Patchouli, used magic to detect the initial number of mushroom on each point, represented by $a_1,a_2,\ldots,a_n$.

Marisa can start out at any point in the forest on minute $0$. Each minute, the followings happen in order:

* She moves from point $x$ to $y$ ($|x-y|\le 1$, possibly $y=x$).
* She collects all mushrooms on point $y$.
* A new mushroom appears on each point in the forest.

## Note

 that she cannot collect mushrooms on minute $0$.

Now, Marisa wants to know the maximum number of mushrooms she can pick after $k$ minutes.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$, $k$ ($1 \le n \le 2 \cdot 10 ^ 5$, $1\le k \le 10^9$) — the number of positions with mushrooms and the time Marisa has, respectively.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le 10^9$) — the initial number of mushrooms on point $1,2,\ldots,n$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10 ^ 5$.

### Output

For each test case, print the maximum number of mushrooms Marisa can pick after $k$ minutes.

## Example

### Input


```text
45 25 6 1 2 35 75 6 1 2 31 29999995 700001000000000 1000000000 1000000000 1000000000 1000000000
```
### Output

```text

12
37
1000000
5000349985

```
## Note

Test case 1:

Marisa can start at $x=2$. In the first minute, she moves to $x=1$ and collect $5$ mushrooms. The number of mushrooms will be $[1,7,2,3,4]$. In the second minute, she moves to $x=2$ and collects $7$ mushrooms. The numbers of mushrooms will be $[2,1,3,4,5]$. After $2$ minutes, Marisa collects $12$ mushrooms.

It can be shown that it is impossible to collect more than $12$ mushrooms.

Test case 2:

This is one of her possible moving path:

$2 \rightarrow 3 \rightarrow 2 \rightarrow 1 \rightarrow 2 \rightarrow 3 \rightarrow 4 \rightarrow 5$

It can be shown that it is impossible to collect more than $37$ mushrooms.



#### Tags 

#1600 #NOT OK #brute_force #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_796_(Div._1).md)
- [Codeforces Round #796 (en)](../blogs/Codeforces_Round_796_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
