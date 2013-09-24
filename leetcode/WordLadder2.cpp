class Solution {
public:
    static vector< vector<string> > findLadders( string start, string end, unordered_set<string> & dict ) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> cur_layer;
        vector<string> pre_layer;
        map< string, vector<string> > parents;
        cur_layer.push_back(start);
        dict.erase( start );
        dict.insert( end );
        while( cur_layer.size() != 0 )
        {
        	pre_layer = cur_layer;
        	cur_layer.clear();
        	for( int i = 0; i != pre_layer.size(); ++i )
        	{
        		string cur_str( pre_layer[i] );
        		if( cur_str==end )
        		{
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
	        				cur_layer.push_back( tmp_str );
	        				parents[tmp_str].push_back(cur_str);
	        			}
	        		}
        		}
        	}
        	for( int i = 0; i != cur_layer.size(); ++i )
        	{
        		dict.erase(cur_layer[i]);
        	}
        }
        //cout<<parents[end][0]<<endl;
        vector< vector<string> > result;
        vector< string > path;
        buildPath( parents, result, path, end );
        return result;
    }
    static void buildPath( map<string, vector<string> >&parents, vector< vector<string> >& result, vector<string> path, string cur )
    {
    	if( parents.find(cur) == parents.end() )
    	{
    		result.push_back( path );
    		return;
    	}
    	for( int i = 0; i != parents[cur].size(); ++i )
    	{
    		//cout<<cur<<"<-"<<parents[cur][i]<<endl;
    		buildPath( parents, result, path, parents[cur][i] );
    		path.push_back( parents[cur][i]);
    	}
    }
};