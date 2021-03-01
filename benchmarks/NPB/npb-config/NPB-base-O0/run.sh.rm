#!/bin/csh

mkdir -p bin
mkdir -p result

foreach benchmark ( ft mg cg lu bt is ep sp )
    foreach class ( S W A B C D )
        echo "compiling $benchmark.$class. (SER-C)"
        make $benchmark CLASS=$class
        echo "running $benchmark.$class. (SER-C)"
        bin/$benchmark.$class.x > result/$benchmark.$class.out
        echo "done.\n"
    end
end
