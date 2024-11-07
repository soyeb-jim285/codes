<h1 style='text-align: center;'> C. Rudolf and the Ugly String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Rudolf has a string $s$ of length $n$. Rudolf considers the string $s$ to be ugly if it contains the substring$^\dagger$ "pie" or the substring "map", otherwise the string $s$ will be considered beautiful.

For example, "ppiee", "mmap", "dfpiefghmap" are ugly strings, while "mathp", "ppiiee" are beautiful strings.

Rudolf wants to shorten the string $s$ by removing some characters to make it beautiful.

The main character doesn't like to strain, so he asks you to make the string beautiful by removing the minimum number of characters. He can remove characters from any positions in the string (not just from the beginning or end of the string).

$^\dagger$ String $a$ is a substring of $b$ if there exists a consecutive segment of characters in string $b$ equal to $a$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^6$) — the length of the string $s$.

The next line of each test case contains the string $s$ of length $n$. The string $s$ consists of lowercase Latin letters.

The sum of $n$ over all test cases does not exceed $10^6$.

### Output

For each test case, output a single integer — the minimum number of characters that need to be deleted to make the string $s$ beautiful. If the string is initially beautiful, then output $0$.

## Example

### Input


```text
69mmapnapie9azabazapi8mappppie18mapmapmapmapmapmap1p11pppiepieeee
```
### Output

```text

2
0
2
6
0
2

```
## Note

In the first test case, for example, you can delete the $4$th and $9$th characters to make the string beautiful.

In the second test case, the string is already beautiful.



#### Tags 

#900 #NOT OK #dp #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_933_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
- [../blogs/https:_codeforces.com_blog_entry_126654.md](../blogs/https:_codeforces.com_blog_entry_126654.md)
