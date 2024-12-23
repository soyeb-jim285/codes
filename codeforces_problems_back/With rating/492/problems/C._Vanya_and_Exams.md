<h1 style='text-align: center;'> C. Vanya and Exams</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vanya wants to pass *n* exams and get the academic scholarship. He will get the scholarship if the average grade mark for all the exams is at least *avg*. The exam grade cannot exceed *r*. Vanya has passed the exams and got grade *a**i* for the *i*-th exam. To increase the grade for the *i*-th exam by 1 point, Vanya must write *b**i* essays. He can raise the exam grade multiple times.

What is the minimum number of essays that Vanya needs to write to get scholarship?

## Input

The first line contains three integers *n*, *r*, *avg* (1 ≤ *n* ≤ 105, 1 ≤ *r* ≤ 109, 1 ≤ *avg* ≤ *min*(*r*, 106)) — the number of exams, the maximum grade and the required grade point average, respectively.

Each of the following *n* lines contains space-separated integers *a**i* and *b**i* (1 ≤ *a**i* ≤ *r*, 1 ≤ *b**i* ≤ 106).

## Output

In the first line print the minimum number of essays.

## Examples

## Input


```
5 5 4  
5 2  
4 7  
3 1  
3 2  
2 5  

```
## Output


```
4  

```
## Input


```
2 5 4  
5 2  
5 2  

```
## Output


```
0  

```
## Note

In the first sample Vanya can write 2 essays for the 3rd exam to raise his grade by 2 points and 2 essays for the 4th exam to raise his grade by 1 point.

In the second sample, Vanya doesn't need to write any essays as his general point average already is above average.



#### tags 

#1400 #greedy #sortings 