<h1 style='text-align: center;'> B. Prefix Removals</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of lowercase letters of the English alphabet. You must perform the following algorithm on $s$:

* Let $x$ be the length of the longest prefix of $s$ which occurs somewhere else in $s$ as a contiguous substring (the other occurrence may also intersect the prefix). If $x = 0$, break. Otherwise, remove the first $x$ characters of $s$, and repeat.

A prefix is a string consisting of several first letters of a given string, without any reorders. An empty prefix is also a valid prefix. For example, the string "abcd" has 5 prefixes: empty string, "a", "ab", "abc" and "abcd".

For instance, if we perform the algorithm on $s =$ "abcabdc", 

* Initially, "ab" is the longest prefix that also appears somewhere else as a substring in $s$, so $s =$ "cabdc" after $1$ operation.
* Then, "c" is the longest prefix that also appears somewhere else as a substring in $s$, so $s =$ "abdc" after $2$ operations.
* Now $x=0$ (because there are no non-empty prefixes of "abdc" that also appear somewhere else as a substring in $s$), so the algorithm terminates.

Find the final state of the string after performing the algorithm.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

This is followed by $t$ lines, each containing a description of one test case. Each line contains a string $s$. The given strings consist only of lowercase letters of the English alphabet and have lengths between $1$ and $2 \cdot 10^5$ inclusive.

It is guaranteed that the sum of the lengths of $s$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print a single line containing the string $s$ after executing the algorithm. It can be shown that such string is non-empty.

## Example

### Input


```text
6abcabdcabbbbbbbbbbcodeforcescffcfccffccfcffcfccfcffccffcfccfzyzyzwxxyyxxyyzzyzzxxwzxwywxwzxxyzzw
```
### Output

```text

abdc
a
b
deforces
cf
xyzzw

```
## Note

The first test case is explained in the statement.

In the second test case, no operations can be performed on $s$.

In the third test case, 

* Initially, $s =$ "bbbbbbbbbb".
* After $1$ operation, $s =$ "b".

In the fourth test case, 

* Initially, $s =$ "codeforces".
* After $1$ operation, $s =$ "odeforces".
* After $2$ operations, $s =$ "deforces".


#### Tags 

#800 #NOT OK #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_778_(Div._1_+_Div._2,_based_on_Technocup_2022_Final_Round).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
