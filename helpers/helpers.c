#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            float g_average = (red + green + blue) / 3.0;
            g_average = roundf(g_average);

            image[i][j].rgbtRed = g_average;
            image[i][j].rgbtGreen = g_average;
            image[i][j].rgbtBlue = g_average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    if (width % 2 == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < (width / 2); j++)
            {
                int red0 = image[i][j].rgbtRed;
                int red1 = image[i][width - j - 1].rgbtRed;
                image[i][j].rgbtRed = red1;
                image[i][width - j - 1].rgbtRed = red0;

                int green0 = image[i][j].rgbtGreen;
                int green1 = image[i][width - j - 1].rgbtGreen;
                image[i][j].rgbtGreen = green1;
                image[i][width - j - 1].rgbtGreen = green0;

                int blue0 = image[i][j].rgbtBlue;
                int blue1 = image[i][width - j - 1].rgbtBlue;
                image[i][j].rgbtBlue = blue1;
                image[i][width - j - 1].rgbtBlue = blue0;
            }
        }
    }
    else
    {
        if (width == 3)
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < (width / 2); j++)
                {
                    int red0 = image[i][j].rgbtRed;
                    int red1 = image[i][width - j - 1].rgbtRed;
                    image[i][j].rgbtRed = red1;
                    image[i][width - j - 1].rgbtRed = red0;

                    int green0 = image[i][j].rgbtGreen;
                    int green1 = image[i][width - j - 1].rgbtGreen;
                    image[i][j].rgbtGreen = green1;
                    image[i][width - j - 1].rgbtGreen = green0;

                    int blue0 = image[i][j].rgbtBlue;
                    int blue1 = image[i][width - j - 1].rgbtBlue;
                    image[i][j].rgbtBlue = blue1;
                    image[i][width - j - 1].rgbtBlue = blue0;
                }
            }
        }
        else
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < (width / 2) - 1; j++)
                {
                    int red0 = image[i][j].rgbtRed;
                    int red1 = image[i][width - j - 1].rgbtRed;
                    image[i][j].rgbtRed = red1;
                    image[i][width - j - 1].rgbtRed = red0;

                    int green0 = image[i][j].rgbtGreen;
                    int green1 = image[i][width - j - 1].rgbtGreen;
                    image[i][j].rgbtGreen = green1;
                    image[i][width - j - 1].rgbtGreen = green0;

                    int blue0 = image[i][j].rgbtBlue;
                    int blue1 = image[i][width - j - 1].rgbtBlue;
                    image[i][j].rgbtBlue = blue1;
                    image[i][width - j - 1].rgbtBlue = blue0;
                }
            }
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int red[height][width];
    int green[height][width];
    int blue[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red[i][j] = image[i][j].rgbtRed;
            green[i][j] = image[i][j].rgbtGreen;
            blue[i][j] = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // changing image corner top-left
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round((red[0][0] + red[0][1] + red[1][0] + red[1][1]) / 4.0);
                image[i][j].rgbtGreen = round((green[0][0] + green[0][1] + green[1][0] + green[1][1]) / 4.0);
                image[i][j].rgbtBlue = round((blue[0][0] + blue[0][1] + blue[1][0] + blue[1][1]) / 4.0);
            }

            // changing image corner down-left
            else if (i == (height - 1) && j == 0)
            {
                image[i][j].rgbtRed = round((red[height - 1][0] + red[height - 1][1] + red[height - 2][0] + red[height - 2][1]) / 4.0);
                image[i][j].rgbtGreen =  round((green[height - 1][0] + green[height - 1][1] + green[height - 2][0] + green[height - 2][1]) / 4.0);
                image[i][j].rgbtBlue = round((blue[height - 1][0] + blue[height - 1][1] + blue[height - 2][0] + blue[height - 2][1]) / 4.0);
            }

            // changing image corner top-right
            else if (i == 0 && j == (width - 1))
            {
                image[i][j].rgbtRed = round((red[0][width - 1] + red[0][width - 2] + red[1][width - 1] + red[1][width - 2]) / 4.0);
                image[i][j].rgbtGreen =  round((green[0][width - 1] + green[0][width - 2] + green[1][width - 1] + green[1][width - 2]) / 4.0);
                image[i][j].rgbtBlue = round((blue[0][width - 1] + blue[0][width - 2] + blue[1][width - 1] + blue[1][width - 2]) / 4.0);
            }

            // changing image corner down-right
            else if (i == (height - 1) && j == (width - 1))
            {
                image[i][j].rgbtRed = round((red[height - 1][(width - 1)] + red[height - 1][(width - 2)] + red[height - 2][(width - 1)] + \
                                             red[height - 2][(width - 2)]) / 4.0);
                image[i][j].rgbtGreen =  round((green[height - 1][(width - 1)] + green[height - 1][(width - 2)] + \
                                                green[height - 2][(width - 1)] + green[height - 2][(width - 2)]) / 4.0);
                image[i][j].rgbtBlue = round((blue[height - 1][(width - 1)] + blue[height - 1][(width - 2)] + blue[height - 2][(width - 1)] + \
                                              blue[height - 2][(width - 2)]) / 4.0);
            }

            // changing the top edge
            else if (i == 0 && j > 0 && j < (width - 1))
            {
                image[i][j].rgbtRed = round((red[i][j - 1] + red[i][j] + red[i][j + 1] + red[1][j - 1] + red[1][j] + red[1][j + 1]) / 6.0);
                image[i][j].rgbtGreen = round((green[i][j - 1] + green[i][j] + green[i][j + 1] + green[1][j - 1] + green[1][j] + \
                                               green[1][j + 1]) / 6.0);
                image[i][j].rgbtBlue = round((blue[i][j - 1] + blue[i][j] + blue[i][j + 1] + blue[1][j - 1] + blue[1][j] + blue[1][j + 1]) / 6.0);
            }

            // changing the left edge
            else if (j == 0 && i > 0 && i < (height - 1))
            {
                image[i][j].rgbtRed = round((red[i - 1][j] + red[i][j] + red[i + 1][j] + red[i - 1][1] + red[i][1] + red[i + 1][1]) / 6.0);
                image[i][j].rgbtGreen = round((green[i - 1][j] + green[i][j] + green[i + 1][j] + green[i - 1][1] + green[i][1] + \
                                               green[i + 1][1]) / 6.0);
                image[i][j].rgbtBlue = round((blue[i - 1][j] + blue[i][j] + blue[i + 1][j] + blue[i - 1][1] + blue[i][1] + blue[i + 1][1]) / 6.0);
            }

            // changing the right edge
            else if (j == (width - 1) && i > 0 && i < (height - 1))
            {
                image[i][j].rgbtRed = round((red[i - 1][j - 1] + red[i - 1][j] + red[i][j - 1] + red[i][j] + red[i + 1][j - 1] + red[i + 1][j]) / \
                                            6.0);
                image[i][j].rgbtGreen = round((green[i - 1][j - 1] + green[i - 1][j] + green[i][j - 1] + green[i][j] + green[i + 1][j - 1] + \
                                               green[i + 1][j]) / 6.0);
                image[i][j].rgbtBlue = round((blue[i - 1][j - 1] + blue[i - 1][j] + blue[i][j - 1] + blue[i][j] + blue[i + 1][j - 1] + \
                                              blue[i + 1][j]) / 6.0);
            }

            // changing the down edge
            else if (i == (height - 1) && j > 0 && j < (width - 1))
            {
                image[i][j].rgbtRed = round((red[i - 1][j - 1] + red[i - 1][j] + red[i - 1][j + 1] + red[i][j - 1] + red[i][j] + \
                                             red[i][j + 1]) / 6.0);
                image[i][j].rgbtGreen = round((green[i - 1][j - 1] + green[i - 1][j] + green[i - 1][j + 1] + green[i][j - 1] + green[i][j] + \
                                               green[i][j + 1]) / 6.0);
                image[i][j].rgbtBlue = round((blue[i - 1][j - 1] + blue[i - 1][j] + blue[i - 1][j + 1] + blue[i][j - 1] + blue[i][j] + \
                                              blue[i][j + 1]) / 6.0);
            }

            // changing the middle pixel
            else if (i > 0 && i < (height - 1) && j > 0 && j < (width - 1))
            {
                image[i][j].rgbtRed = round((red[i - 1][j - 1] + red[i - 1][j] + red[i - 1][j + 1] + red[i][j - 1] + red[i][j] + red[i][j + 1] + \
                                             red[i + 1][j - 1] + red[i + 1][j] + red[i + 1][j + 1]) / 9.0);
                image[i][j].rgbtGreen = round((green[i - 1][j - 1] + green[i - 1][j] + green[i - 1][j + 1] + green[i][j - 1] + green[i][j] + \
                                               green[i][j + 1] + green[i + 1][j - 1] + green[i + 1][j] + green[i + 1][j + 1]) / 9.0);
                image[i][j].rgbtBlue = round((blue[i - 1][j - 1] + blue[i - 1][j] + blue[i - 1][j + 1] + blue[i][j - 1] + blue[i][j] + \
                                              blue[i][j + 1] + blue[i + 1][j - 1] + blue[i + 1][j] + blue[i + 1][j + 1]) / 9.0);
            }
        }
    }


    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int (*red)[width] = malloc(sizeof(int[height][width]));
    int (*green)[width] = malloc(sizeof(int[height][width]));
    int (*blue)[width] = malloc(sizeof(int[height][width]));

    int (*gxred)[width] = malloc(sizeof(int[height][width]));
    int (*gxgreen)[width] = malloc(sizeof(int[height][width]));
    int (*gxblue)[width] = malloc(sizeof(int[height][width]));


    int (*gyred)[width] = malloc(sizeof(int[height][width]));
    int (*gygreen)[width] = malloc(sizeof(int[height][width]));
    int (*gyblue)[width] = malloc(sizeof(int[height][width]));

    int (*Gred)[width] = malloc(sizeof(int[height][width]));
    int (*Ggreen)[width] = malloc(sizeof(int[height][width]));
    int (*Gblue)[width] = malloc(sizeof(int[height][width]));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red[i][j] = image[i][j].rgbtRed;
            green[i][j] = image[i][j].rgbtGreen;
            blue[i][j] = image[i][j].rgbtBlue;
        }
    }

    // Doing for Gx and Gy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // changing image corner top-left
            if (i == 0 && j == 0)
            {
                //Gx
                gxred[i][j] = round((red[0][0] * 0) + (red[0][1] * 2) + (red[1][0] * 0) + (red[1][1] * 1));
                gxgreen[i][j] = round((green[0][0] * 0) + (green[0][1] * 2) + (green[1][0] * 0) + (green[1][1] * 1));
                gxblue[i][j] = round((blue[0][0] * 0) + (blue[0][1] * 2) + (blue[1][0] * 0) + (blue[1][1] * 1));
                //Gy
                gyred[i][j] = round((red[0][0] * 0) + (red[0][1] * 0) + (red[1][0] * 2) + (red[1][1] * 1));
                gygreen[i][j] = round((green[0][0] * 0) + (green[0][1] * 0) + (green[1][0] * 2) + (green[1][1] * 1));
                gyblue[i][j] = round((blue[0][0] * 0) + (blue[0][1] * 0) + (blue[1][0] * 2) + (blue[1][1] * 1));
                // sqrt(Gx^2 + Gy^2)
                Gred[i][j] = round(sqrt(pow(gxred[i][j], 2.0) + pow(gyred[i][j], 2.0)));
                Ggreen[i][j] = round(sqrt(pow(gxgreen[i][j], 2.0) + pow(gygreen[i][j], 2.0)));
                Gblue[i][j] = round(sqrt(pow(gxblue[i][j], 2.0) + pow(gyblue[i][j], 2.0)));
                //if value > 255, round to 255
                if (Gred[i][j] > 255)
                {
                    Gred[i][j] = 255;
                }
                if (Ggreen[i][j] > 255)
                {
                    Ggreen[i][j] = 255;
                }
                if (Gblue[i][j] > 255)
                {
                    Gblue[i][j] = 255;
                }

                image[i][j].rgbtRed = Gred[i][j];
                image[i][j].rgbtGreen = Ggreen[i][j];
                image[i][j].rgbtBlue = Gblue[i][j];
            }

            // changing image corner down-left
            else if (i == (height - 1) && j == 0)
            {
                //Gx
                gxred[i][j] = round((red[height - 2][0] * 0) + (red[height - 2][1] * 1) + (red[height - 1][0] * 0) + \
                                    (red[height - 1][1] * 2));
                gxgreen[i][j] = round((green[height - 2][0] * 0) + (green[height - 2][1] * 1) + (green[height - 1][0] * 0) + \
                                      (green[height - 1][1] * 2));
                gxblue[i][j] = round((blue[height - 2][0] * 0) + (blue[height - 2][1] * 1) + (blue[height - 1][0] * 0) + \
                                     (blue[height - 1][1] * 2));
                //Gy
                gyred[i][j] = round((red[height - 2][0] * (-2)) + (red[height - 2][1] * (-1)) + (red[height - 1][0] * 0) + \
                                    (red[height - 1][1] * 0));
                gygreen[i][j] = round((green[height - 2][0] * (-2)) + (green[height - 2][1] * (-1)) + (green[height - 1][0] * 0) + \
                                      (green[height - 1][1] * 0));
                gyblue[i][j] = round((blue[height - 2][0] * (-2)) + (blue[height - 2][1] * (-1)) + (blue[height - 1][0] * 0) + \
                                     (blue[height - 1][1] * 0));
                // sqrt(Gx^2 + Gy^2)
                Gred[i][j] = round(sqrt(pow(gxred[i][j], 2) + pow(gyred[i][j], 2)));
                Ggreen[i][j] = round(sqrt(pow(gxgreen[i][j], 2) + pow(gygreen[i][j], 2)));
                Gblue[i][j] = round(sqrt(pow(gxblue[i][j], 2) + pow(gyblue[i][j], 2)));
                //if value > 255, round to 255
                if (Gred[i][j] > 255)
                {
                    Gred[i][j] = 255;
                }
                if (Ggreen[i][j] > 255)
                {
                    Ggreen[i][j] = 255;
                }
                if (Gblue[i][j] > 255)
                {
                    Gblue[i][j] = 255;
                }

                image[i][j].rgbtRed = Gred[i][j];
                image[i][j].rgbtGreen = Ggreen[i][j];
                image[i][j].rgbtBlue = Gblue[i][j];
            }

            // changing image corner top-right
            else if (i == 0 && j == (width - 1))
            {
                //Gx
                gxred[i][j] = round((red[0][width - 2] * (-2)) + (red[0][width - 1] * 0) + (red[1][width - 2] * (-1)) + \
                                    (red[1][width - 1] * 0));
                gxgreen[i][j] = round((green[0][width - 2] * (-2)) + (green[0][width - 1] * 0) + (green[1][width - 2] * (-1)) + \
                                      (green[1][width - 1] * 0));
                gxblue[i][j] = round((blue[0][width - 2] * (-2)) + (blue[0][width - 1] * 0) + (blue[1][width - 2] * (-1)) + \
                                     (blue[1][width - 1] * 0));
                //Gy
                gyred[i][j] = round((red[0][width - 2] * 0) + (red[0][width - 1] * 0) + (red[1][width - 2] * 1) + \
                                    (red[1][width - 1] * 2));
                gygreen[i][j] = round((green[0][width - 2] * 0) + (green[0][width - 1] * 0) + (green[1][width - 2] * 1) + \
                                      (green[1][width - 1] * 2));
                gyblue[i][j] = round((blue[0][width - 2] * 0) + (blue[0][width - 1] * 0) + (blue[1][width - 2] * 1) + \
                                     (blue[1][width - 1] * 2));
                // sqrt(Gx^2 + Gy^2)
                Gred[i][j] = round(sqrt(pow(gxred[i][j], 2) + pow(gyred[i][j], 2)));
                Ggreen[i][j] = round(sqrt(pow(gxgreen[i][j], 2) + pow(gygreen[i][j], 2)));
                Gblue[i][j] = round(sqrt(pow(gxblue[i][j], 2) + pow(gyblue[i][j], 2)));
                //if value > 255, round to 255
                if (Gred[i][j] > 255)
                {
                    Gred[i][j] = 255;
                }
                if (Ggreen[i][j] > 255)
                {
                    Ggreen[i][j] = 255;
                }
                if (Gblue[i][j] > 255)
                {
                    Gblue[i][j] = 255;
                }

                image[i][j].rgbtRed = Gred[i][j];
                image[i][j].rgbtGreen = Ggreen[i][j];
                image[i][j].rgbtBlue = Gblue[i][j];

            }

            // changing image corner down-right
            else if (i == (height - 1) && j == (width - 1))
            {
                //Gx
                gxred[i][j] = round((red[height - 2][width - 2] * (-1)) + (red[height - 2][width - 1] * 0) + \
                                    (red[height - 1][width - 2] * (-2)) + (red[height - 1][width - 1] * 0));
                gxgreen[i][j] = round((green[height - 2][width - 2] * (-1)) + (green[height - 2][width - 1] * 0) + \
                                      (green[height - 1][width - 2] * (-2)) + (green[height - 1][width - 1] * 0));
                gxblue[i][j] = round((blue[height - 2][width - 2] * (-1)) + (blue[height - 2][width - 1] * 0) + \
                                     (blue[height - 1][width - 2] * (-2)) + (blue[height - 1][width - 1] * 0));
                //Gy
                gyred[i][j] = round((red[height - 2][width - 2] * (-1)) + (red[height - 2][width - 1] * (-2)) + \
                                    (red[height - 1][width - 2] * 0) + (red[height - 1][width - 1] * 0));
                gygreen[i][j] = round((green[height - 2][width - 2] * (-1)) + (green[height - 2][width - 1] * (-2)) + \
                                      (green[height - 1][width - 2] * 0) + (green[height - 1][width - 1] * 0));
                gyblue[i][j] = round((blue[height - 2][width - 2] * (-1)) + (blue[height - 2][width - 1] * (-2)) + \
                                     (blue[height - 1][width - 2] * 0) + (blue[height - 1][width - 1] * 0));
                // sqrt(Gx^2 + Gy^2)
                Gred[i][j] = round(sqrt(pow(gxred[i][j], 2) + pow(gyred[i][j], 2)));
                Ggreen[i][j] = round(sqrt(pow(gxgreen[i][j], 2) + pow(gygreen[i][j], 2)));
                Gblue[i][j] = round(sqrt(pow(gxblue[i][j], 2) + pow(gyblue[i][j], 2)));
                //if value > 255, round to 255
                if (Gred[i][j] > 255)
                {
                    Gred[i][j] = 255;
                }
                if (Ggreen[i][j] > 255)
                {
                    Ggreen[i][j] = 255;
                }
                if (Gblue[i][j] > 255)
                {
                    Gblue[i][j] = 255;
                }

                image[i][j].rgbtRed = Gred[i][j];
                image[i][j].rgbtGreen = Ggreen[i][j];
                image[i][j].rgbtBlue = Gblue[i][j];
            }

            // changing the top edge
            else if (i == 0 && j > 0 && j < (width - 1))
            {
                //Gx
                gxred[i][j] = round((red[i][j - 1] * (-2)) + (red[i][j] * 0) + (red[i][j + 1] * 2) + \
                                    (red[i + 1][j - 1] * (-1)) + (red[i + 1][j] * 0) + (red[i + 1][j + 1] * 1));
                gxgreen[i][j] = round((green[i][j - 1] * (-2)) + (green[i][j] * 0) + (green[i][j + 1] * 2) + \
                                      (green[i + 1][j - 1] * (-1)) + (green[i + 1][j] * 0) + (green[i + 1][j + 1] * 1));
                gxblue[i][j] = round((blue[i][j - 1] * (-2)) + (blue[i][j] * 0) + (blue[i][j + 1] * 2) + \
                                     (blue[i + 1][j - 1] * (-1)) + (blue[i + 1][j] * 0) + (blue[i + 1][j + 1] * 1));
                //Gy
                gyred[i][j] = round((red[i][j - 1] * 0) + (red[i][j] * 0) + (red[i][j + 1] * 0) + (red[i + 1][j - 1] * 1) + \
                                    (red[i + 1][j] * 2) + (red[i + 1][j + 1] * 1));
                gygreen[i][j] = round((green[i][j - 1] * 0) + (green[i][j] * 0) + (green[i][j + 1] * 0) + (green[i + 1][j - 1] * 1) + \
                                      (green[i + 1][j] * 2) + (green[i + 1][j + 1] * 1));
                gyblue[i][j] = round((blue[i][j - 1] * 0) + (blue[i][j] * 0) + (blue[i][j + 1] * 0) + (blue[i + 1][j - 1] * 1) + \
                                     (blue[i + 1][j] * 2) + (blue[i + 1][j + 1] * 1));
                // sqrt(Gx^2 + Gy^2)
                Gred[i][j] = round(sqrt(pow(gxred[i][j], 2) + pow(gyred[i][j], 2)));
                Ggreen[i][j] = round(sqrt(pow(gxgreen[i][j], 2) + pow(gygreen[i][j], 2)));
                Gblue[i][j] = round(sqrt(pow(gxblue[i][j], 2) + pow(gyblue[i][j], 2)));
                //if value > 255, round to 255
                if (Gred[i][j] > 255)
                {
                    Gred[i][j] = 255;
                }
                if (Ggreen[i][j] > 255)
                {
                    Ggreen[i][j] = 255;
                }
                if (Gblue[i][j] > 255)
                {
                    Gblue[i][j] = 255;
                }

                image[i][j].rgbtRed = Gred[i][j];
                image[i][j].rgbtGreen = Ggreen[i][j];
                image[i][j].rgbtBlue = Gblue[i][j];
            }

            // changing the left edge
            else if (j == 0 && i > 0 && i < (height - 1))
            {
                //Gx
                gxred[i][j] = round((red[i - 1][j] * 0) + (red[i - 1][j + 1] * 1) + (red[i][j] * 0) + (red[i][j + 1] * 2) + \
                                    (red[i + 1][j] * 0) + (red[i + 1][j + 1] * 1));
                gxgreen[i][j] = round((green[i - 1][j] * 0) + (green[i - 1][j + 1] * 1) + (green[i][j] * 0) + (green[i][j + 1] * 2) + \
                                      (green[i + 1][j] * 0) + (green[i + 1][j + 1] * 1));
                gxblue[i][j] = round((blue[i - 1][j] * 0) + (blue[i - 1][j + 1] * 1) + (blue[i][j] * 0) + (blue[i][j + 1] * 2) + \
                                     (blue[i + 1][j] * 0) + (blue[i + 1][j + 1] * 1));
                //Gy
                gyred[i][j] = round((red[i - 1][j] * (-2)) + (red[i - 1][j + 1] * (-1)) + (red[i][j] * 0) + (red[i][j + 1] * 0) + \
                                    (red[i + 1][j] * 2) + (red[i + 1][j + 1] * 1));
                gygreen[i][j] = round((green[i - 1][j] * (-2)) + (green[i - 1][j + 1] * (-1)) + (green[i][j] * 0) + (green[i][j + 1] * 0) + \
                                      (green[i + 1][j] * 2) + (green[i + 1][j + 1] * 1));
                gyblue[i][j] = round((blue[i - 1][j] * (-2)) + (blue[i - 1][j + 1] * (-1)) + (blue[i][j] * 0) + (blue[i][j + 1] * 0) + \
                                     (blue[i + 1][j] * 2) + (blue[i + 1][j + 1] * 1));
                // sqrt(Gx^2 + Gy^2)
                Gred[i][j] = round(sqrt(pow(gxred[i][j], 2) + pow(gyred[i][j], 2)));
                Ggreen[i][j] = round(sqrt(pow(gxgreen[i][j], 2) + pow(gygreen[i][j], 2)));
                Gblue[i][j] = round(sqrt(pow(gxblue[i][j], 2) + pow(gyblue[i][j], 2)));
                //if value > 255, round to 255
                if (Gred[i][j] > 255)
                {
                    Gred[i][j] = 255;
                }
                if (Ggreen[i][j] > 255)
                {
                    Ggreen[i][j] = 255;
                }
                if (Gblue[i][j] > 255)
                {
                    Gblue[i][j] = 255;
                }

                image[i][j].rgbtRed = Gred[i][j];
                image[i][j].rgbtGreen = Ggreen[i][j];
                image[i][j].rgbtBlue = Gblue[i][j];
            }

            // changing the right edge
            else if (j == (width - 1) && i > 0 && i < (height - 1))
            {
                //Gx
                gxred[i][j] = round((red[i - 1][j - 1] * (-1)) + (red[i - 1][j] * 0) + (red[i][j - 1] * (-2)) + (red[i][j] * 0) + \
                                    (red[i + 1][j - 1] * (-1)) + (red[i + 1][j] * 0));
                gxgreen[i][j] = round((green[i - 1][j - 1] * (-1)) + (green[i - 1][j] * 0) + (green[i][j - 1] * (-2)) + (green[i][j] * 0) + \
                                      (green[i + 1][j - 1] * (-1)) + (green[i + 1][j] * 0));
                gxblue[i][j] = round((blue[i - 1][j - 1] * (-1)) + (blue[i - 1][j] * 0) + (blue[i][j - 1] * (-2)) + (blue[i][j] * 0) + \
                                     (blue[i + 1][j - 1] * (-1)) + (blue[i + 1][j] * 0));
                //Gy
                gyred[i][j] = round((red[i - 1][j - 1] * (-1)) + (red[i - 1][j] * (-2)) + (red[i][j - 1] * 0) + (red[i][j] * 0) + \
                                    (red[i + 1][j - 1] * 1) + (red[i + 1][j] * 2));
                gygreen[i][j] = round((green[i - 1][j - 1] * (-1)) + (green[i - 1][j] * (-2)) + (green[i][j - 1] * 0) + (green[i][j] * 0) + \
                                      (green[i + 1][j - 1] * 1) + (green[i + 1][j] * 2));
                gyblue[i][j] = round((blue[i - 1][j - 1] * (-1)) + (blue[i - 1][j] * (-2)) + (blue[i][j - 1] * 0) + (blue[i][j] * 0) + \
                                     (blue[i + 1][j - 1] * 1) + (blue[i + 1][j] * 2));
                // sqrt(Gx^2 + Gy^2)
                Gred[i][j] = round(sqrt(pow(gxred[i][j], 2) + pow(gyred[i][j], 2)));
                Ggreen[i][j] = round(sqrt(pow(gxgreen[i][j], 2) + pow(gygreen[i][j], 2)));
                Gblue[i][j] = round(sqrt(pow(gxblue[i][j], 2) + pow(gyblue[i][j], 2)));
                //if value > 255, round to 255
                if (Gred[i][j] > 255)
                {
                    Gred[i][j] = 255;
                }
                if (Ggreen[i][j] > 255)
                {
                    Ggreen[i][j] = 255;
                }
                if (Gblue[i][j] > 255)
                {
                    Gblue[i][j] = 255;
                }

                image[i][j].rgbtRed = Gred[i][j];
                image[i][j].rgbtGreen = Ggreen[i][j];
                image[i][j].rgbtBlue = Gblue[i][j];
            }

            // changing the down edge
            else if (i == (height - 1) && j > 0 && j < (width - 1))
            {
                //Gx
                gxred[i][j] = round((red[i - 1][j - 1] * (-1)) + (red[i - 1][j] * 0) + (red[i - 1][j + 1] * 1) + \
                                    (red[i][j - 1] * (-2)) + (red[i][j] * 0) + (red[i][j + 1] * 2));
                gxgreen[i][j] = round((green[i - 1][j - 1] * (-1)) + (green[i - 1][j] * 0) + (green[i - 1][j + 1] * 1) + \
                                      (green[i][j - 1] * (-2)) + (green[i][j] * 0) + (green[i][j + 1] * 2));
                gxblue[i][j] = round((blue[i - 1][j - 1] * (-1)) + (blue[i - 1][j] * 0) + (blue[i - 1][j + 1] * 1) + \
                                     (blue[i][j - 1] * (-2)) + (blue[i][j] * 0) + (blue[i][j + 1] * 2));
                //Gy
                gyred[i][j] = round((red[i - 1][j - 1] * (-1)) + (red[i - 1][j] * (-2)) + (red[i - 1][j + 1] * (-1)) + \
                                    (red[i][j - 1] * 0) + (red[i][j] * 0) + (red[i][j + 1] * 0));
                gygreen[i][j] = round((green[i - 1][j - 1] * (-1)) + (green[i - 1][j] * (-2)) + (green[i - 1][j + 1] * (-1)) + \
                                      (green[i][j - 1] * 0) + (green[i][j] * 0) + (green[i][j + 1] * 0));
                gyblue[i][j] = round((blue[i - 1][j - 1] * (-1)) + (blue[i - 1][j] * (-2)) + (blue[i - 1][j + 1] * (-1)) + \
                                     (blue[i][j - 1] * 0) + (blue[i][j] * 0) + (blue[i][j + 1] * 0));
                // sqrt(Gx^2 + Gy^2)
                Gred[i][j] = round(sqrt(pow(gxred[i][j], 2) + pow(gyred[i][j], 2)));
                Ggreen[i][j] = round(sqrt(pow(gxgreen[i][j], 2) + pow(gygreen[i][j], 2)));
                Gblue[i][j] = round(sqrt(pow(gxblue[i][j], 2) + pow(gyblue[i][j], 2)));
                //if value > 255, round to 255
                if (Gred[i][j] > 255)
                {
                    Gred[i][j] = 255;
                }
                if (Ggreen[i][j] > 255)
                {
                    Ggreen[i][j] = 255;
                }
                if (Gblue[i][j] > 255)
                {
                    Gblue[i][j] = 255;
                }

                image[i][j].rgbtRed = Gred[i][j];
                image[i][j].rgbtGreen = Ggreen[i][j];
                image[i][j].rgbtBlue = Gblue[i][j];
            }

            // changing the middle pixel
            else if (i > 0 && i < (height - 1) && j > 0 && j < (width - 1))
            {
                //Gx
                gxred[i][j] = round((red[i - 1][j - 1] * (-1)) + (red[i - 1][j] * 0) + (red[i - 1][j + 1] * 1) + \
                                    (red[i][j - 1] * (-2)) + (red[i][j] * 0) + (red[i][j + 1] * 2) + (red[i + 1][j - 1] * (-1)) + \
                                    (red[i + 1][j] * 0) + (red[i + 1][j + 1] * 1));
                gxgreen[i][j] = round((green[i - 1][j - 1] * (-1)) + (green[i - 1][j] * 0) + (green[i - 1][j + 1] * 1) + \
                                      (green[i][j - 1] * (-2)) + (green[i][j] * 0) + (green[i][j + 1] * 2) + (green[i + 1][j - 1] * (-1)) + \
                                      (green[i + 1][j] * 0) + (green[i + 1][j + 1] * 1));
                gxblue[i][j] = round((blue[i - 1][j - 1] * (-1)) + (blue[i - 1][j] * 0) + (blue[i - 1][j + 1] * 1) + \
                                     (blue[i][j - 1] * (-2)) + (blue[i][j] * 0) + (blue[i][j + 1] * 2) + (blue[i + 1][j - 1] * (-1)) + \
                                     (blue[i + 1][j] * 0) + (blue[i + 1][j + 1] * 1));
                //Gy
                gyred[i][j] = round((red[i - 1][j - 1] * (-1)) + (red[i - 1][j] * (-2)) + (red[i - 1][j + 1] * (-1)) + \
                                    (red[i][j - 1] * 0) + (red[i][j] * 0) + (red[i][j + 1] * 0) + (red[i + 1][j - 1] * 1) + \
                                    (red[i + 1][j] * 2) + (red[i + 1][j + 1] * 1));
                gygreen[i][j] = round((green[i - 1][j - 1] * (-1)) + (green[i - 1][j] * (-2)) + (green[i - 1][j + 1] * (-1)) + \
                                      (green[i][j - 1] * 0) + (green[i][j] * 0) + (green[i][j + 1] * 0) + (green[i + 1][j - 1] * 1) + \
                                      (green[i + 1][j] * 2) + (green[i + 1][j + 1] * 1));
                gyblue[i][j] = round((blue[i - 1][j - 1] * (-1)) + (blue[i - 1][j] * (-2)) + (blue[i - 1][j + 1] * (-1)) + \
                                     (blue[i][j - 1] * 0) + (blue[i][j] * 0) + (blue[i][j + 1] * 0) + (blue[i + 1][j - 1] * 1) + \
                                     (blue[i + 1][j] * 2) + (blue[i + 1][j + 1] * 1));
                // sqrt(Gx^2 + Gy^2)
                Gred[i][j] = round(sqrt(pow(gxred[i][j], 2) + pow(gyred[i][j], 2)));
                Ggreen[i][j] = round(sqrt(pow(gxgreen[i][j], 2) + pow(gygreen[i][j], 2)));
                Gblue[i][j] = round(sqrt(pow(gxblue[i][j], 2) + pow(gyblue[i][j], 2)));
                //if value > 255, round to 255
                if (Gred[i][j] > 255)
                {
                    Gred[i][j] = 255;
                }
                if (Ggreen[i][j] > 255)
                {
                    Ggreen[i][j] = 255;
                }
                if (Gblue[i][j] > 255)
                {
                    Gblue[i][j] = 255;
                }

                image[i][j].rgbtRed = Gred[i][j];
                image[i][j].rgbtGreen = Ggreen[i][j];
                image[i][j].rgbtBlue = Gblue[i][j];
            }
        }
    }

    free(red);
    free(green);
    free(blue);
    free(gxred);
    free(gxgreen);
    free(gxblue);
    free(gyred);
    free(gygreen);
    free(gyblue);
    free(Gred);
    free(Ggreen);
    free(Gblue);

    return;
}