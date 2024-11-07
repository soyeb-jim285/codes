<h1 style='text-align: center;'> B. Make It Ugly</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call an array $a$ beautiful if you can make all its elements the same by using the following operation an arbitrary number of times (possibly, zero): 

* choose an index $i$ ($2 \le i \le |a| - 1$) such that $a_{i - 1} = a_{i + 1}$, and replace $a_i$ with $a_{i - 1}$.

You are given a beautiful array $a_1, a_2, \dots, a_n$. What is the minimum number of elements you have to remove from it in order for it to stop being beautiful? Swapping elements is prohibited. If it is impossible to do so, then output -1.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 3 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$).

Additional constraints on the input:

* in every test case, the given array $a$ is beautiful;
* the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.
### Output

For each test case, output a single integer — the minimum number of elements you have to remove from the array $a$ in order for it to stop being beautiful. If it is impossible, then output -1.

## Example

### Input


```text
432 2 251 2 1 2 11173 3 3 5 3 3 3
```
### Output

```text

-1
1
-1
3

```
## Note

In the first testcase, it is impossible to modify the array in such a way that it stops being beautiful. An array consisting of identical numbers will remain beautiful no matter how many numbers we remove from it.

In the second testcase, you can remove the number at the index $5$, for example.

The resulting array will be $[1, 2, 1, 2]$. Let's check if it is beautiful. Two operations are available: 

* Choose $i = 2$: the array becomes $[1, 1, 1, 2]$. No more operations can be applied to it, and the numbers are not all the same.
* Choose $i = 3$ instead: the array becomes $[1, 2, 2, 2]$. No more operations can be applied to it either, and the numbers are still not all the same.

Thus, the array $[1, 2, 1, 2]$ is not beautiful.

In the fourth testcase, you can remove the first three elements, for example. The resulting array $[5, 3, 3, 3]$ is not beautiful.



#### Tags 

#1200 #NOT OK #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_164_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
