import sys
import csv
from cs50 import SQL

# Creating db variable
db = SQL("sqlite:///students.db")

# Checking if write the house name
if (len(sys.argv) != 2):
    print("House name missing.")
    sys.exit(1)

# Checking if the file has the correct name
if (sys.argv[1] == "Gryffindor" or sys.argv[1] == "Hufflepuff" or sys.argv[1] == "Ravenclaw" or sys.argv[1] == "Slytherin"):
    x = "working"
else:
    print("It looks like your house doesn't exist.")
    sys.exit(1)

final = db.execute("SELECT first, middle, last, birth FROM students WHERE house = (?) ORDER BY last, first;", sys.argv[1])

# Printing the final results
for i in range(len(final)):
    if (final[i]['middle'] == None):
        print(f"{final[i]['first']} {final[i]['last']}, born {final[i]['birth']}")
    else:
        print(f"{final[i]['first']} {final[i]['middle']} {final[i]['last']}, born {final[i]['birth']}")