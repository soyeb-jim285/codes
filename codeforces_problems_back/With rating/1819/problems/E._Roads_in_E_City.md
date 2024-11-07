<h1 style='text-align: center;'> E. Roads in E City</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

As is well known, the city "E" has never had its roads repaired in its a thousand and a half years old history. And only recently the city administration repaired some of them.

It is known that in total in the city "E" there are $n$ intersections and $m$ roads, which can be used in both directions, numbered with integers from $1$ to $m$. The $i$-th road connects intersections with numbers $a_i$ and $b_i$.

Among all $m$ roads, some subset of the roads has been repaired, but you do not know which one. The only information you could get from the city's road services is that you can get from any intersection to any other intersection by driving only on the roads that have been repaired.

You are a young entrepreneur, and decided to organize a delivery service of fresh raw meat in the city "E" (in this city such meat is called "steaks", it is very popular among the locals). You have already recruited a staff of couriers, but the couriers are willing to travel only on repaired roads. Now you have to find out which roads have already been repaired.

The city administration has given you the city for a period of time, so you can make different queries of one of three types:

1. Block the road with the number $x$. In this case, movement on the road for couriers will be forbidden. Initially all roads are unblocked.
2. Unblock the road with the number $x$. In this case, couriers will be able to move on the road $x$ if it is repaired.
3. Try to deliver the order to the intersection with the number $y$. In this case, one of your couriers will start moving from intersection with number $s$ you don't know and deliver the order to intersection with number $y$ if there is a path on unblocked repaired roads from intersection $s$ to intersection $y$. It is guaranteed that intersection $s$ will be chosen beforehand.

Unfortunately, the city is placed at your complete disposal for a short period of time, so you can make no more than $100 \cdot m$ requests.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 1\,000$) — the number of test cases. The description of test cases follows.

The first line contains two integers $n$ and $m$ ($2 \le n \le 2\,000$, $n - 1 \le m \le 2\,000$) —the number of intersections and roads in the city "E".

Each of the following $m$ lines describes one road. The $i$-th of these lines contains two integers $a_i$ and $b_i$ ($1 \le a_i, b_i \le n$) — the ends of the $i$-th road. It is guaranteed that no road connects the city to itself, while it is possible that there are several roads between a pair of different intersections.

It is guaranteed that the sum of $n$ and the sum of $m$ over all test cases does not exceed $2\,000$.

## Interaction

Once you have read the description of the test case, you can make queries. Queries can be of three types:

1. "- $x$" ($1 \le x \le m$). In this case the road with the number $x$ is blocked if it has not already been blocked.
2. "+ $x$" ($1 \le x \le m$). In this case the road with the number $x$ is unblocked. ## Note

 that road $x$ must be blocked beforehand. All roads are initially unblocked.
3. "? $y$" ($1 \le y \le n$). In this case the jury program chooses some city $s$. If you can get from town $s$ to town $y$ by unblocked repaired roads, the jury program will output $1$, otherwise the jury program will output $0$. ## Note

 that city $s$ will be selected before getting information about city $y$, but your previous requests may be taken into account when selecting city $s$.

In total, you can make no more than $100 \cdot m$ queries for each set of input data.

After you have found all repaired roads, output "! $c_1,\ c_2,\ c_3,\ \ldots,\ c_m$", where $c_i$ is $1$ if road $i$ is repaired, and $0$ if road is not repaired. This output will not count in the total number of queries. The jury program will output $1$ if your answer is correct, and $0$ if the answer is not correct. If you received $0$, your program must terminate immediately to receive a Wrong Answer verdict. Otherwise you can get any verdict, because the program will continue reading from the closed stream. If you read $1$, move on to the next test case, or terminate the program if there is none.

## Note

 that you do not have to unblock all roads before outputting the answer. It is guaranteed that all repaired roads are fixed initially and will not be changed by the jury program depending on queries.

After outputting a query or the answer do not forget to output the end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

 HacksYou can't do hacks on this problem.

## Example

## Input


```

2
2 2
1 2
2 1


1

0



1

1
3 3
1 2
2 3
3 1


1

1


1

0


1

1

1

1
```
Output
```





- 1
? 1

? 2

- 2
+ 1
? 1

! 1 0





- 1
? 2

? 1

- 2
? 3

? 3

+ 1
? 3

? 2

? 1

! 1 1 1
```
## Note

In the first test case, road $1$ was repaired, while road $2$ was not. For the first delivery request, intersection $1$ was selected as $s$, and the path from intersection $1$ to $1$ exists. For the second delivery request, intersection $1$ was selected as $s$. Since the only repaired road was blocked, there was no path between intersections $1$ and $2$. For the third delivery request, intersection $2$ was selected as $s$, the path between intersections $2$ and $1$ exists along road $1$, which is repaired and unblocked.

In the second test case, intersections $1$, $3$, $1$, $2$, $2$, $3$, $1$ were selected as starting intersections for delivery requests.



#### tags 

#3200 #interactive #math #probabilities #trees 