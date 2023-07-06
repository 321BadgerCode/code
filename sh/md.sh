#!/bin/bash
#badger
#get input.
echo -n "file: "&&read file

pandoc $(file) | lynx -stdin