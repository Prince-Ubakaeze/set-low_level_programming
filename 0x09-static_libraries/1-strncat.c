char *_strncat(char *d, char *s, int n) { char *r = d; while (*d) d++; while (n-- && (*d++ = *s++)); *d = 0; return (r); }
