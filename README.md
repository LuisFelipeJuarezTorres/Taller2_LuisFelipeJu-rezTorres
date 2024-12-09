# Taller2_LuisFelipeJu-rezTorres
Nombre Alumno: Luis Felipe Juárez Torres.
RUT: 19.950.071-6
Paralelo: C1
Instrucciones para ejecutar el programa: El codigo del Taller se compone de 3 archivos: Gato.cpp, Tablero.cpp y Tablero.h. Tablero.cpp-h, contiene el codigo relacionado con el minimax, con y sin poda Alfa y Beta. Por otro lado, Gato.cpp, contiene el codigo relacionado con la consola, crea un instancia de Tablero y tiene un metodo Jugar(), aparte, en el archivo hay otro metodo, llamado main() que correra el programa, creando una instancia de Gato y llamando al metodo de Jugar(). La forma en que se ejecuto fue: PS C:\Users\fjt99\WorkSpaceC++\Taller2> g++ Gato.cpp Tablero.cpp -o Gato.exe, luego: PS C:\Users\fjt99\WorkSpaceC++\Taller2> .\Gato.exe.


Explicación sobre algortimo utilizado: 
El algortimo Minimax es una técnica que se usa principalmente en juegos de dos jugadores, como el ajedrez, el Gato. Basicamente, ayuda a tomar desiciones inteligentes suponiendo que el oponente también va a jugar lo mejor posible. La idea principal del Minimax es analizar todos los movimientos posibles de un jugador, creando un árbol con las opciones del juego, y luego elegir la jugada que dé el mejor resultado para uno mismo mientras se trata de reducir las oportunidades del oponente. 
Para hacerlo más eficiente, se puede aplicar al poda alfa y beta, que reduce el número de movimientos que se necesitan analizar. Esta técnica descarta ramas del árbol que no afectan la decisión final, ahorrando tiempo y haciendo que el algoritmo sea mucho más rapido.
Diagrama de arbol: En el repositorio hay un pdf(DiagramaArboles) que contiene el diagrama de arbol.
Complejidad algortimica: 
Minimax sin poda alfa-beta: 
O(x^z)----"^": elevado.
x: Número movimiento posibles en cada turno.
z: Profundidad máxima del árbol.
Explora todos los nodos del árbol, lo que lo hace ineficiente para juegos complejos con grandes X e Z.
Minimax con poda alfa y beta:
O(x^(z/2))
x: Número movimiento posibles en cada turno.
z: Profundidad máxima del árbol.
En el mejor de los casos, la poda podra reducir la profundidad efectiva del arbol a la mitad, descartando ramas irrelevantes.




