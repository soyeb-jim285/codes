<h1 style='text-align: center;'> A. Colored Balls: Revisited</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The title is a reference to the very first Educational Round from our writers team, Educational Round 18.

There is a bag, containing colored balls. There are $n$ different colors of balls, numbered from $1$ to $n$. There are $\mathit{cnt}_i$ balls of color $i$ in the bag. The total amount of balls in the bag is odd (e. g. $\mathit{cnt}_1 + \mathit{cnt}_2 + \dots + \mathit{cnt}_n$ is odd).

In one move, you can choose two balls with different colors and take them out of the bag.

At some point, all the remaining balls in the bag will have the same color. That's when you can't make moves anymore.

Find any possible color of the remaining balls.

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 20$) — the number of colors.

The second line contains $n$ integers $\mathit{cnt}_1, \mathit{cnt}_2, \dots, \mathit{cnt}_n$ ($1 \le \mathit{cnt}_i \le 100$) — the amount of balls of each color in the bag.

The total amount of balls in the bag is odd (e. g. $\mathit{cnt}_1 + \mathit{cnt}_2 + \dots + \mathit{cnt}_n$ is odd).

### Output

For each testcase, print a single integer — any possible color of the remaining balls, after you made some moves and can't make moves anymore.

## Example

### Input


```text
331 1 11924 7
```
### Output

```text

3
1
2

```
## Note

In the first testcase, your first and only move can be one of the following: 

* take balls with colors $1$ and $2$;
* take balls with colors $1$ and $3$;
* take balls with colors $2$ and $3$.

After the move, exactly one ball will remain. Its color can be $3, 2$ or $1$ depending on the move.

In the second testcase, you can't make moves at all — there is only color of balls already. This color is $1$.

In the third testcase, you can keep removing one ball of color $1$ and one ball of color $2$ until there are no more balls of color $1$. At the end, three balls of color $2$ remain.



#### Tags 

#800 #OK #brute_force #greedy #implementation #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_135_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
