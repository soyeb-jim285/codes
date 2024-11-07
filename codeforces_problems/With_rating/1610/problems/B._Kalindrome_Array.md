<h1 style='text-align: center;'> B. Kalindrome Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An array $[b_1, b_2, \ldots, b_m]$ is a palindrome, if $b_i = b_{m+1-i}$ for each $i$ from $1$ to $m$. Empty array is also a palindrome.

An array is called kalindrome, if the following condition holds:

* It's possible to select some integer $x$ and delete some of the elements of the array equal to $x$, so that the remaining array (after gluing together the remaining parts) is a palindrome.

## Note

 that you don't have to delete all elements equal to $x$, and you don't have to delete at least one element equal to $x$.

For example : 

* $[1, 2, 1]$ is kalindrome because you can simply not delete a single element.
* $[3, 1, 2, 3, 1]$ is kalindrome because you can choose $x = 3$ and delete both elements equal to $3$, obtaining array $[1, 2, 1]$, which is a palindrome.
* $[1, 2, 3]$ is not kalindrome.

You are given an array $[a_1, a_2, \ldots, a_n]$. Determine if $a$ is kalindrome or not.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$) — elements of the array.

It's guaranteed that the sum of $n$ over all test cases won't exceed $2 \cdot 10^5$.

### Output

For each test case, print YES if $a$ is kalindrome and NO otherwise. You can print each letter in any case.

## Example

### Input


```text
4
1
1
2
1 2
3
1 2 3
5
1 4 4 1 4
```
### Output


```text
YES
YES
NO
YES
```
## Note

In the first test case, array $[1]$ is already a palindrome, so it's a kalindrome as well.

In the second test case, we can choose $x = 2$, delete the second element, and obtain array $[1]$, which is a palindrome.

In the third test case, it's impossible to obtain a palindrome.

In the fourth test case, you can choose $x = 4$ and delete the fifth element, obtaining $[1, 4, 4, 1]$. You also can choose $x = 1$, delete the first and the fourth elements, and obtain $[4, 4, 4]$.



#### Tags 

#1100 #NOT OK #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_17.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
