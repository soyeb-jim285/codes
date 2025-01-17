<h1 style='text-align: center;'> D. Swords</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There were $n$ types of swords in the theater basement which had been used during the plays. Moreover there were exactly $x$ swords of each type. $y$ people have broken into the theater basement and each of them has taken exactly $z$ swords of some single type. 
## Note

 that different people might have taken different types of swords. 
## Note

 that the values $x, y$ and $z$ are unknown for you.

The next morning the director of the theater discovers the loss. He counts all swords — exactly $a_i$ swords of the $i$-th type are left untouched.

The director has no clue about the initial number of swords of each type in the basement, the number of people who have broken into the basement and how many swords each of them have taken.

For example, if $n=3$, $a = [3, 12, 6]$ then one of the possible situations is $x=12$, $y=5$ and $z=3$. Then the first three people took swords of the first type and the other two people took swords of the third type. 
## Note

 that you don't know values $x, y$ and $z$ beforehand but know values of $n$ and $a$.

Thus he seeks for your help. Determine the minimum number of people $y$, which could have broken into the theater basement, and the number of swords $z$ each of them has taken.

###### Input

The first line of the input contains one integer $n$ $(2 \le n \le 2 \cdot 10^{5})$ — the number of types of swords.

The second line of the input contains the sequence $a_1, a_2, \dots, a_n$ $(0 \le a_i \le 10^{9})$, where $a_i$ equals to the number of swords of the $i$-th type, which have remained in the basement after the theft. It is guaranteed that there exists at least one such pair of indices $(j, k)$ that $a_j \neq a_k$.

###### Output

Print two integers $y$ and $z$ — the minimum number of people which could have broken into the basement and the number of swords each of them has taken.

## Examples

###### Input


```text
3
3 12 6
```
###### Output


```text
5 3
```
###### Input


```text
2
2 9
```
###### Output


```text
1 7
```
###### Input


```text
7
2 1000000000 4 6 8 4 2
```
###### Output


```text
2999999987 2
```
###### Input


```text
6
13 52 0 13 26 52
```
###### Output


```text
12 13
```
## Note

In the first example the minimum value of $y$ equals to $5$, i.e. the minimum number of people who could have broken into the basement, is $5$. Each of them has taken $3$ swords: three of them have taken $3$ swords of the first type, and two others have taken $3$ swords of the third type.

In the second example the minimum value of $y$ is $1$, i.e. the minimum number of people who could have broken into the basement, equals to $1$. He has taken $7$ swords of the first type.



#### Tags 

#1300 #NOT OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_587_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
