# SAme as ex00 without database

You’ve been asked to build a simple console-based contact management tool for a small
organization. Contacts are stored in a plain-text CSV file whose name is given as the
single command-line argument when starting the program. Each line should hold six
comma-separated fields: an integer ID, a name, phone, email, city, and a free-form address. In practice the file may contain up to around a thousand valid contacts but also
malformed lines: missing fields, extra whitespace, invalid formats, or duplicate IDs, so
your program must open the file (or error and exit if it can’t), read it line by line, trim
whitespace around fields, and apply basic validation:
• the ID must parse to a positive integer not already loaded;
• name and city must be non-empty after trimming;
• phone should use only digits and typical symbols and include at least one digit;
• email must have one ‘@’ with non-empty local and domain parts and at least one
dot in the domain;
• address may be empty;
• invalid lines are skipped with a warning but don’t crash the program;
• valid contacts are stored in memory up to capacity, tracking the maximum ID.
10
Structured Analysis sd04
After loading, enter a menu loop offering options like listing all contacts, searching by
name or city substring, adding a new contact, updating an existing contact, deleting a
contact, and saving & exiting.
On save, write all contacts back to the same filename (tip: use a temporary file and then
rename, reporting any write errors) and exit. Every prompt must re-ask on invalid input;
after each operation return to the menu until save-and-exit is chosen.
Important:
For this exercise, your goal is to design the high-level structure of the project. The expected output is a set of header files containing the key data structures and function
prototypes you would use if you were to implement the full project.
Pro tip: he original problem description alone probably won’t be enough.
Take some time to extract and rephrase the core requirements (e.g., in a bullet list style)
and sketch out your interpretation of the system using schemes, flowcharts, use-cases,
and any other tools you find useful.
You don’t need to use formal tools: pictures of plain paper are perfectly fine, as
long as they’re readable.
You’re welcome to submit these artifacts as well, just be sure to include a short explanation of what they are and why they help clarify your design.
