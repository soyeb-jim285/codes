<h1 style='text-align: center;'> D. Potion Brewing Class</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice's potion making professor gave the following assignment to his students: brew a potion using $n$ ingredients, such that the proportion of ingredient $i$ in the final potion is $r_i > 0$ (and $r_1 + r_2 + \cdots + r_n = 1$).

He forgot the recipe, and now all he remembers is a set of $n-1$ facts of the form, "ingredients $i$ and $j$ should have a ratio of $x$ to $y$" (i.e., if $a_i$ and $a_j$ are the amounts of ingredient $i$ and $j$ in the potion respectively, then it must hold $a_i/a_j = x/y$), where $x$ and $y$ are positive integers. However, it is guaranteed that the set of facts he remembers is sufficient to uniquely determine the original values $r_i$.

He decided that he will allow the students to pass the class as long as they submit a potion which satisfies all of the $n-1$ requirements (there may be many such satisfactory potions), and contains a positive integer amount of each ingredient.

Find the minimum total amount of ingredients needed to make a potion which passes the class. As the result can be very large, you should print the answer modulo $998\,244\,353$.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$).

Each of the next $n-1$ lines contains four integers $i, j, x, y$ ($1 \le i, j \le n$, $i\not=j$, $1\le x, y \le n$) — ingredients $i$ and $j$ should have a ratio of $x$ to $y$. It is guaranteed that the set of facts is sufficient to uniquely determine the original values $r_i$.

It is also guaranteed that the sum of $n$ for all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print the minimum total amount of ingredients needed to make a potion which passes the class, modulo $998\,244\,353$.

## Example

## Input


```

343 2 3 41 2 4 31 4 2 485 4 2 36 4 5 41 3 5 26 8 2 13 5 3 43 2 2 56 7 4 3178 7 4 169 17 4 55 14 13 1211 1 17 146 13 8 92 11 3 114 17 7 217 16 8 615 5 1 1416 7 1 1012 17 13 1011 16 7 210 11 6 413 17 14 63 11 15 815 6 12 8
```
## Output


```

69
359
573672453

```
## Note

In the first test case, the minimum total amount of ingredients is $69$. In fact, the amounts of ingredients $1, 2, 3, 4$ of a valid potion are $16, 12, 9, 32$, respectively. The potion is valid because 

* Ingredients $3$ and $2$ have a ratio of $9 : 12 = 3 : 4$;
* Ingredients $1$ and $2$ have a ratio of $16 : 12 = 4 : 3$;
* Ingredients $1$ and $4$ have a ratio of $16 : 32 = 2 : 4$.

In the second test case, the amounts of ingredients $1, 2, 3, 4, 5, 6, 7, 8$ in the potion that minimizes the total amount of ingredients are $60, 60, 24, 48, 32, 60, 45, 30$.



#### tags 

#2100 #dfs_and_similar #math #number_theory #trees 