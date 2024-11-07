<h1 style='text-align: center;'> J. Jackets and Packets</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Pak Chanek has $N$ jackets that are stored in a wardrobe. Pak Chanek's wardrobe has enough room for two stacks of jackets, namely the left stack and the right stack. Initially, all $N$ jackets are in the left stack, while the right stack is empty. Initially, the $i$-th jacket from the top of the left stack has colour $C_i$.

Pak Chanek wants to pack all of those jackets into some packets, such that the jackets in the same packet has the same colour. However, it is possible for two jackets with the same colour to be in different packets.

Pak Chanek can do two kinds of operations: 

* Pak Chanek can pick any number of jackets from the top from one stack as long as the colour is the same, then take those jackets out of the stack and pack them into a packet. This packing operation takes $X$ minutes, no matter how many jackets are packed.
* Pak Chanek can move one topmost jacket from one stack to the top of the other stack (possibly right to left or left to right). This moving operation takes $Y$ minutes.

Determine the minimum time to pack all jackets!

## Input

The first line contains three integers $N$, $X$, and $Y$ ($1 \leq N \leq 400$; $1\leq X,Y\leq10^9$) — the number of jackets, the time to do a packing operation, and the time to do a movement operation.

The second line contains $N$ integers $C_1, C_2, C_3, \ldots, C_N$ ($1 \leq C_i \leq N$) — the colour of each jacket.

## Output

An integer representing the minimum time to pack all jackets.

## Example

## Input


```

8 7 2
4 4 2 4 1 2 2 1

```
## Output


```

38

```
## Note

Let's denote the contents of the two stacks using arrays that represent the colours of the jackets in the stack from top to bottom. Initially, the two stacks form $[4, 4, 2, 4, 1, 2, 2, 1]$ and $[]$.

Pak Chanek can do the following sequence of operations: 

1. Movement from left to right. The two stacks become $[4, 2, 4, 1, 2, 2, 1]$ and $[4]$.
2. Movement from left to right. The two stacks become $[2, 4, 1, 2, 2, 1]$ and $[4, 4]$.
3. Packing for $1$ jacket from the top of the left stack. The two stacks become $[4, 1, 2, 2, 1]$ and $[4, 4]$.
4. Movement from left to right. The two stacks become $[1, 2, 2, 1]$ and $[4, 4, 4]$.
5. Movement from left to right. The two stacks become $[2, 2, 1]$ and $[1, 4, 4, 4]$.
6. Packing for $2$ jackets from the top of the left stack. The two stacks become $[1]$ and $[1, 4, 4, 4]$.
7. Movement from right to left. The two stacks become $[1, 1]$ and $[4, 4, 4]$.
8. Packing for $3$ jackets from the top of the right stack. The two stacks become $[1, 1]$ and $[]$.
9. Packing for $2$ jackets from the top of the left stack. The two stacks become $[]$ and $[]$.

In total, it requires a time of $2+2+7+2+2+7+2+7+7=38$ minutes to pack all jackets. It can be proven that there are no other ways that are faster.



#### tags 

#2800 #dp 