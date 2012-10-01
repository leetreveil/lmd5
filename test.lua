require("lmd5")
local md5 = md5.new()
md5:update("abc")
assert(md5:hexdigest() == "900150983cd24fb0d6963f7d28e17f72")