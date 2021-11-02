DE Section A4.6
Arduino 555 Project Tester

Signal input on pin 2

Displays time high, period, and duty cycle to see if the circuit meets the project requirements
Arduino outputs:
tH, T, DC

In case of upload errors on the Mac because the USB port is "busy" open a terminal and do this:

lsof | grep "/dev/cu.usbmodem"

to get a list processes using the USB port

The kill the process number that's using the port.
