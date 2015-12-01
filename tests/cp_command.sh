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

echo "ccp /usr/share/dict/american-english outfile"
echo "exit"
{   echo ccp /usr/share/dict/american-english outfile ;
    sleep .5
    echo "exit" ;
} | bin/lab08
echo ""
test outfile && echo "/usr/share/dict/american-english copied to outfile" || echo "/usr/share/dict/american-english was not copied to outfile"
echo ""
sleep .5

echo "Difference between input file and output file:"
grep -Fxvf /usr/share/dict/american-english outfile
echo ""

sleep 5

rm outfile

#
# Test UNIX cp method
#

echo "ucp /usr/share/dict/american-english outfile"
echo "exit"
{   echo ucp /usr/share/dict/american-english outfile ;
    sleep .5
    echo "exit" ;
} | bin/lab08
echo ""
test outfile && echo "/usr/share/dict/american-english copied to outfile" || echo "/usr/share/dict/american-english was not copied to outfile"
echo ""
sleep .5

echo "Difference between input file and output file:"
grep -Fxvf /usr/share/dict/american-english outfile
echo ""

sleep 5

rm outfile

#
# Test UNIX Buffer cp method
#

echo "bcp /usr/share/dict/american-english outfile"
echo "exit"
{   echo bcp /usr/share/dict/american-english outfile ;
    sleep .5
    echo "exit" ;
} | bin/lab08
echo ""
test outfile && echo "/usr/share/dict/american-english copied to outfile" || echo "/usr/share/dict/american-english was not copied to outfile"
echo ""
sleep .5

echo "Difference between input file and output file:"
grep -Fxvf /usr/share/dict/american-english outfile
echo ""

sleep 5

rm outfile

#rm infile
