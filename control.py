import serial                                      # add Serial library for serial communication
import pyautogui                                   # add pyautogui library for programmatically controlling the mouse and keyboard.
import time
Arduino_Serial = serial.Serial('/dev/ttyUSB0',9600)       # Initialize serial and Create Serial port object called Arduino_Serial
 
while 1:
    incoming_data = str (Arduino_Serial.readline().decode()) # read the serial data and print it as line
    print(incoming_data)                            # print the incoming Serial data
     
     if 'Play/Pause' in incoming_data:
        pyautogui.typewrite(['space'], 0.2)

    if 'Rewind' in incoming_data:
        pyautogui.hotkey('ctrl', 'left')  

    if 'Forward' in incoming_data:
        pyautogui.hotkey('ctrl', 'right') 

    if 'Vup' in incoming_data:
        pyautogui.hotkey('ctrl', 'down')
        

    if 'Vdown' in incoming_data:
        pyautogui.hotkey('ctrl', 'up')
    incoming_data = "";                  
    time.sleep(3)