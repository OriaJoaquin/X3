Sistemas Operativos Avanzados
===============================
Proyecto de Sistemas operativos avanzados

Grupo: X3 <br /> 
-----------
* [Facal, Ernesto Manuel](https://github.com/ErnestoFacal)<br />
* [Marson, Tomás](https://github.com/tomimarson)
* [Oria, Joaquín Ariel](https://github.com/OriaJoaquin)<br /> 
* [Schiro, Andrés](https://github.com/ASchiro7)<br /> 

Proyecto: BrillaMe :star: <br /> 
---------
## Descripción

BrillaMe es un robot de clasificación de objetos. Basados en la toma de varias muestras de luz, en distintas intensidades y desde distintas posiciones, que luego seran procesadas podemos determinar si un objeto es ***brillante*** o ***no brillante***.
## Materiales

* Arduino uno 

![imagenArduino](https://imgs.clipartwiki.com/clipimg/small/162-1623636_this-is-a-small-microcontroller-that-you-can.png)

El Arduino Uno es una placa de microcontrolador de código abierto basado en el microchip ATmega328P. La placa está equipada con conjuntos de pines de E/S digitales y analógicas que pueden conectarse a varias placas de expansión y otros circuitos. La placa tiene 14 pines digitales, 6 pines analógicos y programables con el Arduino IDE (Entorno de desarrollo integrado) a través de un cable USB tipo B.Puede ser alimentado por el cable USB o por una batería externa de 9 voltios, aunque acepta voltajes entre 7 y 20 voltios.


* Modulo detector sensor de obstaculos infrarrojo arduino 

![ImagenSensor01](https://www.luisllamas.es/wp-content/uploads/2016/06/arduino-detector-obstaculos-infrarrojos-componente.png)

Este módulo está conformado por un LED emisor infrarrojo y un fotodiodo el cual es sensible a la intensidad. El haz infrarrojo emitido al ser reflejado por el obstáculo es detectado por el fotodiodo, la señal del fotodiodo es comparada por el LM393 con la referencia del potenciómetro. La distancia de detección es configura con el potenciómetro. La salida del módulo es digital
Posee 2 leds, uno de los cuales indica que el módulo está alimentado y el otro enciende cuando el sensor detecta un obstáculo (muy útil para realizar el ajuste).


* Servomotor Mg996 Digital 10Kg-13Kg Torque

![ImagenServo01](https://afel.cl/content/uploads/servomotor-ds04-nfc.jpg)

Este servo de rotación continua convierte a un Servo estandar RC de pulsos PWM en un Servo de velocidad de rotación continua (360°), con un Torque de 5.5Kg/cm.
El punto de reposo por defecto es de 1.5ms, pero esto se puede modificar con un pequeño destornillador de punta plana para girar un pequeño ajuste que se encuentra a la mitad del Servo.
Aplicando un ancho de pulso por encima del punto de reposo, provocara un giro en sentido inverso a las manecillas del reloj y la velocidad aumenta a medida que se aumenta el ancho de pulso. 
Aplicando un ancho de pulso por debajo del punto de reposo, provocara la rotación en sentido a las manecillas del reloj con una velocidad cada vez mayor a medida que se disminuye la anchura de pulso.


* Celda de Carga

![ImagenSensorPeso](http://tdrobotica.co/2463/celda-de-carga-de-1-kg-barra-recta.jpg)

Sensor de peso o fuerza de 10 kg. El Sensor de Peso o Fuerza de 10kg es un sensor de celda de carga, que puede medir hasta poco más de 10 kg de peso, convirtiendo dicha variable de fuerza en una señal eléctrica, gracias a su confiabilidad es ampliamente utilizado en proyectos de medición de peso y básculas. Un sensor de celda de carga se encarga de convertir una fuerza o peso en una señal de voltaje, así que el peso que ejerza el objeto corresponderá a una cantidad de voltaje determinada.


* Transmisor de Cela de Carga

![ImagenTransmisorCelda](http://www.naylampmechatronics.com/464-large_default/modulo-hx711-transmisor-de-celda-de-carga.jpg)

Este módulo es una interface entre las celdas de carga y el microcontrolador, permitiendo poder leer el peso de manera sencilla. Internamente se encarga de la lectura del puente wheatstone formado por la celda de carga, convirtiendo la lectura analógica a digital con su conversor A/D interno de 24 bits.
Es muy utilizado en procesos industriales, sistemas de medición automatizada e industria médica.
Se comunica con el microcontrolador mediante 2 pines (Clock y Data) de forma serial.


* Módulo Bluetooth

![ImagenModuloBluetooth](http://www.maxelectronica.cl/5-large_default/modulo-bluetooth-serial-ttl-esclavo-hc-06.jpg)

Permite añadir a Arduino la función de poder comunicarse sin cables con otros dispositivos mediante la tecnología Bluetooth.

  
* Tira de LEDs blancos.

![ImagenLED](https://cdn1.efectoled.com/13033/tira-led-220v-ac-smd5050-60-led-m-5-metros.jpg)

Iluminarán el objeto para luego analizar cuanta luz refleja.

## Diagrama físico

![diagramaFisico](https://github.com/OriaJoaquin/X3/blob/master/Diagramas/DiagramaFisico.png)

## Diagrama funcional

![diagramaFuncional](https://github.com/OriaJoaquin/X3/blob/master/Diagramas/DiagramaFuncional.png)

## Diagrama lógico

![diagramaLogico](https://github.com/OriaJoaquin/X3/blob/master/Diagramas/Diagrama_logico.png)

## Diagrama de software

![diagramaSoftware](https://github.com/OriaJoaquin/X3/blob/master/Diagramas/Diagrama_software.png)

## Diagrama de ciruitos

![diagramaCircuitos](https://github.com/OriaJoaquin/X3/blob/master/Diagramas/Diagrama_circuito.png)


## Manual de usuario 
Primeros pasos: 
 
1) Conexión Android-BrillaMe 
   - El usuario descargará, instalará, e ingresará a la aplicación de BrillaMe en su dispositivo android (*). 
   - Deberá ingresar a la opción “Buscar Dispositivos”.
   - Asegurarse de haber encendido el BT mediante la opción On.
   - Visualizar vinculados mediante la opción “Ver Vinculados.
   - Seleccionar el dispositivo BrillaMe.
 
(*) Versión mínima de android : android 4.0, (Icream Sandwich)
 
### Eventos 
 
1. Habilitar el modo detección de objeto 
   - Desde el menú principal de BrillaMe , el usuario deberá presionar el botón “Analizar Objeto” para ingresar a dicha ventana.
   - Luego de esto deberá darle a la opción “Comenzar”.
   - Activando esta opción, el usuario deberá colocar un objeto dentro de la caja.
   - Luego de detectar la celda de carga una variación en el peso, comenzará el algoritmo de análisis de objeto brillante.
   - Una vez definido si el objeto es o no brillante, la caja se inclinara en base a la señal que se le envie al servo hacia un lado o al otro ( brillante o no ) dejando caer al objeto en su respectivo recipiente.
   - Luego de esto se podrá repetir el proceso nuevamente ( hasta que alguno de los 2 recipientes se determine lleno en base a los infrarrojos).
 
2. Visualización de estadísticas 
   - Desde el menú principal de BrillaMe, el usuario podrá ver las estadísticas que fueron recolectadas a lo largo del uso de la aplicación apretando el botón “Estadísticas”, las cuales serán: 
 
     - Cesto: Indica si dicho cesto esta lleno o no. 
     - Peso: El peso total que posee el recipiente.
     - Cantidad de elementos: Cantidad de elementos que posee dicho cesto.
(*) Estos 3 valores se indicaran tanto para el cesto de objetos brillantes, como el de objetos no brillantes.
3. Acceder al Disco Mode
   - Desde el menú principal de BrillaMe, acceder a la opción Disco Mode.
   - Luego de esto agitar 2 veces el dispositivo Android para de esta manera activar el Disco Mode.

4. Prender/apagar Luces
   - Desde el menú principal de BrillaMe, acceder a la opción de “Prender/Apagar Luces”, luego de esto tapar el sensor de proximidad del celular, el cual se encuentra en la zona superior frontal al dispositivo (cerca de la cámara frontal).
   - Luego de esto, se encenderán los leds siempre y cuando dicha zona quede tapada.


5. Mover caja
   - Desde el menú principal de BrillaMe, acceder a la opción de “Mover Caja”.
   - Luego de esto orientar el dispositivo hacia un lado u otro para de esta manera hacer girar la caja hacia el respectivo lado que estemos girando el dispositivo.
