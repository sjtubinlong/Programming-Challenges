class Solution {
public:
    static vector< vector<string> > findLadders( string start, string end, unordered_set<string> & dict ) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<string> > result;
        unordered_set<string> cur_layer;
        unordered_set<string> pre_layer;
        unordered_map< string, vector<string> > parents;
        cur_layer.insert(start);
        dict.insert( end );
        dict.erase(start);
        bool findIt = false;
        while( cur_layer.size() != 0 )
        {
            pre_layer = cur_layer;
            cur_layer.clear();
        	for( unordered_set<string>::iterator it = pre_layer.begin(); 
                it != pre_layer.end(); ++it )
        	{
        	    string cur_str = *it ;
        		if( cur_str==end )
        		{
        		    findIt = true;
        		    cur_layer.clear();
        			break;
        		}
        		for( int j = 0; j != cur_str.size(); ++j )
        		{
        			string tmp_str(cur_str);
	        		for( int k = 'a'; k <= 'z'; ++k )
	        		{
	        			if( tmp_str[j] == k )
	        			{
	        				continue;
	        			}
	        			tmp_str[j] = k;
	        			unordered_set<string>::iterator it = dict.find( tmp_str );
	        			if( it != dict.end() )
	        			{
	        				cur_layer.insert( tmp_str );
	        				parents[tmp_str].push_back(cur_str);
	        			}
	        		}
        		}
        	}
        	for( unordered_set<string>::iterator it = cur_layer.begin(); 
                it != cur_layer.end(); ++it  )
        	{
        		dict.erase(*it);
        	}
        }
        if( !findIt )
            return result;
        //cout<<parents[end][0]<<endl;
        vector< string > path;
        buildPath( parents, result, path, end );
        return result;
    }
    static void buildPath( unordered_map<string, vector<string> >&parents, vector< vector<string> >& result, vector<string> &path, string &cur )
    {
    	if( parents[cur].size()==0 )
    	{
    	    path.push_back(cur);
    	    vector<string> revPath = path;
    	    reverse( revPath.begin(), revPath.end() );
    		result.push_back( revPath );
    		path.pop_back();
    		return;
    	}
    	path.push_back(cur);
    	for( int i = 0; i != parents[cur].size(); ++i )
    	{
    		buildPath( parents, result, path, parents[cur][i] );
    	}
    	path.pop_back();
    }
};
