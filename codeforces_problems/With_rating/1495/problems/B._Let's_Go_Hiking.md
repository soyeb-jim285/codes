<h1 style='text-align: center;'> B. Let's Go Hiking</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On a weekend, Qingshan suggests that she and her friend Daniel go hiking. Unfortunately, they are busy high school students, so they can only go hiking on scratch paper.

A permutation $p$ is written from left to right on the paper. First Qingshan chooses an integer index $x$ ($1\le x\le n$) and tells it to Daniel. After that, Daniel chooses another integer index $y$ ($1\le y\le n$, $y \ne x$).

The game progresses turn by turn and as usual, Qingshan moves first. The rules follow: 

* If it is Qingshan's turn, Qingshan must change $x$ to such an index $x'$ that $1\le x'\le n$, $|x'-x|=1$, $x'\ne y$, and $p_{x'}<p_x$ at the same time.
* If it is Daniel's turn, Daniel must change $y$ to such an index $y'$ that $1\le y'\le n$, $|y'-y|=1$, $y'\ne x$, and $p_{y'}>p_y$ at the same time.

The person who can't make her or his move loses, and the other wins. You, as Qingshan's fan, are asked to calculate the number of possible $x$ to make Qingshan win in the case both players play optimally.

#### Input

The first line contains a single integer $n$ ($2\le n\le 10^5$) — the length of the permutation.

The second line contains $n$ distinct integers $p_1,p_2,\dots,p_n$ ($1\le p_i\le n$) — the permutation.

#### Output

Print the number of possible values of $x$ that Qingshan can choose to make her win.

## Examples

#### Input


```text
5
1 2 5 4 3
```
#### Output


```text
1
```
#### Input


```text
7
1 2 4 6 5 3 7
```
#### Output


```text
0
```
## Note

In the first test case, Qingshan can only choose $x=3$ to win, so the answer is $1$.

In the second test case, if Qingshan will choose $x=4$, Daniel can choose $y=1$. In the first turn (Qingshan's) Qingshan chooses $x'=3$ and changes $x$ to $3$. In the second turn (Daniel's) Daniel chooses $y'=2$ and changes $y$ to $2$. Qingshan can't choose $x'=2$ because $y=2$ at this time. Then Qingshan loses.



#### Tags 

#1900 #NOT OK #games #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_706_(Div._1).md)
- [Codeforces Round #706 (en)](../blogs/Codeforces_Round_706_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
