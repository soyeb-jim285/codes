<h1 style='text-align: center;'> F. Little Artem and 2-SAT</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Artem is a very smart programmer. He knows many different difficult algorithms. Recently he has mastered in 2-SAT one.

In computer science, 2-satisfiability (abbreviated as 2-SAT) is the special case of the problem of determining whether a conjunction (logical AND) of disjunctions (logical OR) have a solution, in which all disjunctions consist of no more than two arguments (variables). For the purpose of this problem we consider only 2-SAT formulas where each disjunction consists of exactly two arguments.

Consider the following 2-SAT problem as an example: ![](images/601704e7df7a37d9164f79c37cca99967e8cd046.png). ## Note

 that there might be negations in 2-SAT formula (like for *x*1 and for *x*4).

Artem now tries to solve as many problems with 2-SAT as possible. He found a very interesting one, which he can not solve yet. Of course, he asks you to help him. 

The problem is: given two 2-SAT formulas *f* and *g*, determine whether their sets of possible solutions are the same. Otherwise, find any variables assignment *x* such that *f*(*x*) ≠ *g*(*x*). 

## Input

The first line of the input contains three integers *n*, *m*1 and *m*2 (1 ≤ *n* ≤ 1000, 1 ≤ *m*1, *m*2 ≤ *n*2) — the number of variables, the number of disjunctions in the first formula and the number of disjunctions in the second formula, respectively.

Next *m*1 lines contains the description of 2-SAT formula *f*. The description consists of exactly *m*1 pairs of integers *x**i* ( - *n* ≤ *x**i* ≤ *n*, *x**i* ≠ 0) each on separate line, where *x**i* > 0 corresponds to the variable without negation, while *x**i* < 0 corresponds to the variable with negation. Each pair gives a single disjunction. Next *m*2 lines contains formula *g* in the similar format.

## Output

If both formulas share the same set of solutions, output a single word "SIMILAR" (without quotes). Otherwise output exactly *n* integers *x**i* (![](images/32e81dd1993925f1aa00ee976c0f800b6a7e43cd.png)) — any set of values *x* such that *f*(*x*) ≠ *g*(*x*).

## Examples

## Input


```
2 1 1  
1 2  
1 2  

```
## Output


```
SIMILAR  

```
## Input


```
2 1 1  
1 2  
1 -2  

```
## Output


```
0 0   

```
## Note

First sample has two equal formulas, so they are similar by definition.

In second sample if we compute first function with *x*1 = 0 and *x*2 = 0 we get the result 0, because ![](images/82cbca427149bc7516804c97b5963cbfddd08900.png). But the second formula is 1, because ![](images/c8a53f3cfcb77e8a34515ff1420d44e5e2c3db0b.png).



#### tags 

#3000 