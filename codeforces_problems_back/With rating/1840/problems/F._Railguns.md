<h1 style='text-align: center;'> F. Railguns</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tema is playing a very interesting computer game.

During the next mission, Tema's character found himself on an unfamiliar planet. Unlike Earth, this planet is flat and can be represented as an $n \times m$ rectangle.

Tema's character is located at the point with coordinates $(0, 0)$. In order to successfully complete the mission, he needs to reach the point with coordinates $(n, m)$ alive.

Let the character of the computer game be located at the coordinate $(i, j)$. Every second, starting from the first, Tema can:

* either use vertical hyperjump technology, after which his character will end up at coordinate $(i + 1, j)$ at the end of the second;
* or use horizontal hyperjump technology, after which his character will end up at coordinate $(i, j + 1)$ at the end of the second;
* or Tema can choose not to make a hyperjump, in which case his character will not move during this second;

The aliens that inhabit this planet are very dangerous and hostile. Therefore, they will shoot from their railguns $r$ times.

Each shot completely penetrates one coordinate vertically or horizontally. If the character is in the line of its impact at the time of the shot (at the end of the second), he dies.

Since Tema looked at the game's source code, he knows complete information about each shot — the time, the penetrated coordinate, and the direction of the shot.

What is the minimum time for the character to reach the desired point? If he is doomed to die and cannot reach the point with coordinates $(n, m)$, output $-1$.

## Input

The first line of the input contains a single integer $T$ ($1 \le T \le 10^4$) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n \cdot m \le 10^4$) — the size of the planet, its height and width.

The second line of each test case contains a single integer $r$ ($1 \le r \le 100$) — the number of shots.

Then follow $r$ lines, each describing one shot.

A shot is described by three integers $t$, $d$, $coord$. Where $t$ is the second at which the shot will be fired ($1 \le t \le 10^9$). $d$ is the direction of the shot ($d = 1$ denotes a horizontal shot, $d = 2$ denotes a vertical shot). $coord$ is the size of the penetrated coordinate ($0 \le coord \le n$ for $d = 1$, $0 \le coord \le m$ for $d = 2$).

The sum of the products $n \cdot m$ over all test cases does not exceed $10^4$.

## Output

For each test case, output a single number — the minimum time for the character to reach the coordinate $(n, m)$, or $-1$ if he is doomed to die.

## Example

## Input


```

51 341 2 02 2 13 2 24 1 13 362 1 02 1 12 1 22 2 02 2 12 2 22 137 1 22 1 17 2 12 259 1 23 2 05 1 24 2 27 1 04 676 1 212 1 34 1 017 2 31 2 616 2 63 2 4
```
## Output


```

5
-1
3
6
10

```
## Note

In the first test case, the character can move as follows: $(0, 0) \rightarrow (0, 1) \rightarrow (0, 2) \rightarrow (0, 3) \rightarrow (0, 3) \rightarrow (1, 3)$.

In the second test case, the character will not be able to leave the rectangle that will be completely penetrated by shots at the second $2$.



#### tags 

#2200 #brute_force #dfs_and_similar #dp #graphs 