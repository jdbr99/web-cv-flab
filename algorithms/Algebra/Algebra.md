# Algebra

Es una librería para C/C++ para realizar cálculos matemáticos como los siguientes:

## Máximo Común Divisor
Función **gcd(ELEM, ELEM)**, esta función toma dos numeros y devulve su máximo común divisor.

## Mínimo Común Múltiplo
Función **lcm(ELEM, ELEM)**, esta función toma dos números y devuelve su mínimo común Múltiplo.

## Algoritmo Extendido de Euclides
Función **extendedGcd(ELEM, ELEM, ELEM&, ELEM&)**, esta función recibe dos referencias de ELEM y en cada una asigna un valor r, s. Son una combinación lineal de **a*r + b*s = gcd(a,b)**.

## Exponensiación Binaria
Función **binpow(ELEM, ELEM)**, esta función toma dos valores a, b y devuelve el resultado de la operación a^b.
**Complejidad** logb.

## Exponensiación Binaria con Módulo
Función **binpowMod(ELEM, ELEM, ELEM)**, esta funcíon recibe valores a,b,mod. Devuelve el resultado de la operación (a^b) mód mod.
**Complejidad** logb.
