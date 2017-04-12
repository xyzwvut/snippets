#!/usr/bin/env python

from path import path

#
# Count number of files
#
d = path(DIRECTORY)
#Replace DIRECTORY with your required directory
num_files = len(d.files())
print num_files

#
# Count number of directoryies
#
d = path(DIRECTORY)
#Replace DIRECTORY with your required directory
num_dirs = len(d.dirs())
print num_dirs

#
# Count number of files and directories recusively
#
file_count = 0
dir_count = 0
total = 0
d = path(DIRECTORY)
#Replace DIRECTORY with your required directory
for i in d.walk():
    if i.isfile():
        file_count += 1
    elif i.isdir():
        dir_count += 1
    else:
        pass
    total += 1

print "Total number of files == {0}".format(file_count)
print "Total number of directories == {0}".format(dir_count)


#
# Delete a specific file
#
from path import path
d = path(DIRECTORY)
#replace directory with your desired directory
for i in d.walk():
    if i.isfile():
        if i.name == 'php.py':
            i.remove()


#
# Delete files based on their size
#
d = path('./')
del_size = 4522420
for i in d.walk():
    if i.isfile():
        if i.size > del_size:
        #4522420 is approximately equal to 4.1Mb
        #Change it to your desired size
            i.remove()

