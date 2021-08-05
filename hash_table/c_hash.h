#pragma once


class c_hash_table {
	int m_key = 0;
	deque<int> m_key_list;
	deque<hash_t> m_hash;
	bool is_the_same_key( const int& m_key, const int& key );
	bool is_repeated_value( const int& value );
	void midsquare_key( int& key );
	void show_iterator( const hash_t& hash );
public:
	int& m_get_key( );
	deque<int>& get_key_list( );
	deque<hash_t>& get_hash( );
	void add( const int& value );
	void show( );
	void show_unhash( const int& idx );
	c_hash_table( const int& value );
	~c_hash_table( );
};