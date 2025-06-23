An emergent streaming platform hires you to create a console-based Movie Watchlist app
that reads from and writes to a plain-text CSV file given by the user on the command
line. Each line in that file is expected to hold six comma-separated fields: a positive
integer ID, a movie title, a genre, a watched flag (0 or 1), a rating (1-10 if watched, otherwise 0), and a date watched in YYYY-MM-DD format if watched (otherwise empty).
In practice, the file may contain up to around a thousand valid records but also occasional
malformed lines (e.g., missing fields, extra whitespace, invalid IDs or duplicates, incorrect flags, out-of-range ratings, or bad dates), so your program should attempt to open
the file, read it line by line, trim whitespace around each field, and apply basic validations:
• the ID must parse to a positive integer not seen before;
• title and genre must be non-empty;
• watched flag must be exactly 0 or 1;
• if marked watched, rating can be an integer from 1 to 10 and date watched must
match YYYY-MM-DD within plausible ranges;
• if unwatched, any rating or date content is ignored or warned about but not fatal;
• invalid lines are skipped with a warning to stderr but do not crash the program;
• valid entries are stored in memory, up to capacity, tracking the maximum ID encountered so new entries can be assigned unique IDs.
12
Structured Analysis sd04
After loading, the program enters an interactive menu loop offering operations such as
listing all movies in ascending ID order, searching by title or genre substring, filtering by
watched or unwatched status, adding a new movie, marking an existing movie as watched,
updating title or genre of a chosen movie, deleting a movie (prompting for confirmation),
showing summary statistics (e.g., total movies, counts watched vs. unwatched, average
rating of watched and breakdowns by genre for watched and unwatched sets), and finally
saving and exiting. Every prompt must validate the inputs and re-prompt if invalid.
When saving, all records currently in memory are written back to the same filename, so
that the watchlist on disk reflects any additions, updates, or deletions.
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
