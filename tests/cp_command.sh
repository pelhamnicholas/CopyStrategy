#!/bin/bash

#
# Bash script to test the cp commands
#

# Create a file with something inside of it to copy
echo "Output file exists" >> infile
touch outfile

#
# Test C++ cp method
#

echo "ccp infile outfile"
echo "exit"
{   echo ccp infile outfile ;
    sleep .5
    echo "exit" ;
} | bin/lab08
echo ""
sleep .5

echo "Output file contents:"
cat outfile
echo ""

echo "Difference between input file and output file:"
grep -Fxvf infile outfile
echo ""

sleep .5

rm outfile

#
# Test UNIX cp method
#

echo "ucp infile outfile"
echo "exit"
{   echo ucp infile outfile ;
    sleep .5
    echo "exit" ;
} | bin/lab08
echo ""
sleep .5

echo "Output file contents:"
cat outfile
echo ""

echo "Difference between input file and output file:"
grep -Fxvf infile outfile
echo ""

sleep .5

rm outfile

rm infile
