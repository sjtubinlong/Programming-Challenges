vector< vector<int> > levelOrderII( TreeNode* root )
{
	vector<vector<int>> vc;
    if( root==NULL )
	{
		return vc;
	}
	vector<int> cur;
    cur.push_back(root->val);
    vector<TreeNode*> curNodes;
    curNodes.push_back(root);
	while( cur.size()!=0 )
	{
        vc.push_back( cur );
        vector<TreeNode*> parents = curNodes;
        curNodes.clear();
        cur.clear();
		for( int i = 0; i != parents.size(); ++i )
        {
            if(parents[i]->left)
            {
                curNodes.push_back( parents[i]->left );
                cur.push_back( parents[i]->left->val );
            }
            if(parents[i]->right)
            {
                curNodes.push_back( parents[i]->right );
                cur.push_back( parents[i]->right->val );   
            }
        }
	}
}