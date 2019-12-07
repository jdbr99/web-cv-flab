#include "LAlgebra.h"

// Máximo común divisor
ELEM gcd( ELEM a, ELEM b ) {
    // Eucides Algorithm
    if ( b == 0 )
        return a;
    return ( b, a % b );
}
// Mínimo común múltiplo
ELEM lcm( ELEM a, ELEM b ) {
    ELEM tmp = gcd( a, b );
    return ( a / tmp ) * b;
}

// Extended Euclidean Algorithm
void extendedGcd( ELEM a, ELEM b, ELEM& r, ELEM& s ) {
    if ( a == 0 ) {
        r = 0;
        s = 1;
        return;
    }
    ELEM tmp;
    extendedGcd( b % a, a, r, s );
    tmp = r;
    r   = s - ( b / a ) * r;
    s   = tmp;
}

// Binary exponentiation
ELEM binpow( ELEM a, ELEM b ) {
    if ( b == 0 )
        return 1;
    ELEM tmp = binpow( a, b / 2 );
    if ( b & 1 )
        return tmp * tmp * b;
    return tmp * tmp;
}
ELEM binpowMod( ELEM a, ELEM b, ELEM mod ) {
    if ( b == 0 )
        return 1;
    ELEM tmp = binpow( a, b / 2 );
    tmp      = ( tmp * tmp ) % mod;
    if ( b & 1 )
        return ( tmp * b ) % mod;
    return tmp;
}
