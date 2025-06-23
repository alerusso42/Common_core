# ORIGINAL SUBJECT FROM CUSTOMER

##You are tasked with creating a small console-based software for a community library.

##As of today, the staff of the library maintain a simple plain-text catalog of books in a
file: each line contains information about one book, with fields separated by commas, for
example an identifier number, then the book’s title, then the author’s name.

# example
#0,Gulliver adventure,Jonathan Swift
...
#i,BOOK_NAME,AUTHOR_NAME

Over time
this file may grow to contain up to around a thousand entries. Occasionally, some lines
might be malformed or contain extra whitespace. The staff want a program that, when
run, reads this catalog file, handles any unexpected or malformed lines (e.g., by warning
or skipping them), and keeps all valid entries in memory.

# Everytime program is run, the file is rewritten.
# Spaces are not admitted: 
# 1)	after and before ',' (only between chars);
# 2)	Between '#' and i, in the first key;
# 3)	Before '#';
# 4)	Between the \n or \0 and previous chars.

Once the catalog is loaded, the program should interactively prompt the user to choose
how to look up books: either by searching for a substring in the title or by searching for
a substring in the author’s name. The input for the search should automatically trim
any trailing spaces or newlines, and the search must be case-insensitive, so that typing
"kernighan" will correctly match "Kernighan". If no matching books are found, the program should inform the user; otherwise it should display each matching entry’s identifier,
title, and author in a clear format. After showing results, the program should clean up
any allocated resources and exit.
The tool must be invoked from the command line with the catalog filename as its argument. If the file cannot be opened, the program should report an error and terminate.

# While loop, with a word to exit the loop.
# strcmp case insensitive.

Internally, the program will keep up no more than 1000 book records in memory; The user
interface is text-based: after loading, prompt clearly for “search by title” or “search by author” requiring a valid input (e.g., only accept “1” or “2” or equivalent), then prompt
for the substring, re-prompting if the user just presses Enter without typing anything
meaningful, and take into account a way for the user to terminate the program correctly.

# When rewriting the database, sort by alphabet.
# Save offset of books that starts by different initials:
#	'A', 'B', 'C'...
