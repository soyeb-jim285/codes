<h1 style='text-align: center;'> C. Unstable String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of the characters 0, 1, and ?.

Let's call a string unstable if it consists of the characters 0 and 1 and any two adjacent characters are different (i. e. it has the form 010101... or 101010...).

Let's call a string beautiful if it consists of the characters 0, 1, and ?, and you can replace the characters ? to 0 or 1 (for each character, the choice is independent), so that the string becomes unstable.

For example, the strings 0??10, 0, and ??? are beautiful, and the strings 00 and ?1??1 are not.

Calculate the number of beautiful contiguous substrings of the string $s$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — number of test cases.

The first and only line of each test case contains the string $s$ ($1 \le |s| \le 2 \cdot 10^5$) consisting of characters 0, 1, and ?.

It is guaranteed that the sum of the string lengths over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer — the number of beautiful substrings of the string $s$.

## Example

### Input


```text
3
0?10
???
?10??1100
```
### Output


```text
8
6
25
```


#### Tags 

#1400 #NOT OK #binary_search #dp #greedy #implementation #strings #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_110_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
