'badger
set cmd=createObject("wScript.shell")

a1=inputBox("Title")

cmd.run "cmd"
wScript.sleep 100

cmd.sendKeys "cd/{enter}"
cmd.sendKeys "title '"+a1+"'{enter}"
cmd.sendKeys "color 0a{enter}"
cmd.sendKeys "cls{enter}"
cmd.sendKeys "set /p a1='test: '{enter}"
cmd.sendKeys "echo %a1%"{enter}"
cmd.sendKeys "dir{enter}"