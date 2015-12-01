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

echo "bin/lab08 -c /usr/share/dict/american-english outfile"
bin/lab08 -c /usr/share/dict/american-english outfile ;
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

echo "bin/lab08 -u /usr/share/dict/american-english outfile"
bin/lab08 -u /usr/share/dict/american-english outfile ;
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

echo "bin/lab08 -b /usr/share/dict/american-english outfile"
bin/lab08 -b /usr/share/dict/american-english outfile ;
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
