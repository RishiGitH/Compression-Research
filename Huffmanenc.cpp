#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
 
using namespace std;
 
struct node {
    int freq;
    char ch;
    node* left;
    node* right;
 
    node( char c = ' ', int f = -1 )
    {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
 
    node( node* c1, node* c2 )
    {
        ch = ' ';
        freq = c1 -> freq + c2 -> freq;
        left = c1;
        right = c2;
    }
 
    bool operator ()( const node& l, const node &r)
    {
              return l.freq >r.freq;
        }
 
    void traverse( string code = "" ) const;
 
};
 
void node::traverse( string code ) const
{
    if( left ) {
        left->traverse( code + '0' );
        right->traverse( code + '1' );
    } else {
        cout << ch << "\t" << freq << "\t" << code << endl;
    }
}
 
int main() {
    string str;
    int cnt;
    char c;
    priority_queue< node, vector<node>, node > q;
 
    cin >> str;
 
    for( int i = 65; i <= 90 ; i++ ) {
        c = (char)i;
        cnt = (int)count( str.begin(), str.end(), c );
        if( cnt ) {
            q.push( node( c, cnt ) );
            cnt = 0;
        }
    }
 
    for( int i = 97; i <= 122 ; i++ ) {
                c = (char)i;
                cnt = (int)count( str.begin(), str.end(), c );
                if( cnt ) {
                        q.push( node( c, cnt ) );
                        cnt = 0;
                }
        }
 
    while( q.size() != 1 ) {
        node *left = new node( q.top() );
        q.pop();
        node *right = new node( q.top() );
        q.pop();
        q.push( node( left, right ) );
    }
 
    cout << "Encoding " << endl;
    cout << "Word" << "\t" << "freq" << "\t" << "code" << endl;
    q.top().traverse();
}