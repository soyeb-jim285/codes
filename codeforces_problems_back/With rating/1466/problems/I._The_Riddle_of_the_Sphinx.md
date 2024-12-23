<h1 style='text-align: center;'> I. The Riddle of the Sphinx</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

What walks on four feet in the morning, two in the afternoon, and three at night?This is an interactive problem. This problem doesn't support hacks.

Sphinx's duty is to guard the city of Thebes by making sure that no unworthy traveler crosses its gates. Only the ones who answer her riddle timely and correctly (or get an acc for short) are allowed to pass. As of those who fail, no one heard of them ever again...

So you don't have a choice but to solve the riddle. Sphinx has an array $a_1, a_2, \ldots, a_n$ of nonnegative integers strictly smaller than $2^b$ and asked you to find the maximum value among its elements. Of course, she will not show you the array, but she will give you $n$ and $b$. As it is impossible to answer this riddle blindly, you can ask her some questions. For given $i, y$, she'll answer you whether $a_i$ is bigger than $y$. As sphinxes are not very patient, you can ask at most $3 \cdot (n + b) $ such questions.

Although cunning, sphinxes are honest. Even though the array can change between your queries, answers to the previously asked questions will remain valid.

## Input

The first line contains two integers $n$ and $b$ ($1 \leq n, b \leq 200$). The remaining parts of the input will be given throughout the interaction process.

## Interaction

In each round your program must output a single line with an integer $i$ ($0 \leq i \leq n$) and a binary string of length exactly $b$ denoting the binary representation of $y$ (most significant bit first).

If $i > 0$, this line encodes the question: Is $a_i$ bigger than $y$?. There should be at most $3 \cdot (n+b)$ such lines; after each of them, the interactor will print yes or no in a single line.

If $i = 0$, this is the last round of interaction, after which your program should terminate, and $y$ should be the maximal value among the elements of Sphinx's array. ## Note

 that this round does not count to the query limit.

## Note

 that the interactor is adaptive.

After printing a query, do not forget to output the end of the line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

If your solution does not correctly follow the interaction guideline above, it may receive an arbitrary verdict. Otherwise, your program will receive the Wrong Answer judgment if it reports the wrong maximum.

## Examples

## Input


```

5 3

yes

no

no

no

no

yes

```
Output
```

5 101

5 110

4 100

3 101

2 001

1 000

0 110

```
## Input


```

4 3

no

no

no

no

```
Output
```

1 000

2 000

3 000

4 000

0 000

```
## Input


```

1 1

```
Output
```

0 0

```
## Note

In all examples, the sequence is fixed beforehand.

In the first example, the sequence is $2, 1, 4, 0, 6$.

In the second example, the sequence is $0, 0, 0, 0$.

In the third example, the sequence is $0$.

## Note

 that if the interactor was adaptive, then the interaction in the first and the third example would not be sufficient to return the correct value of maximum.



#### tags 

#3400 #binary_search #data_structures #data_structures #interactive 