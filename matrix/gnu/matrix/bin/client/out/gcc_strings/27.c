#include "cstring.h"

int main(){
	char *d="\ec\e[44;36m";
	//order of list item
	char *lst;
	char *lst2;
	char *s;
	char *s1;
	int pos=0;
	print(d);
	s=newString("arg0,arg1,arg2,arg3,arg4,arg5");
	lst=splitString(s,',');
	lst2=invertList(lst);
	frees(lst);
	lst=orderList(lst2);
	printList(lst);
	frees(lst2);
	frees(s);
	return 0;
}
