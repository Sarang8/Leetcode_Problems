**first make a dummy node and assign its value equals to 0 and its next points to the head of the given linked list.
also make a prev node and point it to the dummy node.
Always remember that a prev node is always required wherever we have to delete a node or we have to break links and create new links . this thing is very important for beginner coders for developing their intusions in future. That's not a rule i have said it on the basis of my coding expirience.
Then you have to traverse the linked list so run a while loop.
check that if the two adjacent nodes are equal or not if the two adjacent nodes are equal then traverse trhe linked list upto ehen the adjacent nodes are not identical.
Then directly connect the link from prev->next to the head->next.
While in other case is the adjacent nodes are not equal then simply traverse the linked list by prev=prev->next.**