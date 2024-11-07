<h1 style='text-align: center;'> G. One-Dimensional Puzzle</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a one-dimensional puzzle, all the elements of which need to be put in one row, connecting with each other. All the puzzle elements are completely white and distinguishable from each other only if they have different shapes. 

Each element has straight borders at the top and bottom, and on the left and right it has connections, each of which can be a protrusion or a recess. You cannot rotate the elements.

You can see that there are exactly $4$ types of elements. Two elements can be connected if the right connection of the left element is opposite to the left connection of the right element.

 ![](images/d862915ed3dc627101b0e632c1c778b818648879.png) All possible types of elements. The puzzle contains $c_1, c_2, c_3, c_4$ elements of each type. The puzzle is considered complete if you have managed to combine all elements into one long chain. You want to know how many ways this can be done.

## Input

The first line contains a single integer $t$ ($1 \le t \le 2 \cdot 10^5$) — the number of input test cases. The descriptions of the test cases follow.

The description of each test case contains $4$ integers $c_i$ ($0 \le c_i \le 10^6$) — the number of elements of each type, respectively.

It is guaranteed that the sum of $c_i$ for all test cases does not exceed $4 \cdot 10^6$.

## Output

For each test case, print one integer — the number of possible ways to solve the puzzle. 

Two methods are considered different if there is $i$, such that the types of elements at the $i$ position in these methods differ.

Since the answer can be very large, output it modulo $998244353$.

If it is impossible to solve the puzzle, print $0$.

## Example

## Input


```

111 1 1 11 2 5 104 6 100 200900000 900000 900000 9000000 0 0 00 0 566 2391 0 0 0100 0 100 00 0 0 45 5 0 25 4 0 5
```
## Output


```

4
66
0
794100779
1
0
1
0
1
36
126

```


#### tags 

#2000 #combinatorics #math #number_theory 