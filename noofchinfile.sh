touch ex.txt
echo "type anything here" >> ex
echo "enter the file name"
read file
c=$(cat $file | wc -c)
w=$(cat $file | wc -w)
l=$(grep -c "." $file)
echo "number of characters in $file is $c"
echo "number of words in $file is $w"
echo "number of lines in $file is $l"