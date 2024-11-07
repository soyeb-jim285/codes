<h1 style='text-align: center;'> C. Developing Skills</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya loves computer games. Finally a game that he's been waiting for so long came out!

The main character of this game has *n* different skills, each of which is characterized by an integer *a**i* from 0 to 100. The higher the number *a**i* is, the higher is the *i*-th skill of the character. The total rating of the character is calculated as the sum of the values ​​of ![](images/1e2dcd02b35f0f5420e94c575edfd8c59edc9fca.png) for all *i* from 1 to *n*. The expression ⌊ *x*⌋ denotes the result of rounding the number *x* down to the nearest integer.

At the beginning of the game Petya got *k* improvement units as a bonus that he can use to increase the skills of his character and his total rating. One improvement unit can increase any skill of Petya's character by exactly one. For example, if *a*4 = 46, after using one imporvement unit to this skill, it becomes equal to 47. A hero's skill cannot rise higher more than 100. Thus, it is permissible that some of the units will remain unused.

Your task is to determine the optimal way of using the improvement units so as to maximize the overall rating of the character. It is not necessary to use all the improvement units.

## Input

The first line of the input contains two positive integers *n* and *k* (1 ≤ *n* ≤ 105, 0 ≤ *k* ≤ 107) — the number of skills of the character and the number of units of improvements at Petya's disposal.

The second line of the input contains a sequence of *n* integers *a**i* (0 ≤ *a**i* ≤ 100), where *a**i* characterizes the level of the *i*-th skill of the character.

## Output

The first line of the output should contain a single non-negative integer — the maximum total rating of the character that Petya can get using *k* or less improvement units.

## Examples

## Input


```
2 4  
7 9  

```
## Output


```
2  

```
## Input


```
3 8  
17 15 19  

```
## Output


```
5  

```
## Input


```
2 2  
99 100  

```
## Output


```
20  

```
## Note

In the first test case the optimal strategy is as follows. Petya has to improve the first skill to 10 by spending 3 improvement units, and the second skill to 10, by spending one improvement unit. Thus, Petya spends all his improvement units and the total rating of the character becomes equal to  *lfloor* *frac*{100}{10} *rfloor* +  *lfloor* *frac*{100}{10} *rfloor* = 10 + 10 =  20.

In the second test the optimal strategy for Petya is to improve the first skill to 20 (by spending 3 improvement units) and to improve the third skill to 20 (in this case by spending 1 improvement units). Thus, Petya is left with 4 improvement units and he will be able to increase the second skill to 19 (which does not change the overall rating, so Petya does not necessarily have to do it). Therefore, the highest possible total rating in this example is ![](images/ccaa4e1e435ea3a339c322e03a32de69d214a257.png).

In the third test case the optimal strategy for Petya is to increase the first skill to 100 by spending 1 improvement unit. Thereafter, both skills of the character will be equal to 100, so Petya will not be able to spend the remaining improvement unit. So the answer is equal to ![](images/b246630ca7d1b95b91970759bd8455cb3e930bf9.png). 



#### tags 

#1400 #implementation #math #sortings 