<h1 style='text-align: center;'> B. OR in Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's define logical *OR* as an operation on two logical values (i. e. values that belong to the set {0, 1}) that is equal to 1 if either or both of the logical values is set to 1, otherwise it is 0. We can define logical *OR* of three or more logical values in the same manner:

![](images/661f67f4b56b351d145dce2e9a87cd7c5f6a4d64.png) where ![](images/7bcdd7440cc300269a3395fa037d5af6351c3221.png) is equal to 1 if some *a**i* = 1, otherwise it is equal to 0.

Nam has a matrix *A* consisting of *m* rows and *n* columns. The rows are numbered from 1 to *m*, columns are numbered from 1 to *n*. Element at row *i* (1 ≤ *i* ≤ *m*) and column *j* (1 ≤ *j* ≤ *n*) is denoted as *A**ij*. All elements of *A* are either 0 or 1. From matrix *A*, Nam creates another matrix *B* of the same size using formula:

![](images/4332dfa4828fa3b9679abe53387834c43c801689.png).

(*B**ij* is *OR* of all elements in row *i* and column *j* of matrix *A*)

Nam gives you matrix *B* and challenges you to guess matrix *A*. Although Nam is smart, he could probably make a mistake while calculating matrix *B*, since size of *A* can be large.

## Input

The first line contains two integer *m* and *n* (1 ≤ *m*, *n* ≤ 100), number of rows and number of columns of matrices respectively.

The next *m* lines each contain *n* integers separated by spaces describing rows of matrix *B* (each element of *B* is either 0 or 1).

## Output

In the first line, print "NO" if Nam has made a mistake when calculating *B*, otherwise print "YES". If the first line is "YES", then also print *m* rows consisting of *n* integers representing matrix *A* that can produce given matrix *B*. If there are several solutions print any one.

## Examples

## Input


```
2 2  
1 0  
0 0  

```
## Output


```
NO  

```
## Input


```
2 3  
1 1 1  
1 1 1  

```
## Output


```
YES  
1 1 1  
1 1 1  

```
## Input


```
2 3  
0 1 0  
1 1 1  

```
## Output


```
YES  
0 0 0  
0 1 0  

```


#### tags 

#1300 #greedy #hashing #implementation 