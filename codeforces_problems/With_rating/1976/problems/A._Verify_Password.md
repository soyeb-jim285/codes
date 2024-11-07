<h1 style='text-align: center;'> A. Verify Password</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is working on his new site, and the current challenge is to make the users pick strong passwords.

Monocarp decided that strong passwords should satisfy the following conditions: 

* password should consist only of lowercase Latin letters and digits;
* there should be no digit that comes after a letter (so, after each letter, there is either another letter or the string ends);
* all digits should be sorted in the non-decreasing order;
* all letters should be sorted in the non-decreasing order.

## Note

 that it's allowed for the password to have only letters or only digits.

Monocarp managed to implement the first condition, but he struggles with the remaining ones. Can you help him to verify the passwords?

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 20$) — the length of the password.

The second line contains a string, consisting of exactly $n$ characters. Each character is either a lowercase Latin letter or a digit.

### Output

For each testcase, print "YES" if the given password is strong and "NO" otherwise.

## Example

### Input


```text
5412ac5123wa9allllmost5ac1236011679
```
### Output

```text

YES
NO
YES
NO
YES

```
## Note

In the second testcase, the letters are not sorted in the non-decreasing order.

In the fourth testcase, there is a digit that comes after a letter — digit '1' after a letter 'c'.



#### Tags 

#800 #NOT OK #implementation #sortings #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_166_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
