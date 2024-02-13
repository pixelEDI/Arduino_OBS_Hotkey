#         _          _ ______ _____ _____
#        (_)        | |  ____|  __ \_   _|
#    _ __  ___  _____| | |__  | |  | || |
#   | '_ \| \ \/ / _ \ |  __| | |  | || |
#   | |_) | |>  <  __/ | |____| |__| || |_
#   | .__/|_/_/\_\___|_|______|_____/_____|
#   | |
#   |_|

#   >> https://links.pixeledi.eu <<
#   DIY Hotkeys | V1.0 | 02.2024

import time
import serial

from obswebsocket import obsws, events 

host = "192.168.178.111"
port = 4455
password = ""

def sendSerial(msg):
    ser = serial.Serial('/dev/ttyACM0', 115200)
    ser.flush()
    data_to_send = msg
    ser.write(data_to_send.encode('utf-8')) 
    ser.close()

def on_event(message):
    #print("Got message: {}".format(message))
    #print(message)

    ws_callback = str(message)
    if "OBS_WEBSOCKET_OUTPUT_STOPPING" in ws_callback:
        print("stop")
        sendSerial("stop")
        
    elif "OBS_WEBSOCKET_OUTPUT_STARTING" in ws_callback:
        print("record")
        sendSerial("record")
        
    elif "OBS_WEBSOCKET_OUTPUT_PAUSED" in ws_callback:
        print("pause")
        sendSerial("pause")
        
    elif "OBS_WEBSOCKET_OUTPUT_RESUMED" in ws_callback:
        print("resume")
        sendSerial("resume")

ws = obsws(host, port, password)
ws.register(on_event)
ws.connect()

try:
    #print("OK")
    time.sleep(100000)
    #print("END")

except KeyboardInterrupt:
    pass

ws.disconnect()
