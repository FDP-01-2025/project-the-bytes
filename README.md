# NOMBRE DEL JUEGO: [BATTLE SHIP]

## Descripción del Proyecto

Battleship es un juego enfocado en la estrategia y en la destruccion de embarcaciones enemigas, en Battleship te embarcaras en una aventura en contra de la Inteligent CPU, una maquina que esta entrenada para que logre adivinar las posibles ubicaciones de tus barcos, haciendo vivir este juego como una experiencia sin frenos, en donde ganara quien logre destruir todas las embarcaciones del rival. Crees que puedas derrotarla?

## Jugabilidad de Battleship

1. Tu y la Inteligent CPU tendran un tablero 10x10 en donde podran colocar sus barcos

2. A ambos se le daran la siguiente cantidad de barcos:
  
|                               TIPOS DE EMBARCACIONES                          |
|-------------------------------------------------------------------------------|
|La maquina  y el   |La maquina y el    |La maquina y el    |La maquina y el    |
|jugador cuentan con|jugador cuentan con|jugador cuentan con|jugador cuentan con|
|un barco de cuatro |dos barcos de tres |tres barcos de dos |cuatro barcos de   |
|espacios.          |espacios.          |espacios.          |un espacio.        |
|(Leviatan      )   |(Destructores)     |(Cruceros)         |(Escoltas)         |
|-------------------|-------------------|-------------------|-------------------|

2. El jugador y el CPU poseen 10 barcos unitarios (1x1), esto para que se lleguen a colocar mas barcos y se encuentren mas dispersos entre el tablero, evitando asi la suposicion de posiciones entre los barcos.

3. Para disparar dentro del tablero se deben de escribir las coordenadas en Y y luego en X para que se dispare en esa posicion. Si las coordenadas a las que se intenta disparar ya han sido atacadas antes. Se pedira que se escriban otras coordenadas.

4. Los turnos para disparar en unas coordenadas seran intercalados entre el jugador y el CPU.

## Modos de juego





4. Los jugadores marcan en su tablero de ataque los resultados para hacer seguimiento de sus intentos y aciertos.
5. Gana el jugador que primero hunde toda la flota enemiga.


Se utilizaran todas las mecanicas vistas durante el curso, las cuales las detallo mas a fondo:

1. Se utilizara if, else y switch para todas las tomas de desiciones que deban existir dentro del videojuego.
2. Se utilizara for, while y do while se utilizara para que se repitan mientras ciertas condiciones dadas se cumplan
3. Los arreglos se usaran principalmente para la generacion de las casillas y guardar los datos de las ubicaciones de los barcos.
4. Las funciones se usaran principalmente para rellenar el tablero de (~) y para utilizar un mismo bloque de codigo en varias partes del videojuego.

## Equipo

- **Nombre del equipo:** [The bytes]

### Integrantes del equipo

1. **Nombre completo:** [Hector Andres Lopez Medrano]  
   **Carnet:** [00015725]

2. **Nombre completo:** [ Rodrigo Josue Medrano Marquez]  
   **Carnet:** [00148625]

3. **Nombre completo:** [Andres Eduardo Vega Mena]  
   **Carnet:** [00077125]

4. **Nombre completo:** [Ricardo Antonio Ramos Rosales]  
   **Carnet:** [00025325]


## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [URL del repositorio]
