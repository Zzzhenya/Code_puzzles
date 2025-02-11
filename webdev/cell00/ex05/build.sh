#!/bin/bash

PREFIX="ex"

if  [[ $# -eq 0 ]];
then
    echo "No arguments supplied"
else
    for ARG in $@
        do
            mkdir "$PREFIX$ARG"
    done
fi