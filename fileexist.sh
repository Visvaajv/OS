touch fil.txt
echo "enter the file name :"
read filename
if [ -f $filename ]
then
echo "file exists"
else
echo "file doesn't exist"
fi