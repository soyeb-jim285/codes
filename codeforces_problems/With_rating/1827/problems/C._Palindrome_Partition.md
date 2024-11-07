<h1 style='text-align: center;'> C. Palindrome Partition</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A substring is a continuous and non-empty segment of letters from a given string, without any reorders.

An even palindrome is a string that reads the same backward as forward and has an even length. For example, strings "zz", "abba", "abccba" are even palindromes, but strings "codeforces", "reality", "aba", "c" are not.

A beautiful string is an even palindrome or a string that can be partitioned into some smaller even palindromes.

You are given a string $s$, consisting of $n$ lowercase Latin letters. Count the number of beautiful substrings of $s$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 5\cdot 10^5$).

The second line of each test case contains a string $s$. String $s$ consists of only lowercase Latin letters and has a length of $n$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5\cdot 10^5$.

### Output

For each test case print the number of beautiful substrings.

## Example

### Input


```text
66abaaba1a2aa6abcdef12accabccbacca6abbaaa
```
### Output

```text

3
0
1
0
14
6

```
## Note

In the first test case, the beautiful substrings are "abaaba", "baab", "aa".

In the last test case, the beautiful substrings are "aa" (counted twice), "abba", "bb", "bbaa", "abbaaa".



#### Tags 

#2600 #NOT OK #binary_search #brute_force #data_structures #dp #hashing #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_873_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
