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
    unordered_map<int, UndirectedGraphNode *> occur;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        if(occur.find(node->label) != occur.end()){
            return occur[node->label];
        }
        UndirectedGraphNode* g = new UndirectedGraphNode(node->label);
        occur[node->label] = g;
        for(int i = 0; i < node->neighbors.size(); ++i){
            UndirectedGraphNode* nb = cloneGraph(node->neighbors[i]);
            g->neighbors.push_back(nb);
        }
        return g;
    }
};