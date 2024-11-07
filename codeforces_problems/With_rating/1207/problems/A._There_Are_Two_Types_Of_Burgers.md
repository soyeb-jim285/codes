<h1 style='text-align: center;'> A. There Are Two Types Of Burgers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are two types of burgers in your restaurant — hamburgers and chicken burgers! To assemble a hamburger you need two buns and a beef patty. To assemble a chicken burger you need two buns and a chicken cutlet. 

You have $b$ buns, $p$ beef patties and $f$ chicken cutlets in your restaurant. You can sell one hamburger for $h$ dollars and one chicken burger for $c$ dollars. Calculate the maximum profit you can achieve.

You have to answer $t$ independent queries.

### Input

The first line contains one integer $t$ ($1 \le t \le 100$) – the number of queries.

The first line of each query contains three integers $b$, $p$ and $f$ ($1 \le b, ~p, ~f \le 100$) — the number of buns, beef patties and chicken cutlets in your restaurant.

The second line of each query contains two integers $h$ and $c$ ($1 \le h, ~c \le 100$) — the hamburger and chicken burger prices in your restaurant.

### Output

For each query print one integer — the maximum profit you can achieve.

## Example

### Input


```text
3
15 2 3
5 10
7 5 2
10 12
1 100 100
100 100
```
### Output


```text
40
34
0
```
## Note

In first query you have to sell two hamburgers and three chicken burgers. Your income is $2 \cdot 5 + 3 \cdot 10 = 40$.

In second query you have to ell one hamburgers and two chicken burgers. Your income is $1 \cdot 10 + 2 \cdot 12 = 34$.

In third query you can not create any type of burgers because because you have only one bun. So your income is zero.



#### Tags 

#800 #NOT OK #brute_force #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_71_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
