Intuition:
The dfs helper functions has three options:
-1 : If we are already covered by a camera
0 : we have a camera
1 : we need a camera.
So, the first condition - either left child or right child is 1 - we need a camera for the current node.
The second condition - either left child or right child is -1 - we are covered.
If neither of these conditions are true, we need a camera.