![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Monsters

  * Task
  * Statistics

CSES - Monsters

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You and some monsters are in a labyrinth. When taking a step to some direction
in the labyrinth, each monster may simultaneously take one as well. Your goal
is to reach one of the boundary squares without ever sharing a square with a
monster.

Your task is to find out if your goal is possible, and if it is, print a path
that you can follow. Your plan has to work in any situation; even if the
monsters know your path beforehand.

# Input

The first input line has two integers $n$ and $m$: the height and width of the
map.

After this there are $n$ lines of $m$ characters describing the map. Each
character is `.` (floor), `#` (wall), `A` (start), or `M` (monster). There is
exactly one `A` in the input.

# Output

First print "YES" if your goal is possible, and "NO" otherwise.

If your goal is possible, also print an example of a valid path (the length of
the path and its description using characters `D`, `U`, `L`, and `R`). You can
print any path, as long as its length is at most $n \cdot m$ steps.

# Constraints

  * $1 \le n,m \le 1000$

# Example

Input:

``` 5 8 ######## #M..A..# #.#.M#.# #M#..#.. #.###### ```

Output:

``` YES 5 RRDDR ```

#### Graph Algorithms

... Message RouteBuilding TeamsRound TripMonstersShortest Routes IShortest
Routes IIHigh ScoreFlight Discount...

* * *

