class Solution {
public:
    string multiply(string num1, string num2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = num1.size();
        int m = num2.size();
        if( n==1 && num1[0]=='0' ) return string("0");
        if( m==1 && num2[0]=='0' ) return string("0");
        if( n==1 && num1[0]=='1' ) return num2;
        if( m==1 && num2[0]=='1' ) return num1;
        reverse( num1.begin(), num1.end() );
        reverse( num2.begin(), num2.end() );
        string &m1 = ( n > m ? num1 : num2 );
        string &m2 = ( n > m ? num2 : num1 );
        string result("0");
        for( int i = 0; i < m2.size(); ++i ){
            string cur;
            if( m2[i]=='0' ){
                cur = string("0");
            }else if( m2[i]=='1' ){
                cur = m1;
            }else{
                int v = 0;
                for( int j = 0; j < m1.size(); ++j ){
                    int tmp = (m2[i]-'0')*(m1[j]-'0')+v;
                    v = tmp/10;
                    cur += ( tmp%10 + '0' );
                }
                if( v > 0 ){
                    cur += ( v + '0' );
                }
            }
            reverse( cur.begin(), cur.end() );
            for( int j = 0; j < i; ++j ){
                cur += '0';
            }
            result = add( result, cur );
        }
        return result;
    }
    string add( string& num1, string num2 ){
        string result;
        int n = num1.size();
        int m = num2.size();
        reverse( num1.begin(), num1.end() );
        reverse( num2.begin(), num2.end() );
        for( int i = 0; i < n-m; ++i ){
            num2 += '0';
        }
        for( int i = 0; i < m-n; ++i ){
            num1 += '0';
        }
        n = m = num1.size();
        int v = 0;
        for( int i = 0; i < n; ++i ){
            int cur = num1[i]-'0' + num2[i]-'0'+ v;
            v = cur/10;
            result += ( cur%10 + '0' );
        }
        if( v ){
            result += ( v + '0' );
        }
        reverse( result.begin(), result.end() );
        return result;
    }
};