<h1 style='text-align: center;'> F. Rock-Paper-Scissors Champion</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

$n$ players are going to play a rock-paper-scissors tournament. As you probably know, in a one-on-one match of rock-paper-scissors, two players choose their shapes independently. The outcome is then determined depending on the chosen shapes: "paper" beats "rock", "rock" beats "scissors", "scissors" beat "paper", and two equal shapes result in a draw.

At the start of the tournament all players will stand in a row, with their numbers increasing from $1$ for the leftmost player, to $n$ for the rightmost player. Each player has a pre-chosen shape that they will use in every game throughout the tournament. Here's how the tournament is conducted:

* If there is only one player left, he is declared the champion.
* Otherwise, two adjacent players in the row are chosen arbitrarily, and they play the next match. The losing player is eliminated from the tournament and leaves his place in the row (with his former neighbours becoming adjacent). If the game is a draw, the losing player is determined by a coin toss.

The organizers are informed about all players' favoured shapes. They wish to find out the total number of players who have a chance of becoming the tournament champion (that is, there is a suitable way to choose the order of the games and manipulate the coin tosses). However, some players are still optimizing their strategy, and can inform the organizers about their new shapes. Can you find the number of possible champions after each such request?

### Input

The first line contains two integers $n$ and $q$ — the number of players and requests respectively ($1 \leq n \leq 2 \cdot 10^5$, $0 \leq q \leq 2 \cdot 10^5$).

The second line contains a string of $n$ characters. The $i$-th of these characters is "R", "P", or "S" if the player $i$ was going to play "rock", "paper", or "scissors" before all requests respectively.

The following $q$ lines describe the requests. The $j$-th of these lines contain an integer $p_j$ and a character $c_j$ meaning that the player $p_j$ is going to use the shape described by the character $c_j$ from this moment ($1 \leq p_j \leq n$).

### Output

Print $q + 1$ integers $r_0, \ldots, r_q$, where $r_k$ is the number of possible champions after processing $k$ requests.

## Example

### Input


```text
3 5
RPS
1 S
2 R
3 P
1 P
2 P
```
### Output


```text
2
2
1
2
2
3
```


#### Tags 

#2500 #NOT OK 

## Blogs
- [All Contest Problems](../Technocup_2019_-_Elimination_Round_4.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
