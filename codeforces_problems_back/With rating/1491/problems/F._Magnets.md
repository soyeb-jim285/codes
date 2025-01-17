<h1 style='text-align: center;'> F. Magnets</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Kochiya Sanae is playing with magnets. Realizing that some of those magnets are demagnetized, she is curious to find them out.

There are $n$ magnets, which can be of the following $3$ types:

* N
* S
* - — these magnets are demagnetized.

 ## Note

 that you don't know the types of these magnets beforehand.

You have a machine which can measure the force between the magnets, and you can use it at most $n+\lfloor \log_2n\rfloor$ times.

You can put some magnets to the left part of the machine and some to the right part of the machine, and launch the machine. Obviously, you can put one magnet to at most one side (you don't have to put all magnets). You can put the same magnet in different queries.

Then the machine will tell the force these magnets produce. Formally, let $n_1,s_1$ be the number of N and S magnets correspondently on the left and $n_2,s_2$ — on the right. Then the force between them would be $n_1n_2+s_1s_2-n_1s_2-n_2s_1$. Please note that the force is a signed value.

However, when the absolute value of the force is strictly larger than $n$, the machine will crash into pieces.

You need to find all magnets of type - (all demagnetized ones), without breaking the machine.

## Note

 that the interactor is not adaptive. The types of the magnets are fixed before the start of the interaction and do not change with queries.

It is guaranteed that there are at least $2$ magnets whose type is not -, and at least $1$ magnet of type -.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

## Interaction

For each test case you should start by reading an integer $n$ ($3 \leq n \leq 2000$) — the number of the magnets. 

It is guaranteed that the total sum of all $n$ over all test cases doesn't exceed $2000$.

After that you can put some magnets into the machine and make a query from the statement.

You have to print each query in three lines:

* In the first line print "? l r" (without quotes) where $l$ and $r$ ($1 \leq l,r < n$, $l+r \leq n$) respectively denote the number of the magnets you put to left and right.
* In the second line print $l$ integers $a_1, \dots, a_l$ ($1 \leq a_i \leq n$, $a_i \neq a_j$ if $i \neq j$) — the indices of the magnets you put to left.
* In the third line print $r$ integers $b_1, \dots, b_r$ ($1 \leq b_i \leq n$, $b_i \neq b_j$ if $i \neq j$) — the indices of the magnets you put to right.
* The same magnet can't be put to both sides in the same query. Formally, you should guarantee that $a_i \neq b_j$ for any $i$ and $j$. However, you may leave some magnets unused.

After printing a query do not forget to output end of line and flush the output. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

After this, you should read an integer $F$ — the force these magnets produce.

## Note

 that if your query is invalid(either the query limit exceeds, the machine crashes or the arguments are invalid), the interactor will terminate immediately. In this case terminate your program to receive verdict Wrong Answer instead of arbitrary verdicts.

If you are confident about your answer, use the following format to report it:

* "! k A", where $k$ is the number of magnets you found, and $A$ is an array consisting of $k$ different integers from $1$ to $n$ denoting the indices of the magnets of type - that you found. You may print elements of $A$ in arbitrary order.
* After that, if this is the last test case, you have to terminate your program; otherwise you should immediately continue to deal with the next test case.

## Note

 that the interactor is not adaptive. The types of the magnets are fixed before the start of interaction and do not change with queries.

Hacks

To hack a solution, use the following format:

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases in your hack.

Then follow the descriptions of the $t$ test cases, each printed in two lines:

* The first line contains a single integer $n$ ($3 \leq n \leq 2000$) — the number of magnets.
* The second line contains a string $S$ of length $n$ consisting of only N, S and -, denoting the magnets' types.
* Each of your test case should guarantee that there are at least $2$ magnets whose type is not -, and at least $1$ magnet of type -. Meanwhile, the total sum of $n$ in all test cases should not exceed $2000$.
## Example

## Input


```

1
4



0



1



0



0


```
Output
```



? 1 1
3
4

? 1 2
1
2 3

? 1 1
1
4

? 1 1
1
3

! 2 3 4

```
## Note

The empty lines in the sample are just for you to better understand the interaction process. You're not required to print them.

In the sample, the types of the magnets are NN--.

At first, you put the third magnet on the left and the fourth one on the right. Both of them have type -, thus no force is produced.

Then you put the first magnet on the left and the second and third one on the right. The third magnet has type -, while the other two magnets are of type N, so the force produced is $1$.

In the following two queries, the force is $0$ since there is only a magnet with property - on the right.

Then we can determine that the magnets of type - are the third and the fourth one, so we should print ! 2 3 4 and exit.



#### tags 

#2700 #binary_search #constructive_algorithms #interactive 