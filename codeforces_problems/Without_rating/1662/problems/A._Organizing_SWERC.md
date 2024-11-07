<h1 style='text-align: center;'> A. Organizing SWERC</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gianni, SWERC's chief judge, received a huge amount of high quality problems from the judges and now he has to choose a problem set for SWERC.

He received $n$ problems and he assigned a beauty score and a difficulty to each of them. The $i$-th problem has beauty score equal to $b_i$ and difficulty equal to $d_i$. The beauty and the difficulty are integers between $1$ and $10$. 

If there are no problems with a certain difficulty (the possible difficulties are $1,2,\dots,10$) then Gianni will ask for more problems to the judges.

Otherwise, for each difficulty between $1$ and $10$, he will put in the problem set one of the most beautiful problems with such difficulty (so the problem set will contain exactly $10$ problems with distinct difficulties). You shall compute the total beauty of the problem set, that is the sum of the beauty scores of the problems chosen by Gianni.

### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1\le t\le 100$) — the number of test cases. The descriptions of the $t$ test cases follow.

The first line of each test case contains the integer $n$ ($1\le n\le 100$) — how many problems Gianni received from the judges.

The next $n$ lines contain two integers each. The $i$-th of such lines contains $b_i$ and $d_i$ ($1\le b_i, d_i\le 10$) — the beauty score and the difficulty of the $i$-th problem.

### Output

For each test case, print the total beauty of the problem set chosen by Gianni. If Gianni cannot create a problem set (because there are no problems with a certain difficulty) print the string MOREPROBLEMS (all letters are uppercase, there are no spaces).

## Example

### Input


```text
238 49 36 7123 1010 110 210 310 43 1010 510 610 710 810 91 10
```
### Output

```text

MOREPROBLEMS
93

```
## Note

In the first test case, Gianni has received only $3$ problems, with difficulties $3, 4, 7$ which are not sufficient to create a problem set (for example because there is not a problem with difficulty $1$).

In the second test case, Gianni will create a problem set by taking the problems $2$, $3$, $4$, $5$, $7$, $8$, $9$, $10$, $11$ (which have beauty equal to $10$ and all difficulties from $1$ to $9$) and one of the problems $1$ and $6$ (which have both beauty $3$ and difficulty $10$). The total beauty of the resulting problem set is $10\cdot 9 + 3 = 93$.



#### Tags 

#NOT OK #brute_force #implementation 

## Blogs
- [All Contest Problems](../SWERC_2021-2022_-_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [SWERC 2021-2022 (en)](../blogs/SWERC_2021-2022_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
