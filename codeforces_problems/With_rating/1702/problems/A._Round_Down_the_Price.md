<h1 style='text-align: center;'> A. Round Down the Price</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

At the store, the salespeople want to make all prices round. 

In this problem, a number that is a power of $10$ is called a round number. For example, the numbers $10^0 = 1$, $10^1 = 10$, $10^2 = 100$ are round numbers, but $20$, $110$ and $256$ are not round numbers. 

So, if an item is worth $m$ bourles (the value of the item is not greater than $10^9$), the sellers want to change its value to the nearest round number that is not greater than $m$. They ask you: by how many bourles should you decrease the value of the item to make it worth exactly $10^k$ bourles, where the value of $k$ — is the maximum possible ($k$ — any non-negative integer).

For example, let the item have a value of $178$-bourles. Then the new price of the item will be $100$, and the answer will be $178-100=78$.

### Input

The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases .

Each test case is a string containing a single integer $m$ ($1 \le m \le 10^9$) — the price of the item.

### Output

For each test case, output on a separate line a single integer $d$ ($0 \le d < m$) such that if you reduce the cost of the item by $d$ bourles, the cost of the item will be the maximal possible round number. More formally: $m - d = 10^k$, where $k$ — the maximum possible non-negative integer.

## Example

### Input


```text
712178209999999999000987654321
```
### Output

```text

0
1
78
10
899999999
8000
887654321

```
## Note

In the example:

* $1 - 0 = 10^0$,
* $2 - 1 = 10^0$,
* $178 - 78 = 10^2$,
* $20 - 10 = 10^1$,
* $999999999 - 899999999 = 10^8$,
* $9000 - 8000 = 10^3$,
* $987654321 - 887654321 = 10^8$.

## Note

 that in each test case, we get the maximum possible round number.



#### Tags 

#800 #OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_805_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
