<h1 style='text-align: center;'> A. Garland</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a garland consisting of $4$ colored light bulbs, the color of the $i$-th light bulb is $s_i$.

Initially, all the light bulbs are turned off. Your task is to turn all the light bulbs on. You can perform the following operation any number of times: select a light bulb and switch its state (turn it on if it was off, and turn it off if it was on). The only restriction on the above operation is that you can apply the operation to a light bulb only if the previous operation was applied to a light bulb of a different color (the first operation can be applied to any light bulb).

Calculate the minimum number of operations to turn all the light bulbs on, or report that this is impossible.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The single line of each test case contains $s$ — a sequence of $4$ characters, where each character is a decimal digit. The $i$-th character denotes the color of the $i$-th light bulb.

### Output

For each test case, print one integer — the minimum number of operations to turn all the light bulbs on. If it is impossible to turn all the bulbs on, print -1.

## Example

### Input


```text
3954600003313
```
### Output

```text

4
-1
6

```
## Note

In the first example, all the colors are different, so you can just turn all the bulbs on in $4$ operations.

In the second example, it is impossible to turn all the bulbs on, because after you switch one light bulb, it is impossible to turn the others on.

In the third example, you can proceed as follows: turn the first light bulb on, turn the third light bulb on, turn the fourth light bulb on, turn the third light bulb off, turn the second light bulb on, turn the third light bulb on.



#### Tags 

#800 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_145_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
