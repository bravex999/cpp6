#!/bin/bash

echo "===== CHAR ====="
echo "./convert a"
./convert a
echo

echo "===== INT ====="
echo "./convert 0"
./convert 0
echo

echo "./convert 42"
./convert 42
echo

echo "./convert -42"
./convert -42
echo

echo "===== FLOAT / DOUBLE ====="
echo "./convert 4.2"
./convert 4.2
echo

echo "./convert -4.2"
./convert -4.2
echo

echo "./convert 4.2f"
./convert 4.2f
echo

echo "===== PSEUDOLITERALS ====="
echo "./convert nan"
./convert nan
echo

echo "./convert nanf"
./convert nanf
echo

echo "./convert +inf"
./convert +inf
echo

echo "./convert -inf"
./convert -inf
echo

echo "./convert +inff"
./convert +inff
echo

echo "./convert -inff"
./convert -inff
echo

echo "===== INVALID ====="
echo "./convert hello"
./convert hello
echo

echo "./convert 42abc"
./convert 42abc
echo
