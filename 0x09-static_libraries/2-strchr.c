char *_strchr(char *s, char c) { while (*s != c && *s) s++; return (*s == c ? s : 0); }
