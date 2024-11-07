<h1 style='text-align: center;'> F. Phoenix and Memory</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Phoenix is trying to take a photo of his $n$ friends with labels $1, 2, \dots, n$ who are lined up in a row in a special order. But before he can take the photo, his friends get distracted by a duck and mess up their order.

Now, Phoenix must restore the order but he doesn't remember completely! He only remembers that the $i$-th friend from the left had a label between $a_i$ and $b_i$ inclusive. Does there exist a unique way to order his friends based of his memory? 

## Input

The first line contains one integer $n$ ($1 \le n \le 2\cdot10^5$)  — the number of friends.

The $i$-th of the next $n$ lines contain two integers $a_i$ and $b_i$ ($1 \le a_i \le b_i \le n$)  — Phoenix's memory of the $i$-th position from the left.

It is guaranteed that Phoenix's memory is valid so there is at least one valid ordering.

## Output

If Phoenix can reorder his friends in a unique order, print YES followed by $n$ integers  — the $i$-th integer should be the label of the $i$-th friend from the left.

Otherwise, print NO. Then, print any two distinct valid orderings on the following two lines. If are multiple solutions, print any.

## Examples

## Input


```

4
4 4
1 3
2 4
3 4

```
## Output


```

YES
4 1 2 3 

```
## Input


```

4
1 3
2 4
3 4
2 3

```
## Output


```

NO
1 3 4 2 
1 2 4 3 

```


#### tags 

#2600 #data_structures #dfs_and_similar #graphs #greedy 