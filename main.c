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

void time_into_words(unsigned int hour, unsigned int minute)
{
    printf("time_into_words(%u, %u)\n", hour, minute);
}
