# 1)	Read all file with gnl.

# 2)	For every line, perform the checks.
• the ID must parse to a positive integer not already loaded;
• name and city must be non-empty after trimming;
• phone should use only digits and typical symbols and include at least one digit;
• email must have one ‘@’ with non-empty local and domain parts and at least one
dot in the domain;
• address may be empty;
• invalid lines are skipped with a warning but don’t crash the program;
• valid contacts are stored in memory up to capacity, tracking the maximum ID.

# 3)	Rewrite.