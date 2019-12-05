# Método de Newton-Raphson

El método de **Newton-Raphson** es un método de cálculo utilizado para encontrar raíces de una función. Es un algoritmo que iterativamente encuentra mejores aproximaciones.

Uno de los problemas más grandes que se presentan al implementar este algoritmo es el problema de _desbordamiento de variables_, debido a que la cantidad de números decimales encontrados es incrementalmente mayor.

## Explicación

El algoritmo requiere una función derivable en un punto $x_0$ y un punto $x_0$ inicial para calcular una aproximación inicial.

Este algoritmo ejecuta iterativamente la función
\[ x_n+1 = \frac{f(x_n)}{f'(x_n)} \]
y retorna la aproximación después de las iteraciones especificadas.

```go
package main

import (
  "fmt"
  // Utilizamos el módulo "calculus" para derivar y procesar la string de la función
  clc "github.com/TheDemx27/calculus"
)

func main() {
  // Declaración de las variables utilizadas para entrada de usuario
  var (
    usrInput string
    usrX float64
    usrIt uint8
  )
  
  // Leemos la entrada del usuario
  fmt.Println("Input single variable function:")
  fmt.Scanln(&usrInput)

  fmt.Println("Input initial x value:")
  fmt.Scanln(&usrX)

  fmt.Println("Input amount of iterations:")
  fmt.Scanln(&usrIt)

  // Mostramos al usuario la aproximación encontrada después de las iteraciones especificadas
  fmt.Println("The approximation is:")
  fmt.Println(NewtonRaphson(usrInput, usrX, usrIt))
}

// La función recibe un string de función, un x inicial y la catidad de veces a iterar. Realiza una aproximación inicial y luego itera la fórmula la cantidad de veces especificada
func NewtonRaphson(funcStr string, x0 float64, iterations uint8) float64 {
  f := clc.NewFunc(funcStr)
  approximation := (x0 - (f.Eval(x0) / f.Diff(x0)))
  for i := 0; i < int(iterations); i++ {
    approximation -= f.Eval(approximation)/f.Diff(approximation)
  }
  return approximation
}
```
