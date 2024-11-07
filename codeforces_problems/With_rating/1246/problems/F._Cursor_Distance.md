<h1 style='text-align: center;'> F. Cursor Distance</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There is a string $s$ of lowercase English letters. A cursor is positioned on one of the characters. The cursor can be moved with the following operation: choose a letter $c$ and a direction (left or right). The cursor is then moved to the closest occurence of $c$ in the chosen direction. If there is no letter $c$ in that direction, the cursor stays in place. For example, if $s = \mathtt{abaab}$ with the cursor on the second character ($\mathtt{a[b]aab}$), then:

* moving to the closest letter $\mathtt{a}$ to the left places the cursor on the first character ($\mathtt{[a]baab}$);
* moving to the closest letter $\mathtt{a}$ to the right places the cursor the third character ($\mathtt{ab[a]ab}$);
* moving to the closest letter $\mathtt{b}$ to the right places the cursor on the fifth character ($\mathtt{abaa[b]}$);
* any other operation leaves the cursor in place.

Let $\mathrm{dist}(i, j)$ be the smallest number of operations needed to move the cursor from the $i$-th character to the $j$-th character. Compute $\displaystyle \sum_{i = 1}^n \sum_{j = 1}^n \mathrm{dist}(i, j)$.

#### Input

The only line contains a non-empty string $s$ of at most $10^5$ lowercase English letters.

#### Output

Print a single integer $\displaystyle \sum_{i = 1}^n \sum_{j = 1}^n \mathrm{dist}(i, j)$.

## Examples

#### Input


```text
abcde
```
#### Output


```text
20
```
#### Input


```text
abacaba
```
#### Output


```text
58
```
## Note

In the first sample case, $\mathrm{dist}(i, j) = 0$ for any pair $i = j$, and $1$ for all other pairs.



#### Tags 

#3500 #NOT OK 

## Blogs
- [All Contest Problems](../Codeforces_Round_596_(Div._1,_based_on_Technocup_2020_Elimination_Round_2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
