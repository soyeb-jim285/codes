<h1 style='text-align: center;'> A. String Generation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One fall day Joe got bored because he couldn't find himself something interesting to do. Marty suggested Joe to generate a string of length $n$ to entertain him somehow. It didn't seem particularly difficult, but Joe's generated string had to follow these rules:

* the string may only contain characters 'a', 'b', or 'c';
* the maximum length of a substring of this string that is a palindrome does not exceed $k$.

 ![](images/10d6acb7a5a08122f364198611f17101e3601362.png) A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end. For example, strings "a", "bc", "abc" are substrings of a string "abc", while strings "ac", "ba", "cba" are not.

A string is a palindrome if it reads the same from the left to the right and from the right to the left. For example, strings "abccba", "abbba", "aba", "abacaba", "a", and "bacab" are palindromes, while strings "abcbba", "abb", and "ab" are not.

Now Joe wants to find any correct string. Help him! It can be proven that the answer always exists under the given constraints.

### Input

Each test contains one or more test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10$).

The only line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 1\,000$) — the required string length and the maximum length of a palindrome substring, respectively.

### Output

For each test case, print any string that satisfies the conditions from the problem statement. If there are multiple correct answers, you can print any one of them. It can be proven that the answer always exists under the given constraints.

## Example

### Input


```text
2
3 2
4 1
```
### Output


```text
aab
acba
```
## Note

In the first test case of the example, the palindrome substring with the maximum length is "aa". Its length does not exceed $2$, so it fits.

In the second test case all palindrome substrings have the length one.



#### Tags 

#800 #NOT OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_689_(Div._2,_based_on_Zed_Code_Competition).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
