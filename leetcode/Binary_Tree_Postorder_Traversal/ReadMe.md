	In postorder, the root node will be visited at the end.

	So, for a node Cur, if it is not a leaf node, the previously visited node should be its left child or right child. For such reason, we can determin next step by comparing the last visited node to current node's sons. 
	
	When the current node is a leaf node, we just visit it and pop it from the stack.
	