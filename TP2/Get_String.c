#include "Get_String.h"


int getString(char** result) {
  int chunksize = NUMCARACTERES;
  char *s = NULL;
  char *temp = NULL;
  int buffersize = chunksize+1;
  int ret = RES_OK;
  int N = 0;
  
  s = malloc(buffersize);  
  if (s == NULL) 
    return ERR_OUT_OF_MEMORY;
  else if (fgets(s, chunksize+1, stdin) == NULL) {
    free(s);
    ret = ERROR_OR_EOF;
  } else {
    while ((strchr(s, '\n') == NULL) && (ret != ERR_OUT_OF_MEMORY)) {
      buffersize += chunksize;
      temp = realloc(s, buffersize);
      if (temp == NULL) {
	free(s); 
	s = NULL;
	ret = ERR_OUT_OF_MEMORY;
      } else {
	s = temp;
	if (fgets(s+buffersize-chunksize-1, chunksize+1, stdin) == NULL) 
	  ret = ERR_OUT_OF_MEMORY;
      }
    }
    if (ret != ERR_OUT_OF_MEMORY) {
      N = strlen(s);
      s[N -1] = 0;
      *result = s;
    } else free(s);
  }
  return ret;
}
