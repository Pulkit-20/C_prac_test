char* removeDuplicateLetters(char* s) {
    int i,j=0, alphabet[26] ={0}, choosen[26] = {0}, count =0, len = strlen(s);
    char* out = (char*)calloc(sizeof(char), 27);
    for(i =0;i<len; i++) alphabet[s[i]-'a']++;
    for(i=0; i<len;i++) {
        alphabet[s[i] - 'a']--;
        if(choosen[s[i]- 'a']) continue;
        while (j>0 && s[i] < out[j-1] && alphabet[out[j-1] - 'a'] > 0)
            choosen[out[--j] - 'a'] =0;
        choosen[s[i]-'a'] = out[j++] = s[i];;
    }
    out[j] = '\0';
    return out;
}