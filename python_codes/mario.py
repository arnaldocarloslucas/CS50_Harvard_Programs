# Prompt the user for the Height
height = (input("Height: "))

check = False
while check == False:
    try:
        height = int(height)
        if (height >= 1 and height <= 8):
            check = True
        elif (height < 1 or height > 8):
            height = (input("Height: "))
            check = False
    except:
        height = (input("Height: "))

# Build pyramid
for i in range(height):
    j = i + 1
    k = 0
    m = 0
    while j < height:
        print(" ", end="")
        j += 1
    while k <= i:
        print("#", end="")
        k += 1
    print("  ", end="")
    while m <= i:
        print("#", end="")
        m += 1
    print()
