<h1 style='text-align: center;'> E. Two Houses</h1>

<h5 style='text-align: center;'>time limit per test: 3.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem. Remember to flush your output while communicating with the testing program. You may use fflush(stdout) in C++, system.out.flush() in Java, stdout.flush() in Python or flush(output) in Pascal to flush the output. If you use some other programming language, consult its documentation. You may also refer to the guide on interactive problems: <https://codeforces.com/blog/entry/45307>.

There is a city in which Dixit lives. In the city, there are $n$ houses. There is  exactly one directed road between every pair of houses. For example, consider two houses A and B, then there is a directed road either from A to B or from B to A but not both. The number of roads leading to the $i$-th house is $k_i$.

Two houses A and B are bi-reachable if A is reachable from B and B is reachable from A. We say that house B is reachable from house A when there is a path from house A to house B.

Dixit wants to buy two houses in the city, that is, one for living and one for studying. Of course, he would like to travel from one house to another. So, he wants to find a pair of bi-reachable houses A and B. Among all such pairs, he wants to choose one with the maximum value of $|k_A - k_B|$, where $k_i$ is the number of roads leading to the house $i$. If more than one optimal pair exists, any of them is suitable.

Since Dixit is busy preparing CodeCraft, can you help him find the desired pair of houses, or tell him that no such houses exist?

In the problem input, you are not given the direction of each road. You are given — for each house — only the number of incoming roads to that house ($k_i$).

You are allowed to ask only one type of query from the judge: give two houses A and B, and the judge answers whether B is reachable from A. There is no upper limit on the number of queries. But, you cannot ask more queries after the judge answers "Yes" to any of your queries. Also, you cannot ask the same query twice.

Once you have exhausted all your queries (or the judge responds "Yes" to any of your queries), your program must output its guess for the two houses and quit.

See the 
## Interaction

 section below for more details.

#### Input

The first line contains a single integer $n$ ($3 \le n \le 500$) denoting the number of houses in the city. The next line contains $n$ space-separated integers $k_1, k_2, \dots, k_n$ ($0 \le k_i \le n - 1$), the $i$-th of them represents the number of incoming roads to the $i$-th house.

## Interaction

To ask a query, print "? A B" $(1 \leq A,B \leq N, A\neq B)$. The judge will respond "Yes" if house B is reachable from house A, or "No" otherwise.

To output the final answer, print "! A B", where A and B are bi-reachable with the maximum possible value of $|k_A - k_B|$. If there does not exist such pair of houses A and B, output "! 0 0".

After outputting the final answer, your program must terminate immediately, otherwise you will receive Wrong Answer verdict.

You cannot ask the same query twice. There is no upper limit to the number of queries you ask, but, you cannot ask more queries after the judge answers "Yes" to any of your queries. Your program must now output the final answer ("! A B" or "! 0 0") and terminate.

If you ask a query in incorrect format or repeat a previous query, you will get Wrong Answer verdict.

After printing a query do not forget to output the end of the line and flush the output. Otherwise, you will get the Idleness limit exceeded error. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.
## Examples

#### Input


```text
3
1 1 1
Yes
```
##Output
```text

? 1 2
! 1 2
```
#### Input

```text

4
1 2 0 3
No
No
No
No
No
No
```
##Output
```text

? 2 1
? 1 3
? 4 1
? 2 3
? 4 2
? 4 3
! 0 0
```
## Note

In the first sample input, we are given a city of three houses with one incoming road each. The user program asks one query: "? 1 2": asking whether we can reach from house $1$ to house $2$. The judge responds with "Yes". The user program now concludes that this is sufficient information to determine the correct answer. So, it outputs "! 1 2" and quits.

In the second sample input, the user program queries for six different pairs of houses, and finally answers "! 0 0" as it is convinced that no two houses as desired in the question exist in this city.



#### Tags 

#2200 #NOT OK #brute_force #graphs #greedy #interactive #sortings 

## Blogs
- [All Contest Problems](../CodeCraft-21_and_Codeforces_Round_711_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
