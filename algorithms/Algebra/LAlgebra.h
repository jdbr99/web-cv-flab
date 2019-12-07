#ifndef LALGEBRA_H
#define LALGEBRA_H

#define ELEM long long

// Máximo común divisor
ELEM gcd( ELEM, ELEM );
// Mínimo común múltiplo
ELEM lcm( ELEM, ELEM );

// Extended Euclidean Algorithm
void extendedGcd( ELEM, ELEM, ELEM&, ELEM& );

// Binary exponentiation
ELEM binpow( ELEM, ELEM );
ELEM binpowMod( ELEM, ELEM, ELEM );

#endif
