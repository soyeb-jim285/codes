<h1 style='text-align: center;'> D. Drazil and Morning Exercise</h1>

<h5 style='text-align: center;'>time limit per test: 3.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Drazil and Varda are the earthworm couple. They want to find a good place to bring up their children. They found a good ground containing nature hole. The hole contains many rooms, some pairs of rooms are connected by small tunnels such that earthworm can move between them.

Let's consider rooms and small tunnels as the vertices and edges in a graph. This graph is a tree. In the other words, any pair of vertices has an unique path between them.

Each room that is leaf in the graph is connected with a ground by a vertical tunnel. Here, leaf is a vertex that has only one outgoing edge in the graph.

Each room is large enough only to fit one earthworm living in it. Earthworm can't live in a tunnel.

Drazil and Varda have a plan to educate their children. They want all their children to do morning exercises immediately after getting up!

When the morning is coming, all earthworm children get up in the same time, then each of them chooses the farthest path to the ground for gathering with others (these children are lazy, so they all want to do exercises as late as possible).

Drazil and Varda want the difference between the time first earthworm child arrives outside and the time the last earthworm child arrives outside to be not larger than *l* (otherwise children will spread around the ground and it will be hard to keep them exercising together).

Also, The rooms that are occupied by their children should form a connected set. In the other words, for any two rooms that are occupied with earthworm children, all rooms that lie on the path between them should be occupied with earthworm children too.

How many children Drazil and Varda may have at most in order to satisfy all conditions above? Drazil and Varda want to know the answer for many different choices of *l*.

(Drazil and Varda don't live in the hole with their children)

## Input

The first line contains one integer *n* denoting how many rooms there are in the hole (2 ≤ *n* ≤ 105).

Then there are *n* - 1 lines following. Each of these lines contains three integers *x*, *y*, *v* (1 ≤ *x*, *y* ≤ *n*, 1 ≤ *v* ≤ 106) denoting there is a small tunnel between room *x* and room *y* that takes time *v* to pass. 

Suppose that the time for an earthworm to get out to the ground from any leaf room is the same.

The next line contains an integer *q* (1 ≤ *q* ≤ 50), denoting the number of different value of *l* you need to process.

The last line contains *q* numbers, each number denoting a value of *l* (1 ≤ *l* ≤ 1011).

## Output

You should print *q* lines. Each line should contain one integer denoting the answer for a corresponding value of *l*.

## Examples

## Input


```
5  
1 2 3  
2 3 4  
4 5 3  
3 4 2  
5  
1 2 3 4 5  

```
## Output


```
1  
3  
3  
3  
5  

```
## Input


```
12  
5 9 3  
2 1 7  
11 7 2  
6 5 5  
2 5 3  
6 7 2  
1 4 4  
8 5 7  
1 3 8  
11 12 3  
10 8 2  
10  
13 14 14 13 13 4 6 7 2 1  

```
## Output


```
10  
10  
10  
10  
10  
3  
3  
5  
2  
1  

```
## Note

For the first sample the hole looks like the following. Rooms 1 and 5 are leaves, so they contain a vertical tunnel connecting them to the ground. The lengths of farthest path from rooms 1 – 5 to the ground are 12, 9, 7, 9, 12 respectively. 

If l = 1, we may only choose any single room. 

If l = 2..4, we may choose rooms 2, 3, and 4 as the answer. 

If l = 5, we may choose all rooms.

![](images/61987c5fd72706f8fa47b4eba74e97eae4b7d8db.png)

#### tags 

#2800 #dfs_and_similar #dp #dsu #trees #two_pointers 