#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for the correct input
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    BYTE buffer[512];
    FILE *img;

    // Save for the images index
    int jpg_counter = 0;

    // name needs 7 chars and one '\0' = 8
    char name[8];

    // Reading all the card
    while (fread(buffer, 512, 1, file))
    {

        // Condition to create a JPG file just if is true
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff \
            && (buffer[3] & 0xf0) == 0xe0)
        {
            //If we are in the first JPG
            if (jpg_counter == 0)
            {
                sprintf(name, "%03i.jpg", jpg_counter);
                img = fopen(name, "w");
                fwrite(buffer, 512, 1, img);
                jpg_counter++;
            }
            //If not at the first JPG
            else
            {
                fclose(img);
                sprintf(name, "%03i.jpg", jpg_counter);
                img = fopen(name, "w");
                fwrite(buffer, 512, 1, img);
                jpg_counter++;
            }

        }
        //If do not encounter a begin of a JPG
        else if (jpg_counter != 0)
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    fclose(img);
    fclose(file);
}