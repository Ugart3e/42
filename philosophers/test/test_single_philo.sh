#!/bin/bash

CMD="../a.out 1 800 200 200"
$CMD > output.log &

PID=$!
sleep 3

if grep -q "Has taken fork1" output.log && grep -q "died" output.log; then
    echo "✅ Filósofo solitario muere tras no poder comer"
else
    echo "❌ Error con el caso de un solo filósofo"
    tail output.log
    kill $PID
    exit 1
fi

kill $PID
wait $PID 2>/dev/null
