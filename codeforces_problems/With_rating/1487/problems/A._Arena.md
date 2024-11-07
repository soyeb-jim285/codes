<h1 style='text-align: center;'> A. Arena</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

$n$ heroes fight against each other in the Arena. Initially, the $i$-th hero has level $a_i$.

Each minute, a fight between two different heroes occurs. These heroes can be chosen arbitrarily (it's even possible that it is the same two heroes that were fighting during the last minute).

When two heroes of equal levels fight, nobody wins the fight. When two heroes of different levels fight, the one with the higher level wins, and his level increases by $1$.

The winner of the tournament is the first hero that wins in at least $100^{500}$ fights (note that it's possible that the tournament lasts forever if no hero wins this number of fights, then there is no winner). A possible winner is a hero such that there exists a sequence of fights that this hero becomes the winner of the tournament.

Calculate the number of possible winners among $n$ heroes.

### Input

The first line contains one integer $t$ ($1 \le t \le 500$) — the number of test cases.

Each test case consists of two lines. The first line contains one integer $n$ ($2 \le n \le 100$) — the number of heroes. The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 100$), where $a_i$ is the initial level of the $i$-th hero.

### Output

For each test case, print one integer — the number of possible winners among the given $n$ heroes.

## Example

### Input


```text
3
3
3 2 2
2
5 5
4
1 3 3 7
```
### Output


```text
1
0
3
```
## Note

In the first test case of the example, the only possible winner is the first hero.

In the second test case of the example, each fight between the heroes results in nobody winning it, so the tournament lasts forever and there is no winner.



#### Tags 

#800 #NOT OK #implementation #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_104_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
