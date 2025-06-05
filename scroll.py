import serial,subprocess

serialPort = serial.Serial(port = "/dev/rfcomm0", baudrate=9600,
                           bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE)

serialString = ""
jCount = 0 #hack to bypass the anti-clockwise encoder issue

while(1):
    serialString = serialPort.readline()
    # Print the contents of the serial data
#    print(serialString.decode('Ascii'))
    if serialString.decode('Ascii') == "k\n":
        if jCount:
            subprocess.call(["xdotool","key","Down"])
            #subprocess.call(["xdotool","type","j"])
            jCount = 0
        else:
            subprocess.call(["xdotool","key","Up"])
    elif serialString.decode('Ascii') == "j\n":
        subprocess.call(["xdotool","key","Down"])
        jCount = 1


