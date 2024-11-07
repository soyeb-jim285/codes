<h1 style='text-align: center;'> B. Domino for Young</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a Young diagram. 

Given diagram is a histogram with $n$ columns of lengths $a_1, a_2, \ldots, a_n$ ($a_1 \geq a_2 \geq \ldots \geq a_n \geq 1$).

 ![](images/94e21a4955f87bc6a87fae2c191cb199091d11b4.png) Young diagram for $a=[3,2,2,2,1]$. Your goal is to find the largest number of non-overlapping dominos that you can draw inside of this histogram, a domino is a $1 \times 2$ or $2 \times 1$ rectangle.

## Input

The first line of input contain one integer $n$ ($1 \leq n \leq 300\,000$): the number of columns in the given histogram.

The next line of input contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 300\,000, a_i \geq a_{i+1}$): the lengths of columns.

## Output

## Output

 one integer: the largest number of non-overlapping dominos that you can draw inside of the given Young diagram.

## Example

## Input


```

5
3 2 2 2 1

```
## Output


```

4

```
## Note

Some of the possible solutions for the example:

![](images/a16580ae80f17ddfd658d64fefe83b64e0ef0882.png) ![](images/27f74eae955e98b8a7b95f87b92cbbb8491af1e0.png)



#### tags 

#2000 #dp #greedy #math 