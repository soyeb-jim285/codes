<h1 style='text-align: center;'> A. Sasha and Array Coloring</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sasha found an array $a$ consisting of $n$ integers and asked you to paint elements.

You have to paint each element of the array. You can use as many colors as you want, but each element should be painted into exactly one color, and for each color, there should be at least one element of that color.

The cost of one color is the value of $\max(S) - \min(S)$, where $S$ is the sequence of elements of that color. The cost of the whole coloring is the sum of costs over all colors.

For example, suppose you have an array $a = [\color{red}{1}, \color{red}{5}, \color{blue}{6}, \color{blue}{3}, \color{red}{4}]$, and you painted its elements into two colors as follows: elements on positions $1$, $2$ and $5$ have color $1$; elements on positions $3$ and $4$ have color $2$. Then:

* the cost of the color $1$ is $\max([1, 5, 4]) - \min([1, 5, 4]) = 5 - 1 = 4$;
* the cost of the color $2$ is $\max([6, 3]) - \min([6, 3]) = 6 - 3 = 3$;
* the total cost of the coloring is $7$.

For the given array $a$, you have to calculate the maximum possible cost of the coloring.

### Input

The first line contains one integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 50$) — length of $a$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq 50$) — array $a$.

### Output

For each test case output the maximum possible cost of the coloring.

## Example

### Input


```text
651 5 6 3 41541 6 3 961 13 9 3 7 242 2 2 254 5 2 2 3
```
### Output

```text

7
0
11
23
0
5

```
## Note

In the first example one of the optimal coloring is $[\color{red}{1}, \color{red}{5}, \color{blue}{6}, \color{blue}{3}, \color{red}{4}]$. The answer is $(5 - 1) + (6 - 3) = 7$.

In the second example, the only possible coloring is $[\color{blue}{5}]$, for which the answer is $5 - 5 = 0$.

In the third example, the optimal coloring is $[\color{blue}{1}, \color{red}{6}, \color{red}{3}, \color{blue}{9}]$, the answer is $(9 - 1) + (6 - 3) = 11$. 



#### Tags 

#800 #NOT OK #greedy #sortings #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_881_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
