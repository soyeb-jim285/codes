<h1 style='text-align: center;'> F. String and Operations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of $n$ characters. These characters are among the first $k$ lowercase letters of the Latin alphabet. You have to perform $n$ operations with the string.

During the $i$-th operation, you take the character that initially occupied the $i$-th position, and perform one of the following actions with it:

* swap it with the previous character in the string (if it exists). This operation is represented as L;
* swap it with the next character in the string (if it exists). This operation is represented as R;
* cyclically change it to the previous character in the alphabet (b becomes a, c becomes b, and so on; a becomes the $k$-th letter of the Latin alphabet). This operation is represented as D;
* cyclically change it to the next character in the alphabet (a becomes b, b becomes c, and so on; the $k$-th letter of the Latin alphabet becomes a). This operation is represented as U;
* do nothing. This operation is represented as 0.

For example, suppose the initial string is test, $k = 20$, and the sequence of operations is URLD. Then the string is transformed as follows:

1. the first operation is U, so we change the underlined letter in test to the next one in the first $20$ Latin letters, which is a. The string is now aest;
2. the second operation is R, so we swap the underlined letter with the next one in the string aest. The string is now aset;
3. the third operation is L, so we swap the underlined letter with the previous one in the string aset (note that this is now the $2$-nd character of the string, but it was initially the $3$-rd one, so the $3$-rd operation is performed to it). The resulting string is saet;
4. the fourth operation is D, so we change the underlined letter in saet to the previous one in the first $20$ Latin letters, which is s. The string is now saes.

The result of performing the sequence of operations is saes.

Given the string $s$ and the value of $k$, find the lexicographically smallest string that can be obtained after applying a sequence of operations to $s$.

### Input

The first line contains one integer $t$ ($1 \le t \le 1000$) — the number of test cases.

Each test case consists of two lines. The first line contains two integers $n$ and $k$ ($1 \le n \le 500$; $2 \le k \le 26$). 

The second line contains a string $s$ consisting of $n$ characters. Each character is one of the $k$ first letters of the Latin alphabet (in lower case).

### Output

For each test case, print one line containing the lexicographically smallest string that can be obtained from $s$ using one sequence of operations.

## Example

### Input


```text
6
4 2
bbab
7 5
cceddda
6 5
ecdaed
7 4
dcdbdaa
8 3
ccabbaca
5 7
eabba
```
### Output


```text
aaaa
baccacd
aabdac
aabacad
aaaaaaaa
abadb
```


#### Tags 

#2800 #NOT OK #dp #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_99_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
