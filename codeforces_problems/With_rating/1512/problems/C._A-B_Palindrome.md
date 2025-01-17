<h1 style='text-align: center;'> C. A-B Palindrome</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of the characters '0', '1', and '?'. You need to replace all the characters with '?' in the string $s$ by '0' or '1' so that the string becomes a palindrome and has exactly $a$ characters '0' and exactly $b$ characters '1'. Note that each of the characters '?' is replaced independently from the others.

A string $t$ of length $n$ is called a palindrome if the equality $t[i] = t[n-i+1]$ is true for all $i$ ($1 \le i \le n$).

For example, if $s=$"01?????0", $a=4$ and $b=4$, then you can replace the characters '?' in the following ways: 

* "01011010";
* "01100110".

For the given string $s$ and the numbers $a$ and $b$, replace all the characters with '?' in the string $s$ by '0' or '1' so that the string becomes a palindrome and has exactly $a$ characters '0' and exactly $b$ characters '1'.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$). Then $t$ test cases follow.

The first line of each test case contains two integers $a$ and $b$ ($0 \le a, b \le 2 \cdot 10^5$, $a + b \ge 1$).

The second line of each test case contains the string $s$ of length $a+b$, consisting of the characters '0', '1', and '?'.

It is guaranteed that the sum of the string lengths of $s$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output: 

* "-1", if you can't replace all the characters '?' in the string $s$ by '0' or '1' so that the string becomes a palindrome and that it contains exactly $a$ characters '0' and exactly $b$ characters '1';
* the string that is obtained as a result of the replacement, otherwise.

If there are several suitable ways to replace characters, you can output any.

## Example

### Input


```text
9
4 4
01?????0
3 3
??????
1 0
?
2 2
0101
2 2
01?0
0 1
0
0 3
1?1
2 2
?00?
4 3
??010?0
```
### Output


```text
01011010
-1
0
-1
0110
-1
111
1001
0101010
```


#### Tags 

#1200 #NOT OK #constructive_algorithms #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_713_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
