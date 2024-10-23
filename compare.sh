echo “Enter two string”
read a
read b
if [ -z $a ]
then 
echo “ First String is empty: Null String”
fi
if [ -z $b ]
then 
echo “ Second String is empty: Null String”
fi
if [ $a = $b ]
then 
echo “Strings are equal: strings Matched”
else
echo “Strings are not equal: Strings not match”
fi
