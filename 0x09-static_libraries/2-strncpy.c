char *_strncpy(char *d, char *s, int n) { char *r = d; while (n-- && (*d++ = *s++)); return (r); }
