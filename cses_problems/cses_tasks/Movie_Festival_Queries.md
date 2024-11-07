![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Movie Festival Queries

  * Task
  * Statistics

CSES - Movie Festival Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

In a movie festival, $n$ movies will be shown. You know the starting and
ending time of each movie.

Your task is to process $q$ queries of the form: if you arrive and leave the
festival at specific times, what is the maximum number of movies you can
watch?

You can watch two movies if the first movie ends before or exactly when the
second movie starts. You can start the first movie exactly when you arrive and
leave exactly when the last movie ends.

# Input

The first input line has two integers $n$ and $q$: the number of movies and
queries.

After this, there are $n$ lines describing the movies. Each line has two
integers $a$ and $b$: the starting and ending time of a movie.

Finally, there are $q$ lines describing the queries. Each line has two
integers $a$ and $b$: your arrival and leaving time.

# Output

Print the maximum number of movies for each query.

# Constraints

  * $1 \le n,q \le 2 \cdot 10^5$
  * $1 \le a < b \le 10^6$

# Example

Input:

``` 4 3 2 5 6 10 4 7 9 10 5 9 2 10 7 10 ```

Output:

``` 0 2 1 ```

#### Additional Problems

... Special SubstringsPermutation InversionsMaximum Xor SubarrayMovie Festival
QueriesChess TournamentTree TraversalsNetwork RenovationGraph Girth...

* * *

