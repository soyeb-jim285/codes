<h1 style='text-align: center;'> E. Double Permutation Inc.</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp recently became an employee of the company "Double Permutation Inc." Now he is a fan of permutations and is looking for them everywhere!

A permutation in this problem is a sequence of integers $p_1, p_2, \dots, p_k$ such that every integer from $1$ to $k$ occurs exactly once in it. For example, the following sequences are permutations of $[3, 1, 4, 2]$, $[1]$ and $[6, 1, 2, 3, 5, 4]$. The following sequences are not permutations: $[0, 1]$, $[1, 2, 2]$, $[1, 2, 4]$ and $[2, 3]$.

In the lobby of the company's headquarter statistics on visits to the company's website for the last $n$ days are published — the sequence $a_1, a_2, \dots, a_n$. Polycarp wants to color all the elements of this sequence in one of three colors (red, green or blue) so that:

* all red numbers, being written out of $a_1, a_2, \dots, a_n$ from left to right (that is, without changing their relative order), must form some permutation (let's call it $P$);
* all green numbers, being written out of $a_1, a_2, \dots, a_n$ from left to right (that is, without changing their relative order), must form the same permutation $P$;
* among blue numbers there should not be elements that are equal to some element of the permutation $P$.

Help Polycarp to color all $n$ numbers so that the total number of red and green elements is maximum.

###### Input

The first line contains an integer $n$ ($1 \le n \le 2\cdot10^5$) — the length of the sequence $a$. The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 2\cdot10^5$).

###### Output

Print a string $s$ of length $n$ such that:

* $s_i$='R', if the element $a_i$ must be colored in red;
* $s_i$='G', if the element $a_i$ must be colored in green;
* $s_i$='B', if the element $a_i$ must be colored in blue.

The string $s$ should maximize the total number of red and green elements when fulfilling the requirements from the main part of the problem statement. If there are several optimal answers, print any of them.

## Examples

###### Input


```text
5
1 2 3 2 1
```
###### Output


```text
RBBBG
```
###### Input


```text
3
1 1 1
```
###### Output


```text
BBB
```
###### Input


```text
10
3 3 2 2 5 4 1 5 4 1
```
###### Output


```text
RGRGRRRGGG
```
###### Input


```text
10
3 9 3 1 2 1 2 4 4 4
```
###### Output


```text
RBGRRGGBBB
```


#### Tags 

#2000 #NOT OK #*special #binary_search #greedy 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_2.md)
- [Kotlin Heroes: Episode 2 (en)](../blogs/Kotlin_Heroes:_Episode_2_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
