@echo off
echo start
for %%f in (*.csv) do (
  echo %%f > input.txt
  type input.txt
  call doSingleTest.cmd
) 
echo done