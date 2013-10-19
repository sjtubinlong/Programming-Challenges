/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( node==NULL ) return NULL;
        unordered_map< int, UndirectedGraphNode * > occur;
        return dfs( node, occur );
    }
    UndirectedGraphNode * dfs( UndirectedGraphNode *node, unordered_map< int, UndirectedGraphNode * >& occur ){
        if( node==NULL ) return NULL;
        if( occur.find(node->label) != occur.end() ){
            return occur[node->label];
        }
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        occur[ node->label ] = newNode;
        for( int i = 0; i < node->neighbors.size(); ++i ){
            newNode->neighbors.push_back( dfs(node->neighbors[i], occur) );
        }
        return newNode;
    }
    
};