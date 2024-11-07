<h1 style='text-align: center;'> F. Boolean Computer</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice has a computer that operates on $w$-bit integers. The computer has $n$ registers for values. The current content of the registers is given as an array $a_1, a_2, \ldots, a_n$. 

The computer uses so-called "number gates" to manipulate this data. Each "number gate" takes two registers as inputs and calculates a function of the two values stored in those registers. 
## Note

 that you can use the same register as both inputs.

Each "number gate" is assembled from bit gates. There are six types of bit gates: AND, OR, XOR, NOT AND, NOT OR, and NOT XOR, denoted "A", "O", "X", "a", "o", "x", respectively. Each bit gate takes two bits as input. Its output given the input bits $b_1$, $b_2$ is given below:

 $\begin{matrix} b_1 & b_2 & A & O & X & a & o & x \\\ 0 & 0 & 0 & 0 & 0 & 1 & 1 & 1 \\\ 0 & 1 & 0 & 1 & 1 & 1 & 0 & 0 \\\ 1 & 0 & 0 & 1 & 1 & 1 & 0 & 0 \\\ 1 & 1 & 1 & 1 & 0 & 0 & 0 & 1 \\\ \end{matrix}$ To build a "number gate", one takes $w$ bit gates and assembles them into an array. A "number gate" takes two $w$-bit integers $x_1$ and $x_2$ as input. The "number gate" splits the integers into $w$ bits and feeds the $i$-th bit of each input to the $i$-th bit gate. After that, it assembles the resulting bits again to form an output word. 

For instance, for $4$-bit computer we might have a "number gate" "AXoA" (AND, XOR, NOT OR, AND). For two inputs, $13 = 1101_2$ and $10 = 1010_2$, this returns $12 = 1100_2$, as $1$ and $1$ is $1$, $1$ xor $0$ is $1$, not ($0$ or $1$) is $0$, and finally $1$ and $0$ is $0$. 

You are given a description of $m$ "number gates". For each gate, your goal is to report the number of register pairs for which the "number gate" outputs the number $0$. In other words, find the number of ordered pairs $(i,j)$ where $1 \leq i,j \leq n$, such that $w_k(a_i, a_j) = 0$, where $w_k$ is the function computed by the $k$-th "number gate".

###### Input

The first line contains three integers: $w$, $n$, and $m~(1 \leq w \leq 12, 1 \leq n \leq 3\cdot 10^4, 1 \leq m \leq 5\cdot 10^4)$ — the word size, the number of variables, and the number of gates.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ $(0 \leq a_i < 2^w)$ — the value of variables stored in the registers.

Each of the next $m$ lines contains a string $g_j~(|g_j| = w)$ with a description of a single gate. Each character of $g_j$ is one of "A", "O", "X", "a", "o", "x".

###### Output

Print $m$ lines. The $i$-th line should contain the number of ordered pairs of variables for which the $i$-th gate returns zero.

## Examples

###### Input


```text
4 3 1  
13 10 6  
AXoA  

```
###### Output


```text
3  

```
###### Input


```text
1 7 6  
0 1 1 0 1 0 0  
A  
O  
X  
a  
o  
x  

```
###### Output


```text
40  
16  
25  
9  
33  
24  

```
###### Input


```text
6 2 4  
47 12  
AOXaox  
AAaaAA  
xxxxxx  
XXXXXX  

```
###### Output


```text
2  
3  
0  
2  

```
###### Input


```text
2 2 2  
2 0  
xO  
Ox  

```
###### Output


```text
2  
0  

```
## Note

In the first test case, the inputs in binary are $1101$, $1010$, $0110$. The pairs that return $0$ are $(13, 6)$, $(6, 13)$, and $(6, 6)$. As it was already mentioned in the problem statement, $13 \oplus 10 = 10 \oplus 13 = 12$. The other pairs are $13 \oplus 13 = 11$, $10 \oplus 10 = 8$ and $10 \oplus 6 = 6 \oplus 10 = 4$. 



#### Tags 

#2800 #NOT OK #bitmasks #brute_force #fft #math 

## Blogs
- [All Contest Problems](../Lyft_Level_5_Challenge_2018_-_Elimination_Round.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
