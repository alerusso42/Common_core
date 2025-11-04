# THIS IS A COMMENT
# Copre: char singolo, int, float (con 'f'), double, pseudo-literals.

# CHAR
a
Z
@
~

# INT
0
42
-42
+7
2147483647
-2147483648
#	overflow
2147483648
-2147483649
9999999999999999999999999
-9999999999999999999999999

# FLOAT (con 'f')
0.0f
4.2f
-3.14f
-0.0f
nanf
+inff
-inff
-3.4028235e38f
3.4028235e38f

# DOUBLE
0.0
4.2
-3.14
-0.0
nan
+inf
-inf

#Parsing error

.
.f
+.f
-.f
+.
-.
..1
1..
1.2.3
3.14ff
42f f
42f.
42.f.
42.f
42.
.5
.5f
42a
3. f
3 .14f
nanff
infF
NaN
INF
InF
nAnf
+.
-.
+.f
-.f
+.inf
-.nan
42-
3.14f+
++7
--7