#!/bin/bash

if [ $# -lt 1 ]
then
    echo "Usage: $0 <#threads>"
else
    thnum=$1
    if [ ! -e "none${thnum}" ]; then
        gcc -pthread -o none${thnum} -DTHNUM=${thnum} none.c main.c
    fi
    if [ ! -e "mutex${thnum}" ]; then
        gcc -pthread -o mutex${thnum} -DTHNUM=${thnum} -DMUTEX mutex.c main.c
    fi
    if [ ! -e "lockfree${thnum}" ]; then
        gcc -pthread -o lockfree${thnum} -DTHNUM=${thnum} lockfree.c main.c
    fi

    echo ""
    echo "+++ 1. No lock +++"
    time ./none${thnum}
    echo ""
    echo "+++ 2. Mutex +++"
    time ./mutex${thnum}
    echo ""
    echo "+++ 3. Lock-free +++"
    time ./lockfree${thnum}

    rm ./none${thnum}
    rm ./mutex${thnum}
    rm ./lockfree${thnum}
fi
