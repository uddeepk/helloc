/* mystrindex: return the position of the rightmost occurence of t in s, or -1 if there is none*/
int mystrindex(char s[], char t[])
{
  int i, j, k, l = -1;

  for (i = 0; s[i] != '\0'; ++i) {
    for ( j = i, k = 0; t[k] != '\0' && s[j] == t[k] ; ++j, ++k)
      ;
    if (k > 0 && t[k] == '\0')
      l = i;//return i;
  }
  return l; // changed from -1 to l
}
