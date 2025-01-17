<h1 style='text-align: center;'> A. Valera and Plates</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Valera is a lazy student. He has *m* clean bowls and *k* clean plates. 

Valera has made an eating plan for the next *n* days. As Valera is lazy, he will eat exactly one dish per day. At that, in order to eat a dish, he needs exactly one clean plate or bowl. We know that Valera can cook only two types of dishes. He can eat dishes of the first type from bowls and dishes of the second type from either bowls or plates. 

When Valera finishes eating, he leaves a dirty plate/bowl behind. His life philosophy doesn't let him eat from dirty kitchenware. So sometimes he needs to wash his plate/bowl before eating. Find the minimum number of times Valera will need to wash a plate/bowl, if he acts optimally.

## Input

The first line of the input contains three integers *n*, *m*, *k* (1 ≤ *n*, *m*, *k* ≤ 1000) — the number of the planned days, the number of clean bowls and the number of clean plates.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 2). If *a**i* equals one, then on day *i* Valera will eat a first type dish. If *a**i* equals two, then on day *i* Valera will eat a second type dish. 

## Output

Print a single integer — the minimum number of times Valera will need to wash a plate/bowl.

## Examples

## Input


```
3 1 1  
1 2 1  

```
## Output


```
1  

```
## Input


```
4 3 1  
1 1 1 1  

```
## Output


```
1  

```
## Input


```
3 1 2  
2 2 2  

```
## Output


```
0  

```
## Input


```
8 2 2  
1 2 1 2 1 2 1 2  

```
## Output


```
4  

```
## Note

In the first sample Valera will wash a bowl only on the third day, so the answer is one.

In the second sample, Valera will have the first type of the dish during all four days, and since there are only three bowls, he will wash a bowl exactly once.

In the third sample, Valera will have the second type of dish for all three days, and as they can be eaten from either a plate or a bowl, he will never need to wash a plate/bowl.



#### tags 

#900 #greedy #implementation 