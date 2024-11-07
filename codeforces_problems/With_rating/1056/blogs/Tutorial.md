# Tutorial


### [1056A - Determine Line](../problems/A._Determine_Line.md "Mail.Ru Cup 2018 Round 3")

This is a simple implementation problem. A tram line is suitable if it appears at all stops, i.e. exactly $n$ times. Make an array of $100$ integers and count how many times each integer appears. Then just output each index where the array hits $n$.

Author, preparation: [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN").

 Tutorial is loading...Author, preparation: [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot").

 Tutorial is loading...Author, preparation: [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN").

 Tutorial is loading...Author, preparation: [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN").

 
### [1056E - Check Transcription](../problems/E._Check_Transcription.md "Mail.Ru Cup 2018 Round 3")

The solution builds on one key observation.

Suppose we know the length of r0. Then, since the number of '0' and '1' is fixed and the length of the resulting string is also fixed, we know the length of r1 (or know, that there is no integer-sized r1 possible).

So let's bruteforce the length of r0, calculate the length of r1 and then check whether the corresponding substrings of t are equal (so r0 and r1 can be defined correctly).

Sounds like O(|s||t|) (since the number of candidates is ≤|t| and check can be done in |s|, for example with hashes)? Haha, it is O(|t|).

First, notice that it is not exactly important whether we bruteforce length of r0 or r1 — one of them defines the other one.

So suppose we are bruteforcing over the letter with larger number of occurrences in pattern string s.

Let's denote it's number of occurrences as c, this way, clearly, there are at most |t|c candidates. And each candidate is checked in |s|. So the whole time is |t|c|s|

Since we used the more frequent letter, c≥|s|2. And hence |t|c|s|≤2|t|.

Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot"), preparation: [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot").

 Tutorial is loading...Author, preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon").

 Tutorial is loading...Author, preparation: [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN").

 Tutorial is loading...Author [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN"), preparation: [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN"), [300iq](https://codeforces.com/profile/300iq "Legendary Grandmaster 300iq").

Huge thanks to [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot") and [300iq](https://codeforces.com/profile/300iq "Legendary Grandmaster 300iq") for discussing the problems and general invaluable help in preparation!

