out("==================== started ==========")


function logLine(tbl) 
  local f = io.open("testResult.log", "a")
  local first = true
  for _,s in ipairs(tbl) do
    if not first then 
      f:write("\t")
    end
    first = false
    f:write(s)
  end
  f:write("\n")
  io.close(f)
end

function parseFileName(sFileName)
  local mod, typ, cols, wors, kb = { sFileName:match("(%a+)_(%a+)_(%d+)Rx(%d+)Cx(%d+)B_(%d+)KB") }
end

function doTest(sFileName)
  out("loading ", sFileName)
  local tmr = Timer:new()

  local props = parseFileName(sFileName)

  local info = console.memory_info()
  out(info)
  logLine( {sFileName, "1", "loading", 
    info.physical_kb, info.virtual_kb, info.read_kb, info.write_kb, info.other_kb, } )

  local stats = import.csv(sFileName, nil, 'Opening a data file')

  if nil ~= stats then 
    out("success, ", #stats, "rows")
  end

  local info = console.memory_info()
  local ar = {sFileName, "2", "loaded",
    info.physical_kb, info.virtual_kb, info.read_kb, info.write_kb, info.other_kb,
    #stats, }
  ar[#ar+1] = tmr:passed()


  -- test mean performance
  local tmr = Timer:new()
  local cols = 0
  for _,name in ipairs(stats.header) do
    cols = cols+1
	local val = stats:mean("["..name.."]")
    out("mean of \""..name.."\" = "..tostring(val))
  end
  ar[#ar+1] = tmr:passed() / cols

  --test median performance
  local tmr = Timer:new()
  local cols = 0
  for _,name in ipairs(stats.header) do
    cols = cols+1
	local val = stats:median("["..name.."]")
    out("median of \""..name.."\" = "..tostring(val))
  end
  ar[#ar+1] = tmr:passed() / cols


  --put parsed file info
  for _,v in ipairs({ sFileName:match("(%a+)_(%a+)_(%d+)Rx(%d+)Cx(%d+)B_(%d+)KB") }) do
    ar[#ar+1] = v
  end

  logLine( ar )

--[[
  collectgarbage('collect')
  local info = console.memory_info()
  logLine( {sFileName, "3", "gc",
    info.physical_kb, info.virtual_kb, info.read_kb, info.write_kb, info.other_kb,
    #stats, } )
]]--

  out("done ", sFileName)
end



local sFileName = "set_uniq_str_10000Rx20Cx31B_6MB.csv"
local sCfgFile = "input.txt"

inp = io.open(sCfgFile, "r")
if nil ~= inp then
  sFileName = inp:read("*line")
  io.close(inp)
  out("taking", "\""..sFileName.."\"", "for the test from the ", sCfgFile)
else
  out("could not find the file", sCfgFile)
end

doTest(sFileName);