char *_strcat(char *d, char *s) { char *r = d; while (*d) d++; while ((*d++ = *s++)); return (r); }
