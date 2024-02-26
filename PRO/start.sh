#!/bin/bash
gcc server.c -lfcgi -o server
spawn-fcgi -a 127.0.0.1 -p8080 ./server
