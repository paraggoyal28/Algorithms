#include <stdio.h>
#include <string.h>
int main()
{ 
	int t;
  	scanf("%d",&t);
        while(t>0)
        {
		char str[3000002];
		scanf("%s",str);                                                                long int n = strlen(str);
		long int i;
		long int ans = 0;
		long int max = n*(n+1)/2;
		for(i=0;i<n-1;i++)                                                              {
			if(str[i] == str[i+1])
				ans += max-n;
			else
				ans += n;
		}
		printf("%ld\n", ans);
		t--;
	}
}
