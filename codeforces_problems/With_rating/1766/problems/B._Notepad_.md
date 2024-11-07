<h1 style='text-align: center;'> B. Notepad#</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You want to type the string $s$, consisting of $n$ lowercase Latin letters, using your favorite text editor 
## Note

pad#.

## Note

pad
# supports two kinds of operations: 

* append any letter to the end of the string;
* copy a continuous substring of an already typed string and paste this substring to the end of the string.

Can you type string $s$ in strictly less than $n$ operations?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the string $s$.

The second line contains a string $s$, consisting of $n$ lowercase Latin letters.

The sum of $n$ doesn't exceed $2 \cdot 10^5$ over all testcases.

### Output

For each testcase, print "YES" if you can type string $s$ in strictly less than $n$ operations. Otherwise, print "NO".

## Example

### Input


```text
610codeforces8labacaba5uohhh16isthissuffixtree1x4momo
```
### Output

```text

NO
YES
NO
YES
NO
YES

```
## Note

In the first testcase, you can start with typing "codef" ($5$ operations), then copy "o" ($1$ operation) from an already typed part, then finish with typing "rces" ($4$ operations). That will be $10$ operations, which is not strictly less than $n$. There exist other ways to type "codeforces". However, no matter what you do, you can't do less than $n$ operations.

In the second testcase, you can type "labac" ($5$ operations), then copy "aba" ($1$ operation), finishing the string in $6$ operations.



#### Tags 

#1000 #OK #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_139_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
