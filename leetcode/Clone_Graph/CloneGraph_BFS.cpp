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
        UndirectedGraphNode *root = new UndirectedGraphNode( node->label );
        unordered_map< UndirectedGraphNode *, UndirectedGraphNode * > occur;
        occur[node] = root;
        queue<UndirectedGraphNode *> Q;
        Q.push(node);
        while( !Q.empty() ){
            UndirectedGraphNode *cur = Q.front();
            Q.pop();
            for( int i = 0; i < cur->neighbors.size(); ++i ){
                if( occur.find(cur->neighbors[i]) == occur.end() ){
                    UndirectedGraphNode *newNode = new UndirectedGraphNode( cur->neighbors[i]->label );
                    occur[ cur->neighbors[i] ] = newNode;
                    occur[cur]->neighbors.push_back(newNode);
                    Q.push( cur->neighbors[i] );
                }else{
                    occur[cur]->neighbors.push_back( occur[cur->neighbors[i]] );
                }
            }
            
        }
        return root;
    }
};