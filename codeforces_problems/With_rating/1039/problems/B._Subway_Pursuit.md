<h1 style='text-align: center;'> B. Subway Pursuit</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

This is an interactive problem.

In the Wonderful Metropolis of the Future, there is no need in subway train drivers. Due to the technological progress, they were replaced by the Artificial Intelligence (AI). Unfortunately, one day the predictions of sci-fi writers came true: the AI rebelled and now there is an uncontrollable train in the subway. It can be dangerous! Your task is to find the train and stop the AI.

The subway of the Metropolis is one line (regular straight line with no self-intersections) with $n$ stations, indexed consecutively from $1$ to $n$. At each moment the train is at some station. You need to determine the index of this station, so that the train would be secured.

To find the train, dispatcher Sarah gave you a gadget that allows you to select arbitrary numbers $l$ and $r$ ($l \le r$), and then check, whether the train is located on a station with index between $l$ and $r$, inclusive. Unfortunately, recharging of the gadget takes some time (and every time you use it as soon as possible), so between two applications of the gadget the train can move to any station that is at most $k$ stations away. Formally, if the train was at the station $x$ when the gadget was applied, then at the next application of the gadget the train can appear at any station $y$ such that $\max(1, x - k) \leq y \leq \min(n, x + k)$.

## Note

 that AI is not aware that you are trying to catch the train, so it makes all moves according to its predefined plan.

After an examination of the gadget you found that it is very old and can hold no more than $4500$ applications, after which it will break and your mission will be considered a failure.

Can you find the station with the train using no more than $4500$ applications of the gadgets?

### Input

The first line contains two integers $n$ and $k$ ($1 \leq n \leq 10^{18}$, $0 \leq k \leq 10$) — the number of stations and the maximum number of stations the train can move between two applications of the gadget.

## Interaction

You can apply the gadget at most $4500$ times. In order to apply the gadget you need to print two space-separated integers $l$ and $r$ ($1 \leq l \leq r \leq n$). You will then receive either string "Yes", if the train is between stations $l$ and $r$, inclusive, or string "No" otherwise. If $l = r$ and you received "Yes", then you found the train successfully, and your program must halt immediately.

Answer "Bad" instead of "Yes" or "No" means that you made an invalid query or made too many queries. Exit immediately after receiving "Bad" and you will see Wrong answer verdict. Otherwise you can get an arbitrary verdict because your solution will continue to read from a closed stream.

After printing a query do not forget to output end of line and flush the output. Otherwise you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

In order to hack, you should present a test in the following format.

The first line should contain three integers $n$, $k$ and $p$ ($1 \le n \le 10^{18}$, $0 \le k \le 10$, $1 \le p \le n$) — the number of stations, the maximum number of stations the train can move between two applications of the gadget and the initial position of the train, respectively.

Each of the next $4500$ lines should contain a single integer $x$ ($1 \le x \le n$) — the positions of the train after each query. Two consecutive positions (including the initial one) should not differ by more than $k$.

For example, the following lines are the first lines of the sample test.


```text
  
10 2 5  
5  
3  
5  
7  
7  
...  

```
## Example

### Input


```text
10 2  
  
Yes  
  
No  
  
Yes  
  
Yes  

```
#Output
```text
3 5  
  
3 3  
  
3 4  
  
5 5  

```
## Note

In the first sample, the train was initially at the station $5$, after the first application of the gadget it did not move, after the second application it moved to the station $3$, and after the third application moved again to the station $5$.



#### Tags 

#2100 #NOT OK #binary_search #interactive #probabilities 

## Blogs
- [All Contest Problems](../Codeforces_Round_507_(Div._1,_based_on_Olympiad_of_Metropolises).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
