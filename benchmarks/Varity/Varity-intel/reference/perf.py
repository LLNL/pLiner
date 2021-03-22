import numpy as np
import json

## pLiner
config, time=[], []
with open('pLiner-plog.json') as json_file:
    data = json.load(json_file)
    for item in data:
        config.append(item[0])
        time.append(item[1])

    print "/n pLiner:"
    print "configs:" , np.average(config), np.median(config), np.amin(config), np.amax(config)
    print "time:" , np.sum(time), np.average(time), np.median(time), np.amin(time), np.amax(time) 


## herbgrind
time=[]
with open('herbgrind-plog.json') as json_file:
    data = json.load(json_file)
    for item in data:
        time.append(item[0])

    print "/n herbgrind:"
    print "time:" , np.sum(time), np.average(time), np.median(time), np.amin(time), np.amax(time) 
