echo "Enter two numbers :"
read a
read b
echo "MENU 1. Addition 2. Subtraction 3. Multiplication 4. Division"
echo "Enter the choice:"
read c
case $c in
1)echo "Sum=$(expr $a + $b)";;
2) echo "Subtraction=$(expr $a - $b)";;
3)echo "Multiplication=$(expr $a * $b)";;
4) echo "Division=$(expr $a / $b)";;
5)echo "Invalid Choice: Try Again";;
esac