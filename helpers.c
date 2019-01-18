// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // assign char variable to parse the first character (numerator) from the fraction string
    char num = fraction[0];
    // assign char variable to parse the last character (denomonator) from the fraction string
    char den = fraction[2];
    // assign int variable numerator to store converted string value to integer
    int numerator = 0;
    // convert the numerator string (num) to an integer (numerator)
    switch (num)
    {
        case '0':
            numerator = 0;
            break;
        case '1':
            numerator = 1;
            break;
        case '2':
            numerator = 2;
            break;
        case '3':
            numerator = 3;
            break;
        case '4':
            numerator = 4;
            break;
        case '5':
            numerator = 5;
            break;
        case '6':
            numerator = 6;
            break;
        case '7':
            numerator = 7;
            break;
        case '8':
            numerator = 8;
            break;
        case '9':
            numerator = 9;
            break;
            // write the rest below
    }
    // based on the value of the denomonator (den) calculate the number of eighths to return
    switch (den)
    {
        case '1':
            return numerator *= 8;
            break;
        case '2':
            return numerator *= 4;
            break;
        case '4':
            return numerator *= 2;
            break;
        case '8':
            return numerator;
            break;
    }
    // if all else fails, return 0
    return 0;
}
/* --
The frequency, f, of some note is 2 ^ (n/12) × 440, where n is the number
of semitones from that note to A4, where n is negative if that note is below
(i.e., to the left of) A4 and positive if that note is above (i.e., to the right of) A4.
-- */
// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int ret;
    // if note is A4, return 440
    ret = strncmp(note, "A4", 2);
    if (ret == 0)
    {
        return 440;
    }
    /*--
    Dynamically create a multidemensional array to hold all 88 piano keys
    (can be scaled to hold more or less keys). Each key has capacity
    to hold 6 chars because sharp and flat notes will be stored in one key (i.e., G#5Ab5)
    --*/
    char keys[89][7] = {{0}};
    // assign char variable key and initialize to 72, which will be the int value for 'A', and starting key of array
    int key = 72;
    // assign char k to store letter value of note in keys array.
    char k;
    // assign char sharp to store the '#' symbol for sharp notes
    char sharp = {0};
    // assign char flat to store the 'b' symbol for flat notes
    char flat = 'b';
    // assign int variable octave to store the octave of the note and initialize to O
    int octave = 0;
    // assign int variable A4 and initialize to 48, which is the index at which note A4 is located in array
    int A4 = 48;
    // assign double variable fracToDec which will store the decimal value of the fraction
    double fracToDec = 0;
    // assign double variable n (number of keys note is from A4);
    double n = 0;
    /*--
    Assign double variable d and initialize to 12 which is the denominator value in formula used to
    calculate frequency of note. (i.e., 2 ^ (n/d) * 440)
    --*/
    double d = 12;
    // assign variable to store the frequency as a float
    double frequencyFloat = 0;
    // declare int ret1 which will return 0 if note matches key in array and is sharp
    int ret1;
    // declare int ret1 which will return 0 if note matches key in array and is flat
    int ret2;
    // assign string keyString which will hold value of key in array as a string
    string keyString = "";
    // assign char keyStringSharp to hold value of key in array as string if it's a sharp note.
    char keyStringSharp[1][4] = {{0}};
    // assign char keyStringSharp to hold value of key in array as string if it's a flat note.
    char keyStringFlat[1][4] = {{0}};
    // assign string variable to convert char keyStringSharp to string data type for comparison
    string kSSharp = "";
    // assign string variable to convert char keyStringFlat to string data type for comparison
    string kSFlat = "";
    for (int i = 0; i < 88; i++)
    {
        // since octaves begin with C, assign ASCII index values for A and B as 72 and 73 for loop
        if (key == 72)
        {
            k = 'A';
        }
        else if (key == 73)
        {
            k = 'B';
        }
        else
        {
            k = key;
        }
        /*--
        Assign char k1 to store value of next key in the array on this iteration so we can
        create flat and sharp keys.
        --*/
        char k1 = k + 1;
        if (k1 == 72)
        {
            k1 = 'A';
        }
        // merge note letter (k), sharp or flat symbols, and octive into one string.
        char mergedKey[7];
        if (sharp == '#')
        {
            //add support for flat and sharp, saving 6 values to key instead of 3. 3 for sharp, 3 for flat
            sprintf(mergedKey, "%c%c%i%c%c%i", k, sharp, octave, k1, flat, octave);
            // sharp key
            keys[i][0] = mergedKey[0];
            keys[i][1] = mergedKey[1];
            keys[i][2] = mergedKey[2];
            // flat key
            keys[i][3] = mergedKey[3];
            keys[i][4] = mergedKey[4];
            keys[i][5] = mergedKey[5];
            // create sharp note string
            keyStringSharp[0][0] = keys[i][0];
            keyStringSharp[0][1] = keys[i][1];
            keyStringSharp[0][2] = keys[i][2];
            // create flat note string
            keyStringFlat[0][0] = keys[i][3];
            keyStringFlat[0][1] = keys[i][4];
            keyStringFlat[0][2] = keys[i][5];
            sharp = 0;
            // if we haven't reached end of octave, increase key
            if (key < 73)
            {
                key++;
            }
            // if we have reached end of octave, set key to 67 (C)
            else
            {
                key = 67;
            }
        }
        // if key isn't flat or sharp, create key with just 3 arguments
        else
        {
            int thisKey = 0;
            sprintf(mergedKey, "%c%i", k, octave);
            keys[i][0] = mergedKey[0];
            keys[i][1] = mergedKey[1];
            switch (key)
            {
                case 73:
                    thisKey = 73;
                    key = 67;
                    sharp = 0;
                    break;
                case 69:
                    thisKey = 69;
                    key++;
                    sharp = 0;
                    break;
            }
            // if next key is a sharp or flat key, set sharp to '#'
            if (thisKey != 73 && key != 73 && thisKey != 69 && key != 69)
            {
                sharp = '#';
            }

        }
        // if key is 67 (C) and next key is not sharp or flat, increase octave by 1
        if (key == 67 && sharp == 0)
        {
            octave++;
        }
        keyString = keys[i];
        // compare the note and key in the array. If they match, strncmp will return 0
        ret = strncmp(note, keyString, 3);
        // if next key is not sharp or flat, not 67 (C) or 70 (F), set values of this sharp and flat key in array
        if (sharp != '#' && key != 67 && key != 70)
        {
            kSSharp = keyStringSharp[0];
            kSFlat = keyStringFlat[0];
            // compare the note and sharp key in the array. If they match, strncmp will return 0
            ret1 = strncmp(note, kSSharp, 3);
            // compare the note and flat key in the array. If they match, strncmp will return 0
            ret2 = strncmp(note, kSFlat, 3);
        }
        // if next key is sharp, flat, 67 or 70, reset values of these variables
        else
        {
            kSSharp = "";
            kSFlat = "";
            ret1 = 1;
            ret2 = 1;
        }
        // if the note matches the key string value, calculate and return the frequency
        if (ret == 0 || ret1 == 0 || ret2 == 0)
        {
            n = i - A4;
            fracToDec = n / d;
            frequencyFloat = pow(2.00, fracToDec) * 440;
            int f = round(frequencyFloat);
            return f;
        }
    }
    // if all else fails, return 0
    return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    int ret;
    ret = strncmp(s, "", 1);
    if (ret == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
