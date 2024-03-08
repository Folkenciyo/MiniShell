
#include "../../../include/libft.h"

char    *ft_strndup(const char *str, int n)
{
    char *dest;
    int len;
    
    len = ft_strlen(str);
    if (len < n)
        n = len;
    dest = (char*)malloc(n + 1);

    if (!dest)
        return (NULL);
    ft_memcpy(dest,str,n);
    dest[n] = '\0';
    return (dest);
}