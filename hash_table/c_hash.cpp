#include "include.h"

int& c_hash_table::m_get_key( ) {
    return m_key;
}

deque<int>& c_hash_table::get_key_list( ) {
    return m_key_list;
}

deque<hash_t>& c_hash_table::get_hash( ) {
	return m_hash;
}

bool c_hash_table::is_the_same_key( const int& m_key, const int& key ) {
    return m_key == key;
}

bool c_hash_table::is_repeated_value( const int& value ) {
    for ( auto& hash : m_hash ) {
        if ( is_the_same_key( m_key, hash.key ) ) {
            hash.values_list.push_back( value );
            return true;
        }
    }
    return false;
}

//метод середины квадрата
void c_hash_table::midsquare_key( int& key ) {
    key *= key;
    key >>= 11;
    key %= 1024;
}

void c_hash_table::show_iterator( const hash_t& hash ) {
    cout << "value:" << hash.value << " key:" << hash.key << std::endl;
    if ( !hash.values_list.empty( ) ) {
        cout << "key insist, other values:";
        for ( const auto& values_list : hash.values_list ) {
            cout << values_list << " ";
        }
        cout << endl;
    }
}

void c_hash_table::add( const int& value ) {
    m_key = rand( ) % 1024;
    m_key_list.push_back( m_key );
    midsquare_key( m_key );

    if ( !is_repeated_value( value ) ) {
        hash_t hash = { value, m_key };
        m_hash.push_back( hash );
    }
}

void c_hash_table::show( ) {
    for ( const auto& hash : m_hash ) {
        show_iterator( hash );
    }
}

void c_hash_table::show_unhash( const int& idx ) {
    if ( idx < 0 || idx >= m_key_list.size( ) ) {
        return;
    }
    cout << "unhashing\n";
    auto key = m_key_list.at( idx );
    midsquare_key( key );
    for ( const auto& hash : m_hash ) {
        if ( is_the_same_key( key, hash.key ) ) {
            show_iterator( hash );
        }
    }
}

c_hash_table::c_hash_table( const int& value ) {
    add( value );
}


c_hash_table::~c_hash_table( ) {

}

