unsigned int _strspn(char *s, char *a) { unsigned int n = 0; (void)a; while (*s++) n++; return (n); }
