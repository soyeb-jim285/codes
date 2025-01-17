<h1 style='text-align: center;'> B. Present from Lena</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya's birthday is approaching and Lena decided to sew a patterned handkerchief to him as a present. Lena chose digits from 0 to *n* as the pattern. The digits will form a rhombus. The largest digit *n* should be located in the centre. The digits should decrease as they approach the edges. For example, for *n* = 5 the handkerchief pattern should look like that: 


```
  
          0  
        0 1 0  
      0 1 2 1 0  
    0 1 2 3 2 1 0  
  0 1 2 3 4 3 2 1 0  
0 1 2 3 4 5 4 3 2 1 0  
  0 1 2 3 4 3 2 1 0  
    0 1 2 3 2 1 0  
      0 1 2 1 0  
        0 1 0  
          0  

```
Your task is to determine the way the handkerchief will look like by the given *n*.

## Input

The first line contains the single integer *n* (2 ≤ *n* ≤ 9).

## Output

Print a picture for the given *n*. You should strictly observe the number of spaces before the first digit on each line. Every two adjacent digits in the same line should be separated by exactly one space. There should be no spaces after the last digit at the end of each line.

## Examples

## Input


```
2  

```
## Output


```
    0  
  0 1 0  
0 1 2 1 0  
  0 1 0  
    0  

```
## Input


```
3  

```
## Output


```
      0  
    0 1 0  
  0 1 2 1 0  
0 1 2 3 2 1 0  
  0 1 2 1 0  
    0 1 0  
      0  

```


#### tags 

#1000 #constructive_algorithms #implementation 