<h1 style='text-align: center;'> G. A Certain Magical Party</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ people at a party. The $i$-th person has an amount of happiness $a_i$.

Every person has a certain kind of personality which can be represented as a binary integer $b$. If $b = 0$, it means the happiness of the person will increase if he tells the story to someone strictly less happy than them. If $b = 1$, it means the happiness of the person will increase if he tells the story to someone strictly more happy than them.

Let us define a speaking order as an ordering of the people from left to right. Now the following process occurs. We go from left to right. The current person tells the story to all people other than himself. 
## Note

 that all happiness values stay constant while this happens. After the person is done, he counts the number of people who currently have strictly less/more happiness than him as per his kind of personality, and his happiness increases by that value. 
## Note

 that only the current person's happiness value increases.

As the organizer of the party, you don't want anyone to leave sad. Therefore, you want to count the number of speaking orders such that at the end of the process all $n$ people have equal happiness.

Two speaking orders are considered different if there exists at least one person who does not have the same position in the two speaking orders.

##### Input

The first line contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the number of people.

The second line contains a sequence of $n$ integers $a_1,a_2,...,a_n$ ($1 \leq a_i \leq 2n$)  — the happiness values.

The third line contains a sequence of $n$ binary numbers $b_1,b_2,...,b_n$ ($b_i \in \{0,1\}$)  — the kinds of personality.

##### Output

##### Output

 the number of different valid speaking orders. Since this number can be large, output it modulo $998244353$.

## Examples

##### Input


```text
4
1 2 4 4
1 1 0 0
```
##### Output


```text
2
```
##### Input


```text
4
3 4 3 1
0 1 0 0
```
##### Output


```text
0
```
##### Input


```text
21
1 2 19 19 19 19 19 19 19 19 19 21 21 21 21 21 21 21 21 21 21
1 1 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1
```
##### Output


```text
49439766
```
## Note

Here is the explanation for the first example. One valid speaking order is $[2,1,4,3]$ (here, we have written the indices of each person). Each step shows the current happiness values and results.

Step $1$: $[1,2,4,4]$ $\rightarrow$ Person $2$ tells the story to others. Since his kind of personality is $1$, his happiness increases by $2$ since persons $3$ and $4$ have strictly greater happiness.

Step $2$: $[1,4,4,4]$ $\rightarrow$ Person $1$ tells the story to others. Since his kind of personality is $1$, his happiness increases by $3$ since persons $2$, $3$ and $4$ have strictly greater happiness.

Step $3$: $[4,4,4,4]$ $\rightarrow$ Person $4$ tells the story to others. Since his kind of personality is $0$, his happiness increases by $0$ since no one has strictly lesser happiness.

Step $4$: $[4,4,4,4]$ $\rightarrow$ Person $3$ tells the story to others. Since his kind of personality is $0$, his happiness increases by $0$ since no one has strictly lesser happiness.

At the end, everyone has equal happiness.

## Note

 that $[2,1,3,4]$ is also a valid answer for this example.

It can be shown that there is no valid ordering for the second example.



#### Tags 

#3300 #NOT OK #combinatorics #data_structures #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_819_(Div._1_+_Div._2)_and_Grimoire_of_Code_Annual_Contest_2022.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
