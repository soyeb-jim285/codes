<h1 style='text-align: center;'> E. Outermost Maximums</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Yeri has an array of $n + 2$ non-negative integers : $a_0, a_1, ..., a_n, a_{n + 1}$.

We know that $a_0 = a_{n + 1} = 0$.

She wants to make all the elements of $a$ equal to zero in the minimum number of operations.

In one operation she can do one of the following: 

* Choose the leftmost maximum element and change it to the maximum of the elements on its left.
* Choose the rightmost maximum element and change it to the maximum of the elements on its right.

Help her find the minimum number of operations needed to make all elements of $a$ equal to zero.

##### Input

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le n$).

##### Output

Print a single integer  — the minimum number of operations needed to make all elements of $a$ equal to zero.

## Examples

##### Input


```text
6
1 4 2 4 0 2
```
##### Output


```text
7
```
##### Input


```text
5
1 3 5 4 2
```
##### Output


```text
9
```
##### Input


```text
4
0 0 0 0
```
##### Output


```text
0
```
## Note

In the first sample, you get $\langle 1, \underline{1}, 2, 4, 0, 2 \rangle$ by performing the first operation and $\langle 1, 4, 2, \underline{2}, 0, 2 \rangle$ by performing the second operation.

One way to achieve our goal is shown below. (The underlines show the last change.) $\langle 1, 4, 2, 4, 0, 2 \rangle \to \langle 1, 4, 2, \underline{2}, 0, 2 \rangle \to \langle 1, \underline{1}, 2, 2, 0, 2 \rangle \to \langle 1, 1, 2, 2, 0, \underline{0} \rangle \to \langle 1, 1, 2, \underline{0}, 0, 0 \rangle \to \langle 1, 1, \underline{0}, 0, 0, 0 \rangle \to \langle \underline{0}, 1, 0, 0, 0, 0 \rangle \to \langle 0, \underline{0}, 0, 0, 0, 0 \rangle $

In the third sample each element is already equal to zero so no operations are needed.



#### Tags 

#3400 #NOT OK #data_structures #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_800_(Div._1).md)
- [Codeforces Round #800 (en)](../blogs/Codeforces_Round_800_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
