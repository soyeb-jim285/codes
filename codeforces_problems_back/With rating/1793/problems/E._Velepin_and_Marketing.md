<h1 style='text-align: center;'> E. Velepin and Marketing</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The famous writer Velepin is very productive. Recently, he signed a contract with a well-known publication and now he needs to write $k_i$ books for $i$-th year. This is not a problem for him at all, he can write as much as he wants about samurai, space, emptiness, insects and werewolves.

He has $n$ regular readers, each of whom in the $i$-th year will read one of the $k_i$ books published by Velepin. Readers are very fond of discussing books, so the $j$-th of them will be satisfied within a year if at least $a_j$ persons read the same book as him (including himself).

Velepin has obvious problems with marketing, so he turned to you! A well-known book reading service can control what each of Velepin's regular readers will read, but he does not want books to be wasted, so someone should read each book. And so they turned to you with a request to tell you what the maximum number of regular readers can be made satisfied during each of the years, if you can choose each person the book he will read.

## Input

The first line contains a single integer $n$ $(2 \le n \le 3 \cdot 10^5)$ — the number of regular readers of Velepin.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ $(1 \le a_i \le n)$ — the number of necessary readers of the same book for the happiness of the $i$-th person.

The third line contains a single integer $q$ $(1 \le q \le 3 \cdot 10^5)$ — the number of years to analyze.

Each of the following $q$ lines contains a single integer $k_j$ $(2 \le k_j \le n)$ — the number of books that Velepin must write in $j$-th a year.

## Output

Print $q$ lines, each of them has exactly one number — the maximum number of people who can be satisfied in $j$-th a year if Velepin releases $k_j$ books.

## Examples

## Input


```

5
1 2 2 2 2
3
2
3
4

```
## Output


```

5
5
3

```
## Input


```

6
1 2 3 4 5 6
2
2
3

```
## Output


```

5
4

```
## Input


```

6
4 4 1 4 4 4
3
2
3
4

```
## Output


```

6
5
1

```
## Note

In the first example, in the first year, the optimal division is $1, 2, 2, 2, 2$ (the first book is read by the first person, and everyone else reads the second). In the second year, the optimal solution is $1, 2, 2, 3, 3$ (the first book is read by the first person, the second book is read by the second and third person, and all the others read the third book). In the third year, the optimal split will be $1, 2, 3, 4, 2$. Accordingly, the number of satisfied people over the years will be $5, 5, 3$.

In the second example, in the first year, the optimal division is $1, 1, 1, 1, 1, 2$, then everyone will be happy except the $6$-th person. In the second year, the optimal division is $1, 1, 1, 1, 2, 3$, then everyone will be happy except the $5$-th and $6$-th person.



#### tags 

#2600 #binary_search #data_structures #dp #greedy #sortings #two_pointers 