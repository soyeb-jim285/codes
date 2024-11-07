<h1 style='text-align: center;'> E. Swap and Take</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You're given an array consisting of $n$ integers. You have to perform $n$ turns.

Initially your score is $0$.

On the $i$-th turn, you are allowed to leave the array as it is or swap any one pair of $2$ adjacent elements in the array and change exactly one of them to $0$(and leave the value of other element unchanged) after swapping. In either case(whether you swap or not), after this you add $a_i$ to your score. 

What's the maximum possible score you can get?

#### Input

The first line contains a single integer $n$ ($2 \le n \le 500$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^6$).

#### Output

Print a single integer — the maximum possible score.

## Examples

#### Input


```text
2
3 1
```
#### Output


```text
6
```
#### Input


```text
5
7 3 9 6 12
```
#### Output


```text
52
```
## Note

In the first example, to get the maximum score we do as follows. Do nothing on the first turn, add $3$ to the score. Swap the first and the second elements and turn $1$ to $0$ on the second turn, and add $3$ to the score. The final score is $6$.



#### Tags 

#2600 #NOT OK #dp #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_825_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
