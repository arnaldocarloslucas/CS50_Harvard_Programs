import csv
import sys
import re


def main():
    # Check if the input is correct
    length = len(sys.argv)
    if (length != 3):
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Open the file of indentify and save it on a list
    with open(sys.argv[1], "r") as file_csv:
        ID = file_csv.read()
        # Just the STR for search (ID2)
        ID2 = re.split('\n', ID)
        ID2 = re.split(',', ID2[0])
        ID2.pop(0)

        # Create 3 lists base to compare with the result
        ID_base = re.split('\n', ID)
        ID_base.pop(len(ID_base) - 1)
        ID_base.pop(0)
        final_dict, list_names = strs_base(ID_base)

    # Open the file of DNA and save it on a list
    with open(sys.argv[2], "r") as file_txt:
        DNA = file_txt.read()

    # Saving the higher values in a list to compare later
    str_count = []
    for i in range(len(ID2)):
        str_count.append(STRcompare(ID2[i], DNA))

    # Comparing the final results
    # Loop to the end of the dictionary with len (final_dict)
    test = []
    check_out = False
    check_in = False
    for i in range(len(final_dict)):
        test = final_dict[list_names[i]]

        # Compare final dictionary values with str_count
        j = 0
        if int(test[j]) == str_count[j]:
            check_in = False
            while check_in == False:
                if int(test[j]) == str_count[j]:
                    j = j + 1
                    if (j == len(str_count)):
                        print(list_names[i])
                        check_in = True
                        check_out = True
                else:
                    check_in = True

    if check_out == False:
        print("No match")


def STRcompare(STRs, sequence):
    # Get the length of the specific str
    length_str = len(STRs)
    # Creating list counter
    count = 0
    list_count = []
    # Create a loop to vary the DNA sequence according
    # to the specific length
    for i in range(len(sequence)):
        # If combine
        if sequence[i:(i+length_str)] == STRs:
            # Do a while adding the length in the variation
            # until it doesn't match anymore
            while sequence[i:(i+length_str)] == STRs:
                # For each combination, add 1 to a counter_list
                # at the position of the main loop
                count = count + 1
                i = i + length_str
            list_count.append(count)
            count = 0
        # If not combine
        else:
            # Add 1 to the next search sequence[i+1:j+1]
            i = i + 1
    # max(list_count) to get the high value
    if list_count != []:
        high = max(list_count)
        # Return the higher value
        return high


def strs_base(ID_input):
    tmp_dict = {}
    list_names = []
    final_dict = {}
    # Split ID_input to ID_input length in a dictionary
    for i in range(len(ID_input)):
        tmp_dict[i] = ID_input[i]
        # Take each vector and divide its string by ","
        tmp_dict[i] = re.split(',', tmp_dict[i])
        # Pegar todos os nomes em cada lista
        names = tmp_dict.get(i)
        list_names.append(names[0])
        # Remove temporary dictionary names
        tmp_dict[i].pop(0)
        # Add tmp_dict values to final_dict
    for i in range(len(ID_input)):
        final_dict[list_names[i]] = tmp_dict[i]
    # return the final dictionary
    return final_dict, list_names


# Run the program
main()