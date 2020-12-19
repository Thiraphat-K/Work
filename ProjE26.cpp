#include <iostream>
#include <map>

using namespace std;

int cycle_length( int d )
{
  map< int, int > r;
  int n = 1, i = 1;
  while ( n != 0 ) {
    n = ( 10 * n  ) % d;
    if ( r.count( n ) == 1 )
      break;
    r[ n ] = i++;
  }
  return  n == 0 ? 0 : i - r[ n ];
}

int main()
{
  int lmax = 0, d;
  for ( int i = 2; i < 1000; i++ ) {
    int l = cycle_length( i );
    if ( l > lmax ) {
      lmax = l;
      d = i;
    }
  }
  cout << "Longest cycle = " << lmax << ", for d = " << d << endl;
}