<h1 style='text-align: center;'> D. Ice Sculptures</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Berland University is preparing to celebrate the 256-th anniversary of its founding! A specially appointed Vice Rector for the celebration prepares to decorate the campus. In the center of the campus *n* ice sculptures were erected. The sculptures are arranged in a circle at equal distances from each other, so they form a regular *n*-gon. They are numbered in clockwise order with numbers from 1 to *n*.

The site of the University has already conducted a voting that estimated each sculpture's characteristic of *t**i* — the degree of the sculpture's attractiveness. The values of *t**i* can be positive, negative or zero.

When the university rector came to evaluate the work, he said that this might be not the perfect arrangement. He suggested to melt some of the sculptures so that: 

* the remaining sculptures form a regular polygon (the number of vertices should be between 3 and *n*),
* the sum of the *t**i* values of the remaining sculptures is maximized.

Help the Vice Rector to analyze the criticism — find the maximum value of *t**i* sum which can be obtained in this way. It is allowed not to melt any sculptures at all. The sculptures can not be moved.

## Input

The first input line contains an integer *n* (3 ≤ *n* ≤ 20000) — the initial number of sculptures. The second line contains a sequence of integers *t*1, *t*2, ..., *t**n*, *t**i* — the degree of the *i*-th sculpture's attractiveness ( - 1000 ≤ *t**i* ≤ 1000). The numbers on the line are separated by spaces.

## Output

Print the required maximum sum of the sculptures' attractiveness.

## Examples

## Input


```
8  
1 2 -3 4 -5 5 2 3  

```
## Output


```
14  

```
## Input


```
6  
1 -2 3 -4 5 -6  

```
## Output


```
9  

```
## Input


```
6  
1 2 3 4 5 6  

```
## Output


```
21  

```
## Note

In the first sample it is best to leave every second sculpture, that is, leave sculptures with attractivenesses: 2, 4, 5 и 3.



#### tags 

#1300 #*special #brute_force #number_theory 