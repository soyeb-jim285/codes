<h1 style='text-align: center;'> C. Sofia and the Lost Operations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sofia had an array of $n$ integers $a_1, a_2, \ldots, a_n$. One day she got bored with it, so she decided to sequentially apply $m$ modification operations to it.

Each modification operation is described by a pair of numbers $\langle c_j, d_j \rangle$ and means that the element of the array with index $c_j$ should be assigned the value $d_j$, i.e., perform the assignment $a_{c_j} = d_j$. After applying all modification operations sequentially, Sofia discarded the resulting array.

Recently, you found an array of $n$ integers $b_1, b_2, \ldots, b_n$. You are interested in whether this array is Sofia's array. You know the values of the original array, as well as the values $d_1, d_2, \ldots, d_m$. The values $c_1, c_2, \ldots, c_m$ turned out to be lost.

Is there a sequence $c_1, c_2, \ldots, c_m$ such that the sequential application of modification operations $\langle c_1, d_1, \rangle, \langle c_2, d_2, \rangle, \ldots, \langle c_m, d_m \rangle$ to the array $a_1, a_2, \ldots, a_n$ transforms it into the array $b_1, b_2, \ldots, b_n$?

### Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains an integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the size of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the elements of the original array.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \le b_i \le 10^9$) — the elements of the found array.

The fourth line contains an integer $m$ ($1 \le m \le 2 \cdot 10^5$) — the number of modification operations.

The fifth line contains $m$ integers $d_1, d_2, \ldots, d_m$ ($1 \le d_j \le 10^9$) — the preserved value for each modification operation.

It is guaranteed that the sum of the values of $n$ for all test cases does not exceed $2 \cdot 10^5$, similarly the sum of the values of $m$ for all test cases does not exceed $2 \cdot 10^5$.

### Output

### Output

 $t$ lines, each of which is the answer to the corresponding test case. As an answer, output "YES" if there exists a suitable sequence $c_1, c_2, \ldots, c_m$, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

### Input


```text
731 2 11 3 241 3 1 241 2 3 52 1 3 522 357 6 1 10 103 6 1 11 1134 3 1143 1 7 82 2 7 10510 3 2 2 155 7 1 7 94 10 1 2 981 1 9 8 7 2 10 441000000000 203 203 203203 1000000000 203 10000000002203 100000000011151 3 4 5 1
```
### Output

```text

YES
NO
NO
NO
YES
NO
YES

```


#### Tags 

#1300 #NOT OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_950_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
