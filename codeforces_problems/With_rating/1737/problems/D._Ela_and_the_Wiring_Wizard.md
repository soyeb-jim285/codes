<h1 style='text-align: center;'> D. Ela and the Wiring Wizard</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/2ac13384224c9790093bb3d06e9e6f2c8ac3965d.png) Ela needs to send a large package from machine $1$ to machine $n$ through a network of machines. Currently, with the network condition, she complains that the network is too slow and the package can't arrive in time. Luckily, a Wiring Wizard offered her a helping hand.

The network can be represented as an undirected connected graph with $n$ nodes, each node representing a machine. $m$ wires are used to connect them. Wire $i$ is used to connect machines $u_i$ and $v_i$, and has a weight $w_i$. The aforementioned large package, if going through wire $i$, will move from machine $u_i$ to machine $v_i$ (or vice versa) in exactly $w_i$ microseconds. The Wiring Wizard can use his spell an arbitrary number of times. For each spell, he will choose the wire of index $i$, connecting machine $u_i$ and $v_i$, and rewire it following these steps:

* Choose one machine that is connected by this wire. Without loss of generality, let's choose $v_i$.
* Choose a machine that is currently connecting to $v_i$ (including $u_i$), call it $t_i$. Disconnect the wire indexed $i$ from $v_i$, then using it to connect $u_i$ and $t_i$.

The rewiring of wire $i$ will takes $w_i$ microseconds, and the weight of the wire will not change after this operation. After a rewiring, a machine might have some wire connect it with itself. Also, the Wiring Wizard has warned Ela that rewiring might cause temporary disconnections between some machines, but Ela just ignores it anyway. Her mission is to send the large package from machine $1$ to machine $n$ as fast as possible. 
## Note

 that the Wizard can use his spell on a wire zero, one, or many times. To make sure the network works seamlessly while transferring the large package, once the package starts transferring from machine $1$, the Wiring Wizard cannot use his spell to move wires around anymore.

Ela wonders, with the help of the Wiring Wizard, what is the least amount of time needed to transfer the large package from machine $1$ to $n$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The first line contains $n$ and $m$ ($2 \le n \le 500$, $n - 1 \le m \le 250 000$), the number of nodes and number of wires, respectively.

For the next $m$ lines, $i$-th line will contains $u_i$, $v_i$ and $w_i$ ($1 \le u_i, v_i \le n$, $1 \le w_i \le 10^9$) - the indices 2 machines that are connected by the $i$-th edge and the weight of it.

It is guaranteed that the sum of $n$ over all test cases does not exceed $500$ and the sum of $m$ over all test cases does not exceed $250 000$. The graph in each test case is guaranteed to be connected, no self-loops, but it can contain multiple edges.

### Output

For each test case, output one integer denotes the least amount of time needed to transfer the large package from machine $1$ to $n$.

## Example

### Input


```text
38 91 2 36 4 53 5 66 1 37 4 43 8 42 3 37 8 54 5 24 51 2 12 4 13 4 13 1 11 3 28 84 6 927 1 656 5 436 7 964 3 744 8 547 4 992 5 22
```
### Output

```text

9
2
154

```
## Note

Here is the graph in the first test case in the sample input:

 ![](images/f9ec918ddf0bcf55cfc3ef448f304006986c5054.png) Ela can ask the Wiring Wizard to use his spell on wire with the index of $7$, which is connecting machines $2$ and $3$. Then, since the machine $8$ is connected to machine $3$, the Wiring Wizard can disconnect wire $7$ from machine $3$ and connect it to machine $8$ in $3$ microseconds (weight of wire $3$).

After that, the package can be sent from machine $1$ to machine $8$ in $6$ microseconds. Therefore, the answer is $3 + 6 = 9$ microseconds.

Here is the graph in the third test case in the sample input:

 ![](images/a06cfddb6d85be5a7295fb2306e8ba624a9e5659.png) 

#### Tags 

#2200 #NOT OK #brute_force #dp #graphs #greedy #implementation #shortest_paths 

## Blogs
- [All Contest Problems](../Dytechlab_Cup_2022.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
