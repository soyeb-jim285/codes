<h1 style='text-align: center;'> C. Table Decorations</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have *r* red, *g* green and *b* blue balloons. To decorate a single table for the banquet you need exactly three balloons. Three balloons attached to some table shouldn't have the same color. What maximum number *t* of tables can be decorated if we know number of balloons of each color?

Your task is to write a program that for given values *r*, *g* and *b* will find the maximum number *t* of tables, that can be decorated in the required manner.

## Input

The single line contains three integers *r*, *g* and *b* (0 ≤ *r*, *g*, *b* ≤ 2·109) — the number of red, green and blue baloons respectively. The numbers are separated by exactly one space.

## Output

Print a single integer *t* — the maximum number of tables that can be decorated in the required manner.

## Examples

## Input


```
5 4 3  

```
## Output


```
4  

```
## Input


```
1 1 1  

```
## Output


```
1  

```
## Input


```
2 3 3  

```
## Output


```
2  

```
## Note

In the first sample you can decorate the tables with the following balloon sets: "rgg", "gbb", "brr", "rrg", where "r", "g" and "b" represent the red, green and blue balls, respectively.



#### tags 

#1800 #greedy 