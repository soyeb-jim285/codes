<h1 style='text-align: center;'> C. New Year Presents</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Santa has prepared boxes with presents for $n$ kids, one box for each kid. There are $m$ kinds of presents: balloons, sweets, chocolate bars, toy cars... A child would be disappointed to receive two presents of the same kind, so all kinds of presents in one box are distinct.

Having packed all the presents, Santa realized that different boxes can contain different number of presents. It would be unfair to the children, so he decided to move some presents between boxes, and make their sizes similar. After all movements, the difference between the maximal and the minimal number of presents in a box must be as small as possible. All presents in each box should still be distinct. Santa wants to finish the job as fast as possible, so he wants to minimize the number of movements required to complete the task.

Given the sets of presents in each box, find the shortest sequence of movements of presents between boxes that minimizes the difference of sizes of the smallest and the largest box, and keeps all presents in each box distinct.

## Input

The first line of input contains two integers $n$, $m$ ($1 \leq n, m \leq 100\ 000$), the number of boxes and the number of kinds of the presents. Denote presents with integers from $1$ to $m$.

Each of the following $n$ lines contains the description of one box. It begins with an integer $s_i$ ($s_i \geq 0$), the number of presents in the box, $s_i$ distinct integers between $1$ and $m$ follow, denoting the kinds of presents in that box.

The total number of presents in all boxes does not exceed $500\,000$.

## Output

Print one integer $k$ at the first line of output, the number of movements in the shortest sequence that makes the sizes of the boxes differ by at most one. Then print $k$ lines that describe movements in the same order in which they should be performed. Each movement is described by three integers $from_i$, $to_i$, $kind_i$. It means that the present of kind $kind_i$ is moved from the box with number $from_i$ to the box with number $to_i$. Boxes are numbered from one in the order they are given in the input.

At the moment when the movement is performed the present with kind $kind_i$ must be present in the box with number $from_i$. After performing all moves each box must not contain two presents of the same kind.

If there are several optimal solutions, output any of them.

## Example

## Input


```

3 5
5 1 2 3 4 5
2 1 2
2 3 4

```
## Output


```

2
1 3 5
1 2 3

```


#### tags 

#2400 #constructive_algorithms #data_structures 