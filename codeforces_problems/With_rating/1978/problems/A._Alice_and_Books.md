<h1 style='text-align: center;'> A. Alice and Books</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice has $n$ books. The $1$-st book contains $a_1$ pages, the $2$-nd book contains $a_2$ pages, $\ldots$, the $n$-th book contains $a_n$ pages. Alice does the following:

* She divides all the books into two non-empty piles. Thus, each book ends up in exactly one of the two piles.
* Alice reads one book with the highest number in each pile.

Alice loves reading very much. Help her find the maximum total number of pages she can read by dividing the books into two piles.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 500$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 100$) — the number of books Alice has.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the number of pages in each book.

### Output

For each test case, output a single integer — the maximum number of pages Alice can read.

## Example

### Input


```text
521 142 3 3 152 2 3 2 2210 331 2 3
```
### Output

```text

2
4
5
13
5

```
## Note

In the first test case, Alice can put book number $1$ in the first pile, and book number $2$ in the second pile. Then she will read $a_1 + a_2 = 1 + 1 = 2$ pages.

In the second test case, Alice can put books with numbers $2$ and $3$ in the first pile, and books with numbers $1$ and $4$ in the second pile. Then she will read the book with the highest number $3$ from the first pile, and the book with the highest number $4$ from the second pile. Then she will read $a_3 + a_4 = 3 + 1 = 4$ pages.



#### Tags 

#800 #NOT OK #constructive_algorithms #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_953_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
