<h1 style='text-align: center;'> D. Liars and Serge</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* people, sitting in a line at the table. For each person we know that he always tells either the truth or lies.

Little Serge asked them: how many of you always tell the truth? Each of the people at the table knows everything (who is an honest person and who is a liar) about all the people at the table. The honest people are going to say the correct answer, the liars are going to say any integer from 1 to *n*, which is not the correct answer. Every liar chooses his answer, regardless of the other liars, so two distinct liars may give distinct answer.

Serge does not know any information about the people besides their answers to his question. He took a piece of paper and wrote *n* integers *a*1, *a*2, ..., *a**n*, where *a**i* is the answer of the *i*-th person in the row. Given this sequence, Serge determined that exactly *k* people sitting at the table apparently lie.

Serge wonders, how many variants of people's answers (sequences of answers *a* of length *n*) there are where one can say that exactly *k* people sitting at the table apparently lie. As there can be rather many described variants of answers, count the remainder of dividing the number of the variants by 777777777.

## Input

The first line contains two integers *n*, *k*, (1 ≤ *k* ≤ *n* ≤ 28). It is guaranteed that *n* — is the power of number 2.

## Output

Print a single integer — the answer to the problem modulo 777777777.

## Examples

## Input


```
1 1  

```
## Output


```
0  

```
## Input


```
2 1  

```
## Output


```
2  

```


#### tags 

#2700 #dp 