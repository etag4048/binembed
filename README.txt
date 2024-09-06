binembed - Embeds binary data into an executable

binembed [-h header path] [-o archive path] file ...

DOCUMENTATION

man -l binembed.1

INSTALLATION

1) Copy 'binembed' to a directory contained in the $PATH
variable

2) Copy the manual page to '/usr/share/man1'

QUICK EXAMPLE

echo "Something" > test1.txt

./binembed test1.txt

cc example.c resources.a -o example

./example test1.txt
path: test1.txt
size of resource: 10
Something
