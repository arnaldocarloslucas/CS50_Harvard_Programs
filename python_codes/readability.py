# Get the text for input
text = input("text: ")

# Count the number of letters
count_letter = 0
for letter in text:
    if (letter.isalpha()):
        count_letter += 1
# Count the number of words
words = len(text.split())

# Count the number of sentences
text = text.replace('!', '.')
text = text.replace('?', '.')
sentences = len(text.split('.')) - 1

# Tests all parameters
# print(count_letter)
# print(words)
# print(sentences)

# Coleman-Liau
L = float((count_letter / words) * 100)
S = float((sentences / words) * 100)
index = int(round(0.0588 * L - 0.296 * S - 15.8))
# Test the index
# print(index)

if (index < 1):
    print("Before Grade 1")
elif (index >= 16):
    print("Grade 16+")
else:
    print(f"Grade {index}")