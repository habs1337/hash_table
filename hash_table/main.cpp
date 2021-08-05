#include "include.h"


int main( ) {
	srand( time( NULL ) );
	c_hash_table hash_table( 1 );
	for ( int i = 0; i < 100; i++ ) {
		hash_table.add( rand( ) % 10 );
	}
	hash_table.show( );
	hash_table.show_unhash( 0 );
	system( "pause" );
	return 0;
}