#!/bin/bash

fail=0

function expect_fail {
    echo "Probando: $*"
    output=$($* 2>&1)
    status=$?
    if [ $status -eq 0 ]; then
        echo "❌ Error: No falló como se esperaba"
        echo "Output: $output"
        fail=1
    else
        echo "✅ Correctamente rechazado"
    fi
}

expect_fail "../a.out"
expect_fail "../a.out -5 800 200 200"
expect_fail "../a.out 0 800 200 200"
expect_fail "../a.out 5 0 200 200"
expect_fail "../a.out 5 800 -200 200"
expect_fail "../a.out 5 800 200 200 -1"

exit $fail
