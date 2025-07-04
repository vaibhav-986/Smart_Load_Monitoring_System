# Smart_Load_Monitoring_System
Simulate a smart load monitoring system that :
  (a) continuously measures the weight of materials placed on a platform using the HX711 weight sensor module   
  (b) provides real-time alerts to warehouse staff via the cloud when the weight exceeds or falls below a predefined threshold, indicating overloading or material depletion

File wokwi_simulation.txt contains the link to the simulation done on wokwi.com simulator,( https://wokwi.com/projects/435526580330294273 ).
File circuit_diagram.jpg contains the circuit connections for the project .
File calibration.ino contains the code for the calibrating the load cells.
File weight.ino contains the project code to measure the weight and report the measured values in grams and also reports whether the measured weight is underload , overload or controlled weight in real time .

Project components :  
  1) HX711 Amplifier
  2) Load Cells (Strain Gauges 3KG)
  3) Arduino uno
  4) Arduino uno LCD didplay shield 
