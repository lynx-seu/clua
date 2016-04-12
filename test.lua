local t = require("t")

local ttt = {
	{1,2,3},
	{4,5,6,7},
	{8,9},
	{10,11,15},
}

local aa = t.test(ttt, 4)
print(aa)


for k, v in pairs(aa) do
	print(k, v)
end

