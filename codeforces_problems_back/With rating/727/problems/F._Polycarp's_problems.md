<h1 style='text-align: center;'> F. Polycarp's problems</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp is an experienced participant in Codehorses programming contests. Now he wants to become a problemsetter.

He sent to the coordinator a set of *n* problems. Each problem has it's quality, the quality of the *i*-th problem is *a**i* (*a**i* can be positive, negative or equal to zero). The problems are ordered by expected difficulty, but the difficulty is not related to the quality in any way. The easiest problem has index 1, the hardest problem has index *n*.

The coordinator's mood is equal to *q* now. After reading a problem, the mood changes by it's quality. It means that after the coordinator reads a problem with quality *b*, the value *b* is added to his mood. The coordinator always reads problems one by one from the easiest to the hardest, it's impossible to change the order of the problems.

If after reading some problem the coordinator's mood becomes negative, he immediately stops reading and rejects the problemset.

Polycarp wants to remove the minimum number of problems from his problemset to make the coordinator's mood non-negative at any moment of time. Polycarp is not sure about the current coordinator's mood, but he has *m* guesses "the current coordinator's mood *q* = *b**i*".

For each of *m* guesses, find the minimum number of problems Polycarp needs to remove so that the coordinator's mood will always be greater or equal to 0 while he reads problems from the easiest of the remaining problems to the hardest.

## Input

The first line of input contains two integers *n* and *m* (1 ≤ *n* ≤ 750, 1 ≤ *m* ≤ 200 000) — the number of problems in the problemset and the number of guesses about the current coordinator's mood.

The second line of input contains *n* integers *a*1, *a*2, ..., *a**n* ( - 109 ≤ *a**i* ≤ 109) — the qualities of the problems in order of increasing difficulty.

The third line of input contains *m* integers *b*1, *b*2, ..., *b**m* (0 ≤ *b**i* ≤ 1015) — the guesses of the current coordinator's mood *q*.

## Output

Print *m* lines, in *i*-th line print single integer — the answer to the problem with *q* = *b**i*.

## Example

## Input


```
6 3  
8 -5 -4 1 -7 4  
0 7 3  

```
## Output


```
2  
0  
1  

```


#### tags 

#2300 #binary_search #dp #greedy 