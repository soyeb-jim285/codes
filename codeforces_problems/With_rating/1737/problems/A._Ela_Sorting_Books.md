<h1 style='text-align: center;'> A. Ela Sorting Books</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>



|  | Ela loves reading a lot, just like her new co-workers in DTL! On her first day after becoming an engineer in DTL, she is challenged by a co-worker to sort a heap of books into different compartments on the shelf. |
| --- | --- |



$n$ books must be split into $k$ compartments on the bookshelf ($n$ is divisible by $k$). Each book is represented by a lowercase Latin letter from 'a' to 'y' inclusively, which is the beginning letter in the title of the book.

Ela must stack exactly $\frac{n}{k}$ books in each compartment. After the books are stacked, for each compartment indexed from $1$ to $k$, she takes the minimum excluded (MEX) letter of the multiset of letters formed by letters representing all books in that compartment, then combines the resulting letters into a string. The first letter of the resulting string is the MEX letter of the multiset of letters formed by the first compartment, the second letter of the resulting string is the MEX letter of the multiset of letters formed by the second compartment, ... and so on. Please note, under the constraint of this problem, MEX letter can always be determined for any multiset found in this problem because 'z' is not used.

What is the lexicographically greatest resulting string possible that Ela can create?

A string $a$ is lexicographically greater than a string $b$ if and only if one of the following holds:

* $b$ is a prefix of $a$, but $b \ne a$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears later in the alphabet than the corresponding letter in $b$.

The minimum excluded (MEX) letter of a multiset of letters is the letter that appears earliest in the alphabet and is not contained in the multiset. For example, if a multiset of letters contains $7$ letters 'b', 'a', 'b', 'c', 'e', 'c', 'f' respectively, then the MEX letter of this compartment is 'd', because 'd' is not included in the multiset, and all letters comes before 'd' in the alphabet, namely 'a', 'b' and 'c', are included in the multiset.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 200$; $1 \le k \le n$). It is guaranteed that $n$ is divisible by $k$.

The second line of each test case contains a string of $n$ lowercase Latin letters from 'a' to 'y' inclusively. Each letter represents the starting letter of the title of a book in the initial heap.

It is guaranteed that the sum of $n$ over all test cases does not exceed $1000$.

### Output

For each test case, output a string of $k$ letters which is the most optimal string that Ela can find.

## Example

### Input


```text
512 3cabccadabaac12 6cabccadabaac12 12cabccadabaac25 1abcdefghijklmnopqrstuvwxy10 5bcdxedbcfg
```
### Output

```text

edb
ccbbba
bbbbbaaaaaaa
z
aaaaa

```
## Note

In the first test case, the books can be divided into $3$ compartments as below:

* the first compartment contains the books with indices $1, 2, 3, 7$: $multiset_1 = \{$'c', 'a', 'b', 'd'$\}$ $\rightarrow$ $MEX(multiset_1) =$ 'e'
* the second compartment contains the books with indices $4, 5, 6, 9$ : $multiset_2 = \{$'c', 'c', 'a', 'b'$\}$ $\rightarrow$ $MEX(multiset_2) =$ 'd'
* the third compartment contains the remaining books $8, 10, 11, 12$ : $multiset_3 = \{$ 'a', 'a', 'a', 'c'$\}$ $\rightarrow$ $MEX(multiset_3) =$ 'b'

Therefore, the answer is 'edb'. It can be proven that there is no way that Ela can arrange the books so that it results in a lexicographically greater string.

 ![](images/45b7a6c149c79d98ff93542c526126f0e44b0e0d.png) 

#### Tags 

#900 #NOT OK #greedy #implementation #strings 

## Blogs
- [All Contest Problems](../Dytechlab_Cup_2022.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
