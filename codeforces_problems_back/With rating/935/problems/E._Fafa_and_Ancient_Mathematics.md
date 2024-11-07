<h1 style='text-align: center;'> E. Fafa and Ancient Mathematics</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ancient Egyptians are known to have understood difficult concepts in mathematics. The ancient Egyptian mathematician Ahmes liked to write a kind of arithmetic expressions on papyrus paper which he called as Ahmes arithmetic expression.

An Ahmes arithmetic expression can be defined as: 

* "*d*" is an Ahmes arithmetic expression, where *d* is a one-digit positive integer;
* "(*E*1 *op* *E*2)" is an Ahmes arithmetic expression, where *E*1 and *E*2 are valid Ahmes arithmetic expressions (without spaces) and *op* is either plus ( + ) or minus ( - ).

 For example 5, (1-1) and ((1+(2-3))-5) are valid Ahmes arithmetic expressions.On his trip to Egypt, Fafa found a piece of papyrus paper having one of these Ahmes arithmetic expressions written on it. Being very ancient, the papyrus piece was very worn out. As a result, all the operators were erased, keeping only the numbers and the brackets. Since Fafa loves mathematics, he decided to challenge himself with the following task:

Given the number of plus and minus operators in the original expression, find out the maximum possible value for the expression on the papyrus paper after putting the plus and minus operators in the place of the original erased operators.

## Input

The first line contains a string *E* (1 ≤ |*E*| ≤ 104) — a valid Ahmes arithmetic expression. All operators are erased and replaced with '?'.

The second line contains two space-separated integers *P* and *M* (0 ≤ *min*(*P*, *M*) ≤ 100) — the number of plus and minus operators, respectively. 

It is guaranteed that *P* + *M* =  the number of erased operators.

## Output

Print one line containing the answer to the problem.

## Examples

## Input


```
(1?1)  
1 0  

```
## Output


```
2  

```
## Input


```
(2?(1?2))  
1 1  

```
## Output


```
1  

```
## Input


```
((1?(5?7))?((6?2)?7))  
3 2  

```
## Output


```
18  

```
## Input


```
((1?(5?7))?((6?2)?7))  
2 3  

```
## Output


```
16  

```
## Note

* The first sample will be (1 + 1)  =  2.
* The second sample will be (2 + (1 - 2))  =  1.
* The third sample will be ((1 - (5 - 7)) + ((6 + 2) + 7))  =  18.
* The fourth sample will be ((1 + (5 + 7)) - ((6 - 2) - 7))  =  16.


#### tags 

#2300 #dfs_and_similar #dp #trees 