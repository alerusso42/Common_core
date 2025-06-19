# ORIGINAL SUBJECT FROM CUSTOMER

You have been approached by a young professional who keeps track of their spending in
a simple text file and wants a small console program to help them make sense of it. Each
line of their file represents one purchase or expense, written by hand or exported from
another app; they separate fields with commas but sometimes forget to format things
perfectly. A typical line might look like ‘2024-01-15,12.50,Food,Latte at cafe‘, but occasionally there are typos, extra spaces, missing fields, non-numeric amounts, or dates in
the wrong format.
They ask you to build a software to read their file (whose name is supplied on the command line) and quietly skip invalid lines (or printing a warning so they know something
was off) while storing up to around a thousand valid records in memory. After loading, the
program should ask the user how they want to view or filter their expenses: perhaps by
entering a piece of a category name (like "food” to catch "Food” or "food”), or by specifying a date range (e.g., between "2024-01-01” and "2024-01-31”), or simply choosing to see
everything. The prompts must insist on valid input: re-asking if someone just presses Enter, or types a date in a wrong format, or gives a start date that comes after the end date.
Internally, dates are stored in the ‘YYYY-MM-DD‘ format, allowing for lexicographic
comparison once validated. Amounts are positive floating-point numbers. If a line contains ‘invalid_amount‘, ‘zero‘, or a negative value, that record should be skipped with
a warning. Categories and descriptions may contain extra whitespace or mixed casing;
your program should trim them and handle category comparisons in a case-insensitive
manner. In any summary, categories that differ only in case should be grouped together

# ?????

as identical. After the user selects a filter, the program filters the in-memory records

accordingly, then computes and displays a summary:
• Total number of records under consideration
• Total amount spent
• Average expense
• Breakdown by category, showing:
◦ Total spent per category
◦ Percentage of the total each category represents
If no records match the filter, the program should clearly indicate that. Once the summary is displayed, the program should clean up any allocated memory and exit. If the
file cannot be opened, the program should print an error message and terminate.
Important:
For this exercise, your goal is to design the high-level structure of the project. The expected output is a set of header files containing the key data structures and function
prototypes you would use if you were to implement the full project.
Pro tip: he original problem description alone probably won’t be enough.
Take some time to extract and rephrase the core requirements (e.g., in a bullet list style)
and sketch out your interpretation of the system using schemes, flowcharts, use-cases,
and any other tools you find useful.
You don’t need to use formal tools: pictures of plain paper are perfectly fine, as
long as they’re readable.
You’re welcome to submit these artifacts as well, just be sure to include a short explanation of what they are and why they help clarify your design


