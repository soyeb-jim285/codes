<h1 style='text-align: center;'> C. AquaMoon and Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Cirno has prepared $n$ arrays of length $n$ each. Each array is a permutation of $n$ integers from $1$ to $n$. These arrays are special: for all $1 \leq i \leq n$, if we take the $i$-th element of each array and form another array of length $n$ with these elements, the resultant array is also a permutation of $n$ integers from $1$ to $n$. In the other words, if you put these $n$ arrays under each other to form a matrix with $n$ rows and $n$ columns, this matrix is a [Latin square](https://en.wikipedia.org/wiki/Latin_square).

Afterwards, Cirno added additional $n$ arrays, each array is a permutation of $n$ integers from $1$ to $n$. For all $1 \leq i \leq n$, there exists at least one position $1 \leq k \leq n$, such that for the $i$-th array and the $(n + i)$-th array, the $k$-th element of both arrays is the same. Notice that the arrays indexed from $n + 1$ to $2n$ don't have to form a Latin square. 

Also, Cirno made sure that for all $2n$ arrays, no two arrays are completely equal, i. e. for all pair of indices $1 \leq i < j \leq 2n$, there exists at least one position $1 \leq k \leq n$, such that the $k$-th elements of the $i$-th and $j$-th array are different.

Finally, Cirno arbitrarily changed the order of $2n$ arrays.

AquaMoon calls a subset of all $2n$ arrays of size $n$ good if these arrays from a Latin square.

AquaMoon wants to know how many good subsets exist. Because this number may be particularly large, find it modulo $998\,244\,353$. Also, she wants to find any good subset. Can you help her?

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($5 \leq n \leq 500$).

Then $2n$ lines followed. The $i$-th of these lines contains $n$ integers, representing the $i$-th array.

It is guaranteed, that the sum of $n$ over all test cases does not exceed $500$.

### Output

For each test case print two lines.

In the first line, print the number of good subsets by modulo $998\,244\,353$.

In the second line, print $n$ indices from $1$ to $2n$ — indices of the $n$ arrays that form a good subset (you can print them in any order). If there are several possible answers — print any of them.

## Example

### Input


```text
3
7
1 2 3 4 5 6 7
2 3 4 5 6 7 1
3 4 5 6 7 1 2
4 5 6 7 1 2 3
5 6 7 1 2 3 4
6 7 1 2 3 4 5
7 1 2 3 4 5 6
1 2 3 4 5 7 6
1 3 4 5 6 7 2
1 4 5 6 7 3 2
1 5 6 7 4 2 3
1 6 7 5 2 3 4
1 7 6 2 3 4 5
1 7 2 3 4 5 6
5
4 5 1 2 3
3 5 2 4 1
1 2 3 4 5
5 2 4 1 3
3 4 5 1 2
2 3 4 5 1
1 3 5 2 4
4 1 3 5 2
2 4 1 3 5
5 1 2 3 4
6
2 3 4 5 6 1
3 1 2 6 4 5
6 1 2 3 4 5
5 6 1 3 2 4
4 3 6 5 2 1
5 6 1 2 3 4
4 5 6 1 2 3
3 4 5 6 1 2
1 2 3 4 5 6
2 5 4 1 6 3
3 2 5 4 1 6
1 4 3 6 5 2
```
### Output


```text
1
1 2 3 4 5 6 7
2
1 3 5 6 10
4
1 3 6 7 8 9
```
## Note

In the first test case, the number of good subsets is $1$. The only such subset is the set of arrays with indices $1$, $2$, $3$, $4$, $5$, $6$, $7$.

In the second test case, the number of good subsets is $2$. They are $1$, $3$, $5$, $6$, $10$ or $2$, $4$, $7$, $8$, $9$.



#### Tags 

#2800 #NOT OK #2-sat #brute_force #combinatorics #constructive_algorithms #graph_matchings #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Round_732_(Div._1).md)
- [Codeforces Round #732 (en)](../blogs/Codeforces_Round_732_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
