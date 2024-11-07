<h1 style='text-align: center;'> H. GCD is Greater</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

In the evenings during the hike, Kirill and Anton decided to take out an array of integers $a$ of length $n$ from their backpack and play a game with it. The rules are as follows:

1. Kirill chooses from $2$ to $(n-2)$ numbers and encircles them in red.
2. Anton encircles all the remaining numbers in blue.
3. Kirill calculates the greatest common divisor ([GCD](https://en.wikipedia.org/wiki/Greatest_common_divisor)) of all the red numbers.
4. Anton calculates the [bitwise AND](https://en.wikipedia.org/wiki/Bitwise_operation#AND) of all the blue numbers and adds the number $x$ to the result.
5. If the GCD of all the red numbers is strictly greater than the sum of the bitwise AND of all the blue numbers and the number $x$, then Kirill wins; otherwise, Anton wins.

Help Kirill to beat Anton or tell if it's impossible.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 20\,000$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers $n$ and $x$ ($4\le n \le 4\cdot 10^5$, $0 \le x \le 4\cdot 10^5$) — the number of integers and the number $x$ respectively.

The second line contains an array $a$ of length $n$ ($1 \le a_i \le 4\cdot 10^5$).

It is guaranteed that the sum of $n$ for all test cases does not exceed $4\cdot 10^5$. It is also guaranteed that the sum of the maximum values of $a_i$ for each test case does not exceed $4\cdot 10^5$.

### Output

For each test case, output "YES" on the first line if the condition can be met, on the second line, output the number of chosen numbers by Kirill and the numbers themselves in any order separated by a space, and on the third line, output the size of the second set and the numbers in it.

Otherwise, output "NO".

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

## Example

### Input


```text
84 14 3 1 84 14 5 8 45 01 1 1 1 15 231 63 127 63 314 11 3 3 38 34 3 4 1 2 2 5 34 21 4 3 68 4831 61 37 15 53 26 61 12
```
### Output

```text

YES
2 4 8
2 3 1 
YES
2 4 4
2 5 8 
NO
YES
2 63 63
3 31 127 31
YES
2 3 3
2 1 3
YES
2 4 4
6 3 1 2 2 5 3
YES
2 3 6
2 1 4 
YES
2 61 61
6 31 37 15 53 26 12

```


#### Tags 

#2600 #NOT OK #brute_force #data_structures #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_935_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
