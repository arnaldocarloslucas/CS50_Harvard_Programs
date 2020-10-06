import sys
import csv
import re
from cs50 import SQL

# Creating db variable
db = SQL("sqlite:///students.db")

# Checking if the file exists
if (len(sys.argv) != 2):
    print("characters.csv file missing.")
    sys.exit(1)

# Opening csv file
tmp1 = []
students = []
with open(sys.argv[1]) as char_file:
    tmp = csv.reader(char_file, delimiter=',')
    for row in tmp:
        students.append(row)
    for i in range(1, len(students)):
        students[i][0] = re.split(' ', students[i][0])
        if (len(students[i][0]) == 2):
            students[i][0].append(None)
            students[i][0][1], students[i][0][2] = students[i][0][2], students[i][0][1]

        first = students[i][0][0]
        middle = students[i][0][1]
        last = students[i][0][2]
        house = students[i][1]
        birth = students[i][2]

        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   first, middle, last, house, birth)
