<h1 style='text-align: center;'> C. Water the Trees</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ trees in a park, numbered from $1$ to $n$. The initial height of the $i$-th tree is $h_i$.

You want to water these trees, so they all grow to the same height.

The watering process goes as follows. You start watering trees at day $1$. During the $j$-th day you can: 

* Choose a tree and water it. If the day is odd (e.g. $1, 3, 5, 7, \dots$), then the height of the tree increases by $1$. If the day is even (e.g. $2, 4, 6, 8, \dots$), then the height of the tree increases by $2$.
* Or skip a day without watering any tree.

## Note

 that you can't water more than one tree in a day. 

Your task is to determine the minimum number of days required to water the trees so they grow to the same height.

You have to answer $t$ independent test cases.

### Input

The first line of the input contains one integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases.

The first line of the test case contains one integer $n$ ($1 \le n \le 3 \cdot 10^5$) — the number of trees.

The second line of the test case contains $n$ integers $h_1, h_2, \ldots, h_n$ ($1 \le h_i \le 10^9$), where $h_i$ is the height of the $i$-th tree.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$ ($\sum n \le 3 \cdot 10^5$).

### Output

For each test case, print one integer — the minimum number of days required to water the trees, so they grow to the same height.

## Example

### Input


```text
331 2 454 4 3 5 572 5 4 8 3 7 4
```
### Output

```text

4
3
16

```
## Note

Consider the first test case of the example. The initial state of the trees is $[1, 2, 4]$.

1. During the first day, let's water the first tree, so the sequence of heights becomes $[2, 2, 4]$;
2. during the second day, let's water the second tree, so the sequence of heights becomes $[2, 4, 4]$;
3. let's skip the third day;
4. during the fourth day, let's water the first tree, so the sequence of heights becomes $[4, 4, 4]$.

Thus, the answer is $4$.



#### Tags 

#1700 #NOT OK #binary_search #greedy #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_126_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
