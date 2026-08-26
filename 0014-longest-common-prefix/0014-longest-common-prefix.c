char* longestCommonPrefix(char** strs, int strsSize) {
 char* str = (char*)malloc(strlen(strs[0]) + 1);
 strcpy(str,strs[0]);

    for(int i=1;i<strsSize;i++)
    {
        int j=0;
  while( (str[j] && strs[i][j] )&& str[j] == strs[i][j]) {
            j++;
        }
        
        
     str[j] = '\0';
        
        
        if (str[0] == '\0') {
            return str;
        }
    }
    
    return str;
    }

