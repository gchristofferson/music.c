// Helper functions for music

#include <cs50.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    int numerator = atoi(fraction[0]);
    int denominator = atoi(fraction[2]);
    switch(denominator)
    {
        case 1:
            return numerator *= 8;
            break;
        case 2:
            return numerator *=4;
            break;
        case 4:
            return numerator *=2;
            break;
        case 8:
            return numerator;
            break;
    }
}
/* --
The frequencies of one octave’s notes differ from those of adjacent octaves'
notes by a factor of two. For instance, the frequency of A3 is 220 Hz (i.e., half that of A4),
while the frequency of A5 is 880 Hz (i.e., twice that of A4). More generally, the frequency, f,
of some note is 2n/12 × 440, where n is the number of semitones from that note to A4, where n is negative
if that note is below (i.e., to the left of) A4 and positive if that note is above (i.e., to the right of) A4.
-- */
// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    // for A4, return 440
    if (note = "A4")
    {
        return 440;
    }
    // parse the string into a note and its octave
    char letter;
    // convert string letter to ASCII index
    note[0] = atoi(letter);
    int letter = note[0];
    // add 7 to letters A and B as they are at the end of each octave.
    if (letter == 65 || letter == 66)
    {
        letter += 7;
    }
    char octave;
    note[1] = atoi(octave);
    // int oct = note[1];
    int userOct = note[1];
    //create an array to hold all 88 piano keys
    char keys[89] = {0};
    int key = 65;
    char k;
    int octave = 0;
    for(i = 0; i < 88; i++)
    {
       if (key == 65 && octave != 0)
       {
           octave++;
       }
       // keys[i] = key + octave as string
       char theKey[4];
        sprintf(theKey, "%s%i", key, octave);
        keys[i] = theKey;
        if (key < 71)
        {
            key++;
        }
        else
        {
            key = 65;
        }
    }

    // calculate the frequency of the note in the given octave
    // the frequency, f, of some note is 2^(n/12) x 440, where n is the number of semitones from that note to A4
        // calculate what n should be
            //calculate how many octaves greater or lesser note is than A4.
            //
        // create recursive function for calculating semitones
        // create recursive function for calculating octaves
    // return the frequency
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if (s = "")
    return 0;
}
