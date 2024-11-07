<h1 style='text-align: center;'> A. Strong Password</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Monocarp's current password on Codeforces is a string $s$, consisting of lowercase Latin letters. Monocarp thinks that his current password is too weak, so he wants to insert exactly one lowercase Latin letter into the password to make it stronger. Monocarp can choose any letter and insert it anywhere, even before the first character or after the last character.

Monocarp thinks that the password's strength is proportional to the time it takes him to type the password. The time it takes to type the password is calculated as follows:

* the time to type the first character is $2$ seconds;
* for each character other than the first, the time it takes to type it is $1$ second if it is the same as the previous character, or $2$ seconds otherwise.

For example, the time it takes to type the password abacaba is $14$; the time it takes to type the password a is $2$; the time it takes to type the password aaabacc is $11$.

You have to help Monocarp — insert a lowercase Latin letter into his password so that the resulting password takes the maximum possible amount of time to type.

### Input

The first line contains one integer $t$ ($1 \le t \le 1000$) — the number of test cases.

Each test case consists of one line containing the string $s$ ($1 \le |s| \le 10$), consisting of lowercase Latin letters.

### Output

For each test case, print one line containing the new password — a string which can be obtained from $s$ by inserting one lowercase Latin letter. The string you print should have the maximum possible required time to type it. If there are multiple answers, print any of them.

## Example

### Input


```text
4aaaaabbpassword
```
### Output

```text

wa
aada
abcb
pastsword

```


#### Tags 

#NOT OK #brute_force #implementation #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_168_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1](../blogs/Tutorial_1.md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
