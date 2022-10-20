first = input(" Enter the first no: ")
#print(" The no is: " + first)
operator = input(" Enter the operator(+,-,*,/,%) :")
second = input(" Enter the second no: ")

first = int(first)
second = int(second)

if operator == "+" :
    print(first + second)

elif operator == "-" :
    print(first - second)

elif operator == "*" :
    print(first * second)

elif operator == "/" :
    print(first / second)

elif operator == "%" :
    print(first % second)


else :
    print("Invalid Syntax")

