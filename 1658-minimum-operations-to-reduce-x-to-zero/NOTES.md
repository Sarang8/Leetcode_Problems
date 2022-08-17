**Whenever we need to work in a circular type structure like in this problem we can have a valid answer with the first few elements and the last few elements & we need to maximise/minimise the length of the anwer. We can think of picking a max size/min size subarray inside the array and subtracting it with the total length of array to find the min/max length of the original problem.**
Here, we changed x to sum of array - x, you will need to change this in future problems as well if you need to apply subarray logic.**
​
​
**This is a slighty tricky variant of Sliding Window problem.
​
Trick to make this question easy :
​
Total = Sum of all elements of the nums array.
Now find max operation to find (total-x) in the array
Check result :
​
If the result comes to 0 then return -1
else return size-result**