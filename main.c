#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void time_string_into_words(char* text);
extern void time_into_words(unsigned int hour, unsigned int minute);

int main(int argc, char* argv[])
{
    register int i;

    for (i = 1; i < argc; i++)
        time_string_into_words(argv[i]);
    return 0;
}

void time_string_into_words(char* text)
{
    char* new_offset;
    unsigned long hour, minute;

    new_offset = strchr(text, ':');
    while (new_offset != NULL) {
        *(new_offset) = ' '; /* Use spaces to separate HH from MM for strtol. */
        new_offset = strchr(text, ':'); /* Just in case user inputs HH:MM:SS. */
    }

    hour = strtoul(text, &new_offset, 10);
    minute = strtoul(new_offset, NULL, 10);
    time_into_words(
        (unsigned int)(hour % 24),
        (unsigned int)(minute % 60)
    );
}

static const char* hrs[12] = {
    "twelve", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten", "eleven",
};
static const char* mins[60] = {
    "o'clock", "oh one", "oh two", "oh three", "oh four", "oh five", "oh six",
    "oh seven", "oh eight", "oh nine",

    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen",

    "twenty", "twenty-one", "twenty-two", "twenty-three", "twenty-four",
    "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine",

    "thirty", "thirty-one", "thirty-two", "thirty-three", "thirty-four",
    "thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine",

    "forty", "forty-one", "forty-two", "forty-three", "forty-four",
    "forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine",

    "fifty", "fifty-one", "fifty-two", "fifty-three", "fifty-four",
    "fifty-five", "fifty-six", "fifty-seven", "fifty-eight", "fifty-nine",
};

void time_into_words(unsigned int hour, unsigned int minute)
{
    printf(
        "It's %s %s %cM.\n",
        hrs[hour % 12], mins[minute % 60],
        (hour < 12) ? 'A' : 'P'
    );
}
