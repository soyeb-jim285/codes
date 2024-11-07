<h1 style='text-align: center;'> B. Three Threadlets</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once upon a time, bartender Decim found three threadlets and a pair of scissors.

In one operation, Decim chooses any threadlet and cuts it into two threadlets, whose lengths are positive integers and their sum is equal to the length of the threadlet being cut.

For example, he can cut a threadlet of length $5$ into threadlets of lengths $2$ and $3$, but he cannot cut it into threadlets of lengths $2.5$ and $2.5$, or lengths $0$ and $5$, or lengths $3$ and $4$.

Decim can perform at most three operations. He is allowed to cut the threadlets obtained from previous cuts. Will he be able to make all the threadlets of equal length?

### Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then follows the description of each test case.

In a single line of each test case, there are three integers $a$, $b$, $c$ ($1 \le a, b, c \le 10^9$) — the lengths of the threadlets.

### Output

For each test case, output "YES" if it is possible to make all the threadlets of equal length by performing at most three operations, otherwise output "NO".

You can output "YES" and "NO" in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

## Example

### Input


```text
151 3 25 5 56 36 127 8 76 3 34 4 1212 6 81000000000 1000000000 10000000003 7 19 9 19 3 62 8 25 3 108 4 82 8 4
```
### Output

```text

YES
YES
NO
NO
YES
YES
NO
YES
NO
NO
YES
YES
NO
YES
NO

```
## Note

Let's consider some testcases of the first test.

In the first testcase, you can apply following operations:

$1, 3, 2 \to 1, 2, 1, 2 \to 1, 1, 1, 1, 2 \to 1, 1, 1, 1, 1, 1$.

In the second testcase, you can do nothing, the threadlets are already of equal length.

In the third testcase, it isn't possible to make threadlets of equal length.



#### Tags 

#900 #OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_903_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
