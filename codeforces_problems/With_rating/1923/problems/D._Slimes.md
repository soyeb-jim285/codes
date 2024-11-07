<h1 style='text-align: center;'> D. Slimes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ slimes placed in a line. The slimes are numbered from $1$ to $n$ in order from left to right. The size of the $i$-th slime is $a_i$.

Every second, the following happens: exactly one slime eats one of its neighbors and increases its size by the eaten neighbor's size. A slime can eat its neighbor only if it is strictly bigger than this neighbor. If there is no slime which is strictly bigger than one of its neighbors, the process ends.

For example, suppose $n = 5$, $a = [2, 2, 3, 1, 4]$. The process can go as follows:

* first, the $3$-rd slime eats the $2$-nd slime. The size of the $3$-rd slime becomes $5$, the $2$-nd slime is eaten.
* then, the $3$-rd slime eats the $1$-st slime (they are neighbors since the $2$-nd slime is already eaten). The size of the $3$-rd slime becomes $7$, the $1$-st slime is eaten.
* then, the $5$-th slime eats the $4$-th slime. The size of the $5$-th slime becomes $5$, the $4$-th slime is eaten.
* then, the $3$-rd slime eats the $5$-th slime (they are neighbors since the $4$-th slime is already eaten). The size of the $3$-rd slime becomes $12$, the $5$-th slime is eaten.

For each slime, calculate the minimum number of seconds it takes for this slime to be eaten by another slime (among all possible ways the process can go), or report that it is impossible.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 3 \cdot 10^5$) — the number of slimes.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$).

The sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

### Output

For each test case, print $n$ integers. The $i$-th integer should be equal to the minimum number of seconds it takes for the $i$-th slime to be eaten by another slime or -1 if it is impossible.

## Example

### Input


```text
443 2 4 231 2 352 2 3 1 174 2 3 6 1 1 8
```
### Output

```text

2 1 2 1 
1 1 -1 
2 1 -1 1 2 
2 1 1 3 1 1 4 

```


#### Tags 

#1800 #OK #binary_search #constructive_algorithms #data_structures #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_162_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
