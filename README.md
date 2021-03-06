# Servo-motor-control

<p align="justify">In this code the rotation of a servo motor is controlled using a potentiometer.</p>

<p align="justify">The position of the motor shaft of a servo motor can be precisely controlled between 0&#xb0; and 180&#xb0; by providing a PWM input signal of duty cycle between
5% and 10%. Therefore, if the generation of the PWM signal can be controlled by a sensor, the sensor input could determine the rotation of the motor.</p>

<p align="justify">Here, the potentiometer, which is connected to the ADC of the microcontroller, is used to determine the rotation of the servo motor. At its minimum and maximum 
positions, the ADC output of the potentiometer would be 0 and 1023 respectively. By mapping these two values to the variable determining the duty cycle of the 50 Hz PWM signal 
generated by the microcontroller, we can have the rotation of the potentiometer knob control the rotation of the servo motor shaft.</p>

<p align="justify">For more information on the servo motor, visit my servo motor repo <a href="https://github.com/asitha-navaratne/Servo-motor-sweep">here</a>. For more 
information on PWM signal generation, visit my PWM-fast repo <a href="https://github.com/asitha-navaratne/PWM-fast">here</a>. For more information on using the ADC of the 
ATmega32A, visit my ADC repo <a href="https://github.com/asitha-navaratne/ADC-USART">here</a>.</p>
