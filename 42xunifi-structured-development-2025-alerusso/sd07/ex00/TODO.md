# 1)	Read all file with gnl.
#		Allocs right size for data structure.

# 2)	Before rewriting the file, save into a 3D matrix of strings.
#	matrix[0] are all books that starts with 'A', [1] with 'B'...
#	Alternately, we could use an hash table, like murmurhash.

# 3)	Before rewriting the file, trim spaces.
# Spaces are not admitted: 
# 	after and before ',' (only between chars);
# 	Between '#' and i, in the first key;
# 	Before '#';
# 	Between the \n or \0 and previous chars.


# 4)	Rewrite the entire matrix into a new file.
#		If file surpasses 1000 entries, make multiple files.
#		Save offset of words with 'A', 'B', ecc.

# 5)	loop in which user asks for books. Strncmp. EZ.		