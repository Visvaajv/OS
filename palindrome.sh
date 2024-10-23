echo "Enter the number:"
read n
num=0
a=$n
while [ $n -gt 0 ]
do
    k=$(expr $n % 10)         
    num=$(expr $num \* 10 + $k)  
    n=$(expr $n / 10)         
done
if [ $num -eq $a ]; then
    echo "It's a Palindrome"
else
    echo "Not a Palindrome"
fi