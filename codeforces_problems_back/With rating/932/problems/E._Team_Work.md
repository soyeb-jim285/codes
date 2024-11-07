<h1 style='text-align: center;'> E. Team Work</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a team of *N* people. For a particular task, you can pick any non-empty subset of people. The cost of having *x* people for the task is *x**k*. 

## Output

 the sum of costs over all non-empty subsets of people.

## Input

Only line of input contains two integers *N* (1 ≤ *N* ≤ 109) representing total number of people and *k* (1 ≤ *k* ≤ 5000).

## Output

## Output

 the sum of costs for all non empty subsets modulo 109 + 7.

## Examples

## Input


```
1 1  

```
## Output


```
1  

```
## Input


```
3 2  

```
## Output


```
24  

```
## Note

In the first example, there is only one non-empty subset {1} with cost 11 = 1.

In the second example, there are seven non-empty subsets.

- {1} with cost 12 = 1

- {2} with cost 12 = 1

- {1, 2} with cost 22 = 4

- {3} with cost 12 = 1

- {1, 3} with cost 22 = 4

- {2, 3} with cost 22 = 4

- {1, 2, 3} with cost 32 = 9

The total cost is 1 + 1 + 4 + 1 + 4 + 4 + 9 = 24.



#### tags 

#2400 #combinatorics #dp #math 