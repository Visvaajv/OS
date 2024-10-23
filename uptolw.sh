touch HELLO.txt
echo "Enter the Filename"
read filename
if [  !  -f  $filename ];
then
echo "Filename $filename does not exists"
exit 1
else
echo "$filename" | tr '[:upper:]' '[:lower:]'
fi