<h1 style='text-align: center;'> H. Twin Friends</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You meet two new friends who are twins. The name of the elder twin is $A$, which consists of $N$ characters. While the name of the younger twin is $B$, which consists of $M$ characters. It is known that $N \leq M$.

You want to call each of them with a nickname. For the elder twin, you want to pick any permutation of $A$ as the nickname. For the younger twin, you want to remove exactly $M - N$ characters from any permutation of $B$. Denote the nicknames of the elder twin and the younger twin as $A'$ and $B'$, respectively.

You want the nicknames to satisfy the following requirement. For each $i$ that satisfies $1 \leq i \leq N$, $B'_i$ must be equal to either $A'_i$ or the next letter that follows alphabetically after $A'_i$ (if such a next letter exists).

Determine the number of different pairs of nicknames $(A', B')$ that satisfy the requirement. Two pairs of nicknames are considered different if at least one of the nicknames are different. As the result might be large, find the answer modulo $998\,244\,353$.

###### Input

The first line consists of two integers $N$ $M$ ($1 \leq N \leq M \leq 200\,000$).

The second line consists of a string $A$ of length $N$.

The third line consists of a string $B$ of length $M$.

All strings consist of only upper-case letters.

###### Output

###### Output

 a single integer representing number of different pairs $(A', B')$ that satisfy the requirement, modulo $998\,244\,353$.

## Examples

###### Input


```text
3 4
AMA
ANAB
```
###### Output


```text
9
```
###### Input


```text
5 8
BINUS
BINANUSA
```
###### Output


```text
120
```
###### Input


```text
15 30
BINUSUNIVERSITY
BINANUSANTARAUNIVERSITYJAKARTA
```
###### Output


```text
151362308
```
###### Input


```text
4 4
UDIN
ASEP
```
###### Output


```text
0
```
## Note

Explanation for the sample input/output #1

The $9$ pairs are:

* (AAM, AAN),
* (AAM, ABN),
* (AAM, BAN),
* (AMA, ANA),
* (AMA, ANB),
* (AMA, BNA),
* (MAA, NAA),
* (MAA, NAB), and
* (MAA, NBA).

Explanation for the sample input/output #2

The $120$ pairs are the pairs where $A'$ is a permutation of BINUS and $B' = A'$.



#### Tags 

#2200 #NOT OK #combinatorics #dp 

## Blogs
- [All Contest Problems](../2023-2024_ICPC,_Asia_Jakarta_Regional_Contest_(Online_Mirror,_Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
