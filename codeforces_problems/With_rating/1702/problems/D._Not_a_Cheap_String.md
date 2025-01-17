<h1 style='text-align: center;'> D. Not a Cheap String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let $s$ be a string of lowercase Latin letters. Its price is the sum of the indices of letters (an integer between 1 and 26) that are included in it. For example, the price of the string abca is $1+2+3+1=7$.

The string $w$ and the integer $p$ are given. Remove the minimal number of letters from $w$ so that its price becomes less than or equal to $p$ and print the resulting string. Note that the resulting string may be empty. You can delete arbitrary letters, they do not have to go in a row. If the price of a given string $w$ is less than or equal to $p$, then nothing needs to be deleted and $w$ must be output.

Note that when you delete a letter from $w$, the order of the remaining letters is preserved. For example, if you delete the letter e from the string test, you get tst.

### Input

The first line of input contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases in the test. The following are descriptions of $t$ test cases.

Each case consists of two lines.

The first of them is the string $w$, it is non-empty and consists of lowercase Latin letters. Its length does not exceed $2\cdot10^5$.

The second line contains an integer $p$ ($1 \le p \le 5\,200\,000$).

It is guaranteed that the sum of string lengths $w$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

### Output

 exactly $t$ rows, the $i$-th of them should contain the answer to the $i$-th set of input data. Print the longest string that is obtained from $w$ by deleting letters such that its price is less or equal to $p$. If there are several answers, then output any of them.

Note that the empty string  — is one of the possible answers. In this case, just output an empty string.

## Example

### Input


```text
5abca2abca6codeforces1codeforces10codeforces100
```
### Output

```text

aa
abc

cdc
codeforces
```


#### Tags 

#1000 #OK #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_805_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
