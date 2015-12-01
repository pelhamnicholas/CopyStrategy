#!/bin/bash

#
# Bash script to test the cp commands
#

# Create a file with something inside of it to copy
#echo "Output file exists" >> infile
#touch outfile

#
# Test C++ cp method
#

echo "ccp LICENSE outfile"
echo "exit"
{   echo ccp LICENSE outfile ;
    sleep .5
    echo "exit" ;
} | bin/lab08
echo ""
sleep .5

echo "Difference between input file and output file:"
grep -Fxvf LICENSE outfile
echo ""

sleep 5

rm outfile

#
# Test UNIX cp method
#

echo "ucp LICENSE outfile"
echo "exit"
{   echo ucp LICENSE outfile ;
    sleep .5
    echo "exit" ;
} | bin/lab08
echo ""
sleep .5

echo "Difference between input file and output file:"
grep -Fxvf LICENSE outfile
echo ""

sleep 5

rm outfile

#
# Test UNIX Buffer cp method
#

echo "bcp LICENSE outfile"
echo "exit"
{   echo bcp LICENSE outfile ;
    sleep .5
    echo "exit" ;
} | bin/lab08
echo ""
sleep .5

echo "Difference between input file and output file:"
grep -Fxvf LICENSE outfile
echo ""

sleep 5

rm outfile

#rm infile
