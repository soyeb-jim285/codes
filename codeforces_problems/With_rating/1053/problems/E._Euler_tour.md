<h1 style='text-align: center;'> E. Euler tour</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Euler is a little, cute squirrel. When the autumn comes, he collects some reserves for winter. The interesting fact is that Euler likes to collect acorns in a specific way. A tree can be described as $n$ acorns connected by $n - 1$ branches, such that there is exactly one way between each pair of acorns. Let's enumerate the acorns from $1$ to $n$.

The squirrel chooses one acorn (not necessary with number $1$) as a start, and visits them in a way called "Euler tour" (see notes), collecting each acorn when he visits it for the last time.

Today morning Kate was observing Euler. She took a sheet of paper and wrote down consecutive indices of acorns on his path. Unfortunately, during her way to home it started raining and some of numbers became illegible. Now the girl is very sad, because she has to present the observations to her teacher.

"Maybe if I guess the lacking numbers, I'll be able to do it!" she thought. Help her and restore any valid Euler tour of some tree or tell that she must have made a mistake.

##### Input

The first line contains a single integer $n$ ($1 \leq n \leq 5 \cdot 10^5$), denoting the number of acorns in the tree.

The second line contains $2n - 1$ integers $a_1, a_2, \ldots, a_{2n-1}$ ($0 \leq a_i \leq n$) — the Euler tour of the tree that Kate wrote down. $0$ means an illegible number, which has to be guessed.

##### Output

If there is no Euler tour satisfying the given description, output "no" in the first line.

Otherwise, on the first line output "yes", and then in the second line print the Euler tour which satisfy the given description.

Any valid Euler tour will be accepted, since the teacher doesn't know how exactly the initial tree looks.

## Examples

##### Input


```text
2  
1 0 0  

```
##### Output


```text
yes  
1 2 1  

```
##### Input


```text
4  
1 0 3 2 0 0 0  

```
##### Output


```text
yes  
1 4 3 2 3 4 1  

```
##### Input


```text
5  
0 1 2 3 4 1 0 0 0  

```
##### Output


```text
no  

```
## Note

An Euler tour of a tree with $n$ acorns is a sequence of $2n - 1$ indices of acorns. such that each acorn occurs at least once, the first and the last acorns are same and each two consecutive acorns are directly connected with a branch.



#### Tags 

#3500 #NOT OK #constructive_algorithms #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_512_(Div._1,_based_on_Technocup_2019_Elimination_Round_1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
