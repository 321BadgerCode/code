#!/bin/bash
#badger
#display info..
echo -n "python app path: "
which python3
echo -n "current python lib. version: "
ls -l $(which python3)
echo -n "python version: "
python3 --version

#get input.
echo "ex.: \"3.10\"(has many imported modules)"
echo "ex.: \"3.11\"(to use idle3)"
echo -n "versions to switch to(has to be installed): "&&read v

#change python lib. version.
sudo ln -sf /usr/bin/python${v} /usr/bin/python3