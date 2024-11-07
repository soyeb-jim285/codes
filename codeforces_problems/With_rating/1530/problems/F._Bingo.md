<h1 style='text-align: center;'> F. Bingo</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Getting ready for VK Fest 2021, you prepared a table with $n$ rows and $n$ columns, and filled each cell of this table with some event related with the festival that could either happen or not: for example, whether you will win a prize on the festival, or whether it will rain.

Forecasting algorithms used in VK have already estimated the probability for each event to happen. Event in row $i$ and column $j$ will happen with probability $a_{i, j} \cdot 10^{-4}$. All of the events are mutually independent.

Let's call the table winning if there exists a line such that all $n$ events on it happen. The line could be any horizontal line (cells $(i, 1), (i, 2), \ldots, (i, n)$ for some $i$), any vertical line (cells $(1, j), (2, j), \ldots, (n, j)$ for some $j$), the main diagonal (cells $(1, 1), (2, 2), \ldots, (n, n)$), or the antidiagonal (cells $(1, n), (2, n - 1), \ldots, (n, 1)$).

Find the probability of your table to be winning, and output it modulo $31\,607$ (see 
##### Output

 section).

##### Input

The first line contains a single integer $n$ ($2 \le n \le 21$) — the dimensions of the table.

The $i$-th of the next $n$ lines contains $n$ integers $a_{i, 1}, a_{i, 2}, \ldots, a_{i, n}$ ($0 < a_{i, j} < 10^4$). The probability of event in cell $(i, j)$ to happen is $a_{i, j} \cdot 10^{-4}$.

##### Output

Print the probability that your table will be winning, modulo $31\,607$.

Formally, let $M = 31\,607$. It can be shown that the answer can be expressed as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \not \equiv 0 \pmod{M}$. 
##### Output

 the integer equal to $p \cdot q^{-1} \bmod M$. In other words, output such an integer $x$ that $0 \le x < M$ and $x \cdot q \equiv p \pmod{M}$.

## Examples

##### Input


```text
2
5000 5000
5000 5000
```
##### Output


```text
5927
```
##### Input


```text
2
2500 6000
3000 4000
```
##### Output


```text
24812
```
##### Input


```text
3
1000 2000 3000
4000 5000 6000
7000 8000 9000
```
##### Output


```text
25267
```
## Note

In the first example, any two events form a line, and the table will be winning if any two events happen. The probability of this is $\frac{11}{16}$, and $5927 \cdot 16 \equiv 11 \pmod{31\,607}$.



#### Tags 

#2600 #NOT OK #bitmasks #combinatorics #dp #math #probabilities 

## Blogs
- [All Contest Problems](../Codeforces_Round_733_(Div._1_+_Div._2,_based_on_VK_Cup_2021_-_Elimination_(Engine)).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
