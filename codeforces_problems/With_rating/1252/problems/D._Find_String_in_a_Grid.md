<h1 style='text-align: center;'> D. Find String in a Grid</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a grid $G$ containing $R$ rows (numbered from $1$ to $R$, top to bottom) and $C$ columns (numbered from $1$ to $C$, left to right) of uppercase characters. The character in the $r^{th}$ row and the $c^{th}$ column is denoted by $G_{r, c}$. You also have $Q$ strings containing uppercase characters. For each of the string, you want to find the number of occurrences of the string in the grid.

An occurrence of string $S$ in the grid is counted if $S$ can be constructed by starting at one of the cells in the grid, going right $0$ or more times, and then going down $0$ or more times. Two occurrences are different if the set of cells used to construct the string is different. Formally, for each string $S$, you would like to count the number of tuples $\langle r, c, \Delta r, \Delta c \rangle$ such that: 

* $1 \le r \le R$ and $r \le r + \Delta r \le R$
* $1 \le c \le C$ and $c \le c + \Delta c \le C$
* $S = G_{r, c} G_{r, c + 1} \dots G_{r, c + \Delta c} G_{r + 1, c + \Delta c} \dots G_{r + \Delta r, c + \Delta c}$
#### Input

#### Input

 begins with a line containing three integers: $R$ $C$ $Q$ ($1 \le R, C \le 500$; $1 \le Q \le 200\,000$) representing the size of the grid and the number of strings, respectively. The next $R$ lines each contains $C$ uppercase characters representing the grid. The $c^{th}$ character on the $r^{th}$ line is $G_{r, c}$. The next $Q$ lines each contains a string $S$ containing uppercase characters. The length of this string is a positive integer not more than $200\,000$. The sum of the length of all $Q$ strings combined is not more than $200\,000$.

#### Output

For each query in the same order as input, output in a line an integer representing the number of occurrences of the string in the grid.

## Examples

#### Input


```text
3 3 5
ABC
BCD
DAB
ABC
BC
BD
AC
A
```
#### Output


```text
2
3
1
0
2
```
#### Input


```text
2 3 3
AAA
AAA
A
AAA
AAAAA
```
#### Output


```text
6
4
0
```
## Note

Explanation for the sample input/output #1

* There are $2$ occurrences of "ABC", represented by the tuples $\langle 1, 1, 1, 1 \rangle$ and $\langle 1, 1, 0, 2 \rangle$.
* There are $3$ occurrences of "BC", represented by the tuples $\langle 1, 2, 0, 1 \rangle$, $\langle 1, 2, 1, 0 \rangle$, and $\langle 2, 1, 0, 1 \rangle$.
* There is $1$ occurrence of "BD", represented by the tuple $\langle 2, 1, 1, 0 \rangle$.
* There is no occurrence of "AC".
* There are $2$ occurrences of "A", represented by the tuples $\langle 1, 1, 0, 0 \rangle$ and $\langle 3, 2, 0, 0 \rangle$.


#### Tags 

#3000 #NOT OK #data_structures #dp #strings #trees 

## Blogs
- [All Contest Problems](../2019-2020_ICPC,_Asia_Jakarta_Regional_Contest_(Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
