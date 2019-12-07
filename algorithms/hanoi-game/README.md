# Torres de Hanoi

El juego de las torres de Hanoi, es un juego matemático. Consiste en tres barras y una cantidad variable de discos que se pueden apilar en cualquier barra.
El juego inicia con los discos ordenados en una torre en una de las barras con el disco más chico hasta arriba.  
El objetivo del juego es mover la torre entera de una barra a otra siguiendo las siguientes reglas:
1. Sólo un disco puede moverse en cada turno.
2. Cada turno consiste en mover el disco de la cima de una torre y colocarlo en la cima de otra.
3. No se puede colocar un disco sobre uno más chico.

Con 3 discos, el juego puede ser completado en 7 turnos. El número mínimo de turnos en el que se puede completar el juego es _2^n-1_, donde _n_ es el número de discos.

El código que se encuentra en este siitio, es una implementación de dicho juego en el lenguaje C++ utilizando _stacks_ basados en _linked lists_.