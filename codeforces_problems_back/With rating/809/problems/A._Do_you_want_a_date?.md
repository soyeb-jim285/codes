<h1 style='text-align: center;'> A. Do you want a date?</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Leha decided to move to a quiet town Vičkopolis, because he was tired by living in Bankopolis. Upon arrival he immediately began to expand his network of hacked computers. During the week Leha managed to get access to *n* computers throughout the town. Incidentally all the computers, which were hacked by Leha, lie on the same straight line, due to the reason that there is the only one straight street in Vičkopolis.

Let's denote the coordinate system on this street. Besides let's number all the hacked computers with integers from 1 to *n*. So the *i*-th hacked computer is located at the point *x**i*. Moreover the coordinates of all computers are distinct. 

Leha is determined to have a little rest after a hard week. Therefore he is going to invite his friend Noora to a restaurant. However the girl agrees to go on a date with the only one condition: Leha have to solve a simple task.

Leha should calculate a sum of *F*(*a*) for all *a*, where *a* is a non-empty subset of the set, that consists of all hacked computers. Formally, let's denote *A* the set of all integers from 1 to *n*. Noora asks the hacker to find value of the expression ![](images/c34dec8c1b7fcd87d979d9ee754ed6bccf74dbaf.png). Here *F*(*a*) is calculated as the maximum among the distances between all pairs of computers from the set *a*. Formally, ![](images/27a60caeac865f8d46f6a4e1f522eacb08256443.png). Since the required sum can be quite large Noora asks to find it modulo 109 + 7.

Though, Leha is too tired. Consequently he is not able to solve this task. Help the hacker to attend a date.

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 3·105) denoting the number of hacked computers.

The second line contains *n* integers *x*1, *x*2, ..., *x**n* (1 ≤ *x**i* ≤ 109) denoting the coordinates of hacked computers. It is guaranteed that all *x**i* are distinct.

## Output

Print a single integer — the required sum modulo 109 + 7.

## Examples

## Input


```
2  
4 7  

```
## Output


```
3  

```
## Input


```
3  
4 3 1  

```
## Output


```
9  

```
## Note

There are three non-empty subsets in the first sample test:![](images/02b2d12556dad85f1c6c6912786eb87d4be2ea17.png), ![](images/22f6a537962c86b3e28ddb8aaca28a7cdd219a8c.png) and ![](images/7d0f73b3e94e13cb797f39e93d9da74835c5a02d.png). The first and the second subset increase the sum by 0 and the third subset increases the sum by 7 - 4 = 3. In total the answer is 0 + 0 + 3 = 3.

There are seven non-empty subsets in the second sample test. Among them only the following subsets increase the answer: ![](images/f368c407c8e85e2b5fedfffaff39d471d765f026.png), ![](images/bb8f2118a3ac352db393b1f067b28e398ce7f816.png), ![](images/049032074c04b16bc0cc153f95471c40b222072b.png), ![](images/dc93c7f5b3d122314c9c5a707fae556a8f72a574.png). In total the sum is (4 - 3) + (4 - 1) + (3 - 1) + (4 - 1) = 9.



#### tags 

#1500 #implementation #math #sortings 