#!/usr/bin/env bash

set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

function check_log() {
    LOG=$( { ${1}; } 2>&1 )
    STATUS=$?
    echo "$LOG"
    if echo "$LOG" | grep -q -E "${2}"
    then
        exit 1
    fi

    if [ $STATUS -ne 0 ]
    then
        exit $STATUS
    fi
}


print_header "RUN clang-format"
check_log "clang-format -style=google -i ./project/*/*.c ./project/*.c ./project/*/*.h " "\(information\)"

print_header "RUN scan-build"
check_log "scan-build make build" "\(information\)"

print_header "RUN cppcheck"
check_log "cppcheck project --enable=all --inconclusive --error-exitcode=1 -i project/build -i project/tests -I project --suppress=missingIncludeSystem" "\(information\)"

print_header "RUN cland-tidy"
check_log "clang-tidy **/*.c -warnings-as-errors=* -extra-arg=-std=c99 -- -Iproject -Iproject/email_lib -Iproject/utils  " "Error (?:reading|while processing)"

print_header "RUN cpplint"
check_log "cpplint --extensions=c project/* project/email_lib/*  project/utils/* " "\(information\)"

print_header "SUCCESS"
