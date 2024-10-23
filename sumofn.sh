echo "Enter the number:"
read n
i=1
sum=0
echo "Enter the numbers"
while [ $i -le $n ] 
do
read num
sum=$((sum + num)) 
i=$((i + 1)) 
done 
echo "sum = $sum"