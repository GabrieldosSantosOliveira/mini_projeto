#!/usr/bin/bash

./pbuild "2x^2-2x^0" p1
./pview p1
./pbuild "2x^1-2x^0" p2
./pview p2
./psum p1 p2 soma
./psub p1 p2 sub
./pview soma
./pview sub