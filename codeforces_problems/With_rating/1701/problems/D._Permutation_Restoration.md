<h1 style='text-align: center;'> D. Permutation Restoration</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp had a permutation $a$ of $n$ integers $1$, $2$, ..., $n$ (a permutation is an array where each element from $1$ to $n$ occurs exactly once).

Then Monocarp calculated an array of integers $b$ of size $n$, where $b_i = \left\lfloor \frac{i}{a_i} \right\rfloor$. For example, if the permutation $a$ is $[2, 1, 4, 3]$, then the array $b$ is equal to $\left[ \left\lfloor \frac{1}{2} \right\rfloor, \left\lfloor \frac{2}{1} \right\rfloor, \left\lfloor \frac{3}{4} \right\rfloor, \left\lfloor \frac{4}{3} \right\rfloor \right] = [0, 2, 0, 1]$.

Unfortunately, the Monocarp has lost his permutation, so he wants to restore it. Your task is to find a permutation $a$ that corresponds to the given array $b$. If there are multiple possible permutations, then print any of them. The tests are constructed in such a way that least one suitable permutation exists.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^5$) — number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 5 \cdot 10^5$).

The second line contains $n$ integers $b_1, b_2, \dots, b_n$ ($0 \le b_i \le n$).

Additional constrains on the input:

* the sum of $n$ over test cases does not exceed $5 \cdot 10^5$;
* there exists at least one permutation $a$ that would yield this array $b$.
### Output

For each test case, print $n$ integers — a permutation $a$ that corresponds to the given array $b$. If there are multiple possible permutations, then print any of them.

## Example

### Input


```text
440 2 0 121 150 0 1 4 130 1 3
```
### Output

```text

2 1 4 3 
1 2 
3 4 2 1 5 
3 2 1 

```


#### Tags 

#1900 #NOT OK #binary_search #data_structures #greedy #math #sortings #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_131_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
