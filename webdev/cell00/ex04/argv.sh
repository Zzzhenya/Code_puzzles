#!/bin/bash

if  [[ $# -eq 0 ]];
then
    echo "No arguments supplied"
elif [[ $# -gt 3 ]];
then
    echo "Arguments larger than max (3)"
else
    for arg in $@
    do echo $arg
    done
fi