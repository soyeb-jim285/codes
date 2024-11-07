<h1 style='text-align: center;'> F. Valuable Cards</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

In his favorite cafe Kmes once again wanted to try the herring under a fur coat. Previously, it would not have been difficult for him to do this, but the cafe recently introduced a new purchasing policy.

Now, in order to make a purchase, Kmes needs to solve the following problem: $n$ cards with prices for different positions are laid out in front of him, on the $i$-th card there is an integer $a_i$, among these prices there is no whole positive integer $x$.

Kmes is asked to divide these cards into the minimum number of bad segments (so that each card belongs to exactly one segment). A segment is considered bad if it is impossible to select a subset of cards with a product equal to $x$. All segments, in which Kmes will divide the cards, must be bad.

Formally, the segment $(l, r)$ is bad if there are no indices $i_1 < i_2 < \ldots < i_k$ such that $l \le i_1, i_k \le r$, and $a_{i_1} \cdot a_{i_2} \ldots \cdot a_{i_k} = x$.

Help Kmes determine the minimum number of bad segments in order to enjoy his favorite dish.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^3$) — the number of test cases.

The first line of each set of input data gives you $2$ integers $n$ and $x$ ($1 \le n \le 10^5, 2 \le x \le 10^5$) — the number of cards and the integer, respectively.

The second line of each set of input data contains $n$ integers $a_i$ ($1 \le a_i \le 2 \cdot 10^5, a_i \neq x$) — the prices on the cards.

It is guaranteed that the sum of $n$ over all sets of test data does not exceed $10^5$.

### Output

For each set of input data, output the minimum number of bad segments.

## Example

### Input


```text
86 42 3 6 2 1 29 10000050000 25000 12500 6250 3125 2 4 8 165 21 1 1 1 18 64 3 4 3 4 3 4 37 126 11 1 3 11 10 210 52 4 4 2 4 4 4 3 1 17 84 6 5 1 2 4 18 273 9 17 26 2 20 9 3
```
### Output

```text

3
2
1
1
2
1
3
3

```


#### Tags 

#1900 #NOT OK #brute_force #dp #greedy #number_theory #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_957_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1](../blogs/Tutorial_1.md)
- [Shayan's Video Tutorial (en)](../blogs/Shayan's_Video_Tutorial_(en).md)
