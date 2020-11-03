# hand-gestures :hand: 
<h3>What does this project do?</h2>
<p>This project gets rid of using keyboard for playing/pausing videos or (rewind/forward) or scrolling something.There are laptops out there which are costly and have hand gesture support in them but if you want to do it in a cheap way. This project is perfect for that.</p>
  
<h3> How does it work? :eyes:</h3>
<p>All the functions this project supports is based on basically the distance from the ultrasonic sensor that I am using. I have used 2 ultrasonic sensors in this project. One for right hand and one for left hand. I have used an Arduino Uno R3 for the project so the distance calculated can be seen in serial monitor and based on this distance I print play/pause on serial monitor.</p>
<p>Now the functions like play/pause which are printed on the serial monitor can be accessed using a python package call pyserial. Next based on these values the python script does the intended function. For this I am using library called 'pyautogui' so once i get the data from serial monitor, we just have to use some if conditions and then i can use pyautogui library functions to do the job.</p>

<h3>Functions Supported :tv:</h3>
<ul>
  <li>Playing/Pausing Video</li>
  <li>Rewinding/Forwarding</li>
  <li>Page scrolling</li>
  <li>Tab Switching</li>
  <li>Increasing/Decreasing Volume</li>

 </ul>

<h3>Libraries :key:</h3>
<ul>
  <li>Pyserial</li>
  <li>Pyautogui</li>
</ul>

<h3>Components Used :smirk:</h3>
<ul>
  <li>HC-SR04 Ultrasonic Sensor(2)(168 rs as on Amazon)</li>
  <li>Jumper Wires(100-200 rs comes as a pack)</li>
  <li>Arduino Uno R3 (400-500 excluding cable)</li>
  <li>USB-A type cable (100-200 Rs) </li>
  <li> Two sided cellotape(for sticking sensors and arduino to the laptop)</li>
</ul>
  
