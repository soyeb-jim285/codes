<h1 style='text-align: center;'> G. Permutation of Given</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You were given only one number, $n$. It didn't seem interesting to you, so you wondered if it's possible to come up with an array of length $n$ consisting of non-zero integers, such that if each element of the array is replaced by the sum of its neighbors (the elements on the ends are replaced by their only neighbors), you obtain a permutation of the numbers in the original array.

#### Input

Each test case contains only one number, $n$ ($2 \leq n \leq 10^6$).

#### Output

If a solution exists, output "YES" (without quotes), followed by an array $a$ ($-10^9 \leq a_i \leq 10^9, a_i \neq 0$) that satisfies the condition of the problem. If there are multiple possible answers, output any of them.

If there is no suitable array, output "NO" (without quotes).

The words "YES" and "NO" can be output in any case, for example, "YES", "Yes", "yEs", and so on.

## Examples

#### Input


```text
4
```
#### Output

```text

YES
1 2 -2 -1
```
#### Input


```text
5
```
#### Output

```text

NO

```
## Note

In the first test, the array [$1, 2, -2, -1$] is suitable, because if each element is replaced by the sum of its neighbors, the resulting array is [$2, -1, 1, -2$], which is a permutation of the original array.

In the second test, it can be shown that there is no solution.



#### Tags 

#2700 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_922_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
