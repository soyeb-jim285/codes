<h1 style='text-align: center;'> B. Hongcow's Game</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem. In the interaction section below you will see the information about flushing the output.

In this problem, you will be playing a game with Hongcow. How lucky of you!

Hongcow has a hidden *n* by *n* matrix *M*. Let *M**i*, *j* denote the entry *i*-th row and *j*-th column of the matrix. The rows and columns are labeled from 1 to *n*.

The matrix entries are between 0 and 109. In addition, *M**i*, *i* = 0 for all valid *i*. Your task is to find the minimum value along each row, excluding diagonal elements. Formally, for each *i*, you must find ![](images/3943866668dac6c7c35903f90df68a3d53ff6de1.png).

To do this, you can ask Hongcow some questions.

A question consists of giving Hongcow a subset of distinct indices {*w*1, *w*2, ..., *w**k*}, with 1 ≤ *k* ≤ *n*. Hongcow will respond with *n* integers. The *i*-th integer will contain the minimum value of *min*1 ≤ *j* ≤ *k**M**i*, *w**j*.

You may only ask Hongcow at most 20 questions — he thinks you only need that many questions answered.

When you are ready to answer, print out a single integer  - 1 on its own line, then *n* integers on the next line. The *i*-th integer should be the minimum value in the *i*-th row of the matrix, excluding the *i*-th element. Do not forget to flush the final answer as well. Printing the answer does not count as asking a question.

You will get Wrong Answer verdict if 

* Your question or answers are not in the format described in this statement.
* You ask strictly more than 20 questions.
* Your question contains duplicate indices.
* The value of *k* in your question does not lie in the range from 1 to *n*, inclusive.
* Your final answer is not correct.

 You will get Idleness Limit Exceeded if you don't print anything or if you forget to flush the output, including for the final answer (more info about flushing output below).## Input

The first line of input will contain a single integer *n* (2 ≤ *n* ≤ 1, 000).

## Output

To print the final answer, print out the string -1 on its own line. Then, the next line should contain *n* integers. The *i*-th integer should be the minimum value of the *i*-th row of the matrix, excluding elements on the diagonal. Do not forget to flush your answer!

## Interaction

To ask a question, print out a single integer *k* on its own line, denoting the size of your subset. Then, the next line should contain *k* integers *w*1, *w*2, ... *w**k*. ## Note

, you must flush your output to get a response.

Hongcow will respond by printing out a line with *n* integers. The *i*-th integer in this line represents the minimum value of *M**i*, *w**j* where *j* is between 1 and *k*.

You may only ask a question at most 20 times, otherwise, you will get Wrong Answer.

To flush you can use (just after printing an integer and end-of-line): 

* fflush(stdout) in C++;
* System.out.flush() in Java;
* stdout.flush() in Python;
* flush(output) in Pascal;
* See the documentation for other languages.

Hacking To hack someone, use the following format 


```
  
n  
M_{1,1} M_{1,2} ... M_{1,n}  
M_{2,1} M_{2,2} ... M_{2,n}  
...  
M_{n,1} M_{n,2} ... M_{n,n}  

```
Of course, contestant programs will not be able to see this input.

## Examples

## Input


```
3  
0 0 0  
2 7 0  
0 0 4  
3 0 8  
0 5 4
```
## Output


```
3  
1 2 3  
1  
3  
2  
1 2  
1  
2  
1  
1  
-1  
2 5 4  

```
## Input


```
2  
0 0  
0 0
```
## Output


```
1  
2  
1  
1  
-1  
0 0
```
## Note

In the first sample, Hongcow has the hidden matrix 


```
  
[  
 [0, 3, 2],  
 [5, 0, 7],  
 [4, 8 ,0],  
]  

```
Here is a more readable version demonstrating the interaction. The column on the left represents Hongcow, while the column on the right represents the contestant. 


```
  
3  
              3  
              1 2 3  
0 0 0  
              1  
              3  
2 7 0  
              2  
              1 2  
0 0 4  
              1  
              2  
3 0 8  
              1  
              1  
0 5 4  
              -1  
              2 5 4  

```
For the second sample, it is possible for off-diagonal elements of the matrix to be zero.



#### tags 

#1900 #bitmasks #divide_and_conquer #interactive 