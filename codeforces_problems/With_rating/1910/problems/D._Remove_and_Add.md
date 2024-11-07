<h1 style='text-align: center;'> D. Remove and Add</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \dots, a_n$, consisting of $n$ integers.

You goal is to make is strictly increasing. To achieve that, you perform each of the following operations exactly once: 

* first, remove any element;
* second, select any number of elements (possibly, none or all $n-1$) and add $1$ to them.

## Note

 that you are not allowed to rearrange the elements of the array.

For the resulting array $a'$, $a'_1 < a'_2 < \dots < a'_{n-1}$ should hold. Determine if it's possible to achieve that.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of elements of the array.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$).

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

### Output

For each testcase, print YES if it's possible to remove one element and add $1$ to some elements (possibly, none or all), so that the array becomes strictly increasing. Otherwise, print NO.

## Example

### Input


```text
844 4 1 554 4 1 5 5210 531 2 332 1 141 1 1 141 3 1 251 1 3 3 1
```
### Output

```text

YES
NO
YES
YES
YES
NO
YES
YES

```
## Note

In the first testcase, you can remove the third element and add $1$ to the second and the last element. $a'$ will become $[4, 5, 6]$, which is strictly increasing.

In the second testcase, there is no way to perform the operations, so that the result is strictly increasing.

In the third testcase, you can remove either of the elements.

In the fourth testcase, you are already given a strictly increasing array, but you still have to remove an element. The result $a'$ can be $[1, 3]$, for example.



#### Tags 

#1800 #NOT OK #*special #greedy 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_9_(Unrated,_T-Shirts_+_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
