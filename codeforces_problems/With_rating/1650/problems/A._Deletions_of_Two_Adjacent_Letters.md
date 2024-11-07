<h1 style='text-align: center;'> A. Deletions of Two Adjacent Letters</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The string $s$ is given, the string length is odd number. The string consists of lowercase letters of the Latin alphabet.

As long as the string length is greater than $1$, the following operation can be performed on it: select any two adjacent letters in the string $s$ and delete them from the string. For example, from the string "lemma" in one operation, you can get any of the four strings: "mma", "lma", "lea" or "lem" In particular, in one operation, the length of the string reduces by $2$.

Formally, let the string $s$ have the form $s=s_1s_2 \dots s_n$ ($n>1$). During one operation, you choose an arbitrary index $i$ ($1 \le i < n$) and replace $s=s_1s_2 \dots s_{i-1}s_{i+2} \dots s_n$.

For the given string $s$ and the letter $c$, determine whether it is possible to make such a sequence of operations that in the end the equality $s=c$ will be true? In other words, is there such a sequence of operations that the process will end with a string of length $1$, which consists of the letter $c$?

### Input

The first line of input data contains an integer $t$ ($1 \le t \le 10^3$) — the number of input test cases.

The descriptions of the $t$ cases follow. Each test case is represented by two lines:

* string $s$, which has an odd length from $1$ to $49$ inclusive and consists of lowercase letters of the Latin alphabet;
* is a string containing one letter $c$, where $c$ is a lowercase letter of the Latin alphabet.
### Output

For each test case in a separate line output:

* YES, if the string $s$ can be converted so that $s=c$ is true;
* NO otherwise.

You can output YES and NO in any case (for example, the strings yEs, yes, Yes and YES will be recognized as a positive response).

## Example

### Input


```text
5abcdecabcdebxyaaaaaaaaaaaaaaaacontestt
```
### Output

```text

YES
NO
NO
YES
YES

```
## Note

In the first test case, $s$="abcde". You need to get $s$="c". For the first operation, delete the first two letters, we get $s$="cde". In the second operation, we delete the last two letters, so we get the expected value of $s$="c".

In the third test case, $s$="x", it is required to get $s$="y". Obviously, this cannot be done.



#### Tags 

#800 #OK #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_776_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
