#wordladder2
##BFS,use two unordered_set to store current level and the previous level
##because the graph exists curcuit, use set to avoid dunplicating nodes
#
##Marked Problems
Gas Station
#Tortoise and Hare Algorithm( Finding cycle in Linked list )
##Prove:
###Length of head to cycle started node:x
###Length of the cycle: y
###Let hare run two steps while tortoise runs one step
###while both of them entered the cycle, the hare is definetly to overlap the tortoise at some node, we define it as m:
The hare totally runs: x + k*y + m
The tortoise totally runs: x + t*y + m
Thus, k*y = 2t*y + x + m
we have (x + m) mod y = 0
We can conclude that if the hare run more x steps, it will reach the cycle's starting node.
