Sistemas Operativos Avanzados
===============================
Proyecto de Sistemas operativos avanzados

Grupo: X3 <br /> 
-----------
* [Barja Fernandez, Omar Max](https://github.com/omx17)<br /> 
* [Facal, Ernesto Manuel](https://github.com/ErnestoFacal)<br />
* [Marson, Tomás](https://github.com/tomimarson)
* [Oria, Joaquín Ariel](https://github.com/OriaJoaquin)<br /> 
* [Schiro, Andrés](https://github.com/ASchiro7)<br /> 

Proyecto: ReciclaMe<br /> 
---------
### Descripción

ReciclaMe es un robot de reciclaje autónomo que explota el poder del aprendizaje profundo para mejorar las capacidades humanas en una tarea que es crucialmente importante, a través del reconocimiento y clasificacion de los distintos tipos de materiales.

### Materiales

* Arduino uno 

![imagenArduino](https://imgs.clipartwiki.com/clipimg/small/162-1623636_this-is-a-small-microcontroller-that-you-can.png)

El Arduino Uno es una placa de microcontrolador de código abierto basado en el microchip ATmega328P. La placa está equipada con conjuntos de pines de E/S digitales y analógicas que pueden conectarse a varias placas de expansión y otros circuitos. La placa tiene 14 pines digitales, 6 pines analógicos y programables con el Arduino IDE (Entorno de desarrollo integrado) a través de un cable USB tipo B.Puede ser alimentado por el cable USB o por una batería externa de 9 voltios, aunque acepta voltajes entre 7 y 20 voltios.

* Modulo detector sensor de obstaculos infrarrojo arduino 

![ImagenSensor01](https://www.luisllamas.es/wp-content/uploads/2016/06/arduino-detector-obstaculos-infrarrojos-componente.png)

Este módulo está conformado por un LED emisor infrarrojo y un fotodiodo el cual es sensible a la intensidad. El haz infrarrojo emitido al ser reflejado por el obstáculo es detectado por el fotodiodo, la señal del fotodiodo es comparada por el LM393 con la referencia del potenciómetro. La distancia de detección es configura con el potenciómetro. La salida del módulo es digital
Posee 2 leds, uno de los cuales indica que el módulo está alimentado y el otro enciende cuando el sensor detecta un obstáculo (muy útil para realizar el ajuste).

* Servomotor DS04-NFC 360° Grados 5.5Kg-cm

![ImagenServo01](https://afel.cl/content/uploads/servomotor-ds04-nfc.jpg)

Este servo de rotación continua convierte a un Servo estandar RC de pulsos PWM en un Servo de velocidad de rotación continua (360°), con un Torque de 5.5Kg/cm.
El punto de reposo por defecto es de 1.5ms, pero esto se puede modificar con un pequeño destornillador de punta plana para girar un pequeño ajuste que se encuentra a la mitad del Servo.
Aplicando un ancho de pulso por encima del punto de reposo, provocara un giro en sentido inverso a las manecillas del reloj y la velocidad aumenta a medida que se aumenta el ancho de pulso. 
Aplicando un ancho de pulso por debajo del punto de reposo, provocara la rotación en sentido a las manecillas del reloj con una velocidad cada vez mayor a medida que se disminuye la anchura de pulso.

* Celda de Carga

![ImagenSensorPeso](https://electronilab.co/wp-content/uploads/2018/01/Celda-de-carga-5kg-sensor-de-Fuerza-o-Peso-2.jpg)

Sensor de peso o fuerza de 5 kg. El Sensor de Peso o Fuerza de 5kg es un sensor de celda de carga, que puede medir hasta poco más de 5 kg de peso, convirtiendo dicha variable de fuerza en una señal eléctrica, gracias a su confiabilidad es ampliamente utilizado en proyectos de medición de peso y básculas. Un sensor de celda de carga se encarga de convertir una fuerza o peso en una señal de voltaje, así que el peso que ejerza el objeto corresponderá a una cantidad de voltaje determinada.

* Transmisor de Cela de Carga

![ImagenTransmisorCelda](http://tdrobotica.co/2463/celda-de-carga-de-1-kg-barra-recta.jpg)

Este módulo es una interface entre las celdas de carga y el microcontrolador, permitiendo poder leer el peso de manera sencilla. Internamente se encarga de la lectura del puente wheatstone formado por la celda de carga, convirtiendo la lectura analógica a digital con su conversor A/D interno de 24 bits.
Es muy utilizado en procesos industriales, sistemas de medición automatizada e industria médica.
Se comunica con el microcontrolador mediante 2 pines (Clock y Data) de forma serial.

* Módulo Bluetooth

![ImagenModuloBluetooth](http://www.maxelectronica.cl/5-large_default/modulo-bluetooth-serial-ttl-esclavo-hc-06.jpg)

Permite añadir a Arduino la función de poder comunicarse sin cables con otros dispositivos mediante la tecnología Bluetooth.

### Diagrama físico

![diagramaFisico](https://github.com/OriaJoaquin/X3/blob/master/Diagramas/DiagramaFisico.png)

### Diagrama funcional

![diagramaFuncional](https://github.com/OriaJoaquin/X3/blob/master/Diagramas/DiagramaFuncional.png)
