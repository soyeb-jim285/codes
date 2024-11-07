<h1 style='text-align: center;'> E. Colored Balls</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* boxes with colored balls on the table. Colors are numbered from 1 to *n*. *i*-th box contains *a**i* balls, all of which have color *i*. You have to write a program that will divide all balls into sets such that:

* each ball belongs to exactly one of the sets,
* there are no empty sets,
* there is no set containing two (or more) balls of different colors (each set contains only balls of one color),
* there are no two sets such that the difference between their sizes is greater than 1.

Print the minimum possible number of sets.

## Input

The first line contains one integer number *n* (1 ≤ *n* ≤ 500).

The second line contains *n* integer numbers *a*1, *a*2, ... , *a**n* (1 ≤ *a**i* ≤ 109).

## Output

Print one integer number — the minimum possible number of sets.

## Examples

## Input


```
3  
4 7 8  

```
## Output


```
5  

```
## Input


```
2  
2 7  

```
## Output


```
4  

```
## Note

In the first example the balls can be divided into sets like that: one set with 4 balls of the first color, two sets with 3 and 4 balls, respectively, of the second color, and two sets with 4 balls of the third color.



#### tags 

#2500 #greedy #math #number_theory 