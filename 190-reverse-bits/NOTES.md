We create a new variable to store the answer i.e. the reversed binary representation.
​
Initially ans variable is 0. To store more bits we need to expand its space.
So we perform ans<<=1 which can also be written as ans = ans << 1.
This left shifts ans variable by 1 space towards its left. So now ans is 0 0.
​
We read only the last bit of the given binary form n, using & operation like n & 1.
​
Then we add this last bit of n to ans. If the last bit of n was 1, then ans is 0 1 now.
We can add in 2 ways: ans = ans + (n&1) or ans = ans | (n&1).
The second OR operation is much faster.
​
As we have dealt with the current last bit, we remove it by right shifting n; n = n>>1.
​
We repeat all the above steps 2 to 5, for 32 times for each of the 32 bits.