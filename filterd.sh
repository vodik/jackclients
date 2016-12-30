#!/bin/bash

if [[ ! -f ./filterd ]]; then
  echo "filterd not found"
  exit 1
fi

export LD_LIBRARY_PATH="$PWD/lib:$LD_LIBRARY_PATH"
exec ./filterd
