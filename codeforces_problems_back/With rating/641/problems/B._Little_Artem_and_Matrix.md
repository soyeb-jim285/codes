<h1 style='text-align: center;'> B. Little Artem and Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Artem likes electronics. He can spend lots of time making different schemas and looking for novelties in the nearest electronics store. The new control element was delivered to the store recently and Artem immediately bought it.

That element can store information about the matrix of integers size *n* × *m*. There are *n* + *m* inputs in that element, i.e. each row and each column can get the signal. When signal comes to the input corresponding to some row, this row cyclically shifts to the left, that is the first element of the row becomes last element, second element becomes first and so on. When signal comes to the input corresponding to some column, that column shifts cyclically to the top, that is first element of the column becomes last element, second element becomes first and so on. Rows are numbered with integers from 1 to *n* from top to bottom, while columns are numbered with integers from 1 to *m* from left to right.

Artem wants to carefully study this element before using it. For that purpose he is going to set up an experiment consisting of *q* turns. On each turn he either sends the signal to some input or checks what number is stored at some position of the matrix.

Artem has completed his experiment and has written down the results, but he has lost the chip! Help Artem find any initial matrix that will match the experiment results. It is guaranteed that experiment data is consistent, which means at least one valid matrix exists.

## Input

The first line of the input contains three integers *n*, *m* and *q* (1 ≤ *n*, *m* ≤ 100, 1 ≤ *q* ≤ 10 000) — dimensions of the matrix and the number of turns in the experiment, respectively.

Next *q* lines contain turns descriptions, one per line. Each description starts with an integer *t**i* (1 ≤ *t**i* ≤ 3) that defines the type of the operation. For the operation of first and second type integer *r**i* (1 ≤ *r**i* ≤ *n*) or *c**i* (1 ≤ *c**i* ≤ *m*) follows, while for the operations of the third type three integers *r**i*, *c**i* and *x**i* (1 ≤ *r**i* ≤ *n*, 1 ≤ *c**i* ≤ *m*,  - 109 ≤ *x**i* ≤ 109) are given.

Operation of the first type (*t**i* = 1) means that signal comes to the input corresponding to row *r**i*, that is it will shift cyclically. Operation of the second type (*t**i* = 2) means that column *c**i* will shift cyclically. Finally, operation of the third type means that at this moment of time cell located in the row *r**i* and column *c**i* stores value *x**i*.

## Output

Print the description of any valid initial matrix as *n* lines containing *m* integers each. All output integers should not exceed 109 by their absolute value.

If there are multiple valid solutions, output any of them.

## Examples

## Input


```
2 2 6  
2 1  
2 2  
3 1 1 1  
3 2 2 2  
3 1 2 8  
3 2 1 8  

```
## Output


```
8 2   
1 8   

```
## Input


```
3 3 2  
1 2  
3 2 2 5  

```
## Output


```
0 0 0   
0 0 5   
0 0 0   

```


#### tags 

#1400 #implementation 