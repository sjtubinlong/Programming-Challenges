
	Proof:
	1. Assume the length from head to the cycle is x
	2. Assume the cycle itself's length is y.
	3. Pointer slow run one step every time, and Pointer fast run two steps each time.
	4. It is obvious that the faster will meet the slower at some node in the cycle. we define the length from the start node to such node is z.
	5. the slower totally run x + ky + z steps, and the faster x + py + z, so x + py + z = 2(x + ky + z)
	6. Thus, we have  x = (p - 2k - 1)y + (y - z)
	7. Then let the slower start from the head node again, and finally they will meet each other at the cycle start point.
	
	* Hint: The fast start from point z, and keep rolling in the cycle for p - 2k - 1 times, then run y - z more step to the start node of cycle. Meanwhile, the slower entered the cycle. 

