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
        UndirectedGraphNode *newNode = NULL;
        unordered_map< int, UndirectedGraphNode * > occur;
        dfs( newNode, node, occur );
        return newNode;
    }
    void dfs( UndirectedGraphNode *&cur, UndirectedGraphNode *node, unordered_map< int, UndirectedGraphNode * >& occur ){
        if( node==NULL ) return;
        cur = new UndirectedGraphNode(node->label);
        cur->neighbors = vector<UndirectedGraphNode *>( node->neighbors.size(), NULL );
        if( occur.find(node->label)==occur.end() ){
            occur[cur->label] = cur;
        }
        for( int i = 0; i < node->neighbors.size(); ++i ){
            if( occur.find(node->neighbors[i]->label)==occur.end() ){
                dfs( cur->neighbors[i], node->neighbors[i], occur );
            }else{
                cur->neighbors[i] = occur[ node->neighbors[i]->label ];
            }
        }
    }
    
};