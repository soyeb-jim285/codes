<h1 style='text-align: center;'> A. Division?</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Codeforces separates its users into $4$ divisions by their rating:

* For Division 1: $1900 \leq \mathrm{rating}$
* For Division 2: $1600 \leq \mathrm{rating} \leq 1899$
* For Division 3: $1400 \leq \mathrm{rating} \leq 1599$
* For Division 4: $\mathrm{rating} \leq 1399$

Given a $\mathrm{rating}$, print in which division the $\mathrm{rating}$ belongs.

### Input

The first line of the input contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of testcases.

The description of each test consists of one line containing one integer $\mathrm{rating}$ ($-5000 \leq \mathrm{rating} \leq 5000$).

### Output

For each test case, output a single line containing the correct division in the format "Division X", where $X$ is an integer between $1$ and $4$ representing the division for the corresponding rating.

## Example

### Input


```text
7-789129913001399140016792300
```
### Output

```text

Division 4
Division 4
Division 4
Division 4
Division 3
Division 2
Division 1

```
## Note

For test cases $1-4$, the corresponding ratings are $-789$, $1299$, $1300$, $1399$, so all of them are in division $4$.

For the fifth test case, the corresponding rating is $1400$, so it is in division $3$.

For the sixth test case, the corresponding rating is $1679$, so it is in division $2$.

For the seventh test case, the corresponding rating is $2300$, so it is in division $1$.



#### Tags 

#800 #OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_784_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
