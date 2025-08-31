#include "../lib.hpp"

/*
        Cut a string from start to end (included).

        Example:

        string = "Hello world!"
        start = 5
        end = 5

        string becomes: "Helloworld!\0"
*/
int     cut_string(string string, size_t start, size_t end)
{
        unsigned int    temp;
        unsigned int    temp1;
        unsigned int    string_len;

        end++;
        if (string.size() == 0 || (start > end))
                return (1);
        string_len = string.size();
        temp = start;
        while ((start != end) && (string[start] != 0))
                string[start++] = 0;
        end = start;
        start = temp;
        temp = 0;
        temp1 = string.size();
        while (end != string_len--)
        {
                string[start + temp] = string[end + temp];
                ++temp;
        }
        string[temp1 - (end - start)] = 0;
        return (0);
}