import os
for i in xrange(1,51):
    command = 'python ../../../scripts/search.py test_'+str(i)+'.c \"--\"'
    print command
    os.system(command)

    print "************End of file "+str(i)+"***************************"

