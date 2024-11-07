![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Mail Delivery

  * Task
  * Statistics

CSES - Mail Delivery

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to deliver mail to the inhabitants of a city. For this reason,
you want to find a route whose starting and ending point are the post office,
and that goes through every street exactly once.

# Input

The first input line has two integers $n$ and $m$: the number of crossings and
streets. The crossings are numbered $1,\,2,\ldots,\,n$, and the post office is
located at crossing $1$.

After that, there are m lines describing the streets. Each line has two
integers $a$ and $b$: there is a street between crossings $a$ and $b$. All
streets are two-way streets.

Every street is between two different crossings, and there is at most one
street between two crossings.

# Output

Print all the crossings on the route in the order you will visit them. You can
print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

# Constraints

$2\leq n\leq 10^5$  
$1\leq m\leq 2 . 10^5$  
$1\leq a,\,b\leq n$

# Example

Input:

``` 6 8 1 2 1 3 2 3 2 4 2 6 3 5 3 6 4 5 ```

Output:

``` 1 2 6 3 2 4 5 3 1 ```

#### Graph Algorithms

... Planets and KingdomsGiant PizzaCoin CollectorMail DeliveryDe Bruijn
SequenceTeleporters PathHamiltonian FlightsKnight's Tour...

* * *

