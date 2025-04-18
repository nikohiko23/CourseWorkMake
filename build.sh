#!/bin/bash
echo " Building..."
g++ -std=c++17 -Iinclude src/*.cpp -o bin/mybuild
echo "Done.Run with: ./bin/mybuild"