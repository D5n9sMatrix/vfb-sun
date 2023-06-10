#!/bin/bash
./decompiler.sh $1 > matches.java
cat matches.java | grep "import" | sed 's/import//' | sed 's/;//' > /tmp/temp
while read a
do
echo $a
echo "---------------------------" >> matches.java
./decompiler.sh $a >> matches.java
done < /tmp/temp

