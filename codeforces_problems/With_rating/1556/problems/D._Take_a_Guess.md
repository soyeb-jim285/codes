<h1 style='text-align: center;'> D. Take a Guess</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/95c574488a9b1009109e4e45aecb19b0e6c48b74.png) This is an interactive task

William has a certain sequence of integers $a_1, a_2, \dots, a_n$ in his mind, but due to security concerns, he does not want to reveal it to you completely. William is ready to respond to no more than $2 \cdot n$ of the following questions:

* What is the result of a [bitwise AND](https://en.wikipedia.org/wiki/Bitwise_operation#AND) of two items with indices $i$ and $j$ ($i \neq j$)
* What is the result of a [bitwise OR](https://en.wikipedia.org/wiki/Bitwise_operation#OR) of two items with indices $i$ and $j$ ($i \neq j$)

You can ask William these questions and you need to find the $k$-th smallest number of the sequence.

Formally the $k$-th smallest number is equal to the number at the $k$-th place in a 1-indexed array sorted in non-decreasing order. For example in array $[5, 3, 3, 10, 1]$ $4$th smallest number is equal to $5$, and $2$nd and $3$rd are $3$.

### Input

It is guaranteed that for each element in a sequence the condition $0 \le a_i \le 10^9$ is satisfied.

## Interaction

In the first line you will be given two integers $n$ and $k$ $(3 \le n \le 10^4, 1 \le k \le n)$, which are the number of items in the sequence $a$ and the number $k$.

After that, you can ask no more than $2 \cdot n$ questions (not including the "finish" operation).

Each line of your output may be of one of the following types: 

* "or i j" $(1 \le i, j \le n, i \neq j)$, where $i$ and $j$ are indices of items for which you want to calculate the bitwise OR.
* "and i j" $(1 \le i, j \le n, i \neq j)$, where $i$ and $j$ are indices of items for which you want to calculate the bitwise AND.
* "finish res", where $res$ is the $k$th smallest number in the sequence. After outputting this line the program execution must conclude.

In response to the first two types of queries, you will get an integer $x$, the result of the operation for the numbers you have selected.

After outputting a line do not forget to output a new line character and flush the output buffer. Otherwise you will get the "Idleness limit exceeded". To flush the buffer use:

* fflush(stdout) in C++
* System.out.flush() in Java
* stdout.flush() in Python
* flush(output) in Pascal
* for other languages refer to documentation

If you perform an incorrect query the response will be $-1$. After receiving response $-1$ you must immediately halt your program in order to receive an "Incorrect answer" verdict.

Hacking 

To perform a hack you will need to use the following format:

The first line must contain two integers $n$ and $k$ $(3 \le n \le 10^4, 1 \le k \le n)$, which are the number of items in the sequence $a$ and the number $k$.

The second line must contain $n$ integers $a_1, a_2, \dots, a_n$ $(0 \le a_i \le 10^9)$, the sequence $a$.

## Example

### Input


```text

7 6

2

7
```
#Output
```text

and 2 5

or 5 6

finish 5
```
## Note

In the example, the hidden sequence is $[1, 6, 4, 2, 3, 5, 4]$.

Below is the interaction in the example.



| Query (contestant's program) | Response (interactor) | 
## Note

s |
| --- | --- | --- |
| and 2 5 | 2 | $a_2=6$, $a_5=3$. Interactor returns bitwise AND of the given numbers. |
| or 5 6 | 7 | $a_5=3$, $a_6=5$. Interactor returns bitwise OR of the given numbers. |
| finish 5 |  | $5$ is the correct answer. 
## Note

 that you must find the value and not the index of the kth smallest number. |

 



#### Tags 

#1800 #NOT OK #bitmasks #constructive_algorithms #interactive #math 

## Blogs
- [All Contest Problems](../Deltix_Round,_Summer_2021_(open_for_everyone,_rated,_Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
