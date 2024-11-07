<h1 style='text-align: center;'> A. Game of Life</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/9cbb0971d1fb7ede892276cac83500a3c7afe02a.png) William really likes the cellular automaton called "Game of Life" so he decided to make his own version. For simplicity, William decided to define his cellular automaton on an array containing $n$ cells, with each cell either being alive or dead.

Evolution of the array in William's cellular automaton occurs iteratively in the following way:

* If the element is dead and it has exactly $1$ alive neighbor in the current state of the array, then on the next iteration it will become alive. For an element at index $i$ the neighbors would be elements with indices $i - 1$ and $i + 1$. If there is no element at that index, it is considered to be a dead neighbor.
* William is a humane person so all alive elements stay alive.

Check the note section for examples of the evolution.

You are given some initial state of all elements and you need to help William find the state of the array after $m$ iterations of evolution.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^3$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($2 \le n \le 10^3, 1 \le m \le 10^9$), which are the total number of cells in the array and the number of iterations.

The second line of each test case contains a string of length $n$ made up of characters "0" and "1" and defines the initial state of the array. "1" means a cell is alive and "0" means it is dead.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^4$.

### Output

In each test case output a string of length $n$, made up of characters "0" and "1"  — the state of the array after $m$ iterations of evolution.

## Example

### Input


```text
4
11 3
01000000001
10 2
0110100101
5 2
10101
3 100
000
```
### Output


```text
11111001111
1110111101
10101
000
```
## Note

Sequence of iterations of evolution for the first test case 

* 01000000001  — initial state
* 11100000011  — first iteration of evolution
* 11110000111  — second iteration of evolution
* 11111001111  — third iteration of evolution

Sequence of iterations of evolution for the second test case 

* 0110100101  — initial state
* 1110111101  — first iteration of evolution
* 1110111101  — second iteration of evolution


#### Tags 

#800 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Deltix_Round,_Spring_2021_(open_for_everyone,_rated,_Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
