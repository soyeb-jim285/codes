<h1 style='text-align: center;'> D. Lizard Era: Beginning</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the game Lizard Era: Beginning the protagonist will travel with three companions: Lynn, Meliana and Worrigan. Overall the game has *n* mandatory quests. To perform each of them, you need to take exactly two companions.

The attitude of each of the companions to the hero is an integer. Initially, the attitude of each of them to the hero of neutral and equal to 0. As the hero completes quests, he makes actions that change the attitude of the companions, whom he took to perform this task, in positive or negative direction.

Tell us what companions the hero needs to choose to make their attitude equal after completing all the quests. If this can be done in several ways, choose the one in which the value of resulting attitude is greatest possible.

## Input

The first line contains positive integer *n* (1 ≤ *n* ≤ 25) — the number of important tasks. 

Next *n* lines contain the descriptions of the tasks — the *i*-th line contains three integers *l**i*, *m**i*, *w**i* — the values by which the attitude of Lynn, Meliana and Worrigan respectively will change towards the hero if the hero takes them on the *i*-th task. All the numbers in the input are integers and do not exceed 107 in absolute value.

## Output

If there is no solution, print in the first line "Impossible".

Otherwise, print *n* lines, two characters is each line — in the *i*-th line print the first letters of the companions' names that hero should take to complete the *i*-th task ('L' for Lynn, 'M' for Meliana, 'W' for Worrigan). Print the letters in any order, if there are multiple solutions, print any of them.

## Examples

## Input


```
3  
1 0 0  
0 1 0  
0 0 1  

```
## Output


```
LM  
MW  
MW  

```
## Input


```
7  
0 8 9  
5 9 -2  
6 -8 -7  
9 4 5  
-4 -9 9  
-4 5 2  
-6 8 -7  

```
## Output


```
LM  
MW  
LM  
LW  
MW  
LM  
LW  

```
## Input


```
2  
1 0 0  
1 1 0  

```
## Output


```
Impossible  

```


#### tags 

#2300 #meet-in-the-middle 