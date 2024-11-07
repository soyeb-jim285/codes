def solve(b, c, d):
    # dp[i][carry] means whether it is possible to satisfy the equation up to the ith bit with the given carry
    dp = [[False for _ in range(2)] for _ in range(32 + 1)]  # We have 32 bits
    dp[0][0] = True  # Initial state with no carry

    # Result to store the solution
    a = 0

    # Iterate over all bits
    for i in range(32):  # Processing 32 bits (assuming 32-bit integers)
        for carry in range(2):  # Two possible carry states: 0 or 1
            if not dp[i][carry]:
                continue

            b_i = (b >> i) & 1
            c_i = (c >> i) & 1
            d_i = (d >> i) & 1

            # Try setting a_i = 0
            a_i = 0
            left = d_i + (c_i & a_i) + carry
            right = a_i | b_i
            if left % 2 == right:
                new_carry = left // 2
                dp[i + 1][new_carry] = True

            # Try setting a_i = 1
            a_i = 1
            left = d_i + (c_i & a_i) + carry
            right = a_i | b_i
            if left % 2 == right:
                new_carry = left // 2
                dp[i + 1][new_carry] = True

    # Backtrack to reconstruct the value of a
    carry = 0
    for i in range(31, -1, -1):
        b_i = (b >> i) & 1
        c_i = (c >> i) & 1
        d_i = (d >> i) & 1

        # Try setting a_i = 0
        a_i = 0
        left = d_i + (c_i & a_i) + carry
        right = a_i | b_i
        if dp[i][carry] and left % 2 == right:
            new_carry = left // 2
            if dp[i][new_carry]:
                carry = new_carry
                continue  # a_i is 0, no need to set

        # Otherwise, set a_i = 1
        a |= 1 << i
        a_i = 1
        left = d_i + (c_i & a_i) + carry
        right = a_i | b_i
        carry = left // 2

    return a


print(solve(8, 5, 14))  # Output: 3
