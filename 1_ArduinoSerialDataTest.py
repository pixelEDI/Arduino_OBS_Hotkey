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

import serial

# Öffne die serielle Verbindung COM3
ser = serial.Serial('/dev/ttyACM0', 115200)
ser.flush()

# Sende die Daten
data_to_send = "pause" 
ser.write(data_to_send.encode('utf-8')) 

ser.close()
